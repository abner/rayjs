// Hand-written JS bridges for Box2D Category B: per-call query/cast callbacks.
// These calls are synchronous — trampolineContext is stack-allocated, no heap management needed.
// Included from src/modules/js_box2d.h just before js_box2d_init.

// ─── Trampolines ────────────────────────────────────────────────────────────

static bool js_b2OverlapResultFcn_trampoline(b2ShapeId shapeId, void* context) {
	trampolineContext* tc = (trampolineContext*)context;
	JSContext* ctx = tc->ctx;

	opaqueShadow* ss = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(ss + 1) = shapeId;
	JSValue js_shapeId = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_shapeId, ss);

	JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 1, &js_shapeId);
	bool ret = (bool)JS_ToBool(ctx, (JSValueConst)result);
	JS_FreeValue(ctx, result);
	JS_FreeValue(ctx, js_shapeId);
	return ret;
}

static float js_b2CastResultFcn_trampoline(b2ShapeId shapeId, b2Vec2 point, b2Vec2 normal,
                                            float fraction, void* context) {
	trampolineContext* tc = (trampolineContext*)context;
	JSContext* ctx = tc->ctx;

	opaqueShadow* ss = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(ss + 1) = shapeId;
	JSValue js_shapeId = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_shapeId, ss);

	opaqueShadow* sp = create_shadow_with_data(sizeof(b2Vec2));
	*(b2Vec2*)(sp + 1) = point;
	JSValue js_point = JS_NewObjectClass(ctx, js_b2Vec2_class_id);
	JS_SetOpaque(js_point, sp);

	opaqueShadow* sn = create_shadow_with_data(sizeof(b2Vec2));
	*(b2Vec2*)(sn + 1) = normal;
	JSValue js_normal = JS_NewObjectClass(ctx, js_b2Vec2_class_id);
	JS_SetOpaque(js_normal, sn);

	JSValue argv[4] = { js_shapeId, js_point, js_normal, JS_NewFloat64(ctx, (double)fraction) };
	JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 4, argv);
	double ret_d = 1.0;
	JS_ToFloat64(ctx, &ret_d, result);
	JS_FreeValue(ctx, result);
	JS_FreeValue(ctx, js_shapeId);
	JS_FreeValue(ctx, js_point);
	JS_FreeValue(ctx, js_normal);
	return (float)ret_d;
}

static bool js_b2PlaneResultFcn_trampoline(b2ShapeId shapeId, const b2PlaneResult* plane,
                                            void* context) {
	trampolineContext* tc = (trampolineContext*)context;
	JSContext* ctx = tc->ctx;

	opaqueShadow* ss = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(ss + 1) = shapeId;
	JSValue js_shapeId = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_shapeId, ss);

	opaqueShadow* sp = create_shadow_with_data(sizeof(b2PlaneResult));
	*(b2PlaneResult*)(sp + 1) = *plane;
	JSValue js_plane = JS_NewObjectClass(ctx, js_b2PlaneResult_class_id);
	JS_SetOpaque(js_plane, sp);

	JSValue argv[2] = { js_shapeId, js_plane };
	JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 2, argv);
	bool ret = (bool)JS_ToBool(ctx, (JSValueConst)result);
	JS_FreeValue(ctx, result);
	JS_FreeValue(ctx, js_shapeId);
	JS_FreeValue(ctx, js_plane);
	return ret;
}

// ─── Helper: wrap b2TreeStats into a JS object ──────────────────────────────

static JSValue js_newb2TreeStats(JSContext* ctx, b2TreeStats stats) {
	opaqueShadow* shadow = create_shadow_with_data(sizeof(b2TreeStats));
	*(b2TreeStats*)(shadow + 1) = stats;
	JSValue ret = JS_NewObjectClass(ctx, js_b2TreeStats_class_id);
	JS_SetOpaque(ret, shadow);
	return ret;
}

// ─── Bridge functions ────────────────────────────────────────────────────────

// b2World_OverlapAABB(worldId, aabb, filter, callback) -> b2TreeStats
static JSValue js_b2World_OverlapAABB_bridge(JSContext* ctx, JSValue this_val,
                                              int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;
	b2AABB aabb = js_getb2AABB(ctx, argv[1], &error);
	if (error) return JS_EXCEPTION;
	b2QueryFilter filter = js_getb2QueryFilter(ctx, argv[2], &error);
	if (error) return JS_EXCEPTION;
	if (!JS_IsFunction(ctx, argv[3]))
		return JS_ThrowTypeError(ctx, "argument 4 must be a function");

	trampolineContext tc;
	tc.ctx = ctx;
	tc.func_obj = argv[3];
	b2TreeStats stats = b2World_OverlapAABB(worldId, aabb, filter,
	                                         js_b2OverlapResultFcn_trampoline, &tc);
	return js_newb2TreeStats(ctx, stats);
}

