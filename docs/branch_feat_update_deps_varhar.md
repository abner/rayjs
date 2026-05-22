# Branch: feat/update-deps-varhar

This is the active development branch. It builds on the earlier dependency-modernization work
(quickjs-ng migration in Phase 1, raylib 6.0 upgrade in Phase 2 — see
[`docs/project_overview.md`](project_overview.md)) and adds two things:

1. **All four submodules bumped to their newest versions**
2. **Box2D v3 added as the new `rayjs:box2d` native module**

---

## Submodule versions

| Submodule | Version / commit |
|---|---|
| `thirdparty/quickjs` | quickjs-ng v0.14.0 (`3c051980`) |
| `thirdparty/raylib` | raylib 6.0 (`dbc56a87`) |
| `thirdparty/raygui` | latest master (`b256d455`) |
| `thirdparty/mimalloc` | v3.3.2 (`30b2d9d8`) |
| `thirdparty/box2d` | Box2D v3.x (new submodule) |

---

## Box2D v3 integration — files changed

| File | What changed |
|---|---|
| `CMakeLists.txt` | box2d `add_subdirectory` + include path + link target |
| `bindings/src/index.js` | box2d header parsing, generator customizations, ignore list, field binding overrides |
| `bindings/src/raylib-header.js` | `isEnum` fix for struct getters; `binding.set` guard for const ArrayProxy setters |
| `bindings/src/quickjs.js` | enum→int32 cast fix; `double` default return `0.0d` → `0.0` |
| `bindings/src/typescript.js` | defensive null check for `enumtype` tokens |
| `src/rayjs_base.h` | `extern js_init_module_box2d` declaration; `#ifndef` guards for `MAX_MESH_VERTEX_BUFFERS` etc. |
| `src/rayjs_base.c` | `js_init_module_box2d(ctx, "rayjs:box2d")` call in `JS_NewCustomContext()` |
| `src/rayjs.c` | `#include "modules/js_box2d.h"` |
| `src/modules/js_box2d.h` | generated — 543 bindings |
| `examples/box2d/hello_physics.js` | demo: bouncing ball with restitution — verified working |

---

## Generator bugs fixed (permanent)

These were discovered while integrating Box2D and are now fixed in `bindings/src/`:

1. **Enum → int32 cast** (`quickjs.js`): `cToJs` was emitting `JS_NewInt32(ctx, (int)(src))`.
   `(int)(localvar)` breaks `compilefunctionargs` — `resolveVariable` treats `(int)` as the
   initial value and silently drops the variable, producing `(int32_t)int` in C.  
   **Fix**: pass `src` directly; `cast()` handles `EnumType → int32_t` correctly.

2. **Enum struct fields treated as pointers** (`raylib-header.js`): `isobject()` returns true
   for `type:'type'` variables including enums, so `jsStructGetter` wrapped enum fields in the
   anchor/pointer path.  
   **Fix**: added explicit `isEnum` check to take the plain-value path for enum-typed fields.

3. **Const pointer ArrayProxy setter** (`raylib-header.js`): `jsStructGetter_array` always
   generated a mutating `_set` function even when `binding.set = false`, causing
   `read-only variable is not assignable` for `const T*` fields.  
   **Fix**: `if (binding.set === false)` emits a `return false` stub instead.

4. **`double` default return suffix** (`quickjs.js`): was `"0.0d"` — invalid C.  
   **Fix**: changed to `"0.0"`.

5. **`JS_SetModuleExportList` 4th arg** (`index.js` toolsSource): quickjs-ng v0.14.0 added a
   `len` argument. The old toolsSource entry had only 3 args — the call was silently dropped.  
   **Fix**: added `{type:'int', name:'len'}` to the toolsSource entry.

6. **`unsigned char *` vs `char *` mismatch** (`raylib-header.js`): `endsWith('char *')`
   matched both. The getter used `!== 'char *'` but the ArrayProxy condition used `endsWith`,
   omitting ArrayProxy functions for `unsigned char *` fields while still referencing them.  
   **Fix**: both conditions now use strict `!== 'char *' && !== 'const char *'`.

---

## Key JS API facts for rayjs:box2d

- **Enum values** are exported individually: use `b2_dynamicBody`, not `b2BodyType.b2_dynamicBody`.
- **Struct position fields** require a struct instance: `bodyDef.position = new b2Vec2(0, 10)`,
  not `{x:0, y:10}`.
- **Nested struct fields** return a live proxy — mutations write back to the parent directly.
  Use `shapeDef.material.restitution = 0.75`, not `shapeDef.restitution`.
- **`b2Default*` factories** return a single struct (not array despite a known TS typings bug).
- **Coordinate system**: Box2D is Y-up; raylib is Y-down. Flip Y when converting to screen coords.

---

## What's still ignored (API coverage gaps)

18 functions and 2 structs are currently ignored (down from 27 at initial integration). See
[`docs/box2d_api_coverage_plan.md`](box2d_api_coverage_plan.md) for the full classification
and implementation plan.

### Unblocked since initial integration

| Function | How |
|---|---|
| `b2World_SetFrictionCallback` | Registered `b2FrictionCallback` as a callback type; fixed generator `includes()`-based set/attach detection |
| `b2World_SetRestitutionCallback` | Same fix |
| `b2World_CastMover` | Removed erroneous `ignore()` — no callbacks involved, just a `const b2Capsule*` pointer arg |

The generator fix (`String.includes()` replacing positional `simpleregex` in `index.js` and
`raylib-header.js`) is general — it unblocks any future module with prefixed function names.

### Remaining priority items

- Per-call query/cast callbacks (`b2World_OverlapAABB`, `b2World_CastRay`, etc.) — ~4h, highest gameplay value
- Persistent world callbacks (`b2World_SetCustomFilterCallback`, `b2World_SetPreSolveCallback`) — ~2h
- userData (Set/Get × 4 entity types) — ~1h, pure JS extension module
