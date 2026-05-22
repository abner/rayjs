# Plan: Typings distribution and organisation

## Context

The TypeScript declarations in `bindings/typings/` give in-repo authors (anyone editing
files under `bindings/src/`, `examples/`, `lib/`) IDE auto-complete and `tsc --noEmit`
type checking against the `rayjs:*` modules exposed by the C runtime.

Three independent producers currently write to the same directory:

| Pattern | Source | Producer | Overwrite rules |
|---|---|---|---|
| `lib.js_<name>.d.ts` | C headers parsed by the binding generator | `qjs bindings/src/index.js` (see `bindings/src/index.js:1335`) | Fully overwritten on every run |
| `lib.js_ext_<name>.d.ts` | Hand-written `lib/<name>.d.ts` wrapped in `declare module "rayjs:ext:<name>"` | `cmake/gen_ext_modules.cmake` at configure time | Fully overwritten on every CMake configure; stale files removed |
| `lib.js_box2d_handbridged.d.ts` | Hand-maintained, no producer | (none) | Never touched by tooling |

Two gaps surfaced while wiring up the box2d hand-bridged augmentation file:

**Gap 1 — No release artifact for typings.** Downstream consumers who ship games using
a prebuilt `rayjs` binary have no way to obtain the type declarations short of cloning
the source repo and copying `bindings/typings/` into their game project by hand. There
is no `package.json` `types` field, no `npm publish` flow, no release attachment.

**Gap 2 — Directory mixes three producers with three overwrite policies.** A future
maintainer adding a new typing file has no on-disk signal indicating which bucket their
file belongs to or which command (if any) regenerates it. The risk is most acute for
hand-maintained files like `lib.js_box2d_handbridged.d.ts` — a contributor unfamiliar
with the project might assume the file is auto-generated and waste time looking for a
non-existent producer, or worse, delete it expecting it to be regenerated.

---

## Goals

1. Make it trivial for a downstream game project to consume `rayjs:*` typings without
   cloning the whole rayjs source tree.
2. Make the three producer/overwrite buckets in `bindings/typings/` self-documenting,
   so adding or modifying a typing file does not require reading `bindings/src/index.js`
   or `cmake/gen_ext_modules.cmake`.
3. Do not break the existing in-repo workflow (`tsconfig.json` `typeRoots` resolution
   from `./bindings/typings/`).

---

## Gap 2 — Self-documenting layout (low-effort, do first)

This is essentially a small refactor + a short README. Doing it before Gap 1 means the
release artifact in Gap 1 has a clear directory structure to package.

### Option A — README only (minimal, recommended starting point)

Add `bindings/typings/README.md` (~40 lines) listing the three buckets, the
producer for each, and the rule for adding a new file in each bucket. No code or
filesystem changes; this is the smallest viable fix for Gap 2.

The README references the relevant source lines:
- `bindings/src/index.js:1335` for the C-header generator
- `cmake/gen_ext_modules.cmake:49-72` for the `lib.js_ext_*` generator
- The header comment of `lib.js_box2d_handbridged.d.ts` for the augmentation pattern

**Pros:** zero risk, ~10 minutes of work, no tooling changes.
**Cons:** the directory still mixes buckets at the filesystem level — a future
maintainer must read the README to know which is which.

### Option B — Sub-directories per bucket

Split into `bindings/typings/generated/`, `bindings/typings/ext/`, and
`bindings/typings/handwritten/`. Update both producers, the `tsconfig.json` typeRoots
list, and any consumers (none exist outside the repo today).

**Pros:** filesystem layout encodes the bucket. Stale-file removal in
`gen_ext_modules.cmake:52-58` can drop its glob qualifier — it already only matches
its own pattern, but the directory split makes accidental deletion of hand-written
files structurally impossible.
**Cons:** touches `bindings/src/index.js` (the writeTo call at line 1335 needs the
new path prefix), `cmake/gen_ext_modules.cmake` (TYPINGS_DIR + glob path), and
`tsconfig.json` (typeRoots list). Larger diff for what is mostly a presentation change.

**Recommendation: Option A first.** Revisit Option B only if the directory grows
much bigger (e.g., dozens of hand-written augmentation files) or if a tooling bug
arises from the shared directory.

### Concrete tasks for Option A

1. Write `bindings/typings/README.md`:
   - One sentence per bucket: filename pattern, producer command, edit policy.
   - A note that `tsconfig.json` `typeRoots` discovers every `.d.ts` in this
     directory, so all three buckets land in the same TypeScript namespace.
   - Pointer to `lib.js_box2d_handbridged.d.ts` as the reference example of a
     hand-maintained augmentation (uses `declare module` + `import type` from the
     same module — the only non-obvious pattern in the directory).

2. Add a top-of-file marker comment to each auto-generated file so the
   "auto-generated, do not edit" intent is visible without opening the README:
   - `lib.js_<name>.d.ts` files are emitted by the binding generator. Add a
     leader line in the generator (`bindings/src/typescript.js` — where the file
     content is assembled) so all generated files carry e.g.
     `// Auto-generated by qjs bindings/src/index.js — do not edit.`
   - `lib.js_ext_<name>.d.ts` files already carry such a header today
     (`bindings/typings/lib.js_ext_box2d_userdata.d.ts:1`).

---

## Gap 1 — Release artifact for downstream consumers

The question is *what* a downstream consumer needs and *how* it should be shipped.

### Downstream consumer profile (assumed)

- A game developer who downloads a `rayjs` binary release.
- Wants IDE auto-complete (`rayjs:raylib`, `rayjs:box2d`, etc.) and optionally
  `tsc --noEmit` checking against their game's `.js` files.
