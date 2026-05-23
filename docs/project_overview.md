# rayjs Project Overview

rayjs embeds [QuickJS](https://bellard.org/quickjs/) (JS runtime) + [raylib](https://www.raylib.com/)
(graphics) + [raygui](https://github.com/raysan5/raygui) (GUI) into a single small executable.
This repository is a fork of [mode777/rayjs](https://github.com/mode777/rayjs), extended and
modernized by [RealVarHar](https://github.com/RealVarHar/rayjs).

---

## Architecture

| Layer | Component | Role |
|---|---|---|
| JS runtime | `thirdparty/quickjs` (quickjs-ng) | Executes JavaScript |
| Graphics | `thirdparty/raylib` | 2D/3D rendering, input, audio |
| GUI | `thirdparty/raygui` | Immediate-mode UI widgets |
| Allocator | `thirdparty/mimalloc` | Fast memory allocator (optional) |
| Physics | `thirdparty/box2d` | 2D physics engine (Box2D v3) |
| Binding generator | `bindings/src/index.js` | Parses C headers → generates `src/modules/js_*.h` |

---

## Dependency modernization history

This fork has gone through several phases of dependency and API modernization. Understanding
this history helps when reading git history or working on the binding generator.

### Phase 1 — QuickJS engine migration (`feat/quickjs-ng-migration`)
Migrated from the original bellard/quickjs to [quickjs-ng](https://github.com/quickjs-ng/quickjs)
v0.13.0. quickjs-ng is an actively maintained fork with better standards compliance and
performance improvements. This was kept isolated from the raylib upgrade to simplify debugging.

### Phase 2 — raylib 6.0 + raygui 5.0 upgrade (`feat/raylib-6.0`)
Upgraded to raylib 6.0 and raygui 5.0. Key change: the animation API was restructured in
raylib 6.0 — bindings and examples required corresponding fixes. raygui 5.0 introduced
out-param patterns handled via `setOutParam` / `setOutParamFloat` / `setOutParamBool` helpers.

### Phase 3 — Full dep bump + Box2D v3 (`feat/update-deps-varhar`)
Bumped all four submodules to their newest versions and added Box2D v3
as a native `rayjs:box2d` module. See [`docs/branch_feat_update_deps_varhar.md`](branch_feat_update_deps_varhar.md)
for the full change log and technical details.

### Phase 4 — Web (WebAssembly) target (`feat/web-wasm`)
Current active branch. Adds a containerised Emscripten toolchain
(`platforms/web/Dockerfile` + `build.sh`) and a `cmake/web.cmake` that
ships rayjs as `rayjs.wasm` + `rayjs.js` + an HTML shell. The same JS
game sources run unchanged on both native and web — the synchronous
`while (!WindowShouldClose())` main-loop pattern is preserved via
Asyncify. Per-game JS + assets are fetched at page load and populated
into MEMFS by `platforms/web/loader.js`; the runtime itself is
game-agnostic. Verified end-to-end against five example games covering
`rayjs:raylib`, `rayjs:ext:tiled`, `rayjs:box2d`, miniaudio (Web
Audio), and `rayjs:raygui`. See
[`docs/branch_feat_web_wasm.md`](branch_feat_web_wasm.md) for the full
plan and
[`platforms/web/CAVEATS.md`](../platforms/web/CAVEATS.md) for what
doesn't port (lightmapper, workers, standalone-bytecode mode, REPL).

---

## Binding generator

The generator lives in `bindings/src/` and is the core of how C APIs become JS modules.

- **Entry point**: `bindings/src/index.js` — run with `node bindings/src/index.js`
- **Parser**: `bindings/src/source_parser.js` — parses C headers into an AST
- **Code generator**: `bindings/src/raylib-header.js` — walks the AST, emits C wrappers
- **QuickJS helpers**: `bindings/src/quickjs.js` — `cToJs`, `jsToC`, `jsToCallback`, type casting
- **TypeScript typings**: `bindings/src/typescript.js` — emits `.d.ts` declarations

Output goes to:
- `src/modules/js_<name>.h` — C binding for each module
- `bindings/typings/lib.js_<name>.d.ts` — TypeScript declarations
- `src/rayjs_generated.h` — shared class ID registrations

See [`docs/adding_native_module.md`](adding_native_module.md) for a step-by-step guide to
adding a new native module.

---

## Extension module system (`rayjs:ext:*`)

Pure-JS modules in `lib/` are embedded into the binary and importable as `rayjs:ext:<name>`
without any files on disk. See [`docs/ext_modules.md`](ext_modules.md) for details.

---

## Building

```bash
git submodule update --init --recursive
mkdir build && cd build
cmake ..
make          # or: mingw32-make on Windows
```

Regenerate bindings after any header or generator change:
```bash
node bindings/src/index.js
cmake --build build
```
