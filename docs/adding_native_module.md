# Adding a Native C Library as a rayjs Module

Reference implementation: Box2D v3 → `rayjs:box2d`.  
Follow the same pattern for any future C library.

---

## Step 1 — Add the library as a git submodule

```bash
git submodule add <url> thirdparty/<name>
git -C thirdparty/<name> checkout <tag>
```

---

## Step 2 — Wire into CMakeLists.txt

After the existing raylib `add_subdirectory` block, add three things:

```cmake
# 1. Build the library (disable tests/docs)
message("=== Configure <Name> ===")
set(<NAME>_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(<NAME>_BUILD_TESTBED    OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/<name> EXCLUDE_FROM_ALL)

# 2. Include path for generated headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/<name>/include)

# 3. Link the library
set(RAYJS_LINK_LIBRARIES "${RAYJS_LINK_LIBRARIES}" "<cmake-target>")
```

The CMake target name comes from the library's own CMakeLists.txt (`add_library(<target> ...)`).  
For Box2D v3 it is `box2d`.

---

## Step 3 — Extend the binding generator (`bindings/src/index.js`)

Four additions in order:

### 3a. Parse the header (near other module definitions)
```js
modules['<name>'] = new source_parser(
    fs.readFileSync("thirdparty/<name>/include/<name>/<name>.h", "utf8"),
    sourcefiles
);
```

### 3b. Register the include dictionary
```js
includeDictionary['<name>'] = (gen, vars) => {
    gen.includeGen.include("<name>/<name>.h", vars);
};
```

### 3c. Attach a generator
```js
modules['<name>'].gen = new rayjs_header("<name>", '<name>/<name>.h', sharedFnNames);
```

### 3d. Customizations (before the Generate Code loop)

Common patterns used for Box2D v3:

**Ignore threading/internal functions:**
```js
modules['box2d'].ignore("b2SetAllocator");
modules['box2d'].ignore("b2SetAssertFcn");
```

**Disable inaccessible struct fields (function pointers, threading):**
```js
const worldDef = modules['box2d'].getStruct("b2WorldDef");
if (worldDef) {
    for (const f of ['enqueueTask','finishTask','userTaskContext','workerCount']) {
        const field = worldDef.fields.find(a => a.name === f);
        if (field) { field.binding.get = false; field.binding.set = false; }
    }
}
```

**Disable setters on const pointer array fields:**
```js
const chainDef = modules['box2d'].getStruct("b2ChainDef");
if (chainDef) {
    const pts = chainDef.fields.find(a => a.name === 'points');
    if (pts) { pts.binding.sizeVars = ['ptr.count']; pts.binding.set = false; }
}
```

**Provide size vars for pointer array fields on event structs:**
```js
const contactEvents = modules['box2d'].getStruct("b2ContactEvents");
if (contactEvents) {
    contactEvents.fields.find(a=>a.name==='beginEvents').binding.sizeVars=['ptr.beginCount'];
    contactEvents.fields.find(a=>a.name==='endEvents').binding.sizeVars=['ptr.endCount'];
    contactEvents.fields.find(a=>a.name==='hitEvents').binding.sizeVars=['ptr.hitCount'];
}
```

---

## Step 4 — Register the module in the runtime

**`src/rayjs_base.h`** — add an `extern` declaration alongside the others:
```c
extern JSModuleDef * js_init_module_<name>(JSContext * ctx, const char * module_name);
```

**`src/rayjs_base.c`** — call it in `JS_NewCustomContext()` after the last module:
```c
js_init_module_<name>(ctx, "rayjs:<name>");
```

**`src/rayjs.c`** — include the generated header after the last module include:
```c
#include "modules/js_<name>.h"
```

---

## Step 5 — Run the generator

```bash
node bindings/src/index.js
```

Produces:
- `src/modules/js_<name>.h`
- `bindings/typings/lib.js_<name>.d.ts`
- Updates `src/rayjs_generated.h`

Then build:
```bash
cmake --build build
```

Iterate: fix generator customizations → regenerate → rebuild until clean.

---

## Known generator bugs fixed during Box2D integration

These fixes are permanent in the codebase:

### 1. Enum → int32 conversion (`bindings/src/quickjs.js`)
`cToJs` was emitting `ctx.call('JS_NewInt32', ['ctx', '(int)(src)'])`. The `(int)(localvar)` form breaks `compilefunctionargs`: it resolves the cast `(int)` as the initial value and drops `(localvar)` silently, producing `(int32_t)int` in C.  
**Fix:** Pass `src` directly — `cast()` handles `EnumType → int32_t` automatically.

### 2. Enum fields declared as pointers (`bindings/src/raylib-header.js`)
`isobject()` returns true for enum type variables (they have `type:'type'`), so `jsStructGetter` was wrapping enum fields in the anchor/pointer path.  
**Fix:** Added `isEnum` check to take the plain-value path for enum-typed fields.

### 3. Const pointer ArrayProxy setter (`bindings/src/raylib-header.js`)
`jsStructGetter_array` always generated a `_set` function even when `binding.set = false`, causing `read-only variable is not assignable` for `const T *` fields.  
**Fix:** `if (binding.set === false)` emits a `return false` stub instead of the mutating body.

### 4. `double` default return suffix (`bindings/src/quickjs.js`)
Default return for `double`/`long double` was `"0.0d"` — invalid C.  
**Fix:** Changed to `"0.0"`.

### 5. `JS_SetModuleExportList` signature (`bindings/src/index.js` toolsSource)
New quickjs-ng added a 4th `len` argument. The old toolsSource entry had only 3 args, causing it to be silently dropped.  
**Fix:** Added `{type:'int', name:'len'}` to the toolsSource entry.

### 6. `unsigned char *` vs `char *` condition (`bindings/src/raylib-header.js`)
`endsWith('char *')` matched both `char *` and `unsigned char *`. The getter checked `!== 'char *'` but the ArrayProxy condition used `endsWith`, creating a mismatch that omitted ArrayProxy functions for `unsigned char *` fields while still referencing them.  
**Fix:** Both conditions now use `!== 'char *' && !== 'const char *'`.

---

## JS API patterns to know (Box2D v3 specific)

- Enum values are exported individually: use `b2_dynamicBody`, not `b2BodyType.b2_dynamicBody`.
- Struct fields that are themselves structs return a **live proxy** — mutations on the returned object write back to the parent. Use this for nested fields: `shapeDef.material.restitution = 0.75` (not `shapeDef.restitution`).
- `b2Default*` factory functions return a single struct, not an array (the generated TypeScript typings wrongly say `T[]` — a known typing bug, harmless at runtime).
- Struct position/vector fields require a proper struct instance: `bodyDef.position = new b2Vec2(0, 10)`, not `{x:0, y:10}`.

---

## Coordinate system note (for physics → screen)

Box2D uses Y-up (standard math), raylib uses Y-down (screen). Typical mapping:
```js
const SCALE = 30  // pixels per metre
function toScreenX(px) { return SCREEN_W / 2 + px * SCALE }
function toScreenY(py) { return GROUND_PX - py * SCALE }
```