- Does **not** want to clone rayjs source, run `qjs bindings/src/index.js`, or
  build the project locally.

### Option A — Ship typings as an npm package

Publish `@rayjs/typings` (or similar) to npm, containing only `bindings/typings/*.d.ts`
and a minimal `package.json` whose `types` field points at an index file that
re-exports all the `lib.js_*.d.ts` modules.

**Layout:**
```
@rayjs/typings/
├── package.json        // "types": "./index.d.ts"
├── README.md           // installation + tsconfig snippet
├── index.d.ts          // /// <reference path="./lib.js_raylib.d.ts" /> ...
└── lib.js_*.d.ts       // identical content to in-repo files
```

**Publishing:**
- A GitHub Actions job on tag push (`v*`): rsync `bindings/typings/` →
  `packages/typings/`, set the version from the tag, `npm publish`.
- Alternatively, attach `rayjs-typings-<version>.tgz` to the GitHub Release for
  consumers who don't use npm.

**Consumer use:**
```bash
npm install -D @rayjs/typings
```
Then in their `tsconfig.json`:
```json
"typeRoots": ["./node_modules/@rayjs/typings", "./node_modules/@types"]
```

**Pros:** standard, discoverable, versioned alongside binary releases.
**Cons:** introduces an npm publish responsibility. Requires deciding on a
package name (the `rayjs` name on npm is taken by an unrelated project; would
need to use `@scope/rayjs-typings` or `rayjs-types`).

### Option B — Bundle typings in the binary release

Attach `rayjs-typings-<version>.zip` to each GitHub Release alongside the
platform binaries. Consumers extract it next to their game source and point
`typeRoots` at the extracted directory.

**Pros:** no npm dependency for the rayjs project; release process owns it
entirely.
**Cons:** less convenient for the consumer (manual extract, no `npm install`
upgrade flow). Versioning is implicit in the release tag, no semver lookup.

### Option C — Generate consumer-friendly index file in-repo

Regardless of A or B above, add a generated `bindings/typings/index.d.ts` (or
`rayjs.d.ts`) that does:

```ts
/// <reference path="./lib.js_raylib.d.ts" />
/// <reference path="./lib.js_box2d.d.ts" />
/// <reference path="./lib.js_box2d_handbridged.d.ts" />
// ... one line per file ...
```

The file is regenerated by a CMake step that globs `lib.js_*.d.ts`. Consumers
who copy the directory by hand only need to add one `///<reference>` to their
project. This is also what the npm package's entry point would point at.

**Recommendation: Option A + Option C.** The index file (Option C) is a
prerequisite for both A and B and is independently useful for anyone copying
the directory manually today. Option A is the long-term distribution channel
once the project is ready to commit to an npm publishing flow.

### Concrete tasks for Gap 1

1. **Index file generator** (~1 hour). Add to `cmake/gen_ext_modules.cmake` (or
   a new `cmake/gen_typings_index.cmake`) a step that globs
   `bindings/typings/lib.js_*.d.ts` at configure time and writes
   `bindings/typings/index.d.ts` containing one `/// <reference path>` per file.
   Commit `index.d.ts` like every other typing file.

2. **Decide on distribution channel** — npm (Option A) vs GitHub Release zip
   (Option B). Open question: is there an existing release workflow on the
   varhar fork? If yes, attach the zip there as Option B and defer Option A
   until npm publishing is genuinely needed.

3. **Document the consumer flow** in the main `README.md` — a short
   "Using rayjs in a TypeScript-aware editor" section pointing at the package
   or release artifact.

### Open questions

- **Package name on npm.** `rayjs` is taken. Candidates: `@varhar/rayjs-types`,
  `rayjs-types`, `@rayjs/typings`. Defer until ready to publish.
- **Version pinning vs binary.** The typings must match the binary's exposed
  API. The simplest invariant is "typings package version == rayjs binary
  release tag." Document this explicitly in the package README.
- **Do hand-maintained augmentations belong in the published package?**
  `lib.js_box2d_handbridged.d.ts` documents the JS-facing API of functions
  that exist in the binary, so yes — it ships alongside the auto-generated
  files. The bucket distinction is internal to the rayjs repo.

---

## Priority order and effort estimate

| Step | Description | Effort | Blocks |
|---|---|---|---|
| 1 | `bindings/typings/README.md` (Gap 2, Option A) | 0.5h | nothing |
| 2 | Auto-generated header comments on `lib.js_<name>.d.ts` (Gap 2 polish) | 1h | nothing |
| 3 | `bindings/typings/index.d.ts` generator (Gap 1, Option C) | 1h | step 4 |
| 4 | Distribution channel decision + first release artifact (Gap 1, A or B) | 2-4h | docs update |
| 5 | README "Using rayjs in TypeScript" section | 0.5h | step 4 |

Total: ~5-7 hours of work, split across two small PRs (Gap 2 = steps 1-2,
Gap 1 = steps 3-5).

---

## Out of scope

- Migrating to a fully-typed `rayjs.d.ts` umbrella that re-exports everything via
  `export *`. The current `declare module "rayjs:<name>"` ambient style works fine
  with `typeRoots` and changing it would force consumers to update every import.

- Generating typings from `box2d.h` / `raylib.h` directly at consumer install
  time. The C-header parser lives in the rayjs build chain and is not portable
  enough to ship to consumers.

- Auto-generating the hand-bridged augmentations from `src/box2d_helpers.h`. The
  C bridge functions have JS-facing signatures that diverge from the raw C
  signatures (no `void* context` parameter; callback typedef replaced with a
  proper TS function type). Extracting that automatically is more work than
  maintaining the augmentation file by hand for the seven functions involved.
