# Plan: Fix the struct constructor generator for nested structs

## Symptom

GitHub Actions CI on Windows (MinGW Winlibs, gcc 14+) fails with:

```
src/modules/js_raylib.h:14010:33: error: initialization of 'BoneInfo *' from incompatible
                                        pointer type 'Transform *' [-Wincompatible-pointer-types]
14010 |    currentPose,
      |    ^~~~~~~~~~~
note: (near initialization for '(anonymous).skeleton.bones')

src/modules/js_raylib.h:14011:33: error: initialization of 'Transform *' from incompatible
                                        pointer type 'Matrix *' [-Wincompatible-pointer-types]
14011 |    boneMatrices
      |    ^~~~~~~~~~~~
note: (near initialization for '(anonymous).skeleton.bindPose')
```

Clang and gcc < 14 emit the same diagnostics but as plain warnings, so macOS / older
Linux survive. GCC 14 promoted `-Wincompatible-pointer-types` to a default error, which
makes the latent bug fatal.

## Why CI is now green anyway

`CMakeLists.txt` adds `-Wno-error=incompatible-pointer-types` (plus
`-Wno-error=int-conversion`, `-Wno-error=implicit-function-declaration`) so the build
links on every toolchain. **The misgenerated code is still misgenerated** — the
`js_Model_constructor` produces a `Model` struct with the wrong fields populated. We
just hid the diagnostic so unrelated work can proceed.

**This plan needs to land before the `-Wno-error=` flags can be removed.** Once the
generator is correct, drop the three `Wno-error` lines from `CMakeLists.txt` so future
regressions surface immediately.

---

## Root cause

raylib 6.0 introduced a nested struct in `Model`:

```c
typedef struct ModelSkeleton {
    int boneCount;
    BoneInfo *bones;
    ModelAnimPose bindPose;  // Transform *
} ModelSkeleton;

typedef struct Model {
    Matrix transform;          // top-level field 0
    int meshCount;             //                 1
    int materialCount;         //                 2
    Mesh *meshes;              //                 3
    Material *materials;       //                 4
    int *meshMaterial;         //                 5
    ModelSkeleton skeleton;    //                 6  ← NESTED STRUCT (3 sub-fields)
    ModelAnimPose currentPose; //                 7
    Matrix *boneMatrices;      //                 8
} Model;
```

`bindings/src/raylib-header.js → jsStructConstructor()` emits a positional aggregate
initializer over the parser's flat field list. For a struct with a nested-struct field
it produces:

```c
_struct = (Model){
    transform,
    meshCount,
    materialCount,
    meshes,
    materials,
    meshMaterial,
    0,             // ← intended as ModelSkeleton zero placeholder, but…
    currentPose,
    boneMatrices
};
```

C aggregate-init rules walk top-level fields left-to-right and recurse into nested
structs. The brace-list above is consumed as:

| value supplied | bound to actual field      | correct? |
| -------------- | -------------------------- | -------- |
| transform      | `transform`                | yes      |
| meshCount      | `meshCount`                | yes      |
| materialCount  | `materialCount`            | yes      |
| meshes         | `meshes`                   | yes      |
| materials      | `materials`                | yes      |
| meshMaterial   | `meshMaterial`             | yes      |
| 0              | `skeleton.boneCount`       | yes      |
| currentPose    | `skeleton.bones` ⚠         | **no — type mismatch** |
| boneMatrices   | `skeleton.bindPose` ⚠      | **no — type mismatch** |
| (missing)      | `currentPose` (top-level)  | zero-init |
| (missing)      | `boneMatrices` (top-level) | zero-init |

So the generator (a) misplaces two pointers into the nested skeleton, and (b) silently
zero-initializes the actual top-level `currentPose`/`boneMatrices` fields. The JS
`new Model(...)` path is therefore broken regardless of the compiler diagnostic.

The generator's `jsStructConstructor` (in `bindings/src/raylib-header.js` around the
field-loop block that builds `structArgs`) has no handling for nested-struct fields —
it just pushes `field.name` into the brace list and trusts positional matching.

---

## Audit: are other structs affected?

Quick grep for nested-struct fields in raylib 6.0 / Box2D / raygui headers, scoped to
types we currently bind. Need to enumerate before fixing — known candidate so far is
just `Model.skeleton`. Likely other suspects:

