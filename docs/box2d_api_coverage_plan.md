# Plan: Increasing Box2D API Coverage in rayjs

## Context

`rayjs:box2d` currently ignores 27 functions and 2 structs. The majority fall into a few
patterns that were deferred rather than being fundamentally impossible to bind.

This document classifies each ignored item, explains the technical blocker, proposes a
concrete implementation strategy, and gives a priority ordering.

---

## Inventory of ignored items

### Category A — Simple callbacks (no void* context)

| Function | Callback type | C signature |
|---|---|---|
| `b2World_SetFrictionCallback` | `b2FrictionCallback*` | `float(float, int, float, int)` |
| `b2World_SetRestitutionCallback` | `b2RestitutionCallback*` | `float(float, int, float, int)` |

No `void*` context. Pattern is identical to `SetAudioStreamCallback` in raylib.

**Blocker**: not registered as module callbacks.  
**Fix**: register `b2FrictionCallback` and `b2RestitutionCallback` in `modules['box2d'].callbacks`
inside `index.js`, then remove the two `ignore()` calls. The existing generator loop
(lines 1268-1280) detects "Set" functions and calls `addCallback` automatically.

**Effort**: ~1 hour.

---

### Category B — Per-call query/cast callbacks (most valuable for gameplay)

| Function | Callback type | Return |
|---|---|---|
| `b2World_OverlapAABB(worldId, aabb, filter, fcn*, void* ctx)` | `b2OverlapResultFcn` | `b2TreeStats` |
| `b2World_OverlapShape(worldId, proxy*, filter, fcn*, void* ctx)` | `b2OverlapResultFcn` | `b2TreeStats` |
| `b2World_CastRay(worldId, origin, translation, filter, fcn*, void* ctx)` | `b2CastResultFcn` | `b2TreeStats` |
| `b2World_CastShape(worldId, proxy*, translation, filter, fcn*, void* ctx)` | `b2CastResultFcn` | `b2TreeStats` |
| `b2World_CollideShape(worldId, proxy*, shapeTfm, queryTfm, filter, fcn*, void* ctx)` | `b2CastResultFcn` | `b2TreeStats` |
| `b2World_CollideMover(worldId, capsule*, filter, fcn*, void* ctx)` | `b2PlaneResultFcn` | `void` |

Callback typedefs:
```c
typedef bool  b2OverlapResultFcn(b2ShapeId shapeId, void* context);
typedef float b2CastResultFcn(b2ShapeId shapeId, b2Vec2 point, b2Vec2 normal, float fraction, void* context);
typedef bool  b2PlaneResultFcn(b2ShapeId shapeId, const b2PlaneResult* plane, void* context);
```

**Key insight**: these calls are **synchronous** — Box2D calls the callback entirely within the
function call itself, before it returns. This means a **stack-allocated** `trampolineContext` is
safe: no heap allocation or lifetime management needed.

**Implementation strategy — hand-written C helpers (recommended):**

Create `src/box2d_helpers.h` with one static trampoline per callback type and one JS-binding
wrapper per function. Example for `OverlapAABB`:

```c
// Static trampolines (one per callback type)
static bool js_b2OverlapResultFcn_trampoline(b2ShapeId shapeId, void* context) {
    trampolineContext* tc = (trampolineContext*)context;
    JSContext* ctx = tc->ctx;
    JSValue js_shapeId = JS_NewObjectClass(ctx, js_b2ShapeId_class_id);
    // ... fill js_shapeId fields ...
    JSValue argv[1] = { js_shapeId };
    JSValue result = JS_Call(ctx, tc->func_obj, JS_UNDEFINED, 1, argv);
    bool ret = !JS_IsFalse(result);
    JS_FreeValue(ctx, result);
    JS_FreeValue(ctx, js_shapeId);
    return ret;
}

// JS binding for b2World_OverlapAABB
static JSValue js_b2World_OverlapAABB_bridge(JSContext* ctx, JSValue this_val,
                                              int argc, JSValue* argv) {
    // parse worldId, aabb, filter from argv[0..2]
    // argv[3] = JS callback function
    if (!JS_IsFunction(ctx, argv[3])) return JS_EXCEPTION;
    trampolineContext tc = { ctx, argv[3] };  // STACK — safe because call is sync
    b2TreeStats stats = b2World_OverlapAABB(worldId, aabb, filter,
                                             js_b2OverlapResultFcn_trampoline, &tc);
    // convert stats to JSValue and return
}
```

