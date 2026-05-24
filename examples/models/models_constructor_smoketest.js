// Smoke test for two bindings-generator fixes that landed on
// feat/update-deps-varhar:
//
//   1. `jsStructConstructor` now emits C99 designated initializers. Before
//      that fix, `new Model(...)` silently NULL'd the top-level
//      currentPose / boneMatrices fields (the values were mis-routed into
//      the nested ModelSkeleton via positional brace-init).
//
//   2. Model.skeleton is exposed as three flat read-only accessors —
//      `model.boneCount`, `model.bones`, `model.bindPose` — via the new
//      `binding.virtual` + `binding.access` field-binding overrides in the
//      generator. Before that, those three properties returned undefined
//      because the JS-side `model.skeleton` getter was disabled and no
//      flattening was wired up.
//
// What the script does:
//   - LoadModel a real IQM model (built natively by raylib).
//   - Read the three flat skeleton accessors and assert they're populated.
//   - Reconstruct the model via `new Model(...)` and assert the top-level
//     pointer fields survived (the constructor regression).
//
// Run from the repo root: `./rayjs examples/models/models_constructor_smoketest.js`
// (rayjs chdir's into the script's directory, so the resources/ path is
// relative to examples/models/).

import {
    InitWindow, CloseWindow, LoadModel, UnloadModel,
    Model
} from 'rayjs:raylib';

InitWindow(160, 120, "model-ctor smoke test");

const src = LoadModel("resources/models/iqm/guy.iqm");

console.log("source model loaded");
console.log("  meshCount     =", src.meshCount);
console.log("  materialCount =", src.materialCount);
console.log("  boneCount     =", src.boneCount);

const dst = new Model(
    src.transform,
    src.meshCount,
    src.materialCount,
    src.meshes,
    src.materials,
    src.meshMaterial,
    src.currentPose,
    src.boneMatrices,
);

console.log("rebuilt model via new Model(...):");
console.log("  meshCount     =", dst.meshCount);
console.log("  materialCount =", dst.materialCount);
console.log("  boneCount     =", dst.boneCount);

let ok = true;
function check(name, cond, detail) {
    console.log(`  ${cond ? "OK " : "FAIL"}  ${name}${detail ? "  ("+detail+")" : ""}`);
    if (!cond) ok = false;
}

// Fix #2 — flat skeleton accessors on the source model. The IQM "guy"
// has a real skeleton, so boneCount should be > 0 and the array proxies
// non-null.
check("src.boneCount is a positive integer",
      Number.isInteger(src.boneCount) && src.boneCount > 0,
      `src.boneCount = ${src.boneCount}`);
check("src.bones is non-null",
      src.bones !== null && src.bones !== undefined,
      `typeof = ${typeof src.bones}`);
check("src.bindPose is non-null",
      src.bindPose !== null && src.bindPose !== undefined,
      `typeof = ${typeof src.bindPose}`);

// Fix #1 — the rebuilt model's top-level pointer fields. Before the
// designated-init fix, these landed in the nested skeleton and the
// top-level slots got implicit-zero-init'd to NULL.
check("dst.meshCount matches",
      src.meshCount === dst.meshCount,
      `src=${src.meshCount} dst=${dst.meshCount}`);
check("dst.materialCount matches",
      src.materialCount === dst.materialCount,
      `src=${src.materialCount} dst=${dst.materialCount}`);
check("dst.currentPose is non-null",
      dst.currentPose !== null && dst.currentPose !== undefined,
      `typeof = ${typeof dst.currentPose}`);
check("dst.boneMatrices is non-null",
      dst.boneMatrices !== null && dst.boneMatrices !== undefined,
      `typeof = ${typeof dst.boneMatrices}`);
// The constructor takes only top-level bound fields. `skeleton` is not in
// the JS constructor's signature (it's a nested struct re-exposed via flat
// virtual accessors), so designated-init zero-inits ModelSkeleton on the
// rebuilt model. Asserting boneCount === 0 here documents that: if you
// need skeleton data preserved, use the copy-constructor `new Model(src)`
// instead of the explicit-fields form.
check("dst.boneCount is 0 (skeleton not passed)",
      dst.boneCount === 0,
      `dst.boneCount = ${dst.boneCount}`);

console.log(ok ? "PASS" : "FAIL");

UnloadModel(src);
CloseWindow();