- `Mesh` (only POD fields and pointers — fine)
- `ModelAnimation` (compiler did not complain — likely fine)
- Box2D — most types are PODs with primitives; double-check `b2WorldDef`, `b2BodyDef`
  for any nested filter/contact-event sub-structs that surface as a nested type rather
  than a field-list flatten.

**Step 0** of the implementation should be: run a one-off scan to list every bound
struct that has a sub-field of `type === 'struct'`. That gives the exact test set.

---

## Fix options

### Option A — Designated initializers (recommended)

Emit:

```c
_struct = (Model){
    .transform   = transform,
    .meshCount   = meshCount,
    .materialCount = materialCount,
    .meshes      = meshes,
    .materials   = materials,
    .meshMaterial = meshMaterial,
    .skeleton    = (ModelSkeleton){0},
    .currentPose = currentPose,
    .boneMatrices = boneMatrices,
};
```

Pros: each value is bound by name, so nested-struct fields are immune; readable; works
for any future field reordering or insertion in upstream raylib; standard since C99 so
all our toolchains support it.

Cons: requires the field list to carry stable names through the generator — already
true, since `field.name` is the value being pushed today.

Implementation sketch in `jsStructConstructor`:
- Replace the existing `structArgs.push(field.name)` loop with one that builds
  `{name, value}` pairs and emits `.name = value` per row.
- For a nested-struct field whose binding is disabled, emit `.name = (Type){0}` instead
  of bare `0`.
- The existing `body.declare(structType, "_struct", structArgs)` path becomes a single
  `body.assign("_struct", "(Type){...}")` call (or a small extension to `declare` to
  support designator syntax).

Effort: ~2–3 hours, including the cgen helper for designator syntax.

### Option B — Per-field assignment after zero-init

```c
Model _struct = {0};
_struct.transform     = transform;
_struct.meshCount     = meshCount;
...
_struct.currentPose   = currentPose;
_struct.boneMatrices  = boneMatrices;
```

Pros: avoids any change to brace-init handling; no risk of cgen helper rewrites.

Cons: more lines emitted per struct constructor; the generator already has
`assign()`/`declare()` primitives, so wiring is straightforward, but the diff to
existing `jsStructConstructor` is larger.

Effort: ~2 hours.

### Option C — Special-case nested structs in the brace list (NOT recommended)

Detect `field.type === 'struct'` and emit `(SubType){0}` in its slot. Keeps positional
ordering but is fragile: it only fixes the `0`-placeholder case; if someone adds JS
support for constructing a nested struct from JS args later, positional ordering would
re-bite us. Skip this.

---

## Recommended path

1. **Audit** — small JS script (or quick generator instrumentation) that lists every
   struct currently bound and flags those with `type === 'struct'` sub-fields. Output
   becomes the regression test set.
2. **Implement Option A** (designated initializers) in `jsStructConstructor`.
3. **Regenerate** `src/modules/js_raylib.h` (and any other module headers); diff to
   confirm the only changes are the constructor bodies.
4. **Local build** on macOS — should drop all 5+ `incompatible-pointer-types` /
   `pointer-sign` warnings from the relevant constructors. Don't expect every
   `pointer-sign` warning to vanish — many come from getter code paths
   (`returnVal = CompressData(...)`) which are a separate generator issue.
5. **Push and watch CI** on Windows / Linux / macOS.
6. **Remove the `-Wno-error=…` flags** from `CMakeLists.txt` once all three platforms
   are green without them. (Add a follow-up commit so the fix and the safety-net
   removal are reviewable independently.)
7. **JS smoke test** — `new Model(...)` round-trip from a small example, exercising
   field accessors to confirm the struct is populated correctly.

---

## Related generator issues (out of scope here, file separately if hit)

- `Wpointer-sign` warnings in `js_raylib.h` (`CompressData`, `DecompressData`,
  `ExportImageToMemory`, `ComputeMD5/SHA1/SHA256`, etc.) — return-value capture types
  `char *` / `int *` instead of `unsigned char *` / `unsigned int *`. Separate fix in
  the getter/return-binding code path.
- `Wformat-insufficient-args` at `src/rayjs.c:320` — hand-written, just a `%s` count
  mismatch in the banner; one-line edit when convenient.
- `-Wint-conversion` in `src/modules/quickjs-libc.c` signal-handler stubs — upstream
  quickjs-ng issue when `_GNU_SOURCE` is set on glibc; harmless and gone on macOS.