These wrappers are included from `src/modules/js_box2d.h` via `#include "../box2d_helpers.h"` and
registered in the module's export list at the end of `js_box2d.h` (append to the export array).

Alternatively, register them in `src/rayjs_base.c` after `js_init_module_box2d(...)` via a
follow-up call that adds more exports to the same module.

**Effort**: ~4 hours.

---

### Category C — Persistent world callbacks with void* context

| Function | Callback type | Notes |
|---|---|---|
| `b2World_SetCustomFilterCallback(worldId, fcn*, void* ctx)` | `b2CustomFilterFcn` | Called to allow/deny collision pairs |
| `b2World_SetPreSolveCallback(worldId, fcn*, void* ctx)` | `b2PreSolveFcn` | Called before contact resolution |

Callback typedefs:
```c
typedef bool b2CustomFilterFcn(b2ShapeId shapeIdA, b2ShapeId shapeIdB, void* context);
typedef bool b2PreSolveFcn(b2ShapeId shapeIdA, b2ShapeId shapeIdB, b2Manifold* manifold, void* context);
```

These are persistent — set once, called every physics step. The `void* context` must stay valid.

**Implementation strategy — hand-written C helpers:**

Keep a static `trampolineContext customFilter_ctx` and `trampolineContext preSolve_ctx`. When
the JS setter is called, update the stored trampolineContext and call
`b2World_SetCustomFilterCallback(worldId, trampoline, &customFilter_ctx)`. Same heap/lifetime
management as the existing `AudioStreamCallback` pattern (static array at module scope).

**Effort**: ~2 hours.

---

### Category D — b2World_CastMover (no callback needed — check if fixable)

`b2World_CastMover(worldId, const b2Capsule* mover, b2Vec2 translation, b2QueryFilter filter)` → `float`

This has **no callback**. It was likely ignored because of the `const b2Capsule*` pointer arg.
The bindings system handles pointer args as arrays (e.g., `[capsule]`). Worth testing whether
simply removing the `ignore()` makes it work.

**Effort**: ~30 minutes to test.

---

### Category E — userData (Set/Get for World, Body, Shape, Joint)

8 functions: `b2World_Set/GetUserData`, `b2Body_Set/GetUserData`, `b2Shape_Set/GetUserData`,
`b2Joint_Set/GetUserData`. These take or return `void*`.

The C `void*` has no meaningful representation in JS. However, the use-case — attaching arbitrary
data to a physics entity — is fully achievable in JS without going to C.

**Implementation strategy — pure JS extension module (`lib/box2d_userdata.js`):**

```js
// lib/box2d_userdata.js
// Box2D IDs are structs; use index1 field as a fast key.
// Prefix with type char to avoid collisions between body/shape/joint IDs.

const _store = new Map()

function _key(prefix, id) { return prefix + id.index1 + '_' + id.revision }

export function b2WorldSetUserData(id, val) { _store.set(_key('w', id), val) }
export function b2WorldGetUserData(id) { return _store.get(_key('w', id)) ?? null }

export function b2BodySetUserData(id, val) { _store.set(_key('b', id), val) }
export function b2BodyGetUserData(id) { return _store.get(_key('b', id)) ?? null }

export function b2ShapeSetUserData(id, val) { _store.set(_key('s', id), val) }
export function b2ShapeGetUserData(id) { return _store.get(_key('s', id)) ?? null }

export function b2JointSetUserData(id, val) { _store.set(_key('j', id), val) }
export function b2JointGetUserData(id) { return _store.get(_key('j', id)) ?? null }
```

This becomes importable as `rayjs:ext:box2d_userdata`. No C changes needed.  
**Caveat**: entries aren't cleaned up when bodies are destroyed — callers must remove entries
manually if memory pressure is a concern.

