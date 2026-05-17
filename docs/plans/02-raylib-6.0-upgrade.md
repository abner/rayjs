# Phase 2 — Upgrade to raylib 6.0

## Goal

Move the `raylib` and `raygui` submodules from their current floating
`main` branch to the **raylib 6.0** release (April 2026) and the matching
raygui release, regenerate the bindings, and fix every consumer of the
changed APIs.

## Prerequisites

- **Phase 1 (quickjs-ng migration) is merged to `main`.** Doing both
  migrations together makes it impossible to bisect breakage.
- Read the [raylib 6.0
  CHANGELOG](https://github.com/raysan5/raylib/blob/master/CHANGELOG)
  end-to-end, focusing on lines marked `WARNING`. Each of those is a
  potential binding break.

## Why this is a big release

raylib 6.0 is described by its maintainer as "the biggest raylib release
ever." Areas touching `rayjs` bindings:

- **Skeletal Animation System** — redesigned. New `ModelSkeleton` struct,
  `Model` and `ModelAnimation` layouts changed. Even if the rayjs README
  says "no animation support", we still expose `Model` and load `.glb`
  files, so struct layout matters.
- **File System API** — reorganized into `rcore`. The `utils` module is
  gone. New functions: `FileRename`, `FileRemove`, `FileCopy`, `FileMove`,
  `FileTextReplace`.
- **Build Config System** — `config.h` redesigned; `-DSUPPORT_*=0/1`
  command-line overrides now work.
- **Fullscreen + high-DPI** — redesigned.
- **Text Management API** — redesigned.
- **Platform backends** — new Win32, Emscripten, memory, software renderer
  (rlsw). We don't have to use them, but the rcore module layout changed.
- **`raylib_parser` renamed to `tools/rlparser`** — affects
  `generate-bindings.js` if it shells out.

## Target versions

| Component       | From                    | To                                |
| --------------- | ----------------------- | --------------------------------- |
| `raylib`        | `main` (floating)       | `6.0` (tag, April 2026)           |
| `raygui`        | `main` (floating)       | matching raygui release (5.0-dev tracked) |
| `lightmapper`   | floating                | pin to current SHA for reproducibility |

> raygui 5.0 was tracked by raylib 6.0 examples as `5.0-dev`. Check raygui
> releases for a stable tag; if none is matched to raylib 6.0, pin to the
> commit SHA used by `raylib 6.0`'s `examples/Makefile` or `examples/_external`.

## Branch

```bash
git checkout main
git pull
git checkout -b feat/raylib-6.0
```

## Step-by-step

### 1. Pin the submodules

```bash
# raylib
cd thirdparty/raylib
git fetch --tags
git checkout 6.0
cd ../..

# raygui — find the right tag/SHA first
cd thirdparty/raygui
git fetch --tags
# inspect available tags vs. raylib's examples/Makefile expectation
git tag --list
# git checkout <chosen tag or SHA>
cd ../..

# lightmapper — pin to current SHA
cd thirdparty/lightmapper
git rev-parse HEAD          # record this
cd ../..

git add .gitmodules thirdparty/raylib thirdparty/raygui thirdparty/lightmapper
```

Edit `.gitmodules` to **remove the `branch = main` lines** on `raylib` and
`raygui`. We want pinned commits, not floating branches.

### 2. Update the bindings generator

The generator (`generate-bindings.js` + `bindings/src/index.ts`) consumes
raylib's machine-readable API JSON. Two things to check:

1. **Path to the parser tool.** raylib 6.0 renamed `raylib_parser` to
   `tools/rlparser`. If `generate-bindings.js` shells out to the parser
   binary or includes its source, update the path.
2. **Path to the API JSON output.** raylib ships pre-generated parser
   output in `parser/output/raylib_api.json` (or similar) at the repo
   root. Confirm the path the generator reads still exists.

### 3. Regenerate bindings

```bash
# Run whatever the project uses — likely:
node generate-bindings.js
```

Expect the diff to be **large**. Don't panic. The generator is
deterministic, so the diff reflects raylib's API surface changes.

Commit the regenerated output as a single commit titled
`Regenerate bindings for raylib 6.0` so reviewers can see "this is
mechanical" separate from "this is a hand fix".

### 4. Walk the `WARNING:` list

For each `WARNING` line in raylib's CHANGELOG, decide:

- **Auto-fixed by regeneration** (e.g. function renamed but binding is
  pure-generated): nothing to do.
- **Needs manual fix in `bindings/src/index.ts`**: e.g. a function was
  removed and we had a custom override or `ignore` for it.
- **Needs manual fix in `src/*.c`** (the hand-written helpers): e.g.
  `meshCopy`, `meshMerge`, `imageReadPixel`, `setModelMaterial`,
  `getModelMaterial`, `getModelMesh`, `setShaderLocation`. These touch
  raylib structs directly and will break if struct layouts changed.

### 5. Hot-spot list (where breakage is most likely)

Based on the 6.0 CHANGELOG, prioritize these:

#### `src/` C helpers — struct-layout sensitive

- `Mesh` — verify field offsets used by `meshCopy`, `meshMerge`, and the
  ArrayBuffer-backed mesh creation path in `js_mesh_generation.js`.
- `Model` / `ModelAnimation` / new `ModelSkeleton` — skeletal animation
  redesign. If we exposed any of these structs, layout changed.
- `Image` — verify `imageReadPixel` still indexes correctly.
- `Material` — verify `setModelMaterial`/`getModelMaterial`.
- `Shader` — verify `setShaderLocation`. Shader locations array layout
  is likely unchanged but worth a smoke test.

#### `bindings/src/index.ts` ignore list

Walk every `ignore(...)` entry and check whether the function still
exists. If not, drop the ignore. If it was renamed, add the new name to
the ignore list (or bind it).

#### File system API

The rayjs README doesn't claim to expose much of this, but if there's a
`LoadDirectoryFiles` / `UnloadDirectoryFiles` / `LoadDroppedFiles`
binding, double-check it still compiles — these were renamed in earlier
releases and may have been touched again.

#### `lightmapper.h` integration

The lightmapper library directly touches `Mesh` fields. If `Mesh`
internals changed (vertex buffer pointers, animation vertex storage), the
lightmapper glue in `src/` will need a patch.

### 6. raygui

raygui is single-file header-only. Update mainly means re-pulling the
submodule. If raygui has its own breaking API changes:

- Style API (`GuiSetStyle`, `GuiGetStyle`) — stable since 4.0.
- Control function signatures — unified in 4.0, no further changes expected.
- New controls (if any added in 5.0) — optional to bind.

Check `bindings/src/index.ts` for any raygui-specific overrides.

### 7. TypeScript definitions

Regenerate `lib.raylib.d.ts` so autocomplete matches the new API.

If users have existing `.ts` projects against the old definitions, their
code may need updates — call this out clearly in the release notes.

### 8. Build

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j 2>&1 | tee build.log
```

Iterate on `src/` until clean. Compile warnings are signal — read them.

### 9. Run **every** example

```bash
./rayjs main.js
./rayjs examples/js_example_project
./rayjs examples/js_mesh_generation.js
./rayjs examples/shaders/js_shaders_gradient_lighting.js
./rayjs examples/ts_dungeon
./rayjs examples/ts_game
./rayjs examples/js_lightmapper.js
# ...plus anything else under examples/
```

For each, note: starts cleanly, renders correctly, exits cleanly. The
lightmapper example is the highest-risk because it depends on Mesh
internals.

### 10. Examples that need source updates

If raylib 6.0 renamed functions and our examples used them directly (not
via auto-completion), they'll fail at JS runtime, not at compile time.
Watch for runtime "function is not defined" errors and fix the example.

### 11. README + docs

Now is the time:

- Bump the supported raylib version mention.
- Drop the MinGW caveat (done in Phase 1, but verify).
- Fix clone URL: `mode777/rayjs` → `abner/rayjs`.
- If we removed any API surface that the README advertises (e.g. the
  helper list in "Additional APIs"), update accordingly.

## Done criteria

- [ ] `thirdparty/raylib` pinned to tag `6.0` (no `branch = main`)
- [ ] `thirdparty/raygui` pinned to a tag or SHA matching raylib 6.0
- [ ] `thirdparty/lightmapper` pinned to a SHA
- [ ] Bindings regenerated and committed
- [ ] All `src/` helpers compile cleanly and pass their example smoke tests
- [ ] `lib.raylib.d.ts` regenerated
- [ ] Every example in `examples/` runs and exits cleanly
- [ ] `lightmapper` example produces visually correct output
- [ ] CI green on Linux, macOS, Windows
- [ ] README updated

## Risk register

| Risk | Likelihood | Mitigation |
| ---- | ---------- | ---------- |
| Mesh struct layout changed → lightmapper broken | High | Patch `src/` lightmapper glue, may need short upstream PR |
| Bindings generator output explodes (1000s of diff lines) | High | Commit as separate "mechanical regen" commit so review is tractable |
| raygui API drift breaks raygui examples | Medium | Pin raygui to a known-compatible SHA; rebind any changed controls |
| Some raylib 6.0 function rename we missed | Medium | Run every example; JS runtime errors will surface these |
| Windows MSVC build breaks because of raylib platform backend changes | Medium | Test CI early; raylib 6.0 supports MSVC well |
| Removed API still referenced in JS examples | Low | Grep examples for now-removed function names; fix or document |

## Rollback

```bash
git checkout main
git branch -D feat/raylib-6.0
```

Phase 1 (quickjs-ng) stays in main. Re-attempt later with a smaller bite
(e.g. raylib 6.0 → start with parsing the new API JSON and getting it to
*compile* before worrying about all examples running).

## Notes / scratchpad

_(Use this section while you work)_
