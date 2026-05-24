# Bindings generator — pitfalls and recurring traps

This doc captures three classes of bug that have bitten the rayjs bindings
generator (`bindings/src/`) and how to recognize them. Each one started as
a "small" surface symptom and turned out to be a structural issue in how
the generator emits C code or how generated files are maintained.

Read this before:
- Adding a new field-binding override that disables a struct field.
- Wiring up a new native helper that has to plug into a generated module.
- Adding a `-Wno-error=` flag to `CMakeLists.txt`.

---

## Rule 1 — Never edit `src/modules/js_*.h` directly

Every file under `src/modules/js_*.h` is rewritten wholesale by
`node bindings/src/index.js`. Any edit applied directly to those files
survives only until the next regen — which can be triggered by anyone
fixing an unrelated generator bug.

### The trap, told in two commits

Commit `d970eed` ("Complete Box2D callback bindings: Categories A-E")
hand-patched `src/modules/js_box2d.h` to wire up the trampolines in
`src/box2d_helpers.h`:

```c
#include "../box2d_helpers.h"          // ← injected before js_box2d_init

static int js_box2d_init(JSContext * ctx, JSModuleDef * m) {
    size_t listcount = countof(jsbox2d_funcs);
    JS_SetModuleExportList(ctx, m, jsbox2d_funcs, (int)listcount);
    // ↓ 7 injected lines
    JS_SetModuleExport(ctx, m, "b2World_OverlapAABB",  JS_NewCFunction(ctx, js_b2World_OverlapAABB_bridge,  "b2World_OverlapAABB",  4));
    JS_SetModuleExport(ctx, m, "b2World_CastRay",      JS_NewCFunction(ctx, js_b2World_CastRay_bridge,      "b2World_CastRay",      5));
    // ... etc
}
```

`bindings/src/index.js` was **not** modified — the `ignore("b2World_CastRay")` line
stayed in place. Six months later, commit `c8d684b` regenerated all module headers
to fix the Model constructor (Rule 2 below) and silently wiped the bridge exports.
`examples/box2d/platformer_scarfy.js` failed at module load:

```
SyntaxError: Could not find export 'b2World_CastRay' in module 'rayjs:box2d'
```

The helpers file (`src/box2d_helpers.h`) was untouched — only the glue that
exposes its symbols to JS got wiped.

### The fix pattern (commit `57221ff`)

When a fix has to be post-generation — e.g. injecting a `#include` for a
hand-written helpers file that references JS class IDs declared mid-output —
add a textual replacement inside the writeTo loop in `bindings/src/index.js`:

```js
// in the `for (let key in modules)` loop at ~L1330
module.gen.writeTo(outPath);
const buf = fs.readFileSync(outPath, 'utf8');
let fixed = buf
    .replace(/memoryStore\(js_free,\(void  *\*\)\*/g, 'memoryStore(js_free,(void *)')   // pre-existing
    .replace(/memoryStore\(jsc_free,\(void  *\*\)\*/g, 'memoryStore(jsc_free,(void *)');
if (module.gen.name === 'box2d') {
    // inject #include / JS_SetModuleExport / JS_AddModuleExport via .replace()
}
if (fixed !== buf) fs.writeFileSync(outPath, fixed);
```

There is already a precedent at this location (the `memoryStore` pointer-of-pointer
cast workaround) — keep all post-writeTo patches together.

### Reviewer heuristic

If a PR diff touches `src/modules/js_*.h` **without** touching
`bindings/src/index.js` (or `bindings/src/raylib-header.js`), it's almost
certainly creating a regen landmine. Either:
- Move the change into the generator, or
- Add it as a post-writeTo replacement in the loop described above.

The only legitimate edit-the-generated-file pattern is the GCC-14
`-Wno-error=` flag in CMakeLists.txt: a known-broken generator output
gets demoted from error to warning while the proper fix is being worked.
Even then, the flag's comment must name the generator-side fix that will
remove the demotion.

---

## Rule 2 — Use designated initializers when emitting struct constructors

