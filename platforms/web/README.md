# rayjs — web (WebAssembly) target

This directory holds web-only artifacts: the HTML shell, the asset/JS loader,
and per-game manifest examples. See `docs/branch_feat_web_wasm.md` for the
full plan and rationale.

## Status

**Phase 0 — scaffolding only.** This directory and `cmake/web.cmake` exist
but the build does not yet produce a runnable wasm artifact. Subsequent
phases will populate `shell.html`, `loader.js`, and `manifest.example.json`.

## Prerequisites

The web target requires the Emscripten SDK. Install once:

```sh
# anywhere outside this repo
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
```

Activate the SDK in every new shell before configuring/building:

```sh
source /path/to/emsdk/emsdk_env.sh
```

`emcc --version` should now resolve.

## Building (preview — not functional until Phase 1)

```sh
emcmake cmake -S . -B build-web -DCMAKE_BUILD_TYPE=Release
cmake --build build-web
```

The native build is unchanged and continues to use:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

The two build trees are independent — switching targets does not require
cleaning the other.

## Layout (target)

```
platforms/web/
├── README.md            ← this file
├── shell.html           ← HTML entry point (Phase 3)
├── loader.js            ← preRun fetch → MEMFS writer (Phase 3)
└── manifest.example.json ← schema example for per-game manifests (Phase 3)
```