**Effort**: ~1 hour.

---

### Category F — Contact data output arrays

| Function | Pattern |
|---|---|
| `b2Body_GetContactData(bodyId, b2ContactData* out, int capacity)` → int | caller-allocated output buffer |
| `b2Shape_GetContactData(shapeId, b2ContactData* out, int capacity)` → int | same |

The return value is the count of contacts actually written.

**Implementation strategy — hand-written C wrapper:**

```c
// Wrapper: call with a fixed max-size stack buffer, convert to JS array
static JSValue js_b2Body_GetContactData_bridge(JSContext* ctx, JSValue this_val,
                                                int argc, JSValue* argv) {
    b2BodyId bodyId = ...;
    const int MAX = 32;
    b2ContactData buf[MAX];
    int count = b2Body_GetContactData(bodyId, buf, MAX);
    JSValue arr = JS_NewArray(ctx);
    for (int i = 0; i < count; i++) {
        // convert buf[i] to JS b2ContactData struct and append
    }
    return arr;
}
```

**Effort**: ~2 hours.

---

### Category G — b2DebugDraw (physics debug renderer)

`b2World_Draw(worldId, b2DebugDraw*)` + `b2DebugDraw` struct with 9 function pointer fields.

```c
typedef struct b2DebugDraw {
    void (*DrawPolygonFcn)(const b2Vec2* vertices, int vertexCount, b2HexColor color, void* context);
    void (*DrawSolidPolygonFcn)(b2Transform, const b2Vec2*, int, float radius, b2HexColor, void*);
    void (*DrawCircleFcn)(b2Vec2, float, b2HexColor, void*);
    void (*DrawSolidCircleFcn)(b2Transform, float, b2HexColor, void*);
    void (*DrawSolidCapsuleFcn)(b2Vec2, b2Vec2, float, b2HexColor, void*);
    void (*DrawSegmentFcn)(b2Vec2, b2Vec2, b2HexColor, void*);
    void (*DrawTransformFcn)(b2Transform, void*);
    void (*DrawPointFcn)(b2Vec2, float, b2HexColor, void*);
    void (*DrawStringFcn)(b2Vec2, const char*, b2HexColor, void*);
    // ... bool flags ...
    void* context;
} b2DebugDraw;
```

This is useful for debugging physics in development. Not required for shipping games.

**Implementation strategy — hand-written bridge struct:**

Create a `js_b2DebugDrawBridge` C struct that holds one `trampolineContext` per draw method.
Expose a `b2DebugDrawCreate(jsDrawObject)` JS function that:
1. Allocates a bridge on the heap
2. Reads method properties from `jsDrawObject` (e.g., `drawPolygon`, `drawCircle`, etc.)
3. Stores each JS function in the bridge's corresponding trampolineContext
4. Sets each function pointer in a `b2DebugDraw` to a per-type static trampoline that reads
   the context pointer from the shared `b2DebugDraw.context = bridge`

The bridge must be explicitly freed by calling `b2DebugDrawDestroy(bridge)`.

**Effort**: ~5-6 hours. High complexity, optional — only needed for physics debugging.

---

### Category H — b2DynamicTree, internal/threading functions (not worth binding)

| Item | Reason |
|---|---|
| `b2SetAllocator`, `b2SetAssertFcn`, `b2InternalAssertFcn` | threading/internal — no JS use case |
| `b2Hash`, `b2GetMillisecondsAndReset` | internal utilities; `uint64_t*` arg not worth mapping |
| `b2DynamicTree` struct | low-level AABB tree; the world API is sufficient |

These should remain ignored.

---

## Priority order and effort estimate

