#ifndef JS_box2d_GUARD
	#define JS_box2d_GUARD
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <rayjs_base.h>
	#include <config.h>
	#include <box2d/box2d.h>
	
	static int js_getint(JSContext * ctx,JSValue src,bool * error);
	
	static b2Version js_getb2Version(JSContext * ctx,JSValue src,bool * error){
		b2Version ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Version_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Version_class_id);
			ret =*(b2Version *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Version");
			error[0]=(bool)1;
			return (b2Version){0};
		}
		return ret;
	}
	
	static float js_getfloat(JSContext * ctx,JSValue src,bool * error);
	
	static b2Vec2 js_getb2Vec2(JSContext * ctx,JSValue src,bool * error){
		b2Vec2 ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Vec2_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Vec2_class_id);
			ret =*(b2Vec2 *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2");
			error[0]=(bool)1;
			return (b2Vec2){0};
		}
		return ret;
	}
	
	static b2CosSin js_getb2CosSin(JSContext * ctx,JSValue src,bool * error){
		b2CosSin ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2CosSin_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2CosSin_class_id);
			ret =*(b2CosSin *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2CosSin");
			error[0]=(bool)1;
			return (b2CosSin){0};
		}
		return ret;
	}
	
	static b2Rot js_getb2Rot(JSContext * ctx,JSValue src,bool * error){
		b2Rot ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Rot_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Rot_class_id);
			ret =*(b2Rot *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Rot");
			error[0]=(bool)1;
			return (b2Rot){0};
		}
		return ret;
	}
	
	static b2Transform js_getb2Transform(JSContext * ctx,JSValue src,bool * error){
		b2Transform ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Transform_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Transform_class_id);
			ret =*(b2Transform *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Transform");
			error[0]=(bool)1;
			return (b2Transform){0};
		}
		return ret;
	}
	
	static b2Mat22 js_getb2Mat22(JSContext * ctx,JSValue src,bool * error){
		b2Mat22 ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Mat22_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Mat22_class_id);
			ret =*(b2Mat22 *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Mat22");
			error[0]=(bool)1;
			return (b2Mat22){0};
		}
		return ret;
	}
	
	static b2AABB js_getb2AABB(JSContext * ctx,JSValue src,bool * error){
		b2AABB ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2AABB_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2AABB_class_id);
			ret =*(b2AABB *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2AABB");
			error[0]=(bool)1;
			return (b2AABB){0};
		}
		return ret;
	}
	
	static b2Plane js_getb2Plane(JSContext * ctx,JSValue src,bool * error){
		b2Plane ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Plane_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Plane_class_id);
			ret =*(b2Plane *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Plane");
			error[0]=(bool)1;
			return (b2Plane){0};
		}
		return ret;
	}
	
	static uint16_t js_getuint16_t(JSContext * ctx,JSValue src,bool * error){
		uint16_t ret;
		if(JS_IsNumber(src)){
			uint32_t long_ret;
			JS_ToUint32(ctx,&long_ret,src);
			ret =((uint16_t)long_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type uint16_t");
			error[0]=(bool)1;
			return (uint16_t){0};
		}
		return ret;
	}
	
	static uint8_t js_getuint8_t(JSContext * ctx,JSValue src,bool * error){
		uint8_t ret;
		if(JS_IsNumber(src)){
			uint32_t long_ret;
			JS_ToUint32(ctx,&long_ret,src);
			ret =((uint8_t)long_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type uint8_t");
			error[0]=(bool)1;
			return (uint8_t){0};
		}
		return ret;
	}
	
	static uint8_t * js_getuint8_t_arr3nc(JSContext * ctx,JSValue src,bool * error){
		uint8_t * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			uint8_t * js_ret=JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(uint8_t  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(js_IsArrayLength(ctx,src,(int64_t)3)){
			int64_t size_ret=(int64_t)3;
			size_ret =(int64_t)3;
			ret =(uint8_t  *)jsc_malloc(ctx,size_ret*sizeof(uint8_t));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_IsNumber(src0)){
					uint32_t long_reti;
					JS_ToUint32(ctx,&long_reti,src0);
					ret[i] =((uint8_t)long_reti);
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type uint8_t *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type uint8_t *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2SimplexCache js_getb2SimplexCache(JSContext * ctx,JSValue src,bool * error){
		b2SimplexCache ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SimplexCache_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SimplexCache_class_id);
			ret =*(b2SimplexCache *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SimplexCache");
			error[0]=(bool)1;
			return (b2SimplexCache){0};
		}
		return ret;
	}
	
	static b2Hull js_getb2Hull(JSContext * ctx,JSValue src,bool * error){
		b2Hull ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Hull_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Hull_class_id);
			ret =*(b2Hull *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Hull");
			error[0]=(bool)1;
			return (b2Hull){0};
		}
		return ret;
	}
	
	static b2RayCastInput js_getb2RayCastInput(JSContext * ctx,JSValue src,bool * error){
		b2RayCastInput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2RayCastInput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2RayCastInput_class_id);
			ret =*(b2RayCastInput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RayCastInput");
			error[0]=(bool)1;
			return (b2RayCastInput){0};
		}
		return ret;
	}
	
	static b2ShapeProxy js_getb2ShapeProxy(JSContext * ctx,JSValue src,bool * error){
		b2ShapeProxy ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ShapeProxy_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeProxy_class_id);
			ret =*(b2ShapeProxy *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeProxy");
			error[0]=(bool)1;
			return (b2ShapeProxy){0};
		}
		return ret;
	}
	
	static bool js_getbool(JSContext * ctx,JSValue src,bool * error);
	
	static b2ShapeCastInput js_getb2ShapeCastInput(JSContext * ctx,JSValue src,bool * error){
		b2ShapeCastInput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastInput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeCastInput_class_id);
			ret =*(b2ShapeCastInput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastInput");
			error[0]=(bool)1;
			return (b2ShapeCastInput){0};
		}
		return ret;
	}
	
	static b2CastOutput js_getb2CastOutput(JSContext * ctx,JSValue src,bool * error){
		b2CastOutput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2CastOutput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2CastOutput_class_id);
			ret =*(b2CastOutput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2CastOutput");
			error[0]=(bool)1;
			return (b2CastOutput){0};
		}
		return ret;
	}
	
	static b2MassData js_getb2MassData(JSContext * ctx,JSValue src,bool * error){
		b2MassData ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2MassData_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2MassData_class_id);
			ret =*(b2MassData *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MassData");
			error[0]=(bool)1;
			return (b2MassData){0};
		}
		return ret;
	}
	
	static b2Circle js_getb2Circle(JSContext * ctx,JSValue src,bool * error){
		b2Circle ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Circle_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Circle_class_id);
			ret =*(b2Circle *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Circle");
			error[0]=(bool)1;
			return (b2Circle){0};
		}
		return ret;
	}
	
	static b2Capsule js_getb2Capsule(JSContext * ctx,JSValue src,bool * error){
		b2Capsule ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Capsule_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Capsule_class_id);
			ret =*(b2Capsule *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Capsule");
			error[0]=(bool)1;
			return (b2Capsule){0};
		}
		return ret;
	}
	
	static b2Polygon js_getb2Polygon(JSContext * ctx,JSValue src,bool * error){
		b2Polygon ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Polygon_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Polygon_class_id);
			ret =*(b2Polygon *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Polygon");
			error[0]=(bool)1;
			return (b2Polygon){0};
		}
		return ret;
	}
	
	static b2Segment js_getb2Segment(JSContext * ctx,JSValue src,bool * error){
		b2Segment ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Segment_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Segment_class_id);
			ret =*(b2Segment *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Segment");
			error[0]=(bool)1;
			return (b2Segment){0};
		}
		return ret;
	}
	
	static b2ChainSegment js_getb2ChainSegment(JSContext * ctx,JSValue src,bool * error){
		b2ChainSegment ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ChainSegment_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ChainSegment_class_id);
			ret =*(b2ChainSegment *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ChainSegment");
			error[0]=(bool)1;
			return (b2ChainSegment){0};
		}
		return ret;
	}
	
	static b2SegmentDistanceResult js_getb2SegmentDistanceResult(JSContext * ctx,JSValue src,bool * error){
		b2SegmentDistanceResult ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SegmentDistanceResult_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SegmentDistanceResult_class_id);
			ret =*(b2SegmentDistanceResult *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SegmentDistanceResult");
			error[0]=(bool)1;
			return (b2SegmentDistanceResult){0};
		}
		return ret;
	}
	
	static b2DistanceInput js_getb2DistanceInput(JSContext * ctx,JSValue src,bool * error){
		b2DistanceInput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2DistanceInput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2DistanceInput_class_id);
			ret =*(b2DistanceInput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DistanceInput");
			error[0]=(bool)1;
			return (b2DistanceInput){0};
		}
		return ret;
	}
	
	static b2DistanceOutput js_getb2DistanceOutput(JSContext * ctx,JSValue src,bool * error){
		b2DistanceOutput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2DistanceOutput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2DistanceOutput_class_id);
			ret =*(b2DistanceOutput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DistanceOutput");
			error[0]=(bool)1;
			return (b2DistanceOutput){0};
		}
		return ret;
	}
	
	static b2SimplexVertex js_getb2SimplexVertex(JSContext * ctx,JSValue src,bool * error){
		b2SimplexVertex ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SimplexVertex_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SimplexVertex_class_id);
			ret =*(b2SimplexVertex *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SimplexVertex");
			error[0]=(bool)1;
			return (b2SimplexVertex){0};
		}
		return ret;
	}
	
	static b2Simplex js_getb2Simplex(JSContext * ctx,JSValue src,bool * error){
		b2Simplex ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Simplex_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Simplex_class_id);
			ret =*(b2Simplex *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Simplex");
			error[0]=(bool)1;
			return (b2Simplex){0};
		}
		return ret;
	}
	
	static b2ShapeCastPairInput js_getb2ShapeCastPairInput(JSContext * ctx,JSValue src,bool * error){
		b2ShapeCastPairInput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastPairInput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeCastPairInput_class_id);
			ret =*(b2ShapeCastPairInput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastPairInput");
			error[0]=(bool)1;
			return (b2ShapeCastPairInput){0};
		}
		return ret;
	}
	
	static b2Sweep js_getb2Sweep(JSContext * ctx,JSValue src,bool * error){
		b2Sweep ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Sweep_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Sweep_class_id);
			ret =*(b2Sweep *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Sweep");
			error[0]=(bool)1;
			return (b2Sweep){0};
		}
		return ret;
	}
	
	static b2TOIInput js_getb2TOIInput(JSContext * ctx,JSValue src,bool * error){
		b2TOIInput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2TOIInput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2TOIInput_class_id);
			ret =*(b2TOIInput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TOIInput");
			error[0]=(bool)1;
			return (b2TOIInput){0};
		}
		return ret;
	}
	
	static b2TOIState js_getb2TOIState(JSContext * ctx,JSValue src,bool * error){
		b2TOIState ret;
		if(JS_IsNumber(src)){
			JS_ToInt32(ctx,(int32_t  *)&ret,(JSValueConst)src);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TOIState");
			error[0]=(bool)1;
			return (b2TOIState){0};
		}
		return ret;
	}
	
	static b2TOIOutput js_getb2TOIOutput(JSContext * ctx,JSValue src,bool * error){
		b2TOIOutput ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2TOIOutput_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2TOIOutput_class_id);
			ret =*(b2TOIOutput *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TOIOutput");
			error[0]=(bool)1;
			return (b2TOIOutput){0};
		}
		return ret;
	}
	
	static b2ManifoldPoint js_getb2ManifoldPoint(JSContext * ctx,JSValue src,bool * error){
		b2ManifoldPoint ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ManifoldPoint_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ManifoldPoint_class_id);
			ret =*(b2ManifoldPoint *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ManifoldPoint");
			error[0]=(bool)1;
			return (b2ManifoldPoint){0};
		}
		return ret;
	}
	
	static b2ManifoldPoint * js_getb2ManifoldPoint_arr2nc(JSContext * ctx,JSValue src,bool * error){
		b2ManifoldPoint * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(js_IsArrayLength(ctx,src,(int64_t)2)){
			int64_t size_ret=(int64_t)2;
			size_ret =(int64_t)2;
			ret =(b2ManifoldPoint  *)jsc_malloc(ctx,size_ret*sizeof(b2ManifoldPoint));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ManifoldPoint_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ManifoldPoint_class_id);
					ret[i] =*(b2ManifoldPoint *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ManifoldPoint *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ManifoldPoint *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Manifold js_getb2Manifold(JSContext * ctx,JSValue src,bool * error){
		b2Manifold ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Manifold_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Manifold_class_id);
			ret =*(b2Manifold *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Manifold");
			error[0]=(bool)1;
			return (b2Manifold){0};
		}
		return ret;
	}
	
	static b2TreeStats js_getb2TreeStats(JSContext * ctx,JSValue src,bool * error){
		b2TreeStats ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2TreeStats_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2TreeStats_class_id);
			ret =*(b2TreeStats *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TreeStats");
			error[0]=(bool)1;
			return (b2TreeStats){0};
		}
		return ret;
	}
	
	static b2PlaneResult js_getb2PlaneResult(JSContext * ctx,JSValue src,bool * error){
		b2PlaneResult ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2PlaneResult_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2PlaneResult_class_id);
			ret =*(b2PlaneResult *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2PlaneResult");
			error[0]=(bool)1;
			return (b2PlaneResult){0};
		}
		return ret;
	}
	
	static b2CollisionPlane js_getb2CollisionPlane(JSContext * ctx,JSValue src,bool * error){
		b2CollisionPlane ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2CollisionPlane_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2CollisionPlane_class_id);
			ret =*(b2CollisionPlane *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2CollisionPlane");
			error[0]=(bool)1;
			return (b2CollisionPlane){0};
		}
		return ret;
	}
	
	static b2PlaneSolverResult js_getb2PlaneSolverResult(JSContext * ctx,JSValue src,bool * error){
		b2PlaneSolverResult ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2PlaneSolverResult_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2PlaneSolverResult_class_id);
			ret =*(b2PlaneSolverResult *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2PlaneSolverResult");
			error[0]=(bool)1;
			return (b2PlaneSolverResult){0};
		}
		return ret;
	}
	
	static b2WorldId js_getb2WorldId(JSContext * ctx,JSValue src,bool * error){
		b2WorldId ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2WorldId_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WorldId_class_id);
			ret =*(b2WorldId *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WorldId");
			error[0]=(bool)1;
			return (b2WorldId){0};
		}
		return ret;
	}
	
	static int32_t js_getint32_t(JSContext * ctx,JSValue src,bool * error){
		int32_t ret;
		if(JS_IsNumber(src)){
			JS_ToInt32(ctx,&ret,(JSValueConst)src);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type int32_t");
			error[0]=(bool)1;
			return (int32_t){0};
		}
		return ret;
	}
	
	static b2BodyId js_getb2BodyId(JSContext * ctx,JSValue src,bool * error){
		b2BodyId ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2BodyId_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyId_class_id);
			ret =*(b2BodyId *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyId");
			error[0]=(bool)1;
			return (b2BodyId){0};
		}
		return ret;
	}
	
	static b2ShapeId js_getb2ShapeId(JSContext * ctx,JSValue src,bool * error){
		b2ShapeId ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ShapeId_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeId_class_id);
			ret =*(b2ShapeId *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeId");
			error[0]=(bool)1;
			return (b2ShapeId){0};
		}
		return ret;
	}
	
	static b2ChainId js_getb2ChainId(JSContext * ctx,JSValue src,bool * error){
		b2ChainId ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ChainId_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ChainId_class_id);
			ret =*(b2ChainId *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ChainId");
			error[0]=(bool)1;
			return (b2ChainId){0};
		}
		return ret;
	}
	
	static b2JointId js_getb2JointId(JSContext * ctx,JSValue src,bool * error){
		b2JointId ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2JointId_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2JointId_class_id);
			ret =*(b2JointId *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2JointId");
			error[0]=(bool)1;
			return (b2JointId){0};
		}
		return ret;
	}
	
	static b2RayResult js_getb2RayResult(JSContext * ctx,JSValue src,bool * error){
		b2RayResult ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2RayResult_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2RayResult_class_id);
			ret =*(b2RayResult *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RayResult");
			error[0]=(bool)1;
			return (b2RayResult){0};
		}
		return ret;
	}
	
	static b2WorldDef js_getb2WorldDef(JSContext * ctx,JSValue src,bool * error){
		b2WorldDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2WorldDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WorldDef_class_id);
			ret =*(b2WorldDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WorldDef");
			error[0]=(bool)1;
			return (b2WorldDef){0};
		}
		return ret;
	}
	
	static b2BodyType js_getb2BodyType(JSContext * ctx,JSValue src,bool * error){
		b2BodyType ret;
		if(JS_IsNumber(src)){
			JS_ToInt32(ctx,(int32_t  *)&ret,(JSValueConst)src);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyType");
			error[0]=(bool)1;
			return (b2BodyType){0};
		}
		return ret;
	}
	
	static char * js_getchar_arrnc(JSContext * ctx,JSValue src,bool * error){
		char * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			char * js_ret=(char  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(char  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(char  *)jsc_malloc(ctx,size_ret*sizeof(char));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_IsString(src0)){
					char * js_reti=(char  *)JS_ToCString(ctx,src0);
					ret[i] =((char)js_reti[0]);
					JS_FreeCString(ctx,(const char  *)js_reti);
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type char *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==JS_CLASS_INT8_ARRAY){
			size_t offset_ret;
			size_t size_ret;
			JSValue da_ret=JS_GetTypedArrayBuffer(ctx,(JSValueConst)src,&offset_ret,&size_ret,NULL);
			char * js_ret=(char  *)JS_GetArrayBuffer(ctx,&size_ret,(JSValueConst)da_ret);
			ret =(char  *)jsc_malloc(ctx,size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,size_ret);
			memoryStore(jsc_free,(void  *)ret);
			ret +=offset_ret;
			size_ret -=offset_ret;
			JS_FreeValuePtr(ctx,&da_ret);
		}else if(JS_IsString(src)){
			int64_t size_ret;
			char * js_ret=(char  *)JS_ToCStringLen(ctx,(size_t  *)&size_ret,src);
			char * js2_ret=(char  *)jsc_malloc(ctx,size_ret+1);
			memcpy((void  *)js2_ret,(const void  *)js_ret,(size_t)size_ret);
			js2_ret[size_ret]=(char)0;
			ret=js2_ret;
			JS_FreeCString(ctx,(const char  *)js_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type char *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2BodyDef js_getb2BodyDef(JSContext * ctx,JSValue src,bool * error){
		b2BodyDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2BodyDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyDef_class_id);
			ret =*(b2BodyDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyDef");
			error[0]=(bool)1;
			return (b2BodyDef){0};
		}
		return ret;
	}
	
	static uint64_t js_getuint64_t(JSContext * ctx,JSValue src,bool * error){
		uint64_t ret;
		if(JS_IsNumber(src)){
			uint64_t  long_ret;
			JS_ToInt64(ctx,(int64_t  *)&long_ret,(JSValueConst)src);
			ret =((uint64_t)long_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type uint64_t");
			error[0]=(bool)1;
			return (uint64_t){0};
		}
		return ret;
	}
	
	static b2Filter js_getb2Filter(JSContext * ctx,JSValue src,bool * error){
		b2Filter ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Filter_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Filter_class_id);
			ret =*(b2Filter *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Filter");
			error[0]=(bool)1;
			return (b2Filter){0};
		}
		return ret;
	}
	
	static b2QueryFilter js_getb2QueryFilter(JSContext * ctx,JSValue src,bool * error){
		b2QueryFilter ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2QueryFilter_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2QueryFilter_class_id);
			ret =*(b2QueryFilter *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2QueryFilter");
			error[0]=(bool)1;
			return (b2QueryFilter){0};
		}
		return ret;
	}
	
	static uint32_t js_getuint32_t(JSContext * ctx,JSValue src,bool * error);
	
	static b2SurfaceMaterial js_getb2SurfaceMaterial(JSContext * ctx,JSValue src,bool * error){
		b2SurfaceMaterial ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SurfaceMaterial_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SurfaceMaterial_class_id);
			ret =*(b2SurfaceMaterial *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SurfaceMaterial");
			error[0]=(bool)1;
			return (b2SurfaceMaterial){0};
		}
		return ret;
	}
	
	static b2ShapeDef js_getb2ShapeDef(JSContext * ctx,JSValue src,bool * error){
		b2ShapeDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ShapeDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeDef_class_id);
			ret =*(b2ShapeDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeDef");
			error[0]=(bool)1;
			return (b2ShapeDef){0};
		}
		return ret;
	}
	
	static b2ChainDef js_getb2ChainDef(JSContext * ctx,JSValue src,bool * error){
		b2ChainDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ChainDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ChainDef_class_id);
			ret =*(b2ChainDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ChainDef");
			error[0]=(bool)1;
			return (b2ChainDef){0};
		}
		return ret;
	}
	
	static b2ChainDef b2ChainDef_copy(JSContext * ctx,b2ChainDef ptr){
		b2ChainDef ret=ptr;
		ret.points =(const b2Vec2  *)jsc_malloc(ctx,sizeof(const b2Vec2 *)*ptr.count);
		for(int i=0;i<ptr.count;i++){
		}
		ret.materials =(const b2SurfaceMaterial  *)jsc_malloc(ctx,sizeof(const b2SurfaceMaterial *)*ptr.materialCount);
		for(int i0=0;i0<ptr.materialCount;i0++){
		}
		return ret;
	}
	
	static b2Vec2 * js_getb2Vec2_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2Vec2 * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2Vec2  *)jsc_malloc(ctx,size_ret*sizeof(b2Vec2));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Vec2_class_id);
						ret[i] =*(b2Vec2 *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Vec2 *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(jsc_free,(void  *)ret);
			}else if(JS_IsNumber(src0)){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2Vec2  *)jsc_malloc(ctx,size_ret*sizeof(float));
				for(int i=0;i<size_ret;i++){
					float * tmp_obj=(float  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_IsNumber(src0)){
							double double_tmp_objii0;
							JS_ToFloat64(ctx,&double_tmp_objii0,(JSValueConst)src0);
							tmp_obj[i+i0] =((float)double_tmp_objii0);
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Vec2 *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(jsc_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_GetClassID((JSValueConst)src)==JS_CLASS_FLOAT32_ARRAY){
			size_t offset_ret;
			size_t size_ret;
			JSValue da_ret=JS_GetTypedArrayBuffer(ctx,(JSValueConst)src,&offset_ret,&size_ret,NULL);
			b2Vec2 * js_ret=(b2Vec2  *)JS_GetArrayBuffer(ctx,&size_ret,(JSValueConst)da_ret);
			ret =(b2Vec2  *)jsc_malloc(ctx,size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,size_ret);
			memoryStore(jsc_free,(void  *)ret);
			ret +=offset_ret;
			size_ret -=offset_ret;
			JS_FreeValuePtr(ctx,&da_ret);
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			b2Vec2 * js_ret=(b2Vec2  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(b2Vec2  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Vec2_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Vec2_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Vec2_class_id);
				ret =(b2Vec2  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2SurfaceMaterial * js_getb2SurfaceMaterial_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2SurfaceMaterial * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2SurfaceMaterial  *)jsc_malloc(ctx,size_ret*sizeof(b2SurfaceMaterial));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2SurfaceMaterial_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2SurfaceMaterial_class_id);
					ret[i] =*(b2SurfaceMaterial *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2SurfaceMaterial *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2SurfaceMaterial_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2SurfaceMaterial_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SurfaceMaterial_class_id);
				ret =(b2SurfaceMaterial  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SurfaceMaterial *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SurfaceMaterial *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Profile js_getb2Profile(JSContext * ctx,JSValue src,bool * error){
		b2Profile ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Profile_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Profile_class_id);
			ret =*(b2Profile *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Profile");
			error[0]=(bool)1;
			return (b2Profile){0};
		}
		return ret;
	}
	
	static int js_getint_arg1(JSContext * ctx,JSValue src,bool * error,int size0){
		int ret;
		if(JS_IsNumber(src)){
			int32_t long_ret;
			JS_ToInt32(ctx,&long_ret,(JSValueConst)src);
			ret =((int)long_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type int");
			error[0]=(bool)1;
			return 0;
		}
		return ret;
	}
	
	static int * js_getint_arr12nc(JSContext * ctx,JSValue src,bool * error){
		int * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			int * js_ret=(int  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(int  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(js_IsArrayLength(ctx,src,(int64_t)12)){
			int64_t size_ret=(int64_t)12;
			size_ret =(int64_t)12;
			ret =(int  *)jsc_malloc(ctx,size_ret*sizeof(int));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_IsNumber(src0)){
					int32_t long_reti;
					JS_ToInt32(ctx,&long_reti,(JSValueConst)src0);
					ret[i] =((int)long_reti);
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type int *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==JS_CLASS_INT16_ARRAY){
			size_t offset_ret;
			size_t size_ret;
			JSValue da_ret=JS_GetTypedArrayBuffer(ctx,(JSValueConst)src,&offset_ret,&size_ret,NULL);
			int * js_ret=(int  *)JS_GetArrayBuffer(ctx,&size_ret,(JSValueConst)da_ret);
			ret =(int  *)jsc_malloc(ctx,size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,size_ret);
			memoryStore(jsc_free,(void  *)ret);
			ret +=offset_ret;
			size_ret -=offset_ret;
			JS_FreeValuePtr(ctx,&da_ret);
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type int *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Counters js_getb2Counters(JSContext * ctx,JSValue src,bool * error){
		b2Counters ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2Counters_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Counters_class_id);
			ret =*(b2Counters *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Counters");
			error[0]=(bool)1;
			return (b2Counters){0};
		}
		return ret;
	}
	
	static b2DistanceJointDef js_getb2DistanceJointDef(JSContext * ctx,JSValue src,bool * error){
		b2DistanceJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2DistanceJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2DistanceJointDef_class_id);
			ret =*(b2DistanceJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DistanceJointDef");
			error[0]=(bool)1;
			return (b2DistanceJointDef){0};
		}
		return ret;
	}
	
	static b2MotorJointDef js_getb2MotorJointDef(JSContext * ctx,JSValue src,bool * error){
		b2MotorJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2MotorJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2MotorJointDef_class_id);
			ret =*(b2MotorJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MotorJointDef");
			error[0]=(bool)1;
			return (b2MotorJointDef){0};
		}
		return ret;
	}
	
	static b2MouseJointDef js_getb2MouseJointDef(JSContext * ctx,JSValue src,bool * error){
		b2MouseJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2MouseJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2MouseJointDef_class_id);
			ret =*(b2MouseJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MouseJointDef");
			error[0]=(bool)1;
			return (b2MouseJointDef){0};
		}
		return ret;
	}
	
	static b2FilterJointDef js_getb2FilterJointDef(JSContext * ctx,JSValue src,bool * error){
		b2FilterJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2FilterJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2FilterJointDef_class_id);
			ret =*(b2FilterJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2FilterJointDef");
			error[0]=(bool)1;
			return (b2FilterJointDef){0};
		}
		return ret;
	}
	
	static b2PrismaticJointDef js_getb2PrismaticJointDef(JSContext * ctx,JSValue src,bool * error){
		b2PrismaticJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2PrismaticJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2PrismaticJointDef_class_id);
			ret =*(b2PrismaticJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2PrismaticJointDef");
			error[0]=(bool)1;
			return (b2PrismaticJointDef){0};
		}
		return ret;
	}
	
	static b2RevoluteJointDef js_getb2RevoluteJointDef(JSContext * ctx,JSValue src,bool * error){
		b2RevoluteJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2RevoluteJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2RevoluteJointDef_class_id);
			ret =*(b2RevoluteJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RevoluteJointDef");
			error[0]=(bool)1;
			return (b2RevoluteJointDef){0};
		}
		return ret;
	}
	
	static b2WeldJointDef js_getb2WeldJointDef(JSContext * ctx,JSValue src,bool * error){
		b2WeldJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2WeldJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WeldJointDef_class_id);
			ret =*(b2WeldJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WeldJointDef");
			error[0]=(bool)1;
			return (b2WeldJointDef){0};
		}
		return ret;
	}
	
	static b2WheelJointDef js_getb2WheelJointDef(JSContext * ctx,JSValue src,bool * error){
		b2WheelJointDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2WheelJointDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WheelJointDef_class_id);
			ret =*(b2WheelJointDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WheelJointDef");
			error[0]=(bool)1;
			return (b2WheelJointDef){0};
		}
		return ret;
	}
	
	static b2ExplosionDef js_getb2ExplosionDef(JSContext * ctx,JSValue src,bool * error){
		b2ExplosionDef ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ExplosionDef_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ExplosionDef_class_id);
			ret =*(b2ExplosionDef *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ExplosionDef");
			error[0]=(bool)1;
			return (b2ExplosionDef){0};
		}
		return ret;
	}
	
	static b2SensorBeginTouchEvent js_getb2SensorBeginTouchEvent(JSContext * ctx,JSValue src,bool * error){
		b2SensorBeginTouchEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SensorBeginTouchEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SensorBeginTouchEvent_class_id);
			ret =*(b2SensorBeginTouchEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorBeginTouchEvent");
			error[0]=(bool)1;
			return (b2SensorBeginTouchEvent){0};
		}
		return ret;
	}
	
	static b2SensorEndTouchEvent js_getb2SensorEndTouchEvent(JSContext * ctx,JSValue src,bool * error){
		b2SensorEndTouchEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SensorEndTouchEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SensorEndTouchEvent_class_id);
			ret =*(b2SensorEndTouchEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorEndTouchEvent");
			error[0]=(bool)1;
			return (b2SensorEndTouchEvent){0};
		}
		return ret;
	}
	
	static b2SensorBeginTouchEvent * js_getb2SensorBeginTouchEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2SensorBeginTouchEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2SensorBeginTouchEvent_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2SensorBeginTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2SensorBeginTouchEvent));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2SensorBeginTouchEvent_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2SensorBeginTouchEvent_class_id);
						ret[i] =*(b2SensorBeginTouchEvent *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2SensorBeginTouchEvent *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(jsc_free,(void  *)ret);
			}else if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2SensorBeginTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ShapeId));
				for(int i=0;i<size_ret;i++){
					b2ShapeId * tmp_obj=(b2ShapeId  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
							opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeId_class_id);
							tmp_obj[i+i0] =*(b2ShapeId *)tmpshadow[0].ptr;
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2SensorBeginTouchEvent *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(jsc_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorBeginTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			b2SensorBeginTouchEvent * js_ret=(b2SensorBeginTouchEvent  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(b2SensorBeginTouchEvent  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2SensorBeginTouchEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2SensorBeginTouchEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SensorBeginTouchEvent_class_id);
				ret =(b2SensorBeginTouchEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorBeginTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorBeginTouchEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2SensorEndTouchEvent * js_getb2SensorEndTouchEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2SensorEndTouchEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2SensorEndTouchEvent_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2SensorEndTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2SensorEndTouchEvent));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2SensorEndTouchEvent_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2SensorEndTouchEvent_class_id);
						ret[i] =*(b2SensorEndTouchEvent *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2SensorEndTouchEvent *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(jsc_free,(void  *)ret);
			}else if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2SensorEndTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ShapeId));
				for(int i=0;i<size_ret;i++){
					b2ShapeId * tmp_obj=(b2ShapeId  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
							opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeId_class_id);
							tmp_obj[i+i0] =*(b2ShapeId *)tmpshadow[0].ptr;
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2SensorEndTouchEvent *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(jsc_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorEndTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			b2SensorEndTouchEvent * js_ret=(b2SensorEndTouchEvent  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(b2SensorEndTouchEvent  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2SensorEndTouchEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2SensorEndTouchEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SensorEndTouchEvent_class_id);
				ret =(b2SensorEndTouchEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorEndTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorEndTouchEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2SensorEvents js_getb2SensorEvents(JSContext * ctx,JSValue src,bool * error){
		b2SensorEvents ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2SensorEvents_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2SensorEvents_class_id);
			ret =*(b2SensorEvents *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2SensorEvents");
			error[0]=(bool)1;
			return (b2SensorEvents){0};
		}
		return ret;
	}
	
	static b2SensorEvents b2SensorEvents_copy(JSContext * ctx,b2SensorEvents ptr){
		b2SensorEvents ret=ptr;
		ret.beginEvents =(b2SensorBeginTouchEvent  *)jsc_malloc(ctx,sizeof(b2SensorBeginTouchEvent *)*ptr.beginCount);
		for(int i=0;i<ptr.beginCount;i++){
			ret.beginEvents[i] =ptr.beginEvents[i];
		}
		ret.endEvents =(b2SensorEndTouchEvent  *)jsc_malloc(ctx,sizeof(b2SensorEndTouchEvent *)*ptr.endCount);
		for(int i0=0;i0<ptr.endCount;i0++){
			ret.endEvents[i0] =ptr.endEvents[i0];
		}
		return ret;
	}
	
	static b2ContactBeginTouchEvent js_getb2ContactBeginTouchEvent(JSContext * ctx,JSValue src,bool * error){
		b2ContactBeginTouchEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ContactBeginTouchEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactBeginTouchEvent_class_id);
			ret =*(b2ContactBeginTouchEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactBeginTouchEvent");
			error[0]=(bool)1;
			return (b2ContactBeginTouchEvent){0};
		}
		return ret;
	}
	
	static b2ContactEndTouchEvent js_getb2ContactEndTouchEvent(JSContext * ctx,JSValue src,bool * error){
		b2ContactEndTouchEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ContactEndTouchEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactEndTouchEvent_class_id);
			ret =*(b2ContactEndTouchEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactEndTouchEvent");
			error[0]=(bool)1;
			return (b2ContactEndTouchEvent){0};
		}
		return ret;
	}
	
	static b2ContactHitEvent js_getb2ContactHitEvent(JSContext * ctx,JSValue src,bool * error){
		b2ContactHitEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ContactHitEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactHitEvent_class_id);
			ret =*(b2ContactHitEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactHitEvent");
			error[0]=(bool)1;
			return (b2ContactHitEvent){0};
		}
		return ret;
	}
	
	static b2ContactBeginTouchEvent * js_getb2ContactBeginTouchEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2ContactBeginTouchEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ContactBeginTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ContactBeginTouchEvent));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ContactBeginTouchEvent_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ContactBeginTouchEvent_class_id);
					ret[i] =*(b2ContactBeginTouchEvent *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ContactBeginTouchEvent *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ContactBeginTouchEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ContactBeginTouchEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactBeginTouchEvent_class_id);
				ret =(b2ContactBeginTouchEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactBeginTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactBeginTouchEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ContactEndTouchEvent * js_getb2ContactEndTouchEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2ContactEndTouchEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2ContactEndTouchEvent_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2ContactEndTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ContactEndTouchEvent));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2ContactEndTouchEvent_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ContactEndTouchEvent_class_id);
						ret[i] =*(b2ContactEndTouchEvent *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ContactEndTouchEvent *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(jsc_free,(void  *)ret);
			}else if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2ContactEndTouchEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ShapeId));
				for(int i=0;i<size_ret;i++){
					b2ShapeId * tmp_obj=(b2ShapeId  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
							opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeId_class_id);
							tmp_obj[i+i0] =*(b2ShapeId *)tmpshadow[0].ptr;
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ContactEndTouchEvent *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(jsc_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactEndTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			b2ContactEndTouchEvent * js_ret=(b2ContactEndTouchEvent  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
			ret =(b2ContactEndTouchEvent  *)jsc_malloc(ctx,(size_t)size_ret);
			memcpy((void  *)ret,(const void  *)js_ret,(size_t)size_ret);
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ContactEndTouchEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ContactEndTouchEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactEndTouchEvent_class_id);
				ret =(b2ContactEndTouchEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactEndTouchEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactEndTouchEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ContactHitEvent * js_getb2ContactHitEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2ContactHitEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ContactHitEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2ContactHitEvent));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ContactHitEvent_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ContactHitEvent_class_id);
					ret[i] =*(b2ContactHitEvent *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ContactHitEvent *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ContactHitEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ContactHitEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactHitEvent_class_id);
				ret =(b2ContactHitEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactHitEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactHitEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ContactEvents js_getb2ContactEvents(JSContext * ctx,JSValue src,bool * error){
		b2ContactEvents ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ContactEvents_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactEvents_class_id);
			ret =*(b2ContactEvents *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactEvents");
			error[0]=(bool)1;
			return (b2ContactEvents){0};
		}
		return ret;
	}
	
	static b2ContactEvents b2ContactEvents_copy(JSContext * ctx,b2ContactEvents ptr){
		b2ContactEvents ret=ptr;
		ret.beginEvents =(b2ContactBeginTouchEvent  *)jsc_malloc(ctx,sizeof(b2ContactBeginTouchEvent *)*ptr.beginCount);
		for(int i=0;i<ptr.beginCount;i++){
			ret.beginEvents[i] =ptr.beginEvents[i];
		}
		ret.endEvents =(b2ContactEndTouchEvent  *)jsc_malloc(ctx,sizeof(b2ContactEndTouchEvent *)*ptr.endCount);
		for(int i0=0;i0<ptr.endCount;i0++){
			ret.endEvents[i0] =ptr.endEvents[i0];
		}
		ret.hitEvents =(b2ContactHitEvent  *)jsc_malloc(ctx,sizeof(b2ContactHitEvent *)*ptr.hitCount);
		for(int i1=0;i1<ptr.hitCount;i1++){
			ret.hitEvents[i1] =ptr.hitEvents[i1];
		}
		return ret;
	}
	
	static b2BodyMoveEvent js_getb2BodyMoveEvent(JSContext * ctx,JSValue src,bool * error){
		b2BodyMoveEvent ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2BodyMoveEvent_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyMoveEvent_class_id);
			ret =*(b2BodyMoveEvent *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyMoveEvent");
			error[0]=(bool)1;
			return (b2BodyMoveEvent){0};
		}
		return ret;
	}
	
	static b2BodyMoveEvent * js_getb2BodyMoveEvent_arrnc(JSContext * ctx,JSValue src,bool * error){
		b2BodyMoveEvent * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2BodyMoveEvent  *)jsc_malloc(ctx,size_ret*sizeof(b2BodyMoveEvent));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2BodyMoveEvent_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2BodyMoveEvent_class_id);
					ret[i] =*(b2BodyMoveEvent *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2BodyMoveEvent *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(jsc_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2BodyMoveEvent_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2BodyMoveEvent_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyMoveEvent_class_id);
				ret =(b2BodyMoveEvent  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyMoveEvent *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyMoveEvent *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2BodyEvents js_getb2BodyEvents(JSContext * ctx,JSValue src,bool * error){
		b2BodyEvents ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2BodyEvents_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyEvents_class_id);
			ret =*(b2BodyEvents *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyEvents");
			error[0]=(bool)1;
			return (b2BodyEvents){0};
		}
		return ret;
	}
	
	static b2BodyEvents b2BodyEvents_copy(JSContext * ctx,b2BodyEvents ptr){
		b2BodyEvents ret=ptr;
		ret.moveEvents =(b2BodyMoveEvent  *)jsc_malloc(ctx,sizeof(b2BodyMoveEvent *)*ptr.moveCount);
		for(int i=0;i<ptr.moveCount;i++){
			ret.moveEvents[i] =ptr.moveEvents[i];
		}
		return ret;
	}
	
	static b2ContactData js_getb2ContactData(JSContext * ctx,JSValue src,bool * error){
		b2ContactData ret;
		if(JS_GetClassID((JSValueConst)src)==js_b2ContactData_class_id){
			opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ContactData_class_id);
			ret =*(b2ContactData *)tmpshadow[0].ptr;
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ContactData");
			error[0]=(bool)1;
			return (b2ContactData){0};
		}
		return ret;
	}
	
	static float * js_getfloat_arr(JSContext * ctx,JSValue src,bool * error);
	
	static b2Vec2 * js_getb2Vec2_arr(JSContext * ctx,JSValue src,bool * error){
		b2Vec2 * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2Vec2  *)js_malloc(ctx,size_ret*sizeof(b2Vec2));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Vec2_class_id);
						ret[i] =*(b2Vec2 *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Vec2 *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(js_free,(void  *)ret);
			}else if(JS_IsNumber(src0)){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2Vec2  *)js_malloc(ctx,size_ret*sizeof(float));
				for(int i=0;i<size_ret;i++){
					float * tmp_obj=(float  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_IsNumber(src0)){
							double double_tmp_objii0;
							JS_ToFloat64(ctx,&double_tmp_objii0,(JSValueConst)src0);
							tmp_obj[i+i0] =((float)double_tmp_objii0);
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Vec2 *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(js_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_GetClassID((JSValueConst)src)==JS_CLASS_FLOAT32_ARRAY){
			size_t offset_ret;
			size_t size_ret;
			JSValue da_ret=JS_GetTypedArrayBuffer(ctx,(JSValueConst)src,&offset_ret,&size_ret,NULL);
			ret =(b2Vec2  *)JS_GetArrayBuffer(ctx,&size_ret,(JSValueConst)src);
			ret +=offset_ret;
			size_ret -=offset_ret;
			JS_FreeValuePtr(ctx,&da_ret);
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			ret =(b2Vec2  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Vec2_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Vec2_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Vec2_class_id);
				ret =(b2Vec2  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Vec2 *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2RayCastInput * js_getb2RayCastInput_arr(JSContext * ctx,JSValue src,bool * error){
		b2RayCastInput * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2RayCastInput  *)js_malloc(ctx,size_ret*sizeof(b2RayCastInput));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2RayCastInput_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2RayCastInput_class_id);
					ret[i] =*(b2RayCastInput *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2RayCastInput *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2RayCastInput_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2RayCastInput_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2RayCastInput_class_id);
				ret =(b2RayCastInput  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RayCastInput *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RayCastInput *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Hull * js_getb2Hull_arr(JSContext * ctx,JSValue src,bool * error){
		b2Hull * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2Hull  *)js_malloc(ctx,size_ret*sizeof(b2Hull));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2Hull_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Hull_class_id);
					ret[i] =*(b2Hull *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Hull *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Hull_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Hull_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Hull_class_id);
				ret =(b2Hull  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Hull *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Hull *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Polygon * js_getb2Polygon_arr(JSContext * ctx,JSValue src,bool * error){
		b2Polygon * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2Polygon  *)js_malloc(ctx,size_ret*sizeof(b2Polygon));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2Polygon_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Polygon_class_id);
					ret[i] =*(b2Polygon *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Polygon *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Polygon_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Polygon_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Polygon_class_id);
				ret =(b2Polygon  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Polygon *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Polygon *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Circle * js_getb2Circle_arr(JSContext * ctx,JSValue src,bool * error){
		b2Circle * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2Circle  *)js_malloc(ctx,size_ret*sizeof(b2Circle));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2Circle_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Circle_class_id);
					ret[i] =*(b2Circle *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Circle *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Circle_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Circle_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Circle_class_id);
				ret =(b2Circle  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Circle *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Circle *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Capsule * js_getb2Capsule_arr(JSContext * ctx,JSValue src,bool * error){
		b2Capsule * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2Capsule  *)js_malloc(ctx,size_ret*sizeof(b2Capsule));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2Capsule_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Capsule_class_id);
					ret[i] =*(b2Capsule *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Capsule *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Capsule_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Capsule_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Capsule_class_id);
				ret =(b2Capsule  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Capsule *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Capsule *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Segment * js_getb2Segment_arr(JSContext * ctx,JSValue src,bool * error){
		b2Segment * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)0);
			JS_FreeValue(ctx,src0);
			if(JS_GetClassID((JSValueConst)src0)==js_b2Segment_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				ret =(b2Segment  *)js_malloc(ctx,size_ret*sizeof(b2Segment));
				for(int i=0;i<size_ret;i++){
					src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
					JS_FreeValue(ctx,src0);
					if(JS_GetClassID((JSValueConst)src0)==js_b2Segment_class_id){
						opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Segment_class_id);
						ret[i] =*(b2Segment *)tmpshadow[0].ptr;
					}else{
						JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Segment *");
						error[0]=(bool)1;
						return NULL;
					}
				}
				memoryStore(js_free,(void  *)ret);
			}else if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
				if(size_ret==0){
					JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
					error[0]=(bool)1;
					return NULL;
				}
				size_ret -=size_ret%2;
				ret =(b2Segment  *)js_malloc(ctx,size_ret*sizeof(b2Vec2));
				for(int i=0;i<size_ret;i++){
					b2Vec2 * tmp_obj=(b2Vec2  *)ret;
					for(int i0=0;i0<2;i0++){
						src0 =JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i+i0);
						JS_FreeValue(ctx,src0);
						if(JS_GetClassID((JSValueConst)src0)==js_b2Vec2_class_id){
							opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Vec2_class_id);
							tmp_obj[i+i0] =*(b2Vec2 *)tmpshadow[0].ptr;
						}else{
							JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Segment *");
							error[0]=(bool)1;
							return NULL;
						}
					}
					i +=1;
				}
				memoryStore(js_free,(void  *)ret);
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Segment *");
				error[0]=(bool)1;
				return NULL;
			}
		}else if(JS_IsArrayBuffer((JSValueConst)src)){
			int64_t size_ret;
			ret =(b2Segment  *)JS_GetArrayBuffer(ctx,(size_t  *)&size_ret,(JSValueConst)src);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Segment_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Segment_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Segment_class_id);
				ret =(b2Segment  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Segment *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Segment *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ShapeCastInput * js_getb2ShapeCastInput_arr(JSContext * ctx,JSValue src,bool * error){
		b2ShapeCastInput * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ShapeCastInput  *)js_malloc(ctx,size_ret*sizeof(b2ShapeCastInput));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeCastInput_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeCastInput_class_id);
					ret[i] =*(b2ShapeCastInput *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ShapeCastInput *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastInput_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastInput_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeCastInput_class_id);
				ret =(b2ShapeCastInput  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastInput *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastInput *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ShapeCastPairInput * js_getb2ShapeCastPairInput_arr(JSContext * ctx,JSValue src,bool * error){
		b2ShapeCastPairInput * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ShapeCastPairInput  *)js_malloc(ctx,size_ret*sizeof(b2ShapeCastPairInput));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeCastPairInput_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeCastPairInput_class_id);
					ret[i] =*(b2ShapeCastPairInput *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ShapeCastPairInput *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastPairInput_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ShapeCastPairInput_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeCastPairInput_class_id);
				ret =(b2ShapeCastPairInput  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastPairInput *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeCastPairInput *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2Sweep * js_getb2Sweep_arr(JSContext * ctx,JSValue src,bool * error){
		b2Sweep * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2Sweep  *)js_malloc(ctx,size_ret*sizeof(b2Sweep));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2Sweep_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2Sweep_class_id);
					ret[i] =*(b2Sweep *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2Sweep *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2Sweep_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2Sweep_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2Sweep_class_id);
				ret =(b2Sweep  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Sweep *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2Sweep *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2TOIInput * js_getb2TOIInput_arr(JSContext * ctx,JSValue src,bool * error){
		b2TOIInput * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2TOIInput  *)js_malloc(ctx,size_ret*sizeof(b2TOIInput));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2TOIInput_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2TOIInput_class_id);
					ret[i] =*(b2TOIInput *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2TOIInput *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2TOIInput_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2TOIInput_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2TOIInput_class_id);
				ret =(b2TOIInput  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TOIInput *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2TOIInput *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2DynamicTree * js_getb2DynamicTree_arr(JSContext * ctx,JSValue src,bool * error){
		b2DynamicTree * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2DynamicTree  *)js_malloc(ctx,size_ret*sizeof(b2DynamicTree));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2DynamicTree_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2DynamicTree_class_id);
					ret[i] =*(b2DynamicTree *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2DynamicTree *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2DynamicTree_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2DynamicTree_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2DynamicTree_class_id);
				ret =(b2DynamicTree  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DynamicTree *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DynamicTree *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2CollisionPlane * js_getb2CollisionPlane_arr(JSContext * ctx,JSValue src,bool * error){
		b2CollisionPlane * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2CollisionPlane  *)js_malloc(ctx,size_ret*sizeof(b2CollisionPlane));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2CollisionPlane_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2CollisionPlane_class_id);
					ret[i] =*(b2CollisionPlane *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2CollisionPlane *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2CollisionPlane_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2CollisionPlane_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2CollisionPlane_class_id);
				ret =(b2CollisionPlane  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2CollisionPlane *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2CollisionPlane *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2WorldDef * js_getb2WorldDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2WorldDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2WorldDef  *)js_malloc(ctx,size_ret*sizeof(b2WorldDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2WorldDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2WorldDef_class_id);
					ret[i] =*(b2WorldDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2WorldDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2WorldDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2WorldDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WorldDef_class_id);
				ret =(b2WorldDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WorldDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WorldDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ExplosionDef * js_getb2ExplosionDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2ExplosionDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ExplosionDef  *)js_malloc(ctx,size_ret*sizeof(b2ExplosionDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ExplosionDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ExplosionDef_class_id);
					ret[i] =*(b2ExplosionDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ExplosionDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ExplosionDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ExplosionDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ExplosionDef_class_id);
				ret =(b2ExplosionDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ExplosionDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ExplosionDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2BodyDef * js_getb2BodyDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2BodyDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2BodyDef  *)js_malloc(ctx,size_ret*sizeof(b2BodyDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2BodyDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2BodyDef_class_id);
					ret[i] =*(b2BodyDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2BodyDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2BodyDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2BodyDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2BodyDef_class_id);
				ret =(b2BodyDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2BodyDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static char * js_getchar_arr(JSContext * ctx,JSValue src,bool * error);
	
	static b2ShapeId * js_getb2ShapeId_arr(JSContext * ctx,JSValue src,bool * error){
		b2ShapeId * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ShapeId  *)js_malloc(ctx,size_ret*sizeof(b2ShapeId));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeId_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeId_class_id);
					ret[i] =*(b2ShapeId *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ShapeId *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ShapeId_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ShapeId_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeId_class_id);
				ret =(b2ShapeId  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeId *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeId *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2JointId * js_getb2JointId_arr(JSContext * ctx,JSValue src,bool * error){
		b2JointId * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2JointId  *)js_malloc(ctx,size_ret*sizeof(b2JointId));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2JointId_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2JointId_class_id);
					ret[i] =*(b2JointId *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2JointId *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2JointId_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2JointId_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2JointId_class_id);
				ret =(b2JointId  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2JointId *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2JointId *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ShapeDef * js_getb2ShapeDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2ShapeDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ShapeDef  *)js_malloc(ctx,size_ret*sizeof(b2ShapeDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ShapeDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ShapeDef_class_id);
					ret[i] =*(b2ShapeDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ShapeDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ShapeDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ShapeDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ShapeDef_class_id);
				ret =(b2ShapeDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ShapeDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2ChainDef * js_getb2ChainDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2ChainDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2ChainDef  *)js_malloc(ctx,size_ret*sizeof(b2ChainDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2ChainDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2ChainDef_class_id);
					ret[i] =*(b2ChainDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2ChainDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2ChainDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2ChainDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2ChainDef_class_id);
				ret =(b2ChainDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ChainDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2ChainDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2DistanceJointDef * js_getb2DistanceJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2DistanceJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2DistanceJointDef  *)js_malloc(ctx,size_ret*sizeof(b2DistanceJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2DistanceJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2DistanceJointDef_class_id);
					ret[i] =*(b2DistanceJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2DistanceJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2DistanceJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2DistanceJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2DistanceJointDef_class_id);
				ret =(b2DistanceJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DistanceJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2DistanceJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2MotorJointDef * js_getb2MotorJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2MotorJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2MotorJointDef  *)js_malloc(ctx,size_ret*sizeof(b2MotorJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2MotorJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2MotorJointDef_class_id);
					ret[i] =*(b2MotorJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2MotorJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2MotorJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2MotorJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2MotorJointDef_class_id);
				ret =(b2MotorJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MotorJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MotorJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2MouseJointDef * js_getb2MouseJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2MouseJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2MouseJointDef  *)js_malloc(ctx,size_ret*sizeof(b2MouseJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2MouseJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2MouseJointDef_class_id);
					ret[i] =*(b2MouseJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2MouseJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2MouseJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2MouseJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2MouseJointDef_class_id);
				ret =(b2MouseJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MouseJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2MouseJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2FilterJointDef * js_getb2FilterJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2FilterJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2FilterJointDef  *)js_malloc(ctx,size_ret*sizeof(b2FilterJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2FilterJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2FilterJointDef_class_id);
					ret[i] =*(b2FilterJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2FilterJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2FilterJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2FilterJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2FilterJointDef_class_id);
				ret =(b2FilterJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2FilterJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2FilterJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2PrismaticJointDef * js_getb2PrismaticJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2PrismaticJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2PrismaticJointDef  *)js_malloc(ctx,size_ret*sizeof(b2PrismaticJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2PrismaticJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2PrismaticJointDef_class_id);
					ret[i] =*(b2PrismaticJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2PrismaticJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2PrismaticJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2PrismaticJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2PrismaticJointDef_class_id);
				ret =(b2PrismaticJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2PrismaticJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2PrismaticJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2RevoluteJointDef * js_getb2RevoluteJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2RevoluteJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2RevoluteJointDef  *)js_malloc(ctx,size_ret*sizeof(b2RevoluteJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2RevoluteJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2RevoluteJointDef_class_id);
					ret[i] =*(b2RevoluteJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2RevoluteJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2RevoluteJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2RevoluteJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2RevoluteJointDef_class_id);
				ret =(b2RevoluteJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RevoluteJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2RevoluteJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2WeldJointDef * js_getb2WeldJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2WeldJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2WeldJointDef  *)js_malloc(ctx,size_ret*sizeof(b2WeldJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2WeldJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2WeldJointDef_class_id);
					ret[i] =*(b2WeldJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2WeldJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2WeldJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2WeldJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WeldJointDef_class_id);
				ret =(b2WeldJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WeldJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WeldJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static b2WheelJointDef * js_getb2WheelJointDef_arr(JSContext * ctx,JSValue src,bool * error){
		b2WheelJointDef * ret;
		bool is_arrayProxy=(bool)0;
		if(JS_GetClassID((JSValueConst)src)==js_ArrayProxy_class_id){
			is_arrayProxy =(bool)1;
			void * AP_opaque=JS_GetOpaque((JSValueConst)src,js_ArrayProxy_class_id);
			ArrayProxy_class AP_fn=((ArrayProxy_class *)AP_opaque)[0];
			src =AP_fn.values(ctx,src,AP_fn.opaque,(int)0,false);
		}
		if(JS_IsArray((JSValueConst)src)){
			int64_t size_ret;
			if(JS_GetLength(ctx,(JSValueConst)src,&size_ret)==-1){
				error[0]=(bool)1;
				return NULL;
			}
			if(size_ret==0){
				JS_ThrowTypeError(ctx,(const char  *)"Received empty array");
				error[0]=(bool)1;
				return NULL;
			}
			ret =(b2WheelJointDef  *)js_malloc(ctx,size_ret*sizeof(b2WheelJointDef));
			for(int i=0;i<size_ret;i++){
				JSValue src0=JS_GetPropertyUint32(ctx,(JSValueConst)src,(uint32_t)i);
				JS_FreeValue(ctx,src0);
				if(JS_GetClassID((JSValueConst)src0)==js_b2WheelJointDef_class_id){
					opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src0,js_b2WheelJointDef_class_id);
					ret[i] =*(b2WheelJointDef *)tmpshadow[0].ptr;
				}else{
					JS_ThrowTypeError(ctx,(const char  *)"src0 does not match type b2WheelJointDef *");
					error[0]=(bool)1;
					return NULL;
				}
			}
			memoryStore(js_free,(void  *)ret);
		}else if(JS_GetClassID((JSValueConst)src)==js_b2WheelJointDef_class_id){
			if(JS_GetClassID((JSValueConst)src)==js_b2WheelJointDef_class_id){
				opaqueShadow * tmpshadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)src,js_b2WheelJointDef_class_id);
				ret =(b2WheelJointDef  *)tmpshadow[0].ptr;
			}else{
				JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WheelJointDef *");
				error[0]=(bool)1;
				return NULL;
			}
		}else{
			JS_ThrowTypeError(ctx,(const char  *)"src does not match type b2WheelJointDef *");
			error[0]=(bool)1;
			return NULL;
		}
		if(is_arrayProxy)JS_FreeValue(ctx,src);
		return ret;
	}
	
	static void js_b2Version_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Version_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Version_get_major(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		int major=ptr[0].major;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)major));
		return ret;
	}
	
	static JSValue js_b2Version_set_major(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].major=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Version_get_minor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		int minor=ptr[0].minor;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)minor));
		return ret;
	}
	
	static JSValue js_b2Version_set_minor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].minor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Version_get_revision(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		int revision=ptr[0].revision;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)revision));
		return ret;
	}
	
	static JSValue js_b2Version_set_revision(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Version_class_id);
		b2Version * ptr=(b2Version  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].revision=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Version_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Version", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("major",js_b2Version_get_major,js_b2Version_set_major),
		JS_CGETSET_DEF("minor",js_b2Version_get_minor,js_b2Version_set_minor),
		JS_CGETSET_DEF("revision",js_b2Version_get_revision,js_b2Version_set_revision)
	};
	
	static int js_declare_b2Version(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Version_class_id);
		JSClassDef js_b2Version_def={ .class_name = "b2Version", .finalizer = js_b2Version_finalizer };
		JS_NewClass(rt,js_b2Version_class_id,(const JSClassDef  *)&js_b2Version_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Version_proto_funcs,(int)countof(js_b2Version_proto_funcs));
		JS_SetClassProto(ctx,js_b2Version_class_id,proto);
		return 0;
	}
	
	static void js_b2Vec2_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Vec2_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Vec2_get_x(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Vec2_class_id);
		b2Vec2 * ptr=(b2Vec2  *)shadow[0].ptr;
		float x=ptr[0].x;
		JSValue ret=JS_NewFloat64(ctx,((double)x));
		return ret;
	}
	
	static JSValue js_b2Vec2_set_x(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Vec2_class_id);
		b2Vec2 * ptr=(b2Vec2  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].x=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Vec2_get_y(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Vec2_class_id);
		b2Vec2 * ptr=(b2Vec2  *)shadow[0].ptr;
		float y=ptr[0].y;
		JSValue ret=JS_NewFloat64(ctx,((double)y));
		return ret;
	}
	
	static JSValue js_b2Vec2_set_y(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Vec2_class_id);
		b2Vec2 * ptr=(b2Vec2  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].y=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Vec2_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Vec2", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("x",js_b2Vec2_get_x,js_b2Vec2_set_x),
		JS_CGETSET_DEF("y",js_b2Vec2_get_y,js_b2Vec2_set_y)
	};
	
	static int js_declare_b2Vec2(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Vec2_class_id);
		JSClassDef js_b2Vec2_def={ .class_name = "b2Vec2", .finalizer = js_b2Vec2_finalizer };
		JS_NewClass(rt,js_b2Vec2_class_id,(const JSClassDef  *)&js_b2Vec2_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Vec2_proto_funcs,(int)countof(js_b2Vec2_proto_funcs));
		JS_SetClassProto(ctx,js_b2Vec2_class_id,proto);
		return 0;
	}
	
	static void js_b2CosSin_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2CosSin_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2CosSin_get_cosine(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CosSin_class_id);
		b2CosSin * ptr=(b2CosSin  *)shadow[0].ptr;
		float cosine=ptr[0].cosine;
		JSValue ret=JS_NewFloat64(ctx,((double)cosine));
		return ret;
	}
	
	static JSValue js_b2CosSin_set_cosine(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CosSin_class_id);
		b2CosSin * ptr=(b2CosSin  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].cosine=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CosSin_get_sine(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CosSin_class_id);
		b2CosSin * ptr=(b2CosSin  *)shadow[0].ptr;
		float sine=ptr[0].sine;
		JSValue ret=JS_NewFloat64(ctx,((double)sine));
		return ret;
	}
	
	static JSValue js_b2CosSin_set_sine(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CosSin_class_id);
		b2CosSin * ptr=(b2CosSin  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sine=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2CosSin_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2CosSin", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("cosine",js_b2CosSin_get_cosine,js_b2CosSin_set_cosine),
		JS_CGETSET_DEF("sine",js_b2CosSin_get_sine,js_b2CosSin_set_sine)
	};
	
	static int js_declare_b2CosSin(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2CosSin_class_id);
		JSClassDef js_b2CosSin_def={ .class_name = "b2CosSin", .finalizer = js_b2CosSin_finalizer };
		JS_NewClass(rt,js_b2CosSin_class_id,(const JSClassDef  *)&js_b2CosSin_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2CosSin_proto_funcs,(int)countof(js_b2CosSin_proto_funcs));
		JS_SetClassProto(ctx,js_b2CosSin_class_id,proto);
		return 0;
	}
	
	static void js_b2Rot_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Rot_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Rot_get_c(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Rot_class_id);
		b2Rot * ptr=(b2Rot  *)shadow[0].ptr;
		float c=ptr[0].c;
		JSValue ret=JS_NewFloat64(ctx,((double)c));
		return ret;
	}
	
	static JSValue js_b2Rot_set_c(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Rot_class_id);
		b2Rot * ptr=(b2Rot  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].c=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Rot_get_s(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Rot_class_id);
		b2Rot * ptr=(b2Rot  *)shadow[0].ptr;
		float s=ptr[0].s;
		JSValue ret=JS_NewFloat64(ctx,((double)s));
		return ret;
	}
	
	static JSValue js_b2Rot_set_s(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Rot_class_id);
		b2Rot * ptr=(b2Rot  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].s=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Rot_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Rot", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("c",js_b2Rot_get_c,js_b2Rot_set_c),
		JS_CGETSET_DEF("s",js_b2Rot_get_s,js_b2Rot_set_s)
	};
	
	static int js_declare_b2Rot(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Rot_class_id);
		JSClassDef js_b2Rot_def={ .class_name = "b2Rot", .finalizer = js_b2Rot_finalizer };
		JS_NewClass(rt,js_b2Rot_class_id,(const JSClassDef  *)&js_b2Rot_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Rot_proto_funcs,(int)countof(js_b2Rot_proto_funcs));
		JS_SetClassProto(ctx,js_b2Rot_class_id,proto);
		return 0;
	}
	
	static void js_b2Transform_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Transform_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Transform_get_p(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Transform_class_id);
		b2Transform * ptr=(b2Transform  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * p=&ptr[0].p;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)p,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Transform_set_p(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Transform_class_id);
		b2Transform * ptr=(b2Transform  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].p=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Transform_get_q(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Transform_class_id);
		b2Transform * ptr=(b2Transform  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Rot * q=&ptr[0].q;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)q,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Transform_set_q(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Transform_class_id);
		b2Transform * ptr=(b2Transform  *)shadow[0].ptr;
		local_memlock=true;
		b2Rot value=js_getb2Rot(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].q=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Transform_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Transform", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("p",js_b2Transform_get_p,js_b2Transform_set_p),
		JS_CGETSET_DEF("q",js_b2Transform_get_q,js_b2Transform_set_q)
	};
	
	static int js_declare_b2Transform(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Transform_class_id);
		JSClassDef js_b2Transform_def={ .class_name = "b2Transform", .finalizer = js_b2Transform_finalizer };
		JS_NewClass(rt,js_b2Transform_class_id,(const JSClassDef  *)&js_b2Transform_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Transform_proto_funcs,(int)countof(js_b2Transform_proto_funcs));
		JS_SetClassProto(ctx,js_b2Transform_class_id,proto);
		return 0;
	}
	
	static void js_b2Mat22_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Mat22_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Mat22_get_cx(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Mat22_class_id);
		b2Mat22 * ptr=(b2Mat22  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * cx=&ptr[0].cx;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)cx,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Mat22_set_cx(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Mat22_class_id);
		b2Mat22 * ptr=(b2Mat22  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].cx=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Mat22_get_cy(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Mat22_class_id);
		b2Mat22 * ptr=(b2Mat22  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * cy=&ptr[0].cy;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)cy,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Mat22_set_cy(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Mat22_class_id);
		b2Mat22 * ptr=(b2Mat22  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].cy=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Mat22_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Mat22", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("cx",js_b2Mat22_get_cx,js_b2Mat22_set_cx),
		JS_CGETSET_DEF("cy",js_b2Mat22_get_cy,js_b2Mat22_set_cy)
	};
	
	static int js_declare_b2Mat22(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Mat22_class_id);
		JSClassDef js_b2Mat22_def={ .class_name = "b2Mat22", .finalizer = js_b2Mat22_finalizer };
		JS_NewClass(rt,js_b2Mat22_class_id,(const JSClassDef  *)&js_b2Mat22_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Mat22_proto_funcs,(int)countof(js_b2Mat22_proto_funcs));
		JS_SetClassProto(ctx,js_b2Mat22_class_id,proto);
		return 0;
	}
	
	static void js_b2AABB_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2AABB_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2AABB_get_lowerBound(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2AABB_class_id);
		b2AABB * ptr=(b2AABB  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * lowerBound=&ptr[0].lowerBound;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)lowerBound,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_set_lowerBound(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2AABB_class_id);
		b2AABB * ptr=(b2AABB  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].lowerBound=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2AABB_get_upperBound(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2AABB_class_id);
		b2AABB * ptr=(b2AABB  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * upperBound=&ptr[0].upperBound;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)upperBound,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_set_upperBound(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2AABB_class_id);
		b2AABB * ptr=(b2AABB  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].upperBound=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2AABB_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2AABB", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("lowerBound",js_b2AABB_get_lowerBound,js_b2AABB_set_lowerBound),
		JS_CGETSET_DEF("upperBound",js_b2AABB_get_upperBound,js_b2AABB_set_upperBound)
	};
	
	static int js_declare_b2AABB(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2AABB_class_id);
		JSClassDef js_b2AABB_def={ .class_name = "b2AABB", .finalizer = js_b2AABB_finalizer };
		JS_NewClass(rt,js_b2AABB_class_id,(const JSClassDef  *)&js_b2AABB_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2AABB_proto_funcs,(int)countof(js_b2AABB_proto_funcs));
		JS_SetClassProto(ctx,js_b2AABB_class_id,proto);
		return 0;
	}
	
	static void js_b2Plane_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Plane_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Plane_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Plane_class_id);
		b2Plane * ptr=(b2Plane  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Plane_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Plane_class_id);
		b2Plane * ptr=(b2Plane  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Plane_get_offset(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Plane_class_id);
		b2Plane * ptr=(b2Plane  *)shadow[0].ptr;
		float offset=ptr[0].offset;
		JSValue ret=JS_NewFloat64(ctx,((double)offset));
		return ret;
	}
	
	static JSValue js_b2Plane_set_offset(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Plane_class_id);
		b2Plane * ptr=(b2Plane  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].offset=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Plane_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Plane", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("normal",js_b2Plane_get_normal,js_b2Plane_set_normal),
		JS_CGETSET_DEF("offset",js_b2Plane_get_offset,js_b2Plane_set_offset)
	};
	
	static int js_declare_b2Plane(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Plane_class_id);
		JSClassDef js_b2Plane_def={ .class_name = "b2Plane", .finalizer = js_b2Plane_finalizer };
		JS_NewClass(rt,js_b2Plane_class_id,(const JSClassDef  *)&js_b2Plane_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Plane_proto_funcs,(int)countof(js_b2Plane_proto_funcs));
		JS_SetClassProto(ctx,js_b2Plane_class_id,proto);
		return 0;
	}
	
	static void js_b2SimplexCache_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SimplexCache_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SimplexCache_get_count(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		uint16_t count=ptr[0].count;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)count));
		return ret;
	}
	
	static JSValue js_b2SimplexCache_set_count(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].count=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexCache_indexA_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<3;i++){
			uint8_t src0=ptr[0].indexA[i];
			JSValue ret1=JS_NewUint32(ctx,(uint32_t)((unsigned long)src0));
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2SimplexCache_indexA_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		int length=(int)3;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2SimplexCache_indexA_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)3));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<3){
				uint8_t src=ptr[0].indexA[property];
				JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)src));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2SimplexCache_indexA_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<3){
				bool error=(bool)0;
				local_memlock=true;
				uint8_t ret=js_getuint8_t(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].indexA[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2SimplexCache_indexA_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<3){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2SimplexCache_get_indexA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2SimplexCache_indexA_values,.keys = js_b2SimplexCache_indexA_keys,.get = js_b2SimplexCache_indexA_get,.set = js_b2SimplexCache_indexA_set,.has = js_b2SimplexCache_indexA_has});
		return ret;
	}
	
	static JSValue js_b2SimplexCache_set_indexA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		local_memlock=true;
		uint8_t * value=js_getuint8_t_arr3nc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		memcpy((void  *)ptr[0].indexA,(const void  *)value,3*sizeof(uint8_t));
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexCache_indexB_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<3;i++){
			uint8_t src0=ptr[0].indexB[i];
			JSValue ret1=JS_NewUint32(ctx,(uint32_t)((unsigned long)src0));
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2SimplexCache_indexB_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		int length=(int)3;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2SimplexCache_indexB_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)3));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<3){
				uint8_t src=ptr[0].indexB[property];
				JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)src));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2SimplexCache_indexB_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<3){
				bool error=(bool)0;
				local_memlock=true;
				uint8_t ret=js_getuint8_t(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].indexB[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2SimplexCache_indexB_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2SimplexCache * ptr=(b2SimplexCache  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<3){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2SimplexCache_get_indexB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2SimplexCache_indexB_values,.keys = js_b2SimplexCache_indexB_keys,.get = js_b2SimplexCache_indexB_get,.set = js_b2SimplexCache_indexB_set,.has = js_b2SimplexCache_indexB_has});
		return ret;
	}
	
	static JSValue js_b2SimplexCache_set_indexB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexCache_class_id);
		b2SimplexCache * ptr=(b2SimplexCache  *)shadow[0].ptr;
		local_memlock=true;
		uint8_t * value=js_getuint8_t_arr3nc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		memcpy((void  *)ptr[0].indexB,(const void  *)value,3*sizeof(uint8_t));
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SimplexCache_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SimplexCache", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("count",js_b2SimplexCache_get_count,js_b2SimplexCache_set_count),
		JS_CGETSET_DEF("indexA",js_b2SimplexCache_get_indexA,js_b2SimplexCache_set_indexA),
		JS_CGETSET_DEF("indexB",js_b2SimplexCache_get_indexB,js_b2SimplexCache_set_indexB)
	};
	
	static int js_declare_b2SimplexCache(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SimplexCache_class_id);
		JSClassDef js_b2SimplexCache_def={ .class_name = "b2SimplexCache", .finalizer = js_b2SimplexCache_finalizer };
		JS_NewClass(rt,js_b2SimplexCache_class_id,(const JSClassDef  *)&js_b2SimplexCache_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SimplexCache_proto_funcs,(int)countof(js_b2SimplexCache_proto_funcs));
		JS_SetClassProto(ctx,js_b2SimplexCache_class_id,proto);
		return 0;
	}
	
	static void js_b2Hull_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Hull_class_id);
		deallocate_shadow(rt,shadow);
	}
	static const JSCFunctionListEntry js_b2Hull_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Hull", JS_PROP_CONFIGURABLE)
	};
	
	static int js_declare_b2Hull(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Hull_class_id);
		JSClassDef js_b2Hull_def={ .class_name = "b2Hull", .finalizer = js_b2Hull_finalizer };
		JS_NewClass(rt,js_b2Hull_class_id,(const JSClassDef  *)&js_b2Hull_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Hull_proto_funcs,(int)countof(js_b2Hull_proto_funcs));
		JS_SetClassProto(ctx,js_b2Hull_class_id,proto);
		return 0;
	}
	
	static void js_b2RayCastInput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2RayCastInput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2RayCastInput_get_origin(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * origin=&ptr[0].origin;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)origin,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RayCastInput_set_origin(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].origin=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayCastInput_get_translation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * translation=&ptr[0].translation;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)translation,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RayCastInput_set_translation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].translation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayCastInput_get_maxFraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		float maxFraction=ptr[0].maxFraction;
		JSValue ret=JS_NewFloat64(ctx,((double)maxFraction));
		return ret;
	}
	
	static JSValue js_b2RayCastInput_set_maxFraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayCastInput_class_id);
		b2RayCastInput * ptr=(b2RayCastInput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxFraction=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2RayCastInput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2RayCastInput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("origin",js_b2RayCastInput_get_origin,js_b2RayCastInput_set_origin),
		JS_CGETSET_DEF("translation",js_b2RayCastInput_get_translation,js_b2RayCastInput_set_translation),
		JS_CGETSET_DEF("maxFraction",js_b2RayCastInput_get_maxFraction,js_b2RayCastInput_set_maxFraction)
	};
	
	static int js_declare_b2RayCastInput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2RayCastInput_class_id);
		JSClassDef js_b2RayCastInput_def={ .class_name = "b2RayCastInput", .finalizer = js_b2RayCastInput_finalizer };
		JS_NewClass(rt,js_b2RayCastInput_class_id,(const JSClassDef  *)&js_b2RayCastInput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2RayCastInput_proto_funcs,(int)countof(js_b2RayCastInput_proto_funcs));
		JS_SetClassProto(ctx,js_b2RayCastInput_class_id,proto);
		return 0;
	}
	
	static void js_b2ShapeProxy_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ShapeProxy_class_id);
		deallocate_shadow(rt,shadow);
	}
	static const JSCFunctionListEntry js_b2ShapeProxy_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ShapeProxy", JS_PROP_CONFIGURABLE)
	};
	
	static int js_declare_b2ShapeProxy(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ShapeProxy_class_id);
		JSClassDef js_b2ShapeProxy_def={ .class_name = "b2ShapeProxy", .finalizer = js_b2ShapeProxy_finalizer };
		JS_NewClass(rt,js_b2ShapeProxy_class_id,(const JSClassDef  *)&js_b2ShapeProxy_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ShapeProxy_proto_funcs,(int)countof(js_b2ShapeProxy_proto_funcs));
		JS_SetClassProto(ctx,js_b2ShapeProxy_class_id,proto);
		return 0;
	}
	
	static void js_b2ShapeCastInput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ShapeCastInput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ShapeCastInput_get_proxy(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxy=&ptr[0].proxy;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxy,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastInput_set_proxy(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxy=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastInput_get_translation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * translation=&ptr[0].translation;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)translation,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastInput_set_translation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].translation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastInput_get_maxFraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		float maxFraction=ptr[0].maxFraction;
		JSValue ret=JS_NewFloat64(ctx,((double)maxFraction));
		return ret;
	}
	
	static JSValue js_b2ShapeCastInput_set_maxFraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxFraction=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastInput_get_canEncroach(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		bool canEncroach=ptr[0].canEncroach;
		JSValue ret=JS_NewBool(ctx,canEncroach);
		return ret;
	}
	
	static JSValue js_b2ShapeCastInput_set_canEncroach(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastInput_class_id);
		b2ShapeCastInput * ptr=(b2ShapeCastInput  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].canEncroach=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ShapeCastInput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ShapeCastInput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("proxy",js_b2ShapeCastInput_get_proxy,js_b2ShapeCastInput_set_proxy),
		JS_CGETSET_DEF("translation",js_b2ShapeCastInput_get_translation,js_b2ShapeCastInput_set_translation),
		JS_CGETSET_DEF("maxFraction",js_b2ShapeCastInput_get_maxFraction,js_b2ShapeCastInput_set_maxFraction),
		JS_CGETSET_DEF("canEncroach",js_b2ShapeCastInput_get_canEncroach,js_b2ShapeCastInput_set_canEncroach)
	};
	
	static int js_declare_b2ShapeCastInput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ShapeCastInput_class_id);
		JSClassDef js_b2ShapeCastInput_def={ .class_name = "b2ShapeCastInput", .finalizer = js_b2ShapeCastInput_finalizer };
		JS_NewClass(rt,js_b2ShapeCastInput_class_id,(const JSClassDef  *)&js_b2ShapeCastInput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ShapeCastInput_proto_funcs,(int)countof(js_b2ShapeCastInput_proto_funcs));
		JS_SetClassProto(ctx,js_b2ShapeCastInput_class_id,proto);
		return 0;
	}
	
	static void js_b2CastOutput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2CastOutput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2CastOutput_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CastOutput_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CastOutput_get_point(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point=&ptr[0].point;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CastOutput_set_point(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CastOutput_get_fraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		float fraction=ptr[0].fraction;
		JSValue ret=JS_NewFloat64(ctx,((double)fraction));
		return ret;
	}
	
	static JSValue js_b2CastOutput_set_fraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fraction=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CastOutput_get_iterations(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		int iterations=ptr[0].iterations;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)iterations));
		return ret;
	}
	
	static JSValue js_b2CastOutput_set_iterations(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].iterations=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CastOutput_get_hit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		bool hit=ptr[0].hit;
		JSValue ret=JS_NewBool(ctx,hit);
		return ret;
	}
	
	static JSValue js_b2CastOutput_set_hit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CastOutput_class_id);
		b2CastOutput * ptr=(b2CastOutput  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hit=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2CastOutput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2CastOutput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("normal",js_b2CastOutput_get_normal,js_b2CastOutput_set_normal),
		JS_CGETSET_DEF("point",js_b2CastOutput_get_point,js_b2CastOutput_set_point),
		JS_CGETSET_DEF("fraction",js_b2CastOutput_get_fraction,js_b2CastOutput_set_fraction),
		JS_CGETSET_DEF("iterations",js_b2CastOutput_get_iterations,js_b2CastOutput_set_iterations),
		JS_CGETSET_DEF("hit",js_b2CastOutput_get_hit,js_b2CastOutput_set_hit)
	};
	
	static int js_declare_b2CastOutput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2CastOutput_class_id);
		JSClassDef js_b2CastOutput_def={ .class_name = "b2CastOutput", .finalizer = js_b2CastOutput_finalizer };
		JS_NewClass(rt,js_b2CastOutput_class_id,(const JSClassDef  *)&js_b2CastOutput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2CastOutput_proto_funcs,(int)countof(js_b2CastOutput_proto_funcs));
		JS_SetClassProto(ctx,js_b2CastOutput_class_id,proto);
		return 0;
	}
	
	static void js_b2MassData_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2MassData_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2MassData_get_mass(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		float mass=ptr[0].mass;
		JSValue ret=JS_NewFloat64(ctx,((double)mass));
		return ret;
	}
	
	static JSValue js_b2MassData_set_mass(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].mass=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MassData_get_center(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * center=&ptr[0].center;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)center,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MassData_set_center(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].center=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MassData_get_rotationalInertia(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		float rotationalInertia=ptr[0].rotationalInertia;
		JSValue ret=JS_NewFloat64(ctx,((double)rotationalInertia));
		return ret;
	}
	
	static JSValue js_b2MassData_set_rotationalInertia(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MassData_class_id);
		b2MassData * ptr=(b2MassData  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].rotationalInertia=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2MassData_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2MassData", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("mass",js_b2MassData_get_mass,js_b2MassData_set_mass),
		JS_CGETSET_DEF("center",js_b2MassData_get_center,js_b2MassData_set_center),
		JS_CGETSET_DEF("rotationalInertia",js_b2MassData_get_rotationalInertia,js_b2MassData_set_rotationalInertia)
	};
	
	static int js_declare_b2MassData(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2MassData_class_id);
		JSClassDef js_b2MassData_def={ .class_name = "b2MassData", .finalizer = js_b2MassData_finalizer };
		JS_NewClass(rt,js_b2MassData_class_id,(const JSClassDef  *)&js_b2MassData_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2MassData_proto_funcs,(int)countof(js_b2MassData_proto_funcs));
		JS_SetClassProto(ctx,js_b2MassData_class_id,proto);
		return 0;
	}
	
	static void js_b2Circle_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Circle_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Circle_get_center(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Circle_class_id);
		b2Circle * ptr=(b2Circle  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * center=&ptr[0].center;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)center,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Circle_set_center(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Circle_class_id);
		b2Circle * ptr=(b2Circle  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].center=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Circle_get_radius(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Circle_class_id);
		b2Circle * ptr=(b2Circle  *)shadow[0].ptr;
		float radius=ptr[0].radius;
		JSValue ret=JS_NewFloat64(ctx,((double)radius));
		return ret;
	}
	
	static JSValue js_b2Circle_set_radius(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Circle_class_id);
		b2Circle * ptr=(b2Circle  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].radius=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Circle_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Circle", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("center",js_b2Circle_get_center,js_b2Circle_set_center),
		JS_CGETSET_DEF("radius",js_b2Circle_get_radius,js_b2Circle_set_radius)
	};
	
	static int js_declare_b2Circle(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Circle_class_id);
		JSClassDef js_b2Circle_def={ .class_name = "b2Circle", .finalizer = js_b2Circle_finalizer };
		JS_NewClass(rt,js_b2Circle_class_id,(const JSClassDef  *)&js_b2Circle_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Circle_proto_funcs,(int)countof(js_b2Circle_proto_funcs));
		JS_SetClassProto(ctx,js_b2Circle_class_id,proto);
		return 0;
	}
	
	static void js_b2Capsule_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Capsule_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Capsule_get_center1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * center1=&ptr[0].center1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)center1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Capsule_set_center1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].center1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Capsule_get_center2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * center2=&ptr[0].center2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)center2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Capsule_set_center2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].center2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Capsule_get_radius(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		float radius=ptr[0].radius;
		JSValue ret=JS_NewFloat64(ctx,((double)radius));
		return ret;
	}
	
	static JSValue js_b2Capsule_set_radius(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Capsule_class_id);
		b2Capsule * ptr=(b2Capsule  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].radius=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Capsule_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Capsule", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("center1",js_b2Capsule_get_center1,js_b2Capsule_set_center1),
		JS_CGETSET_DEF("center2",js_b2Capsule_get_center2,js_b2Capsule_set_center2),
		JS_CGETSET_DEF("radius",js_b2Capsule_get_radius,js_b2Capsule_set_radius)
	};
	
	static int js_declare_b2Capsule(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Capsule_class_id);
		JSClassDef js_b2Capsule_def={ .class_name = "b2Capsule", .finalizer = js_b2Capsule_finalizer };
		JS_NewClass(rt,js_b2Capsule_class_id,(const JSClassDef  *)&js_b2Capsule_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Capsule_proto_funcs,(int)countof(js_b2Capsule_proto_funcs));
		JS_SetClassProto(ctx,js_b2Capsule_class_id,proto);
		return 0;
	}
	
	static void js_b2Polygon_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Polygon_class_id);
		deallocate_shadow(rt,shadow);
	}
	static const JSCFunctionListEntry js_b2Polygon_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Polygon", JS_PROP_CONFIGURABLE)
	};
	
	static int js_declare_b2Polygon(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Polygon_class_id);
		JSClassDef js_b2Polygon_def={ .class_name = "b2Polygon", .finalizer = js_b2Polygon_finalizer };
		JS_NewClass(rt,js_b2Polygon_class_id,(const JSClassDef  *)&js_b2Polygon_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Polygon_proto_funcs,(int)countof(js_b2Polygon_proto_funcs));
		JS_SetClassProto(ctx,js_b2Polygon_class_id,proto);
		return 0;
	}
	
	static void js_b2Segment_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Segment_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Segment_get_point1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Segment_class_id);
		b2Segment * ptr=(b2Segment  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point1=&ptr[0].point1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Segment_set_point1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Segment_class_id);
		b2Segment * ptr=(b2Segment  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Segment_get_point2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Segment_class_id);
		b2Segment * ptr=(b2Segment  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point2=&ptr[0].point2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Segment_set_point2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Segment_class_id);
		b2Segment * ptr=(b2Segment  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point2=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Segment_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Segment", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("point1",js_b2Segment_get_point1,js_b2Segment_set_point1),
		JS_CGETSET_DEF("point2",js_b2Segment_get_point2,js_b2Segment_set_point2)
	};
	
	static int js_declare_b2Segment(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Segment_class_id);
		JSClassDef js_b2Segment_def={ .class_name = "b2Segment", .finalizer = js_b2Segment_finalizer };
		JS_NewClass(rt,js_b2Segment_class_id,(const JSClassDef  *)&js_b2Segment_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Segment_proto_funcs,(int)countof(js_b2Segment_proto_funcs));
		JS_SetClassProto(ctx,js_b2Segment_class_id,proto);
		return 0;
	}
	
	static void js_b2ChainSegment_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ChainSegment_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ChainSegment_get_ghost1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * ghost1=&ptr[0].ghost1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)ghost1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ChainSegment_set_ghost1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].ghost1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainSegment_get_segment(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Segment * segment=&ptr[0].segment;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)segment,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Segment_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ChainSegment_set_segment(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		local_memlock=true;
		b2Segment value=js_getb2Segment(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].segment=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainSegment_get_ghost2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * ghost2=&ptr[0].ghost2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)ghost2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ChainSegment_set_ghost2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].ghost2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainSegment_get_chainId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		int chainId=ptr[0].chainId;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)chainId));
		return ret;
	}
	
	static JSValue js_b2ChainSegment_set_chainId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainSegment_class_id);
		b2ChainSegment * ptr=(b2ChainSegment  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].chainId=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ChainSegment_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ChainSegment", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("ghost1",js_b2ChainSegment_get_ghost1,js_b2ChainSegment_set_ghost1),
		JS_CGETSET_DEF("segment",js_b2ChainSegment_get_segment,js_b2ChainSegment_set_segment),
		JS_CGETSET_DEF("ghost2",js_b2ChainSegment_get_ghost2,js_b2ChainSegment_set_ghost2),
		JS_CGETSET_DEF("chainId",js_b2ChainSegment_get_chainId,js_b2ChainSegment_set_chainId)
	};
	
	static int js_declare_b2ChainSegment(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ChainSegment_class_id);
		JSClassDef js_b2ChainSegment_def={ .class_name = "b2ChainSegment", .finalizer = js_b2ChainSegment_finalizer };
		JS_NewClass(rt,js_b2ChainSegment_class_id,(const JSClassDef  *)&js_b2ChainSegment_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ChainSegment_proto_funcs,(int)countof(js_b2ChainSegment_proto_funcs));
		JS_SetClassProto(ctx,js_b2ChainSegment_class_id,proto);
		return 0;
	}
	
	static void js_b2SegmentDistanceResult_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SegmentDistanceResult_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SegmentDistanceResult_get_closest1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * closest1=&ptr[0].closest1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)closest1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SegmentDistanceResult_set_closest1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].closest1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SegmentDistanceResult_get_closest2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * closest2=&ptr[0].closest2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)closest2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SegmentDistanceResult_set_closest2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].closest2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SegmentDistanceResult_get_fraction1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		float fraction1=ptr[0].fraction1;
		JSValue ret=JS_NewFloat64(ctx,((double)fraction1));
		return ret;
	}
	
	static JSValue js_b2SegmentDistanceResult_set_fraction1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fraction1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SegmentDistanceResult_get_fraction2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		float fraction2=ptr[0].fraction2;
		JSValue ret=JS_NewFloat64(ctx,((double)fraction2));
		return ret;
	}
	
	static JSValue js_b2SegmentDistanceResult_set_fraction2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fraction2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SegmentDistanceResult_get_distanceSquared(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		float distanceSquared=ptr[0].distanceSquared;
		JSValue ret=JS_NewFloat64(ctx,((double)distanceSquared));
		return ret;
	}
	
	static JSValue js_b2SegmentDistanceResult_set_distanceSquared(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SegmentDistanceResult_class_id);
		b2SegmentDistanceResult * ptr=(b2SegmentDistanceResult  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].distanceSquared=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SegmentDistanceResult_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SegmentDistanceResult", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("closest1",js_b2SegmentDistanceResult_get_closest1,js_b2SegmentDistanceResult_set_closest1),
		JS_CGETSET_DEF("closest2",js_b2SegmentDistanceResult_get_closest2,js_b2SegmentDistanceResult_set_closest2),
		JS_CGETSET_DEF("fraction1",js_b2SegmentDistanceResult_get_fraction1,js_b2SegmentDistanceResult_set_fraction1),
		JS_CGETSET_DEF("fraction2",js_b2SegmentDistanceResult_get_fraction2,js_b2SegmentDistanceResult_set_fraction2),
		JS_CGETSET_DEF("distanceSquared",js_b2SegmentDistanceResult_get_distanceSquared,js_b2SegmentDistanceResult_set_distanceSquared)
	};
	
	static int js_declare_b2SegmentDistanceResult(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SegmentDistanceResult_class_id);
		JSClassDef js_b2SegmentDistanceResult_def={ .class_name = "b2SegmentDistanceResult", .finalizer = js_b2SegmentDistanceResult_finalizer };
		JS_NewClass(rt,js_b2SegmentDistanceResult_class_id,(const JSClassDef  *)&js_b2SegmentDistanceResult_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SegmentDistanceResult_proto_funcs,(int)countof(js_b2SegmentDistanceResult_proto_funcs));
		JS_SetClassProto(ctx,js_b2SegmentDistanceResult_class_id,proto);
		return 0;
	}
	
	static void js_b2DistanceInput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2DistanceInput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2DistanceInput_get_proxyA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyA=&ptr[0].proxyA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceInput_set_proxyA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceInput_get_proxyB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyB=&ptr[0].proxyB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceInput_set_proxyB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceInput_get_transformA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Transform * transformA=&ptr[0].transformA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)transformA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceInput_set_transformA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Transform value=js_getb2Transform(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transformA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceInput_get_transformB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Transform * transformB=&ptr[0].transformB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)transformB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceInput_set_transformB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Transform value=js_getb2Transform(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transformB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceInput_get_useRadii(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		bool useRadii=ptr[0].useRadii;
		JSValue ret=JS_NewBool(ctx,useRadii);
		return ret;
	}
	
	static JSValue js_b2DistanceInput_set_useRadii(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceInput_class_id);
		b2DistanceInput * ptr=(b2DistanceInput  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].useRadii=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2DistanceInput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2DistanceInput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("proxyA",js_b2DistanceInput_get_proxyA,js_b2DistanceInput_set_proxyA),
		JS_CGETSET_DEF("proxyB",js_b2DistanceInput_get_proxyB,js_b2DistanceInput_set_proxyB),
		JS_CGETSET_DEF("transformA",js_b2DistanceInput_get_transformA,js_b2DistanceInput_set_transformA),
		JS_CGETSET_DEF("transformB",js_b2DistanceInput_get_transformB,js_b2DistanceInput_set_transformB),
		JS_CGETSET_DEF("useRadii",js_b2DistanceInput_get_useRadii,js_b2DistanceInput_set_useRadii)
	};
	
	static int js_declare_b2DistanceInput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2DistanceInput_class_id);
		JSClassDef js_b2DistanceInput_def={ .class_name = "b2DistanceInput", .finalizer = js_b2DistanceInput_finalizer };
		JS_NewClass(rt,js_b2DistanceInput_class_id,(const JSClassDef  *)&js_b2DistanceInput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2DistanceInput_proto_funcs,(int)countof(js_b2DistanceInput_proto_funcs));
		JS_SetClassProto(ctx,js_b2DistanceInput_class_id,proto);
		return 0;
	}
	
	static void js_b2DistanceOutput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2DistanceOutput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2DistanceOutput_get_pointA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * pointA=&ptr[0].pointA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)pointA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_pointA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].pointA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceOutput_get_pointB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * pointB=&ptr[0].pointB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)pointB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_pointB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].pointB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceOutput_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceOutput_get_distance(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		float distance=ptr[0].distance;
		JSValue ret=JS_NewFloat64(ctx,((double)distance));
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_distance(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].distance=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceOutput_get_iterations(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		int iterations=ptr[0].iterations;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)iterations));
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_iterations(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].iterations=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceOutput_get_simplexCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		int simplexCount=ptr[0].simplexCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)simplexCount));
		return ret;
	}
	
	static JSValue js_b2DistanceOutput_set_simplexCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceOutput_class_id);
		b2DistanceOutput * ptr=(b2DistanceOutput  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].simplexCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2DistanceOutput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2DistanceOutput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("pointA",js_b2DistanceOutput_get_pointA,js_b2DistanceOutput_set_pointA),
		JS_CGETSET_DEF("pointB",js_b2DistanceOutput_get_pointB,js_b2DistanceOutput_set_pointB),
		JS_CGETSET_DEF("normal",js_b2DistanceOutput_get_normal,js_b2DistanceOutput_set_normal),
		JS_CGETSET_DEF("distance",js_b2DistanceOutput_get_distance,js_b2DistanceOutput_set_distance),
		JS_CGETSET_DEF("iterations",js_b2DistanceOutput_get_iterations,js_b2DistanceOutput_set_iterations),
		JS_CGETSET_DEF("simplexCount",js_b2DistanceOutput_get_simplexCount,js_b2DistanceOutput_set_simplexCount)
	};
	
	static int js_declare_b2DistanceOutput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2DistanceOutput_class_id);
		JSClassDef js_b2DistanceOutput_def={ .class_name = "b2DistanceOutput", .finalizer = js_b2DistanceOutput_finalizer };
		JS_NewClass(rt,js_b2DistanceOutput_class_id,(const JSClassDef  *)&js_b2DistanceOutput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2DistanceOutput_proto_funcs,(int)countof(js_b2DistanceOutput_proto_funcs));
		JS_SetClassProto(ctx,js_b2DistanceOutput_class_id,proto);
		return 0;
	}
	
	static void js_b2SimplexVertex_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SimplexVertex_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SimplexVertex_get_wA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * wA=&ptr[0].wA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)wA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_wA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].wA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexVertex_get_wB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * wB=&ptr[0].wB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)wB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_wB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].wB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexVertex_get_w(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * w=&ptr[0].w;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)w,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_w(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].w=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexVertex_get_a(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		float a=ptr[0].a;
		JSValue ret=JS_NewFloat64(ctx,((double)a));
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_a(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].a=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexVertex_get_indexA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		int indexA=ptr[0].indexA;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)indexA));
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_indexA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].indexA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SimplexVertex_get_indexB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		int indexB=ptr[0].indexB;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)indexB));
		return ret;
	}
	
	static JSValue js_b2SimplexVertex_set_indexB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SimplexVertex_class_id);
		b2SimplexVertex * ptr=(b2SimplexVertex  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].indexB=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SimplexVertex_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SimplexVertex", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("wA",js_b2SimplexVertex_get_wA,js_b2SimplexVertex_set_wA),
		JS_CGETSET_DEF("wB",js_b2SimplexVertex_get_wB,js_b2SimplexVertex_set_wB),
		JS_CGETSET_DEF("w",js_b2SimplexVertex_get_w,js_b2SimplexVertex_set_w),
		JS_CGETSET_DEF("a",js_b2SimplexVertex_get_a,js_b2SimplexVertex_set_a),
		JS_CGETSET_DEF("indexA",js_b2SimplexVertex_get_indexA,js_b2SimplexVertex_set_indexA),
		JS_CGETSET_DEF("indexB",js_b2SimplexVertex_get_indexB,js_b2SimplexVertex_set_indexB)
	};
	
	static int js_declare_b2SimplexVertex(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SimplexVertex_class_id);
		JSClassDef js_b2SimplexVertex_def={ .class_name = "b2SimplexVertex", .finalizer = js_b2SimplexVertex_finalizer };
		JS_NewClass(rt,js_b2SimplexVertex_class_id,(const JSClassDef  *)&js_b2SimplexVertex_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SimplexVertex_proto_funcs,(int)countof(js_b2SimplexVertex_proto_funcs));
		JS_SetClassProto(ctx,js_b2SimplexVertex_class_id,proto);
		return 0;
	}
	
	static void js_b2Simplex_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Simplex_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Simplex_get_v1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2SimplexVertex * v1=&ptr[0].v1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)v1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2SimplexVertex_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Simplex_set_v1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		local_memlock=true;
		b2SimplexVertex value=js_getb2SimplexVertex(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].v1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Simplex_get_v2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2SimplexVertex * v2=&ptr[0].v2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)v2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2SimplexVertex_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Simplex_set_v2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		local_memlock=true;
		b2SimplexVertex value=js_getb2SimplexVertex(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].v2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Simplex_get_v3(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2SimplexVertex * v3=&ptr[0].v3;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)v3,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2SimplexVertex_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Simplex_set_v3(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		local_memlock=true;
		b2SimplexVertex value=js_getb2SimplexVertex(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].v3=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Simplex_get_count(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		int count=ptr[0].count;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)count));
		return ret;
	}
	
	static JSValue js_b2Simplex_set_count(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Simplex_class_id);
		b2Simplex * ptr=(b2Simplex  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].count=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Simplex_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Simplex", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("v1",js_b2Simplex_get_v1,js_b2Simplex_set_v1),
		JS_CGETSET_DEF("v2",js_b2Simplex_get_v2,js_b2Simplex_set_v2),
		JS_CGETSET_DEF("v3",js_b2Simplex_get_v3,js_b2Simplex_set_v3),
		JS_CGETSET_DEF("count",js_b2Simplex_get_count,js_b2Simplex_set_count)
	};
	
	static int js_declare_b2Simplex(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Simplex_class_id);
		JSClassDef js_b2Simplex_def={ .class_name = "b2Simplex", .finalizer = js_b2Simplex_finalizer };
		JS_NewClass(rt,js_b2Simplex_class_id,(const JSClassDef  *)&js_b2Simplex_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Simplex_proto_funcs,(int)countof(js_b2Simplex_proto_funcs));
		JS_SetClassProto(ctx,js_b2Simplex_class_id,proto);
		return 0;
	}
	
	static void js_b2ShapeCastPairInput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ShapeCastPairInput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ShapeCastPairInput_get_proxyA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyA=&ptr[0].proxyA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_proxyA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_proxyB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyB=&ptr[0].proxyB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_proxyB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_transformA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Transform * transformA=&ptr[0].transformA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)transformA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_transformA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Transform value=js_getb2Transform(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transformA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_transformB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Transform * transformB=&ptr[0].transformB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)transformB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_transformB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Transform value=js_getb2Transform(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transformB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_translationB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * translationB=&ptr[0].translationB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)translationB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_translationB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].translationB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_maxFraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		float maxFraction=ptr[0].maxFraction;
		JSValue ret=JS_NewFloat64(ctx,((double)maxFraction));
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_maxFraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxFraction=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeCastPairInput_get_canEncroach(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		bool canEncroach=ptr[0].canEncroach;
		JSValue ret=JS_NewBool(ctx,canEncroach);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPairInput_set_canEncroach(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeCastPairInput_class_id);
		b2ShapeCastPairInput * ptr=(b2ShapeCastPairInput  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].canEncroach=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ShapeCastPairInput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ShapeCastPairInput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("proxyA",js_b2ShapeCastPairInput_get_proxyA,js_b2ShapeCastPairInput_set_proxyA),
		JS_CGETSET_DEF("proxyB",js_b2ShapeCastPairInput_get_proxyB,js_b2ShapeCastPairInput_set_proxyB),
		JS_CGETSET_DEF("transformA",js_b2ShapeCastPairInput_get_transformA,js_b2ShapeCastPairInput_set_transformA),
		JS_CGETSET_DEF("transformB",js_b2ShapeCastPairInput_get_transformB,js_b2ShapeCastPairInput_set_transformB),
		JS_CGETSET_DEF("translationB",js_b2ShapeCastPairInput_get_translationB,js_b2ShapeCastPairInput_set_translationB),
		JS_CGETSET_DEF("maxFraction",js_b2ShapeCastPairInput_get_maxFraction,js_b2ShapeCastPairInput_set_maxFraction),
		JS_CGETSET_DEF("canEncroach",js_b2ShapeCastPairInput_get_canEncroach,js_b2ShapeCastPairInput_set_canEncroach)
	};
	
	static int js_declare_b2ShapeCastPairInput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ShapeCastPairInput_class_id);
		JSClassDef js_b2ShapeCastPairInput_def={ .class_name = "b2ShapeCastPairInput", .finalizer = js_b2ShapeCastPairInput_finalizer };
		JS_NewClass(rt,js_b2ShapeCastPairInput_class_id,(const JSClassDef  *)&js_b2ShapeCastPairInput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ShapeCastPairInput_proto_funcs,(int)countof(js_b2ShapeCastPairInput_proto_funcs));
		JS_SetClassProto(ctx,js_b2ShapeCastPairInput_class_id,proto);
		return 0;
	}
	
	static void js_b2Sweep_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Sweep_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Sweep_get_localCenter(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localCenter=&ptr[0].localCenter;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localCenter,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sweep_set_localCenter(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localCenter=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Sweep_get_c1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * c1=&ptr[0].c1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)c1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sweep_set_c1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].c1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Sweep_get_c2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * c2=&ptr[0].c2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)c2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sweep_set_c2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].c2=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Sweep_get_q1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Rot * q1=&ptr[0].q1;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)q1,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sweep_set_q1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		local_memlock=true;
		b2Rot value=js_getb2Rot(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].q1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Sweep_get_q2(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Rot * q2=&ptr[0].q2;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)q2,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sweep_set_q2(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Sweep_class_id);
		b2Sweep * ptr=(b2Sweep  *)shadow[0].ptr;
		local_memlock=true;
		b2Rot value=js_getb2Rot(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].q2=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Sweep_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Sweep", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("localCenter",js_b2Sweep_get_localCenter,js_b2Sweep_set_localCenter),
		JS_CGETSET_DEF("c1",js_b2Sweep_get_c1,js_b2Sweep_set_c1),
		JS_CGETSET_DEF("c2",js_b2Sweep_get_c2,js_b2Sweep_set_c2),
		JS_CGETSET_DEF("q1",js_b2Sweep_get_q1,js_b2Sweep_set_q1),
		JS_CGETSET_DEF("q2",js_b2Sweep_get_q2,js_b2Sweep_set_q2)
	};
	
	static int js_declare_b2Sweep(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Sweep_class_id);
		JSClassDef js_b2Sweep_def={ .class_name = "b2Sweep", .finalizer = js_b2Sweep_finalizer };
		JS_NewClass(rt,js_b2Sweep_class_id,(const JSClassDef  *)&js_b2Sweep_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Sweep_proto_funcs,(int)countof(js_b2Sweep_proto_funcs));
		JS_SetClassProto(ctx,js_b2Sweep_class_id,proto);
		return 0;
	}
	
	static void js_b2TOIInput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2TOIInput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2TOIInput_get_proxyA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyA=&ptr[0].proxyA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TOIInput_set_proxyA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TOIInput_get_proxyB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeProxy * proxyB=&ptr[0].proxyB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)proxyB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TOIInput_set_proxyB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeProxy value=js_getb2ShapeProxy(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].proxyB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TOIInput_get_sweepA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Sweep * sweepA=&ptr[0].sweepA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)sweepA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Sweep_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TOIInput_set_sweepA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Sweep value=js_getb2Sweep(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sweepA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TOIInput_get_sweepB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Sweep * sweepB=&ptr[0].sweepB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)sweepB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Sweep_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TOIInput_set_sweepB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		local_memlock=true;
		b2Sweep value=js_getb2Sweep(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sweepB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TOIInput_get_maxFraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		float maxFraction=ptr[0].maxFraction;
		JSValue ret=JS_NewFloat64(ctx,((double)maxFraction));
		return ret;
	}
	
	static JSValue js_b2TOIInput_set_maxFraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIInput_class_id);
		b2TOIInput * ptr=(b2TOIInput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxFraction=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2TOIInput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2TOIInput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("proxyA",js_b2TOIInput_get_proxyA,js_b2TOIInput_set_proxyA),
		JS_CGETSET_DEF("proxyB",js_b2TOIInput_get_proxyB,js_b2TOIInput_set_proxyB),
		JS_CGETSET_DEF("sweepA",js_b2TOIInput_get_sweepA,js_b2TOIInput_set_sweepA),
		JS_CGETSET_DEF("sweepB",js_b2TOIInput_get_sweepB,js_b2TOIInput_set_sweepB),
		JS_CGETSET_DEF("maxFraction",js_b2TOIInput_get_maxFraction,js_b2TOIInput_set_maxFraction)
	};
	
	static int js_declare_b2TOIInput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2TOIInput_class_id);
		JSClassDef js_b2TOIInput_def={ .class_name = "b2TOIInput", .finalizer = js_b2TOIInput_finalizer };
		JS_NewClass(rt,js_b2TOIInput_class_id,(const JSClassDef  *)&js_b2TOIInput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2TOIInput_proto_funcs,(int)countof(js_b2TOIInput_proto_funcs));
		JS_SetClassProto(ctx,js_b2TOIInput_class_id,proto);
		return 0;
	}
	
	static void js_b2TOIOutput_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2TOIOutput_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2TOIOutput_get_state(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIOutput_class_id);
		b2TOIOutput * ptr=(b2TOIOutput  *)shadow[0].ptr;
		b2TOIState state=ptr[0].state;
		JSValue ret=JS_NewInt32(ctx,(int32_t)state);
		return ret;
	}
	
	static JSValue js_b2TOIOutput_set_state(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIOutput_class_id);
		b2TOIOutput * ptr=(b2TOIOutput  *)shadow[0].ptr;
		local_memlock=true;
		b2TOIState value=js_getb2TOIState(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].state=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TOIOutput_get_fraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIOutput_class_id);
		b2TOIOutput * ptr=(b2TOIOutput  *)shadow[0].ptr;
		float fraction=ptr[0].fraction;
		JSValue ret=JS_NewFloat64(ctx,((double)fraction));
		return ret;
	}
	
	static JSValue js_b2TOIOutput_set_fraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TOIOutput_class_id);
		b2TOIOutput * ptr=(b2TOIOutput  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fraction=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2TOIOutput_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2TOIOutput", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("state",js_b2TOIOutput_get_state,js_b2TOIOutput_set_state),
		JS_CGETSET_DEF("fraction",js_b2TOIOutput_get_fraction,js_b2TOIOutput_set_fraction)
	};
	
	static int js_declare_b2TOIOutput(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2TOIOutput_class_id);
		JSClassDef js_b2TOIOutput_def={ .class_name = "b2TOIOutput", .finalizer = js_b2TOIOutput_finalizer };
		JS_NewClass(rt,js_b2TOIOutput_class_id,(const JSClassDef  *)&js_b2TOIOutput_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2TOIOutput_proto_funcs,(int)countof(js_b2TOIOutput_proto_funcs));
		JS_SetClassProto(ctx,js_b2TOIOutput_class_id,proto);
		return 0;
	}
	
	static void js_b2ManifoldPoint_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ManifoldPoint_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ManifoldPoint_get_point(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point=&ptr[0].point;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_point(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_anchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * anchorA=&ptr[0].anchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)anchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_anchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].anchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_anchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * anchorB=&ptr[0].anchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)anchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_anchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].anchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_separation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		float separation=ptr[0].separation;
		JSValue ret=JS_NewFloat64(ctx,((double)separation));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_separation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].separation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_normalImpulse(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		float normalImpulse=ptr[0].normalImpulse;
		JSValue ret=JS_NewFloat64(ctx,((double)normalImpulse));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_normalImpulse(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normalImpulse=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_tangentImpulse(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		float tangentImpulse=ptr[0].tangentImpulse;
		JSValue ret=JS_NewFloat64(ctx,((double)tangentImpulse));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_tangentImpulse(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].tangentImpulse=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_totalNormalImpulse(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		float totalNormalImpulse=ptr[0].totalNormalImpulse;
		JSValue ret=JS_NewFloat64(ctx,((double)totalNormalImpulse));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_totalNormalImpulse(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].totalNormalImpulse=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_normalVelocity(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		float normalVelocity=ptr[0].normalVelocity;
		JSValue ret=JS_NewFloat64(ctx,((double)normalVelocity));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_normalVelocity(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normalVelocity=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_id(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		uint16_t id=ptr[0].id;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)id));
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_id(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].id=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ManifoldPoint_get_persisted(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		bool persisted=ptr[0].persisted;
		JSValue ret=JS_NewBool(ctx,persisted);
		return ret;
	}
	
	static JSValue js_b2ManifoldPoint_set_persisted(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ManifoldPoint_class_id);
		b2ManifoldPoint * ptr=(b2ManifoldPoint  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].persisted=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ManifoldPoint_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ManifoldPoint", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("point",js_b2ManifoldPoint_get_point,js_b2ManifoldPoint_set_point),
		JS_CGETSET_DEF("anchorA",js_b2ManifoldPoint_get_anchorA,js_b2ManifoldPoint_set_anchorA),
		JS_CGETSET_DEF("anchorB",js_b2ManifoldPoint_get_anchorB,js_b2ManifoldPoint_set_anchorB),
		JS_CGETSET_DEF("separation",js_b2ManifoldPoint_get_separation,js_b2ManifoldPoint_set_separation),
		JS_CGETSET_DEF("normalImpulse",js_b2ManifoldPoint_get_normalImpulse,js_b2ManifoldPoint_set_normalImpulse),
		JS_CGETSET_DEF("tangentImpulse",js_b2ManifoldPoint_get_tangentImpulse,js_b2ManifoldPoint_set_tangentImpulse),
		JS_CGETSET_DEF("totalNormalImpulse",js_b2ManifoldPoint_get_totalNormalImpulse,js_b2ManifoldPoint_set_totalNormalImpulse),
		JS_CGETSET_DEF("normalVelocity",js_b2ManifoldPoint_get_normalVelocity,js_b2ManifoldPoint_set_normalVelocity),
		JS_CGETSET_DEF("id",js_b2ManifoldPoint_get_id,js_b2ManifoldPoint_set_id),
		JS_CGETSET_DEF("persisted",js_b2ManifoldPoint_get_persisted,js_b2ManifoldPoint_set_persisted)
	};
	
	static int js_declare_b2ManifoldPoint(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ManifoldPoint_class_id);
		JSClassDef js_b2ManifoldPoint_def={ .class_name = "b2ManifoldPoint", .finalizer = js_b2ManifoldPoint_finalizer };
		JS_NewClass(rt,js_b2ManifoldPoint_class_id,(const JSClassDef  *)&js_b2ManifoldPoint_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ManifoldPoint_proto_funcs,(int)countof(js_b2ManifoldPoint_proto_funcs));
		JS_SetClassProto(ctx,js_b2ManifoldPoint_class_id,proto);
		return 0;
	}
	
	static void js_b2Manifold_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Manifold_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Manifold_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Manifold_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Manifold_get_rollingImpulse(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		float rollingImpulse=ptr[0].rollingImpulse;
		JSValue ret=JS_NewFloat64(ctx,((double)rollingImpulse));
		return ret;
	}
	
	static JSValue js_b2Manifold_set_rollingImpulse(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].rollingImpulse=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Manifold_points_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2Manifold * ptr=(b2Manifold  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<2;i++){
			b2ManifoldPoint * src0=(ptr[0].points+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2ManifoldPoint_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2Manifold_points_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2Manifold * ptr=(b2Manifold  *)ptr_u;
		int length=(int)2;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2Manifold_points_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2Manifold * ptr=(b2Manifold  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)2));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<2){
				b2ManifoldPoint * src=(ptr[0].points+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2ManifoldPoint_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2Manifold_points_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2Manifold * ptr=(b2Manifold  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<2){
				bool error=(bool)0;
				local_memlock=true;
				b2ManifoldPoint ret=js_getb2ManifoldPoint(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].points[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2Manifold_points_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2Manifold * ptr=(b2Manifold  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<2){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2Manifold_get_points(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2Manifold_points_values,.keys = js_b2Manifold_points_keys,.get = js_b2Manifold_points_get,.set = js_b2Manifold_points_set,.has = js_b2Manifold_points_has});
		return ret;
	}
	
	static JSValue js_b2Manifold_set_points(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		local_memlock=true;
		b2ManifoldPoint * value=js_getb2ManifoldPoint_arr2nc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		memcpy((void  *)ptr[0].points,(const void  *)value,2*sizeof(b2ManifoldPoint));
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Manifold_get_pointCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		int pointCount=ptr[0].pointCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)pointCount));
		return ret;
	}
	
	static JSValue js_b2Manifold_set_pointCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Manifold_class_id);
		b2Manifold * ptr=(b2Manifold  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].pointCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Manifold_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Manifold", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("normal",js_b2Manifold_get_normal,js_b2Manifold_set_normal),
		JS_CGETSET_DEF("rollingImpulse",js_b2Manifold_get_rollingImpulse,js_b2Manifold_set_rollingImpulse),
		JS_CGETSET_DEF("points",js_b2Manifold_get_points,js_b2Manifold_set_points),
		JS_CGETSET_DEF("pointCount",js_b2Manifold_get_pointCount,js_b2Manifold_set_pointCount)
	};
	
	static int js_declare_b2Manifold(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Manifold_class_id);
		JSClassDef js_b2Manifold_def={ .class_name = "b2Manifold", .finalizer = js_b2Manifold_finalizer };
		JS_NewClass(rt,js_b2Manifold_class_id,(const JSClassDef  *)&js_b2Manifold_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Manifold_proto_funcs,(int)countof(js_b2Manifold_proto_funcs));
		JS_SetClassProto(ctx,js_b2Manifold_class_id,proto);
		return 0;
	}
	
	static void js_b2TreeStats_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2TreeStats_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2TreeStats_get_nodeVisits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TreeStats_class_id);
		b2TreeStats * ptr=(b2TreeStats  *)shadow[0].ptr;
		int nodeVisits=ptr[0].nodeVisits;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)nodeVisits));
		return ret;
	}
	
	static JSValue js_b2TreeStats_set_nodeVisits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TreeStats_class_id);
		b2TreeStats * ptr=(b2TreeStats  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].nodeVisits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2TreeStats_get_leafVisits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TreeStats_class_id);
		b2TreeStats * ptr=(b2TreeStats  *)shadow[0].ptr;
		int leafVisits=ptr[0].leafVisits;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)leafVisits));
		return ret;
	}
	
	static JSValue js_b2TreeStats_set_leafVisits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2TreeStats_class_id);
		b2TreeStats * ptr=(b2TreeStats  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].leafVisits=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2TreeStats_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2TreeStats", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("nodeVisits",js_b2TreeStats_get_nodeVisits,js_b2TreeStats_set_nodeVisits),
		JS_CGETSET_DEF("leafVisits",js_b2TreeStats_get_leafVisits,js_b2TreeStats_set_leafVisits)
	};
	
	static int js_declare_b2TreeStats(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2TreeStats_class_id);
		JSClassDef js_b2TreeStats_def={ .class_name = "b2TreeStats", .finalizer = js_b2TreeStats_finalizer };
		JS_NewClass(rt,js_b2TreeStats_class_id,(const JSClassDef  *)&js_b2TreeStats_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2TreeStats_proto_funcs,(int)countof(js_b2TreeStats_proto_funcs));
		JS_SetClassProto(ctx,js_b2TreeStats_class_id,proto);
		return 0;
	}
	
	static void js_b2PlaneResult_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2PlaneResult_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2PlaneResult_get_plane(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Plane * plane=&ptr[0].plane;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)plane,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Plane_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PlaneResult_set_plane(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Plane value=js_getb2Plane(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].plane=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PlaneResult_get_point(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point=&ptr[0].point;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PlaneResult_set_point(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PlaneResult_get_hit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		bool hit=ptr[0].hit;
		JSValue ret=JS_NewBool(ctx,hit);
		return ret;
	}
	
	static JSValue js_b2PlaneResult_set_hit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneResult_class_id);
		b2PlaneResult * ptr=(b2PlaneResult  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hit=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2PlaneResult_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2PlaneResult", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("plane",js_b2PlaneResult_get_plane,js_b2PlaneResult_set_plane),
		JS_CGETSET_DEF("point",js_b2PlaneResult_get_point,js_b2PlaneResult_set_point),
		JS_CGETSET_DEF("hit",js_b2PlaneResult_get_hit,js_b2PlaneResult_set_hit)
	};
	
	static int js_declare_b2PlaneResult(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2PlaneResult_class_id);
		JSClassDef js_b2PlaneResult_def={ .class_name = "b2PlaneResult", .finalizer = js_b2PlaneResult_finalizer };
		JS_NewClass(rt,js_b2PlaneResult_class_id,(const JSClassDef  *)&js_b2PlaneResult_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2PlaneResult_proto_funcs,(int)countof(js_b2PlaneResult_proto_funcs));
		JS_SetClassProto(ctx,js_b2PlaneResult_class_id,proto);
		return 0;
	}
	
	static void js_b2CollisionPlane_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2CollisionPlane_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2CollisionPlane_get_plane(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Plane * plane=&ptr[0].plane;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)plane,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Plane_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CollisionPlane_set_plane(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		local_memlock=true;
		b2Plane value=js_getb2Plane(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].plane=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CollisionPlane_get_pushLimit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		float pushLimit=ptr[0].pushLimit;
		JSValue ret=JS_NewFloat64(ctx,((double)pushLimit));
		return ret;
	}
	
	static JSValue js_b2CollisionPlane_set_pushLimit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].pushLimit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CollisionPlane_get_push(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		float push=ptr[0].push;
		JSValue ret=JS_NewFloat64(ctx,((double)push));
		return ret;
	}
	
	static JSValue js_b2CollisionPlane_set_push(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].push=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CollisionPlane_get_clipVelocity(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		bool clipVelocity=ptr[0].clipVelocity;
		JSValue ret=JS_NewBool(ctx,clipVelocity);
		return ret;
	}
	
	static JSValue js_b2CollisionPlane_set_clipVelocity(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2CollisionPlane_class_id);
		b2CollisionPlane * ptr=(b2CollisionPlane  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].clipVelocity=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2CollisionPlane_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2CollisionPlane", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("plane",js_b2CollisionPlane_get_plane,js_b2CollisionPlane_set_plane),
		JS_CGETSET_DEF("pushLimit",js_b2CollisionPlane_get_pushLimit,js_b2CollisionPlane_set_pushLimit),
		JS_CGETSET_DEF("push",js_b2CollisionPlane_get_push,js_b2CollisionPlane_set_push),
		JS_CGETSET_DEF("clipVelocity",js_b2CollisionPlane_get_clipVelocity,js_b2CollisionPlane_set_clipVelocity)
	};
	
	static int js_declare_b2CollisionPlane(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2CollisionPlane_class_id);
		JSClassDef js_b2CollisionPlane_def={ .class_name = "b2CollisionPlane", .finalizer = js_b2CollisionPlane_finalizer };
		JS_NewClass(rt,js_b2CollisionPlane_class_id,(const JSClassDef  *)&js_b2CollisionPlane_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2CollisionPlane_proto_funcs,(int)countof(js_b2CollisionPlane_proto_funcs));
		JS_SetClassProto(ctx,js_b2CollisionPlane_class_id,proto);
		return 0;
	}
	
	static void js_b2PlaneSolverResult_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2PlaneSolverResult_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2PlaneSolverResult_get_translation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneSolverResult_class_id);
		b2PlaneSolverResult * ptr=(b2PlaneSolverResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * translation=&ptr[0].translation;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)translation,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PlaneSolverResult_set_translation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneSolverResult_class_id);
		b2PlaneSolverResult * ptr=(b2PlaneSolverResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].translation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PlaneSolverResult_get_iterationCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneSolverResult_class_id);
		b2PlaneSolverResult * ptr=(b2PlaneSolverResult  *)shadow[0].ptr;
		int iterationCount=ptr[0].iterationCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)iterationCount));
		return ret;
	}
	
	static JSValue js_b2PlaneSolverResult_set_iterationCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PlaneSolverResult_class_id);
		b2PlaneSolverResult * ptr=(b2PlaneSolverResult  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].iterationCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2PlaneSolverResult_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2PlaneSolverResult", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("translation",js_b2PlaneSolverResult_get_translation,js_b2PlaneSolverResult_set_translation),
		JS_CGETSET_DEF("iterationCount",js_b2PlaneSolverResult_get_iterationCount,js_b2PlaneSolverResult_set_iterationCount)
	};
	
	static int js_declare_b2PlaneSolverResult(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2PlaneSolverResult_class_id);
		JSClassDef js_b2PlaneSolverResult_def={ .class_name = "b2PlaneSolverResult", .finalizer = js_b2PlaneSolverResult_finalizer };
		JS_NewClass(rt,js_b2PlaneSolverResult_class_id,(const JSClassDef  *)&js_b2PlaneSolverResult_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2PlaneSolverResult_proto_funcs,(int)countof(js_b2PlaneSolverResult_proto_funcs));
		JS_SetClassProto(ctx,js_b2PlaneSolverResult_class_id,proto);
		return 0;
	}
	
	static void js_b2WorldId_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2WorldId_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2WorldId_get_index1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldId_class_id);
		b2WorldId * ptr=(b2WorldId  *)shadow[0].ptr;
		uint16_t index1=ptr[0].index1;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)index1));
		return ret;
	}
	
	static JSValue js_b2WorldId_set_index1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldId_class_id);
		b2WorldId * ptr=(b2WorldId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].index1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldId_get_generation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldId_class_id);
		b2WorldId * ptr=(b2WorldId  *)shadow[0].ptr;
		uint16_t generation=ptr[0].generation;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)generation));
		return ret;
	}
	
	static JSValue js_b2WorldId_set_generation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldId_class_id);
		b2WorldId * ptr=(b2WorldId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].generation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2WorldId_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2WorldId", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("index1",js_b2WorldId_get_index1,js_b2WorldId_set_index1),
		JS_CGETSET_DEF("generation",js_b2WorldId_get_generation,js_b2WorldId_set_generation)
	};
	
	static int js_declare_b2WorldId(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2WorldId_class_id);
		JSClassDef js_b2WorldId_def={ .class_name = "b2WorldId", .finalizer = js_b2WorldId_finalizer };
		JS_NewClass(rt,js_b2WorldId_class_id,(const JSClassDef  *)&js_b2WorldId_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2WorldId_proto_funcs,(int)countof(js_b2WorldId_proto_funcs));
		JS_SetClassProto(ctx,js_b2WorldId_class_id,proto);
		return 0;
	}
	
	static void js_b2BodyId_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2BodyId_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2BodyId_get_index1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		int32_t index1=ptr[0].index1;
		JSValue ret=JS_NewInt32(ctx,index1);
		return ret;
	}
	
	static JSValue js_b2BodyId_set_index1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		local_memlock=true;
		int32_t value=js_getint32_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].index1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyId_get_world0(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		uint16_t world0=ptr[0].world0;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)world0));
		return ret;
	}
	
	static JSValue js_b2BodyId_set_world0(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].world0=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyId_get_generation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		uint16_t generation=ptr[0].generation;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)generation));
		return ret;
	}
	
	static JSValue js_b2BodyId_set_generation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyId_class_id);
		b2BodyId * ptr=(b2BodyId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].generation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2BodyId_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2BodyId", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("index1",js_b2BodyId_get_index1,js_b2BodyId_set_index1),
		JS_CGETSET_DEF("world0",js_b2BodyId_get_world0,js_b2BodyId_set_world0),
		JS_CGETSET_DEF("generation",js_b2BodyId_get_generation,js_b2BodyId_set_generation)
	};
	
	static int js_declare_b2BodyId(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2BodyId_class_id);
		JSClassDef js_b2BodyId_def={ .class_name = "b2BodyId", .finalizer = js_b2BodyId_finalizer };
		JS_NewClass(rt,js_b2BodyId_class_id,(const JSClassDef  *)&js_b2BodyId_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2BodyId_proto_funcs,(int)countof(js_b2BodyId_proto_funcs));
		JS_SetClassProto(ctx,js_b2BodyId_class_id,proto);
		return 0;
	}
	
	static void js_b2ShapeId_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ShapeId_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ShapeId_get_index1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		int32_t index1=ptr[0].index1;
		JSValue ret=JS_NewInt32(ctx,index1);
		return ret;
	}
	
	static JSValue js_b2ShapeId_set_index1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		local_memlock=true;
		int32_t value=js_getint32_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].index1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeId_get_world0(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		uint16_t world0=ptr[0].world0;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)world0));
		return ret;
	}
	
	static JSValue js_b2ShapeId_set_world0(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].world0=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeId_get_generation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		uint16_t generation=ptr[0].generation;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)generation));
		return ret;
	}
	
	static JSValue js_b2ShapeId_set_generation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeId_class_id);
		b2ShapeId * ptr=(b2ShapeId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].generation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ShapeId_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ShapeId", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("index1",js_b2ShapeId_get_index1,js_b2ShapeId_set_index1),
		JS_CGETSET_DEF("world0",js_b2ShapeId_get_world0,js_b2ShapeId_set_world0),
		JS_CGETSET_DEF("generation",js_b2ShapeId_get_generation,js_b2ShapeId_set_generation)
	};
	
	static int js_declare_b2ShapeId(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ShapeId_class_id);
		JSClassDef js_b2ShapeId_def={ .class_name = "b2ShapeId", .finalizer = js_b2ShapeId_finalizer };
		JS_NewClass(rt,js_b2ShapeId_class_id,(const JSClassDef  *)&js_b2ShapeId_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ShapeId_proto_funcs,(int)countof(js_b2ShapeId_proto_funcs));
		JS_SetClassProto(ctx,js_b2ShapeId_class_id,proto);
		return 0;
	}
	
	static void js_b2ChainId_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ChainId_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ChainId_get_index1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		int32_t index1=ptr[0].index1;
		JSValue ret=JS_NewInt32(ctx,index1);
		return ret;
	}
	
	static JSValue js_b2ChainId_set_index1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		local_memlock=true;
		int32_t value=js_getint32_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].index1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainId_get_world0(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		uint16_t world0=ptr[0].world0;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)world0));
		return ret;
	}
	
	static JSValue js_b2ChainId_set_world0(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].world0=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainId_get_generation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		uint16_t generation=ptr[0].generation;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)generation));
		return ret;
	}
	
	static JSValue js_b2ChainId_set_generation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainId_class_id);
		b2ChainId * ptr=(b2ChainId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].generation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ChainId_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ChainId", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("index1",js_b2ChainId_get_index1,js_b2ChainId_set_index1),
		JS_CGETSET_DEF("world0",js_b2ChainId_get_world0,js_b2ChainId_set_world0),
		JS_CGETSET_DEF("generation",js_b2ChainId_get_generation,js_b2ChainId_set_generation)
	};
	
	static int js_declare_b2ChainId(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ChainId_class_id);
		JSClassDef js_b2ChainId_def={ .class_name = "b2ChainId", .finalizer = js_b2ChainId_finalizer };
		JS_NewClass(rt,js_b2ChainId_class_id,(const JSClassDef  *)&js_b2ChainId_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ChainId_proto_funcs,(int)countof(js_b2ChainId_proto_funcs));
		JS_SetClassProto(ctx,js_b2ChainId_class_id,proto);
		return 0;
	}
	
	static void js_b2JointId_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2JointId_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2JointId_get_index1(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		int32_t index1=ptr[0].index1;
		JSValue ret=JS_NewInt32(ctx,index1);
		return ret;
	}
	
	static JSValue js_b2JointId_set_index1(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		local_memlock=true;
		int32_t value=js_getint32_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].index1=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2JointId_get_world0(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		uint16_t world0=ptr[0].world0;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)world0));
		return ret;
	}
	
	static JSValue js_b2JointId_set_world0(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].world0=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2JointId_get_generation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		uint16_t generation=ptr[0].generation;
		JSValue ret=JS_NewUint32(ctx,(uint32_t)((unsigned long)generation));
		return ret;
	}
	
	static JSValue js_b2JointId_set_generation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2JointId_class_id);
		b2JointId * ptr=(b2JointId  *)shadow[0].ptr;
		local_memlock=true;
		uint16_t value=js_getuint16_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].generation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2JointId_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2JointId", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("index1",js_b2JointId_get_index1,js_b2JointId_set_index1),
		JS_CGETSET_DEF("world0",js_b2JointId_get_world0,js_b2JointId_set_world0),
		JS_CGETSET_DEF("generation",js_b2JointId_get_generation,js_b2JointId_set_generation)
	};
	
	static int js_declare_b2JointId(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2JointId_class_id);
		JSClassDef js_b2JointId_def={ .class_name = "b2JointId", .finalizer = js_b2JointId_finalizer };
		JS_NewClass(rt,js_b2JointId_class_id,(const JSClassDef  *)&js_b2JointId_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2JointId_proto_funcs,(int)countof(js_b2JointId_proto_funcs));
		JS_SetClassProto(ctx,js_b2JointId_class_id,proto);
		return 0;
	}
	
	static void js_b2RayResult_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2RayResult_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2RayResult_get_shapeId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeId=&ptr[0].shapeId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RayResult_set_shapeId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeId=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_point(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point=&ptr[0].point;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RayResult_set_point(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RayResult_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_fraction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		float fraction=ptr[0].fraction;
		JSValue ret=JS_NewFloat64(ctx,((double)fraction));
		return ret;
	}
	
	static JSValue js_b2RayResult_set_fraction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fraction=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_nodeVisits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		int nodeVisits=ptr[0].nodeVisits;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)nodeVisits));
		return ret;
	}
	
	static JSValue js_b2RayResult_set_nodeVisits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].nodeVisits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_leafVisits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		int leafVisits=ptr[0].leafVisits;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)leafVisits));
		return ret;
	}
	
	static JSValue js_b2RayResult_set_leafVisits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].leafVisits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RayResult_get_hit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		bool hit=ptr[0].hit;
		JSValue ret=JS_NewBool(ctx,hit);
		return ret;
	}
	
	static JSValue js_b2RayResult_set_hit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RayResult_class_id);
		b2RayResult * ptr=(b2RayResult  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hit=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2RayResult_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2RayResult", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("shapeId",js_b2RayResult_get_shapeId,js_b2RayResult_set_shapeId),
		JS_CGETSET_DEF("point",js_b2RayResult_get_point,js_b2RayResult_set_point),
		JS_CGETSET_DEF("normal",js_b2RayResult_get_normal,js_b2RayResult_set_normal),
		JS_CGETSET_DEF("fraction",js_b2RayResult_get_fraction,js_b2RayResult_set_fraction),
		JS_CGETSET_DEF("nodeVisits",js_b2RayResult_get_nodeVisits,js_b2RayResult_set_nodeVisits),
		JS_CGETSET_DEF("leafVisits",js_b2RayResult_get_leafVisits,js_b2RayResult_set_leafVisits),
		JS_CGETSET_DEF("hit",js_b2RayResult_get_hit,js_b2RayResult_set_hit)
	};
	
	static int js_declare_b2RayResult(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2RayResult_class_id);
		JSClassDef js_b2RayResult_def={ .class_name = "b2RayResult", .finalizer = js_b2RayResult_finalizer };
		JS_NewClass(rt,js_b2RayResult_class_id,(const JSClassDef  *)&js_b2RayResult_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2RayResult_proto_funcs,(int)countof(js_b2RayResult_proto_funcs));
		JS_SetClassProto(ctx,js_b2RayResult_class_id,proto);
		return 0;
	}
	
	static void js_b2WorldDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2WorldDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2WorldDef_get_gravity(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * gravity=&ptr[0].gravity;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)gravity,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_gravity(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].gravity=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_restitutionThreshold(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float restitutionThreshold=ptr[0].restitutionThreshold;
		JSValue ret=JS_NewFloat64(ctx,((double)restitutionThreshold));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_restitutionThreshold(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].restitutionThreshold=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_hitEventThreshold(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float hitEventThreshold=ptr[0].hitEventThreshold;
		JSValue ret=JS_NewFloat64(ctx,((double)hitEventThreshold));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_hitEventThreshold(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hitEventThreshold=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_contactHertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float contactHertz=ptr[0].contactHertz;
		JSValue ret=JS_NewFloat64(ctx,((double)contactHertz));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_contactHertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].contactHertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_contactDampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float contactDampingRatio=ptr[0].contactDampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)contactDampingRatio));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_contactDampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].contactDampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_maxContactPushSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float maxContactPushSpeed=ptr[0].maxContactPushSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)maxContactPushSpeed));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_maxContactPushSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxContactPushSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_maximumLinearSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		float maximumLinearSpeed=ptr[0].maximumLinearSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)maximumLinearSpeed));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_maximumLinearSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maximumLinearSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_enableSleep(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		bool enableSleep=ptr[0].enableSleep;
		JSValue ret=JS_NewBool(ctx,enableSleep);
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_enableSleep(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSleep=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_enableContinuous(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		bool enableContinuous=ptr[0].enableContinuous;
		JSValue ret=JS_NewBool(ctx,enableContinuous);
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_enableContinuous(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableContinuous=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WorldDef_get_workerCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		int workerCount=ptr[0].workerCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)workerCount));
		return ret;
	}
	
	static JSValue js_b2WorldDef_set_workerCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WorldDef_class_id);
		b2WorldDef * ptr=(b2WorldDef  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].workerCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2WorldDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2WorldDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("gravity",js_b2WorldDef_get_gravity,js_b2WorldDef_set_gravity),
		JS_CGETSET_DEF("restitutionThreshold",js_b2WorldDef_get_restitutionThreshold,js_b2WorldDef_set_restitutionThreshold),
		JS_CGETSET_DEF("hitEventThreshold",js_b2WorldDef_get_hitEventThreshold,js_b2WorldDef_set_hitEventThreshold),
		JS_CGETSET_DEF("contactHertz",js_b2WorldDef_get_contactHertz,js_b2WorldDef_set_contactHertz),
		JS_CGETSET_DEF("contactDampingRatio",js_b2WorldDef_get_contactDampingRatio,js_b2WorldDef_set_contactDampingRatio),
		JS_CGETSET_DEF("maxContactPushSpeed",js_b2WorldDef_get_maxContactPushSpeed,js_b2WorldDef_set_maxContactPushSpeed),
		JS_CGETSET_DEF("maximumLinearSpeed",js_b2WorldDef_get_maximumLinearSpeed,js_b2WorldDef_set_maximumLinearSpeed),
		JS_CGETSET_DEF("frictionCallback",NULL,NULL),
		JS_CGETSET_DEF("restitutionCallback",NULL,NULL),
		JS_CGETSET_DEF("enableSleep",js_b2WorldDef_get_enableSleep,js_b2WorldDef_set_enableSleep),
		JS_CGETSET_DEF("enableContinuous",js_b2WorldDef_get_enableContinuous,js_b2WorldDef_set_enableContinuous),
		JS_CGETSET_DEF("workerCount",js_b2WorldDef_get_workerCount,js_b2WorldDef_set_workerCount),
		JS_CGETSET_DEF("enqueueTask",NULL,NULL),
		JS_CGETSET_DEF("finishTask",NULL,NULL),
		JS_CGETSET_DEF("userTaskContext",NULL,NULL),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2WorldDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2WorldDef_class_id);
		JSClassDef js_b2WorldDef_def={ .class_name = "b2WorldDef", .finalizer = js_b2WorldDef_finalizer };
		JS_NewClass(rt,js_b2WorldDef_class_id,(const JSClassDef  *)&js_b2WorldDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2WorldDef_proto_funcs,(int)countof(js_b2WorldDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2WorldDef_class_id,proto);
		return 0;
	}
	
	static void js_b2BodyDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2BodyDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2BodyDef_get_type(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		b2BodyType type=ptr[0].type;
		JSValue ret=JS_NewInt32(ctx,(int32_t)type);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_type(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyType value=js_getb2BodyType(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].type=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_position(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * position=&ptr[0].position;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)position,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_position(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].position=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_rotation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Rot * rotation=&ptr[0].rotation;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)rotation,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_rotation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Rot value=js_getb2Rot(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].rotation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_linearVelocity(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * linearVelocity=&ptr[0].linearVelocity;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)linearVelocity,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_linearVelocity(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].linearVelocity=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_angularVelocity(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		float angularVelocity=ptr[0].angularVelocity;
		JSValue ret=JS_NewFloat64(ctx,((double)angularVelocity));
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_angularVelocity(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].angularVelocity=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_linearDamping(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		float linearDamping=ptr[0].linearDamping;
		JSValue ret=JS_NewFloat64(ctx,((double)linearDamping));
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_linearDamping(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].linearDamping=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_angularDamping(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		float angularDamping=ptr[0].angularDamping;
		JSValue ret=JS_NewFloat64(ctx,((double)angularDamping));
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_angularDamping(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].angularDamping=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_gravityScale(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		float gravityScale=ptr[0].gravityScale;
		JSValue ret=JS_NewFloat64(ctx,((double)gravityScale));
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_gravityScale(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].gravityScale=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_sleepThreshold(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		float sleepThreshold=ptr[0].sleepThreshold;
		JSValue ret=JS_NewFloat64(ctx,((double)sleepThreshold));
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_sleepThreshold(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sleepThreshold=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_name(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		const char * name=ptr[0].name;
		JSValue ret=JS_NewString(ctx,name);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_name(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		char * value=js_getchar_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].name!=NULL)jsc_free(ctx,(void  *)ptr[0].name);
		ptr[0].name =(const char  *)value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_enableSleep(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool enableSleep=ptr[0].enableSleep;
		JSValue ret=JS_NewBool(ctx,enableSleep);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_enableSleep(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSleep=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_isAwake(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool isAwake=ptr[0].isAwake;
		JSValue ret=JS_NewBool(ctx,isAwake);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_isAwake(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].isAwake=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_fixedRotation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool fixedRotation=ptr[0].fixedRotation;
		JSValue ret=JS_NewBool(ctx,fixedRotation);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_fixedRotation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fixedRotation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_isBullet(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool isBullet=ptr[0].isBullet;
		JSValue ret=JS_NewBool(ctx,isBullet);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_isBullet(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].isBullet=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_isEnabled(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool isEnabled=ptr[0].isEnabled;
		JSValue ret=JS_NewBool(ctx,isEnabled);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_isEnabled(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].isEnabled=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyDef_get_allowFastRotation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		bool allowFastRotation=ptr[0].allowFastRotation;
		JSValue ret=JS_NewBool(ctx,allowFastRotation);
		return ret;
	}
	
	static JSValue js_b2BodyDef_set_allowFastRotation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyDef_class_id);
		b2BodyDef * ptr=(b2BodyDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].allowFastRotation=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2BodyDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2BodyDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("type",js_b2BodyDef_get_type,js_b2BodyDef_set_type),
		JS_CGETSET_DEF("position",js_b2BodyDef_get_position,js_b2BodyDef_set_position),
		JS_CGETSET_DEF("rotation",js_b2BodyDef_get_rotation,js_b2BodyDef_set_rotation),
		JS_CGETSET_DEF("linearVelocity",js_b2BodyDef_get_linearVelocity,js_b2BodyDef_set_linearVelocity),
		JS_CGETSET_DEF("angularVelocity",js_b2BodyDef_get_angularVelocity,js_b2BodyDef_set_angularVelocity),
		JS_CGETSET_DEF("linearDamping",js_b2BodyDef_get_linearDamping,js_b2BodyDef_set_linearDamping),
		JS_CGETSET_DEF("angularDamping",js_b2BodyDef_get_angularDamping,js_b2BodyDef_set_angularDamping),
		JS_CGETSET_DEF("gravityScale",js_b2BodyDef_get_gravityScale,js_b2BodyDef_set_gravityScale),
		JS_CGETSET_DEF("sleepThreshold",js_b2BodyDef_get_sleepThreshold,js_b2BodyDef_set_sleepThreshold),
		JS_CGETSET_DEF("name",js_b2BodyDef_get_name,js_b2BodyDef_set_name),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("enableSleep",js_b2BodyDef_get_enableSleep,js_b2BodyDef_set_enableSleep),
		JS_CGETSET_DEF("isAwake",js_b2BodyDef_get_isAwake,js_b2BodyDef_set_isAwake),
		JS_CGETSET_DEF("fixedRotation",js_b2BodyDef_get_fixedRotation,js_b2BodyDef_set_fixedRotation),
		JS_CGETSET_DEF("isBullet",js_b2BodyDef_get_isBullet,js_b2BodyDef_set_isBullet),
		JS_CGETSET_DEF("isEnabled",js_b2BodyDef_get_isEnabled,js_b2BodyDef_set_isEnabled),
		JS_CGETSET_DEF("allowFastRotation",js_b2BodyDef_get_allowFastRotation,js_b2BodyDef_set_allowFastRotation),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2BodyDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2BodyDef_class_id);
		JSClassDef js_b2BodyDef_def={ .class_name = "b2BodyDef", .finalizer = js_b2BodyDef_finalizer };
		JS_NewClass(rt,js_b2BodyDef_class_id,(const JSClassDef  *)&js_b2BodyDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2BodyDef_proto_funcs,(int)countof(js_b2BodyDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2BodyDef_class_id,proto);
		return 0;
	}
	
	static void js_b2Filter_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Filter_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Filter_get_categoryBits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		uint64_t categoryBits=ptr[0].categoryBits;
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)categoryBits));
		return ret;
	}
	
	static JSValue js_b2Filter_set_categoryBits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		local_memlock=true;
		uint64_t value=js_getuint64_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].categoryBits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Filter_get_maskBits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		uint64_t maskBits=ptr[0].maskBits;
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)maskBits));
		return ret;
	}
	
	static JSValue js_b2Filter_set_maskBits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		local_memlock=true;
		uint64_t value=js_getuint64_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maskBits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Filter_get_groupIndex(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		int groupIndex=ptr[0].groupIndex;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)groupIndex));
		return ret;
	}
	
	static JSValue js_b2Filter_set_groupIndex(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Filter_class_id);
		b2Filter * ptr=(b2Filter  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].groupIndex=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Filter_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Filter", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("categoryBits",js_b2Filter_get_categoryBits,js_b2Filter_set_categoryBits),
		JS_CGETSET_DEF("maskBits",js_b2Filter_get_maskBits,js_b2Filter_set_maskBits),
		JS_CGETSET_DEF("groupIndex",js_b2Filter_get_groupIndex,js_b2Filter_set_groupIndex)
	};
	
	static int js_declare_b2Filter(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Filter_class_id);
		JSClassDef js_b2Filter_def={ .class_name = "b2Filter", .finalizer = js_b2Filter_finalizer };
		JS_NewClass(rt,js_b2Filter_class_id,(const JSClassDef  *)&js_b2Filter_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Filter_proto_funcs,(int)countof(js_b2Filter_proto_funcs));
		JS_SetClassProto(ctx,js_b2Filter_class_id,proto);
		return 0;
	}
	
	static void js_b2QueryFilter_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2QueryFilter_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2QueryFilter_get_categoryBits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2QueryFilter_class_id);
		b2QueryFilter * ptr=(b2QueryFilter  *)shadow[0].ptr;
		uint64_t categoryBits=ptr[0].categoryBits;
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)categoryBits));
		return ret;
	}
	
	static JSValue js_b2QueryFilter_set_categoryBits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2QueryFilter_class_id);
		b2QueryFilter * ptr=(b2QueryFilter  *)shadow[0].ptr;
		local_memlock=true;
		uint64_t value=js_getuint64_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].categoryBits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2QueryFilter_get_maskBits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2QueryFilter_class_id);
		b2QueryFilter * ptr=(b2QueryFilter  *)shadow[0].ptr;
		uint64_t maskBits=ptr[0].maskBits;
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)maskBits));
		return ret;
	}
	
	static JSValue js_b2QueryFilter_set_maskBits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2QueryFilter_class_id);
		b2QueryFilter * ptr=(b2QueryFilter  *)shadow[0].ptr;
		local_memlock=true;
		uint64_t value=js_getuint64_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maskBits=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2QueryFilter_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2QueryFilter", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("categoryBits",js_b2QueryFilter_get_categoryBits,js_b2QueryFilter_set_categoryBits),
		JS_CGETSET_DEF("maskBits",js_b2QueryFilter_get_maskBits,js_b2QueryFilter_set_maskBits)
	};
	
	static int js_declare_b2QueryFilter(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2QueryFilter_class_id);
		JSClassDef js_b2QueryFilter_def={ .class_name = "b2QueryFilter", .finalizer = js_b2QueryFilter_finalizer };
		JS_NewClass(rt,js_b2QueryFilter_class_id,(const JSClassDef  *)&js_b2QueryFilter_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2QueryFilter_proto_funcs,(int)countof(js_b2QueryFilter_proto_funcs));
		JS_SetClassProto(ctx,js_b2QueryFilter_class_id,proto);
		return 0;
	}
	
	static void js_b2SurfaceMaterial_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SurfaceMaterial_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SurfaceMaterial_get_friction(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		float friction=ptr[0].friction;
		JSValue ret=JS_NewFloat64(ctx,((double)friction));
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_friction(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].friction=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SurfaceMaterial_get_restitution(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		float restitution=ptr[0].restitution;
		JSValue ret=JS_NewFloat64(ctx,((double)restitution));
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_restitution(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].restitution=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SurfaceMaterial_get_rollingResistance(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		float rollingResistance=ptr[0].rollingResistance;
		JSValue ret=JS_NewFloat64(ctx,((double)rollingResistance));
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_rollingResistance(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].rollingResistance=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SurfaceMaterial_get_tangentSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		float tangentSpeed=ptr[0].tangentSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)tangentSpeed));
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_tangentSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].tangentSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SurfaceMaterial_get_userMaterialId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		int userMaterialId=ptr[0].userMaterialId;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)userMaterialId));
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_userMaterialId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].userMaterialId=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SurfaceMaterial_get_customColor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		uint32_t customColor=ptr[0].customColor;
		JSValue ret=JS_NewUint32(ctx,customColor);
		return ret;
	}
	
	static JSValue js_b2SurfaceMaterial_set_customColor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SurfaceMaterial_class_id);
		b2SurfaceMaterial * ptr=(b2SurfaceMaterial  *)shadow[0].ptr;
		local_memlock=true;
		uint32_t value=js_getuint32_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].customColor=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SurfaceMaterial_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SurfaceMaterial", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("friction",js_b2SurfaceMaterial_get_friction,js_b2SurfaceMaterial_set_friction),
		JS_CGETSET_DEF("restitution",js_b2SurfaceMaterial_get_restitution,js_b2SurfaceMaterial_set_restitution),
		JS_CGETSET_DEF("rollingResistance",js_b2SurfaceMaterial_get_rollingResistance,js_b2SurfaceMaterial_set_rollingResistance),
		JS_CGETSET_DEF("tangentSpeed",js_b2SurfaceMaterial_get_tangentSpeed,js_b2SurfaceMaterial_set_tangentSpeed),
		JS_CGETSET_DEF("userMaterialId",js_b2SurfaceMaterial_get_userMaterialId,js_b2SurfaceMaterial_set_userMaterialId),
		JS_CGETSET_DEF("customColor",js_b2SurfaceMaterial_get_customColor,js_b2SurfaceMaterial_set_customColor)
	};
	
	static int js_declare_b2SurfaceMaterial(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SurfaceMaterial_class_id);
		JSClassDef js_b2SurfaceMaterial_def={ .class_name = "b2SurfaceMaterial", .finalizer = js_b2SurfaceMaterial_finalizer };
		JS_NewClass(rt,js_b2SurfaceMaterial_class_id,(const JSClassDef  *)&js_b2SurfaceMaterial_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SurfaceMaterial_proto_funcs,(int)countof(js_b2SurfaceMaterial_proto_funcs));
		JS_SetClassProto(ctx,js_b2SurfaceMaterial_class_id,proto);
		return 0;
	}
	
	static void js_b2ShapeDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ShapeDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ShapeDef_get_material(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2SurfaceMaterial * material=&ptr[0].material;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)material,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_material(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		b2SurfaceMaterial value=js_getb2SurfaceMaterial(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].material=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_density(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		float density=ptr[0].density;
		JSValue ret=JS_NewFloat64(ctx,((double)density));
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_density(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].density=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_filter(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Filter * filter=&ptr[0].filter;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)filter,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Filter_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_filter(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Filter value=js_getb2Filter(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].filter=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_isSensor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool isSensor=ptr[0].isSensor;
		JSValue ret=JS_NewBool(ctx,isSensor);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_isSensor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].isSensor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_enableSensorEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool enableSensorEvents=ptr[0].enableSensorEvents;
		JSValue ret=JS_NewBool(ctx,enableSensorEvents);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_enableSensorEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSensorEvents=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_enableContactEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool enableContactEvents=ptr[0].enableContactEvents;
		JSValue ret=JS_NewBool(ctx,enableContactEvents);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_enableContactEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableContactEvents=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_enableHitEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool enableHitEvents=ptr[0].enableHitEvents;
		JSValue ret=JS_NewBool(ctx,enableHitEvents);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_enableHitEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableHitEvents=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_enablePreSolveEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool enablePreSolveEvents=ptr[0].enablePreSolveEvents;
		JSValue ret=JS_NewBool(ctx,enablePreSolveEvents);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_enablePreSolveEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enablePreSolveEvents=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_invokeContactCreation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool invokeContactCreation=ptr[0].invokeContactCreation;
		JSValue ret=JS_NewBool(ctx,invokeContactCreation);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_invokeContactCreation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].invokeContactCreation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ShapeDef_get_updateBodyMass(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		bool updateBodyMass=ptr[0].updateBodyMass;
		JSValue ret=JS_NewBool(ctx,updateBodyMass);
		return ret;
	}
	
	static JSValue js_b2ShapeDef_set_updateBodyMass(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ShapeDef_class_id);
		b2ShapeDef * ptr=(b2ShapeDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].updateBodyMass=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ShapeDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ShapeDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("material",js_b2ShapeDef_get_material,js_b2ShapeDef_set_material),
		JS_CGETSET_DEF("density",js_b2ShapeDef_get_density,js_b2ShapeDef_set_density),
		JS_CGETSET_DEF("filter",js_b2ShapeDef_get_filter,js_b2ShapeDef_set_filter),
		JS_CGETSET_DEF("isSensor",js_b2ShapeDef_get_isSensor,js_b2ShapeDef_set_isSensor),
		JS_CGETSET_DEF("enableSensorEvents",js_b2ShapeDef_get_enableSensorEvents,js_b2ShapeDef_set_enableSensorEvents),
		JS_CGETSET_DEF("enableContactEvents",js_b2ShapeDef_get_enableContactEvents,js_b2ShapeDef_set_enableContactEvents),
		JS_CGETSET_DEF("enableHitEvents",js_b2ShapeDef_get_enableHitEvents,js_b2ShapeDef_set_enableHitEvents),
		JS_CGETSET_DEF("enablePreSolveEvents",js_b2ShapeDef_get_enablePreSolveEvents,js_b2ShapeDef_set_enablePreSolveEvents),
		JS_CGETSET_DEF("invokeContactCreation",js_b2ShapeDef_get_invokeContactCreation,js_b2ShapeDef_set_invokeContactCreation),
		JS_CGETSET_DEF("updateBodyMass",js_b2ShapeDef_get_updateBodyMass,js_b2ShapeDef_set_updateBodyMass),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2ShapeDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ShapeDef_class_id);
		JSClassDef js_b2ShapeDef_def={ .class_name = "b2ShapeDef", .finalizer = js_b2ShapeDef_finalizer };
		JS_NewClass(rt,js_b2ShapeDef_class_id,(const JSClassDef  *)&js_b2ShapeDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ShapeDef_proto_funcs,(int)countof(js_b2ShapeDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2ShapeDef_class_id,proto);
		return 0;
	}
	
	static void js_b2ChainDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ChainDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ChainDef_points_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].count;i++){
			b2Vec2 * src0=(b2Vec2  *)(ptr[0].points+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2ChainDef_points_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		int length=ptr[0].count;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2ChainDef_points_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].count));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].count){
				const b2Vec2 src=ptr[0].points[property];
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)&src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2ChainDef_points_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		return false;
	}
	
	static int js_b2ChainDef_points_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].count){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2ChainDef_get_points(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2ChainDef_points_values,.keys = js_b2ChainDef_points_keys,.get = js_b2ChainDef_points_get,.set = js_b2ChainDef_points_set,.has = js_b2ChainDef_points_has});
		return ret;
	}
	
	static JSValue js_b2ChainDef_get_count(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		int count=ptr[0].count;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)count));
		return ret;
	}
	
	static JSValue js_b2ChainDef_set_count(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].count=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainDef_materials_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].materialCount;i++){
			b2SurfaceMaterial * src0=(b2SurfaceMaterial  *)(ptr[0].materials+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2ChainDef_materials_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		int length=ptr[0].materialCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2ChainDef_materials_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].materialCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].materialCount){
				const b2SurfaceMaterial src=ptr[0].materials[property];
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)&src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2ChainDef_materials_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		return false;
	}
	
	static int js_b2ChainDef_materials_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2ChainDef * ptr=(b2ChainDef  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].materialCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2ChainDef_get_materials(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2ChainDef_materials_values,.keys = js_b2ChainDef_materials_keys,.get = js_b2ChainDef_materials_get,.set = js_b2ChainDef_materials_set,.has = js_b2ChainDef_materials_has});
		return ret;
	}
	
	static JSValue js_b2ChainDef_get_materialCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		int materialCount=ptr[0].materialCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)materialCount));
		return ret;
	}
	
	static JSValue js_b2ChainDef_set_materialCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].materialCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainDef_get_filter(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Filter * filter=&ptr[0].filter;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)filter,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Filter_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ChainDef_set_filter(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Filter value=js_getb2Filter(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].filter=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainDef_get_isLoop(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		bool isLoop=ptr[0].isLoop;
		JSValue ret=JS_NewBool(ctx,isLoop);
		return ret;
	}
	
	static JSValue js_b2ChainDef_set_isLoop(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].isLoop=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ChainDef_get_enableSensorEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		bool enableSensorEvents=ptr[0].enableSensorEvents;
		JSValue ret=JS_NewBool(ctx,enableSensorEvents);
		return ret;
	}
	
	static JSValue js_b2ChainDef_set_enableSensorEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ChainDef_class_id);
		b2ChainDef * ptr=(b2ChainDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSensorEvents=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ChainDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ChainDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("points",js_b2ChainDef_get_points,NULL),
		JS_CGETSET_DEF("count",js_b2ChainDef_get_count,js_b2ChainDef_set_count),
		JS_CGETSET_DEF("materials",js_b2ChainDef_get_materials,NULL),
		JS_CGETSET_DEF("materialCount",js_b2ChainDef_get_materialCount,js_b2ChainDef_set_materialCount),
		JS_CGETSET_DEF("filter",js_b2ChainDef_get_filter,js_b2ChainDef_set_filter),
		JS_CGETSET_DEF("isLoop",js_b2ChainDef_get_isLoop,js_b2ChainDef_set_isLoop),
		JS_CGETSET_DEF("enableSensorEvents",js_b2ChainDef_get_enableSensorEvents,js_b2ChainDef_set_enableSensorEvents),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2ChainDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ChainDef_class_id);
		JSClassDef js_b2ChainDef_def={ .class_name = "b2ChainDef", .finalizer = js_b2ChainDef_finalizer };
		JS_NewClass(rt,js_b2ChainDef_class_id,(const JSClassDef  *)&js_b2ChainDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ChainDef_proto_funcs,(int)countof(js_b2ChainDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2ChainDef_class_id,proto);
		return 0;
	}
	
	static void js_b2Profile_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Profile_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Profile_get_step(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float step=ptr[0].step;
		JSValue ret=JS_NewFloat64(ctx,((double)step));
		return ret;
	}
	
	static JSValue js_b2Profile_set_step(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].step=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_pairs(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float pairs=ptr[0].pairs;
		JSValue ret=JS_NewFloat64(ctx,((double)pairs));
		return ret;
	}
	
	static JSValue js_b2Profile_set_pairs(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].pairs=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_collide(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float collide=ptr[0].collide;
		JSValue ret=JS_NewFloat64(ctx,((double)collide));
		return ret;
	}
	
	static JSValue js_b2Profile_set_collide(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collide=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_solve(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float solve=ptr[0].solve;
		JSValue ret=JS_NewFloat64(ctx,((double)solve));
		return ret;
	}
	
	static JSValue js_b2Profile_set_solve(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].solve=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_mergeIslands(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float mergeIslands=ptr[0].mergeIslands;
		JSValue ret=JS_NewFloat64(ctx,((double)mergeIslands));
		return ret;
	}
	
	static JSValue js_b2Profile_set_mergeIslands(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].mergeIslands=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_prepareStages(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float prepareStages=ptr[0].prepareStages;
		JSValue ret=JS_NewFloat64(ctx,((double)prepareStages));
		return ret;
	}
	
	static JSValue js_b2Profile_set_prepareStages(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].prepareStages=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_solveConstraints(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float solveConstraints=ptr[0].solveConstraints;
		JSValue ret=JS_NewFloat64(ctx,((double)solveConstraints));
		return ret;
	}
	
	static JSValue js_b2Profile_set_solveConstraints(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].solveConstraints=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_prepareConstraints(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float prepareConstraints=ptr[0].prepareConstraints;
		JSValue ret=JS_NewFloat64(ctx,((double)prepareConstraints));
		return ret;
	}
	
	static JSValue js_b2Profile_set_prepareConstraints(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].prepareConstraints=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_integrateVelocities(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float integrateVelocities=ptr[0].integrateVelocities;
		JSValue ret=JS_NewFloat64(ctx,((double)integrateVelocities));
		return ret;
	}
	
	static JSValue js_b2Profile_set_integrateVelocities(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].integrateVelocities=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_warmStart(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float warmStart=ptr[0].warmStart;
		JSValue ret=JS_NewFloat64(ctx,((double)warmStart));
		return ret;
	}
	
	static JSValue js_b2Profile_set_warmStart(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].warmStart=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_solveImpulses(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float solveImpulses=ptr[0].solveImpulses;
		JSValue ret=JS_NewFloat64(ctx,((double)solveImpulses));
		return ret;
	}
	
	static JSValue js_b2Profile_set_solveImpulses(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].solveImpulses=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_integratePositions(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float integratePositions=ptr[0].integratePositions;
		JSValue ret=JS_NewFloat64(ctx,((double)integratePositions));
		return ret;
	}
	
	static JSValue js_b2Profile_set_integratePositions(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].integratePositions=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_relaxImpulses(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float relaxImpulses=ptr[0].relaxImpulses;
		JSValue ret=JS_NewFloat64(ctx,((double)relaxImpulses));
		return ret;
	}
	
	static JSValue js_b2Profile_set_relaxImpulses(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].relaxImpulses=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_applyRestitution(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float applyRestitution=ptr[0].applyRestitution;
		JSValue ret=JS_NewFloat64(ctx,((double)applyRestitution));
		return ret;
	}
	
	static JSValue js_b2Profile_set_applyRestitution(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].applyRestitution=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_storeImpulses(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float storeImpulses=ptr[0].storeImpulses;
		JSValue ret=JS_NewFloat64(ctx,((double)storeImpulses));
		return ret;
	}
	
	static JSValue js_b2Profile_set_storeImpulses(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].storeImpulses=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_splitIslands(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float splitIslands=ptr[0].splitIslands;
		JSValue ret=JS_NewFloat64(ctx,((double)splitIslands));
		return ret;
	}
	
	static JSValue js_b2Profile_set_splitIslands(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].splitIslands=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_transforms(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float transforms=ptr[0].transforms;
		JSValue ret=JS_NewFloat64(ctx,((double)transforms));
		return ret;
	}
	
	static JSValue js_b2Profile_set_transforms(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transforms=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_hitEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float hitEvents=ptr[0].hitEvents;
		JSValue ret=JS_NewFloat64(ctx,((double)hitEvents));
		return ret;
	}
	
	static JSValue js_b2Profile_set_hitEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hitEvents=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_refit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float refit=ptr[0].refit;
		JSValue ret=JS_NewFloat64(ctx,((double)refit));
		return ret;
	}
	
	static JSValue js_b2Profile_set_refit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].refit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_bullets(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float bullets=ptr[0].bullets;
		JSValue ret=JS_NewFloat64(ctx,((double)bullets));
		return ret;
	}
	
	static JSValue js_b2Profile_set_bullets(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bullets=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_sleepIslands(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float sleepIslands=ptr[0].sleepIslands;
		JSValue ret=JS_NewFloat64(ctx,((double)sleepIslands));
		return ret;
	}
	
	static JSValue js_b2Profile_set_sleepIslands(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sleepIslands=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Profile_get_sensors(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		float sensors=ptr[0].sensors;
		JSValue ret=JS_NewFloat64(ctx,((double)sensors));
		return ret;
	}
	
	static JSValue js_b2Profile_set_sensors(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Profile_class_id);
		b2Profile * ptr=(b2Profile  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sensors=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Profile_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Profile", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("step",js_b2Profile_get_step,js_b2Profile_set_step),
		JS_CGETSET_DEF("pairs",js_b2Profile_get_pairs,js_b2Profile_set_pairs),
		JS_CGETSET_DEF("collide",js_b2Profile_get_collide,js_b2Profile_set_collide),
		JS_CGETSET_DEF("solve",js_b2Profile_get_solve,js_b2Profile_set_solve),
		JS_CGETSET_DEF("mergeIslands",js_b2Profile_get_mergeIslands,js_b2Profile_set_mergeIslands),
		JS_CGETSET_DEF("prepareStages",js_b2Profile_get_prepareStages,js_b2Profile_set_prepareStages),
		JS_CGETSET_DEF("solveConstraints",js_b2Profile_get_solveConstraints,js_b2Profile_set_solveConstraints),
		JS_CGETSET_DEF("prepareConstraints",js_b2Profile_get_prepareConstraints,js_b2Profile_set_prepareConstraints),
		JS_CGETSET_DEF("integrateVelocities",js_b2Profile_get_integrateVelocities,js_b2Profile_set_integrateVelocities),
		JS_CGETSET_DEF("warmStart",js_b2Profile_get_warmStart,js_b2Profile_set_warmStart),
		JS_CGETSET_DEF("solveImpulses",js_b2Profile_get_solveImpulses,js_b2Profile_set_solveImpulses),
		JS_CGETSET_DEF("integratePositions",js_b2Profile_get_integratePositions,js_b2Profile_set_integratePositions),
		JS_CGETSET_DEF("relaxImpulses",js_b2Profile_get_relaxImpulses,js_b2Profile_set_relaxImpulses),
		JS_CGETSET_DEF("applyRestitution",js_b2Profile_get_applyRestitution,js_b2Profile_set_applyRestitution),
		JS_CGETSET_DEF("storeImpulses",js_b2Profile_get_storeImpulses,js_b2Profile_set_storeImpulses),
		JS_CGETSET_DEF("splitIslands",js_b2Profile_get_splitIslands,js_b2Profile_set_splitIslands),
		JS_CGETSET_DEF("transforms",js_b2Profile_get_transforms,js_b2Profile_set_transforms),
		JS_CGETSET_DEF("hitEvents",js_b2Profile_get_hitEvents,js_b2Profile_set_hitEvents),
		JS_CGETSET_DEF("refit",js_b2Profile_get_refit,js_b2Profile_set_refit),
		JS_CGETSET_DEF("bullets",js_b2Profile_get_bullets,js_b2Profile_set_bullets),
		JS_CGETSET_DEF("sleepIslands",js_b2Profile_get_sleepIslands,js_b2Profile_set_sleepIslands),
		JS_CGETSET_DEF("sensors",js_b2Profile_get_sensors,js_b2Profile_set_sensors)
	};
	
	static int js_declare_b2Profile(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Profile_class_id);
		JSClassDef js_b2Profile_def={ .class_name = "b2Profile", .finalizer = js_b2Profile_finalizer };
		JS_NewClass(rt,js_b2Profile_class_id,(const JSClassDef  *)&js_b2Profile_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Profile_proto_funcs,(int)countof(js_b2Profile_proto_funcs));
		JS_SetClassProto(ctx,js_b2Profile_class_id,proto);
		return 0;
	}
	
	static void js_b2Counters_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2Counters_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2Counters_get_bodyCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int bodyCount=ptr[0].bodyCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)bodyCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_bodyCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_shapeCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int shapeCount=ptr[0].shapeCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)shapeCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_shapeCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_contactCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int contactCount=ptr[0].contactCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)contactCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_contactCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].contactCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_jointCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int jointCount=ptr[0].jointCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)jointCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_jointCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].jointCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_islandCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int islandCount=ptr[0].islandCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)islandCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_islandCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].islandCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_stackUsed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int stackUsed=ptr[0].stackUsed;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)stackUsed));
		return ret;
	}
	
	static JSValue js_b2Counters_set_stackUsed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].stackUsed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_staticTreeHeight(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int staticTreeHeight=ptr[0].staticTreeHeight;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)staticTreeHeight));
		return ret;
	}
	
	static JSValue js_b2Counters_set_staticTreeHeight(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].staticTreeHeight=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_treeHeight(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int treeHeight=ptr[0].treeHeight;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)treeHeight));
		return ret;
	}
	
	static JSValue js_b2Counters_set_treeHeight(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].treeHeight=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_byteCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int byteCount=ptr[0].byteCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)byteCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_byteCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].byteCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_get_taskCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		int taskCount=ptr[0].taskCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)taskCount));
		return ret;
	}
	
	static JSValue js_b2Counters_set_taskCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].taskCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Counters_colorCounts_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2Counters * ptr=(b2Counters  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<12;i++){
			int src0=ptr[0].colorCounts[i];
			JSValue ret1=JS_NewInt32(ctx,(int32_t)((long)src0));
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2Counters_colorCounts_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2Counters * ptr=(b2Counters  *)ptr_u;
		int length=(int)12;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2Counters_colorCounts_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2Counters * ptr=(b2Counters  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)12));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<12){
				int src=ptr[0].colorCounts[property];
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)src));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2Counters_colorCounts_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2Counters * ptr=(b2Counters  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<12){
				bool error=(bool)0;
				local_memlock=true;
				int ret=js_getint_arg1(ctx,set_to,&error,(int)12);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].colorCounts[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2Counters_colorCounts_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2Counters * ptr=(b2Counters  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<12){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2Counters_get_colorCounts(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2Counters_colorCounts_values,.keys = js_b2Counters_colorCounts_keys,.get = js_b2Counters_colorCounts_get,.set = js_b2Counters_colorCounts_set,.has = js_b2Counters_colorCounts_has});
		return ret;
	}
	
	static JSValue js_b2Counters_set_colorCounts(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2Counters_class_id);
		b2Counters * ptr=(b2Counters  *)shadow[0].ptr;
		local_memlock=true;
		int * value=js_getint_arr12nc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		memcpy((void  *)ptr[0].colorCounts,(const void  *)value,12*sizeof(int));
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2Counters_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2Counters", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyCount",js_b2Counters_get_bodyCount,js_b2Counters_set_bodyCount),
		JS_CGETSET_DEF("shapeCount",js_b2Counters_get_shapeCount,js_b2Counters_set_shapeCount),
		JS_CGETSET_DEF("contactCount",js_b2Counters_get_contactCount,js_b2Counters_set_contactCount),
		JS_CGETSET_DEF("jointCount",js_b2Counters_get_jointCount,js_b2Counters_set_jointCount),
		JS_CGETSET_DEF("islandCount",js_b2Counters_get_islandCount,js_b2Counters_set_islandCount),
		JS_CGETSET_DEF("stackUsed",js_b2Counters_get_stackUsed,js_b2Counters_set_stackUsed),
		JS_CGETSET_DEF("staticTreeHeight",js_b2Counters_get_staticTreeHeight,js_b2Counters_set_staticTreeHeight),
		JS_CGETSET_DEF("treeHeight",js_b2Counters_get_treeHeight,js_b2Counters_set_treeHeight),
		JS_CGETSET_DEF("byteCount",js_b2Counters_get_byteCount,js_b2Counters_set_byteCount),
		JS_CGETSET_DEF("taskCount",js_b2Counters_get_taskCount,js_b2Counters_set_taskCount),
		JS_CGETSET_DEF("colorCounts",js_b2Counters_get_colorCounts,js_b2Counters_set_colorCounts)
	};
	
	static int js_declare_b2Counters(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2Counters_class_id);
		JSClassDef js_b2Counters_def={ .class_name = "b2Counters", .finalizer = js_b2Counters_finalizer };
		JS_NewClass(rt,js_b2Counters_class_id,(const JSClassDef  *)&js_b2Counters_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2Counters_proto_funcs,(int)countof(js_b2Counters_proto_funcs));
		JS_SetClassProto(ctx,js_b2Counters_class_id,proto);
		return 0;
	}
	
	static void js_b2DistanceJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2DistanceJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2DistanceJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_localAnchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorA=&ptr[0].localAnchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_localAnchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_localAnchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorB=&ptr[0].localAnchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_localAnchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_length(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float length=ptr[0].length;
		JSValue ret=JS_NewFloat64(ctx,((double)length));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_length(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].length=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_enableSpring(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		bool enableSpring=ptr[0].enableSpring;
		JSValue ret=JS_NewBool(ctx,enableSpring);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_enableSpring(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSpring=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_hertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float hertz=ptr[0].hertz;
		JSValue ret=JS_NewFloat64(ctx,((double)hertz));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_hertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_dampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float dampingRatio=ptr[0].dampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)dampingRatio));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_dampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].dampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_enableLimit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		bool enableLimit=ptr[0].enableLimit;
		JSValue ret=JS_NewBool(ctx,enableLimit);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_enableLimit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableLimit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_minLength(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float minLength=ptr[0].minLength;
		JSValue ret=JS_NewFloat64(ctx,((double)minLength));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_minLength(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].minLength=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_maxLength(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float maxLength=ptr[0].maxLength;
		JSValue ret=JS_NewFloat64(ctx,((double)maxLength));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_maxLength(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxLength=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_enableMotor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		bool enableMotor=ptr[0].enableMotor;
		JSValue ret=JS_NewBool(ctx,enableMotor);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_enableMotor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableMotor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_maxMotorForce(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float maxMotorForce=ptr[0].maxMotorForce;
		JSValue ret=JS_NewFloat64(ctx,((double)maxMotorForce));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_maxMotorForce(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxMotorForce=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_motorSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		float motorSpeed=ptr[0].motorSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)motorSpeed));
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_motorSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].motorSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2DistanceJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2DistanceJointDef_class_id);
		b2DistanceJointDef * ptr=(b2DistanceJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2DistanceJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2DistanceJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2DistanceJointDef_get_bodyIdA,js_b2DistanceJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2DistanceJointDef_get_bodyIdB,js_b2DistanceJointDef_set_bodyIdB),
		JS_CGETSET_DEF("localAnchorA",js_b2DistanceJointDef_get_localAnchorA,js_b2DistanceJointDef_set_localAnchorA),
		JS_CGETSET_DEF("localAnchorB",js_b2DistanceJointDef_get_localAnchorB,js_b2DistanceJointDef_set_localAnchorB),
		JS_CGETSET_DEF("length",js_b2DistanceJointDef_get_length,js_b2DistanceJointDef_set_length),
		JS_CGETSET_DEF("enableSpring",js_b2DistanceJointDef_get_enableSpring,js_b2DistanceJointDef_set_enableSpring),
		JS_CGETSET_DEF("hertz",js_b2DistanceJointDef_get_hertz,js_b2DistanceJointDef_set_hertz),
		JS_CGETSET_DEF("dampingRatio",js_b2DistanceJointDef_get_dampingRatio,js_b2DistanceJointDef_set_dampingRatio),
		JS_CGETSET_DEF("enableLimit",js_b2DistanceJointDef_get_enableLimit,js_b2DistanceJointDef_set_enableLimit),
		JS_CGETSET_DEF("minLength",js_b2DistanceJointDef_get_minLength,js_b2DistanceJointDef_set_minLength),
		JS_CGETSET_DEF("maxLength",js_b2DistanceJointDef_get_maxLength,js_b2DistanceJointDef_set_maxLength),
		JS_CGETSET_DEF("enableMotor",js_b2DistanceJointDef_get_enableMotor,js_b2DistanceJointDef_set_enableMotor),
		JS_CGETSET_DEF("maxMotorForce",js_b2DistanceJointDef_get_maxMotorForce,js_b2DistanceJointDef_set_maxMotorForce),
		JS_CGETSET_DEF("motorSpeed",js_b2DistanceJointDef_get_motorSpeed,js_b2DistanceJointDef_set_motorSpeed),
		JS_CGETSET_DEF("collideConnected",js_b2DistanceJointDef_get_collideConnected,js_b2DistanceJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2DistanceJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2DistanceJointDef_class_id);
		JSClassDef js_b2DistanceJointDef_def={ .class_name = "b2DistanceJointDef", .finalizer = js_b2DistanceJointDef_finalizer };
		JS_NewClass(rt,js_b2DistanceJointDef_class_id,(const JSClassDef  *)&js_b2DistanceJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2DistanceJointDef_proto_funcs,(int)countof(js_b2DistanceJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2DistanceJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2MotorJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2MotorJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2MotorJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_linearOffset(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * linearOffset=&ptr[0].linearOffset;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)linearOffset,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_linearOffset(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].linearOffset=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_angularOffset(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		float angularOffset=ptr[0].angularOffset;
		JSValue ret=JS_NewFloat64(ctx,((double)angularOffset));
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_angularOffset(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].angularOffset=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_maxForce(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		float maxForce=ptr[0].maxForce;
		JSValue ret=JS_NewFloat64(ctx,((double)maxForce));
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_maxForce(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxForce=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_maxTorque(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		float maxTorque=ptr[0].maxTorque;
		JSValue ret=JS_NewFloat64(ctx,((double)maxTorque));
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_maxTorque(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxTorque=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_correctionFactor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		float correctionFactor=ptr[0].correctionFactor;
		JSValue ret=JS_NewFloat64(ctx,((double)correctionFactor));
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_correctionFactor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].correctionFactor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2MotorJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MotorJointDef_class_id);
		b2MotorJointDef * ptr=(b2MotorJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2MotorJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2MotorJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2MotorJointDef_get_bodyIdA,js_b2MotorJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2MotorJointDef_get_bodyIdB,js_b2MotorJointDef_set_bodyIdB),
		JS_CGETSET_DEF("linearOffset",js_b2MotorJointDef_get_linearOffset,js_b2MotorJointDef_set_linearOffset),
		JS_CGETSET_DEF("angularOffset",js_b2MotorJointDef_get_angularOffset,js_b2MotorJointDef_set_angularOffset),
		JS_CGETSET_DEF("maxForce",js_b2MotorJointDef_get_maxForce,js_b2MotorJointDef_set_maxForce),
		JS_CGETSET_DEF("maxTorque",js_b2MotorJointDef_get_maxTorque,js_b2MotorJointDef_set_maxTorque),
		JS_CGETSET_DEF("correctionFactor",js_b2MotorJointDef_get_correctionFactor,js_b2MotorJointDef_set_correctionFactor),
		JS_CGETSET_DEF("collideConnected",js_b2MotorJointDef_get_collideConnected,js_b2MotorJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2MotorJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2MotorJointDef_class_id);
		JSClassDef js_b2MotorJointDef_def={ .class_name = "b2MotorJointDef", .finalizer = js_b2MotorJointDef_finalizer };
		JS_NewClass(rt,js_b2MotorJointDef_class_id,(const JSClassDef  *)&js_b2MotorJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2MotorJointDef_proto_funcs,(int)countof(js_b2MotorJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2MotorJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2MouseJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2MouseJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2MouseJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_target(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * target=&ptr[0].target;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)target,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_target(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].target=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_hertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		float hertz=ptr[0].hertz;
		JSValue ret=JS_NewFloat64(ctx,((double)hertz));
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_hertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_dampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		float dampingRatio=ptr[0].dampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)dampingRatio));
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_dampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].dampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_maxForce(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		float maxForce=ptr[0].maxForce;
		JSValue ret=JS_NewFloat64(ctx,((double)maxForce));
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_maxForce(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxForce=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2MouseJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2MouseJointDef_class_id);
		b2MouseJointDef * ptr=(b2MouseJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2MouseJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2MouseJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2MouseJointDef_get_bodyIdA,js_b2MouseJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2MouseJointDef_get_bodyIdB,js_b2MouseJointDef_set_bodyIdB),
		JS_CGETSET_DEF("target",js_b2MouseJointDef_get_target,js_b2MouseJointDef_set_target),
		JS_CGETSET_DEF("hertz",js_b2MouseJointDef_get_hertz,js_b2MouseJointDef_set_hertz),
		JS_CGETSET_DEF("dampingRatio",js_b2MouseJointDef_get_dampingRatio,js_b2MouseJointDef_set_dampingRatio),
		JS_CGETSET_DEF("maxForce",js_b2MouseJointDef_get_maxForce,js_b2MouseJointDef_set_maxForce),
		JS_CGETSET_DEF("collideConnected",js_b2MouseJointDef_get_collideConnected,js_b2MouseJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2MouseJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2MouseJointDef_class_id);
		JSClassDef js_b2MouseJointDef_def={ .class_name = "b2MouseJointDef", .finalizer = js_b2MouseJointDef_finalizer };
		JS_NewClass(rt,js_b2MouseJointDef_class_id,(const JSClassDef  *)&js_b2MouseJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2MouseJointDef_proto_funcs,(int)countof(js_b2MouseJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2MouseJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2FilterJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2FilterJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2FilterJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2FilterJointDef_class_id);
		b2FilterJointDef * ptr=(b2FilterJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2FilterJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2FilterJointDef_class_id);
		b2FilterJointDef * ptr=(b2FilterJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2FilterJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2FilterJointDef_class_id);
		b2FilterJointDef * ptr=(b2FilterJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2FilterJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2FilterJointDef_class_id);
		b2FilterJointDef * ptr=(b2FilterJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2FilterJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2FilterJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2FilterJointDef_get_bodyIdA,js_b2FilterJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2FilterJointDef_get_bodyIdB,js_b2FilterJointDef_set_bodyIdB),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2FilterJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2FilterJointDef_class_id);
		JSClassDef js_b2FilterJointDef_def={ .class_name = "b2FilterJointDef", .finalizer = js_b2FilterJointDef_finalizer };
		JS_NewClass(rt,js_b2FilterJointDef_class_id,(const JSClassDef  *)&js_b2FilterJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2FilterJointDef_proto_funcs,(int)countof(js_b2FilterJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2FilterJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2PrismaticJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2PrismaticJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2PrismaticJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_localAnchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorA=&ptr[0].localAnchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_localAnchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_localAnchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorB=&ptr[0].localAnchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_localAnchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_localAxisA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAxisA=&ptr[0].localAxisA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAxisA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_localAxisA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAxisA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_referenceAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float referenceAngle=ptr[0].referenceAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)referenceAngle));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_referenceAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].referenceAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_targetTranslation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float targetTranslation=ptr[0].targetTranslation;
		JSValue ret=JS_NewFloat64(ctx,((double)targetTranslation));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_targetTranslation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].targetTranslation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_enableSpring(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		bool enableSpring=ptr[0].enableSpring;
		JSValue ret=JS_NewBool(ctx,enableSpring);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_enableSpring(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSpring=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_hertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float hertz=ptr[0].hertz;
		JSValue ret=JS_NewFloat64(ctx,((double)hertz));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_hertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_dampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float dampingRatio=ptr[0].dampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)dampingRatio));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_dampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].dampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_enableLimit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		bool enableLimit=ptr[0].enableLimit;
		JSValue ret=JS_NewBool(ctx,enableLimit);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_enableLimit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableLimit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_lowerTranslation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float lowerTranslation=ptr[0].lowerTranslation;
		JSValue ret=JS_NewFloat64(ctx,((double)lowerTranslation));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_lowerTranslation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].lowerTranslation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_upperTranslation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float upperTranslation=ptr[0].upperTranslation;
		JSValue ret=JS_NewFloat64(ctx,((double)upperTranslation));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_upperTranslation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].upperTranslation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_enableMotor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		bool enableMotor=ptr[0].enableMotor;
		JSValue ret=JS_NewBool(ctx,enableMotor);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_enableMotor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableMotor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_maxMotorForce(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float maxMotorForce=ptr[0].maxMotorForce;
		JSValue ret=JS_NewFloat64(ctx,((double)maxMotorForce));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_maxMotorForce(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxMotorForce=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_motorSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		float motorSpeed=ptr[0].motorSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)motorSpeed));
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_motorSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].motorSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2PrismaticJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2PrismaticJointDef_class_id);
		b2PrismaticJointDef * ptr=(b2PrismaticJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2PrismaticJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2PrismaticJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2PrismaticJointDef_get_bodyIdA,js_b2PrismaticJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2PrismaticJointDef_get_bodyIdB,js_b2PrismaticJointDef_set_bodyIdB),
		JS_CGETSET_DEF("localAnchorA",js_b2PrismaticJointDef_get_localAnchorA,js_b2PrismaticJointDef_set_localAnchorA),
		JS_CGETSET_DEF("localAnchorB",js_b2PrismaticJointDef_get_localAnchorB,js_b2PrismaticJointDef_set_localAnchorB),
		JS_CGETSET_DEF("localAxisA",js_b2PrismaticJointDef_get_localAxisA,js_b2PrismaticJointDef_set_localAxisA),
		JS_CGETSET_DEF("referenceAngle",js_b2PrismaticJointDef_get_referenceAngle,js_b2PrismaticJointDef_set_referenceAngle),
		JS_CGETSET_DEF("targetTranslation",js_b2PrismaticJointDef_get_targetTranslation,js_b2PrismaticJointDef_set_targetTranslation),
		JS_CGETSET_DEF("enableSpring",js_b2PrismaticJointDef_get_enableSpring,js_b2PrismaticJointDef_set_enableSpring),
		JS_CGETSET_DEF("hertz",js_b2PrismaticJointDef_get_hertz,js_b2PrismaticJointDef_set_hertz),
		JS_CGETSET_DEF("dampingRatio",js_b2PrismaticJointDef_get_dampingRatio,js_b2PrismaticJointDef_set_dampingRatio),
		JS_CGETSET_DEF("enableLimit",js_b2PrismaticJointDef_get_enableLimit,js_b2PrismaticJointDef_set_enableLimit),
		JS_CGETSET_DEF("lowerTranslation",js_b2PrismaticJointDef_get_lowerTranslation,js_b2PrismaticJointDef_set_lowerTranslation),
		JS_CGETSET_DEF("upperTranslation",js_b2PrismaticJointDef_get_upperTranslation,js_b2PrismaticJointDef_set_upperTranslation),
		JS_CGETSET_DEF("enableMotor",js_b2PrismaticJointDef_get_enableMotor,js_b2PrismaticJointDef_set_enableMotor),
		JS_CGETSET_DEF("maxMotorForce",js_b2PrismaticJointDef_get_maxMotorForce,js_b2PrismaticJointDef_set_maxMotorForce),
		JS_CGETSET_DEF("motorSpeed",js_b2PrismaticJointDef_get_motorSpeed,js_b2PrismaticJointDef_set_motorSpeed),
		JS_CGETSET_DEF("collideConnected",js_b2PrismaticJointDef_get_collideConnected,js_b2PrismaticJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2PrismaticJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2PrismaticJointDef_class_id);
		JSClassDef js_b2PrismaticJointDef_def={ .class_name = "b2PrismaticJointDef", .finalizer = js_b2PrismaticJointDef_finalizer };
		JS_NewClass(rt,js_b2PrismaticJointDef_class_id,(const JSClassDef  *)&js_b2PrismaticJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2PrismaticJointDef_proto_funcs,(int)countof(js_b2PrismaticJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2PrismaticJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2RevoluteJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2RevoluteJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2RevoluteJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_localAnchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorA=&ptr[0].localAnchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_localAnchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_localAnchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorB=&ptr[0].localAnchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_localAnchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_referenceAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float referenceAngle=ptr[0].referenceAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)referenceAngle));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_referenceAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].referenceAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_targetAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float targetAngle=ptr[0].targetAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)targetAngle));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_targetAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].targetAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_enableSpring(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		bool enableSpring=ptr[0].enableSpring;
		JSValue ret=JS_NewBool(ctx,enableSpring);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_enableSpring(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSpring=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_hertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float hertz=ptr[0].hertz;
		JSValue ret=JS_NewFloat64(ctx,((double)hertz));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_hertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_dampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float dampingRatio=ptr[0].dampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)dampingRatio));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_dampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].dampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_enableLimit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		bool enableLimit=ptr[0].enableLimit;
		JSValue ret=JS_NewBool(ctx,enableLimit);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_enableLimit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableLimit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_lowerAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float lowerAngle=ptr[0].lowerAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)lowerAngle));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_lowerAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].lowerAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_upperAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float upperAngle=ptr[0].upperAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)upperAngle));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_upperAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].upperAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_enableMotor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		bool enableMotor=ptr[0].enableMotor;
		JSValue ret=JS_NewBool(ctx,enableMotor);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_enableMotor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableMotor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_maxMotorTorque(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float maxMotorTorque=ptr[0].maxMotorTorque;
		JSValue ret=JS_NewFloat64(ctx,((double)maxMotorTorque));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_maxMotorTorque(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxMotorTorque=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_motorSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float motorSpeed=ptr[0].motorSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)motorSpeed));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_motorSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].motorSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_drawSize(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		float drawSize=ptr[0].drawSize;
		JSValue ret=JS_NewFloat64(ctx,((double)drawSize));
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_drawSize(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].drawSize=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2RevoluteJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2RevoluteJointDef_class_id);
		b2RevoluteJointDef * ptr=(b2RevoluteJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2RevoluteJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2RevoluteJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2RevoluteJointDef_get_bodyIdA,js_b2RevoluteJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2RevoluteJointDef_get_bodyIdB,js_b2RevoluteJointDef_set_bodyIdB),
		JS_CGETSET_DEF("localAnchorA",js_b2RevoluteJointDef_get_localAnchorA,js_b2RevoluteJointDef_set_localAnchorA),
		JS_CGETSET_DEF("localAnchorB",js_b2RevoluteJointDef_get_localAnchorB,js_b2RevoluteJointDef_set_localAnchorB),
		JS_CGETSET_DEF("referenceAngle",js_b2RevoluteJointDef_get_referenceAngle,js_b2RevoluteJointDef_set_referenceAngle),
		JS_CGETSET_DEF("targetAngle",js_b2RevoluteJointDef_get_targetAngle,js_b2RevoluteJointDef_set_targetAngle),
		JS_CGETSET_DEF("enableSpring",js_b2RevoluteJointDef_get_enableSpring,js_b2RevoluteJointDef_set_enableSpring),
		JS_CGETSET_DEF("hertz",js_b2RevoluteJointDef_get_hertz,js_b2RevoluteJointDef_set_hertz),
		JS_CGETSET_DEF("dampingRatio",js_b2RevoluteJointDef_get_dampingRatio,js_b2RevoluteJointDef_set_dampingRatio),
		JS_CGETSET_DEF("enableLimit",js_b2RevoluteJointDef_get_enableLimit,js_b2RevoluteJointDef_set_enableLimit),
		JS_CGETSET_DEF("lowerAngle",js_b2RevoluteJointDef_get_lowerAngle,js_b2RevoluteJointDef_set_lowerAngle),
		JS_CGETSET_DEF("upperAngle",js_b2RevoluteJointDef_get_upperAngle,js_b2RevoluteJointDef_set_upperAngle),
		JS_CGETSET_DEF("enableMotor",js_b2RevoluteJointDef_get_enableMotor,js_b2RevoluteJointDef_set_enableMotor),
		JS_CGETSET_DEF("maxMotorTorque",js_b2RevoluteJointDef_get_maxMotorTorque,js_b2RevoluteJointDef_set_maxMotorTorque),
		JS_CGETSET_DEF("motorSpeed",js_b2RevoluteJointDef_get_motorSpeed,js_b2RevoluteJointDef_set_motorSpeed),
		JS_CGETSET_DEF("drawSize",js_b2RevoluteJointDef_get_drawSize,js_b2RevoluteJointDef_set_drawSize),
		JS_CGETSET_DEF("collideConnected",js_b2RevoluteJointDef_get_collideConnected,js_b2RevoluteJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2RevoluteJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2RevoluteJointDef_class_id);
		JSClassDef js_b2RevoluteJointDef_def={ .class_name = "b2RevoluteJointDef", .finalizer = js_b2RevoluteJointDef_finalizer };
		JS_NewClass(rt,js_b2RevoluteJointDef_class_id,(const JSClassDef  *)&js_b2RevoluteJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2RevoluteJointDef_proto_funcs,(int)countof(js_b2RevoluteJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2RevoluteJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2WeldJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2WeldJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2WeldJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_localAnchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorA=&ptr[0].localAnchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_localAnchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_localAnchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorB=&ptr[0].localAnchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_localAnchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_referenceAngle(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		float referenceAngle=ptr[0].referenceAngle;
		JSValue ret=JS_NewFloat64(ctx,((double)referenceAngle));
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_referenceAngle(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].referenceAngle=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_linearHertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		float linearHertz=ptr[0].linearHertz;
		JSValue ret=JS_NewFloat64(ctx,((double)linearHertz));
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_linearHertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].linearHertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_angularHertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		float angularHertz=ptr[0].angularHertz;
		JSValue ret=JS_NewFloat64(ctx,((double)angularHertz));
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_angularHertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].angularHertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_linearDampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		float linearDampingRatio=ptr[0].linearDampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)linearDampingRatio));
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_linearDampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].linearDampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_angularDampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		float angularDampingRatio=ptr[0].angularDampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)angularDampingRatio));
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_angularDampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].angularDampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2WeldJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WeldJointDef_class_id);
		b2WeldJointDef * ptr=(b2WeldJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2WeldJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2WeldJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2WeldJointDef_get_bodyIdA,js_b2WeldJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2WeldJointDef_get_bodyIdB,js_b2WeldJointDef_set_bodyIdB),
		JS_CGETSET_DEF("localAnchorA",js_b2WeldJointDef_get_localAnchorA,js_b2WeldJointDef_set_localAnchorA),
		JS_CGETSET_DEF("localAnchorB",js_b2WeldJointDef_get_localAnchorB,js_b2WeldJointDef_set_localAnchorB),
		JS_CGETSET_DEF("referenceAngle",js_b2WeldJointDef_get_referenceAngle,js_b2WeldJointDef_set_referenceAngle),
		JS_CGETSET_DEF("linearHertz",js_b2WeldJointDef_get_linearHertz,js_b2WeldJointDef_set_linearHertz),
		JS_CGETSET_DEF("angularHertz",js_b2WeldJointDef_get_angularHertz,js_b2WeldJointDef_set_angularHertz),
		JS_CGETSET_DEF("linearDampingRatio",js_b2WeldJointDef_get_linearDampingRatio,js_b2WeldJointDef_set_linearDampingRatio),
		JS_CGETSET_DEF("angularDampingRatio",js_b2WeldJointDef_get_angularDampingRatio,js_b2WeldJointDef_set_angularDampingRatio),
		JS_CGETSET_DEF("collideConnected",js_b2WeldJointDef_get_collideConnected,js_b2WeldJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2WeldJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2WeldJointDef_class_id);
		JSClassDef js_b2WeldJointDef_def={ .class_name = "b2WeldJointDef", .finalizer = js_b2WeldJointDef_finalizer };
		JS_NewClass(rt,js_b2WeldJointDef_class_id,(const JSClassDef  *)&js_b2WeldJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2WeldJointDef_proto_funcs,(int)countof(js_b2WeldJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2WeldJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2WheelJointDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2WheelJointDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2WheelJointDef_get_bodyIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdA=&ptr[0].bodyIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_bodyIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_bodyIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyIdB=&ptr[0].bodyIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_bodyIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_localAnchorA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorA=&ptr[0].localAnchorA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_localAnchorA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_localAnchorB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAnchorB=&ptr[0].localAnchorB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAnchorB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_localAnchorB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAnchorB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_localAxisA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * localAxisA=&ptr[0].localAxisA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)localAxisA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_localAxisA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].localAxisA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_enableSpring(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		bool enableSpring=ptr[0].enableSpring;
		JSValue ret=JS_NewBool(ctx,enableSpring);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_enableSpring(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableSpring=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_hertz(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float hertz=ptr[0].hertz;
		JSValue ret=JS_NewFloat64(ctx,((double)hertz));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_hertz(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hertz=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_dampingRatio(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float dampingRatio=ptr[0].dampingRatio;
		JSValue ret=JS_NewFloat64(ctx,((double)dampingRatio));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_dampingRatio(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].dampingRatio=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_enableLimit(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		bool enableLimit=ptr[0].enableLimit;
		JSValue ret=JS_NewBool(ctx,enableLimit);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_enableLimit(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableLimit=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_lowerTranslation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float lowerTranslation=ptr[0].lowerTranslation;
		JSValue ret=JS_NewFloat64(ctx,((double)lowerTranslation));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_lowerTranslation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].lowerTranslation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_upperTranslation(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float upperTranslation=ptr[0].upperTranslation;
		JSValue ret=JS_NewFloat64(ctx,((double)upperTranslation));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_upperTranslation(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].upperTranslation=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_enableMotor(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		bool enableMotor=ptr[0].enableMotor;
		JSValue ret=JS_NewBool(ctx,enableMotor);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_enableMotor(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].enableMotor=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_maxMotorTorque(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float maxMotorTorque=ptr[0].maxMotorTorque;
		JSValue ret=JS_NewFloat64(ctx,((double)maxMotorTorque));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_maxMotorTorque(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maxMotorTorque=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_motorSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		float motorSpeed=ptr[0].motorSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)motorSpeed));
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_motorSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].motorSpeed=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJointDef_get_collideConnected(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		bool collideConnected=ptr[0].collideConnected;
		JSValue ret=JS_NewBool(ctx,collideConnected);
		return ret;
	}
	
	static JSValue js_b2WheelJointDef_set_collideConnected(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2WheelJointDef_class_id);
		b2WheelJointDef * ptr=(b2WheelJointDef  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].collideConnected=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2WheelJointDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2WheelJointDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("bodyIdA",js_b2WheelJointDef_get_bodyIdA,js_b2WheelJointDef_set_bodyIdA),
		JS_CGETSET_DEF("bodyIdB",js_b2WheelJointDef_get_bodyIdB,js_b2WheelJointDef_set_bodyIdB),
		JS_CGETSET_DEF("localAnchorA",js_b2WheelJointDef_get_localAnchorA,js_b2WheelJointDef_set_localAnchorA),
		JS_CGETSET_DEF("localAnchorB",js_b2WheelJointDef_get_localAnchorB,js_b2WheelJointDef_set_localAnchorB),
		JS_CGETSET_DEF("localAxisA",js_b2WheelJointDef_get_localAxisA,js_b2WheelJointDef_set_localAxisA),
		JS_CGETSET_DEF("enableSpring",js_b2WheelJointDef_get_enableSpring,js_b2WheelJointDef_set_enableSpring),
		JS_CGETSET_DEF("hertz",js_b2WheelJointDef_get_hertz,js_b2WheelJointDef_set_hertz),
		JS_CGETSET_DEF("dampingRatio",js_b2WheelJointDef_get_dampingRatio,js_b2WheelJointDef_set_dampingRatio),
		JS_CGETSET_DEF("enableLimit",js_b2WheelJointDef_get_enableLimit,js_b2WheelJointDef_set_enableLimit),
		JS_CGETSET_DEF("lowerTranslation",js_b2WheelJointDef_get_lowerTranslation,js_b2WheelJointDef_set_lowerTranslation),
		JS_CGETSET_DEF("upperTranslation",js_b2WheelJointDef_get_upperTranslation,js_b2WheelJointDef_set_upperTranslation),
		JS_CGETSET_DEF("enableMotor",js_b2WheelJointDef_get_enableMotor,js_b2WheelJointDef_set_enableMotor),
		JS_CGETSET_DEF("maxMotorTorque",js_b2WheelJointDef_get_maxMotorTorque,js_b2WheelJointDef_set_maxMotorTorque),
		JS_CGETSET_DEF("motorSpeed",js_b2WheelJointDef_get_motorSpeed,js_b2WheelJointDef_set_motorSpeed),
		JS_CGETSET_DEF("collideConnected",js_b2WheelJointDef_get_collideConnected,js_b2WheelJointDef_set_collideConnected),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("internalValue",NULL,NULL)
	};
	
	static int js_declare_b2WheelJointDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2WheelJointDef_class_id);
		JSClassDef js_b2WheelJointDef_def={ .class_name = "b2WheelJointDef", .finalizer = js_b2WheelJointDef_finalizer };
		JS_NewClass(rt,js_b2WheelJointDef_class_id,(const JSClassDef  *)&js_b2WheelJointDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2WheelJointDef_proto_funcs,(int)countof(js_b2WheelJointDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2WheelJointDef_class_id,proto);
		return 0;
	}
	
	static void js_b2ExplosionDef_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ExplosionDef_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ExplosionDef_get_maskBits(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		uint64_t maskBits=ptr[0].maskBits;
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)maskBits));
		return ret;
	}
	
	static JSValue js_b2ExplosionDef_set_maskBits(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		local_memlock=true;
		uint64_t value=js_getuint64_t(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].maskBits=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ExplosionDef_get_position(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * position=&ptr[0].position;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)position,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ExplosionDef_set_position(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].position=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ExplosionDef_get_radius(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		float radius=ptr[0].radius;
		JSValue ret=JS_NewFloat64(ctx,((double)radius));
		return ret;
	}
	
	static JSValue js_b2ExplosionDef_set_radius(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].radius=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ExplosionDef_get_falloff(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		float falloff=ptr[0].falloff;
		JSValue ret=JS_NewFloat64(ctx,((double)falloff));
		return ret;
	}
	
	static JSValue js_b2ExplosionDef_set_falloff(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].falloff=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ExplosionDef_get_impulsePerLength(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		float impulsePerLength=ptr[0].impulsePerLength;
		JSValue ret=JS_NewFloat64(ctx,((double)impulsePerLength));
		return ret;
	}
	
	static JSValue js_b2ExplosionDef_set_impulsePerLength(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ExplosionDef_class_id);
		b2ExplosionDef * ptr=(b2ExplosionDef  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].impulsePerLength=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ExplosionDef_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ExplosionDef", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("maskBits",js_b2ExplosionDef_get_maskBits,js_b2ExplosionDef_set_maskBits),
		JS_CGETSET_DEF("position",js_b2ExplosionDef_get_position,js_b2ExplosionDef_set_position),
		JS_CGETSET_DEF("radius",js_b2ExplosionDef_get_radius,js_b2ExplosionDef_set_radius),
		JS_CGETSET_DEF("falloff",js_b2ExplosionDef_get_falloff,js_b2ExplosionDef_set_falloff),
		JS_CGETSET_DEF("impulsePerLength",js_b2ExplosionDef_get_impulsePerLength,js_b2ExplosionDef_set_impulsePerLength)
	};
	
	static int js_declare_b2ExplosionDef(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ExplosionDef_class_id);
		JSClassDef js_b2ExplosionDef_def={ .class_name = "b2ExplosionDef", .finalizer = js_b2ExplosionDef_finalizer };
		JS_NewClass(rt,js_b2ExplosionDef_class_id,(const JSClassDef  *)&js_b2ExplosionDef_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ExplosionDef_proto_funcs,(int)countof(js_b2ExplosionDef_proto_funcs));
		JS_SetClassProto(ctx,js_b2ExplosionDef_class_id,proto);
		return 0;
	}
	
	static void js_b2SensorBeginTouchEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SensorBeginTouchEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SensorBeginTouchEvent_get_sensorShapeId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorBeginTouchEvent_class_id);
		b2SensorBeginTouchEvent * ptr=(b2SensorBeginTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * sensorShapeId=&ptr[0].sensorShapeId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)sensorShapeId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SensorBeginTouchEvent_set_sensorShapeId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorBeginTouchEvent_class_id);
		b2SensorBeginTouchEvent * ptr=(b2SensorBeginTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sensorShapeId=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SensorBeginTouchEvent_get_visitorShapeId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorBeginTouchEvent_class_id);
		b2SensorBeginTouchEvent * ptr=(b2SensorBeginTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * visitorShapeId=&ptr[0].visitorShapeId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)visitorShapeId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SensorBeginTouchEvent_set_visitorShapeId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorBeginTouchEvent_class_id);
		b2SensorBeginTouchEvent * ptr=(b2SensorBeginTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].visitorShapeId=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SensorBeginTouchEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SensorBeginTouchEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("sensorShapeId",js_b2SensorBeginTouchEvent_get_sensorShapeId,js_b2SensorBeginTouchEvent_set_sensorShapeId),
		JS_CGETSET_DEF("visitorShapeId",js_b2SensorBeginTouchEvent_get_visitorShapeId,js_b2SensorBeginTouchEvent_set_visitorShapeId)
	};
	
	static int js_declare_b2SensorBeginTouchEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SensorBeginTouchEvent_class_id);
		JSClassDef js_b2SensorBeginTouchEvent_def={ .class_name = "b2SensorBeginTouchEvent", .finalizer = js_b2SensorBeginTouchEvent_finalizer };
		JS_NewClass(rt,js_b2SensorBeginTouchEvent_class_id,(const JSClassDef  *)&js_b2SensorBeginTouchEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SensorBeginTouchEvent_proto_funcs,(int)countof(js_b2SensorBeginTouchEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2SensorBeginTouchEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2SensorEndTouchEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SensorEndTouchEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SensorEndTouchEvent_get_sensorShapeId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEndTouchEvent_class_id);
		b2SensorEndTouchEvent * ptr=(b2SensorEndTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * sensorShapeId=&ptr[0].sensorShapeId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)sensorShapeId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SensorEndTouchEvent_set_sensorShapeId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEndTouchEvent_class_id);
		b2SensorEndTouchEvent * ptr=(b2SensorEndTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].sensorShapeId=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SensorEndTouchEvent_get_visitorShapeId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEndTouchEvent_class_id);
		b2SensorEndTouchEvent * ptr=(b2SensorEndTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * visitorShapeId=&ptr[0].visitorShapeId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)visitorShapeId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2SensorEndTouchEvent_set_visitorShapeId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEndTouchEvent_class_id);
		b2SensorEndTouchEvent * ptr=(b2SensorEndTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].visitorShapeId=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SensorEndTouchEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SensorEndTouchEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("sensorShapeId",js_b2SensorEndTouchEvent_get_sensorShapeId,js_b2SensorEndTouchEvent_set_sensorShapeId),
		JS_CGETSET_DEF("visitorShapeId",js_b2SensorEndTouchEvent_get_visitorShapeId,js_b2SensorEndTouchEvent_set_visitorShapeId)
	};
	
	static int js_declare_b2SensorEndTouchEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SensorEndTouchEvent_class_id);
		JSClassDef js_b2SensorEndTouchEvent_def={ .class_name = "b2SensorEndTouchEvent", .finalizer = js_b2SensorEndTouchEvent_finalizer };
		JS_NewClass(rt,js_b2SensorEndTouchEvent_class_id,(const JSClassDef  *)&js_b2SensorEndTouchEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SensorEndTouchEvent_proto_funcs,(int)countof(js_b2SensorEndTouchEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2SensorEndTouchEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2SensorEvents_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2SensorEvents_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2SensorEvents_beginEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].beginCount;i++){
			b2SensorBeginTouchEvent * src0=(ptr[0].beginEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2SensorBeginTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2SensorEvents_beginEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		int length=ptr[0].beginCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2SensorEvents_beginEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].beginCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				b2SensorBeginTouchEvent * src=(ptr[0].beginEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2SensorBeginTouchEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2SensorEvents_beginEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				bool error=(bool)0;
				local_memlock=true;
				b2SensorBeginTouchEvent ret=js_getb2SensorBeginTouchEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].beginEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2SensorEvents_beginEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2SensorEvents_get_beginEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2SensorEvents_beginEvents_values,.keys = js_b2SensorEvents_beginEvents_keys,.get = js_b2SensorEvents_beginEvents_get,.set = js_b2SensorEvents_beginEvents_set,.has = js_b2SensorEvents_beginEvents_has});
		return ret;
	}
	
	static JSValue js_b2SensorEvents_set_beginEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2SensorBeginTouchEvent * value=js_getb2SensorBeginTouchEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].beginEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].beginEvents);
		ptr[0].beginEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SensorEvents_endEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].endCount;i++){
			b2SensorEndTouchEvent * src0=(ptr[0].endEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2SensorEndTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2SensorEvents_endEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		int length=ptr[0].endCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2SensorEvents_endEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].endCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].endCount){
				b2SensorEndTouchEvent * src=(ptr[0].endEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2SensorEndTouchEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2SensorEvents_endEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].endCount){
				bool error=(bool)0;
				local_memlock=true;
				b2SensorEndTouchEvent ret=js_getb2SensorEndTouchEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].endEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2SensorEvents_endEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2SensorEvents * ptr=(b2SensorEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].endCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2SensorEvents_get_endEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2SensorEvents_endEvents_values,.keys = js_b2SensorEvents_endEvents_keys,.get = js_b2SensorEvents_endEvents_get,.set = js_b2SensorEvents_endEvents_set,.has = js_b2SensorEvents_endEvents_has});
		return ret;
	}
	
	static JSValue js_b2SensorEvents_set_endEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2SensorEndTouchEvent * value=js_getb2SensorEndTouchEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].endEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].endEvents);
		ptr[0].endEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SensorEvents_get_beginCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		int beginCount=ptr[0].beginCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)beginCount));
		return ret;
	}
	
	static JSValue js_b2SensorEvents_set_beginCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].beginCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SensorEvents_get_endCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		int endCount=ptr[0].endCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)endCount));
		return ret;
	}
	
	static JSValue js_b2SensorEvents_set_endCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2SensorEvents_class_id);
		b2SensorEvents * ptr=(b2SensorEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].endCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2SensorEvents_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2SensorEvents", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("beginEvents",js_b2SensorEvents_get_beginEvents,js_b2SensorEvents_set_beginEvents),
		JS_CGETSET_DEF("endEvents",js_b2SensorEvents_get_endEvents,js_b2SensorEvents_set_endEvents),
		JS_CGETSET_DEF("beginCount",js_b2SensorEvents_get_beginCount,js_b2SensorEvents_set_beginCount),
		JS_CGETSET_DEF("endCount",js_b2SensorEvents_get_endCount,js_b2SensorEvents_set_endCount)
	};
	
	static int js_declare_b2SensorEvents(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2SensorEvents_class_id);
		JSClassDef js_b2SensorEvents_def={ .class_name = "b2SensorEvents", .finalizer = js_b2SensorEvents_finalizer };
		JS_NewClass(rt,js_b2SensorEvents_class_id,(const JSClassDef  *)&js_b2SensorEvents_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2SensorEvents_proto_funcs,(int)countof(js_b2SensorEvents_proto_funcs));
		JS_SetClassProto(ctx,js_b2SensorEvents_class_id,proto);
		return 0;
	}
	
	static void js_b2ContactBeginTouchEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ContactBeginTouchEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ContactBeginTouchEvent_get_shapeIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdA=&ptr[0].shapeIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_set_shapeIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_get_shapeIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdB=&ptr[0].shapeIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_set_shapeIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_get_manifold(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Manifold * manifold=&ptr[0].manifold;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)manifold,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_set_manifold(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactBeginTouchEvent_class_id);
		b2ContactBeginTouchEvent * ptr=(b2ContactBeginTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2Manifold value=js_getb2Manifold(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].manifold=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ContactBeginTouchEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ContactBeginTouchEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("shapeIdA",js_b2ContactBeginTouchEvent_get_shapeIdA,js_b2ContactBeginTouchEvent_set_shapeIdA),
		JS_CGETSET_DEF("shapeIdB",js_b2ContactBeginTouchEvent_get_shapeIdB,js_b2ContactBeginTouchEvent_set_shapeIdB),
		JS_CGETSET_DEF("manifold",js_b2ContactBeginTouchEvent_get_manifold,js_b2ContactBeginTouchEvent_set_manifold)
	};
	
	static int js_declare_b2ContactBeginTouchEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ContactBeginTouchEvent_class_id);
		JSClassDef js_b2ContactBeginTouchEvent_def={ .class_name = "b2ContactBeginTouchEvent", .finalizer = js_b2ContactBeginTouchEvent_finalizer };
		JS_NewClass(rt,js_b2ContactBeginTouchEvent_class_id,(const JSClassDef  *)&js_b2ContactBeginTouchEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ContactBeginTouchEvent_proto_funcs,(int)countof(js_b2ContactBeginTouchEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2ContactBeginTouchEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2ContactEndTouchEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ContactEndTouchEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ContactEndTouchEvent_get_shapeIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEndTouchEvent_class_id);
		b2ContactEndTouchEvent * ptr=(b2ContactEndTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdA=&ptr[0].shapeIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactEndTouchEvent_set_shapeIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEndTouchEvent_class_id);
		b2ContactEndTouchEvent * ptr=(b2ContactEndTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEndTouchEvent_get_shapeIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEndTouchEvent_class_id);
		b2ContactEndTouchEvent * ptr=(b2ContactEndTouchEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdB=&ptr[0].shapeIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactEndTouchEvent_set_shapeIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEndTouchEvent_class_id);
		b2ContactEndTouchEvent * ptr=(b2ContactEndTouchEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdB=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ContactEndTouchEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ContactEndTouchEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("shapeIdA",js_b2ContactEndTouchEvent_get_shapeIdA,js_b2ContactEndTouchEvent_set_shapeIdA),
		JS_CGETSET_DEF("shapeIdB",js_b2ContactEndTouchEvent_get_shapeIdB,js_b2ContactEndTouchEvent_set_shapeIdB)
	};
	
	static int js_declare_b2ContactEndTouchEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ContactEndTouchEvent_class_id);
		JSClassDef js_b2ContactEndTouchEvent_def={ .class_name = "b2ContactEndTouchEvent", .finalizer = js_b2ContactEndTouchEvent_finalizer };
		JS_NewClass(rt,js_b2ContactEndTouchEvent_class_id,(const JSClassDef  *)&js_b2ContactEndTouchEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ContactEndTouchEvent_proto_funcs,(int)countof(js_b2ContactEndTouchEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2ContactEndTouchEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2ContactHitEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ContactHitEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ContactHitEvent_get_shapeIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdA=&ptr[0].shapeIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactHitEvent_set_shapeIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactHitEvent_get_shapeIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdB=&ptr[0].shapeIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactHitEvent_set_shapeIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactHitEvent_get_point(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * point=&ptr[0].point;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)point,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactHitEvent_set_point(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].point=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactHitEvent_get_normal(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Vec2 * normal=&ptr[0].normal;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)normal,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactHitEvent_set_normal(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2Vec2 value=js_getb2Vec2(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].normal=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactHitEvent_get_approachSpeed(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		float approachSpeed=ptr[0].approachSpeed;
		JSValue ret=JS_NewFloat64(ctx,((double)approachSpeed));
		return ret;
	}
	
	static JSValue js_b2ContactHitEvent_set_approachSpeed(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactHitEvent_class_id);
		b2ContactHitEvent * ptr=(b2ContactHitEvent  *)shadow[0].ptr;
		local_memlock=true;
		float value=js_getfloat(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].approachSpeed=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ContactHitEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ContactHitEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("shapeIdA",js_b2ContactHitEvent_get_shapeIdA,js_b2ContactHitEvent_set_shapeIdA),
		JS_CGETSET_DEF("shapeIdB",js_b2ContactHitEvent_get_shapeIdB,js_b2ContactHitEvent_set_shapeIdB),
		JS_CGETSET_DEF("point",js_b2ContactHitEvent_get_point,js_b2ContactHitEvent_set_point),
		JS_CGETSET_DEF("normal",js_b2ContactHitEvent_get_normal,js_b2ContactHitEvent_set_normal),
		JS_CGETSET_DEF("approachSpeed",js_b2ContactHitEvent_get_approachSpeed,js_b2ContactHitEvent_set_approachSpeed)
	};
	
	static int js_declare_b2ContactHitEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ContactHitEvent_class_id);
		JSClassDef js_b2ContactHitEvent_def={ .class_name = "b2ContactHitEvent", .finalizer = js_b2ContactHitEvent_finalizer };
		JS_NewClass(rt,js_b2ContactHitEvent_class_id,(const JSClassDef  *)&js_b2ContactHitEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ContactHitEvent_proto_funcs,(int)countof(js_b2ContactHitEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2ContactHitEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2ContactEvents_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ContactEvents_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ContactEvents_beginEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].beginCount;i++){
			b2ContactBeginTouchEvent * src0=(ptr[0].beginEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2ContactBeginTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2ContactEvents_beginEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		int length=ptr[0].beginCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2ContactEvents_beginEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].beginCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				b2ContactBeginTouchEvent * src=(ptr[0].beginEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2ContactBeginTouchEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2ContactEvents_beginEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				bool error=(bool)0;
				local_memlock=true;
				b2ContactBeginTouchEvent ret=js_getb2ContactBeginTouchEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].beginEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2ContactEvents_beginEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].beginCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2ContactEvents_get_beginEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2ContactEvents_beginEvents_values,.keys = js_b2ContactEvents_beginEvents_keys,.get = js_b2ContactEvents_beginEvents_get,.set = js_b2ContactEvents_beginEvents_set,.has = js_b2ContactEvents_beginEvents_has});
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_beginEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2ContactBeginTouchEvent * value=js_getb2ContactBeginTouchEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].beginEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].beginEvents);
		ptr[0].beginEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEvents_endEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].endCount;i++){
			b2ContactEndTouchEvent * src0=(ptr[0].endEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2ContactEndTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2ContactEvents_endEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		int length=ptr[0].endCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2ContactEvents_endEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].endCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].endCount){
				b2ContactEndTouchEvent * src=(ptr[0].endEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2ContactEndTouchEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2ContactEvents_endEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].endCount){
				bool error=(bool)0;
				local_memlock=true;
				b2ContactEndTouchEvent ret=js_getb2ContactEndTouchEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].endEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2ContactEvents_endEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].endCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2ContactEvents_get_endEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2ContactEvents_endEvents_values,.keys = js_b2ContactEvents_endEvents_keys,.get = js_b2ContactEvents_endEvents_get,.set = js_b2ContactEvents_endEvents_set,.has = js_b2ContactEvents_endEvents_has});
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_endEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2ContactEndTouchEvent * value=js_getb2ContactEndTouchEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].endEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].endEvents);
		ptr[0].endEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEvents_hitEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].hitCount;i++){
			b2ContactHitEvent * src0=(ptr[0].hitEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2ContactHitEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2ContactEvents_hitEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		int length=ptr[0].hitCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2ContactEvents_hitEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].hitCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].hitCount){
				b2ContactHitEvent * src=(ptr[0].hitEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2ContactHitEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2ContactEvents_hitEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].hitCount){
				bool error=(bool)0;
				local_memlock=true;
				b2ContactHitEvent ret=js_getb2ContactHitEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].hitEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2ContactEvents_hitEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2ContactEvents * ptr=(b2ContactEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].hitCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2ContactEvents_get_hitEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2ContactEvents_hitEvents_values,.keys = js_b2ContactEvents_hitEvents_keys,.get = js_b2ContactEvents_hitEvents_get,.set = js_b2ContactEvents_hitEvents_set,.has = js_b2ContactEvents_hitEvents_has});
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_hitEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2ContactHitEvent * value=js_getb2ContactHitEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].hitEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].hitEvents);
		ptr[0].hitEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEvents_get_beginCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		int beginCount=ptr[0].beginCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)beginCount));
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_beginCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].beginCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEvents_get_endCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		int endCount=ptr[0].endCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)endCount));
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_endCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].endCount=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactEvents_get_hitCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		int hitCount=ptr[0].hitCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)hitCount));
		return ret;
	}
	
	static JSValue js_b2ContactEvents_set_hitCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactEvents_class_id);
		b2ContactEvents * ptr=(b2ContactEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].hitCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ContactEvents_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ContactEvents", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("beginEvents",js_b2ContactEvents_get_beginEvents,js_b2ContactEvents_set_beginEvents),
		JS_CGETSET_DEF("endEvents",js_b2ContactEvents_get_endEvents,js_b2ContactEvents_set_endEvents),
		JS_CGETSET_DEF("hitEvents",js_b2ContactEvents_get_hitEvents,js_b2ContactEvents_set_hitEvents),
		JS_CGETSET_DEF("beginCount",js_b2ContactEvents_get_beginCount,js_b2ContactEvents_set_beginCount),
		JS_CGETSET_DEF("endCount",js_b2ContactEvents_get_endCount,js_b2ContactEvents_set_endCount),
		JS_CGETSET_DEF("hitCount",js_b2ContactEvents_get_hitCount,js_b2ContactEvents_set_hitCount)
	};
	
	static int js_declare_b2ContactEvents(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ContactEvents_class_id);
		JSClassDef js_b2ContactEvents_def={ .class_name = "b2ContactEvents", .finalizer = js_b2ContactEvents_finalizer };
		JS_NewClass(rt,js_b2ContactEvents_class_id,(const JSClassDef  *)&js_b2ContactEvents_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ContactEvents_proto_funcs,(int)countof(js_b2ContactEvents_proto_funcs));
		JS_SetClassProto(ctx,js_b2ContactEvents_class_id,proto);
		return 0;
	}
	
	static void js_b2BodyMoveEvent_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2BodyMoveEvent_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2BodyMoveEvent_get_transform(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Transform * transform=&ptr[0].transform;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)transform,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2BodyMoveEvent_set_transform(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2Transform value=js_getb2Transform(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].transform=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyMoveEvent_get_bodyId(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2BodyId * bodyId=&ptr[0].bodyId;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)bodyId,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2BodyMoveEvent_set_bodyId(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyId value=js_getb2BodyId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].bodyId=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyMoveEvent_get_fellAsleep(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		bool fellAsleep=ptr[0].fellAsleep;
		JSValue ret=JS_NewBool(ctx,fellAsleep);
		return ret;
	}
	
	static JSValue js_b2BodyMoveEvent_set_fellAsleep(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyMoveEvent_class_id);
		b2BodyMoveEvent * ptr=(b2BodyMoveEvent  *)shadow[0].ptr;
		local_memlock=true;
		bool value=js_getbool(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].fellAsleep=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2BodyMoveEvent_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2BodyMoveEvent", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("transform",js_b2BodyMoveEvent_get_transform,js_b2BodyMoveEvent_set_transform),
		JS_CGETSET_DEF("bodyId",js_b2BodyMoveEvent_get_bodyId,js_b2BodyMoveEvent_set_bodyId),
		JS_CGETSET_DEF("userData",NULL,NULL),
		JS_CGETSET_DEF("fellAsleep",js_b2BodyMoveEvent_get_fellAsleep,js_b2BodyMoveEvent_set_fellAsleep)
	};
	
	static int js_declare_b2BodyMoveEvent(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2BodyMoveEvent_class_id);
		JSClassDef js_b2BodyMoveEvent_def={ .class_name = "b2BodyMoveEvent", .finalizer = js_b2BodyMoveEvent_finalizer };
		JS_NewClass(rt,js_b2BodyMoveEvent_class_id,(const JSClassDef  *)&js_b2BodyMoveEvent_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2BodyMoveEvent_proto_funcs,(int)countof(js_b2BodyMoveEvent_proto_funcs));
		JS_SetClassProto(ctx,js_b2BodyMoveEvent_class_id,proto);
		return 0;
	}
	
	static void js_b2BodyEvents_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2BodyEvents_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2BodyEvents_moveEvents_values(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2BodyEvents * ptr=(b2BodyEvents  *)ptr_u;
		JSValue ret=JS_NewArray(ctx);
		for(int i=0;i<ptr[0].moveCount;i++){
			b2BodyMoveEvent * src0=(ptr[0].moveEvents+i);
			JS_DupValue(ctx,(JSValueConst)anchor);
			opaqueShadow * ptr_ret1=create_shadow_with_external((void  *)src0,anchor);
			JSValue ret1=JS_NewObjectClass(ctx,js_b2BodyMoveEvent_class_id);
			JS_SetOpaque((JSValueConst)ret1,(void  *)ptr_ret1);
			JS_DefinePropertyValueUint32(ctx,(JSValueConst)ret,(uint32_t)i,ret1,JS_PROP_C_W_E);
		}
		if(as_sting==true){
			ret =JS_JSONStringify(ctx,(JSValueConst)ret,(JSValueConst)JS_UNDEFINED,(JSValueConst)JS_UNDEFINED);
		}
		return ret;
	}
	
	static int js_b2BodyEvents_moveEvents_keys(JSContext * ctx,void * ptr_u,JSPropertyEnum * * keys){
		b2BodyEvents * ptr=(b2BodyEvents  *)ptr_u;
		int length=ptr[0].moveCount;
		keys[0] =(JSPropertyEnum  *)js_malloc(ctx,(length+1)*sizeof(JSPropertyEnum));
		for(int i=0;i<length;i++){
			keys[0][i] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_NewAtomUInt32(ctx,i)};
		}
		keys[0][length] =(JSPropertyEnum){.is_enumerable=false, .atom=JS_ATOM_length};
		return true;
	}
	
	static JSValue js_b2BodyEvents_moveEvents_get(JSContext * ctx,JSValue anchor,void * ptr_u,int property,bool as_sting){
		b2BodyEvents * ptr=(b2BodyEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				JSValue ret=JS_NewInt32(ctx,(int32_t)((long)ptr[0].moveCount));
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}else{
			if(property>=0&&property<ptr[0].moveCount){
				b2BodyMoveEvent * src=(ptr[0].moveEvents+property);
				JS_DupValue(ctx,(JSValueConst)anchor);
				opaqueShadow * ptr_ret=create_shadow_with_external((void  *)src,anchor);
				JSValue ret=JS_NewObjectClass(ctx,js_b2BodyMoveEvent_class_id);
				JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
				return ret;
			}else{
				return JS_UNDEFINED;
			}
		}
	}
	
	static int js_b2BodyEvents_moveEvents_set(JSContext * ctx,void * ptr_u,JSValue set_to,int property,bool as_sting){
		b2BodyEvents * ptr=(b2BodyEvents  *)ptr_u;
		if(as_sting==true){
			return false;
		}else{
			if(property>=0&&property<ptr[0].moveCount){
				bool error=(bool)0;
				local_memlock=true;
				b2BodyMoveEvent ret=js_getb2BodyMoveEvent(ctx,set_to,&error);
				if(error==1)return 0;
				local_memlock=false;
				ptr[0].moveEvents[property]=ret;
				return true;
			}else{
				return false;
			}
		}
		return true;
	}
	
	static int js_b2BodyEvents_moveEvents_has(JSContext * ctx,void * ptr_u,int property,bool as_sting){
		b2BodyEvents * ptr=(b2BodyEvents  *)ptr_u;
		if(as_sting==true){
			if(property==JS_ATOM_length){
				return true;
			}else{
				return false;
			}
		}else{
			if(property>=0&&property<ptr[0].moveCount){
				return true;
			}else{
				return false;
			}
		}
	}
	
	static JSValue js_b2BodyEvents_get_moveEvents(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyEvents_class_id);
		b2BodyEvents * ptr=(b2BodyEvents  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		JSValue ret=js_NewArrayProxy(ctx,(ArrayProxy_class){.anchor = anchor,.opaque = ptr,.values = js_b2BodyEvents_moveEvents_values,.keys = js_b2BodyEvents_moveEvents_keys,.get = js_b2BodyEvents_moveEvents_get,.set = js_b2BodyEvents_moveEvents_set,.has = js_b2BodyEvents_moveEvents_has});
		return ret;
	}
	
	static JSValue js_b2BodyEvents_set_moveEvents(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyEvents_class_id);
		b2BodyEvents * ptr=(b2BodyEvents  *)shadow[0].ptr;
		local_memlock=true;
		b2BodyMoveEvent * value=js_getb2BodyMoveEvent_arrnc(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		if(ptr[0].moveEvents!=NULL)jsc_free(ctx,(void  *)ptr[0].moveEvents);
		ptr[0].moveEvents =value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2BodyEvents_get_moveCount(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyEvents_class_id);
		b2BodyEvents * ptr=(b2BodyEvents  *)shadow[0].ptr;
		int moveCount=ptr[0].moveCount;
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)moveCount));
		return ret;
	}
	
	static JSValue js_b2BodyEvents_set_moveCount(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2BodyEvents_class_id);
		b2BodyEvents * ptr=(b2BodyEvents  *)shadow[0].ptr;
		local_memlock=true;
		int value=js_getint(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].moveCount=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2BodyEvents_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2BodyEvents", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("moveEvents",js_b2BodyEvents_get_moveEvents,js_b2BodyEvents_set_moveEvents),
		JS_CGETSET_DEF("moveCount",js_b2BodyEvents_get_moveCount,js_b2BodyEvents_set_moveCount)
	};
	
	static int js_declare_b2BodyEvents(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2BodyEvents_class_id);
		JSClassDef js_b2BodyEvents_def={ .class_name = "b2BodyEvents", .finalizer = js_b2BodyEvents_finalizer };
		JS_NewClass(rt,js_b2BodyEvents_class_id,(const JSClassDef  *)&js_b2BodyEvents_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2BodyEvents_proto_funcs,(int)countof(js_b2BodyEvents_proto_funcs));
		JS_SetClassProto(ctx,js_b2BodyEvents_class_id,proto);
		return 0;
	}
	
	static void js_b2ContactData_finalizer(JSRuntime * rt,JSValue val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque((JSValueConst)val,js_b2ContactData_class_id);
		deallocate_shadow(rt,shadow);
	}
	
	static JSValue js_b2ContactData_get_shapeIdA(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdA=&ptr[0].shapeIdA;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdA,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactData_set_shapeIdA(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdA=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactData_get_shapeIdB(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2ShapeId * shapeIdB=&ptr[0].shapeIdB;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)shapeIdB,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactData_set_shapeIdB(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		local_memlock=true;
		b2ShapeId value=js_getb2ShapeId(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].shapeIdB=value;
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2ContactData_get_manifold(JSContext * ctx,JSValue this_val){
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		JSValue anchor;
		if(JS_IsUndefined(shadow[0].anchor)||JS_IsNull(shadow[0].anchor)){
			anchor=this_val;
		}else{
			anchor=shadow[0].anchor;
		}
		b2Manifold * manifold=&ptr[0].manifold;
		JS_DupValue(ctx,(JSValueConst)anchor);
		opaqueShadow * ptr_ret=create_shadow_with_external((void  *)manifold,anchor);
		JSValue ret=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ContactData_set_manifold(JSContext * ctx,JSValue this_val,JSValue v){
		bool error=(bool)0;
		opaqueShadow * shadow=(opaqueShadow  *)JS_GetOpaque2(ctx,(JSValueConst)this_val,js_b2ContactData_class_id);
		b2ContactData * ptr=(b2ContactData  *)shadow[0].ptr;
		local_memlock=true;
		b2Manifold value=js_getb2Manifold(ctx,v,&error);
		if(error==1)return JS_EXCEPTION;
		local_memlock=false;
		ptr[0].manifold=value;
		return JS_UNDEFINED;
	}
	static const JSCFunctionListEntry js_b2ContactData_proto_funcs[]={
		JS_PROP_STRING_DEF("[Symbol.toStringTag]","b2ContactData", JS_PROP_CONFIGURABLE),
		JS_CGETSET_DEF("shapeIdA",js_b2ContactData_get_shapeIdA,js_b2ContactData_set_shapeIdA),
		JS_CGETSET_DEF("shapeIdB",js_b2ContactData_get_shapeIdB,js_b2ContactData_set_shapeIdB),
		JS_CGETSET_DEF("manifold",js_b2ContactData_get_manifold,js_b2ContactData_set_manifold)
	};
	
	static int js_declare_b2ContactData(JSContext * ctx,JSModuleDef * m){
		JSRuntime * rt=JS_GetRuntime(ctx);
		JS_NewClassID(rt,&js_b2ContactData_class_id);
		JSClassDef js_b2ContactData_def={ .class_name = "b2ContactData", .finalizer = js_b2ContactData_finalizer };
		JS_NewClass(rt,js_b2ContactData_class_id,(const JSClassDef  *)&js_b2ContactData_def);
		JSValue proto=JS_NewObject(ctx);
		JS_SetPropertyFunctionList(ctx,(JSValueConst)proto,js_b2ContactData_proto_funcs,(int)countof(js_b2ContactData_proto_funcs));
		JS_SetClassProto(ctx,js_b2ContactData_class_id,proto);
		return 0;
	}
	static trampolineContext * b2FrictionCallback_arr=NULL;
	
	static float callback_b2FrictionCallback(float frictionA,int userMaterialIdA,float frictionB,int userMaterialIdB){
		JSValue func1;
		bool error=(bool)0;
		trampolineContext tctx=*b2FrictionCallback_arr;
		JSContext * ctx=tctx.ctx;
		JSValue js0=JS_NewFloat64(ctx,((double)frictionA));
		JSValue js1=JS_NewInt32(ctx,(int32_t)((long)userMaterialIdA));
		JSValue js2=JS_NewFloat64(ctx,((double)frictionB));
		JSValue js3=JS_NewInt32(ctx,(int32_t)((long)userMaterialIdB));
		JSValue argv[4]={
			js0,
			js1,
			js2,
			js3
		};
		JS_DupContext(ctx);
		JS_DupValue(ctx,(JSValueConst)tctx.func_obj);
		JSValue js_ret=JS_Call(ctx,(JSValueConst)tctx.func_obj,(JSValueConst)JS_UNDEFINED,(int)4,(JSValueConst  *)argv);
		JS_FreeValue(ctx,tctx.func_obj);
		JS_FreeContext(ctx);
		JS_FreeValue(ctx,argv[0]);
		JS_FreeValue(ctx,argv[1]);
		JS_FreeValue(ctx,argv[2]);
		JS_FreeValue(ctx,argv[3]);
		float resp=js_getfloat(ctx,js_ret,&error);
		if(error==1)return 0.0f;
		JS_FreeValue(ctx,js_ret);
		return resp;
	}
	static trampolineContext * b2RestitutionCallback_arr=NULL;
	
	static float callback_b2RestitutionCallback(float restitutionA,int userMaterialIdA,float restitutionB,int userMaterialIdB){
		JSValue func1;
		bool error=(bool)0;
		trampolineContext tctx=*b2RestitutionCallback_arr;
		JSContext * ctx=tctx.ctx;
		JSValue js0=JS_NewFloat64(ctx,((double)restitutionA));
		JSValue js1=JS_NewInt32(ctx,(int32_t)((long)userMaterialIdA));
		JSValue js2=JS_NewFloat64(ctx,((double)restitutionB));
		JSValue js3=JS_NewInt32(ctx,(int32_t)((long)userMaterialIdB));
		JSValue argv[4]={
			js0,
			js1,
			js2,
			js3
		};
		JS_DupContext(ctx);
		JS_DupValue(ctx,(JSValueConst)tctx.func_obj);
		JSValue js_ret=JS_Call(ctx,(JSValueConst)tctx.func_obj,(JSValueConst)JS_UNDEFINED,(int)4,(JSValueConst  *)argv);
		JS_FreeValue(ctx,tctx.func_obj);
		JS_FreeContext(ctx);
		JS_FreeValue(ctx,argv[0]);
		JS_FreeValue(ctx,argv[1]);
		JS_FreeValue(ctx,argv[2]);
		JS_FreeValue(ctx,argv[3]);
		float resp=js_getfloat(ctx,js_ret,&error);
		if(error==1)return 0.0f;
		JS_FreeValue(ctx,js_ret);
		return resp;
	}
	
	static JSValue js_b2Version_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Version));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Version_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Version _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Version_class_id){
			b2Version ptr=js_getb2Version(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int major=js_getint(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int minor=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			int revision=js_getint(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Version){
				major,
				minor,
				revision
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Version));
		b2Version * _returnptr=((b2Version *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Version_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Vec2_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Vec2));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Vec2 _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Vec2_class_id){
			b2Vec2 ptr=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float x=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float y=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Vec2){
				x,
				y
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * _returnptr=((b2Vec2 *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2CosSin_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2CosSin));
			JSValue _return=JS_NewObjectClass(ctx,js_b2CosSin_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2CosSin _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2CosSin_class_id){
			b2CosSin ptr=js_getb2CosSin(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float cosine=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float sine=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2CosSin){
				cosine,
				sine
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2CosSin));
		b2CosSin * _returnptr=((b2CosSin *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2CosSin_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Rot_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Rot));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Rot_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Rot _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Rot_class_id){
			b2Rot ptr=js_getb2Rot(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float c=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float s=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Rot){
				c,
				s
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * _returnptr=((b2Rot *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Transform_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Transform));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Transform_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Transform _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Transform_class_id){
			b2Transform ptr=js_getb2Transform(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 p=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Rot q=js_getb2Rot(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Transform){
				p,
				q
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Transform));
		b2Transform * _returnptr=((b2Transform *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Mat22_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Mat22));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Mat22_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Mat22 _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Mat22_class_id){
			b2Mat22 ptr=js_getb2Mat22(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 cx=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 cy=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Mat22){
				cx,
				cy
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Mat22));
		b2Mat22 * _returnptr=((b2Mat22 *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Mat22_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2AABB_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2AABB));
			JSValue _return=JS_NewObjectClass(ctx,js_b2AABB_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2AABB _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2AABB_class_id){
			b2AABB ptr=js_getb2AABB(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 lowerBound=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 upperBound=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2AABB){
				lowerBound,
				upperBound
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * _returnptr=((b2AABB *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Plane_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Plane));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Plane_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Plane _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Plane_class_id){
			b2Plane ptr=js_getb2Plane(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 normal=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float offset=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Plane){
				normal,
				offset
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Plane));
		b2Plane * _returnptr=((b2Plane *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Plane_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SimplexCache_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SimplexCache));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SimplexCache_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SimplexCache _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SimplexCache_class_id){
			b2SimplexCache ptr=js_getb2SimplexCache(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			uint16_t count=js_getuint16_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint8_t * indexA=js_getuint8_t_arr3nc(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			uint8_t * indexB=js_getuint8_t_arr3nc(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SimplexCache){
				count,
				{indexA[0],indexA[1],indexA[2]},
				{indexB[0],indexB[1],indexB[2]}
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SimplexCache));
		b2SimplexCache * _returnptr=((b2SimplexCache *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SimplexCache_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Hull_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Hull));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Hull_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Hull _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Hull_class_id){
			b2Hull ptr=js_getb2Hull(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			_struct =(b2Hull){
				
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Hull));
		b2Hull * _returnptr=((b2Hull *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Hull_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2RayCastInput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2RayCastInput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2RayCastInput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2RayCastInput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2RayCastInput_class_id){
			b2RayCastInput ptr=js_getb2RayCastInput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 origin=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 translation=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float maxFraction=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2RayCastInput){
				origin,
				translation,
				maxFraction
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2RayCastInput));
		b2RayCastInput * _returnptr=((b2RayCastInput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2RayCastInput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ShapeProxy_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ShapeProxy));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ShapeProxy _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ShapeProxy_class_id){
			b2ShapeProxy ptr=js_getb2ShapeProxy(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			_struct =(b2ShapeProxy){
				
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ShapeProxy));
		b2ShapeProxy * _returnptr=((b2ShapeProxy *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ShapeCastInput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ShapeCastInput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeCastInput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ShapeCastInput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ShapeCastInput_class_id){
			b2ShapeCastInput ptr=js_getb2ShapeCastInput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeProxy proxy=js_getb2ShapeProxy(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 translation=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float maxFraction=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			bool canEncroach=js_getbool(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ShapeCastInput){
				proxy,
				translation,
				maxFraction,
				canEncroach
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ShapeCastInput));
		b2ShapeCastInput * _returnptr=((b2ShapeCastInput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeCastInput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2CastOutput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2CastOutput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2CastOutput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2CastOutput_class_id){
			b2CastOutput ptr=js_getb2CastOutput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 normal=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 point=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float fraction=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int iterations=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			bool hit=js_getbool(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2CastOutput){
				normal,
				point,
				fraction,
				iterations,
				hit
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * _returnptr=((b2CastOutput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2MassData_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2MassData));
			JSValue _return=JS_NewObjectClass(ctx,js_b2MassData_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2MassData _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2MassData_class_id){
			b2MassData ptr=js_getb2MassData(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float mass=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 center=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float rotationalInertia=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2MassData){
				mass,
				center,
				rotationalInertia
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * _returnptr=((b2MassData *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Circle_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Circle));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Circle_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Circle _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Circle_class_id){
			b2Circle ptr=js_getb2Circle(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 center=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float radius=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Circle){
				center,
				radius
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Circle));
		b2Circle * _returnptr=((b2Circle *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Circle_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Capsule_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Capsule));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Capsule_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Capsule _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Capsule_class_id){
			b2Capsule ptr=js_getb2Capsule(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 center1=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 center2=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float radius=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Capsule){
				center1,
				center2,
				radius
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Capsule));
		b2Capsule * _returnptr=((b2Capsule *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Capsule_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Polygon_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Polygon));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Polygon _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Polygon_class_id){
			b2Polygon ptr=js_getb2Polygon(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			_struct =(b2Polygon){
				
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * _returnptr=((b2Polygon *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Segment_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Segment));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Segment_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Segment _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Segment_class_id){
			b2Segment ptr=js_getb2Segment(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 point1=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 point2=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Segment){
				point1,
				point2
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Segment));
		b2Segment * _returnptr=((b2Segment *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Segment_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ChainSegment_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ChainSegment));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ChainSegment_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ChainSegment _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ChainSegment_class_id){
			b2ChainSegment ptr=js_getb2ChainSegment(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 ghost1=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Segment segment=js_getb2Segment(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 ghost2=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int chainId=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ChainSegment){
				ghost1,
				segment,
				ghost2,
				chainId
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ChainSegment));
		b2ChainSegment * _returnptr=((b2ChainSegment *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ChainSegment_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SegmentDistanceResult_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SegmentDistanceResult));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SegmentDistanceResult_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SegmentDistanceResult _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SegmentDistanceResult_class_id){
			b2SegmentDistanceResult ptr=js_getb2SegmentDistanceResult(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 closest1=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 closest2=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float fraction1=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float fraction2=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float distanceSquared=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SegmentDistanceResult){
				closest1,
				closest2,
				fraction1,
				fraction2,
				distanceSquared
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SegmentDistanceResult));
		b2SegmentDistanceResult * _returnptr=((b2SegmentDistanceResult *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SegmentDistanceResult_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2DistanceInput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2DistanceInput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceInput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2DistanceInput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2DistanceInput_class_id){
			b2DistanceInput ptr=js_getb2DistanceInput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeProxy proxyA=js_getb2ShapeProxy(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeProxy proxyB=js_getb2ShapeProxy(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Transform transformA=js_getb2Transform(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Transform transformB=js_getb2Transform(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			bool useRadii=js_getbool(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2DistanceInput){
				proxyA,
				proxyB,
				transformA,
				transformB,
				useRadii
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2DistanceInput));
		b2DistanceInput * _returnptr=((b2DistanceInput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceInput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2DistanceOutput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2DistanceOutput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceOutput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2DistanceOutput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2DistanceOutput_class_id){
			b2DistanceOutput ptr=js_getb2DistanceOutput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 pointA=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 pointB=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 normal=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float distance=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int iterations=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			int simplexCount=js_getint(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2DistanceOutput){
				pointA,
				pointB,
				normal,
				distance,
				iterations,
				simplexCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2DistanceOutput));
		b2DistanceOutput * _returnptr=((b2DistanceOutput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceOutput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SimplexVertex_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SimplexVertex));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SimplexVertex_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SimplexVertex _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SimplexVertex_class_id){
			b2SimplexVertex ptr=js_getb2SimplexVertex(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 wA=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 wB=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 w=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float a=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int indexA=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			int indexB=js_getint(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SimplexVertex){
				wA,
				wB,
				w,
				a,
				indexA,
				indexB
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SimplexVertex));
		b2SimplexVertex * _returnptr=((b2SimplexVertex *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SimplexVertex_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Simplex_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Simplex));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Simplex_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Simplex _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Simplex_class_id){
			b2Simplex ptr=js_getb2Simplex(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2SimplexVertex v1=js_getb2SimplexVertex(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2SimplexVertex v2=js_getb2SimplexVertex(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2SimplexVertex v3=js_getb2SimplexVertex(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int count=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Simplex){
				v1,
				v2,
				v3,
				count
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Simplex));
		b2Simplex * _returnptr=((b2Simplex *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Simplex_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ShapeCastPairInput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ShapeCastPairInput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeCastPairInput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ShapeCastPairInput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ShapeCastPairInput_class_id){
			b2ShapeCastPairInput ptr=js_getb2ShapeCastPairInput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeProxy proxyA=js_getb2ShapeProxy(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeProxy proxyB=js_getb2ShapeProxy(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Transform transformA=js_getb2Transform(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Transform transformB=js_getb2Transform(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 translationB=js_getb2Vec2(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float maxFraction=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool canEncroach=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ShapeCastPairInput){
				proxyA,
				proxyB,
				transformA,
				transformB,
				translationB,
				maxFraction,
				canEncroach
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ShapeCastPairInput));
		b2ShapeCastPairInput * _returnptr=((b2ShapeCastPairInput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeCastPairInput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Sweep_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Sweep));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Sweep_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Sweep _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Sweep_class_id){
			b2Sweep ptr=js_getb2Sweep(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 localCenter=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 c1=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 c2=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Rot q1=js_getb2Rot(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			b2Rot q2=js_getb2Rot(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Sweep){
				localCenter,
				c1,
				c2,
				q1,
				q2
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Sweep));
		b2Sweep * _returnptr=((b2Sweep *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Sweep_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2TOIInput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2TOIInput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2TOIInput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2TOIInput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2TOIInput_class_id){
			b2TOIInput ptr=js_getb2TOIInput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeProxy proxyA=js_getb2ShapeProxy(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeProxy proxyB=js_getb2ShapeProxy(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Sweep sweepA=js_getb2Sweep(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Sweep sweepB=js_getb2Sweep(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float maxFraction=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2TOIInput){
				proxyA,
				proxyB,
				sweepA,
				sweepB,
				maxFraction
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2TOIInput));
		b2TOIInput * _returnptr=((b2TOIInput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2TOIInput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2TOIOutput_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2TOIOutput));
			JSValue _return=JS_NewObjectClass(ctx,js_b2TOIOutput_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2TOIOutput _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2TOIOutput_class_id){
			b2TOIOutput ptr=js_getb2TOIOutput(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2TOIState state=js_getb2TOIState(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float fraction=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2TOIOutput){
				state,
				fraction
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2TOIOutput));
		b2TOIOutput * _returnptr=((b2TOIOutput *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2TOIOutput_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ManifoldPoint_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ManifoldPoint));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ManifoldPoint_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ManifoldPoint _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ManifoldPoint_class_id){
			b2ManifoldPoint ptr=js_getb2ManifoldPoint(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 point=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 anchorA=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 anchorB=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float separation=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float normalImpulse=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float tangentImpulse=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float totalNormalImpulse=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float normalVelocity=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t id=js_getuint16_t(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			bool persisted=js_getbool(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ManifoldPoint){
				point,
				anchorA,
				anchorB,
				separation,
				normalImpulse,
				tangentImpulse,
				totalNormalImpulse,
				normalVelocity,
				id,
				persisted
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ManifoldPoint));
		b2ManifoldPoint * _returnptr=((b2ManifoldPoint *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ManifoldPoint_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Manifold_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Manifold));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Manifold _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Manifold_class_id){
			b2Manifold ptr=js_getb2Manifold(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 normal=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float rollingImpulse=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2ManifoldPoint * points=js_getb2ManifoldPoint_arr2nc(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int pointCount=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Manifold){
				normal,
				rollingImpulse,
				{points[0],points[1]},
				pointCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Manifold));
		b2Manifold * _returnptr=((b2Manifold *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2TreeStats_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2TreeStats));
			JSValue _return=JS_NewObjectClass(ctx,js_b2TreeStats_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2TreeStats _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2TreeStats_class_id){
			b2TreeStats ptr=js_getb2TreeStats(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int nodeVisits=js_getint(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int leafVisits=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2TreeStats){
				nodeVisits,
				leafVisits
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2TreeStats));
		b2TreeStats * _returnptr=((b2TreeStats *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2TreeStats_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2PlaneResult_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2PlaneResult));
			JSValue _return=JS_NewObjectClass(ctx,js_b2PlaneResult_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2PlaneResult _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2PlaneResult_class_id){
			b2PlaneResult ptr=js_getb2PlaneResult(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Plane plane=js_getb2Plane(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 point=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			bool hit=js_getbool(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2PlaneResult){
				plane,
				point,
				hit
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2PlaneResult));
		b2PlaneResult * _returnptr=((b2PlaneResult *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2PlaneResult_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2CollisionPlane_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2CollisionPlane));
			JSValue _return=JS_NewObjectClass(ctx,js_b2CollisionPlane_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2CollisionPlane _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2CollisionPlane_class_id){
			b2CollisionPlane ptr=js_getb2CollisionPlane(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Plane plane=js_getb2Plane(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float pushLimit=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float push=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			bool clipVelocity=js_getbool(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2CollisionPlane){
				plane,
				pushLimit,
				push,
				clipVelocity
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2CollisionPlane));
		b2CollisionPlane * _returnptr=((b2CollisionPlane *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2CollisionPlane_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2PlaneSolverResult_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2PlaneSolverResult));
			JSValue _return=JS_NewObjectClass(ctx,js_b2PlaneSolverResult_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2PlaneSolverResult _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2PlaneSolverResult_class_id){
			b2PlaneSolverResult ptr=js_getb2PlaneSolverResult(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 translation=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int iterationCount=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2PlaneSolverResult){
				translation,
				iterationCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2PlaneSolverResult));
		b2PlaneSolverResult * _returnptr=((b2PlaneSolverResult *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2PlaneSolverResult_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2WorldId_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2WorldId));
			JSValue _return=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2WorldId _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2WorldId_class_id){
			b2WorldId ptr=js_getb2WorldId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			uint16_t index1=js_getuint16_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t generation=js_getuint16_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2WorldId){
				index1,
				generation
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * _returnptr=((b2WorldId *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2BodyId_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2BodyId));
			JSValue _return=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2BodyId _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2BodyId_class_id){
			b2BodyId ptr=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int32_t index1=js_getint32_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t world0=js_getuint16_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t generation=js_getuint16_t(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2BodyId){
				index1,
				world0,
				generation
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * _returnptr=((b2BodyId *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ShapeId_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ShapeId));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ShapeId _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ShapeId_class_id){
			b2ShapeId ptr=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int32_t index1=js_getint32_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t world0=js_getuint16_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t generation=js_getuint16_t(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ShapeId){
				index1,
				world0,
				generation
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * _returnptr=((b2ShapeId *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ChainId_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ChainId));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ChainId_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ChainId _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ChainId_class_id){
			b2ChainId ptr=js_getb2ChainId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int32_t index1=js_getint32_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t world0=js_getuint16_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t generation=js_getuint16_t(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ChainId){
				index1,
				world0,
				generation
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ChainId));
		b2ChainId * _returnptr=((b2ChainId *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ChainId_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2JointId_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2JointId));
			JSValue _return=JS_NewObjectClass(ctx,js_b2JointId_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2JointId _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2JointId_class_id){
			b2JointId ptr=js_getb2JointId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int32_t index1=js_getint32_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t world0=js_getuint16_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			uint16_t generation=js_getuint16_t(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2JointId){
				index1,
				world0,
				generation
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * _returnptr=((b2JointId *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2RayResult_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2RayResult));
			JSValue _return=JS_NewObjectClass(ctx,js_b2RayResult_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2RayResult _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2RayResult_class_id){
			b2RayResult ptr=js_getb2RayResult(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 point=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 normal=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float fraction=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int nodeVisits=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			int leafVisits=js_getint(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool hit=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2RayResult){
				shapeId,
				point,
				normal,
				fraction,
				nodeVisits,
				leafVisits,
				hit
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2RayResult));
		b2RayResult * _returnptr=((b2RayResult *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2RayResult_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2WorldDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2WorldDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2WorldDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2WorldDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2WorldDef_class_id){
			b2WorldDef ptr=js_getb2WorldDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Vec2 gravity=js_getb2Vec2(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float restitutionThreshold=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float hitEventThreshold=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float contactHertz=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float contactDampingRatio=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float maxContactPushSpeed=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float maximumLinearSpeed=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSleep=js_getbool(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableContinuous=js_getbool(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			int workerCount=js_getint(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2WorldDef){
				gravity,
				restitutionThreshold,
				hitEventThreshold,
				contactHertz,
				contactDampingRatio,
				maxContactPushSpeed,
				maximumLinearSpeed,
				0,
				0,
				enableSleep,
				enableContinuous,
				workerCount,
				0,
				0,
				0,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2WorldDef));
		b2WorldDef * _returnptr=((b2WorldDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2WorldDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2BodyDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2BodyDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2BodyDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2BodyDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2BodyDef_class_id){
			b2BodyDef ptr=js_getb2BodyDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyType type=js_getb2BodyType(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 position=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Rot rotation=js_getb2Rot(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 linearVelocity=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float angularVelocity=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float linearDamping=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float angularDamping=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float gravityScale=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			float sleepThreshold=js_getfloat(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			char * name=js_getchar_arrnc(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSleep=js_getbool(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			bool isAwake=js_getbool(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			bool fixedRotation=js_getbool(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			bool isBullet=js_getbool(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			bool isEnabled=js_getbool(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			bool allowFastRotation=js_getbool(ctx,argv[15],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2BodyDef){
				type,
				position,
				rotation,
				linearVelocity,
				angularVelocity,
				linearDamping,
				angularDamping,
				gravityScale,
				sleepThreshold,
				name,
				0,
				enableSleep,
				isAwake,
				fixedRotation,
				isBullet,
				isEnabled,
				allowFastRotation,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2BodyDef));
		b2BodyDef * _returnptr=((b2BodyDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2BodyDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Filter_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Filter));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Filter_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Filter _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Filter_class_id){
			b2Filter ptr=js_getb2Filter(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			uint64_t categoryBits=js_getuint64_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint64_t maskBits=js_getuint64_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			int groupIndex=js_getint(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Filter){
				categoryBits,
				maskBits,
				groupIndex
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Filter));
		b2Filter * _returnptr=((b2Filter *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Filter_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2QueryFilter_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2QueryFilter));
			JSValue _return=JS_NewObjectClass(ctx,js_b2QueryFilter_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2QueryFilter _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2QueryFilter_class_id){
			b2QueryFilter ptr=js_getb2QueryFilter(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			uint64_t categoryBits=js_getuint64_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			uint64_t maskBits=js_getuint64_t(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2QueryFilter){
				categoryBits,
				maskBits
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2QueryFilter));
		b2QueryFilter * _returnptr=((b2QueryFilter *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2QueryFilter_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SurfaceMaterial_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SurfaceMaterial));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SurfaceMaterial _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SurfaceMaterial_class_id){
			b2SurfaceMaterial ptr=js_getb2SurfaceMaterial(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float friction=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float restitution=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float rollingResistance=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float tangentSpeed=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int userMaterialId=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			uint32_t customColor=js_getuint32_t(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SurfaceMaterial){
				friction,
				restitution,
				rollingResistance,
				tangentSpeed,
				userMaterialId,
				customColor
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SurfaceMaterial));
		b2SurfaceMaterial * _returnptr=((b2SurfaceMaterial *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ShapeDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ShapeDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ShapeDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ShapeDef_class_id){
			b2ShapeDef ptr=js_getb2ShapeDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2SurfaceMaterial material=js_getb2SurfaceMaterial(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float density=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Filter filter=js_getb2Filter(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			bool isSensor=js_getbool(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSensorEvents=js_getbool(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableContactEvents=js_getbool(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableHitEvents=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			bool enablePreSolveEvents=js_getbool(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			bool invokeContactCreation=js_getbool(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			bool updateBodyMass=js_getbool(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ShapeDef){
				0,
				material,
				density,
				filter,
				isSensor,
				enableSensorEvents,
				enableContactEvents,
				enableHitEvents,
				enablePreSolveEvents,
				invokeContactCreation,
				updateBodyMass,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ShapeDef));
		b2ShapeDef * _returnptr=((b2ShapeDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ShapeDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ChainDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ChainDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ChainDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ChainDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ChainDef_class_id){
			b2ChainDef ptr=js_getb2ChainDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =b2ChainDef_copy(ctx,ptr);
		}else{
			b2Vec2 * points=js_getb2Vec2_arrnc(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int count=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2SurfaceMaterial * materials=js_getb2SurfaceMaterial_arrnc(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int materialCount=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			b2Filter filter=js_getb2Filter(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			bool isLoop=js_getbool(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSensorEvents=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ChainDef){
				0,
				points,
				count,
				materials,
				materialCount,
				filter,
				isLoop,
				enableSensorEvents,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ChainDef));
		b2ChainDef * _returnptr=((b2ChainDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ChainDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Profile_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Profile));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Profile_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Profile _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Profile_class_id){
			b2Profile ptr=js_getb2Profile(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			float step=js_getfloat(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			float pairs=js_getfloat(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float collide=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float solve=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float mergeIslands=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float prepareStages=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float solveConstraints=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float prepareConstraints=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			float integrateVelocities=js_getfloat(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			float warmStart=js_getfloat(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			float solveImpulses=js_getfloat(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			float integratePositions=js_getfloat(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			float relaxImpulses=js_getfloat(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			float applyRestitution=js_getfloat(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			float storeImpulses=js_getfloat(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			float splitIslands=js_getfloat(ctx,argv[15],&error);
			if(error==1)return JS_EXCEPTION;
			float transforms=js_getfloat(ctx,argv[16],&error);
			if(error==1)return JS_EXCEPTION;
			float hitEvents=js_getfloat(ctx,argv[17],&error);
			if(error==1)return JS_EXCEPTION;
			float refit=js_getfloat(ctx,argv[18],&error);
			if(error==1)return JS_EXCEPTION;
			float bullets=js_getfloat(ctx,argv[19],&error);
			if(error==1)return JS_EXCEPTION;
			float sleepIslands=js_getfloat(ctx,argv[20],&error);
			if(error==1)return JS_EXCEPTION;
			float sensors=js_getfloat(ctx,argv[21],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Profile){
				step,
				pairs,
				collide,
				solve,
				mergeIslands,
				prepareStages,
				solveConstraints,
				prepareConstraints,
				integrateVelocities,
				warmStart,
				solveImpulses,
				integratePositions,
				relaxImpulses,
				applyRestitution,
				storeImpulses,
				splitIslands,
				transforms,
				hitEvents,
				refit,
				bullets,
				sleepIslands,
				sensors
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Profile));
		b2Profile * _returnptr=((b2Profile *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Profile_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2Counters_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2Counters));
			JSValue _return=JS_NewObjectClass(ctx,js_b2Counters_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2Counters _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2Counters_class_id){
			b2Counters ptr=js_getb2Counters(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			int bodyCount=js_getint(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int shapeCount=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			int contactCount=js_getint(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int jointCount=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int islandCount=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			int stackUsed=js_getint(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			int staticTreeHeight=js_getint(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			int treeHeight=js_getint(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			int byteCount=js_getint(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			int taskCount=js_getint(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			int * colorCounts=js_getint_arr12nc(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2Counters){
				bodyCount,
				shapeCount,
				contactCount,
				jointCount,
				islandCount,
				stackUsed,
				staticTreeHeight,
				treeHeight,
				byteCount,
				taskCount,
				{colorCounts[0],colorCounts[1],colorCounts[2],colorCounts[3],colorCounts[4],colorCounts[5],colorCounts[6],colorCounts[7],colorCounts[8],colorCounts[9],colorCounts[10],colorCounts[11]}
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2Counters));
		b2Counters * _returnptr=((b2Counters *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2Counters_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2DistanceJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2DistanceJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2DistanceJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2DistanceJointDef_class_id){
			b2DistanceJointDef ptr=js_getb2DistanceJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorA=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorB=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float length=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSpring=js_getbool(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float hertz=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float dampingRatio=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableLimit=js_getbool(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			float minLength=js_getfloat(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			float maxLength=js_getfloat(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableMotor=js_getbool(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			float maxMotorForce=js_getfloat(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			float motorSpeed=js_getfloat(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2DistanceJointDef){
				bodyIdA,
				bodyIdB,
				localAnchorA,
				localAnchorB,
				length,
				enableSpring,
				hertz,
				dampingRatio,
				enableLimit,
				minLength,
				maxLength,
				enableMotor,
				maxMotorForce,
				motorSpeed,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2DistanceJointDef));
		b2DistanceJointDef * _returnptr=((b2DistanceJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2DistanceJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2MotorJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2MotorJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2MotorJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2MotorJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2MotorJointDef_class_id){
			b2MotorJointDef ptr=js_getb2MotorJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 linearOffset=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float angularOffset=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float maxForce=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float maxTorque=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float correctionFactor=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2MotorJointDef){
				bodyIdA,
				bodyIdB,
				linearOffset,
				angularOffset,
				maxForce,
				maxTorque,
				correctionFactor,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2MotorJointDef));
		b2MotorJointDef * _returnptr=((b2MotorJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2MotorJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2MouseJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2MouseJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2MouseJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2MouseJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2MouseJointDef_class_id){
			b2MouseJointDef ptr=js_getb2MouseJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 target=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float hertz=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float dampingRatio=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float maxForce=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2MouseJointDef){
				bodyIdA,
				bodyIdB,
				target,
				hertz,
				dampingRatio,
				maxForce,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2MouseJointDef));
		b2MouseJointDef * _returnptr=((b2MouseJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2MouseJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2FilterJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2FilterJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2FilterJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2FilterJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2FilterJointDef_class_id){
			b2FilterJointDef ptr=js_getb2FilterJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2FilterJointDef){
				bodyIdA,
				bodyIdB,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2FilterJointDef));
		b2FilterJointDef * _returnptr=((b2FilterJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2FilterJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2PrismaticJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2PrismaticJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2PrismaticJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2PrismaticJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2PrismaticJointDef_class_id){
			b2PrismaticJointDef ptr=js_getb2PrismaticJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorA=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorB=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAxisA=js_getb2Vec2(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float referenceAngle=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float targetTranslation=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSpring=js_getbool(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			float hertz=js_getfloat(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			float dampingRatio=js_getfloat(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableLimit=js_getbool(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			float lowerTranslation=js_getfloat(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			float upperTranslation=js_getfloat(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableMotor=js_getbool(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			float maxMotorForce=js_getfloat(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			float motorSpeed=js_getfloat(ctx,argv[15],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[16],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2PrismaticJointDef){
				bodyIdA,
				bodyIdB,
				localAnchorA,
				localAnchorB,
				localAxisA,
				referenceAngle,
				targetTranslation,
				enableSpring,
				hertz,
				dampingRatio,
				enableLimit,
				lowerTranslation,
				upperTranslation,
				enableMotor,
				maxMotorForce,
				motorSpeed,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2PrismaticJointDef));
		b2PrismaticJointDef * _returnptr=((b2PrismaticJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2PrismaticJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2RevoluteJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2RevoluteJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2RevoluteJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2RevoluteJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2RevoluteJointDef_class_id){
			b2RevoluteJointDef ptr=js_getb2RevoluteJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorA=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorB=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float referenceAngle=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float targetAngle=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSpring=js_getbool(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float hertz=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			float dampingRatio=js_getfloat(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableLimit=js_getbool(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			float lowerAngle=js_getfloat(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			float upperAngle=js_getfloat(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableMotor=js_getbool(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			float maxMotorTorque=js_getfloat(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			float motorSpeed=js_getfloat(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			float drawSize=js_getfloat(ctx,argv[15],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[16],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2RevoluteJointDef){
				bodyIdA,
				bodyIdB,
				localAnchorA,
				localAnchorB,
				referenceAngle,
				targetAngle,
				enableSpring,
				hertz,
				dampingRatio,
				enableLimit,
				lowerAngle,
				upperAngle,
				enableMotor,
				maxMotorTorque,
				motorSpeed,
				drawSize,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2RevoluteJointDef));
		b2RevoluteJointDef * _returnptr=((b2RevoluteJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2RevoluteJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2WeldJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2WeldJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2WeldJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2WeldJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2WeldJointDef_class_id){
			b2WeldJointDef ptr=js_getb2WeldJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorA=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorB=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float referenceAngle=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			float linearHertz=js_getfloat(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float angularHertz=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float linearDampingRatio=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			float angularDampingRatio=js_getfloat(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2WeldJointDef){
				bodyIdA,
				bodyIdB,
				localAnchorA,
				localAnchorB,
				referenceAngle,
				linearHertz,
				angularHertz,
				linearDampingRatio,
				angularDampingRatio,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2WeldJointDef));
		b2WeldJointDef * _returnptr=((b2WeldJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2WeldJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2WheelJointDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2WheelJointDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2WheelJointDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2WheelJointDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2WheelJointDef_class_id){
			b2WheelJointDef ptr=js_getb2WheelJointDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2BodyId bodyIdA=js_getb2BodyId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyIdB=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorA=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAnchorB=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 localAxisA=js_getb2Vec2(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableSpring=js_getbool(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			float hertz=js_getfloat(ctx,argv[6],&error);
			if(error==1)return JS_EXCEPTION;
			float dampingRatio=js_getfloat(ctx,argv[7],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableLimit=js_getbool(ctx,argv[8],&error);
			if(error==1)return JS_EXCEPTION;
			float lowerTranslation=js_getfloat(ctx,argv[9],&error);
			if(error==1)return JS_EXCEPTION;
			float upperTranslation=js_getfloat(ctx,argv[10],&error);
			if(error==1)return JS_EXCEPTION;
			bool enableMotor=js_getbool(ctx,argv[11],&error);
			if(error==1)return JS_EXCEPTION;
			float maxMotorTorque=js_getfloat(ctx,argv[12],&error);
			if(error==1)return JS_EXCEPTION;
			float motorSpeed=js_getfloat(ctx,argv[13],&error);
			if(error==1)return JS_EXCEPTION;
			bool collideConnected=js_getbool(ctx,argv[14],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2WheelJointDef){
				bodyIdA,
				bodyIdB,
				localAnchorA,
				localAnchorB,
				localAxisA,
				enableSpring,
				hertz,
				dampingRatio,
				enableLimit,
				lowerTranslation,
				upperTranslation,
				enableMotor,
				maxMotorTorque,
				motorSpeed,
				collideConnected,
				0,
				0
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2WheelJointDef));
		b2WheelJointDef * _returnptr=((b2WheelJointDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2WheelJointDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ExplosionDef_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ExplosionDef));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ExplosionDef_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ExplosionDef _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ExplosionDef_class_id){
			b2ExplosionDef ptr=js_getb2ExplosionDef(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			uint64_t maskBits=js_getuint64_t(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 position=js_getb2Vec2(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			float radius=js_getfloat(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			float falloff=js_getfloat(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float impulsePerLength=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ExplosionDef){
				maskBits,
				position,
				radius,
				falloff,
				impulsePerLength
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ExplosionDef));
		b2ExplosionDef * _returnptr=((b2ExplosionDef *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ExplosionDef_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SensorBeginTouchEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SensorBeginTouchEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SensorBeginTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SensorBeginTouchEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SensorBeginTouchEvent_class_id){
			b2SensorBeginTouchEvent ptr=js_getb2SensorBeginTouchEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId sensorShapeId=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId visitorShapeId=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SensorBeginTouchEvent){
				sensorShapeId,
				visitorShapeId
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SensorBeginTouchEvent));
		b2SensorBeginTouchEvent * _returnptr=((b2SensorBeginTouchEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SensorBeginTouchEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SensorEndTouchEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SensorEndTouchEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SensorEndTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SensorEndTouchEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SensorEndTouchEvent_class_id){
			b2SensorEndTouchEvent ptr=js_getb2SensorEndTouchEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId sensorShapeId=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId visitorShapeId=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SensorEndTouchEvent){
				sensorShapeId,
				visitorShapeId
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SensorEndTouchEvent));
		b2SensorEndTouchEvent * _returnptr=((b2SensorEndTouchEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SensorEndTouchEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2SensorEvents_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2SensorEvents));
			JSValue _return=JS_NewObjectClass(ctx,js_b2SensorEvents_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2SensorEvents _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2SensorEvents_class_id){
			b2SensorEvents ptr=js_getb2SensorEvents(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =b2SensorEvents_copy(ctx,ptr);
		}else{
			b2SensorBeginTouchEvent * beginEvents=js_getb2SensorBeginTouchEvent_arrnc(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2SensorEndTouchEvent * endEvents=js_getb2SensorEndTouchEvent_arrnc(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			int beginCount=js_getint(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int endCount=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2SensorEvents){
				beginEvents,
				endEvents,
				beginCount,
				endCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2SensorEvents));
		b2SensorEvents * _returnptr=((b2SensorEvents *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2SensorEvents_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ContactBeginTouchEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ContactBeginTouchEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ContactBeginTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ContactBeginTouchEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ContactBeginTouchEvent_class_id){
			b2ContactBeginTouchEvent ptr=js_getb2ContactBeginTouchEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId shapeIdA=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId shapeIdB=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Manifold manifold=js_getb2Manifold(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ContactBeginTouchEvent){
				shapeIdA,
				shapeIdB,
				manifold
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ContactBeginTouchEvent));
		b2ContactBeginTouchEvent * _returnptr=((b2ContactBeginTouchEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ContactBeginTouchEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ContactEndTouchEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ContactEndTouchEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ContactEndTouchEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ContactEndTouchEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ContactEndTouchEvent_class_id){
			b2ContactEndTouchEvent ptr=js_getb2ContactEndTouchEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId shapeIdA=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId shapeIdB=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ContactEndTouchEvent){
				shapeIdA,
				shapeIdB
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ContactEndTouchEvent));
		b2ContactEndTouchEvent * _returnptr=((b2ContactEndTouchEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ContactEndTouchEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ContactHitEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ContactHitEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ContactHitEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ContactHitEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ContactHitEvent_class_id){
			b2ContactHitEvent ptr=js_getb2ContactHitEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId shapeIdA=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId shapeIdB=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 point=js_getb2Vec2(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			b2Vec2 normal=js_getb2Vec2(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			float approachSpeed=js_getfloat(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ContactHitEvent){
				shapeIdA,
				shapeIdB,
				point,
				normal,
				approachSpeed
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ContactHitEvent));
		b2ContactHitEvent * _returnptr=((b2ContactHitEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ContactHitEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ContactEvents_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ContactEvents));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ContactEvents_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ContactEvents _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ContactEvents_class_id){
			b2ContactEvents ptr=js_getb2ContactEvents(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =b2ContactEvents_copy(ctx,ptr);
		}else{
			b2ContactBeginTouchEvent * beginEvents=js_getb2ContactBeginTouchEvent_arrnc(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ContactEndTouchEvent * endEvents=js_getb2ContactEndTouchEvent_arrnc(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2ContactHitEvent * hitEvents=js_getb2ContactHitEvent_arrnc(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			int beginCount=js_getint(ctx,argv[3],&error);
			if(error==1)return JS_EXCEPTION;
			int endCount=js_getint(ctx,argv[4],&error);
			if(error==1)return JS_EXCEPTION;
			int hitCount=js_getint(ctx,argv[5],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ContactEvents){
				beginEvents,
				endEvents,
				hitEvents,
				beginCount,
				endCount,
				hitCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ContactEvents));
		b2ContactEvents * _returnptr=((b2ContactEvents *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ContactEvents_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2BodyMoveEvent_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2BodyMoveEvent));
			JSValue _return=JS_NewObjectClass(ctx,js_b2BodyMoveEvent_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2BodyMoveEvent _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2BodyMoveEvent_class_id){
			b2BodyMoveEvent ptr=js_getb2BodyMoveEvent(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2Transform transform=js_getb2Transform(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2BodyId bodyId=js_getb2BodyId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			bool fellAsleep=js_getbool(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2BodyMoveEvent){
				transform,
				bodyId,
				0,
				fellAsleep
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2BodyMoveEvent));
		b2BodyMoveEvent * _returnptr=((b2BodyMoveEvent *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2BodyMoveEvent_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2BodyEvents_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2BodyEvents));
			JSValue _return=JS_NewObjectClass(ctx,js_b2BodyEvents_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2BodyEvents _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2BodyEvents_class_id){
			b2BodyEvents ptr=js_getb2BodyEvents(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =b2BodyEvents_copy(ctx,ptr);
		}else{
			b2BodyMoveEvent * moveEvents=js_getb2BodyMoveEvent_arrnc(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			int moveCount=js_getint(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2BodyEvents){
				moveEvents,
				moveCount
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2BodyEvents));
		b2BodyEvents * _returnptr=((b2BodyEvents *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2BodyEvents_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2ContactData_constructor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		if(argc==0){
			opaqueShadow * ptr__return=create_shadow_with_data0(sizeof(b2ContactData));
			JSValue _return=JS_NewObjectClass(ctx,js_b2ContactData_class_id);
			JS_SetOpaque((JSValueConst)_return,(void  *)ptr__return);
			return _return;
		}
		bool error=(bool)0;
		local_memlock=true;
		b2ContactData _struct;
		if(argc==1&&JS_GetClassID((JSValueConst)argv[0])==js_b2ContactData_class_id){
			b2ContactData ptr=js_getb2ContactData(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =ptr;
		}else{
			b2ShapeId shapeIdA=js_getb2ShapeId(ctx,argv[0],&error);
			if(error==1)return JS_EXCEPTION;
			b2ShapeId shapeIdB=js_getb2ShapeId(ctx,argv[1],&error);
			if(error==1)return JS_EXCEPTION;
			b2Manifold manifold=js_getb2Manifold(ctx,argv[2],&error);
			if(error==1)return JS_EXCEPTION;
			_struct =(b2ContactData){
				shapeIdA,
				shapeIdB,
				manifold
			};
		}
		opaqueShadow * _structShadow=create_shadow_with_data(sizeof(b2ContactData));
		b2ContactData * _returnptr=((b2ContactData *)(_structShadow+1));
		_returnptr[0]=_struct;
		JSValue _return=JS_NewObjectClass(ctx,js_b2ContactData_class_id);
		JS_SetOpaque((JSValueConst)_return,(void  *)_structShadow);
		local_memlock=false;
		return _return;
	}
	
	static JSValue js_b2GetByteCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		int returnVal=b2GetByteCount();
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2GetVersion(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2Version returnVal=b2GetVersion();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Version));
		b2Version * ptr2_ret=((b2Version *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Version_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2GetTicks(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		uint64_t returnVal=b2GetTicks();
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		return ret;
	}
	
	static JSValue js_b2GetMilliseconds(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint64_t ticks=js_getuint64_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2GetMilliseconds(ticks);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Yield(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2Yield();
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2IsValidFloat(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float a=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidFloat(a);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2IsValidVec2(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidVec2(v);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2IsValidRotation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidRotation(q);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2IsValidAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB aabb=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidAABB(aabb);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2IsValidPlane(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Plane a=js_getb2Plane(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidPlane(a);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2MinInt(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		int a=js_getint(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int b=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2MinInt(a,b);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2MaxInt(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		int a=js_getint(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int b=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2MaxInt(a,b);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2AbsInt(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		int a=js_getint(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2AbsInt(a);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2ClampInt(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		int a=js_getint(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int lower=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int upper=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2ClampInt(a,lower,upper);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2MinFloat(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float a=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float b=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MinFloat(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MaxFloat(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float a=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float b=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MaxFloat(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2AbsFloat(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float a=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2AbsFloat(a);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2ClampFloat(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float a=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float lower=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float upper=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2ClampFloat(a,lower,upper);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Atan2(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float y=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float x=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Atan2(y,x);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2ComputeCosSin(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float radians=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2CosSin returnVal=b2ComputeCosSin(radians);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CosSin));
		b2CosSin * ptr2_ret=((b2CosSin *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CosSin_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Dot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Dot(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Cross(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Cross(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CrossVS(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float s=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2CrossVS(v,s);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CrossSV(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float s=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2CrossSV(s,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2LeftPerp(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2LeftPerp(v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RightPerp(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2RightPerp(v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Add(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Add(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Sub(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Sub(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Neg(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Neg(a);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Lerp(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float t=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Lerp(a,b,t);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Mul(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Mul(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulSV(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float s=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MulSV(s,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulAdd(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float s=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MulAdd(a,s,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulSub(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float s=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MulSub(a,s,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Abs(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Abs(a);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Min(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Min(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Max(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Max(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Clamp(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 a=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Clamp(v,a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Length(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Length(v);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Distance(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Distance(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Normalize(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Normalize(v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2IsNormalized(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsNormalized(a);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2GetLengthAndNormalize(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float * length=js_getfloat_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2GetLengthAndNormalize(length,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2NormalizeRot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2NormalizeRot(q);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2IntegrateRotation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q1=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float deltaAngle=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2IntegrateRotation(q1,deltaAngle);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2LengthSquared(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2LengthSquared(v);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceSquared(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 a=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceSquared(a,b);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MakeRot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float radians=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2MakeRot(radians);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ComputeRotationBetweenUnitVectors(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 v1=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v2=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2ComputeRotationBetweenUnitVectors(v1,v2);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2IsNormalizedRot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsNormalizedRot(q);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2NLerp(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q1=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot q2=js_getb2Rot(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float t=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2NLerp(q1,q2,t);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ComputeAngularVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q1=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot q2=js_getb2Rot(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float inv_h=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2ComputeAngularVelocity(q1,q2,inv_h);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Rot_GetAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Rot_GetAngle(q);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Rot_GetXAxis(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Rot_GetXAxis(q);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Rot_GetYAxis(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Rot_GetYAxis(q);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulRot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot r=js_getb2Rot(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2MulRot(q,r);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2InvMulRot(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot r=js_getb2Rot(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2InvMulRot(q,r);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2RelativeAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot b=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot a=js_getb2Rot(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RelativeAngle(b,a);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2UnwindAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float radians=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2UnwindAngle(radians);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RotateVector(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2RotateVector(q,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2InvRotateVector(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Rot q=js_getb2Rot(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2InvRotateVector(q,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TransformPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Transform t=js_getb2Transform(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 p=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2TransformPoint(t,(const b2Vec2)p);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2InvTransformPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Transform t=js_getb2Transform(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 p=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2InvTransformPoint(t,(const b2Vec2)p);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulTransforms(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Transform A=js_getb2Transform(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform B=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform returnVal=b2MulTransforms(A,B);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Transform));
		b2Transform * ptr2_ret=((b2Transform *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2InvMulTransforms(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Transform A=js_getb2Transform(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform B=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform returnVal=b2InvMulTransforms(A,B);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Transform));
		b2Transform * ptr2_ret=((b2Transform *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MulMV(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Mat22 A=js_getb2Mat22(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 v=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MulMV(A,v);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2GetInverse22(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Mat22 A=js_getb2Mat22(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Mat22 returnVal=b2GetInverse22(A);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Mat22));
		b2Mat22 * ptr2_ret=((b2Mat22 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Mat22_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Solve22(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Mat22 A=js_getb2Mat22(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 b=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Solve22(A,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_Contains(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB a=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB b=js_getb2AABB(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2AABB_Contains(a,b);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2AABB_Center(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB a=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2AABB_Center(a);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_Extents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB a=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2AABB_Extents(a);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_Union(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB a=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB b=js_getb2AABB(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2AABB_Union(a,b);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2AABB_Overlaps(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2AABB a=js_getb2AABB(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB b=js_getb2AABB(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2AABB_Overlaps(a,b);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2MakeAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 * points=js_getb2Vec2_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2MakeAABB((const b2Vec2  *)points,count,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2PlaneSeparation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Plane plane=js_getb2Plane(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 point=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PlaneSeparation(plane,point);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2SpringDamper(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float hertz=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float position=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		float velocity=js_getfloat(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		float timeStep=js_getfloat(ctx,argv[4],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2SpringDamper(hertz,dampingRatio,position,velocity,timeStep);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2SetLengthUnitsPerMeter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float lengthUnits=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2SetLengthUnitsPerMeter(lengthUnits);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2GetLengthUnitsPerMeter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		float returnVal=b2GetLengthUnitsPerMeter();
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2IsValidRay(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2IsValidRay((const b2RayCastInput  *)input);
		JSValue ret=JS_NewBool(ctx,returnVal);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakePolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Hull * hull=js_getb2Hull_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakePolygon((const b2Hull  *)hull,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakeOffsetPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Hull * hull=js_getb2Hull_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 position=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeOffsetPolygon((const b2Hull  *)hull,position,rotation);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakeOffsetRoundedPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Hull * hull=js_getb2Hull_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 position=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeOffsetRoundedPolygon((const b2Hull  *)hull,position,rotation,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakeSquare(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float halfWidth=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeSquare(halfWidth);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MakeBox(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float halfWidth=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float halfHeight=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeBox(halfWidth,halfHeight);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MakeRoundedBox(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float halfWidth=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float halfHeight=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeRoundedBox(halfWidth,halfHeight,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MakeOffsetBox(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float halfWidth=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float halfHeight=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 center=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeOffsetBox(halfWidth,halfHeight,center,rotation);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MakeOffsetRoundedBox(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		float halfWidth=js_getfloat(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float halfHeight=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 center=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[4],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2MakeOffsetRoundedBox(halfWidth,halfHeight,center,rotation,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2TransformPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Transform transform=js_getb2Transform(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * polygon=js_getb2Polygon_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2TransformPolygon(transform,(const b2Polygon  *)polygon);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeCircleMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Circle * shape=js_getb2Circle_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float density=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData returnVal=b2ComputeCircleMass((const b2Circle  *)shape,density);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * ptr2_ret=((b2MassData *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeCapsuleMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Capsule * shape=js_getb2Capsule_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float density=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData returnVal=b2ComputeCapsuleMass((const b2Capsule  *)shape,density);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * ptr2_ret=((b2MassData *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputePolygonMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Polygon * shape=js_getb2Polygon_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float density=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData returnVal=b2ComputePolygonMass((const b2Polygon  *)shape,density);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * ptr2_ret=((b2MassData *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeCircleAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Circle * shape=js_getb2Circle_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform transform=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2ComputeCircleAABB((const b2Circle  *)shape,transform);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeCapsuleAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Capsule * shape=js_getb2Capsule_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform transform=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2ComputeCapsuleAABB((const b2Capsule  *)shape,transform);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputePolygonAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Polygon * shape=js_getb2Polygon_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform transform=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2ComputePolygonAABB((const b2Polygon  *)shape,transform);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeSegmentAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Segment * shape=js_getb2Segment_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform transform=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2ComputeSegmentAABB((const b2Segment  *)shape,transform);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2PointInCircle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 point=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * shape=js_getb2Circle_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PointInCircle(point,(const b2Circle  *)shape);
		JSValue ret=JS_NewBool(ctx,returnVal);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2PointInCapsule(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 point=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * shape=js_getb2Capsule_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PointInCapsule(point,(const b2Capsule  *)shape);
		JSValue ret=JS_NewBool(ctx,returnVal);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2PointInPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 point=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * shape=js_getb2Polygon_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PointInPolygon(point,(const b2Polygon  *)shape);
		JSValue ret=JS_NewBool(ctx,returnVal);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2RayCastCircle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * shape=js_getb2Circle_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2RayCastCircle((const b2RayCastInput  *)input,(const b2Circle  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2RayCastCapsule(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * shape=js_getb2Capsule_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2RayCastCapsule((const b2RayCastInput  *)input,(const b2Capsule  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2RayCastSegment(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Segment * shape=js_getb2Segment_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool oneSided=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2RayCastSegment((const b2RayCastInput  *)input,(const b2Segment  *)shape,oneSided);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2RayCastPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * shape=js_getb2Polygon_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2RayCastPolygon((const b2RayCastInput  *)input,(const b2Polygon  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ShapeCastCircle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeCastInput * input=js_getb2ShapeCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * shape=js_getb2Circle_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2ShapeCastCircle((const b2ShapeCastInput  *)input,(const b2Circle  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ShapeCastCapsule(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeCastInput * input=js_getb2ShapeCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * shape=js_getb2Capsule_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2ShapeCastCapsule((const b2ShapeCastInput  *)input,(const b2Capsule  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ShapeCastSegment(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeCastInput * input=js_getb2ShapeCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Segment * shape=js_getb2Segment_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2ShapeCastSegment((const b2ShapeCastInput  *)input,(const b2Segment  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ShapeCastPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeCastInput * input=js_getb2ShapeCastInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * shape=js_getb2Polygon_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2ShapeCastPolygon((const b2ShapeCastInput  *)input,(const b2Polygon  *)shape);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ComputeHull(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 * points=js_getb2Vec2_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Hull returnVal=b2ComputeHull((const b2Vec2  *)points,count);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Hull));
		b2Hull * ptr2_ret=((b2Hull *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Hull_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ValidateHull(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Hull * hull=js_getb2Hull_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2ValidateHull((const b2Hull  *)hull);
		JSValue ret=JS_NewBool(ctx,returnVal);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2SegmentDistance(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 p1=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 q1=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 p2=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 q2=js_getb2Vec2(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2SegmentDistanceResult returnVal=b2SegmentDistance(p1,q1,p2,q2);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2SegmentDistanceResult));
		b2SegmentDistanceResult * ptr2_ret=((b2SegmentDistanceResult *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2SegmentDistanceResult_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2ShapeCast(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeCastPairInput * input=js_getb2ShapeCastPairInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2ShapeCast((const b2ShapeCastPairInput  *)input);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakeProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 * points=js_getb2Vec2_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeProxy returnVal=b2MakeProxy((const b2Vec2  *)points,count,radius);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeProxy));
		b2ShapeProxy * ptr2_ret=((b2ShapeProxy *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MakeOffsetProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 * points=js_getb2Vec2_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float radius=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 position=js_getb2Vec2(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[4],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeProxy returnVal=b2MakeOffsetProxy((const b2Vec2  *)points,count,radius,position,rotation);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeProxy));
		b2ShapeProxy * ptr2_ret=((b2ShapeProxy *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeProxy_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2GetSweepTransform(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Sweep * sweep=js_getb2Sweep_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float time=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform returnVal=b2GetSweepTransform((const b2Sweep  *)sweep,time);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Transform));
		b2Transform * ptr2_ret=((b2Transform *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2TimeOfImpact(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2TOIInput * input=js_getb2TOIInput_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2TOIOutput returnVal=b2TimeOfImpact((const b2TOIInput  *)input);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2TOIOutput));
		b2TOIOutput * ptr2_ret=((b2TOIOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2TOIOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CollideCircles(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Circle * circleA=js_getb2Circle_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfA=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * circleB=js_getb2Circle_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfB=js_getb2Transform(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Manifold returnVal=b2CollideCircles((const b2Circle  *)circleA,xfA,(const b2Circle  *)circleB,xfB);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Manifold));
		b2Manifold * ptr2_ret=((b2Manifold *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CollideCapsules(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Capsule * capsuleA=js_getb2Capsule_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfA=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * capsuleB=js_getb2Capsule_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfB=js_getb2Transform(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Manifold returnVal=b2CollideCapsules((const b2Capsule  *)capsuleA,xfA,(const b2Capsule  *)capsuleB,xfB);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Manifold));
		b2Manifold * ptr2_ret=((b2Manifold *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CollidePolygons(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Polygon * polygonA=js_getb2Polygon_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfA=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * polygonB=js_getb2Polygon_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform xfB=js_getb2Transform(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Manifold returnVal=b2CollidePolygons((const b2Polygon  *)polygonA,xfA,(const b2Polygon  *)polygonB,xfB);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Manifold));
		b2Manifold * ptr2_ret=((b2Manifold *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Manifold_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_Create(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2DynamicTree returnVal=b2DynamicTree_Create();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2DynamicTree));
		b2DynamicTree * ptr2_ret=((b2DynamicTree *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2DynamicTree_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_Destroy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_Destroy(tree);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_CreateProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB aabb=js_getb2AABB(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t categoryBits=js_getuint64_t(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t userData=js_getuint64_t(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2DynamicTree_CreateProxy(tree,aabb,categoryBits,userData);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_DestroyProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_DestroyProxy(tree,proxyId);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_MoveProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB aabb=js_getb2AABB(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_MoveProxy(tree,proxyId,aabb);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_EnlargeProxy(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB aabb=js_getb2AABB(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_EnlargeProxy(tree,proxyId,aabb);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_SetCategoryBits(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t categoryBits=js_getuint64_t(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_SetCategoryBits(tree,proxyId,categoryBits);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_GetCategoryBits(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2DynamicTree_GetCategoryBits(tree,proxyId);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetHeight(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2DynamicTree_GetHeight((const b2DynamicTree  *)tree);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetAreaRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DynamicTree_GetAreaRatio((const b2DynamicTree  *)tree);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetRootBounds(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2DynamicTree_GetRootBounds((const b2DynamicTree  *)tree);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetProxyCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2DynamicTree_GetProxyCount((const b2DynamicTree  *)tree);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_Rebuild(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool fullBuild=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2DynamicTree_Rebuild(tree,fullBuild);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetByteCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2DynamicTree_GetByteCount((const b2DynamicTree  *)tree);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetUserData(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2DynamicTree_GetUserData((const b2DynamicTree  *)tree,proxyId);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_GetAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int proxyId=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2DynamicTree_GetAABB((const b2DynamicTree  *)tree,proxyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DynamicTree_Validate(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_Validate((const b2DynamicTree  *)tree);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DynamicTree_ValidateNoEnlarged(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2DynamicTree * tree=js_getb2DynamicTree_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DynamicTree_ValidateNoEnlarged((const b2DynamicTree  *)tree);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2SolvePlanes(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 targetDelta=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2CollisionPlane * planes=js_getb2CollisionPlane_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2PlaneSolverResult returnVal=b2SolvePlanes(targetDelta,planes,count);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2PlaneSolverResult));
		b2PlaneSolverResult * ptr2_ret=((b2PlaneSolverResult *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2PlaneSolverResult_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2ClipVector(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2Vec2 vector=js_getb2Vec2(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2CollisionPlane * planes=js_getb2CollisionPlane_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int count=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2ClipVector(vector,(const b2CollisionPlane  *)planes,count);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2StoreWorldId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId id=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		uint32_t returnVal=b2StoreWorldId(id);
		JSValue ret=JS_NewUint32(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2LoadWorldId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint32_t x=js_getuint32_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2LoadWorldId(x);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2StoreBodyId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId id=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2StoreBodyId(id);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		return ret;
	}
	
	static JSValue js_b2LoadBodyId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint64_t x=js_getuint64_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyId returnVal=b2LoadBodyId(x);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * ptr2_ret=((b2BodyId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2StoreShapeId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId id=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2StoreShapeId(id);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		return ret;
	}
	
	static JSValue js_b2LoadShapeId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint64_t x=js_getuint64_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId returnVal=b2LoadShapeId(x);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * ptr2_ret=((b2ShapeId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2StoreChainId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId id=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2StoreChainId(id);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		return ret;
	}
	
	static JSValue js_b2LoadChainId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint64_t x=js_getuint64_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ChainId returnVal=b2LoadChainId(x);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ChainId));
		b2ChainId * ptr2_ret=((b2ChainId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ChainId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2StoreJointId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId id=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		uint64_t returnVal=b2StoreJointId(id);
		JSValue ret=JS_NewInt64(ctx,(int64_t)((long long)returnVal));
		return ret;
	}
	
	static JSValue js_b2LoadJointId(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		uint64_t x=js_getuint64_t(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2LoadJointId(x);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultWorldDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2WorldDef returnVal=b2DefaultWorldDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldDef));
		b2WorldDef * ptr2_ret=((b2WorldDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultBodyDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2BodyDef returnVal=b2DefaultBodyDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyDef));
		b2BodyDef * ptr2_ret=((b2BodyDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultFilter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2Filter returnVal=b2DefaultFilter();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Filter));
		b2Filter * ptr2_ret=((b2Filter *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Filter_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultQueryFilter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2QueryFilter returnVal=b2DefaultQueryFilter();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2QueryFilter));
		b2QueryFilter * ptr2_ret=((b2QueryFilter *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2QueryFilter_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultSurfaceMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2SurfaceMaterial returnVal=b2DefaultSurfaceMaterial();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2SurfaceMaterial));
		b2SurfaceMaterial * ptr2_ret=((b2SurfaceMaterial *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultShapeDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2ShapeDef returnVal=b2DefaultShapeDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeDef));
		b2ShapeDef * ptr2_ret=((b2ShapeDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultChainDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2ChainDef returnVal=b2DefaultChainDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ChainDef));
		b2ChainDef * ptr2_ret=((b2ChainDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ChainDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultDistanceJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2DistanceJointDef returnVal=b2DefaultDistanceJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2DistanceJointDef));
		b2DistanceJointDef * ptr2_ret=((b2DistanceJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2DistanceJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultMotorJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2MotorJointDef returnVal=b2DefaultMotorJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MotorJointDef));
		b2MotorJointDef * ptr2_ret=((b2MotorJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MotorJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultMouseJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2MouseJointDef returnVal=b2DefaultMouseJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MouseJointDef));
		b2MouseJointDef * ptr2_ret=((b2MouseJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MouseJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultFilterJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2FilterJointDef returnVal=b2DefaultFilterJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2FilterJointDef));
		b2FilterJointDef * ptr2_ret=((b2FilterJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2FilterJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultPrismaticJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2PrismaticJointDef returnVal=b2DefaultPrismaticJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2PrismaticJointDef));
		b2PrismaticJointDef * ptr2_ret=((b2PrismaticJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2PrismaticJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultRevoluteJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2RevoluteJointDef returnVal=b2DefaultRevoluteJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2RevoluteJointDef));
		b2RevoluteJointDef * ptr2_ret=((b2RevoluteJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2RevoluteJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultWeldJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2WeldJointDef returnVal=b2DefaultWeldJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WeldJointDef));
		b2WeldJointDef * ptr2_ret=((b2WeldJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WeldJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultWheelJointDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2WheelJointDef returnVal=b2DefaultWheelJointDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WheelJointDef));
		b2WheelJointDef * ptr2_ret=((b2WheelJointDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WheelJointDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultExplosionDef(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2ExplosionDef returnVal=b2DefaultExplosionDef();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ExplosionDef));
		b2ExplosionDef * ptr2_ret=((b2ExplosionDef *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ExplosionDef_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2DefaultDebugDraw(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		b2DebugDraw returnVal=b2DefaultDebugDraw();
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2DebugDraw));
		b2DebugDraw * ptr2_ret=((b2DebugDraw *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2DebugDraw_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CreateWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldDef * def=js_getb2WorldDef_arr(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2CreateWorld((const b2WorldDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DestroyWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DestroyWorld(worldId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_IsValid(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId id=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2World_IsValid(id);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2World_Step(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float timeStep=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int subStepCount=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_Step(worldId,timeStep,subStepCount);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_GetBodyEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyEvents returnVal=b2World_GetBodyEvents(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyEvents));
		b2BodyEvents * ptr2_ret=((b2BodyEvents *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyEvents_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_GetSensorEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2SensorEvents returnVal=b2World_GetSensorEvents(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2SensorEvents));
		b2SensorEvents * ptr2_ret=((b2SensorEvents *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2SensorEvents_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_GetContactEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ContactEvents returnVal=b2World_GetContactEvents(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ContactEvents));
		b2ContactEvents * ptr2_ret=((b2ContactEvents *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ContactEvents_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_CastRayClosest(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 origin=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 translation=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2QueryFilter filter=js_getb2QueryFilter(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2RayResult returnVal=b2World_CastRayClosest(worldId,origin,translation,filter);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2RayResult));
		b2RayResult * ptr2_ret=((b2RayResult *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2RayResult_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_CastMover(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * mover=js_getb2Capsule_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 translation=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2QueryFilter filter=js_getb2QueryFilter(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2World_CastMover(worldId,(const b2Capsule  *)mover,translation,filter);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2World_EnableSleeping(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_EnableSleeping(worldId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_IsSleepingEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2World_IsSleepingEnabled(worldId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2World_EnableContinuous(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_EnableContinuous(worldId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_IsContinuousEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2World_IsContinuousEnabled(worldId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2World_SetRestitutionThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float value=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_SetRestitutionThreshold(worldId,value);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_GetRestitutionThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2World_GetRestitutionThreshold(worldId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2World_SetHitEventThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float value=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_SetHitEventThreshold(worldId,value);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_GetHitEventThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2World_GetHitEventThreshold(worldId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2World_SetGravity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 gravity=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_SetGravity(worldId,gravity);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_GetGravity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2World_GetGravity(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_Explode(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ExplosionDef * explosionDef=js_getb2ExplosionDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_Explode(worldId,(const b2ExplosionDef  *)explosionDef);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_SetContactTuning(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		float pushSpeed=js_getfloat(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_SetContactTuning(worldId,hertz,dampingRatio,pushSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_SetMaximumLinearSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float maximumLinearSpeed=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_SetMaximumLinearSpeed(worldId,maximumLinearSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_GetMaximumLinearSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2World_GetMaximumLinearSpeed(worldId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2World_EnableWarmStarting(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_EnableWarmStarting(worldId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_IsWarmStartingEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2World_IsWarmStartingEnabled(worldId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2World_GetAwakeBodyCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2World_GetAwakeBodyCount(worldId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2World_GetProfile(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Profile returnVal=b2World_GetProfile(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Profile));
		b2Profile * ptr2_ret=((b2Profile *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Profile_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_GetCounters(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Counters returnVal=b2World_GetCounters(worldId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Counters));
		b2Counters * ptr2_ret=((b2Counters *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Counters_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2World_SetFrictionCallback(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		void * callback;
		trampolineContext ctx_callback;
		ctx_callback.ctx=ctx;
		ctx_callback.func_obj=argv[1];
		if(JS_IsUndefined(argv[1])||JS_IsNull(argv[1])){
			JS_FreeValue(b2FrictionCallback_arr[0].ctx,b2FrictionCallback_arr[0].func_obj);
			JS_FreeContext(b2FrictionCallback_arr[0].ctx);
			b2FrictionCallback_arr =NULL;
		}else if(JS_IsFunction(ctx,(JSValueConst)argv[1])==1){
			if(b2FrictionCallback_arr!=NULL){
				JS_FreeValue(b2FrictionCallback_arr[0].ctx,b2FrictionCallback_arr[0].func_obj);
				JS_FreeContext(b2FrictionCallback_arr[0].ctx);
			}
			b2FrictionCallback_arr =&ctx_callback;
		}else{
			return JS_EXCEPTION;
		}
		if(b2FrictionCallback_arr==NULL){
			callback =NULL;
		}else{
			callback =callback_b2FrictionCallback;
		}
		JS_DupValue(ctx,(JSValueConst)argv[1]);
		b2World_SetFrictionCallback(worldId,callback);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_SetRestitutionCallback(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		void * callback;
		trampolineContext ctx_callback;
		ctx_callback.ctx=ctx;
		ctx_callback.func_obj=argv[1];
		if(JS_IsUndefined(argv[1])||JS_IsNull(argv[1])){
			JS_FreeValue(b2RestitutionCallback_arr[0].ctx,b2RestitutionCallback_arr[0].func_obj);
			JS_FreeContext(b2RestitutionCallback_arr[0].ctx);
			b2RestitutionCallback_arr =NULL;
		}else if(JS_IsFunction(ctx,(JSValueConst)argv[1])==1){
			if(b2RestitutionCallback_arr!=NULL){
				JS_FreeValue(b2RestitutionCallback_arr[0].ctx,b2RestitutionCallback_arr[0].func_obj);
				JS_FreeContext(b2RestitutionCallback_arr[0].ctx);
			}
			b2RestitutionCallback_arr =&ctx_callback;
		}else{
			return JS_EXCEPTION;
		}
		if(b2RestitutionCallback_arr==NULL){
			callback =NULL;
		}else{
			callback =callback_b2RestitutionCallback;
		}
		JS_DupValue(ctx,(JSValueConst)argv[1]);
		b2World_SetRestitutionCallback(worldId,callback);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_DumpMemoryStats(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_DumpMemoryStats(worldId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_RebuildStaticTree(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_RebuildStaticTree(worldId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2World_EnableSpeculative(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2World_EnableSpeculative(worldId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CreateBody(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyDef * def=js_getb2BodyDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyId returnVal=b2CreateBody(worldId,(const b2BodyDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * ptr2_ret=((b2BodyId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DestroyBody(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DestroyBody(bodyId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_IsValid(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId id=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsValid(id);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_GetType(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyType returnVal=b2Body_GetType(bodyId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_SetType(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyType type=js_getb2BodyType(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetType(bodyId,type);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_SetName(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		char * name=js_getchar_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetName(bodyId,(const char  *)name);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetName(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		char * returnVal=(char  *)b2Body_GetName(bodyId);
		JSValue ret=JS_NewString(ctx,(const char  *)returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_GetPosition(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetPosition(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetRotation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot returnVal=b2Body_GetRotation(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Rot));
		b2Rot * ptr2_ret=((b2Rot *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Rot_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetTransform(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform returnVal=b2Body_GetTransform(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Transform));
		b2Transform * ptr2_ret=((b2Transform *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Transform_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_SetTransform(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 position=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Rot rotation=js_getb2Rot(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetTransform(bodyId,position,rotation);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetLocalPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 worldPoint=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetLocalPoint(bodyId,worldPoint);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetWorldPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localPoint=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetWorldPoint(bodyId,localPoint);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetLocalVector(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 worldVector=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetLocalVector(bodyId,worldVector);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetWorldVector(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localVector=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetWorldVector(bodyId,localVector);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetLinearVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetLinearVelocity(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetAngularVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetAngularVelocity(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_SetLinearVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 linearVelocity=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetLinearVelocity(bodyId,linearVelocity);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_SetAngularVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float angularVelocity=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetAngularVelocity(bodyId,angularVelocity);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_SetTargetTransform(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Transform target=js_getb2Transform(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float timeStep=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetTargetTransform(bodyId,target,timeStep);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetLocalPointVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localPoint=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetLocalPointVelocity(bodyId,localPoint);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetWorldPointVelocity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 worldPoint=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetWorldPointVelocity(bodyId,worldPoint);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_ApplyForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 force=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 point=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyForce(bodyId,force,point,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_ApplyForceToCenter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 force=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyForceToCenter(bodyId,force,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_ApplyTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float torque=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyTorque(bodyId,torque,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_ApplyLinearImpulse(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 impulse=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 point=js_getb2Vec2(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[3],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyLinearImpulse(bodyId,impulse,point,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_ApplyLinearImpulseToCenter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 impulse=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyLinearImpulseToCenter(bodyId,impulse,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_ApplyAngularImpulse(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float impulse=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool wake=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyAngularImpulse(bodyId,impulse,wake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetMass(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_GetRotationalInertia(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetRotationalInertia(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_GetLocalCenterOfMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetLocalCenterOfMass(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetWorldCenterOfMass(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Body_GetWorldCenterOfMass(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_SetMassData(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData massData=js_getb2MassData(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetMassData(bodyId,massData);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetMassData(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData returnVal=b2Body_GetMassData(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * ptr2_ret=((b2MassData *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_ApplyMassFromShapes(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_ApplyMassFromShapes(bodyId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_SetLinearDamping(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float linearDamping=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetLinearDamping(bodyId,linearDamping);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetLinearDamping(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetLinearDamping(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_SetAngularDamping(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float angularDamping=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetAngularDamping(bodyId,angularDamping);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetAngularDamping(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetAngularDamping(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_SetGravityScale(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float gravityScale=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetGravityScale(bodyId,gravityScale);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetGravityScale(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetGravityScale(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_IsAwake(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsAwake(bodyId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_SetAwake(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool awake=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetAwake(bodyId,awake);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_EnableSleep(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableSleep=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_EnableSleep(bodyId,enableSleep);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_IsSleepEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsSleepEnabled(bodyId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_SetSleepThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float sleepThreshold=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetSleepThreshold(bodyId,sleepThreshold);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetSleepThreshold(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Body_GetSleepThreshold(bodyId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_IsEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsEnabled(bodyId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_Disable(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_Disable(bodyId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_Enable(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_Enable(bodyId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_SetFixedRotation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetFixedRotation(bodyId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_IsFixedRotation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsFixedRotation(bodyId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_SetBullet(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_SetBullet(bodyId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_IsBullet(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Body_IsBullet(bodyId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Body_EnableContactEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_EnableContactEvents(bodyId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_EnableHitEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Body_EnableHitEvents(bodyId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Body_GetWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2Body_GetWorld(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Body_GetShapeCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Body_GetShapeCount(bodyId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_GetShapes(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId * shapeArray=js_getb2ShapeId_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int capacity=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Body_GetShapes(bodyId,shapeArray,capacity);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2Body_GetJointCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Body_GetJointCount(bodyId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_GetJoints(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId * jointArray=js_getb2JointId_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int capacity=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Body_GetJoints(bodyId,jointArray,capacity);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2Body_GetContactCapacity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Body_GetContactCapacity(bodyId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Body_ComputeAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2Body_ComputeAABB(bodyId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CreateCircleShape(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeDef * def=js_getb2ShapeDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * circle=js_getb2Circle_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId returnVal=b2CreateCircleShape(bodyId,(const b2ShapeDef  *)def,(const b2Circle  *)circle);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * ptr2_ret=((b2ShapeId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CreateSegmentShape(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeDef * def=js_getb2ShapeDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Segment * segment=js_getb2Segment_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId returnVal=b2CreateSegmentShape(bodyId,(const b2ShapeDef  *)def,(const b2Segment  *)segment);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * ptr2_ret=((b2ShapeId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CreateCapsuleShape(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeDef * def=js_getb2ShapeDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * capsule=js_getb2Capsule_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId returnVal=b2CreateCapsuleShape(bodyId,(const b2ShapeDef  *)def,(const b2Capsule  *)capsule);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * ptr2_ret=((b2ShapeId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CreatePolygonShape(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeDef * def=js_getb2ShapeDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * polygon=js_getb2Polygon_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId returnVal=b2CreatePolygonShape(bodyId,(const b2ShapeDef  *)def,(const b2Polygon  *)polygon);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ShapeId));
		b2ShapeId * ptr2_ret=((b2ShapeId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ShapeId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DestroyShape(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool updateBodyMass=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DestroyShape(shapeId,updateBodyMass);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_IsValid(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId id=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_IsValid(id);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_GetType(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeType returnVal=b2Shape_GetType(shapeId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_GetBody(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyId returnVal=b2Shape_GetBody(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * ptr2_ret=((b2BodyId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2Shape_GetWorld(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_IsSensor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_IsSensor(shapeId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_SetDensity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float density=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool updateBodyMass=js_getbool(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetDensity(shapeId,density,updateBodyMass);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetDensity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Shape_GetDensity(shapeId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_SetFriction(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float friction=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetFriction(shapeId,friction);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetFriction(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Shape_GetFriction(shapeId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_SetRestitution(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float restitution=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetRestitution(shapeId,restitution);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetRestitution(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Shape_GetRestitution(shapeId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_SetMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int material=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetMaterial(shapeId,material);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Shape_GetMaterial(shapeId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_SetSurfaceMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2SurfaceMaterial surfaceMaterial=js_getb2SurfaceMaterial(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetSurfaceMaterial(shapeId,surfaceMaterial);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetSurfaceMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2SurfaceMaterial returnVal=b2Shape_GetSurfaceMaterial(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2SurfaceMaterial));
		b2SurfaceMaterial * ptr2_ret=((b2SurfaceMaterial *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2SurfaceMaterial_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetFilter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Filter returnVal=b2Shape_GetFilter(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Filter));
		b2Filter * ptr2_ret=((b2Filter *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Filter_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_SetFilter(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Filter filter=js_getb2Filter(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetFilter(shapeId,filter);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_EnableSensorEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_EnableSensorEvents(shapeId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_AreSensorEventsEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_AreSensorEventsEnabled(shapeId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_EnableContactEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_EnableContactEvents(shapeId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_AreContactEventsEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_AreContactEventsEnabled(shapeId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_EnablePreSolveEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_EnablePreSolveEvents(shapeId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_ArePreSolveEventsEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_ArePreSolveEventsEnabled(shapeId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_EnableHitEvents(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool flag=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_EnableHitEvents(shapeId,flag);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_AreHitEventsEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_AreHitEventsEnabled(shapeId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_TestPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 point=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Shape_TestPoint(shapeId,point);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Shape_RayCast(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2RayCastInput * input=js_getb2RayCastInput_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2CastOutput returnVal=b2Shape_RayCast(shapeId,(const b2RayCastInput  *)input);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2CastOutput));
		b2CastOutput * ptr2_ret=((b2CastOutput *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2CastOutput_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2Shape_GetCircle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle returnVal=b2Shape_GetCircle(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Circle));
		b2Circle * ptr2_ret=((b2Circle *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Circle_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetSegment(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Segment returnVal=b2Shape_GetSegment(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Segment));
		b2Segment * ptr2_ret=((b2Segment *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Segment_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetChainSegment(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ChainSegment returnVal=b2Shape_GetChainSegment(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ChainSegment));
		b2ChainSegment * ptr2_ret=((b2ChainSegment *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ChainSegment_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetCapsule(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule returnVal=b2Shape_GetCapsule(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Capsule));
		b2Capsule * ptr2_ret=((b2Capsule *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Capsule_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon returnVal=b2Shape_GetPolygon(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Polygon));
		b2Polygon * ptr2_ret=((b2Polygon *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Polygon_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_SetCircle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Circle * circle=js_getb2Circle_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetCircle(shapeId,(const b2Circle  *)circle);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_SetCapsule(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Capsule * capsule=js_getb2Capsule_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetCapsule(shapeId,(const b2Capsule  *)capsule);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_SetSegment(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Segment * segment=js_getb2Segment_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetSegment(shapeId,(const b2Segment  *)segment);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_SetPolygon(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Polygon * polygon=js_getb2Polygon_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Shape_SetPolygon(shapeId,(const b2Polygon  *)polygon);
		memoryClear(ctx);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Shape_GetParentChain(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ChainId returnVal=b2Shape_GetParentChain(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ChainId));
		b2ChainId * ptr2_ret=((b2ChainId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ChainId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetContactCapacity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Shape_GetContactCapacity(shapeId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_GetSensorCapacity(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Shape_GetSensorCapacity(shapeId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Shape_GetSensorOverlaps(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId * overlaps=js_getb2ShapeId_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int capacity=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Shape_GetSensorOverlaps(shapeId,overlaps,capacity);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2Shape_GetAABB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2AABB returnVal=b2Shape_GetAABB(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2AABB));
		b2AABB * ptr2_ret=((b2AABB *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2AABB_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetMassData(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2MassData returnVal=b2Shape_GetMassData(shapeId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2MassData));
		b2MassData * ptr2_ret=((b2MassData *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2MassData_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Shape_GetClosestPoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ShapeId shapeId=js_getb2ShapeId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 target=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Shape_GetClosestPoint(shapeId,target);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2CreateChain(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2BodyId bodyId=js_getb2BodyId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ChainDef * def=js_getb2ChainDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2ChainId returnVal=b2CreateChain(bodyId,(const b2ChainDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2ChainId));
		b2ChainId * ptr2_ret=((b2ChainId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2ChainId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DestroyChain(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DestroyChain(chainId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Chain_GetWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2Chain_GetWorld(chainId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Chain_GetSegmentCount(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Chain_GetSegmentCount(chainId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Chain_GetSegments(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2ShapeId * segmentArray=js_getb2ShapeId_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		int capacity=js_getint(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Chain_GetSegments(chainId,segmentArray,capacity);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2Chain_SetFriction(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float friction=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Chain_SetFriction(chainId,friction);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Chain_GetFriction(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Chain_GetFriction(chainId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Chain_SetRestitution(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float restitution=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Chain_SetRestitution(chainId,restitution);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Chain_GetRestitution(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Chain_GetRestitution(chainId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Chain_SetMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int material=js_getint(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Chain_SetMaterial(chainId,material);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Chain_GetMaterial(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId chainId=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		int returnVal=b2Chain_GetMaterial(chainId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)((long)returnVal));
		return ret;
	}
	
	static JSValue js_b2Chain_IsValid(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2ChainId id=js_getb2ChainId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Chain_IsValid(id);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2DestroyJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DestroyJoint(jointId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_IsValid(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId id=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Joint_IsValid(id);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Joint_GetType(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointType returnVal=b2Joint_GetType(jointId);
		JSValue ret=JS_NewInt32(ctx,(int32_t)returnVal);
		return ret;
	}
	
	static JSValue js_b2Joint_GetBodyA(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyId returnVal=b2Joint_GetBodyA(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * ptr2_ret=((b2BodyId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_GetBodyB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2BodyId returnVal=b2Joint_GetBodyB(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2BodyId));
		b2BodyId * ptr2_ret=((b2BodyId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2BodyId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_GetWorld(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WorldId returnVal=b2Joint_GetWorld(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2WorldId));
		b2WorldId * ptr2_ret=((b2WorldId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2WorldId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_SetLocalAnchorA(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localAnchor=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetLocalAnchorA(jointId,localAnchor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_GetLocalAnchorA(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Joint_GetLocalAnchorA(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_SetLocalAnchorB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localAnchor=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetLocalAnchorB(jointId,localAnchor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_GetLocalAnchorB(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Joint_GetLocalAnchorB(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_GetReferenceAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Joint_GetReferenceAngle(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Joint_SetReferenceAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float angleInRadians=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetReferenceAngle(jointId,angleInRadians);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_SetLocalAxisA(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 localAxis=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetLocalAxisA(jointId,localAxis);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_GetLocalAxisA(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Joint_GetLocalAxisA(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_SetCollideConnected(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool shouldCollide=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetCollideConnected(jointId,shouldCollide);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_GetCollideConnected(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2Joint_GetCollideConnected(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2Joint_WakeBodies(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_WakeBodies(jointId);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_GetConstraintForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2Joint_GetConstraintForce(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2Joint_GetConstraintTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Joint_GetConstraintTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Joint_GetLinearSeparation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Joint_GetLinearSeparation(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Joint_GetAngularSeparation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2Joint_GetAngularSeparation(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2Joint_GetConstraintTuning(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float * hertz=js_getfloat_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float * dampingRatio=js_getfloat_arr(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_GetConstraintTuning(jointId,hertz,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2Joint_SetConstraintTuning(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2Joint_SetConstraintTuning(jointId,hertz,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2CreateDistanceJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJointDef * def=js_getb2DistanceJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateDistanceJoint(worldId,(const b2DistanceJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_SetLength(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float length=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetLength(jointId,length);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_GetLength(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetLength(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_EnableSpring(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableSpring=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_EnableSpring(jointId,enableSpring);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_IsSpringEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2DistanceJoint_IsSpringEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_SetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetSpringHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_SetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetSpringDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_GetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetSpringHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_GetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetSpringDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_EnableLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableLimit=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_EnableLimit(jointId,enableLimit);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_IsLimitEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2DistanceJoint_IsLimitEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_SetLengthRange(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float minLength=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float maxLength=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetLengthRange(jointId,minLength,maxLength);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_GetMinLength(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetMinLength(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_GetMaxLength(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetMaxLength(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_GetCurrentLength(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetCurrentLength(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_EnableMotor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableMotor=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_EnableMotor(jointId,enableMotor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_IsMotorEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2DistanceJoint_IsMotorEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_SetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float motorSpeed=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetMotorSpeed(jointId,motorSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_GetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetMotorSpeed(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_SetMaxMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float force=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2DistanceJoint_SetMaxMotorForce(jointId,force);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2DistanceJoint_GetMaxMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetMaxMotorForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2DistanceJoint_GetMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2DistanceJoint_GetMotorForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateMotorJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJointDef * def=js_getb2MotorJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateMotorJoint(worldId,(const b2MotorJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MotorJoint_SetLinearOffset(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 linearOffset=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJoint_SetLinearOffset(jointId,linearOffset);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJoint_GetLinearOffset(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MotorJoint_GetLinearOffset(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MotorJoint_SetAngularOffset(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float angularOffset=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJoint_SetAngularOffset(jointId,angularOffset);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJoint_GetAngularOffset(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MotorJoint_GetAngularOffset(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MotorJoint_SetMaxForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float maxForce=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJoint_SetMaxForce(jointId,maxForce);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJoint_GetMaxForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MotorJoint_GetMaxForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MotorJoint_SetMaxTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float maxTorque=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJoint_SetMaxTorque(jointId,maxTorque);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJoint_GetMaxTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MotorJoint_GetMaxTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MotorJoint_SetCorrectionFactor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float correctionFactor=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MotorJoint_SetCorrectionFactor(jointId,correctionFactor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MotorJoint_GetCorrectionFactor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MotorJoint_GetCorrectionFactor(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateMouseJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2MouseJointDef * def=js_getb2MouseJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateMouseJoint(worldId,(const b2MouseJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2MouseJoint_SetTarget(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 target=js_getb2Vec2(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MouseJoint_SetTarget(jointId,target);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJoint_GetTarget(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2Vec2 returnVal=b2MouseJoint_GetTarget(jointId);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2Vec2));
		b2Vec2 * ptr2_ret=((b2Vec2 *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2Vec2_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		return ret;
	}
	
	static JSValue js_b2MouseJoint_SetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MouseJoint_SetSpringHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJoint_GetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MouseJoint_GetSpringHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MouseJoint_SetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MouseJoint_SetSpringDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJoint_GetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MouseJoint_GetSpringDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2MouseJoint_SetMaxForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float maxForce=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2MouseJoint_SetMaxForce(jointId,maxForce);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2MouseJoint_GetMaxForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2MouseJoint_GetMaxForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateFilterJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2FilterJointDef * def=js_getb2FilterJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateFilterJoint(worldId,(const b2FilterJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2CreatePrismaticJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJointDef * def=js_getb2PrismaticJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreatePrismaticJoint(worldId,(const b2PrismaticJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_EnableSpring(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableSpring=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_EnableSpring(jointId,enableSpring);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_IsSpringEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PrismaticJoint_IsSpringEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetSpringHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_GetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetSpringHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetSpringDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_GetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetSpringDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetTargetTranslation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float translation=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetTargetTranslation(jointId,translation);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_GetTargetTranslation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetTargetTranslation(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_EnableLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableLimit=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_EnableLimit(jointId,enableLimit);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_IsLimitEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PrismaticJoint_IsLimitEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_GetLowerLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetLowerLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_GetUpperLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetUpperLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetLimits(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float lower=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float upper=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetLimits(jointId,lower,upper);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_EnableMotor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableMotor=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_EnableMotor(jointId,enableMotor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_IsMotorEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2PrismaticJoint_IsMotorEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float motorSpeed=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetMotorSpeed(jointId,motorSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_GetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetMotorSpeed(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_SetMaxMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float force=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2PrismaticJoint_SetMaxMotorForce(jointId,force);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2PrismaticJoint_GetMaxMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetMaxMotorForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_GetMotorForce(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetMotorForce(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_GetTranslation(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetTranslation(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2PrismaticJoint_GetSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2PrismaticJoint_GetSpeed(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateRevoluteJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJointDef * def=js_getb2RevoluteJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateRevoluteJoint(worldId,(const b2RevoluteJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_EnableSpring(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableSpring=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_EnableSpring(jointId,enableSpring);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_IsSpringEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2RevoluteJoint_IsSpringEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetSpringHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_GetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetSpringHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetSpringDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_GetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetSpringDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetTargetAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float angle=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetTargetAngle(jointId,angle);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_GetTargetAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetTargetAngle(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_GetAngle(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetAngle(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_EnableLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableLimit=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_EnableLimit(jointId,enableLimit);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_IsLimitEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2RevoluteJoint_IsLimitEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_GetLowerLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetLowerLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_GetUpperLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetUpperLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetLimits(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float lower=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float upper=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetLimits(jointId,lower,upper);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_EnableMotor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableMotor=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_EnableMotor(jointId,enableMotor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_IsMotorEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2RevoluteJoint_IsMotorEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float motorSpeed=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetMotorSpeed(jointId,motorSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_GetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetMotorSpeed(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_GetMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetMotorTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2RevoluteJoint_SetMaxMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float torque=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2RevoluteJoint_SetMaxMotorTorque(jointId,torque);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2RevoluteJoint_GetMaxMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2RevoluteJoint_GetMaxMotorTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateWeldJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WeldJointDef * def=js_getb2WeldJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateWeldJoint(worldId,(const b2WeldJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2WeldJoint_SetLinearHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WeldJoint_SetLinearHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJoint_GetLinearHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WeldJoint_GetLinearHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WeldJoint_SetLinearDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WeldJoint_SetLinearDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJoint_GetLinearDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WeldJoint_GetLinearDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WeldJoint_SetAngularHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WeldJoint_SetAngularHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJoint_GetAngularHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WeldJoint_GetAngularHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WeldJoint_SetAngularDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WeldJoint_SetAngularDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WeldJoint_GetAngularDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WeldJoint_GetAngularDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2CreateWheelJoint(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2WorldId worldId=js_getb2WorldId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJointDef * def=js_getb2WheelJointDef_arr(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2JointId returnVal=b2CreateWheelJoint(worldId,(const b2WheelJointDef  *)def);
		opaqueShadow * ptr_ret=create_shadow_with_data(sizeof(b2JointId));
		b2JointId * ptr2_ret=((b2JointId *)(ptr_ret+1));
		ptr2_ret[0]=returnVal;
		JSValue ret=JS_NewObjectClass(ctx,js_b2JointId_class_id);
		JS_SetOpaque((JSValueConst)ret,(void  *)ptr_ret);
		memoryClear(ctx);
		return ret;
	}
	
	static JSValue js_b2WheelJoint_EnableSpring(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableSpring=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_EnableSpring(jointId,enableSpring);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_IsSpringEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2WheelJoint_IsSpringEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2WheelJoint_SetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float hertz=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_SetSpringHertz(jointId,hertz);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_GetSpringHertz(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetSpringHertz(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_SetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float dampingRatio=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_SetSpringDampingRatio(jointId,dampingRatio);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_GetSpringDampingRatio(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetSpringDampingRatio(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_EnableLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableLimit=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_EnableLimit(jointId,enableLimit);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_IsLimitEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2WheelJoint_IsLimitEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2WheelJoint_GetLowerLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetLowerLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_GetUpperLimit(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetUpperLimit(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_SetLimits(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float lower=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		float upper=js_getfloat(ctx,argv[2],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_SetLimits(jointId,lower,upper);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_EnableMotor(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool enableMotor=js_getbool(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_EnableMotor(jointId,enableMotor);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_IsMotorEnabled(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		bool returnVal=b2WheelJoint_IsMotorEnabled(jointId);
		JSValue ret=JS_NewBool(ctx,returnVal);
		return ret;
	}
	
	static JSValue js_b2WheelJoint_SetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float motorSpeed=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_SetMotorSpeed(jointId,motorSpeed);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_GetMotorSpeed(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetMotorSpeed(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_SetMaxMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float torque=js_getfloat(ctx,argv[1],&error);
		if(error==1)return JS_EXCEPTION;
		b2WheelJoint_SetMaxMotorTorque(jointId,torque);
		return JS_UNDEFINED;
	}
	
	static JSValue js_b2WheelJoint_GetMaxMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetMaxMotorTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	
	static JSValue js_b2WheelJoint_GetMotorTorque(JSContext * ctx,JSValue this_val,int argc,JSValue * argv){
		bool error=(bool)0;
		b2JointId jointId=js_getb2JointId(ctx,argv[0],&error);
		if(error==1)return JS_EXCEPTION;
		float returnVal=b2WheelJoint_GetMotorTorque(jointId);
		JSValue ret=JS_NewFloat64(ctx,((double)returnVal));
		return ret;
	}
	static const JSCFunctionListEntry jsbox2d_funcs[]={
		JS_CFUNC_DEF("b2GetByteCount",0,js_b2GetByteCount),
		JS_CFUNC_DEF("b2GetVersion",0,js_b2GetVersion),
		JS_CFUNC_DEF("b2GetTicks",0,js_b2GetTicks),
		JS_CFUNC_DEF("b2GetMilliseconds",1,js_b2GetMilliseconds),
		JS_CFUNC_DEF("b2Yield",0,js_b2Yield),
		JS_CFUNC_DEF("b2IsValidFloat",1,js_b2IsValidFloat),
		JS_CFUNC_DEF("b2IsValidVec2",1,js_b2IsValidVec2),
		JS_CFUNC_DEF("b2IsValidRotation",1,js_b2IsValidRotation),
		JS_CFUNC_DEF("b2IsValidAABB",1,js_b2IsValidAABB),
		JS_CFUNC_DEF("b2IsValidPlane",1,js_b2IsValidPlane),
		JS_CFUNC_DEF("b2MinInt",2,js_b2MinInt),
		JS_CFUNC_DEF("b2MaxInt",2,js_b2MaxInt),
		JS_CFUNC_DEF("b2AbsInt",1,js_b2AbsInt),
		JS_CFUNC_DEF("b2ClampInt",3,js_b2ClampInt),
		JS_CFUNC_DEF("b2MinFloat",2,js_b2MinFloat),
		JS_CFUNC_DEF("b2MaxFloat",2,js_b2MaxFloat),
		JS_CFUNC_DEF("b2AbsFloat",1,js_b2AbsFloat),
		JS_CFUNC_DEF("b2ClampFloat",3,js_b2ClampFloat),
		JS_CFUNC_DEF("b2Atan2",2,js_b2Atan2),
		JS_CFUNC_DEF("b2ComputeCosSin",1,js_b2ComputeCosSin),
		JS_CFUNC_DEF("b2Dot",2,js_b2Dot),
		JS_CFUNC_DEF("b2Cross",2,js_b2Cross),
		JS_CFUNC_DEF("b2CrossVS",2,js_b2CrossVS),
		JS_CFUNC_DEF("b2CrossSV",2,js_b2CrossSV),
		JS_CFUNC_DEF("b2LeftPerp",1,js_b2LeftPerp),
		JS_CFUNC_DEF("b2RightPerp",1,js_b2RightPerp),
		JS_CFUNC_DEF("b2Add",2,js_b2Add),
		JS_CFUNC_DEF("b2Sub",2,js_b2Sub),
		JS_CFUNC_DEF("b2Neg",1,js_b2Neg),
		JS_CFUNC_DEF("b2Lerp",3,js_b2Lerp),
		JS_CFUNC_DEF("b2Mul",2,js_b2Mul),
		JS_CFUNC_DEF("b2MulSV",2,js_b2MulSV),
		JS_CFUNC_DEF("b2MulAdd",3,js_b2MulAdd),
		JS_CFUNC_DEF("b2MulSub",3,js_b2MulSub),
		JS_CFUNC_DEF("b2Abs",1,js_b2Abs),
		JS_CFUNC_DEF("b2Min",2,js_b2Min),
		JS_CFUNC_DEF("b2Max",2,js_b2Max),
		JS_CFUNC_DEF("b2Clamp",3,js_b2Clamp),
		JS_CFUNC_DEF("b2Length",1,js_b2Length),
		JS_CFUNC_DEF("b2Distance",2,js_b2Distance),
		JS_CFUNC_DEF("b2Normalize",1,js_b2Normalize),
		JS_CFUNC_DEF("b2IsNormalized",1,js_b2IsNormalized),
		JS_CFUNC_DEF("b2GetLengthAndNormalize",2,js_b2GetLengthAndNormalize),
		JS_CFUNC_DEF("b2NormalizeRot",1,js_b2NormalizeRot),
		JS_CFUNC_DEF("b2IntegrateRotation",2,js_b2IntegrateRotation),
		JS_CFUNC_DEF("b2LengthSquared",1,js_b2LengthSquared),
		JS_CFUNC_DEF("b2DistanceSquared",2,js_b2DistanceSquared),
		JS_CFUNC_DEF("b2MakeRot",1,js_b2MakeRot),
		JS_CFUNC_DEF("b2ComputeRotationBetweenUnitVectors",2,js_b2ComputeRotationBetweenUnitVectors),
		JS_CFUNC_DEF("b2IsNormalizedRot",1,js_b2IsNormalizedRot),
		JS_CFUNC_DEF("b2NLerp",3,js_b2NLerp),
		JS_CFUNC_DEF("b2ComputeAngularVelocity",3,js_b2ComputeAngularVelocity),
		JS_CFUNC_DEF("b2Rot_GetAngle",1,js_b2Rot_GetAngle),
		JS_CFUNC_DEF("b2Rot_GetXAxis",1,js_b2Rot_GetXAxis),
		JS_CFUNC_DEF("b2Rot_GetYAxis",1,js_b2Rot_GetYAxis),
		JS_CFUNC_DEF("b2MulRot",2,js_b2MulRot),
		JS_CFUNC_DEF("b2InvMulRot",2,js_b2InvMulRot),
		JS_CFUNC_DEF("b2RelativeAngle",2,js_b2RelativeAngle),
		JS_CFUNC_DEF("b2UnwindAngle",1,js_b2UnwindAngle),
		JS_CFUNC_DEF("b2RotateVector",2,js_b2RotateVector),
		JS_CFUNC_DEF("b2InvRotateVector",2,js_b2InvRotateVector),
		JS_CFUNC_DEF("b2TransformPoint",2,js_b2TransformPoint),
		JS_CFUNC_DEF("b2InvTransformPoint",2,js_b2InvTransformPoint),
		JS_CFUNC_DEF("b2MulTransforms",2,js_b2MulTransforms),
		JS_CFUNC_DEF("b2InvMulTransforms",2,js_b2InvMulTransforms),
		JS_CFUNC_DEF("b2MulMV",2,js_b2MulMV),
		JS_CFUNC_DEF("b2GetInverse22",1,js_b2GetInverse22),
		JS_CFUNC_DEF("b2Solve22",2,js_b2Solve22),
		JS_CFUNC_DEF("b2AABB_Contains",2,js_b2AABB_Contains),
		JS_CFUNC_DEF("b2AABB_Center",1,js_b2AABB_Center),
		JS_CFUNC_DEF("b2AABB_Extents",1,js_b2AABB_Extents),
		JS_CFUNC_DEF("b2AABB_Union",2,js_b2AABB_Union),
		JS_CFUNC_DEF("b2AABB_Overlaps",2,js_b2AABB_Overlaps),
		JS_CFUNC_DEF("b2MakeAABB",3,js_b2MakeAABB),
		JS_CFUNC_DEF("b2PlaneSeparation",2,js_b2PlaneSeparation),
		JS_CFUNC_DEF("b2SpringDamper",5,js_b2SpringDamper),
		JS_CFUNC_DEF("b2SetLengthUnitsPerMeter",1,js_b2SetLengthUnitsPerMeter),
		JS_CFUNC_DEF("b2GetLengthUnitsPerMeter",0,js_b2GetLengthUnitsPerMeter),
		JS_CFUNC_DEF("b2IsValidRay",1,js_b2IsValidRay),
		JS_CFUNC_DEF("b2MakePolygon",2,js_b2MakePolygon),
		JS_CFUNC_DEF("b2MakeOffsetPolygon",3,js_b2MakeOffsetPolygon),
		JS_CFUNC_DEF("b2MakeOffsetRoundedPolygon",4,js_b2MakeOffsetRoundedPolygon),
		JS_CFUNC_DEF("b2MakeSquare",1,js_b2MakeSquare),
		JS_CFUNC_DEF("b2MakeBox",2,js_b2MakeBox),
		JS_CFUNC_DEF("b2MakeRoundedBox",3,js_b2MakeRoundedBox),
		JS_CFUNC_DEF("b2MakeOffsetBox",4,js_b2MakeOffsetBox),
		JS_CFUNC_DEF("b2MakeOffsetRoundedBox",5,js_b2MakeOffsetRoundedBox),
		JS_CFUNC_DEF("b2TransformPolygon",2,js_b2TransformPolygon),
		JS_CFUNC_DEF("b2ComputeCircleMass",2,js_b2ComputeCircleMass),
		JS_CFUNC_DEF("b2ComputeCapsuleMass",2,js_b2ComputeCapsuleMass),
		JS_CFUNC_DEF("b2ComputePolygonMass",2,js_b2ComputePolygonMass),
		JS_CFUNC_DEF("b2ComputeCircleAABB",2,js_b2ComputeCircleAABB),
		JS_CFUNC_DEF("b2ComputeCapsuleAABB",2,js_b2ComputeCapsuleAABB),
		JS_CFUNC_DEF("b2ComputePolygonAABB",2,js_b2ComputePolygonAABB),
		JS_CFUNC_DEF("b2ComputeSegmentAABB",2,js_b2ComputeSegmentAABB),
		JS_CFUNC_DEF("b2PointInCircle",2,js_b2PointInCircle),
		JS_CFUNC_DEF("b2PointInCapsule",2,js_b2PointInCapsule),
		JS_CFUNC_DEF("b2PointInPolygon",2,js_b2PointInPolygon),
		JS_CFUNC_DEF("b2RayCastCircle",2,js_b2RayCastCircle),
		JS_CFUNC_DEF("b2RayCastCapsule",2,js_b2RayCastCapsule),
		JS_CFUNC_DEF("b2RayCastSegment",3,js_b2RayCastSegment),
		JS_CFUNC_DEF("b2RayCastPolygon",2,js_b2RayCastPolygon),
		JS_CFUNC_DEF("b2ShapeCastCircle",2,js_b2ShapeCastCircle),
		JS_CFUNC_DEF("b2ShapeCastCapsule",2,js_b2ShapeCastCapsule),
		JS_CFUNC_DEF("b2ShapeCastSegment",2,js_b2ShapeCastSegment),
		JS_CFUNC_DEF("b2ShapeCastPolygon",2,js_b2ShapeCastPolygon),
		JS_CFUNC_DEF("b2ComputeHull",2,js_b2ComputeHull),
		JS_CFUNC_DEF("b2ValidateHull",1,js_b2ValidateHull),
		JS_CFUNC_DEF("b2SegmentDistance",4,js_b2SegmentDistance),
		JS_CFUNC_DEF("b2ShapeCast",1,js_b2ShapeCast),
		JS_CFUNC_DEF("b2MakeProxy",3,js_b2MakeProxy),
		JS_CFUNC_DEF("b2MakeOffsetProxy",5,js_b2MakeOffsetProxy),
		JS_CFUNC_DEF("b2GetSweepTransform",2,js_b2GetSweepTransform),
		JS_CFUNC_DEF("b2TimeOfImpact",1,js_b2TimeOfImpact),
		JS_CFUNC_DEF("b2CollideCircles",4,js_b2CollideCircles),
		JS_CFUNC_DEF("b2CollideCapsules",4,js_b2CollideCapsules),
		JS_CFUNC_DEF("b2CollidePolygons",4,js_b2CollidePolygons),
		JS_CFUNC_DEF("b2DynamicTree_Create",0,js_b2DynamicTree_Create),
		JS_CFUNC_DEF("b2DynamicTree_Destroy",1,js_b2DynamicTree_Destroy),
		JS_CFUNC_DEF("b2DynamicTree_CreateProxy",4,js_b2DynamicTree_CreateProxy),
		JS_CFUNC_DEF("b2DynamicTree_DestroyProxy",2,js_b2DynamicTree_DestroyProxy),
		JS_CFUNC_DEF("b2DynamicTree_MoveProxy",3,js_b2DynamicTree_MoveProxy),
		JS_CFUNC_DEF("b2DynamicTree_EnlargeProxy",3,js_b2DynamicTree_EnlargeProxy),
		JS_CFUNC_DEF("b2DynamicTree_SetCategoryBits",3,js_b2DynamicTree_SetCategoryBits),
		JS_CFUNC_DEF("b2DynamicTree_GetCategoryBits",2,js_b2DynamicTree_GetCategoryBits),
		JS_CFUNC_DEF("b2DynamicTree_GetHeight",1,js_b2DynamicTree_GetHeight),
		JS_CFUNC_DEF("b2DynamicTree_GetAreaRatio",1,js_b2DynamicTree_GetAreaRatio),
		JS_CFUNC_DEF("b2DynamicTree_GetRootBounds",1,js_b2DynamicTree_GetRootBounds),
		JS_CFUNC_DEF("b2DynamicTree_GetProxyCount",1,js_b2DynamicTree_GetProxyCount),
		JS_CFUNC_DEF("b2DynamicTree_Rebuild",2,js_b2DynamicTree_Rebuild),
		JS_CFUNC_DEF("b2DynamicTree_GetByteCount",1,js_b2DynamicTree_GetByteCount),
		JS_CFUNC_DEF("b2DynamicTree_GetUserData",2,js_b2DynamicTree_GetUserData),
		JS_CFUNC_DEF("b2DynamicTree_GetAABB",2,js_b2DynamicTree_GetAABB),
		JS_CFUNC_DEF("b2DynamicTree_Validate",1,js_b2DynamicTree_Validate),
		JS_CFUNC_DEF("b2DynamicTree_ValidateNoEnlarged",1,js_b2DynamicTree_ValidateNoEnlarged),
		JS_CFUNC_DEF("b2SolvePlanes",3,js_b2SolvePlanes),
		JS_CFUNC_DEF("b2ClipVector",3,js_b2ClipVector),
		JS_CFUNC_DEF("b2StoreWorldId",1,js_b2StoreWorldId),
		JS_CFUNC_DEF("b2LoadWorldId",1,js_b2LoadWorldId),
		JS_CFUNC_DEF("b2StoreBodyId",1,js_b2StoreBodyId),
		JS_CFUNC_DEF("b2LoadBodyId",1,js_b2LoadBodyId),
		JS_CFUNC_DEF("b2StoreShapeId",1,js_b2StoreShapeId),
		JS_CFUNC_DEF("b2LoadShapeId",1,js_b2LoadShapeId),
		JS_CFUNC_DEF("b2StoreChainId",1,js_b2StoreChainId),
		JS_CFUNC_DEF("b2LoadChainId",1,js_b2LoadChainId),
		JS_CFUNC_DEF("b2StoreJointId",1,js_b2StoreJointId),
		JS_CFUNC_DEF("b2LoadJointId",1,js_b2LoadJointId),
		JS_CFUNC_DEF("b2DefaultWorldDef",0,js_b2DefaultWorldDef),
		JS_CFUNC_DEF("b2DefaultBodyDef",0,js_b2DefaultBodyDef),
		JS_CFUNC_DEF("b2DefaultFilter",0,js_b2DefaultFilter),
		JS_CFUNC_DEF("b2DefaultQueryFilter",0,js_b2DefaultQueryFilter),
		JS_CFUNC_DEF("b2DefaultSurfaceMaterial",0,js_b2DefaultSurfaceMaterial),
		JS_CFUNC_DEF("b2DefaultShapeDef",0,js_b2DefaultShapeDef),
		JS_CFUNC_DEF("b2DefaultChainDef",0,js_b2DefaultChainDef),
		JS_CFUNC_DEF("b2DefaultDistanceJointDef",0,js_b2DefaultDistanceJointDef),
		JS_CFUNC_DEF("b2DefaultMotorJointDef",0,js_b2DefaultMotorJointDef),
		JS_CFUNC_DEF("b2DefaultMouseJointDef",0,js_b2DefaultMouseJointDef),
		JS_CFUNC_DEF("b2DefaultFilterJointDef",0,js_b2DefaultFilterJointDef),
		JS_CFUNC_DEF("b2DefaultPrismaticJointDef",0,js_b2DefaultPrismaticJointDef),
		JS_CFUNC_DEF("b2DefaultRevoluteJointDef",0,js_b2DefaultRevoluteJointDef),
		JS_CFUNC_DEF("b2DefaultWeldJointDef",0,js_b2DefaultWeldJointDef),
		JS_CFUNC_DEF("b2DefaultWheelJointDef",0,js_b2DefaultWheelJointDef),
		JS_CFUNC_DEF("b2DefaultExplosionDef",0,js_b2DefaultExplosionDef),
		JS_CFUNC_DEF("b2DefaultDebugDraw",0,js_b2DefaultDebugDraw),
		JS_CFUNC_DEF("b2CreateWorld",1,js_b2CreateWorld),
		JS_CFUNC_DEF("b2DestroyWorld",1,js_b2DestroyWorld),
		JS_CFUNC_DEF("b2World_IsValid",1,js_b2World_IsValid),
		JS_CFUNC_DEF("b2World_Step",3,js_b2World_Step),
		JS_CFUNC_DEF("b2World_GetBodyEvents",1,js_b2World_GetBodyEvents),
		JS_CFUNC_DEF("b2World_GetSensorEvents",1,js_b2World_GetSensorEvents),
		JS_CFUNC_DEF("b2World_GetContactEvents",1,js_b2World_GetContactEvents),
		JS_CFUNC_DEF("b2World_CastRayClosest",4,js_b2World_CastRayClosest),
		JS_CFUNC_DEF("b2World_CastMover",4,js_b2World_CastMover),
		JS_CFUNC_DEF("b2World_EnableSleeping",2,js_b2World_EnableSleeping),
		JS_CFUNC_DEF("b2World_IsSleepingEnabled",1,js_b2World_IsSleepingEnabled),
		JS_CFUNC_DEF("b2World_EnableContinuous",2,js_b2World_EnableContinuous),
		JS_CFUNC_DEF("b2World_IsContinuousEnabled",1,js_b2World_IsContinuousEnabled),
		JS_CFUNC_DEF("b2World_SetRestitutionThreshold",2,js_b2World_SetRestitutionThreshold),
		JS_CFUNC_DEF("b2World_GetRestitutionThreshold",1,js_b2World_GetRestitutionThreshold),
		JS_CFUNC_DEF("b2World_SetHitEventThreshold",2,js_b2World_SetHitEventThreshold),
		JS_CFUNC_DEF("b2World_GetHitEventThreshold",1,js_b2World_GetHitEventThreshold),
		JS_CFUNC_DEF("b2World_SetGravity",2,js_b2World_SetGravity),
		JS_CFUNC_DEF("b2World_GetGravity",1,js_b2World_GetGravity),
		JS_CFUNC_DEF("b2World_Explode",2,js_b2World_Explode),
		JS_CFUNC_DEF("b2World_SetContactTuning",4,js_b2World_SetContactTuning),
		JS_CFUNC_DEF("b2World_SetMaximumLinearSpeed",2,js_b2World_SetMaximumLinearSpeed),
		JS_CFUNC_DEF("b2World_GetMaximumLinearSpeed",1,js_b2World_GetMaximumLinearSpeed),
		JS_CFUNC_DEF("b2World_EnableWarmStarting",2,js_b2World_EnableWarmStarting),
		JS_CFUNC_DEF("b2World_IsWarmStartingEnabled",1,js_b2World_IsWarmStartingEnabled),
		JS_CFUNC_DEF("b2World_GetAwakeBodyCount",1,js_b2World_GetAwakeBodyCount),
		JS_CFUNC_DEF("b2World_GetProfile",1,js_b2World_GetProfile),
		JS_CFUNC_DEF("b2World_GetCounters",1,js_b2World_GetCounters),
		JS_CFUNC_DEF("b2World_SetFrictionCallback",2,js_b2World_SetFrictionCallback),
		JS_CFUNC_DEF("b2World_SetRestitutionCallback",2,js_b2World_SetRestitutionCallback),
		JS_CFUNC_DEF("b2World_DumpMemoryStats",1,js_b2World_DumpMemoryStats),
		JS_CFUNC_DEF("b2World_RebuildStaticTree",1,js_b2World_RebuildStaticTree),
		JS_CFUNC_DEF("b2World_EnableSpeculative",2,js_b2World_EnableSpeculative),
		JS_CFUNC_DEF("b2CreateBody",2,js_b2CreateBody),
		JS_CFUNC_DEF("b2DestroyBody",1,js_b2DestroyBody),
		JS_CFUNC_DEF("b2Body_IsValid",1,js_b2Body_IsValid),
		JS_CFUNC_DEF("b2Body_GetType",1,js_b2Body_GetType),
		JS_CFUNC_DEF("b2Body_SetType",2,js_b2Body_SetType),
		JS_CFUNC_DEF("b2Body_SetName",2,js_b2Body_SetName),
		JS_CFUNC_DEF("b2Body_GetName",1,js_b2Body_GetName),
		JS_CFUNC_DEF("b2Body_GetPosition",1,js_b2Body_GetPosition),
		JS_CFUNC_DEF("b2Body_GetRotation",1,js_b2Body_GetRotation),
		JS_CFUNC_DEF("b2Body_GetTransform",1,js_b2Body_GetTransform),
		JS_CFUNC_DEF("b2Body_SetTransform",3,js_b2Body_SetTransform),
		JS_CFUNC_DEF("b2Body_GetLocalPoint",2,js_b2Body_GetLocalPoint),
		JS_CFUNC_DEF("b2Body_GetWorldPoint",2,js_b2Body_GetWorldPoint),
		JS_CFUNC_DEF("b2Body_GetLocalVector",2,js_b2Body_GetLocalVector),
		JS_CFUNC_DEF("b2Body_GetWorldVector",2,js_b2Body_GetWorldVector),
		JS_CFUNC_DEF("b2Body_GetLinearVelocity",1,js_b2Body_GetLinearVelocity),
		JS_CFUNC_DEF("b2Body_GetAngularVelocity",1,js_b2Body_GetAngularVelocity),
		JS_CFUNC_DEF("b2Body_SetLinearVelocity",2,js_b2Body_SetLinearVelocity),
		JS_CFUNC_DEF("b2Body_SetAngularVelocity",2,js_b2Body_SetAngularVelocity),
		JS_CFUNC_DEF("b2Body_SetTargetTransform",3,js_b2Body_SetTargetTransform),
		JS_CFUNC_DEF("b2Body_GetLocalPointVelocity",2,js_b2Body_GetLocalPointVelocity),
		JS_CFUNC_DEF("b2Body_GetWorldPointVelocity",2,js_b2Body_GetWorldPointVelocity),
		JS_CFUNC_DEF("b2Body_ApplyForce",4,js_b2Body_ApplyForce),
		JS_CFUNC_DEF("b2Body_ApplyForceToCenter",3,js_b2Body_ApplyForceToCenter),
		JS_CFUNC_DEF("b2Body_ApplyTorque",3,js_b2Body_ApplyTorque),
		JS_CFUNC_DEF("b2Body_ApplyLinearImpulse",4,js_b2Body_ApplyLinearImpulse),
		JS_CFUNC_DEF("b2Body_ApplyLinearImpulseToCenter",3,js_b2Body_ApplyLinearImpulseToCenter),
		JS_CFUNC_DEF("b2Body_ApplyAngularImpulse",3,js_b2Body_ApplyAngularImpulse),
		JS_CFUNC_DEF("b2Body_GetMass",1,js_b2Body_GetMass),
		JS_CFUNC_DEF("b2Body_GetRotationalInertia",1,js_b2Body_GetRotationalInertia),
		JS_CFUNC_DEF("b2Body_GetLocalCenterOfMass",1,js_b2Body_GetLocalCenterOfMass),
		JS_CFUNC_DEF("b2Body_GetWorldCenterOfMass",1,js_b2Body_GetWorldCenterOfMass),
		JS_CFUNC_DEF("b2Body_SetMassData",2,js_b2Body_SetMassData),
		JS_CFUNC_DEF("b2Body_GetMassData",1,js_b2Body_GetMassData),
		JS_CFUNC_DEF("b2Body_ApplyMassFromShapes",1,js_b2Body_ApplyMassFromShapes),
		JS_CFUNC_DEF("b2Body_SetLinearDamping",2,js_b2Body_SetLinearDamping),
		JS_CFUNC_DEF("b2Body_GetLinearDamping",1,js_b2Body_GetLinearDamping),
		JS_CFUNC_DEF("b2Body_SetAngularDamping",2,js_b2Body_SetAngularDamping),
		JS_CFUNC_DEF("b2Body_GetAngularDamping",1,js_b2Body_GetAngularDamping),
		JS_CFUNC_DEF("b2Body_SetGravityScale",2,js_b2Body_SetGravityScale),
		JS_CFUNC_DEF("b2Body_GetGravityScale",1,js_b2Body_GetGravityScale),
		JS_CFUNC_DEF("b2Body_IsAwake",1,js_b2Body_IsAwake),
		JS_CFUNC_DEF("b2Body_SetAwake",2,js_b2Body_SetAwake),
		JS_CFUNC_DEF("b2Body_EnableSleep",2,js_b2Body_EnableSleep),
		JS_CFUNC_DEF("b2Body_IsSleepEnabled",1,js_b2Body_IsSleepEnabled),
		JS_CFUNC_DEF("b2Body_SetSleepThreshold",2,js_b2Body_SetSleepThreshold),
		JS_CFUNC_DEF("b2Body_GetSleepThreshold",1,js_b2Body_GetSleepThreshold),
		JS_CFUNC_DEF("b2Body_IsEnabled",1,js_b2Body_IsEnabled),
		JS_CFUNC_DEF("b2Body_Disable",1,js_b2Body_Disable),
		JS_CFUNC_DEF("b2Body_Enable",1,js_b2Body_Enable),
		JS_CFUNC_DEF("b2Body_SetFixedRotation",2,js_b2Body_SetFixedRotation),
		JS_CFUNC_DEF("b2Body_IsFixedRotation",1,js_b2Body_IsFixedRotation),
		JS_CFUNC_DEF("b2Body_SetBullet",2,js_b2Body_SetBullet),
		JS_CFUNC_DEF("b2Body_IsBullet",1,js_b2Body_IsBullet),
		JS_CFUNC_DEF("b2Body_EnableContactEvents",2,js_b2Body_EnableContactEvents),
		JS_CFUNC_DEF("b2Body_EnableHitEvents",2,js_b2Body_EnableHitEvents),
		JS_CFUNC_DEF("b2Body_GetWorld",1,js_b2Body_GetWorld),
		JS_CFUNC_DEF("b2Body_GetShapeCount",1,js_b2Body_GetShapeCount),
		JS_CFUNC_DEF("b2Body_GetShapes",3,js_b2Body_GetShapes),
		JS_CFUNC_DEF("b2Body_GetJointCount",1,js_b2Body_GetJointCount),
		JS_CFUNC_DEF("b2Body_GetJoints",3,js_b2Body_GetJoints),
		JS_CFUNC_DEF("b2Body_GetContactCapacity",1,js_b2Body_GetContactCapacity),
		JS_CFUNC_DEF("b2Body_ComputeAABB",1,js_b2Body_ComputeAABB),
		JS_CFUNC_DEF("b2CreateCircleShape",3,js_b2CreateCircleShape),
		JS_CFUNC_DEF("b2CreateSegmentShape",3,js_b2CreateSegmentShape),
		JS_CFUNC_DEF("b2CreateCapsuleShape",3,js_b2CreateCapsuleShape),
		JS_CFUNC_DEF("b2CreatePolygonShape",3,js_b2CreatePolygonShape),
		JS_CFUNC_DEF("b2DestroyShape",2,js_b2DestroyShape),
		JS_CFUNC_DEF("b2Shape_IsValid",1,js_b2Shape_IsValid),
		JS_CFUNC_DEF("b2Shape_GetType",1,js_b2Shape_GetType),
		JS_CFUNC_DEF("b2Shape_GetBody",1,js_b2Shape_GetBody),
		JS_CFUNC_DEF("b2Shape_GetWorld",1,js_b2Shape_GetWorld),
		JS_CFUNC_DEF("b2Shape_IsSensor",1,js_b2Shape_IsSensor),
		JS_CFUNC_DEF("b2Shape_SetDensity",3,js_b2Shape_SetDensity),
		JS_CFUNC_DEF("b2Shape_GetDensity",1,js_b2Shape_GetDensity),
		JS_CFUNC_DEF("b2Shape_SetFriction",2,js_b2Shape_SetFriction),
		JS_CFUNC_DEF("b2Shape_GetFriction",1,js_b2Shape_GetFriction),
		JS_CFUNC_DEF("b2Shape_SetRestitution",2,js_b2Shape_SetRestitution),
		JS_CFUNC_DEF("b2Shape_GetRestitution",1,js_b2Shape_GetRestitution),
		JS_CFUNC_DEF("b2Shape_SetMaterial",2,js_b2Shape_SetMaterial),
		JS_CFUNC_DEF("b2Shape_GetMaterial",1,js_b2Shape_GetMaterial),
		JS_CFUNC_DEF("b2Shape_SetSurfaceMaterial",2,js_b2Shape_SetSurfaceMaterial),
		JS_CFUNC_DEF("b2Shape_GetSurfaceMaterial",1,js_b2Shape_GetSurfaceMaterial),
		JS_CFUNC_DEF("b2Shape_GetFilter",1,js_b2Shape_GetFilter),
		JS_CFUNC_DEF("b2Shape_SetFilter",2,js_b2Shape_SetFilter),
		JS_CFUNC_DEF("b2Shape_EnableSensorEvents",2,js_b2Shape_EnableSensorEvents),
		JS_CFUNC_DEF("b2Shape_AreSensorEventsEnabled",1,js_b2Shape_AreSensorEventsEnabled),
		JS_CFUNC_DEF("b2Shape_EnableContactEvents",2,js_b2Shape_EnableContactEvents),
		JS_CFUNC_DEF("b2Shape_AreContactEventsEnabled",1,js_b2Shape_AreContactEventsEnabled),
		JS_CFUNC_DEF("b2Shape_EnablePreSolveEvents",2,js_b2Shape_EnablePreSolveEvents),
		JS_CFUNC_DEF("b2Shape_ArePreSolveEventsEnabled",1,js_b2Shape_ArePreSolveEventsEnabled),
		JS_CFUNC_DEF("b2Shape_EnableHitEvents",2,js_b2Shape_EnableHitEvents),
		JS_CFUNC_DEF("b2Shape_AreHitEventsEnabled",1,js_b2Shape_AreHitEventsEnabled),
		JS_CFUNC_DEF("b2Shape_TestPoint",2,js_b2Shape_TestPoint),
		JS_CFUNC_DEF("b2Shape_RayCast",2,js_b2Shape_RayCast),
		JS_CFUNC_DEF("b2Shape_GetCircle",1,js_b2Shape_GetCircle),
		JS_CFUNC_DEF("b2Shape_GetSegment",1,js_b2Shape_GetSegment),
		JS_CFUNC_DEF("b2Shape_GetChainSegment",1,js_b2Shape_GetChainSegment),
		JS_CFUNC_DEF("b2Shape_GetCapsule",1,js_b2Shape_GetCapsule),
		JS_CFUNC_DEF("b2Shape_GetPolygon",1,js_b2Shape_GetPolygon),
		JS_CFUNC_DEF("b2Shape_SetCircle",2,js_b2Shape_SetCircle),
		JS_CFUNC_DEF("b2Shape_SetCapsule",2,js_b2Shape_SetCapsule),
		JS_CFUNC_DEF("b2Shape_SetSegment",2,js_b2Shape_SetSegment),
		JS_CFUNC_DEF("b2Shape_SetPolygon",2,js_b2Shape_SetPolygon),
		JS_CFUNC_DEF("b2Shape_GetParentChain",1,js_b2Shape_GetParentChain),
		JS_CFUNC_DEF("b2Shape_GetContactCapacity",1,js_b2Shape_GetContactCapacity),
		JS_CFUNC_DEF("b2Shape_GetSensorCapacity",1,js_b2Shape_GetSensorCapacity),
		JS_CFUNC_DEF("b2Shape_GetSensorOverlaps",3,js_b2Shape_GetSensorOverlaps),
		JS_CFUNC_DEF("b2Shape_GetAABB",1,js_b2Shape_GetAABB),
		JS_CFUNC_DEF("b2Shape_GetMassData",1,js_b2Shape_GetMassData),
		JS_CFUNC_DEF("b2Shape_GetClosestPoint",2,js_b2Shape_GetClosestPoint),
		JS_CFUNC_DEF("b2CreateChain",2,js_b2CreateChain),
		JS_CFUNC_DEF("b2DestroyChain",1,js_b2DestroyChain),
		JS_CFUNC_DEF("b2Chain_GetWorld",1,js_b2Chain_GetWorld),
		JS_CFUNC_DEF("b2Chain_GetSegmentCount",1,js_b2Chain_GetSegmentCount),
		JS_CFUNC_DEF("b2Chain_GetSegments",3,js_b2Chain_GetSegments),
		JS_CFUNC_DEF("b2Chain_SetFriction",2,js_b2Chain_SetFriction),
		JS_CFUNC_DEF("b2Chain_GetFriction",1,js_b2Chain_GetFriction),
		JS_CFUNC_DEF("b2Chain_SetRestitution",2,js_b2Chain_SetRestitution),
		JS_CFUNC_DEF("b2Chain_GetRestitution",1,js_b2Chain_GetRestitution),
		JS_CFUNC_DEF("b2Chain_SetMaterial",2,js_b2Chain_SetMaterial),
		JS_CFUNC_DEF("b2Chain_GetMaterial",1,js_b2Chain_GetMaterial),
		JS_CFUNC_DEF("b2Chain_IsValid",1,js_b2Chain_IsValid),
		JS_CFUNC_DEF("b2DestroyJoint",1,js_b2DestroyJoint),
		JS_CFUNC_DEF("b2Joint_IsValid",1,js_b2Joint_IsValid),
		JS_CFUNC_DEF("b2Joint_GetType",1,js_b2Joint_GetType),
		JS_CFUNC_DEF("b2Joint_GetBodyA",1,js_b2Joint_GetBodyA),
		JS_CFUNC_DEF("b2Joint_GetBodyB",1,js_b2Joint_GetBodyB),
		JS_CFUNC_DEF("b2Joint_GetWorld",1,js_b2Joint_GetWorld),
		JS_CFUNC_DEF("b2Joint_SetLocalAnchorA",2,js_b2Joint_SetLocalAnchorA),
		JS_CFUNC_DEF("b2Joint_GetLocalAnchorA",1,js_b2Joint_GetLocalAnchorA),
		JS_CFUNC_DEF("b2Joint_SetLocalAnchorB",2,js_b2Joint_SetLocalAnchorB),
		JS_CFUNC_DEF("b2Joint_GetLocalAnchorB",1,js_b2Joint_GetLocalAnchorB),
		JS_CFUNC_DEF("b2Joint_GetReferenceAngle",1,js_b2Joint_GetReferenceAngle),
		JS_CFUNC_DEF("b2Joint_SetReferenceAngle",2,js_b2Joint_SetReferenceAngle),
		JS_CFUNC_DEF("b2Joint_SetLocalAxisA",2,js_b2Joint_SetLocalAxisA),
		JS_CFUNC_DEF("b2Joint_GetLocalAxisA",1,js_b2Joint_GetLocalAxisA),
		JS_CFUNC_DEF("b2Joint_SetCollideConnected",2,js_b2Joint_SetCollideConnected),
		JS_CFUNC_DEF("b2Joint_GetCollideConnected",1,js_b2Joint_GetCollideConnected),
		JS_CFUNC_DEF("b2Joint_WakeBodies",1,js_b2Joint_WakeBodies),
		JS_CFUNC_DEF("b2Joint_GetConstraintForce",1,js_b2Joint_GetConstraintForce),
		JS_CFUNC_DEF("b2Joint_GetConstraintTorque",1,js_b2Joint_GetConstraintTorque),
		JS_CFUNC_DEF("b2Joint_GetLinearSeparation",1,js_b2Joint_GetLinearSeparation),
		JS_CFUNC_DEF("b2Joint_GetAngularSeparation",1,js_b2Joint_GetAngularSeparation),
		JS_CFUNC_DEF("b2Joint_GetConstraintTuning",3,js_b2Joint_GetConstraintTuning),
		JS_CFUNC_DEF("b2Joint_SetConstraintTuning",3,js_b2Joint_SetConstraintTuning),
		JS_CFUNC_DEF("b2CreateDistanceJoint",2,js_b2CreateDistanceJoint),
		JS_CFUNC_DEF("b2DistanceJoint_SetLength",2,js_b2DistanceJoint_SetLength),
		JS_CFUNC_DEF("b2DistanceJoint_GetLength",1,js_b2DistanceJoint_GetLength),
		JS_CFUNC_DEF("b2DistanceJoint_EnableSpring",2,js_b2DistanceJoint_EnableSpring),
		JS_CFUNC_DEF("b2DistanceJoint_IsSpringEnabled",1,js_b2DistanceJoint_IsSpringEnabled),
		JS_CFUNC_DEF("b2DistanceJoint_SetSpringHertz",2,js_b2DistanceJoint_SetSpringHertz),
		JS_CFUNC_DEF("b2DistanceJoint_SetSpringDampingRatio",2,js_b2DistanceJoint_SetSpringDampingRatio),
		JS_CFUNC_DEF("b2DistanceJoint_GetSpringHertz",1,js_b2DistanceJoint_GetSpringHertz),
		JS_CFUNC_DEF("b2DistanceJoint_GetSpringDampingRatio",1,js_b2DistanceJoint_GetSpringDampingRatio),
		JS_CFUNC_DEF("b2DistanceJoint_EnableLimit",2,js_b2DistanceJoint_EnableLimit),
		JS_CFUNC_DEF("b2DistanceJoint_IsLimitEnabled",1,js_b2DistanceJoint_IsLimitEnabled),
		JS_CFUNC_DEF("b2DistanceJoint_SetLengthRange",3,js_b2DistanceJoint_SetLengthRange),
		JS_CFUNC_DEF("b2DistanceJoint_GetMinLength",1,js_b2DistanceJoint_GetMinLength),
		JS_CFUNC_DEF("b2DistanceJoint_GetMaxLength",1,js_b2DistanceJoint_GetMaxLength),
		JS_CFUNC_DEF("b2DistanceJoint_GetCurrentLength",1,js_b2DistanceJoint_GetCurrentLength),
		JS_CFUNC_DEF("b2DistanceJoint_EnableMotor",2,js_b2DistanceJoint_EnableMotor),
		JS_CFUNC_DEF("b2DistanceJoint_IsMotorEnabled",1,js_b2DistanceJoint_IsMotorEnabled),
		JS_CFUNC_DEF("b2DistanceJoint_SetMotorSpeed",2,js_b2DistanceJoint_SetMotorSpeed),
		JS_CFUNC_DEF("b2DistanceJoint_GetMotorSpeed",1,js_b2DistanceJoint_GetMotorSpeed),
		JS_CFUNC_DEF("b2DistanceJoint_SetMaxMotorForce",2,js_b2DistanceJoint_SetMaxMotorForce),
		JS_CFUNC_DEF("b2DistanceJoint_GetMaxMotorForce",1,js_b2DistanceJoint_GetMaxMotorForce),
		JS_CFUNC_DEF("b2DistanceJoint_GetMotorForce",1,js_b2DistanceJoint_GetMotorForce),
		JS_CFUNC_DEF("b2CreateMotorJoint",2,js_b2CreateMotorJoint),
		JS_CFUNC_DEF("b2MotorJoint_SetLinearOffset",2,js_b2MotorJoint_SetLinearOffset),
		JS_CFUNC_DEF("b2MotorJoint_GetLinearOffset",1,js_b2MotorJoint_GetLinearOffset),
		JS_CFUNC_DEF("b2MotorJoint_SetAngularOffset",2,js_b2MotorJoint_SetAngularOffset),
		JS_CFUNC_DEF("b2MotorJoint_GetAngularOffset",1,js_b2MotorJoint_GetAngularOffset),
		JS_CFUNC_DEF("b2MotorJoint_SetMaxForce",2,js_b2MotorJoint_SetMaxForce),
		JS_CFUNC_DEF("b2MotorJoint_GetMaxForce",1,js_b2MotorJoint_GetMaxForce),
		JS_CFUNC_DEF("b2MotorJoint_SetMaxTorque",2,js_b2MotorJoint_SetMaxTorque),
		JS_CFUNC_DEF("b2MotorJoint_GetMaxTorque",1,js_b2MotorJoint_GetMaxTorque),
		JS_CFUNC_DEF("b2MotorJoint_SetCorrectionFactor",2,js_b2MotorJoint_SetCorrectionFactor),
		JS_CFUNC_DEF("b2MotorJoint_GetCorrectionFactor",1,js_b2MotorJoint_GetCorrectionFactor),
		JS_CFUNC_DEF("b2CreateMouseJoint",2,js_b2CreateMouseJoint),
		JS_CFUNC_DEF("b2MouseJoint_SetTarget",2,js_b2MouseJoint_SetTarget),
		JS_CFUNC_DEF("b2MouseJoint_GetTarget",1,js_b2MouseJoint_GetTarget),
		JS_CFUNC_DEF("b2MouseJoint_SetSpringHertz",2,js_b2MouseJoint_SetSpringHertz),
		JS_CFUNC_DEF("b2MouseJoint_GetSpringHertz",1,js_b2MouseJoint_GetSpringHertz),
		JS_CFUNC_DEF("b2MouseJoint_SetSpringDampingRatio",2,js_b2MouseJoint_SetSpringDampingRatio),
		JS_CFUNC_DEF("b2MouseJoint_GetSpringDampingRatio",1,js_b2MouseJoint_GetSpringDampingRatio),
		JS_CFUNC_DEF("b2MouseJoint_SetMaxForce",2,js_b2MouseJoint_SetMaxForce),
		JS_CFUNC_DEF("b2MouseJoint_GetMaxForce",1,js_b2MouseJoint_GetMaxForce),
		JS_CFUNC_DEF("b2CreateFilterJoint",2,js_b2CreateFilterJoint),
		JS_CFUNC_DEF("b2CreatePrismaticJoint",2,js_b2CreatePrismaticJoint),
		JS_CFUNC_DEF("b2PrismaticJoint_EnableSpring",2,js_b2PrismaticJoint_EnableSpring),
		JS_CFUNC_DEF("b2PrismaticJoint_IsSpringEnabled",1,js_b2PrismaticJoint_IsSpringEnabled),
		JS_CFUNC_DEF("b2PrismaticJoint_SetSpringHertz",2,js_b2PrismaticJoint_SetSpringHertz),
		JS_CFUNC_DEF("b2PrismaticJoint_GetSpringHertz",1,js_b2PrismaticJoint_GetSpringHertz),
		JS_CFUNC_DEF("b2PrismaticJoint_SetSpringDampingRatio",2,js_b2PrismaticJoint_SetSpringDampingRatio),
		JS_CFUNC_DEF("b2PrismaticJoint_GetSpringDampingRatio",1,js_b2PrismaticJoint_GetSpringDampingRatio),
		JS_CFUNC_DEF("b2PrismaticJoint_SetTargetTranslation",2,js_b2PrismaticJoint_SetTargetTranslation),
		JS_CFUNC_DEF("b2PrismaticJoint_GetTargetTranslation",1,js_b2PrismaticJoint_GetTargetTranslation),
		JS_CFUNC_DEF("b2PrismaticJoint_EnableLimit",2,js_b2PrismaticJoint_EnableLimit),
		JS_CFUNC_DEF("b2PrismaticJoint_IsLimitEnabled",1,js_b2PrismaticJoint_IsLimitEnabled),
		JS_CFUNC_DEF("b2PrismaticJoint_GetLowerLimit",1,js_b2PrismaticJoint_GetLowerLimit),
		JS_CFUNC_DEF("b2PrismaticJoint_GetUpperLimit",1,js_b2PrismaticJoint_GetUpperLimit),
		JS_CFUNC_DEF("b2PrismaticJoint_SetLimits",3,js_b2PrismaticJoint_SetLimits),
		JS_CFUNC_DEF("b2PrismaticJoint_EnableMotor",2,js_b2PrismaticJoint_EnableMotor),
		JS_CFUNC_DEF("b2PrismaticJoint_IsMotorEnabled",1,js_b2PrismaticJoint_IsMotorEnabled),
		JS_CFUNC_DEF("b2PrismaticJoint_SetMotorSpeed",2,js_b2PrismaticJoint_SetMotorSpeed),
		JS_CFUNC_DEF("b2PrismaticJoint_GetMotorSpeed",1,js_b2PrismaticJoint_GetMotorSpeed),
		JS_CFUNC_DEF("b2PrismaticJoint_SetMaxMotorForce",2,js_b2PrismaticJoint_SetMaxMotorForce),
		JS_CFUNC_DEF("b2PrismaticJoint_GetMaxMotorForce",1,js_b2PrismaticJoint_GetMaxMotorForce),
		JS_CFUNC_DEF("b2PrismaticJoint_GetMotorForce",1,js_b2PrismaticJoint_GetMotorForce),
		JS_CFUNC_DEF("b2PrismaticJoint_GetTranslation",1,js_b2PrismaticJoint_GetTranslation),
		JS_CFUNC_DEF("b2PrismaticJoint_GetSpeed",1,js_b2PrismaticJoint_GetSpeed),
		JS_CFUNC_DEF("b2CreateRevoluteJoint",2,js_b2CreateRevoluteJoint),
		JS_CFUNC_DEF("b2RevoluteJoint_EnableSpring",2,js_b2RevoluteJoint_EnableSpring),
		JS_CFUNC_DEF("b2RevoluteJoint_IsSpringEnabled",1,js_b2RevoluteJoint_IsSpringEnabled),
		JS_CFUNC_DEF("b2RevoluteJoint_SetSpringHertz",2,js_b2RevoluteJoint_SetSpringHertz),
		JS_CFUNC_DEF("b2RevoluteJoint_GetSpringHertz",1,js_b2RevoluteJoint_GetSpringHertz),
		JS_CFUNC_DEF("b2RevoluteJoint_SetSpringDampingRatio",2,js_b2RevoluteJoint_SetSpringDampingRatio),
		JS_CFUNC_DEF("b2RevoluteJoint_GetSpringDampingRatio",1,js_b2RevoluteJoint_GetSpringDampingRatio),
		JS_CFUNC_DEF("b2RevoluteJoint_SetTargetAngle",2,js_b2RevoluteJoint_SetTargetAngle),
		JS_CFUNC_DEF("b2RevoluteJoint_GetTargetAngle",1,js_b2RevoluteJoint_GetTargetAngle),
		JS_CFUNC_DEF("b2RevoluteJoint_GetAngle",1,js_b2RevoluteJoint_GetAngle),
		JS_CFUNC_DEF("b2RevoluteJoint_EnableLimit",2,js_b2RevoluteJoint_EnableLimit),
		JS_CFUNC_DEF("b2RevoluteJoint_IsLimitEnabled",1,js_b2RevoluteJoint_IsLimitEnabled),
		JS_CFUNC_DEF("b2RevoluteJoint_GetLowerLimit",1,js_b2RevoluteJoint_GetLowerLimit),
		JS_CFUNC_DEF("b2RevoluteJoint_GetUpperLimit",1,js_b2RevoluteJoint_GetUpperLimit),
		JS_CFUNC_DEF("b2RevoluteJoint_SetLimits",3,js_b2RevoluteJoint_SetLimits),
		JS_CFUNC_DEF("b2RevoluteJoint_EnableMotor",2,js_b2RevoluteJoint_EnableMotor),
		JS_CFUNC_DEF("b2RevoluteJoint_IsMotorEnabled",1,js_b2RevoluteJoint_IsMotorEnabled),
		JS_CFUNC_DEF("b2RevoluteJoint_SetMotorSpeed",2,js_b2RevoluteJoint_SetMotorSpeed),
		JS_CFUNC_DEF("b2RevoluteJoint_GetMotorSpeed",1,js_b2RevoluteJoint_GetMotorSpeed),
		JS_CFUNC_DEF("b2RevoluteJoint_GetMotorTorque",1,js_b2RevoluteJoint_GetMotorTorque),
		JS_CFUNC_DEF("b2RevoluteJoint_SetMaxMotorTorque",2,js_b2RevoluteJoint_SetMaxMotorTorque),
		JS_CFUNC_DEF("b2RevoluteJoint_GetMaxMotorTorque",1,js_b2RevoluteJoint_GetMaxMotorTorque),
		JS_CFUNC_DEF("b2CreateWeldJoint",2,js_b2CreateWeldJoint),
		JS_CFUNC_DEF("b2WeldJoint_SetLinearHertz",2,js_b2WeldJoint_SetLinearHertz),
		JS_CFUNC_DEF("b2WeldJoint_GetLinearHertz",1,js_b2WeldJoint_GetLinearHertz),
		JS_CFUNC_DEF("b2WeldJoint_SetLinearDampingRatio",2,js_b2WeldJoint_SetLinearDampingRatio),
		JS_CFUNC_DEF("b2WeldJoint_GetLinearDampingRatio",1,js_b2WeldJoint_GetLinearDampingRatio),
		JS_CFUNC_DEF("b2WeldJoint_SetAngularHertz",2,js_b2WeldJoint_SetAngularHertz),
		JS_CFUNC_DEF("b2WeldJoint_GetAngularHertz",1,js_b2WeldJoint_GetAngularHertz),
		JS_CFUNC_DEF("b2WeldJoint_SetAngularDampingRatio",2,js_b2WeldJoint_SetAngularDampingRatio),
		JS_CFUNC_DEF("b2WeldJoint_GetAngularDampingRatio",1,js_b2WeldJoint_GetAngularDampingRatio),
		JS_CFUNC_DEF("b2CreateWheelJoint",2,js_b2CreateWheelJoint),
		JS_CFUNC_DEF("b2WheelJoint_EnableSpring",2,js_b2WheelJoint_EnableSpring),
		JS_CFUNC_DEF("b2WheelJoint_IsSpringEnabled",1,js_b2WheelJoint_IsSpringEnabled),
		JS_CFUNC_DEF("b2WheelJoint_SetSpringHertz",2,js_b2WheelJoint_SetSpringHertz),
		JS_CFUNC_DEF("b2WheelJoint_GetSpringHertz",1,js_b2WheelJoint_GetSpringHertz),
		JS_CFUNC_DEF("b2WheelJoint_SetSpringDampingRatio",2,js_b2WheelJoint_SetSpringDampingRatio),
		JS_CFUNC_DEF("b2WheelJoint_GetSpringDampingRatio",1,js_b2WheelJoint_GetSpringDampingRatio),
		JS_CFUNC_DEF("b2WheelJoint_EnableLimit",2,js_b2WheelJoint_EnableLimit),
		JS_CFUNC_DEF("b2WheelJoint_IsLimitEnabled",1,js_b2WheelJoint_IsLimitEnabled),
		JS_CFUNC_DEF("b2WheelJoint_GetLowerLimit",1,js_b2WheelJoint_GetLowerLimit),
		JS_CFUNC_DEF("b2WheelJoint_GetUpperLimit",1,js_b2WheelJoint_GetUpperLimit),
		JS_CFUNC_DEF("b2WheelJoint_SetLimits",3,js_b2WheelJoint_SetLimits),
		JS_CFUNC_DEF("b2WheelJoint_EnableMotor",2,js_b2WheelJoint_EnableMotor),
		JS_CFUNC_DEF("b2WheelJoint_IsMotorEnabled",1,js_b2WheelJoint_IsMotorEnabled),
		JS_CFUNC_DEF("b2WheelJoint_SetMotorSpeed",2,js_b2WheelJoint_SetMotorSpeed),
		JS_CFUNC_DEF("b2WheelJoint_GetMotorSpeed",1,js_b2WheelJoint_GetMotorSpeed),
		JS_CFUNC_DEF("b2WheelJoint_SetMaxMotorTorque",2,js_b2WheelJoint_SetMaxMotorTorque),
		JS_CFUNC_DEF("b2WheelJoint_GetMaxMotorTorque",1,js_b2WheelJoint_GetMaxMotorTorque),
		JS_CFUNC_DEF("b2WheelJoint_GetMotorTorque",1,js_b2WheelJoint_GetMotorTorque)
	};
	
	static int js_box2d_init(JSContext * ctx,JSModuleDef * m){
		size_t listcount=countof(jsbox2d_funcs);
		JS_SetModuleExportList(ctx,m,jsbox2d_funcs,(int)listcount);
		js_declare_b2Version(ctx,m);
		JSValue b2Version_constr=JS_NewCFunction2(ctx,js_b2Version_constructor,(const char  *)"b2Version",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Version",b2Version_constr);
		js_declare_b2Vec2(ctx,m);
		JSValue b2Vec2_constr=JS_NewCFunction2(ctx,js_b2Vec2_constructor,(const char  *)"b2Vec2",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Vec2",b2Vec2_constr);
		js_declare_b2CosSin(ctx,m);
		JSValue b2CosSin_constr=JS_NewCFunction2(ctx,js_b2CosSin_constructor,(const char  *)"b2CosSin",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2CosSin",b2CosSin_constr);
		js_declare_b2Rot(ctx,m);
		JSValue b2Rot_constr=JS_NewCFunction2(ctx,js_b2Rot_constructor,(const char  *)"b2Rot",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Rot",b2Rot_constr);
		js_declare_b2Transform(ctx,m);
		JSValue b2Transform_constr=JS_NewCFunction2(ctx,js_b2Transform_constructor,(const char  *)"b2Transform",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Transform",b2Transform_constr);
		js_declare_b2Mat22(ctx,m);
		JSValue b2Mat22_constr=JS_NewCFunction2(ctx,js_b2Mat22_constructor,(const char  *)"b2Mat22",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Mat22",b2Mat22_constr);
		js_declare_b2AABB(ctx,m);
		JSValue b2AABB_constr=JS_NewCFunction2(ctx,js_b2AABB_constructor,(const char  *)"b2AABB",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2AABB",b2AABB_constr);
		js_declare_b2Plane(ctx,m);
		JSValue b2Plane_constr=JS_NewCFunction2(ctx,js_b2Plane_constructor,(const char  *)"b2Plane",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Plane",b2Plane_constr);
		js_declare_b2SimplexCache(ctx,m);
		JSValue b2SimplexCache_constr=JS_NewCFunction2(ctx,js_b2SimplexCache_constructor,(const char  *)"b2SimplexCache",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SimplexCache",b2SimplexCache_constr);
		js_declare_b2Hull(ctx,m);
		JSValue b2Hull_constr=JS_NewCFunction2(ctx,js_b2Hull_constructor,(const char  *)"b2Hull",(int)0,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Hull",b2Hull_constr);
		js_declare_b2RayCastInput(ctx,m);
		JSValue b2RayCastInput_constr=JS_NewCFunction2(ctx,js_b2RayCastInput_constructor,(const char  *)"b2RayCastInput",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2RayCastInput",b2RayCastInput_constr);
		js_declare_b2ShapeProxy(ctx,m);
		JSValue b2ShapeProxy_constr=JS_NewCFunction2(ctx,js_b2ShapeProxy_constructor,(const char  *)"b2ShapeProxy",(int)0,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ShapeProxy",b2ShapeProxy_constr);
		js_declare_b2ShapeCastInput(ctx,m);
		JSValue b2ShapeCastInput_constr=JS_NewCFunction2(ctx,js_b2ShapeCastInput_constructor,(const char  *)"b2ShapeCastInput",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ShapeCastInput",b2ShapeCastInput_constr);
		js_declare_b2CastOutput(ctx,m);
		JSValue b2CastOutput_constr=JS_NewCFunction2(ctx,js_b2CastOutput_constructor,(const char  *)"b2CastOutput",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2CastOutput",b2CastOutput_constr);
		js_declare_b2MassData(ctx,m);
		JSValue b2MassData_constr=JS_NewCFunction2(ctx,js_b2MassData_constructor,(const char  *)"b2MassData",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2MassData",b2MassData_constr);
		js_declare_b2Circle(ctx,m);
		JSValue b2Circle_constr=JS_NewCFunction2(ctx,js_b2Circle_constructor,(const char  *)"b2Circle",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Circle",b2Circle_constr);
		js_declare_b2Capsule(ctx,m);
		JSValue b2Capsule_constr=JS_NewCFunction2(ctx,js_b2Capsule_constructor,(const char  *)"b2Capsule",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Capsule",b2Capsule_constr);
		js_declare_b2Polygon(ctx,m);
		JSValue b2Polygon_constr=JS_NewCFunction2(ctx,js_b2Polygon_constructor,(const char  *)"b2Polygon",(int)0,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Polygon",b2Polygon_constr);
		js_declare_b2Segment(ctx,m);
		JSValue b2Segment_constr=JS_NewCFunction2(ctx,js_b2Segment_constructor,(const char  *)"b2Segment",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Segment",b2Segment_constr);
		js_declare_b2ChainSegment(ctx,m);
		JSValue b2ChainSegment_constr=JS_NewCFunction2(ctx,js_b2ChainSegment_constructor,(const char  *)"b2ChainSegment",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ChainSegment",b2ChainSegment_constr);
		js_declare_b2SegmentDistanceResult(ctx,m);
		JSValue b2SegmentDistanceResult_constr=JS_NewCFunction2(ctx,js_b2SegmentDistanceResult_constructor,(const char  *)"b2SegmentDistanceResult",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SegmentDistanceResult",b2SegmentDistanceResult_constr);
		js_declare_b2DistanceInput(ctx,m);
		JSValue b2DistanceInput_constr=JS_NewCFunction2(ctx,js_b2DistanceInput_constructor,(const char  *)"b2DistanceInput",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2DistanceInput",b2DistanceInput_constr);
		js_declare_b2DistanceOutput(ctx,m);
		JSValue b2DistanceOutput_constr=JS_NewCFunction2(ctx,js_b2DistanceOutput_constructor,(const char  *)"b2DistanceOutput",(int)6,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2DistanceOutput",b2DistanceOutput_constr);
		js_declare_b2SimplexVertex(ctx,m);
		JSValue b2SimplexVertex_constr=JS_NewCFunction2(ctx,js_b2SimplexVertex_constructor,(const char  *)"b2SimplexVertex",(int)6,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SimplexVertex",b2SimplexVertex_constr);
		js_declare_b2Simplex(ctx,m);
		JSValue b2Simplex_constr=JS_NewCFunction2(ctx,js_b2Simplex_constructor,(const char  *)"b2Simplex",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Simplex",b2Simplex_constr);
		js_declare_b2ShapeCastPairInput(ctx,m);
		JSValue b2ShapeCastPairInput_constr=JS_NewCFunction2(ctx,js_b2ShapeCastPairInput_constructor,(const char  *)"b2ShapeCastPairInput",(int)7,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ShapeCastPairInput",b2ShapeCastPairInput_constr);
		js_declare_b2Sweep(ctx,m);
		JSValue b2Sweep_constr=JS_NewCFunction2(ctx,js_b2Sweep_constructor,(const char  *)"b2Sweep",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Sweep",b2Sweep_constr);
		js_declare_b2TOIInput(ctx,m);
		JSValue b2TOIInput_constr=JS_NewCFunction2(ctx,js_b2TOIInput_constructor,(const char  *)"b2TOIInput",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2TOIInput",b2TOIInput_constr);
		js_declare_b2TOIOutput(ctx,m);
		JSValue b2TOIOutput_constr=JS_NewCFunction2(ctx,js_b2TOIOutput_constructor,(const char  *)"b2TOIOutput",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2TOIOutput",b2TOIOutput_constr);
		js_declare_b2ManifoldPoint(ctx,m);
		JSValue b2ManifoldPoint_constr=JS_NewCFunction2(ctx,js_b2ManifoldPoint_constructor,(const char  *)"b2ManifoldPoint",(int)10,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ManifoldPoint",b2ManifoldPoint_constr);
		js_declare_b2Manifold(ctx,m);
		JSValue b2Manifold_constr=JS_NewCFunction2(ctx,js_b2Manifold_constructor,(const char  *)"b2Manifold",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Manifold",b2Manifold_constr);
		js_declare_b2TreeStats(ctx,m);
		JSValue b2TreeStats_constr=JS_NewCFunction2(ctx,js_b2TreeStats_constructor,(const char  *)"b2TreeStats",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2TreeStats",b2TreeStats_constr);
		js_declare_b2PlaneResult(ctx,m);
		JSValue b2PlaneResult_constr=JS_NewCFunction2(ctx,js_b2PlaneResult_constructor,(const char  *)"b2PlaneResult",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2PlaneResult",b2PlaneResult_constr);
		js_declare_b2CollisionPlane(ctx,m);
		JSValue b2CollisionPlane_constr=JS_NewCFunction2(ctx,js_b2CollisionPlane_constructor,(const char  *)"b2CollisionPlane",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2CollisionPlane",b2CollisionPlane_constr);
		js_declare_b2PlaneSolverResult(ctx,m);
		JSValue b2PlaneSolverResult_constr=JS_NewCFunction2(ctx,js_b2PlaneSolverResult_constructor,(const char  *)"b2PlaneSolverResult",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2PlaneSolverResult",b2PlaneSolverResult_constr);
		js_declare_b2WorldId(ctx,m);
		JSValue b2WorldId_constr=JS_NewCFunction2(ctx,js_b2WorldId_constructor,(const char  *)"b2WorldId",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2WorldId",b2WorldId_constr);
		js_declare_b2BodyId(ctx,m);
		JSValue b2BodyId_constr=JS_NewCFunction2(ctx,js_b2BodyId_constructor,(const char  *)"b2BodyId",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2BodyId",b2BodyId_constr);
		js_declare_b2ShapeId(ctx,m);
		JSValue b2ShapeId_constr=JS_NewCFunction2(ctx,js_b2ShapeId_constructor,(const char  *)"b2ShapeId",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ShapeId",b2ShapeId_constr);
		js_declare_b2ChainId(ctx,m);
		JSValue b2ChainId_constr=JS_NewCFunction2(ctx,js_b2ChainId_constructor,(const char  *)"b2ChainId",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ChainId",b2ChainId_constr);
		js_declare_b2JointId(ctx,m);
		JSValue b2JointId_constr=JS_NewCFunction2(ctx,js_b2JointId_constructor,(const char  *)"b2JointId",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2JointId",b2JointId_constr);
		js_declare_b2RayResult(ctx,m);
		JSValue b2RayResult_constr=JS_NewCFunction2(ctx,js_b2RayResult_constructor,(const char  *)"b2RayResult",(int)7,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2RayResult",b2RayResult_constr);
		js_declare_b2WorldDef(ctx,m);
		JSValue b2WorldDef_constr=JS_NewCFunction2(ctx,js_b2WorldDef_constructor,(const char  *)"b2WorldDef",(int)10,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2WorldDef",b2WorldDef_constr);
		js_declare_b2BodyDef(ctx,m);
		JSValue b2BodyDef_constr=JS_NewCFunction2(ctx,js_b2BodyDef_constructor,(const char  *)"b2BodyDef",(int)16,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2BodyDef",b2BodyDef_constr);
		js_declare_b2Filter(ctx,m);
		JSValue b2Filter_constr=JS_NewCFunction2(ctx,js_b2Filter_constructor,(const char  *)"b2Filter",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Filter",b2Filter_constr);
		js_declare_b2QueryFilter(ctx,m);
		JSValue b2QueryFilter_constr=JS_NewCFunction2(ctx,js_b2QueryFilter_constructor,(const char  *)"b2QueryFilter",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2QueryFilter",b2QueryFilter_constr);
		js_declare_b2SurfaceMaterial(ctx,m);
		JSValue b2SurfaceMaterial_constr=JS_NewCFunction2(ctx,js_b2SurfaceMaterial_constructor,(const char  *)"b2SurfaceMaterial",(int)6,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SurfaceMaterial",b2SurfaceMaterial_constr);
		js_declare_b2ShapeDef(ctx,m);
		JSValue b2ShapeDef_constr=JS_NewCFunction2(ctx,js_b2ShapeDef_constructor,(const char  *)"b2ShapeDef",(int)10,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ShapeDef",b2ShapeDef_constr);
		js_declare_b2ChainDef(ctx,m);
		JSValue b2ChainDef_constr=JS_NewCFunction2(ctx,js_b2ChainDef_constructor,(const char  *)"b2ChainDef",(int)7,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ChainDef",b2ChainDef_constr);
		js_declare_b2Profile(ctx,m);
		JSValue b2Profile_constr=JS_NewCFunction2(ctx,js_b2Profile_constructor,(const char  *)"b2Profile",(int)22,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Profile",b2Profile_constr);
		js_declare_b2Counters(ctx,m);
		JSValue b2Counters_constr=JS_NewCFunction2(ctx,js_b2Counters_constructor,(const char  *)"b2Counters",(int)11,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2Counters",b2Counters_constr);
		js_declare_b2DistanceJointDef(ctx,m);
		JSValue b2DistanceJointDef_constr=JS_NewCFunction2(ctx,js_b2DistanceJointDef_constructor,(const char  *)"b2DistanceJointDef",(int)15,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2DistanceJointDef",b2DistanceJointDef_constr);
		js_declare_b2MotorJointDef(ctx,m);
		JSValue b2MotorJointDef_constr=JS_NewCFunction2(ctx,js_b2MotorJointDef_constructor,(const char  *)"b2MotorJointDef",(int)8,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2MotorJointDef",b2MotorJointDef_constr);
		js_declare_b2MouseJointDef(ctx,m);
		JSValue b2MouseJointDef_constr=JS_NewCFunction2(ctx,js_b2MouseJointDef_constructor,(const char  *)"b2MouseJointDef",(int)7,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2MouseJointDef",b2MouseJointDef_constr);
		js_declare_b2FilterJointDef(ctx,m);
		JSValue b2FilterJointDef_constr=JS_NewCFunction2(ctx,js_b2FilterJointDef_constructor,(const char  *)"b2FilterJointDef",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2FilterJointDef",b2FilterJointDef_constr);
		js_declare_b2PrismaticJointDef(ctx,m);
		JSValue b2PrismaticJointDef_constr=JS_NewCFunction2(ctx,js_b2PrismaticJointDef_constructor,(const char  *)"b2PrismaticJointDef",(int)17,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2PrismaticJointDef",b2PrismaticJointDef_constr);
		js_declare_b2RevoluteJointDef(ctx,m);
		JSValue b2RevoluteJointDef_constr=JS_NewCFunction2(ctx,js_b2RevoluteJointDef_constructor,(const char  *)"b2RevoluteJointDef",(int)17,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2RevoluteJointDef",b2RevoluteJointDef_constr);
		js_declare_b2WeldJointDef(ctx,m);
		JSValue b2WeldJointDef_constr=JS_NewCFunction2(ctx,js_b2WeldJointDef_constructor,(const char  *)"b2WeldJointDef",(int)10,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2WeldJointDef",b2WeldJointDef_constr);
		js_declare_b2WheelJointDef(ctx,m);
		JSValue b2WheelJointDef_constr=JS_NewCFunction2(ctx,js_b2WheelJointDef_constructor,(const char  *)"b2WheelJointDef",(int)15,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2WheelJointDef",b2WheelJointDef_constr);
		js_declare_b2ExplosionDef(ctx,m);
		JSValue b2ExplosionDef_constr=JS_NewCFunction2(ctx,js_b2ExplosionDef_constructor,(const char  *)"b2ExplosionDef",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ExplosionDef",b2ExplosionDef_constr);
		js_declare_b2SensorBeginTouchEvent(ctx,m);
		JSValue b2SensorBeginTouchEvent_constr=JS_NewCFunction2(ctx,js_b2SensorBeginTouchEvent_constructor,(const char  *)"b2SensorBeginTouchEvent",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SensorBeginTouchEvent",b2SensorBeginTouchEvent_constr);
		js_declare_b2SensorEndTouchEvent(ctx,m);
		JSValue b2SensorEndTouchEvent_constr=JS_NewCFunction2(ctx,js_b2SensorEndTouchEvent_constructor,(const char  *)"b2SensorEndTouchEvent",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SensorEndTouchEvent",b2SensorEndTouchEvent_constr);
		js_declare_b2SensorEvents(ctx,m);
		JSValue b2SensorEvents_constr=JS_NewCFunction2(ctx,js_b2SensorEvents_constructor,(const char  *)"b2SensorEvents",(int)4,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2SensorEvents",b2SensorEvents_constr);
		js_declare_b2ContactBeginTouchEvent(ctx,m);
		JSValue b2ContactBeginTouchEvent_constr=JS_NewCFunction2(ctx,js_b2ContactBeginTouchEvent_constructor,(const char  *)"b2ContactBeginTouchEvent",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ContactBeginTouchEvent",b2ContactBeginTouchEvent_constr);
		js_declare_b2ContactEndTouchEvent(ctx,m);
		JSValue b2ContactEndTouchEvent_constr=JS_NewCFunction2(ctx,js_b2ContactEndTouchEvent_constructor,(const char  *)"b2ContactEndTouchEvent",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ContactEndTouchEvent",b2ContactEndTouchEvent_constr);
		js_declare_b2ContactHitEvent(ctx,m);
		JSValue b2ContactHitEvent_constr=JS_NewCFunction2(ctx,js_b2ContactHitEvent_constructor,(const char  *)"b2ContactHitEvent",(int)5,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ContactHitEvent",b2ContactHitEvent_constr);
		js_declare_b2ContactEvents(ctx,m);
		JSValue b2ContactEvents_constr=JS_NewCFunction2(ctx,js_b2ContactEvents_constructor,(const char  *)"b2ContactEvents",(int)6,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ContactEvents",b2ContactEvents_constr);
		js_declare_b2BodyMoveEvent(ctx,m);
		JSValue b2BodyMoveEvent_constr=JS_NewCFunction2(ctx,js_b2BodyMoveEvent_constructor,(const char  *)"b2BodyMoveEvent",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2BodyMoveEvent",b2BodyMoveEvent_constr);
		js_declare_b2BodyEvents(ctx,m);
		JSValue b2BodyEvents_constr=JS_NewCFunction2(ctx,js_b2BodyEvents_constructor,(const char  *)"b2BodyEvents",(int)2,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2BodyEvents",b2BodyEvents_constr);
		js_declare_b2ContactData(ctx,m);
		JSValue b2ContactData_constr=JS_NewCFunction2(ctx,js_b2ContactData_constructor,(const char  *)"b2ContactData",(int)3,(JSCFunctionEnum)JS_CFUNC_constructor,(int)0);
		JS_SetModuleExport(ctx,m,(const char  *)"b2ContactData",b2ContactData_constr);
		JS_SetModuleExport(ctx,m,(const char  *)"b2_toiStateUnknown",JS_NewInt32(ctx,(int32_t)b2_toiStateUnknown));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_toiStateFailed",JS_NewInt32(ctx,(int32_t)b2_toiStateFailed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_toiStateOverlapped",JS_NewInt32(ctx,(int32_t)b2_toiStateOverlapped));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_toiStateHit",JS_NewInt32(ctx,(int32_t)b2_toiStateHit));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_toiStateSeparated",JS_NewInt32(ctx,(int32_t)b2_toiStateSeparated));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_staticBody",JS_NewInt32(ctx,(int32_t)b2_staticBody));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_kinematicBody",JS_NewInt32(ctx,(int32_t)b2_kinematicBody));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_dynamicBody",JS_NewInt32(ctx,(int32_t)b2_dynamicBody));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_bodyTypeCount",JS_NewInt32(ctx,(int32_t)b2_bodyTypeCount));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_circleShape",JS_NewInt32(ctx,(int32_t)b2_circleShape));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_capsuleShape",JS_NewInt32(ctx,(int32_t)b2_capsuleShape));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_segmentShape",JS_NewInt32(ctx,(int32_t)b2_segmentShape));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_polygonShape",JS_NewInt32(ctx,(int32_t)b2_polygonShape));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_chainSegmentShape",JS_NewInt32(ctx,(int32_t)b2_chainSegmentShape));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_shapeTypeCount",JS_NewInt32(ctx,(int32_t)b2_shapeTypeCount));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_distanceJoint",JS_NewInt32(ctx,(int32_t)b2_distanceJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_filterJoint",JS_NewInt32(ctx,(int32_t)b2_filterJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_motorJoint",JS_NewInt32(ctx,(int32_t)b2_motorJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_mouseJoint",JS_NewInt32(ctx,(int32_t)b2_mouseJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_prismaticJoint",JS_NewInt32(ctx,(int32_t)b2_prismaticJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_revoluteJoint",JS_NewInt32(ctx,(int32_t)b2_revoluteJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_weldJoint",JS_NewInt32(ctx,(int32_t)b2_weldJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_wheelJoint",JS_NewInt32(ctx,(int32_t)b2_wheelJoint));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorAliceBlue",JS_NewInt32(ctx,(int32_t)b2_colorAliceBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorAntiqueWhite",JS_NewInt32(ctx,(int32_t)b2_colorAntiqueWhite));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorAqua",JS_NewInt32(ctx,(int32_t)b2_colorAqua));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorAquamarine",JS_NewInt32(ctx,(int32_t)b2_colorAquamarine));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorAzure",JS_NewInt32(ctx,(int32_t)b2_colorAzure));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBeige",JS_NewInt32(ctx,(int32_t)b2_colorBeige));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBisque",JS_NewInt32(ctx,(int32_t)b2_colorBisque));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBlack",JS_NewInt32(ctx,(int32_t)b2_colorBlack));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBlanchedAlmond",JS_NewInt32(ctx,(int32_t)b2_colorBlanchedAlmond));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBlue",JS_NewInt32(ctx,(int32_t)b2_colorBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBlueViolet",JS_NewInt32(ctx,(int32_t)b2_colorBlueViolet));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBrown",JS_NewInt32(ctx,(int32_t)b2_colorBrown));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBurlywood",JS_NewInt32(ctx,(int32_t)b2_colorBurlywood));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCadetBlue",JS_NewInt32(ctx,(int32_t)b2_colorCadetBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorChartreuse",JS_NewInt32(ctx,(int32_t)b2_colorChartreuse));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorChocolate",JS_NewInt32(ctx,(int32_t)b2_colorChocolate));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCoral",JS_NewInt32(ctx,(int32_t)b2_colorCoral));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCornflowerBlue",JS_NewInt32(ctx,(int32_t)b2_colorCornflowerBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCornsilk",JS_NewInt32(ctx,(int32_t)b2_colorCornsilk));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCrimson",JS_NewInt32(ctx,(int32_t)b2_colorCrimson));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorCyan",JS_NewInt32(ctx,(int32_t)b2_colorCyan));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkBlue",JS_NewInt32(ctx,(int32_t)b2_colorDarkBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkCyan",JS_NewInt32(ctx,(int32_t)b2_colorDarkCyan));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkGoldenRod",JS_NewInt32(ctx,(int32_t)b2_colorDarkGoldenRod));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkGray",JS_NewInt32(ctx,(int32_t)b2_colorDarkGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkGreen",JS_NewInt32(ctx,(int32_t)b2_colorDarkGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkKhaki",JS_NewInt32(ctx,(int32_t)b2_colorDarkKhaki));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkMagenta",JS_NewInt32(ctx,(int32_t)b2_colorDarkMagenta));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkOliveGreen",JS_NewInt32(ctx,(int32_t)b2_colorDarkOliveGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkOrange",JS_NewInt32(ctx,(int32_t)b2_colorDarkOrange));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkOrchid",JS_NewInt32(ctx,(int32_t)b2_colorDarkOrchid));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkRed",JS_NewInt32(ctx,(int32_t)b2_colorDarkRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkSalmon",JS_NewInt32(ctx,(int32_t)b2_colorDarkSalmon));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkSeaGreen",JS_NewInt32(ctx,(int32_t)b2_colorDarkSeaGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkSlateBlue",JS_NewInt32(ctx,(int32_t)b2_colorDarkSlateBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkSlateGray",JS_NewInt32(ctx,(int32_t)b2_colorDarkSlateGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkTurquoise",JS_NewInt32(ctx,(int32_t)b2_colorDarkTurquoise));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDarkViolet",JS_NewInt32(ctx,(int32_t)b2_colorDarkViolet));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDeepPink",JS_NewInt32(ctx,(int32_t)b2_colorDeepPink));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDeepSkyBlue",JS_NewInt32(ctx,(int32_t)b2_colorDeepSkyBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDimGray",JS_NewInt32(ctx,(int32_t)b2_colorDimGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorDodgerBlue",JS_NewInt32(ctx,(int32_t)b2_colorDodgerBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorFireBrick",JS_NewInt32(ctx,(int32_t)b2_colorFireBrick));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorFloralWhite",JS_NewInt32(ctx,(int32_t)b2_colorFloralWhite));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorForestGreen",JS_NewInt32(ctx,(int32_t)b2_colorForestGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorFuchsia",JS_NewInt32(ctx,(int32_t)b2_colorFuchsia));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGainsboro",JS_NewInt32(ctx,(int32_t)b2_colorGainsboro));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGhostWhite",JS_NewInt32(ctx,(int32_t)b2_colorGhostWhite));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGold",JS_NewInt32(ctx,(int32_t)b2_colorGold));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGoldenRod",JS_NewInt32(ctx,(int32_t)b2_colorGoldenRod));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGray",JS_NewInt32(ctx,(int32_t)b2_colorGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGreen",JS_NewInt32(ctx,(int32_t)b2_colorGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorGreenYellow",JS_NewInt32(ctx,(int32_t)b2_colorGreenYellow));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorHoneyDew",JS_NewInt32(ctx,(int32_t)b2_colorHoneyDew));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorHotPink",JS_NewInt32(ctx,(int32_t)b2_colorHotPink));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorIndianRed",JS_NewInt32(ctx,(int32_t)b2_colorIndianRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorIndigo",JS_NewInt32(ctx,(int32_t)b2_colorIndigo));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorIvory",JS_NewInt32(ctx,(int32_t)b2_colorIvory));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorKhaki",JS_NewInt32(ctx,(int32_t)b2_colorKhaki));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLavender",JS_NewInt32(ctx,(int32_t)b2_colorLavender));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLavenderBlush",JS_NewInt32(ctx,(int32_t)b2_colorLavenderBlush));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLawnGreen",JS_NewInt32(ctx,(int32_t)b2_colorLawnGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLemonChiffon",JS_NewInt32(ctx,(int32_t)b2_colorLemonChiffon));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightBlue",JS_NewInt32(ctx,(int32_t)b2_colorLightBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightCoral",JS_NewInt32(ctx,(int32_t)b2_colorLightCoral));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightCyan",JS_NewInt32(ctx,(int32_t)b2_colorLightCyan));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightGoldenRodYellow",JS_NewInt32(ctx,(int32_t)b2_colorLightGoldenRodYellow));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightGray",JS_NewInt32(ctx,(int32_t)b2_colorLightGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightGreen",JS_NewInt32(ctx,(int32_t)b2_colorLightGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightPink",JS_NewInt32(ctx,(int32_t)b2_colorLightPink));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightSalmon",JS_NewInt32(ctx,(int32_t)b2_colorLightSalmon));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightSeaGreen",JS_NewInt32(ctx,(int32_t)b2_colorLightSeaGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightSkyBlue",JS_NewInt32(ctx,(int32_t)b2_colorLightSkyBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightSlateGray",JS_NewInt32(ctx,(int32_t)b2_colorLightSlateGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightSteelBlue",JS_NewInt32(ctx,(int32_t)b2_colorLightSteelBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLightYellow",JS_NewInt32(ctx,(int32_t)b2_colorLightYellow));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLime",JS_NewInt32(ctx,(int32_t)b2_colorLime));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLimeGreen",JS_NewInt32(ctx,(int32_t)b2_colorLimeGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorLinen",JS_NewInt32(ctx,(int32_t)b2_colorLinen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMagenta",JS_NewInt32(ctx,(int32_t)b2_colorMagenta));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMaroon",JS_NewInt32(ctx,(int32_t)b2_colorMaroon));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumAquaMarine",JS_NewInt32(ctx,(int32_t)b2_colorMediumAquaMarine));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumBlue",JS_NewInt32(ctx,(int32_t)b2_colorMediumBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumOrchid",JS_NewInt32(ctx,(int32_t)b2_colorMediumOrchid));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumPurple",JS_NewInt32(ctx,(int32_t)b2_colorMediumPurple));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumSeaGreen",JS_NewInt32(ctx,(int32_t)b2_colorMediumSeaGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumSlateBlue",JS_NewInt32(ctx,(int32_t)b2_colorMediumSlateBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumSpringGreen",JS_NewInt32(ctx,(int32_t)b2_colorMediumSpringGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumTurquoise",JS_NewInt32(ctx,(int32_t)b2_colorMediumTurquoise));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMediumVioletRed",JS_NewInt32(ctx,(int32_t)b2_colorMediumVioletRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMidnightBlue",JS_NewInt32(ctx,(int32_t)b2_colorMidnightBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMintCream",JS_NewInt32(ctx,(int32_t)b2_colorMintCream));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMistyRose",JS_NewInt32(ctx,(int32_t)b2_colorMistyRose));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorMoccasin",JS_NewInt32(ctx,(int32_t)b2_colorMoccasin));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorNavajoWhite",JS_NewInt32(ctx,(int32_t)b2_colorNavajoWhite));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorNavy",JS_NewInt32(ctx,(int32_t)b2_colorNavy));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOldLace",JS_NewInt32(ctx,(int32_t)b2_colorOldLace));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOlive",JS_NewInt32(ctx,(int32_t)b2_colorOlive));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOliveDrab",JS_NewInt32(ctx,(int32_t)b2_colorOliveDrab));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOrange",JS_NewInt32(ctx,(int32_t)b2_colorOrange));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOrangeRed",JS_NewInt32(ctx,(int32_t)b2_colorOrangeRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorOrchid",JS_NewInt32(ctx,(int32_t)b2_colorOrchid));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPaleGoldenRod",JS_NewInt32(ctx,(int32_t)b2_colorPaleGoldenRod));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPaleGreen",JS_NewInt32(ctx,(int32_t)b2_colorPaleGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPaleTurquoise",JS_NewInt32(ctx,(int32_t)b2_colorPaleTurquoise));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPaleVioletRed",JS_NewInt32(ctx,(int32_t)b2_colorPaleVioletRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPapayaWhip",JS_NewInt32(ctx,(int32_t)b2_colorPapayaWhip));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPeachPuff",JS_NewInt32(ctx,(int32_t)b2_colorPeachPuff));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPeru",JS_NewInt32(ctx,(int32_t)b2_colorPeru));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPink",JS_NewInt32(ctx,(int32_t)b2_colorPink));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPlum",JS_NewInt32(ctx,(int32_t)b2_colorPlum));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPowderBlue",JS_NewInt32(ctx,(int32_t)b2_colorPowderBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorPurple",JS_NewInt32(ctx,(int32_t)b2_colorPurple));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorRebeccaPurple",JS_NewInt32(ctx,(int32_t)b2_colorRebeccaPurple));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorRed",JS_NewInt32(ctx,(int32_t)b2_colorRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorRosyBrown",JS_NewInt32(ctx,(int32_t)b2_colorRosyBrown));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorRoyalBlue",JS_NewInt32(ctx,(int32_t)b2_colorRoyalBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSaddleBrown",JS_NewInt32(ctx,(int32_t)b2_colorSaddleBrown));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSalmon",JS_NewInt32(ctx,(int32_t)b2_colorSalmon));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSandyBrown",JS_NewInt32(ctx,(int32_t)b2_colorSandyBrown));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSeaGreen",JS_NewInt32(ctx,(int32_t)b2_colorSeaGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSeaShell",JS_NewInt32(ctx,(int32_t)b2_colorSeaShell));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSienna",JS_NewInt32(ctx,(int32_t)b2_colorSienna));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSilver",JS_NewInt32(ctx,(int32_t)b2_colorSilver));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSkyBlue",JS_NewInt32(ctx,(int32_t)b2_colorSkyBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSlateBlue",JS_NewInt32(ctx,(int32_t)b2_colorSlateBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSlateGray",JS_NewInt32(ctx,(int32_t)b2_colorSlateGray));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSnow",JS_NewInt32(ctx,(int32_t)b2_colorSnow));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSpringGreen",JS_NewInt32(ctx,(int32_t)b2_colorSpringGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorSteelBlue",JS_NewInt32(ctx,(int32_t)b2_colorSteelBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorTan",JS_NewInt32(ctx,(int32_t)b2_colorTan));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorTeal",JS_NewInt32(ctx,(int32_t)b2_colorTeal));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorThistle",JS_NewInt32(ctx,(int32_t)b2_colorThistle));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorTomato",JS_NewInt32(ctx,(int32_t)b2_colorTomato));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorTurquoise",JS_NewInt32(ctx,(int32_t)b2_colorTurquoise));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorViolet",JS_NewInt32(ctx,(int32_t)b2_colorViolet));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorWheat",JS_NewInt32(ctx,(int32_t)b2_colorWheat));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorWhite",JS_NewInt32(ctx,(int32_t)b2_colorWhite));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorWhiteSmoke",JS_NewInt32(ctx,(int32_t)b2_colorWhiteSmoke));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorYellow",JS_NewInt32(ctx,(int32_t)b2_colorYellow));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorYellowGreen",JS_NewInt32(ctx,(int32_t)b2_colorYellowGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBox2DRed",JS_NewInt32(ctx,(int32_t)b2_colorBox2DRed));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBox2DBlue",JS_NewInt32(ctx,(int32_t)b2_colorBox2DBlue));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBox2DGreen",JS_NewInt32(ctx,(int32_t)b2_colorBox2DGreen));
		JS_SetModuleExport(ctx,m,(const char  *)"b2_colorBox2DYellow",JS_NewInt32(ctx,(int32_t)b2_colorBox2DYellow));
		JS_SetModuleExport(ctx,m,(const char  *)"B2_HASH_INIT",JS_NewInt32(ctx,(int32_t)B2_HASH_INIT));
		JS_SetModuleExport(ctx,m,(const char  *)"B2_PI",JS_NewFloat64(ctx,(double)B2_PI));
		JS_SetModuleExport(ctx,m,(const char  *)"B2_MAX_POLYGON_VERTICES",JS_NewInt32(ctx,(int32_t)B2_MAX_POLYGON_VERTICES));
		JS_SetModuleExport(ctx,m,(const char  *)"B2_DEFAULT_CATEGORY_BITS",JS_NewInt32(ctx,(int32_t)B2_DEFAULT_CATEGORY_BITS));
		return 0;
	}
	
	JSModuleDef * js_init_module_box2d(JSContext * ctx,const char * module_name){
		JSModuleDef * m=JS_NewCModule(ctx,module_name,js_box2d_init);
		if(!m)return NULL;
		size_t listcount=countof(jsbox2d_funcs);
		JS_AddModuleExportList(ctx,m,jsbox2d_funcs,(int)listcount);
		JS_AddModuleExport(ctx,m,(const char  *)"b2Version");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Vec2");
		JS_AddModuleExport(ctx,m,(const char  *)"b2CosSin");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Rot");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Transform");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Mat22");
		JS_AddModuleExport(ctx,m,(const char  *)"b2AABB");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Plane");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SimplexCache");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Hull");
		JS_AddModuleExport(ctx,m,(const char  *)"b2RayCastInput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ShapeProxy");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ShapeCastInput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2CastOutput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2MassData");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Circle");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Capsule");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Polygon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Segment");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ChainSegment");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SegmentDistanceResult");
		JS_AddModuleExport(ctx,m,(const char  *)"b2DistanceInput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2DistanceOutput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SimplexVertex");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Simplex");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ShapeCastPairInput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Sweep");
		JS_AddModuleExport(ctx,m,(const char  *)"b2TOIInput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2TOIOutput");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ManifoldPoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Manifold");
		JS_AddModuleExport(ctx,m,(const char  *)"b2TreeStats");
		JS_AddModuleExport(ctx,m,(const char  *)"b2PlaneResult");
		JS_AddModuleExport(ctx,m,(const char  *)"b2CollisionPlane");
		JS_AddModuleExport(ctx,m,(const char  *)"b2PlaneSolverResult");
		JS_AddModuleExport(ctx,m,(const char  *)"b2WorldId");
		JS_AddModuleExport(ctx,m,(const char  *)"b2BodyId");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ShapeId");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ChainId");
		JS_AddModuleExport(ctx,m,(const char  *)"b2JointId");
		JS_AddModuleExport(ctx,m,(const char  *)"b2RayResult");
		JS_AddModuleExport(ctx,m,(const char  *)"b2WorldDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2BodyDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Filter");
		JS_AddModuleExport(ctx,m,(const char  *)"b2QueryFilter");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SurfaceMaterial");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ShapeDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ChainDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Profile");
		JS_AddModuleExport(ctx,m,(const char  *)"b2Counters");
		JS_AddModuleExport(ctx,m,(const char  *)"b2DistanceJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2MotorJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2MouseJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2FilterJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2PrismaticJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2RevoluteJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2WeldJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2WheelJointDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ExplosionDef");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SensorBeginTouchEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SensorEndTouchEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2SensorEvents");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ContactBeginTouchEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ContactEndTouchEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ContactHitEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ContactEvents");
		JS_AddModuleExport(ctx,m,(const char  *)"b2BodyMoveEvent");
		JS_AddModuleExport(ctx,m,(const char  *)"b2BodyEvents");
		JS_AddModuleExport(ctx,m,(const char  *)"b2ContactData");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_toiStateUnknown");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_toiStateFailed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_toiStateOverlapped");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_toiStateHit");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_toiStateSeparated");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_staticBody");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_kinematicBody");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_dynamicBody");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_bodyTypeCount");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_circleShape");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_capsuleShape");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_segmentShape");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_polygonShape");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_chainSegmentShape");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_shapeTypeCount");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_distanceJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_filterJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_motorJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_mouseJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_prismaticJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_revoluteJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_weldJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_wheelJoint");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorAliceBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorAntiqueWhite");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorAqua");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorAquamarine");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorAzure");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBeige");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBisque");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBlack");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBlanchedAlmond");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBlueViolet");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBrown");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBurlywood");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCadetBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorChartreuse");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorChocolate");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCoral");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCornflowerBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCornsilk");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCrimson");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorCyan");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkCyan");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkGoldenRod");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkKhaki");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkMagenta");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkOliveGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkOrange");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkOrchid");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkSalmon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkSeaGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkSlateBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkSlateGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkTurquoise");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDarkViolet");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDeepPink");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDeepSkyBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDimGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorDodgerBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorFireBrick");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorFloralWhite");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorForestGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorFuchsia");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGainsboro");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGhostWhite");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGold");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGoldenRod");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorGreenYellow");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorHoneyDew");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorHotPink");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorIndianRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorIndigo");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorIvory");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorKhaki");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLavender");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLavenderBlush");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLawnGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLemonChiffon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightCoral");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightCyan");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightGoldenRodYellow");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightPink");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightSalmon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightSeaGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightSkyBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightSlateGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightSteelBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLightYellow");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLime");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLimeGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorLinen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMagenta");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMaroon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumAquaMarine");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumOrchid");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumPurple");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumSeaGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumSlateBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumSpringGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumTurquoise");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMediumVioletRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMidnightBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMintCream");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMistyRose");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorMoccasin");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorNavajoWhite");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorNavy");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOldLace");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOlive");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOliveDrab");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOrange");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOrangeRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorOrchid");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPaleGoldenRod");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPaleGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPaleTurquoise");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPaleVioletRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPapayaWhip");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPeachPuff");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPeru");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPink");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPlum");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPowderBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorPurple");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorRebeccaPurple");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorRosyBrown");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorRoyalBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSaddleBrown");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSalmon");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSandyBrown");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSeaGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSeaShell");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSienna");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSilver");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSkyBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSlateBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSlateGray");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSnow");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSpringGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorSteelBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorTan");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorTeal");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorThistle");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorTomato");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorTurquoise");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorViolet");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorWheat");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorWhite");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorWhiteSmoke");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorYellow");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorYellowGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBox2DRed");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBox2DBlue");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBox2DGreen");
		JS_AddModuleExport(ctx,m,(const char  *)"b2_colorBox2DYellow");
		JS_AddModuleExport(ctx,m,(const char  *)"B2_HASH_INIT");
		JS_AddModuleExport(ctx,m,(const char  *)"B2_PI");
		JS_AddModuleExport(ctx,m,(const char  *)"B2_MAX_POLYGON_VERTICES");
		JS_AddModuleExport(ctx,m,(const char  *)"B2_DEFAULT_CATEGORY_BITS");
		return m;
	}

#endif //JS_box2d_GUARD