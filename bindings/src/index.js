import * as fs from "./fs.js";
globalThis.config=JSON.parse(fs.readFileSync('bindings/config/buildFlags.json','utf8'));
globalThis.extrainfo={};

const cgen = (await import("./cgen.js"));
const rayjs_header = (await import("./raylib-header.js")).RayJsHeader;

let source_parser,simpleregex,defaultTypeParts;
{
    let sp = (await import("./source_parser.js"));
    source_parser=sp.source_parser;
    defaultTypeParts=sp.defaultTypeParts;
    simpleregex=sp.simpleregex;
}
const qj=await import("./quickjs.js");
const QuickJsGenerator = qj.QuickJsGenerator;

// @ts-ignore
String.prototype.replaceAt = function(index, replacement) {
    return this.substr(0, index) + replacement + this.substr(index+1);
};
if(globalThis.structuredClone==undefined){
    globalThis.structuredClone=(obj)=>{
        if(typeof(obj)=='object'){
            let obj2;
            if(Array.isArray(obj)){
                obj2=[];
            }else{
                obj2={};
            }
            for(let key in obj){
                obj2[key]=globalThis.structuredClone(obj[key]);
            }
            return obj2;
        }
        return obj;
    }
}
String.prototype.countChar=function(c) {
    var result = 0, i = 0;
    for(i;i<this.length;i++)if(this[i]==c)result++;
    return result;
};
let modules= {};//name=>api
let ignored=0;
function attachGetters(api){
    api.getFunction=(name)=> api.functions.find(x => x.name === name);
    api.getStruct=(name)=> api.structs.find(x => x.name === name);
    api.getCallback=(name)=> api.callbacks.find(x => x.name === name);
    api.getEnum=(name)=> api.enums.find(x => x.name === name);
    api.ignore=(name)=>{
        let obj=api.getFunction(name);
        if(!obj)obj=api.getStruct(name);
        if(!obj)obj=api.getCallback(name);
        if(!obj)obj=api.getEnum(name);
        if(obj){
            obj.binding = { ignore: true };
            ignored++;
        }
    };
}
function normalizeType(type=''){
    return type.replaceAll("*", " * ").replaceAll('[',' [').replace(new RegExp("\\s+",'g'),' ').trim();
}
function removeDuplicates(module,key,names){
    let j=0;
    for(let i=0;i<module[key].length;i++){
        if(!names.has(module[key][i].name)){
            module[key][j]=module[key][i];
            j++;
        }
    }
    if(j<module[key].length)module[key]=module[key].slice(0,j);
}
const includeDictionary={};
function fixModuleRedefs(source){
    //Sometimes when parsing source in C it is a redefinition of something yet to be declared
    //We want to catch those and mark them correctly
    let varsMap={};
    let toScan=[];
    let newDefined=[];
    for(let fn of source.functions)varsMap[fn.name] = [source.functions,fn];
    for(let fn of source.callbacks)varsMap[fn.name] = [source.callbacks,fn];
    for(let en of source.enums){
        for(let value of en.values){
            varsMap[value.name] = [en.values,value];
        }
    }
    for(let en of source.unions){
        varsMap[en.name] = [source.unions,en];
    }
    for(let st of source.structs){
        varsMap[st.name] = [source.structs,st];
    }
    for(let al of source.aliases){
        varsMap[al.name] = [al,source.aliases];
    }
    for(let value of source.staticData){
        varsMap[value.name] = [source.staticData,value];
    }
    for(let def of source.defines){
        if(def.type=='undefined'){
            if(def.content.body!=''){
                toScan.push(def);
            }else{
                newDefined.push(def);
            }
        }else{
            varsMap[def.name] = [def,source.defines];
            newDefined.push(def);
        }
    }
    //Try to resolve undefined
    for(let def of toScan){
        let redefOf = varsMap[def.content.body];
        if(redefOf==undefined){
            newDefined.push(def);
        }else{
            let copy=structuredClone(redefOf[1]);
            copy.name=def.name;
            redefOf[0].push(copy);
        }
    }
}
//TODO: debug bool true=NaN
//TODO: debug eval DEG2RAD="PI/180.0f)"
function sourceToVars(source){
    let varsMap={};
    for(let fn of source.functions){
        varsMap[fn.name] = {type:'function',name:fn.name,args:fn.args.map(a=>{return {type:a.type,name:a.name};}),returnType:(fn.props.const?'const ':'')+fn.returnType};
    }
    for(let fn of source.callbacks){
        varsMap[fn.name] = {type:'type',subtype:'function',ptrtype:fn.type,name:fn.name,args:fn.args.map(a=>{return {type:a.type,name:a.name};}),returnType:fn.returnType};
    }
    for(let en of source.enums){
        for(let value of en.values){
            varsMap[value.name] = {type:'value',subtype:'int',name:value.name,props:{}};
        }
    }
    for(let en of source.unions){
        varsMap[en.name] = ({type:'type',subtype:'enum',name:en.name,fields:en.fields});
    }
    for(let st of source.structs){
        //varsMap[st.name] = ({type:'type',subtype:'struct',name:st.name,fields:st.fields.map(a=>{return {type:a.type,name:a.name};}),props:st.props});
        varsMap[st.name] = ({type:'type',subtype:'struct',name:st.name,fields:st.fields,props:st.props});
    }
    for(let al of source.aliases){
        varsMap[al.name] = ({type:'alias',name:al.name,aliasof:al.type});
    }
    for(let value of source.staticData){
        let type=value.type;
        let props={static:true};
        varsMap[value.name] = ({type:'value',subtype:type,props,name:value.name});
    }
    for(let def of source.defines){
        if(def.type=='bool'){
            varsMap[def.name] = ({type:'value',subtype:'int',name:def.name,props:{}});
        }else if(def.type=='eval'){
            varsMap[def.name] = ({type:'value',subtype:'double',name:def.name,props:{}});
        }else if(def.type=='function'){
            varsMap[def.name] = {type:'function',name:def.name,args:def.content.args.map(a=>'void'),returnType:'void'};
        }else if(def.type=='struct'){
            varsMap[def.name] = ({type:"value",subtype:def.content.type,name:def.name});
        }else if(def.type=='int'){
            varsMap[def.name] = ({type:'value',subtype:'int',name:def.name,props:{}});
        }else if(def.type=='string'){
            varsMap[def.name] = ({type:'value',subtype:'char *',name:def.name,props:{}});
        }else if(def.type=='float'){
            varsMap[def.name] = ({type:'value',subtype:'float',name:def.name,props:{}});
        }else if(def.type=='double'){
            varsMap[def.name] = ({type:'value',subtype:'double',name:def.name,props:{}});
        }else if(def.type=='undefined'){
            //Most likely a redefinition, check if exists
            if(def.content.body.startsWith('JS_MKVAL(')||def.content.body.startsWith('JS_MKPTR(')||def.content.body.startsWith('JS_NAN(')){
                varsMap[def.name] = {type:'value',subtype:'JSValue',name:def.name,props:{}};
            }
        }
    }
    return varsMap;
}
function updateInclude(module,includeName,key,value){
    const vars = module.gen.includeGen.tokenList.find(a=>a.text.name==includeName).text.vars;
    let varLoc=vars.findIndex(a=>a.name==key);
    if(key!=-1){
        vars[key]=value;
    }else{
        vars.push(value);
    }
}
function main() {
    let att,cb;
    // load quickjs.c since it has the enum we need
    let sourcefiles= {
        "quickjs.h": "thirdparty/quickjs/quickjs.h",
        "modules/quickjs-libc.h": "src/modules/quickjs-libc.h",
        "quickjs-atom.h": "thirdparty/quickjs/quickjs-atom.h",
        "rayjs_generated.h":"src/rayjs_generated.h",
        "default":false
    };
    let quickjsSource=new source_parser(fs.readFileSync("thirdparty/quickjs/quickjs.c", "utf8"),sourcefiles);
    let classEnum=quickjsSource.enums.find(a=>a.name===''&&a.values.some(b=>b.name==='JS_CLASS_OBJECT'));
    let classEnumLine="enum {\n";
    for(let value of classEnum.values){
        classEnumLine+=value.name+' = '+value.value+',';
    }
    classEnumLine+="\n};";


    globalThis.config=JSON.parse(fs.readFileSync('bindings/config/buildFlags.json','utf8'));//We want to re-parse inner quickjs.h, so reset info gained from quickjs.c
    let configmodule=new source_parser(fs.readFileSync("thirdparty/raylib/src/config.h", "utf8"));//only parse to add #defined
    // Box2D macro definitions for C static library context (B2_API = empty, B2_INLINE = static inline)
    globalThis.config.defined['BOX2D_EXPORT'] = {type:'undefined', content:{body:''}};
    globalThis.config.defined['B2_API']       = {type:'undefined', content:{body:''}};
    globalThis.config.defined['B2_INLINE']    = {type:'undefined', content:{body:'static inline'}};
    let toolsSource = new source_parser(fs.readFileSync("src/rayjs_base.h", "utf8"),sourcefiles);
    toolsSource=sourceToVars(toolsSource);
    toolsSource['countof']={name:'countof',type:'function',args:[{type:'any',name:'a'}],returnType:'size_t'};
    toolsSource['sizeof']={name:'sizeof',type:'function',args:[{type:'any',name:'a'}],returnType:'size_t'};
    // JS_EXTERN functions not picked up by source_parser (moved from static inline to JS_EXTERN in new quickjs); add manually
    toolsSource['JS_ToFloat64']={name:'JS_ToFloat64',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'double *',name:'pres'},{type:'JSValueConst',name:'val'}],returnType:'int'};
    toolsSource['JS_ToInt32']={name:'JS_ToInt32',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'int32_t *',name:'pres'},{type:'JSValueConst',name:'val'}],returnType:'int'};
    toolsSource['JS_ToInt64']={name:'JS_ToInt64',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'int64_t *',name:'pres'},{type:'JSValueConst',name:'val'}],returnType:'int'};
    toolsSource['JS_ToBool']={name:'JS_ToBool',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'val'}],returnType:'int'};
    toolsSource['JS_ThrowTypeError']={name:'JS_ThrowTypeError',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'const char *',name:'fmt'}],returnType:'JSValue'};
    toolsSource['JS_FreeValue']={name:'JS_FreeValue',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValue',name:'v'}],returnType:'void'};
    toolsSource['JS_FreeCString']={name:'JS_FreeCString',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'const char *',name:'ptr'}],returnType:'void'};
    toolsSource['JS_FreeContext']={name:'JS_FreeContext',type:'function',args:[{type:'JSContext *',name:'s'}],returnType:'void'};
    toolsSource['JS_FreeRuntime']={name:'JS_FreeRuntime',type:'function',args:[{type:'JSRuntime *',name:'rt'}],returnType:'void'};
    toolsSource['JS_DupContext']={name:'JS_DupContext',type:'function',args:[{type:'JSContext *',name:'ctx'}],returnType:'JSContext *'};
    toolsSource['JS_DupValue']={name:'JS_DupValue',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'v'}],returnType:'JSValue'};
    toolsSource['JS_GetRuntime']={name:'JS_GetRuntime',type:'function',args:[{type:'JSContext *',name:'ctx'}],returnType:'JSRuntime *'};
    toolsSource['JS_GetClassID']={name:'JS_GetClassID',type:'function',args:[{type:'JSValueConst',name:'v'}],returnType:'JSClassID'};
    toolsSource['JS_GetOpaque']={name:'JS_GetOpaque',type:'function',args:[{type:'JSValueConst',name:'obj'},{type:'JSClassID',name:'class_id'}],returnType:'void *'};
    toolsSource['JS_GetOpaque2']={name:'JS_GetOpaque2',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'obj'},{type:'JSClassID',name:'class_id'}],returnType:'void *'};
    toolsSource['JS_SetOpaque']={name:'JS_SetOpaque',type:'function',args:[{type:'JSValueConst',name:'obj'},{type:'void *',name:'opaque'}],returnType:'int'};
    toolsSource['JS_GetLength']={name:'JS_GetLength',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'obj'},{type:'int64_t *',name:'pres'}],returnType:'int'};
    toolsSource['JS_NewArray']={name:'JS_NewArray',type:'function',args:[{type:'JSContext *',name:'ctx'}],returnType:'JSValue'};
    toolsSource['JS_NewObject']={name:'JS_NewObject',type:'function',args:[{type:'JSContext *',name:'ctx'}],returnType:'JSValue'};
    toolsSource['JS_NewObjectClass']={name:'JS_NewObjectClass',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSClassID',name:'class_id'}],returnType:'JSValue'};
    toolsSource['JS_NewStringLen']={name:'JS_NewStringLen',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'const char *',name:'str1'},{type:'size_t',name:'len1'}],returnType:'JSValue'};
    toolsSource['JS_NewArrayBufferCopy']={name:'JS_NewArrayBufferCopy',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'const uint8_t *',name:'buf'},{type:'size_t',name:'len'}],returnType:'JSValue'};
    toolsSource['JS_NewCFunction2']={name:'JS_NewCFunction2',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSCFunction *',name:'func'},{type:'const char *',name:'name'},{type:'int',name:'length'},{type:'JSCFunctionEnum',name:'cproto'},{type:'int',name:'magic'}],returnType:'JSValue'};
    toolsSource['JS_NewCModule']={name:'JS_NewCModule',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'const char *',name:'name_str'},{type:'JSModuleInitFunc *',name:'init_func'}],returnType:'JSModuleDef *'};
    toolsSource['JS_NewClass']={name:'JS_NewClass',type:'function',args:[{type:'JSRuntime *',name:'rt'},{type:'JSClassID',name:'class_id'},{type:'const JSClassDef *',name:'class_def'}],returnType:'int'};
    toolsSource['JS_NewClassID']={name:'JS_NewClassID',type:'function',args:[{type:'JSRuntime *',name:'rt'},{type:'JSClassID *',name:'pclass_id'}],returnType:'JSClassID'};
    toolsSource['JS_GetPropertyUint32']={name:'JS_GetPropertyUint32',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'this_obj'},{type:'uint32_t',name:'idx'}],returnType:'JSValue'};
    toolsSource['JS_SetPropertyUint32']={name:'JS_SetPropertyUint32',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'this_obj'},{type:'uint32_t',name:'idx'},{type:'JSValue',name:'val'}],returnType:'int'};
    toolsSource['JS_DefinePropertyValueUint32']={name:'JS_DefinePropertyValueUint32',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'this_obj'},{type:'uint32_t',name:'idx'},{type:'JSValue',name:'val'},{type:'int',name:'flags'}],returnType:'int'};
    toolsSource['JS_SetPropertyFunctionList']={name:'JS_SetPropertyFunctionList',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'obj'},{type:'const JSCFunctionListEntry *',name:'tab'},{type:'int',name:'len'}],returnType:'int'};
    toolsSource['JS_SetClassProto']={name:'JS_SetClassProto',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSClassID',name:'class_id'},{type:'JSValue',name:'obj'}],returnType:'void'};
    toolsSource['JS_GetArrayBuffer']={name:'JS_GetArrayBuffer',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'size_t *',name:'psize'},{type:'JSValueConst',name:'obj'}],returnType:'uint8_t *'};
    toolsSource['JS_GetTypedArrayBuffer']={name:'JS_GetTypedArrayBuffer',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'obj'},{type:'size_t *',name:'pbyte_offset'},{type:'size_t *',name:'pbyte_length'},{type:'size_t *',name:'pbytes_per_element'}],returnType:'JSValue'};
    toolsSource['JS_GetTypedArrayType']={name:'JS_GetTypedArrayType',type:'function',args:[{type:'JSValueConst',name:'obj'}],returnType:'int'};
    toolsSource['JS_Call']={name:'JS_Call',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'func_obj'},{type:'JSValueConst',name:'this_obj'},{type:'int',name:'argc'},{type:'JSValueConst *',name:'argv'}],returnType:'JSValue'};
    toolsSource['JS_JSONStringify']={name:'JS_JSONStringify',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'obj'},{type:'JSValueConst',name:'replacer'},{type:'JSValueConst',name:'space0'}],returnType:'JSValue'};
    toolsSource['JS_AddModuleExport']={name:'JS_AddModuleExport',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSModuleDef *',name:'m'},{type:'const char *',name:'name_str'}],returnType:'int'};
    toolsSource['JS_AddModuleExportList']={name:'JS_AddModuleExportList',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSModuleDef *',name:'m'},{type:'const JSCFunctionListEntry *',name:'tab'},{type:'int',name:'len'}],returnType:'int'};
    toolsSource['JS_SetModuleExport']={name:'JS_SetModuleExport',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSModuleDef *',name:'m'},{type:'const char *',name:'export_name'},{type:'JSValue',name:'val'}],returnType:'int'};
    toolsSource['JS_SetModuleExportList']={name:'JS_SetModuleExportList',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSModuleDef *',name:'m'},{type:'const JSCFunctionListEntry *',name:'tab'},{type:'int',name:'len'}],returnType:'int'};
    toolsSource['JS_SetMaxStackSize']={name:'JS_SetMaxStackSize',type:'function',args:[{type:'JSRuntime *',name:'rt'},{type:'size_t',name:'stack_size'}],returnType:'void'};
    toolsSource['JS_IsArrayBuffer']={name:'JS_IsArrayBuffer',type:'function',args:[{type:'JSValueConst',name:'obj'}],returnType:'bool'};
    toolsSource['JS_IsArray']={name:'JS_IsArray',type:'function',args:[{type:'JSValueConst',name:'val'}],returnType:'bool'};
    toolsSource['JS_IsFunction']={name:'JS_IsFunction',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'val'}],returnType:'bool'};
    toolsSource['JS_IsEqual']={name:'JS_IsEqual',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValueConst',name:'op1'},{type:'JSValueConst',name:'op2'}],returnType:'int'};
    toolsSource['JS_NewAtomUInt32']={name:'JS_NewAtomUInt32',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'uint32_t',name:'n'}],returnType:'JSAtom'};
    // Raylib constants not in config.h (defined in implementation files); needed for sizeVars
    toolsSource['MAX_MESH_VERTEX_BUFFERS']={name:'MAX_MESH_VERTEX_BUFFERS',type:'value',subtype:'int',props:{}};
    toolsSource['RL_MAX_SHADER_LOCATIONS']={name:'RL_MAX_SHADER_LOCATIONS',type:'value',subtype:'int',props:{}};
    toolsSource['RL_DEFAULT_BATCH_DRAWCALLS']={name:'RL_DEFAULT_BATCH_DRAWCALLS',type:'value',subtype:'int',props:{}};
    // QuickJS memory allocation functions (JS_EXTERN in new quickjs, not static inline)
    toolsSource['js_malloc']={name:'js_malloc',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'size_t',name:'size'}],returnType:'void *'};
    toolsSource['js_free']={name:'js_free',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'void *',name:'ptr'}],returnType:'void'};
    toolsSource['js_calloc']={name:'js_calloc',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'size_t',name:'count'},{type:'size_t',name:'size'}],returnType:'void *'};
    toolsSource['js_realloc']={name:'js_realloc',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'void *',name:'ptr'},{type:'size_t',name:'size'}],returnType:'void *'};
    toolsSource['js_postMessage']={name:'js_postMessage',type:'function',args:[{type:'JSContext *',name:'ctx'},{type:'JSValue',name:'worker'},{type:'int',name:'argc'},{type:'JSValue *',name:'argv'}],returnType:'JSValue'};
    // C boolean literals — referenced as variable names by cgen when JS boolean false/true is passed to .call()
    toolsSource['false']={name:'false',type:'value',subtype:'bool',props:{}};
    toolsSource['true']={name:'true',type:'value',subtype:'bool',props:{}};
    globalThis.toolsSource=Object.values(toolsSource);
    toolsSource=undefined;
    // Load the pre-generated raylib api
    let once={};
    modules['raylib'] = new source_parser(fs.readFileSync("thirdparty/raylib/src/raylib.h", "utf8"),sourcefiles);
    attachGetters(modules['raylib']);

    att = modules['raylib'].getCallback("AudioCallback");
    att.args[0].type='float *';
    att.binding.threaded = true;
    //audioCallback has different sizes depending on what called it
    cb = structuredClone(att);
    cb.name='AudioStreamCallback';
    cb.args[0].sizeVars = ['frames*2'];
    modules['raylib'].callbacks.push(cb);
    modules['raylib'].getFunction('SetAudioStreamCallback').args[1].type='AudioStreamCallback';
    cb = structuredClone(att);
    cb.name='AudioMixedProcessor';
    //cb.args[0].type += ' &';
    cb.args[0].sizeVars = [`frames*${(config.defined['AUDIO_DEVICE_CHANNELS'] ?? {content:{body:2}}).content.body}`];
    modules['raylib'].callbacks.push(cb);
    modules['raymath']=new source_parser(fs.readFileSync("thirdparty/raylib/src/raymath.h", "utf8"),sourcefiles);
    modules['rcamera']=new source_parser(fs.readFileSync("thirdparty/raylib/src/rcamera.h", "utf8"),sourcefiles);
    modules['raygui']=new source_parser(fs.readFileSync("thirdparty/raygui/src/raygui.h", "utf8"),sourcefiles);
    modules['rlights']=new source_parser(fs.readFileSync("thirdparty/raylib/examples/shaders/rlights.h", "utf8"),sourcefiles);
    modules['reasings']=new source_parser(fs.readFileSync("thirdparty/raylib/examples/shapes/reasings.h", "utf8"),sourcefiles);
    modules['rlgl']=new source_parser(fs.readFileSync("thirdparty/raylib/src/rlgl.h", "utf8"),sourcefiles);
    modules['rlightmapper']=new source_parser(fs.readFileSync("src/rlightmapper.h", "utf8"),sourcefiles);
    const box2d_sourcefiles = Object.assign({}, sourcefiles, {
        "base.h": "thirdparty/box2d/include/box2d/base.h",
        "collision.h": "thirdparty/box2d/include/box2d/collision.h",
        "id.h": "thirdparty/box2d/include/box2d/id.h",
        "types.h": "thirdparty/box2d/include/box2d/types.h",
        "math_functions.h": "thirdparty/box2d/include/box2d/math_functions.h",
    });
    modules['box2d']=new source_parser(fs.readFileSync("thirdparty/box2d/include/box2d/box2d.h", "utf8"),box2d_sourcefiles);
    //gather shared code for rayjs_generated
    let modules_generated={
        functions: [],
        staticData: [],
        unions: [],
        callbacks: [],
        aliases: [],
        defines: [],
        comments: [],
        enums:[classEnum],
        structs:[],
    };
    for(let key in modules){
        for(let struct of modules[key].structs){
            //modules_generated.staticData.push({type:"JSClassID",name:`js_${struct.name}_class_id`});
        }
        modules_generated.structs=modules_generated.structs.concat(modules[key].structs);
    }
    modules_generated.gen = new QuickJsGenerator();

    for(let struct of modules_generated.structs){
        // Register types
        struct.props=struct.props||{};
        struct.props.bound_name = `js_${struct.name}_class_id`;
        modules_generated.gen.jsClassId(struct.props.bound_name);
        modules_generated.staticData.push({type:"JSClassID",name:struct.props.bound_name});
    }
    modules_generated.structs=[];
    for(let en of modules_generated.enums){
        // Register enum
        modules_generated.gen.cgen.enum(en.name,en.values);
    }
    fs.writeFileSync(`src/rayjs_generated.h`, modules_generated.gen.cgen.toString());

    //We dont expect to both create an include and import it, so re-creation is necessary
    includeDictionary['generated']=(gen,vars)=>{
        //gen.includeGen.include("rayjs_generated.h",vars);
    };
    includeDictionary["config"]=(gen,vars)=>{
        gen.includeGen.include("config.h",vars);
    };
    includeDictionary["raylib"]=(gen,vars)=>{
        gen.includeGen.include("raylib.h",vars);
    };
    let sharedFnNames={};
    modules['raylib'].gen = new rayjs_header("raylib",'raylib.h',sharedFnNames);
    includeDictionary["raymath"]=(gen,vars)=>{
        gen.includeGen.include("raymath.h",vars);
    };
    modules['raymath'].gen = new rayjs_header("raymath",'raymath.h',sharedFnNames);
    includeDictionary["rcamera"]=(gen,vars)=>{
        gen.includeGen.include("rcamera.h",vars);
    };
    modules['rcamera'].gen = new rayjs_header("rcamera",'rcamera.h',sharedFnNames);
    includeDictionary["raygui"]=(gen,vars)=>{
        let defines=[];
        if(!once['raygui']){
            once['raygui']=true;
            defines.push("RAYGUI_IMPLEMENTATION");
        }
        gen.includeGen.include("raygui.h",vars,defines);
    };
    modules['raygui'].gen = new rayjs_header("raygui",'raygui.h',sharedFnNames);
    includeDictionary["rlights"]=(gen,vars)=>{
        let defines=[];
        if(!once['rlights']){
            once['rlights']=true;
            defines.push("RLIGHTS_IMPLEMENTATION");
        }
        gen.includeGen.include("rlights.h",vars,defines);
    };
    modules['rlights'].gen = new rayjs_header("rlights",'rlights.h',sharedFnNames);
    includeDictionary["reasings"]=(gen,vars)=>{
        gen.includeGen.include("reasings.h",vars );
    };
    modules['reasings'].gen = new rayjs_header("reasings",'reasings.h',sharedFnNames);
    includeDictionary["rlgl"]=(gen,vars)=>{
        gen.includeGen.include("rlgl.h",vars );
    };
    modules['rlgl'].gen = new rayjs_header("rlgl",'rlgl.h',sharedFnNames);
    includeDictionary['rlightmapper']=(gen,vars)=>{
        let defines=[];
        if(!once['rlightmapper']){
            once['rlightmapper']=true;
            defines.push("RLIGHTMAPPER_IMPLEMENTATION");
        }
        gen.includeGen.include("rlightmapper.h",vars,defines);
    };
    modules['rlightmapper'].gen = new rayjs_header("rlightmapper",'rlightmapper.h',sharedFnNames);
    includeDictionary['box2d']=(gen,vars)=>{
        gen.includeGen.include("box2d/box2d.h",vars);
    };
    modules['box2d'].gen = new rayjs_header("box2d",'box2d/box2d.h',sharedFnNames);
    for(let key in modules)attachGetters(modules[key]);

    //generate hashmap of names to detect dependencies
    //This is done ahead of time to avoid ref types (&) that will be deprecated
    const namemap={};
    const namemap_val={};
    namemap['generated']=sourceToVars(modules_generated);
    namemap_val['generated']=Object.values(namemap['generated']);
    namemap['config']=sourceToVars(configmodule);
    namemap_val['config']=Object.values(namemap['config']);
    for(let key in modules){
        fixModuleRedefs(modules[key]);
        namemap[key]=sourceToVars(modules[key]);
        namemap_val[key]=Object.values(namemap[key]);
    }



    // Remove duplicate structs and functions from modules
    let dedup=new Set();
    for(let i=0;i<modules['raylib'].functions.length;i++){dedup.add(modules['raylib'].functions[i].name);}
    for(let i=0;i<modules['raylib'].structs.length;i++){dedup.add(modules['raylib'].structs[i].name);}
    for(let i=0;i<modules['raylib'].enums.length;i++){dedup.add(modules['raylib'].enums[i].name);}
    for(let i=0;i<modules['raylib'].aliases.length;i++){dedup.add(modules['raylib'].aliases[i].name);}
    for(let name in modules){
        //set access all fields by default
        for(let struct of modules[name].structs){
            struct.binding={createConstructor: true};
            const binding=struct.binding;
            for(let field of struct.fields){
                field.binding={get: true, set: true};
            }
        }
        if(name=='raylib')continue;
        removeDuplicates(modules[name],'functions',dedup);
        removeDuplicates(modules[name],'structs',dedup);
        removeDuplicates(modules[name],'enums',dedup);
        removeDuplicates(modules[name],'aliases',dedup);
    }
    att = modules['rlightmapper'].getStruct('Lightmapper');
    att.fields.find(a=>a.name=='data').binding.sizeVars=['ptr.w * ptr.h * 4'];
    att.fields.find(a=>a.name=='lm_handle').binding={};//Internal lightmapper context, no reason to bind this
    att.props.copyFunction=false;
    att = modules['raylib'].getStruct("Image");//destructor: "UnloadImage"
    att.props.copyFunction='ImageCopy';
    att = att.fields.find(a=>a.name=='data').binding;
    att.sizeVars=['GetPixelDataSize(ptr.width,ptr.height,ptr.format)'];
    att.typeCast="unsigned char *";
    //Warning! size,typeCast depends on:
    //Image Frames, see LoadImageAnim (how can we store additional frameCount data?)
    //From ImageFormat@rtextures.c:1256
    //format==PIXELFORMAT_UNCOMPRESSED_GRAYSCALE ?      image->width*image->height*sizeof(unsigned char)
    //format==PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA ?     image->width*image->height*2*sizeof(unsigned char)
    //format==PIXELFORMAT_UNCOMPRESSED_R5G6B5 ?         image->width*image->height*sizeof(unsigned short)
    //format==PIXELFORMAT_UNCOMPRESSED_R8G8B8 ?         image->width*image->height*3*sizeof(unsigned char)
    //format==PIXELFORMAT_UNCOMPRESSED_R5G5B5A1 ?       image->width*image->height*sizeof(unsigned short)
    //format==PIXELFORMAT_UNCOMPRESSED_R4G4B4A4 ?       image->width*image->height*sizeof(unsigned short)
    //format==PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 ?       image->width*image->height*4*sizeof(unsigned char)
    //format==PIXELFORMAT_UNCOMPRESSED_R32 ?            image->width*image->height*sizeof(float)
    //format==PIXELFORMAT_UNCOMPRESSED_R32G32B32 ?      image->width*image->height*3*sizeof(float)
    //format==PIXELFORMAT_UNCOMPRESSED_R32G32B32A32 ?   image->width*image->height*4*sizeof(float)
    //format==PIXELFORMAT_UNCOMPRESSED_R16 ?            image->width*image->height*sizeof(unsigned short)
    //format==PIXELFORMAT_UNCOMPRESSED_R16G16B16 ?      image->width*image->height*3*sizeof(unsigned short)
    //format==PIXELFORMAT_UNCOMPRESSED_R16G16B16A16 ?   image->width*image->height*4*sizeof(unsigned short)

    att = modules['raylib'].getStruct("Wave");//destructor: "UnloadWave"
    att = att.fields.find(a=>a.name=='data').binding;
    att.sizeVars=['ptr.frameCount*ptr.channels'];
    att.typeCast='short *';
    //modules['raylib'].getStruct("Sound");//destructor: "UnloadSound"
    att = modules['raylib'].getStruct("Music");//destructor: "UnloadMusicStream"
    att.props.copyFunction=false;
    att = att.fields.find(a=>a.name=='ctxData');att.binding.get=false;att.binding.set=false;//internal use only
    att = modules['raylib'].getStruct("ModelSkeleton");
    att.fields.find(a=>a.name=='bones').binding.sizeVars=['ptr.boneCount'];
    att.fields.find(a=>a.name=='bindPose').type='Transform *'; // ModelAnimPose typedef
    att.fields.find(a=>a.name=='bindPose').binding.sizeVars=['ptr.boneCount'];
    att = modules['raylib'].getStruct("Model");//destructor: "UnloadModel"
    att.fields.find(a=>a.name=='meshes').binding.sizeVars=['ptr.meshCount'];
    att.fields.find(a=>a.name=='meshMaterial').binding.sizeVars=['ptr.meshCount'];
    att.fields.find(a=>a.name=='materials').binding.sizeVars=['ptr.materialCount'];
    att.fields.find(a=>a.name=='skeleton').binding.get=false;att.fields.find(a=>a.name=='skeleton').binding.set=false; // nested struct, accessed via boneCount/bones/bindPose getters
    att.fields.find(a=>a.name=='currentPose').type='Transform *'; // ModelAnimPose typedef
    att.fields.find(a=>a.name=='currentPose').binding.sizeVars=['ptr.skeleton.boneCount'];
    att.fields.find(a=>a.name=='boneMatrices').binding.sizeVars=['ptr.skeleton.boneCount'];
    att = modules['raylib'].getFunction("LoadCodepoints");
    att.returnSizeVars=['count[0]'];
    att = modules['raylib'].getFunction("ComputeSHA256");
    att.returnSizeVars=[8];
    att = modules['raylib'].getStruct("ModelAnimation");
    att.fields.find(a=>a.name=='keyframePoses').type='Transform * *'; // ModelAnimPose* typedef
    att.fields.find(a=>a.name=='keyframePoses').binding.sizeVars=['ptr.keyframeCount','ptr.boneCount'];
    att = modules['raylib'].getStruct("Mesh");//destructor: "UnloadMesh"
    att.fields.find(a=>a.name=='vertices').binding.sizeVars=['ptr.vertexCount*3'];
    att.fields.find(a=>a.name=='texcoords').binding.sizeVars=['ptr.vertexCount*2'];
    att.fields.find(a=>a.name=='texcoords2').binding.sizeVars=['ptr.vertexCount*2'];
    att.fields.find(a=>a.name=='normals').binding.sizeVars=['ptr.vertexCount*3'];
    att.fields.find(a=>a.name=='tangents').binding.sizeVars=['ptr.vertexCount*4'];
    att.fields.find(a=>a.name=='colors').binding.sizeVars=['ptr.vertexCount*4'];
    att.fields.find(a=>a.name=='indices').binding.sizeVars=['ptr.vertexCount'];
    att.fields.find(a=>a.name=='animVertices').binding.sizeVars=['ptr.vertexCount*3'];
    att.fields.find(a=>a.name=='animNormals').binding.sizeVars=['ptr.vertexCount*3'];
    att.fields.find(a=>a.name=='boneIndices').binding.sizeVars=['ptr.vertexCount*4'];
    att.fields.find(a=>a.name=='boneWeights').binding.sizeVars=['ptr.vertexCount*4'];
    att.fields.find(a=>a.name=='vboId').binding.sizeVars=['MAX_MESH_VERTEX_BUFFERS'];
    att = modules['raylib'].getStruct("Shader");//destructor: "UnloadShader"
    att.fields.find(a=>a.name=='locs').binding.sizeVars=['RL_MAX_SHADER_LOCATIONS'];
    //att = modules['raylib'].getStruct("Texture");//destructor: "UnloadTexture"
    att = modules['raylib'].getStruct("Font");//destructor: "UnloadFont"
    att.fields.find(a=>a.name=='recs').binding.sizeVars=['ptr.glyphCount'];
    att.fields.find(a=>a.name=='glyphs').binding.sizeVars=['ptr.glyphCount'];
    //modules['raylib'].getStruct("RenderTexture");//destructor: "UnloadRenderTexture"
    //modules['raylib'].getStruct("MaterialMap");//destructor: "UnloadMaterialMap"
    att = modules['raylib'].getStruct("Material");
    att.fields.find(a=>a.name=='maps').binding.sizeVars=[(config.defined['MAX_MATERIAL_MAPS'] ?? {content:{body:12}}).content.body];
    att = modules['raylib'].getStruct("FilePathList");
    att.fields.find(a=>a.name=='paths').binding.sizeVars=["ptr.count"];
    att = modules['raylib'].getStruct("AutomationEventList");
    att.fields.find(a=>a.name=='events').binding.sizeVars=["ptr.count"];
    att = modules['raylib'].getFunction('GenImageFontAtlas');
    att = att.args.find(a=>a.name=='glyphRecs');
    att.type='Rectangle * &';
    att.binding.sizeVars=['glyphCount'];//?? on apiCall writeback but never
    att.binding.typeCast='void &';//?? on apiCall writeback but never
    att = modules['rlgl'].getStruct("rlVertexBuffer");
    att.fields.find(a=>a.name=='vertices').binding.sizeVars=["ptr.elementCount*3*4"];
    att.fields.find(a=>a.name=='texcoords').binding.sizeVars=["ptr.elementCount*2*4"];
    att.fields.find(a=>a.name=='normals').binding.sizeVars=["ptr.elementCount*3*4"];
    att.fields.find(a=>a.name=='colors').binding.sizeVars=["ptr.elementCount*4*4"];
    cb = att.fields.find(a=>a.name=='indices');
    if(cb!=undefined){
        cb.binding.sizeVars=["ptr.elementCount*6"];
    }
    att = modules['rlgl'].getStruct("rlRenderBatch");
    att.fields.find(a=>a.name=='vertexBuffer').binding.sizeVars=["ptr.bufferCount"];
    att.fields.find(a=>a.name=='draws').binding.sizeVars=["RL_DEFAULT_BATCH_DRAWCALLS"];

    modules['raylib'].getFunction("EndDrawing").binding = { after: gen => gen.call("app_update_quickjs", ['ctx']) };
    // Custom frame control functions
    // NOT SUPPORTED BECAUSE NEEDS COMPILER FLAG
    modules['raylib'].ignore("SwapScreenBuffer");
    modules['raylib'].ignore("PollInputEvents");
    modules['raylib'].getFunction("SetShaderValue").binding.body = (gen,header) => {
        gen.declare('bool','error',0);
        gen.declare("void *", "value", "NULL");
        header.jsToC(gen,"Shader","shader", "argv[0]");
        header.jsToC(gen,"int","locIndex", "argv[1]");
        header.jsToC(gen,"int","uniformType", "argv[3]");
        gen.call('memoryClear',['ctx']);
        let cases={
            "SHADER_UNIFORM_FLOAT":['float *','float &'],
            "SHADER_UNIFORM_VEC2":["Vector2 *",'Vector2 &'],
            "SHADER_UNIFORM_VEC3":["Vector3 *",'Vector3 &'],
            "SHADER_UNIFORM_VEC4":["Vector4 *",'Vector4 &'],
            "SHADER_UNIFORM_INT||SHADER_UNIFORM_SAMPLER2D":['int *','int &'],
            "SHADER_UNIFORM_IVEC2":["int *",'int [2]'],
            "SHADER_UNIFORM_IVEC3":["int *","int [3]"],
            "SHADER_UNIFORM_IVEC4":["int *","int [4]"],
            "SHADER_UNIFORM_UINT":['unsigned int *','unsigned int &'],
            "SHADER_UNIFORM_UIVEC2":['unsigned int *',"unsigned int [2]"],
            "SHADER_UNIFORM_UIVEC3":['unsigned int *',"unsigned int [3]"],
            "SHADER_UNIFORM_UIVEC4":['unsigned int *',"unsigned int [4]"],
            "default":[]
        };
        //Named VEC but examples and inner code use (float *) technically the same
        const sw = gen.switch("uniformType",Object.keys(cases),(ctx,i)=>{
            if(i=='default'){
                ctx.call('JS_ThrowTypeError',['ctx',`"unknown uniformType"`]);
                ctx.return("JS_EXCEPTION");
            }else{
                header.jsToC(ctx,cases[i][1],"val", "argv[2]");
                ctx.assign("value",'val(void *)');
            }
        });
        gen.call("SetShaderValue", ["shader", "locIndex", "value", "uniformType"]);
        gen.call('memoryClear',['ctx']);
        gen.return("JS_UNDEFINED");
    };
    modules['raylib'].getFunction("SetShaderValueV").binding.body = (gen,header) => {
        header.jsToC(gen,"int","count","argv[4]");
        gen.declare('bool','error',0);
        gen.declare("void *", "value", "NULL");
        header.jsToC(gen,"Shader","shader", "argv[0]");
        header.jsToC(gen,"int","locIndex", "argv[1]");
        header.jsToC(gen,"int","uniformType", "argv[3]");
        let cases={
            "SHADER_UNIFORM_FLOAT":['float *','float [size0]','count'],
            "SHADER_UNIFORM_VEC2":["Vector2 *",'Vector2 [size0]','count'],
            "SHADER_UNIFORM_VEC3":["Vector3 *",'Vector3 [size0]','count'],
            "SHADER_UNIFORM_VEC4":["Vector4 *",'Vector4 [size0]','count'],
            "SHADER_UNIFORM_INT||SHADER_UNIFORM_SAMPLER2D":['int *','int [size0]','count'],
            "SHADER_UNIFORM_IVEC2":["int *",'int [size0]','2*count'],
            "SHADER_UNIFORM_IVEC3":["int *","int [size0]",'3*count'],
            "SHADER_UNIFORM_IVEC4":["int *","int [size0]",'4*count'],
            "SHADER_UNIFORM_UINT":['unsigned int *','unsigned int [size0]','count'],
            "SHADER_UNIFORM_UIVEC2":['unsigned int *',"unsigned int [size0]",'2*count'],
            "SHADER_UNIFORM_UIVEC3":['unsigned int *',"unsigned int [size0]",'3*count'],
            "SHADER_UNIFORM_UIVEC4":['unsigned int *',"unsigned int [size0]",'4*count'],
            "default":[]
        };
        //Named VEC but examples and inner code use (float *) technically the same
        const sw = gen.switch("uniformType",Object.keys(cases),(ctx,i)=>{
            if(i=='default'){
                ctx.call('JS_ThrowTypeError',['ctx',`"unknown uniformType"`]);
                ctx.return("JS_EXCEPTION");
            }else{
                header.jsToC(ctx,cases[i][1],"val", "argv[2]",{sizeVars:[cases[i][2]]});
                ctx.assign("value",'val(void *)');
            }
        });
        gen.call("SetShaderValueV", ["shader", "locIndex", "value", "uniformType",'count']);
        gen.call('memoryClear',['ctx']);
        gen.return("JS_UNDEFINED");
    };
    modules['rlgl'].getFunction("rlSetUniform").binding.body = (gen,header) => {
        header.jsToC(gen,"int","count","argv[3]");
        gen.declare("void *", "value", "NULL");
        header.jsToC(gen,"int","locIndex", "argv[0]");
        header.jsToC(gen,"int","uniformType", "argv[2]");
        let cases={
            "SHADER_UNIFORM_FLOAT":['float *','float [size0]','count'],
            "SHADER_UNIFORM_VEC2":["Vector2 *",'Vector2 [size0]','count'],
            "SHADER_UNIFORM_VEC3":["Vector3 *",'Vector3 [size0]','count'],
            "SHADER_UNIFORM_VEC4":["Vector4 *",'Vector4 [size0]','count'],
            "SHADER_UNIFORM_INT||SHADER_UNIFORM_SAMPLER2D":['int *','int [size0]','count'],
            "SHADER_UNIFORM_IVEC2":["int *",'int [size0]','2*count'],
            "SHADER_UNIFORM_IVEC3":["int *","int [size0]",'3*count'],
            "SHADER_UNIFORM_IVEC4":["int *","int [size0]",'4*count'],
            "SHADER_UNIFORM_UINT":['unsigned int *','unsigned int [size0]','count'],
            "SHADER_UNIFORM_UIVEC2":['unsigned int *',"unsigned int [size0]",'2*count'],
            "SHADER_UNIFORM_UIVEC3":['unsigned int *',"unsigned int [size0]",'3*count'],
            "SHADER_UNIFORM_UIVEC4":['unsigned int *',"unsigned int [size0]",'4*count'],
            "default":[]
        };
        //Named VEC but examples and inner code use (float *) technically the same
        const sw = gen.switch("uniformType",Object.keys(cases),(ctx,i)=>{
            if(i=='default'){
                ctx.call('JS_ThrowTypeError',['ctx',`"unknown uniformType"`]);
                ctx.return("JS_EXCEPTION");
            }else{
                header.jsToC(ctx,cases[i][1],"val", "argv[1]",{sizeVars:[cases[i][2]]});
                ctx.assign("value",'val(void *)');
            }
        });
        gen.call("rlSetUniform", ["locIndex", "value", "uniformType",'count']);
        gen.call('memoryClear',['ctx']);
        gen.return("JS_UNDEFINED");
    };
    modules['raylib'].getFunction("SetShaderValueV").args.find(a=>a.name=='value').name='values';


    /*******OPINION*********/
    //Opinion sections exist due to developer opinion and shall be accessable behind a config flag (TODO)
    // JS User has no need to raw allocate memory
    modules['raylib'].ignore("MemAlloc");
    modules['raylib'].ignore("MemRealloc");
    modules['raylib'].ignore("MemFree");
    modules['raylib'].ignore("UnloadCodepoints");
    // JS User should never freeze process using sleep (no async will fire)
    modules['raylib'].ignore("WaitTime");
    // Right now, it is not usefull to users to get native window handler address
    modules['raylib'].ignore("GetWindowHandle");
    /*******OPINION*********/

    // SetTraceLogCallback uses va_list and as such needs custom any[] implementation
    modules['raylib'].getFunction("ComputeMD5").returnSizeVars = [4];
    modules['raylib'].getFunction("ComputeSHA1").returnSizeVars = [5];
    modules['raylib'].getFunction("LoadTextLines").returnSizeVars = ['count[0]'];
    modules['raylib'].getFunction("TextSplit").returnSizeVars = ['count[0]'];
    modules['raygui'].getFunction("GuiGetIcons").returnSizeVars = ['RAYGUI_ICON_MAX_ICONS*RAYGUI_ICON_DATA_ELEMENTS'];
    modules['raygui'].getFunction("GuiLoadIcons").returnType = "void";//returns null or unknown size buffer
    modules['raygui'].getFunction("GuiTextSplit").returnSizeVars = ["count[0]"];
    modules['raygui'].getFunction("GuiLoadIconsFromMemory").returnType = "void";//returns null or unknown size buffer
    modules['raylib'].ignore("TraceLogCallback");
    modules['raylib'].ignore("SetTraceLogCallback");
    // Files management functions
    att = modules['raylib'].getFunction("LoadFileData");
    att.args.find(a=>a.name=='dataSize').type='int &';
    att.returnSizeVars = ['dataSize[0]'];
    att.returnType = "unsigned char *";//casting to void* is an estetic choice to use buffer like SaveFileData
    att.binding.after = gen => gen.call("UnloadFileData", ["returnVal"]);
    modules['raylib'].ignore("UnloadFileData");
    att = modules['raylib'].getFunction("ExportImageToMemory");
    att.returnSizeVars = ['fileSize[0]'];
    // TODO: SaveFileData works but unnecessary makes copy of memory
    modules['raylib'].getFunction("SaveFileData").binding = {};
    modules['raylib'].getFunction("LoadFileText").binding.after = gen => gen.call("UnloadFileText", ["returnVal"]);
    modules['raylib'].ignore("UnloadFileText");
    const createFileList = (gen, loadName, unloadName, args) => {
        gen.call(loadName, args, { type: "FilePathList", name: "files" });
        gen.call("JS_NewArray", ["ctx"], { type: "JSValue", name: "ret" });
        gen.for(0, "files.count",(ctx,iter)=>{
            let tmpvar=ctx.allocVariable('str');
            ctx.call('JS_NewString',['ctx','files.paths['+iter+']'],{type:'JSValue',name:tmpvar});
            ctx.call("JS_SetPropertyUint32", ["ctx", "ret", iter, tmpvar]);
        });
        gen.call(unloadName, ["files"]);
    };
    modules['raylib'].getFunction("LoadDirectoryFiles").binding = {
        jsReturns: "string[]",
        body: (gen,header) => {
            header.jsToC(gen,"const char *", "dirPath", "argv[0]");
            createFileList(gen, "LoadDirectoryFiles", "UnloadDirectoryFiles", ["dirPath"]);
            gen.call('memoryClear',['ctx']);
            gen.return("ret");
        }
    };
    modules['raylib'].getFunction("LoadDirectoryFilesEx").binding = {
        jsReturns: "string[]",
        body: (gen,header) => {
            header.jsToC(gen,"const char *", "basePath", "argv[0]");
            header.jsToC(gen,"const char *", "filter", "argv[1]",{allowNull:true});
            header.jsToC(gen,"bool", "scanSubdirs", "argv[2]");
            createFileList(gen, "LoadDirectoryFilesEx", "UnloadDirectoryFiles", ["basePath", "filter", "scanSubdirs"]);
            gen.call('memoryClear',['ctx']);
            gen.return("ret");
        }
    };
    modules['raylib'].ignore("UnloadDirectoryFiles");
    modules['raylib'].getFunction("LoadDroppedFiles").binding = {
        jsReturns: "string[]",
        body: gen => {
            createFileList(gen, "LoadDroppedFiles", "UnloadDroppedFiles", []);
            gen.return("ret");
        }
    };
    modules['raylib'].ignore("UnloadDroppedFiles");
    modules['raylib'].getFunction("LoadImageColors").binding = {
        jsReturns: "ArrayBuffer",
        body: (gen,header) => {
            header.jsToC(gen,"Image", "image", "argv[0]");
            gen.call("LoadImageColors", ["image"], { name: "colors", type: "Color *" });
            gen.call('JS_NewArrayBufferCopy',['ctx','colors','image.width*image.height*sizeof(Color)'],{type:'JSValue',name:'retVal'});
            gen.call("UnloadImageColors", ["colors"]);
            gen.call('memoryClear',['ctx']);
            gen.return("retVal");
        }
    };
    let applyffix=false;
    const lfx = modules['raylib'].getFunction("LoadFontEx");
    lfx.args[2].binding = { allowNull: true };
    if(!config.bindText){
        //Text functions are enabled for compatibility
        modules['raylib'].functions.filter(x => x.name.startsWith("Text")).forEach(x => modules['raylib'].ignore(x.name));
        let att=modules['raygui'].getFunction("GuiTextSplit");
        att.returnSizeVars = ["count[0]","returnVal[i+1])-returnVal[i]"];
        att.returnType="unsigned char";
    }else{
        /*******OPINION*********/
        //Using textCopy is more cumbersome than doing it natively, due to not supporting C string offsets
        modules['raylib'].ignore("TextCopy");
        modules['raygui'].ignore("GetTextLines");//handled natively, dont use
        /*******OPINION*********/
        //modules['raylib'].getFunction("TextCopy").args.find(parm => parm.name === 'dst').type='char * &';
        modules['raylib'].getFunction("TextFormat").binding.body=(gen,header)=>{
            //TODO: Can improve performance by reusing buffers (static)
            let bufferdefined=false;
            const errorCleanupFn =(ctx)=>{
                ctx.call('memoryClear',['ctx']);
                ctx.call('js_free',['ctx','char_ptr']);
                if(bufferdefined)ctx.call('js_free',['ctx','buffer']);
            };
            let flags={dynamicAlloc:true};//reduces code size

            gen.declare('size_t','char_ptrlen',10);
            gen.call('js_calloc',['ctx', 'char_ptrlen', 'sizeof(char)'],{type:'char *',name:'char_ptr'});
            gen.declare("int64_t","formatlen");
            gen.if('JS_GetLength(ctx,argv[0],formatlen)==-1',(ctx)=>{
                errorCleanupFn(ctx);
                ctx.return("JS_EXCEPTION");
            });
            header.jsToC(gen,'char *','format','argv[0]');
            gen.declare('char *','subformat',`format`);
            gen.declare('size_t','subformatlen',0);
            gen.declare('char','subformatlenh');
            gen.declare('size_t','bufferlen','formatlen*2');
            gen.call('js_calloc',['ctx','bufferlen','sizeof(char)'],{type:'char *',name:'buffer'});
            bufferdefined=true;
            gen.declare('int','l',0);
            gen.declare('int','c',1);
            gen.declare('int','ilen',0);
            gen.for(0, 'formatlen',(ctx)=>{
                ctx.if(["format[i]!='%'",''],(ctx)=>{
                    ctx.assign('buffer[l]','format[i]');
                    ctx.add('int','l',1);
                },(ctx)=>{
                    ctx.declare('int','n',2);
                    ctx.declare('int','w',0);
                    ctx.declare('int','p',0);
                    ctx.declare('int','firsth','i+1');
                    ctx.declare('char','har','format[firsth]');
                    ctx.if('har==0',(ctx)=>{
                        (new QuickJsGenerator(ctx)).cToJs('char *','ret','buffer',{},0,['l']);
                        errorCleanupFn(ctx);
                        ctx.return('ret');
                    });

                    ctx.while("!(har>=97&&har<=122)&&!(har>=65&&har<=90)&&har!='%'",(ctx)=>{
                        ctx.add('int','firsth',1);
                        ctx.declare('char','har','format[firsth]');
                        ctx.if('har==0',(ctx)=>{
                            (new QuickJsGenerator(ctx)).cToJs('char *','ret','buffer',{},0,['l']);
                            errorCleanupFn(ctx);
                            ctx.return('ret');
                        });
                    });
                    ctx.declare('int','lasth','firsth');
                    ctx.assign('har','format[lasth]');
                    ctx.while('strchr("diuoxXfFeEfFeEgGaAcspn%", har)==NULL',(ctx)=>{
                        ctx.if("har=='*'",(ctx)=>{
                            ctx.if("n==1",(ctx)=>{
                                ctx.declare('int','w','p');
                            });
                            header.jsToC(ctx,'int','p','argv[c]');
                            ctx.add('int','c',1);
                            ctx.sub('int','n',1);
                        });
                        ctx.add('','lasth',1);
                        ctx.declare('char','har','format[lasth]');
                        ctx.if('har==0',(ctx)=>{
                            (new QuickJsGenerator(ctx)).cToJs('char *','ret','buffer',{},0,['l']);
                            errorCleanupFn(ctx);
                            ctx.return('ret');
                        });
                    });
                    ctx.declare('size_t','subformatlen','lasth-i+1');
                    ctx.declare('char','subformatlenh','format[lasth+1]');
                    ctx.declare('char *','subformat','format+i');
                    ctx.assign('subformat[subformatlen]',0);
                    ctx.if("format[lasth]=='%'",(ctx)=>{
                        ctx.declare('int','i','lasth');
                        ctx.assign("buffer[l]","'%'");
                        ctx.add('int',"l",1);
                        ctx.continue();
                    });
                    ctx.call('memset',['char_ptr',0,'ilen * sizeof(char)']);
                    ctx.switch('har',["'d'||'i'","'u'||'o'||'x'||'X'","'f'||'F'||'e'||'E'||'g'||'G'||'a'||'A'","'c'","'s'","'p'","'n'"],(ctx,cas)=>{
                        switch(cas){
                            case "'d'||'i'":{
                                header.jsToC(ctx,'int64_t','a','argv[c]');
                                ctx.if(['firsth==lasth',''],(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(int)a'],{type:'char *',name:'char_ptr'});
                                },(ctx)=>{
                                    ctx.switch('format[lasth-1]',["'h'","'l'","'j'","'z'","'t'"],(ctx,cas)=>{
                                        switch(cas){
                                            case "'h'":{
                                                ctx.if(["subformat[lasth-i-2]=='h'",''],(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(signed char)a'],{type:'char *',name:'char_ptr'});
                                                },(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(short int)a'],{type:'char *',name:'char_ptr'});
                                                });
                                            }break;
                                            case "'l'":{
                                                ctx.if(["subformat[lasth-i-2]=='l'",''],(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(long long int)a'],{type:'char *',name:'char_ptr'});
                                                },(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(long int)a'],{type:'char *',name:'char_ptr'});
                                                });
                                            }break;
                                            case "'j'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(intmax_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                            case "'z'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(size_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                            case "'t'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(ptrdiff_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                            //Dont do anything on default, if this is a broken format, let it be skipped
                                        }
                                    });
                                });
                            }break;
                            case "'u'||'o'||'x'||'X'":{
                                header.jsToC(ctx,'uint32_t','a','argv[c]');
                                ctx.if(['firsth==lasth',''],(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(unsigned int)a'],{type:'char *',name:'char_ptr'});
                                },(ctx)=>{
                                    ctx.switch('subformat[lasth-i-1]',["'h'","'l'","'j'","'z'","'t'"],(ctx,cas)=>{
                                        switch(cas){
                                            case "'h'":{
                                                ctx.if(["subformat[lasth-i-2]=='h'",''],(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(unsigned char)a'],{type:'char *',name:'char_ptr'});
                                                },(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(unsigned short int)a'],{type:'char *',name:'char_ptr'});
                                                });
                                            }break;
                                            case "'l'":{
                                                ctx.if(["subformat[lasth-i-2]=='l'",''],(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(unsigned long long int)a'],{type:'char *',name:'char_ptr'});
                                                },(ctx)=>{
                                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(unsigned long int)a'],{type:'char *',name:'char_ptr'});
                                                });
                                            }break;
                                            case "'j'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(uintmax_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                            case "'z'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(size_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                            case "'t'":{
                                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(ptrdiff_t)a'],{type:'char *',name:'char_ptr'});
                                            }break;
                                        }
                                        //Dont do anything on default, if this is a broken format, let it be skipped
                                    });
                                });
                            }break;
                            case "'f'||'F'||'e'||'E'||'g'||'G'||'a'||'A'":{
                                header.jsToC(ctx,'double','a','argv[c]');
                                ctx.if(['firsth==lasth',''],(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(double)a'],{type:'char *',name:'char_ptr'});
                                },(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(long double)a'],{type:'char *',name:'char_ptr'});
                                });
                            }break;
                            case "'c'":{
                                header.jsToC(ctx,'char','a','argv[c]');
                                ctx.if(['firsth==lasth',''],(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(int)a'],{type:'char *',name:'char_ptr'});
                                },(ctx)=>{
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(wint_t)a'],{type:'char *',name:'char_ptr'});
                                });
                            }break;
                            case "'s'":{
                                ctx.if(['firsth==lasth',''],(ctx)=>{
                                    header.jsToC(ctx,'char *','a','argv[c]');
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','a'],{type:'char *',name:'char_ptr'});
                                },(ctx)=>{
                                    header.jsToC(ctx,'wchar_t *','a','argv[c]');
                                    ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','a'],{type:'char *',name:'char_ptr'});
                                });
                            }break;
                            case "'p'":{
                                ctx.call('asnprintf',['ctx','char_ptr','char_ptrlen','subformat','n','w','p','(void *)&argv[c]'],{type:'char *',name:'char_ptr'});
                            }break;
                            case "'n'":{
                                (new QuickJsGenerator(ctx)).cToJs('int','argv[c]','l',{dynamicAlloc:true,supressDeclaration:true});
                            }break;
                        }
                    });
                    ctx.assign('subformat[subformatlen]','subformatlenh');
                    ctx.add('int','c',1);
                    ctx.call('strlen',['char_ptr'],{type:'int',name:'ilen'});
                    ctx.declare('int','maxstrlen','formatlen+l+ilen-lasth');
                    ctx.if('bufferlen<maxstrlen',(ctx)=>{
                        ctx.call('js_realloc',['ctx','buffer','maxstrlen'],{type:'char *',name:'buffer'});
                        ctx.call('memset',['buffer+bufferlen',0,'maxstrlen-bufferlen']);
                        ctx.declare('int','bufferlen','maxstrlen');
                    });
                    ctx.call('strncpy',['buffer+l','char_ptr','ilen']);
                    ctx.add('int','l','ilen');
                    ctx.declare('int','i','lasth');
                });
            });
            (new QuickJsGenerator(gen)).cToJs('char *','js_buffer','buffer');
            errorCleanupFn(gen);
            gen.return('js_buffer');
        };
    }
    att = modules['raylib'].getFunction("LoadWaveSamples");
    att.returnSizeVars = ['wave.frameCount*wave.channels'];
    att.binding.after = gen => gen.call("UnloadWaveSamples", ["returnVal"]);
    // requires returning pointer
    att = modules['rlgl'].getFunction("rlReadTexturePixels");
    att.returnType="unsigned char *";
    if(config.defined['GRAPHICS_API_OPENGL_11'] || config.defined['GRAPHICS_API_OPENGL_33']){
        att.returnSizeVars = ['GetPixelDataSize(width, height, format)'];
    }else if(config.defined['GRAPHICS_API_OPENGL_ES2']){
        att.returnSizeVars = ['GetPixelDataSize(width, height, RL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8)'];
    }else{
        modules['rlgl'].ignore("rlReadTexturePixels");
    }
    att = modules['rlgl'].getFunction('rlLoadTexture');
    att.args[0].binding.allowNull=true;
    att = modules['rlgl'].getFunction("rlGetShaderLocsDefault");
    att.returnSizeVars = [String(config.defined['RL_MAX_SHADER_LOCATIONS'].content.body)];
    // Wave/Sound management functions
    modules['raylib'].ignore("SetAudioStreamCallback");
    modules['raylib'].ignore("AttachAudioStreamProcessor");
    modules['raylib'].ignore("DetachAudioStreamProcessor");
    modules['raylib'].getFunction('AttachAudioMixedProcessor').args[0].type='AudioMixedProcessor';
    att = modules['raylib'].getCallback("SaveFileDataCallback");
    att.args[1].type='unsigned char *';
    att.args[1].sizeVars=['dataSize'];
    // Requires fixes to void* parameters
    modules['rlgl'].ignore("rlLoadExtensions");
    modules['rlgl'].ignore("rlSetVertexAttributeDefault");
    //modules['rlgl'].ignore("rlSetUniform");
    modules['rlgl'].ignore("rlGetProcAddress");
    att = modules['raylib'].getFunction("LoadRandomSequence");
    att.returnSizeVars = ['count'];
    att.binding = { after: gen => gen.call("UnloadRandomSequence", ['returnVal']) };
    att = modules['rlgl'].getFunction("rlReadScreenPixels");
    att.returnSizeVars = ['width*height*4'];
    att = modules['rlgl'].getFunction("rlLoadShaderBuffer");
    att.args[1].binding.allowNull=true;
    att = modules['raylib'].getFunction("LoadModelAnimations");
    att.returnSizeVars = ['animCount[0]'];
    function detectPointer(fn){//A compressed way to separate pointers from arrays with the advantage of being somewhat generic
        for(let i=0;i<fn.args.length;i++){
            const parm=fn.args[i];
            if(parm.type.endsWith(' *')>0){
                if(fn.args.length==1 && parm.type.endsWith('char *')){//Arrays tend to require length int but strings not
                    continue;
                }
                const name=parm.name.toLowerCase();
                const subtype=parm.type.toLowerCase().substring(0,parm.type.length-2);
                //common names
                if(name==subtype || ['dst','texture','view','active','alpha','filesize','datasize','count','position','frames','lm','checked','scrollindex','codepointsize','animcount'].includes(name)){
                    parm.type=parm.type.replaceAt(parm.type.length-1,'&');
                }else
                if(name.endsWith('s')){
                    continue;
                }else
                if(subtype.startsWith('vector') || subtype.startsWith('quaternion')){
                    parm.type=parm.type.replaceAt(parm.type.length-1,'&');
                }
            }
        }
    }
    //manual reference assignment
    att = modules['raygui'].getFunction('GuiColorPicker').args[2];
    att.type = att.type.replaceAt(att.type.length-1,'&');
    for(let key in modules){
        modules[key].functions.forEach(detectPointer);
        modules[key].callbacks.forEach(detectPointer);
    }
    att = modules['raygui'].getFunction('GuiTextBox').args[1];
    att.type = att.type + ' &';
    att = modules['raygui'].getFunction('GuiValueBoxFloat').args[1];
    att.type = att.type + ' &';
    att.binding.allowNull=true;
    cb = modules['raylib'].getStruct('AudioStream').fields;
    att = cb.find(field=>field.name=='buffer');
    att.type = att.type.replace(" *"," &");
    att = cb.find(field=>field.name=='processor');
    att.type = att.type.replace(" *"," &");
    //Dont allow using buffer (searching for typedef source is not supported yet)
    att = modules['raylib'].getStruct('AudioStream');
    att.fields.find(a=>a.name=='buffer').binding = {};
    att.fields.find(a=>a.name=='processor').binding = {};
    modules['raylib'].getStruct('rAudioBuffer').binding.createConstructor=false;
    modules['raylib'].getStruct('rAudioProcessor').binding.createConstructor=false;

    att = modules['raylib'].getFunction('LoadFontData');
    att.args[3].binding.allowNull=true;
    att.returnSizeVars=[['codepointCount > 0','','codepointCount','95']];//New functionality, sizevars need to accept (nested) conditionals
    modules['raylib'].getFunction('LoadShader').args[0].binding.allowNull=true;
    modules['raygui'].getFunction('GuiSpinner').args[1].binding.allowNull=true;
    modules['raygui'].getFunction('GuiValueBox').args[1].binding.allowNull=true;
    modules['raygui'].getFunction('GuiColorPicker').args[1].binding.allowNull=true;
    att=modules['raygui'].getFunction('GuiSlider');
    att.args[1].binding.allowNull=true;//textleft
    att.args[2].binding.allowNull=true;//textright
    att = modules['raygui'].getFunction('GuiSliderBar');
    att.args[1].binding.allowNull=true;
    att.args[2].binding.allowNull=true;
    att = modules['raygui'].getFunction('GuiDrawText');
    att.args[0].binding.allowNull=true;
    modules['raygui'].getFunction('GuiProgressBar').args[1].binding.allowNull=true;
    modules['raygui'].getFunction('GuiIconText').args[1].binding.allowNull=true;
    att=modules['raygui'].getFunction('GuiScrollPanel');
    att.args[1].binding.allowNull=true;
    att.args[4].binding.allowNull=true;
    att=modules['raygui'].getFunction('GuiStatusBar');
    att.args[1].binding.allowNull=true;
    att=modules['raygui'].getFunction('GuiPanel');
    att.args[1].binding.allowNull=true;
    att=modules['raygui'].getFunction('GuiGrid');
    att.args.find(a=>a.name=="text").binding.allowNull=true;
    att.args.find(a=>a.name=="mouseCell").binding.allowNull=true;
    modules['raygui'].getFunction('GuiColorBarAlpha').args[1].binding.allowNull=true;
    modules['raygui'].getFunction('GuiTextInputBox').args[6].binding.allowNull=true;
    modules['raygui'].getFunction('GuiListViewEx').args[1].binding.allowNull=true;
    modules['raylib'].getFunction('LoadAutomationEventList').args[0].binding.allowNull=true;
    modules['raygui'].functions.push({
        returnType:'float', name:'GuiGetAlpha', args:[], props:{}, binding:{body:(gen,header)=>{
                (new QuickJsGenerator(gen)).cToJs('float','ret','guiAlpha');
                gen.return('ret');
            }}
    });
    modules['raygui'].functions.push({
        returnType:'bool', name:'GuiIsExclusive', args:[], props:{}, binding:{body:(gen,header)=>{
            (new QuickJsGenerator(gen)).cToJs('bool','ret','guiControlExclusiveMode');
            gen.return('ret');
        }}
    });

    modules['raylib'].ignore('bool');

    // Box2D customizations
    // Ignore low-level alloc/assert hooks (not useful from JS)
    modules['box2d'].ignore("b2SetAllocator");
    modules['box2d'].ignore("b2SetAssertFcn");
    // Ignore internal assert (exposed via !NDEBUG only, not in the public API surface)
    modules['box2d'].ignore("b2InternalAssertFcn");
    // b2DebugDraw has function-pointer fields for rendering callbacks — mark all non-bindable
    // (users integrate debug draw via custom C code, not from JS)
    // b2DebugDraw requires C function pointer callbacks — not usable from JS
    att = modules['box2d'].getStruct("b2DebugDraw");
    if(att) att.binding.ignore=true;
    // General pass: disable void* fields and function-pointer fields in all box2d structs
    // (void* cannot be meaningfully used in JS; function pointers are C-only callbacks)
    for(const s of modules['box2d'].structs){
        for(const field of s.fields){
            const t=field.type.trim();
            if(t==='void *' || t==='void*' || (t.includes('(') && t.includes('*'))){
                field.binding.get=false; field.binding.set=false;
            }
        }
    }
    // b2WorldDef: disable threading fields and internal value
    att = modules['box2d'].getStruct("b2WorldDef");
    if(att){
        for(const fname of ['enqueueTask','finishTask','userTaskContext','frictionCallback','restitutionCallback','internalValue']){
            const f=att.fields.find(a=>a.name===fname);
            if(f){f.binding.get=false; f.binding.set=false;}
        }
    }
    // Disable internalValue on all def structs (Box2D uses it to detect uninitialized defs)
    for(const sname of ['b2BodyDef','b2ShapeDef','b2ChainDef','b2DistanceJointDef','b2MotorJointDef',
                        'b2MouseJointDef','b2FilterJointDef','b2PrismaticJointDef','b2RevoluteJointDef',
                        'b2WeldJointDef','b2WheelJointDef']){
        att=modules['box2d'].getStruct(sname);
        if(att){
            const iv=att.fields.find(a=>a.name==='internalValue');
            if(iv){iv.binding.get=false; iv.binding.set=false;}
        }
    }
    // Event structs: set sizeVars for array-pointer fields
    att=modules['box2d'].getStruct("b2SensorEvents");
    if(att){
        att.fields.find(a=>a.name==='beginEvents').binding.sizeVars=['ptr.beginCount'];
        att.fields.find(a=>a.name==='endEvents').binding.sizeVars=['ptr.endCount'];
    }
    att=modules['box2d'].getStruct("b2ContactEvents");
    if(att){
        att.fields.find(a=>a.name==='beginEvents').binding.sizeVars=['ptr.beginCount'];
        att.fields.find(a=>a.name==='endEvents').binding.sizeVars=['ptr.endCount'];
        att.fields.find(a=>a.name==='hitEvents').binding.sizeVars=['ptr.hitCount'];
    }
    att=modules['box2d'].getStruct("b2BodyEvents");
    if(att){
        att.fields.find(a=>a.name==='moveEvents').binding.sizeVars=['ptr.moveCount'];
    }
    // b2ChainDef: const pointer fields are read-only arrays
    att=modules['box2d'].getStruct("b2ChainDef");
    if(att){
        const pts=att.fields.find(a=>a.name==='points');
        if(pts){pts.binding.sizeVars=['ptr.count']; pts.binding.set=false;}
        const mats=att.fields.find(a=>a.name==='materials');
        if(mats){mats.binding.sizeVars=['ptr.materialCount']; mats.binding.set=false;}
    }
    // b2BodyMoveEvent: userData void* — leave as no get/set
    att=modules['box2d'].getStruct("b2BodyMoveEvent");
    if(att){
        const ud=att.fields.find(a=>a.name==='userData');
        if(ud){ud.binding.get=false; ud.binding.set=false;}
    }
    // b2Counters.colorCounts is a fixed array [12]
    att=modules['box2d'].getStruct("b2Counters");
    if(att){
        const cc=att.fields.find(a=>a.name==='colorCounts');
        if(cc)cc.binding.sizeVars=[12];
    }
    // b2World_Draw uses b2DebugDraw* which has function pointers — ignore for now
    modules['box2d'].ignore("b2World_Draw");
    // b2World_OverlapAABB/Shape and Cast functions accept void* context alongside callbacks
    // The callbacks (b2OverlapResultFcn, b2CastResultFcn) are useful but need special handling;
    // ignore the raw void* context versions for now (users call via JS function wrapping)
    modules['box2d'].ignore("b2World_OverlapAABB");
    modules['box2d'].ignore("b2World_OverlapShape");
    modules['box2d'].ignore("b2World_CastRay");
    modules['box2d'].ignore("b2World_CastShape");
    modules['box2d'].ignore("b2World_CastMover");
    modules['box2d'].ignore("b2World_CollideShape");
    modules['box2d'].ignore("b2World_SetCustomFilterCallback");
    modules['box2d'].ignore("b2World_SetPreSolveCallback");
    // b2DynamicTree is an internal BVH structure — dynamic array of nodes with no fixed size
    const dTree=modules['box2d'].getStruct("b2DynamicTree");
    if(dTree) dTree.binding.ignore=true;
    // Ignore b2Hash (low-level utility, takes uint8_t* data)
    modules['box2d'].ignore("b2Hash");
    // b2GetMillisecondsAndReset takes uint64_t* (output param) — ignore to avoid complexity
    modules['box2d'].ignore("b2GetMillisecondsAndReset");
    // b2Shape_GetContactData and b2Body_GetContactData return arrays via output params
    modules['box2d'].ignore("b2Shape_GetContactData");
    modules['box2d'].ignore("b2Body_GetContactData");
    // void* UserData functions — can't represent untyped pointers in JS
    modules['box2d'].ignore("b2World_SetUserData");
    modules['box2d'].ignore("b2World_GetUserData");
    modules['box2d'].ignore("b2Body_SetUserData");
    modules['box2d'].ignore("b2Body_GetUserData");
    modules['box2d'].ignore("b2Shape_SetUserData");
    modules['box2d'].ignore("b2Shape_GetUserData");
    modules['box2d'].ignore("b2Joint_SetUserData");
    modules['box2d'].ignore("b2Joint_GetUserData");
    // b2World_CollideMover uses callback
    modules['box2d'].ignore("b2World_CollideMover");
    // Friction/restitution callbacks are C function pointers — not callable from JS
    modules['box2d'].ignore("b2World_SetFrictionCallback");
    modules['box2d'].ignore("b2World_SetRestitutionCallback");

    for(let key in modules){
        const module=modules[key];
        module.aliases.forEach(x => module.gen.registerAlias(x));
    }
    let guirefFuntions=["GuiSpinner", "GuiValueBox", "GuiValueBoxFloat", "GuiSlider", "GuiSliderBar", "GuiProgressBar", "GuiScrollBar"];
    for(let fnname of guirefFuntions){
        att=modules['raygui'].getFunction(fnname).args.find(a=>a.name=='value');
        att.type=att.type.replaceAll('*','&');
    }

    //Generate Code
    for(let key in modules){
        const module=modules[key];
        console.log("Module: "+key);
        includeDictionary['config'](modules[key].gen,namemap_val['config']);
        includeDictionary['generated'](modules[key].gen,namemap_val['generated']);
        //need to figure out if module requires other modules
        let checks={};
        for(let fn of module.functions){
            for(let param of fn.args){
                for(let type of param.type.split(' ')){
                    checks[type]=true;
                }
            }
        }
        for(let alias of module.aliases){
            for(let type of alias.type.split(' ')){
                checks[type]=true;
            }
        }
        for(let callback of module.callbacks){
            for(let param of callback.args){
                for(let type of param.type.split(' ')){
                    checks[type]=true;
                }
            }
        }
        checks=Object.keys(checks).filter(type=>!defaultTypeParts.includes(type));
        for(let modulekey in modules){
            if(modulekey==key){
                includeDictionary[key](modules[key].gen,namemap_val[modulekey]);
                continue;
            }
            const namemap_module=namemap[modulekey]
            for(let check of checks){
                while(namemap[key][check] && namemap[key][check].type=='alias'){
                    check=namemap[key][check].aliasof;
                }
                if(namemap_module[check] && !namemap[key][check]){
                    includeDictionary[modulekey](modules[key].gen,namemap_val[modulekey]);
                    break;
                }
            }
        }
        module.enums.forEach(x => module.gen.preRegisterEnum(x));
        module.structs.forEach(x => module.gen.addApiStruct_object(x));
        //On top level, before assigning functions, check for callbacks, if present in a function, add callback first
        const callbacks=module.callbacks.map(c=>c.name);
        module.functions.forEach(fn => {
            let param=fn.args.find(param=>callbacks.includes(param.type));
            if(param!==undefined){
                let callback=module.callbacks.find(a=>a.name==param.type);
                let capture=[];
                const attachmode=simpleregex(fn.name.toLowerCase(),['os','set','os','attach'],0,capture);
                capture=capture.join('');
                if(capture=='')return;
                module.gen.addCallback("callback_"+callback.name,param.type,callback,capture=='attach',callback.binding.threaded==true);
            }
        });
        module.functions.forEach(x => module.gen.addApiFunction(x));
        module.enums.forEach(x => module.gen.addEnum(x));
        module.defines.forEach(x => {
            if(x.type=='bool' && x.name.endsWith('_H'))return;//GUARD
            if(x.type=='int'){
                module.gen.exportGlobalInt(x.name,x.binding.comment);
            }
            if(x.type=='float' || x.type=='double'){
                module.gen.exportGlobalDouble(x.name,x.binding.comment);
            }
            if(x.type=='struct'){
                module.gen.exportGlobalStruct(x.content.body.type, x.name, x.content.body.values, x.binding.comment);
            }
            if(x.type=='undefined' && module.gen.exported[x.content]!=undefined){
                const aliasof=module.gen.exported[x.content];
                if(aliasof=='int'){
                    module.gen.exportGlobalInt(x.name,x.binding.comment);
                }else if(aliasof=='float'){
                    module.gen.exportGlobalDouble(x.name,x.binding.comment);
                }
            }
        });
    }
    //Write to file
    try{
        for(let key in modules){
            const module=modules[key];
            console.log("Writing module "+module.gen.name);
            module.gen.writeTo(`src/modules/js_${module.gen.name}.h`);
            module.gen.typings.writeTo(`bindings/typings/lib.js_${module.gen.name}.d.ts`,{variables:module.gen.definitions.cgen.getVariables(),includegen:module.gen.includeGen,modules});
            const ignored = modules[key].functions.filter(x => x.binding.ignore).length;
            console.log(`Converted ${modules[key].functions.length+modules[key].structs.length+modules[key].callbacks.length - ignored}, ${ignored} ignored.`);
        }
        console.log("Success!");
    }catch(e){
        console.log(e);
    }
}
try{
    main();
}catch(e){
    console.log(e);
}