| Priority | Item | Strategy | Status | Effort | Value |
|---|---|---|---|---|---|
| 1 | Simple callbacks (Friction/Restitution) | Register in `module.callbacks` | ✅ Done | 1h | medium |
| 2 | b2World_CastMover (no callback) | Remove `ignore()`, test | ✅ Done | 0.5h | medium |
| 3 | Per-call query/cast (OverlapAABB, CastRay, etc.) | Hand-written C helpers in `src/box2d_helpers.h` | Pending | 4h | HIGH |
| 4 | Persistent callbacks (CustomFilter, PreSolve) | Hand-written C helpers | Pending | 2h | high |
| 5 | userData (Set/Get × 4 entity types) | JS extension module `lib/box2d_userdata.js` | Pending | 1h | medium |
| 6 | Contact data output arrays | Hand-written C wrapper | Pending | 2h | medium |
| 7 | b2DebugDraw | Hand-written bridge struct | Pending | 6h | low (debug only) |

---

## Step-by-step: Category A (simple callbacks) — ✅ complete

Implemented. Notes on what was actually needed vs. the original plan:

**Additional generator fix required** (not anticipated in the plan):

The `addCallback` loop in `index.js` and the mode detection in `raylib-header.js:addApiFunction`
both used `simpleregex` at `pos=0` to find `set`/`attach`/`detach` in function names. This
works for raylib (functions start with `Set`/`Attach`/`Detach`) but silently fails for box2d
(`b2World_SetFrictionCallback` has an `b2World_` prefix). Both sites were changed to
`String.includes()`, which scans the full name. This fix is general — it benefits any future
module with prefixed naming.

**`bindings/src/index.js`** — callback registration block added before the ignore section:

```js
// Register b2FrictionCallback and b2RestitutionCallback as bindable callback types
const frictionCb = modules['box2d'].getCallback('b2FrictionCallback');
if (frictionCb) {
    modules['box2d'].callbacks.push(frictionCb);
    modules['box2d'].getFunction('b2World_SetFrictionCallback').args[1].type = 'b2FrictionCallback';
}
const restitutionCb = modules['box2d'].getCallback('b2RestitutionCallback');
if (restitutionCb) {
    modules['box2d'].callbacks.push(restitutionCb);
    modules['box2d'].getFunction('b2World_SetRestitutionCallback').args[1].type = 'b2RestitutionCallback';
}
```

Then remove:
```js
modules['box2d'].ignore("b2World_SetFrictionCallback");
modules['box2d'].ignore("b2World_SetRestitutionCallback");
```

If `getCallback` doesn't find them (they're `typedef`s not parsed as callbacks), manually push:
```js
modules['box2d'].callbacks.push({
    name: 'b2FrictionCallback',
    returnType: 'float',
    args: [
        {name:'frictionA', type:'float'},
        {name:'userMaterialIdA', type:'int'},
        {name:'frictionB', type:'float'},
        {name:'userMaterialIdB', type:'int'},
    ],
    binding: {},
});
```

---

## Step-by-step: Category B (per-call query callbacks) — design

For `b2OverlapResultFcn` and `b2CastResultFcn`, generate two static trampolines in
`src/box2d_helpers.h`. Each JS wrapper:

1. Validates arg count and JS function arg
2. Builds a stack `trampolineContext tc = {ctx, jsFunc}`
3. Calls `b2World_Overlap*(...)` with the trampoline and `&tc`
4. Converts and returns `b2TreeStats`

The generated `js_b2ShapeId_class_id` is already available from the generated bindings — use
it to create JSValue wrappers for shape IDs passed to the callback.

**Registration**: cleanest point is at the end of `js_init_module_box2d` in `js_box2d.h`,
before `return m`, via `JS_SetModuleExport(ctx, m, "b2World_OverlapAABB", js_b2World_OverlapAABB_bridge)`.

---

## Notes

- The `trampolineContext` struct is defined in `src/rayjs_base.h` — `src/box2d_helpers.h` can
  include it directly.
- Box2D ID structs (`b2ShapeId`, `b2BodyId`, etc.) already have `js_*_class_id` values in
  `src/rayjs_generated.h` — use them when constructing JSValues in trampolines.
- Always `JS_DupValue` a JS callback before storing it in a persistent trampolineContext; always
  `JS_FreeValue` when done (or when the callback is unregistered).
- For per-call (stack-allocated) trampolineContexts: no need to Dup/Free the JS function
  since the function's lifetime exceeds the synchronous call.