// b2World_OverlapShape(worldId, proxy, filter, callback) -> b2TreeStats
static JSValue js_b2World_OverlapShape_bridge(JSContext* ctx, JSValue this_val,
                                               int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;
	b2ShapeProxy proxy = js_getb2ShapeProxy(ctx, argv[1], &error);
	if (error) return JS_EXCEPTION;
	b2QueryFilter filter = js_getb2QueryFilter(ctx, argv[2], &error);
	if (error) return JS_EXCEPTION;
	if (!JS_IsFunction(ctx, argv[3]))
		return JS_ThrowTypeError(ctx, "argument 4 must be a function");

	trampolineContext tc;
	tc.ctx = ctx;
	tc.func_obj = argv[3];
	b2TreeStats stats = b2World_OverlapShape(worldId, &proxy, filter,
	                                          js_b2OverlapResultFcn_trampoline, &tc);
	return js_newb2TreeStats(ctx, stats);
}

// b2World_CastRay(worldId, origin, translation, filter, callback) -> b2TreeStats
static JSValue js_b2World_CastRay_bridge(JSContext* ctx, JSValue this_val,
                                          int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;
	b2Vec2 origin = js_getb2Vec2(ctx, argv[1], &error);
	if (error) return JS_EXCEPTION;
	b2Vec2 translation = js_getb2Vec2(ctx, argv[2], &error);
	if (error) return JS_EXCEPTION;
	b2QueryFilter filter = js_getb2QueryFilter(ctx, argv[3], &error);
	if (error) return JS_EXCEPTION;
	if (!JS_IsFunction(ctx, argv[4]))
		return JS_ThrowTypeError(ctx, "argument 5 must be a function");

	trampolineContext tc;
	tc.ctx = ctx;
	tc.func_obj = argv[4];
	b2TreeStats stats = b2World_CastRay(worldId, origin, translation, filter,
	                                     js_b2CastResultFcn_trampoline, &tc);
	return js_newb2TreeStats(ctx, stats);
}

// b2World_CastShape(worldId, proxy, translation, filter, callback) -> b2TreeStats
static JSValue js_b2World_CastShape_bridge(JSContext* ctx, JSValue this_val,
                                            int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;
	b2ShapeProxy proxy = js_getb2ShapeProxy(ctx, argv[1], &error);
	if (error) return JS_EXCEPTION;
	b2Vec2 translation = js_getb2Vec2(ctx, argv[2], &error);
	if (error) return JS_EXCEPTION;
	b2QueryFilter filter = js_getb2QueryFilter(ctx, argv[3], &error);
	if (error) return JS_EXCEPTION;
	if (!JS_IsFunction(ctx, argv[4]))
		return JS_ThrowTypeError(ctx, "argument 5 must be a function");

	trampolineContext tc;
	tc.ctx = ctx;
	tc.func_obj = argv[4];
	b2TreeStats stats = b2World_CastShape(worldId, &proxy, translation, filter,
	                                       js_b2CastResultFcn_trampoline, &tc);
	return js_newb2TreeStats(ctx, stats);
}

// b2World_CollideMover(worldId, mover, filter, callback) -> void
static JSValue js_b2World_CollideMover_bridge(JSContext* ctx, JSValue this_val,
                                               int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;
	b2Capsule mover = js_getb2Capsule(ctx, argv[1], &error);
	if (error) return JS_EXCEPTION;
	b2QueryFilter filter = js_getb2QueryFilter(ctx, argv[2], &error);
	if (error) return JS_EXCEPTION;
	if (!JS_IsFunction(ctx, argv[3]))
		return JS_ThrowTypeError(ctx, "argument 4 must be a function");

	trampolineContext tc;
	tc.ctx = ctx;
	tc.func_obj = argv[3];
	b2World_CollideMover(worldId, &mover, filter, js_b2PlaneResultFcn_trampoline, &tc);
	return JS_UNDEFINED;
}

// ─── Category C: Persistent world callbacks ──────────────────────────────────
// These fire during b2World_Step (same JS thread) — JS_Call is safe, no postMessage needed.
// Static trampolineContexts hold the JS function + its JSContext across steps.

static trampolineContext js_b2CustomFilter_ctx;
static bool             js_b2CustomFilter_active = false;

static trampolineContext js_b2PreSolve_ctx;
static bool             js_b2PreSolve_active = false;