C99 brace-init lists are positional. If a struct contains a nested-struct
**value** field whose `.binding.get` is `false`, a generator that emits a
single `0` placeholder for that field will silently spill the placeholder
into the nested struct's first sub-field, shifting every subsequent value
by N-1 positions (where N is the nested struct's field count).

### The trap

raylib 6.0 introduced:

```c
typedef struct ModelSkeleton {
    int boneCount;          // sub-field 0
    BoneInfo *bones;        // sub-field 1
    Transform *bindPose;    // sub-field 2
} ModelSkeleton;

typedef struct Model {
    Matrix transform;          // 0
    int meshCount;             // 1
    int materialCount;         // 2
    Mesh *meshes;              // 3
    Material *materials;       // 4
    int *meshMaterial;         // 5
    ModelSkeleton skeleton;    // 6  ← nested struct (3 sub-fields)
    Transform *currentPose;    // 7
    Matrix *boneMatrices;      // 8
} Model;
```

`bindings/src/index.js` disables `model.skeleton` (since `ModelSkeleton` is
its own bound type) with `binding.get = false`. The pre-fix generator emitted:

```c
_struct = (Model){
    transform, meshCount, materialCount,
    meshes, materials, meshMaterial,
    0,             // intended as skeleton placeholder
    currentPose,   // ⚠ consumed as skeleton.bones      (Transform* → BoneInfo*)
    boneMatrices,  // ⚠ consumed as skeleton.bindPose   (Matrix*    → Transform*)
};
// top-level currentPose / boneMatrices → MISSING → zero-init to NULL
```

Two pointers landed in the wrong nested-struct slots, the actual
top-level fields were silently nulled, and on GCC-14
`-Wincompatible-pointer-types` blocked the build.

### The fix pattern (commit `c8d684b`)

Emit `.fieldname = value` for every bound field; **omit** disabled fields
entirely so C99 zero-initialization handles them:

```c
_struct = (Model){
    .transform = transform,
    .meshCount = meshCount,
    .materialCount = materialCount,
    .meshes = meshes,
    .materials = materials,
    .meshMaterial = meshMaterial,
    .currentPose = currentPose,
    .boneMatrices = boneMatrices,
    // .skeleton omitted; C99 zero-inits it
};
```

This is correct regardless of upstream header field reordering, and it
keeps working for structs whose nested fields **are** bound (those already
worked under positional init because the typed value matched the
sub-aggregate type — e.g. `Camera3D.position` of type `Vector3` consumes
the entire nested aggregate from a single `Vector3` value).

### Edge cases the generator must handle

- **All fields disabled**: an empty designator list `(Type){}` is invalid
  in C99/C11. Fall back to `{0}` (zero-init). The generator does this
  guard already.
- **Fixed-size array fields** (e.g. `Material.params[4]`): emit
  `.params = {params[0], params[1], ...}`. Designated init plus a
  brace sub-initializer is valid C99.

### Audit before changing this code

Before changing `jsStructConstructor`, run a quick audit: how many bound
structs contain a sub-field whose type is itself a bound struct? The
session that fixed this found 63 such structs — but only **one**
(`Model.skeleton`) had the disabled-field-on-a-nested-struct combination
that triggered the bug. Most nested struct fields are bound, so they
work correctly under either init style.

---

## Rule 3 — A `-Wno-error=` flag is a deadline, not a fix

When a generator-emitted artifact violates a newly-strict compiler
diagnostic, the immediate response is often to demote the flag so CI
stays green. That's appropriate as a stop-gap — but the demotion is
a **debt**, not a solution.

### Bookkeeping rules

Every `-Wno-error=` line in `CMakeLists.txt` must:

1. **Name the specific generator-side fix** that will remove the
   demotion, in a comment immediately above the line.
2. **Be removed as soon as the generator-side fix lands**, in a
   follow-up commit reviewable independently from the fix itself.
3. **Never silently outlive the bug it was masking**. A flag with no
   matching open issue is camouflage for the next bug to land in the
   same code path.

### What "follow-up commit" looks like

The session that fixed `jsStructConstructor` shipped three commits
intentionally:

| Commit    | Scope                                                |
| --------- | ---------------------------------------------------- |
| `c8d684b` | Generator fix + regenerated headers                  |
| `57221ff` | Persistence fix for an unrelated regen-landmine      |
| `d9c679f` | Drop `-Wno-error=incompatible-pointer-types` only    |

Splitting the safety-net removal into its own commit means: if Windows
MinGW CI surprises us, `git revert d9c679f` restores the safety net
without touching the actual fix. A bisect from any future bug lands
on the smallest possible change.

### When demoting is fine

Two of the three demotions on `feat/update-deps-varhar` stayed:
`-Wno-error=int-conversion` and
`-Wno-error=implicit-function-declaration`. Both mask separate
upstream `quickjs-libc.c` signal-handler stubs on glibc — completely
unrelated to the generator. The CMakeLists.txt comment is explicit
about this so future contributors don't assume they're the same bug
and remove them together.

---

## Related material

- [`bindings_struct_constructor_plan.md`](bindings_struct_constructor_plan.md) —
  the original plan that scoped the designated-init fix (now RESOLVED;
  see that file's header).
- [`box2d_api_coverage_plan.md`](box2d_api_coverage_plan.md) — the
  classification of Box2D callback families. Category B (per-call query
  callbacks like `b2World_CastRay`) is implemented via
  `src/box2d_helpers.h` because it needs a JS-callback-plus-opaque-context
  pattern the generic generator can't auto-wrap.
- [`adding_native_module.md`](adding_native_module.md) — full developer
  walkthrough for adding a `rayjs:<name>` module. The generator-bug
  catalog at the bottom is the historical record of `bindings/src/`
  bugs found during the Box2D v3 integration.