static bool js_b2CustomFilterFcn_trampoline(b2ShapeId shapeIdA, b2ShapeId shapeIdB,
                                             void* context) {
	trampolineContext* tc = (trampolineContext*)context;
	JSContext* ctx = tc->ctx;

	opaqueShadow* sa = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(sa + 1) = shapeIdA;
	JSValue js_a = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_a, sa);

	opaqueShadow* sb = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(sb + 1) = shapeIdB;
	JSValue js_b_val = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_b_val, sb);

	JSValue argv[2] = { js_a, js_b_val };
	JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 2, argv);
	bool ret = (bool)JS_ToBool(ctx, (JSValueConst)result);
	JS_FreeValue(ctx, result);
	JS_FreeValue(ctx, js_a);
	JS_FreeValue(ctx, js_b_val);
	return ret;
}

static bool js_b2PreSolveFcn_trampoline(b2ShapeId shapeIdA, b2ShapeId shapeIdB,
                                         b2Manifold* manifold, void* context) {
	trampolineContext* tc = (trampolineContext*)context;
	JSContext* ctx = tc->ctx;

	opaqueShadow* sa = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(sa + 1) = shapeIdA;
	JSValue js_a = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_a, sa);

	opaqueShadow* sb = create_shadow_with_data(sizeof(b2ShapeId));
	*(b2ShapeId*)(sb + 1) = shapeIdB;
	JSValue js_b_val = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
	JS_SetOpaque(js_b_val, sb);

	// Copy the manifold — box2d owns the original; the JS wrapper must not outlive the callback.
	opaqueShadow* sm = create_shadow_with_data(sizeof(b2Manifold));
	*(b2Manifold*)(sm + 1) = *manifold;
	JSValue js_m = JS_NewObjectClass(ctx, js_b2Manifold_class_id);
	JS_SetOpaque(js_m, sm);

	JSValue argv[3] = { js_a, js_b_val, js_m };
	JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 3, argv);
	bool ret = (bool)JS_ToBool(ctx, (JSValueConst)result);
	JS_FreeValue(ctx, result);
	JS_FreeValue(ctx, js_a);
	JS_FreeValue(ctx, js_b_val);
	JS_FreeValue(ctx, js_m);
	return ret;
}

// b2World_SetCustomFilterCallback(worldId, callback | null) -> void
static JSValue js_b2World_SetCustomFilterCallback_bridge(JSContext* ctx, JSValue this_val,
                                                          int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;

	if (JS_IsNull(argv[1]) || JS_IsUndefined(argv[1])) {
		if (js_b2CustomFilter_active) {
			JS_FreeValue(js_b2CustomFilter_ctx.ctx, js_b2CustomFilter_ctx.func_obj);
			js_b2CustomFilter_active = false;
		}
		b2World_SetCustomFilterCallback(worldId, NULL, NULL);
	} else if (JS_IsFunction(ctx, (JSValueConst)argv[1])) {
		if (js_b2CustomFilter_active)
			JS_FreeValue(js_b2CustomFilter_ctx.ctx, js_b2CustomFilter_ctx.func_obj);
		js_b2CustomFilter_ctx.ctx = ctx;
		js_b2CustomFilter_ctx.func_obj = JS_DupValue(ctx, (JSValueConst)argv[1]);
		js_b2CustomFilter_active = true;
		b2World_SetCustomFilterCallback(worldId, js_b2CustomFilterFcn_trampoline,
		                                 &js_b2CustomFilter_ctx);
	} else {
		return JS_ThrowTypeError(ctx, "argument 2 must be a function or null");
	}
	return JS_UNDEFINED;
}

// b2World_SetPreSolveCallback(worldId, callback | null) -> void
static JSValue js_b2World_SetPreSolveCallback_bridge(JSContext* ctx, JSValue this_val,
                                                       int argc, JSValue* argv) {
	bool error = false;
	b2WorldId worldId = js_getb2WorldId(ctx, argv[0], &error);
	if (error) return JS_EXCEPTION;

	if (JS_IsNull(argv[1]) || JS_IsUndefined(argv[1])) {
		if (js_b2PreSolve_active) {
			JS_FreeValue(js_b2PreSolve_ctx.ctx, js_b2PreSolve_ctx.func_obj);
			js_b2PreSolve_active = false;
		}
		b2World_SetPreSolveCallback(worldId, NULL, NULL);
	} else if (JS_IsFunction(ctx, (JSValueConst)argv[1])) {
		if (js_b2PreSolve_active)
			JS_FreeValue(js_b2PreSolve_ctx.ctx, js_b2PreSolve_ctx.func_obj);
		js_b2PreSolve_ctx.ctx = ctx;
		js_b2PreSolve_ctx.func_obj = JS_DupValue(ctx, (JSValueConst)argv[1]);
		js_b2PreSolve_active = true;
		b2World_SetPreSolveCallback(worldId, js_b2PreSolveFcn_trampoline,
		                             &js_b2PreSolve_ctx);
	} else {
		return JS_ThrowTypeError(ctx, "argument 2 must be a function or null");
	}
	return JS_UNDEFINED;
}
