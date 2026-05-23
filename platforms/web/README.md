# rayjs — web (WebAssembly) target

This directory holds web-only artifacts: the HTML shell, the asset/JS loader,
and per-game manifest examples. See `docs/branch_feat_web_wasm.md` for the
full plan and rationale.

## Status

**Phase 0 — scaffolding only.** This directory and `cmake/web.cmake` exist
but the build does not yet produce a runnable wasm artifact. Subsequent
phases will populate `shell.html`, `loader.js`, and `manifest.example.json`.

## Prerequisites

The web build runs inside a container so the host never installs emsdk.
Only Docker (or a compatible runtime such as colima) is required:

```sh
# macOS via colima (lightweight; no Docker Desktop needed):
brew install colima docker
colima start

# or Docker Desktop, or Linux's native docker — any will do.
```

The first invocation of `build.sh` pulls `emscripten/emsdk:3.1.74` (~1 GB,
one-time) and builds a small project image on top. Subsequent builds are
fast.

## Building (preview — not functional until Phase 1 lands)

```sh
platforms/web/build.sh              # configure + build (Release)
platforms/web/build.sh configure    # configure only
platforms/web/build.sh clean        # remove build-web/
platforms/web/build.sh shell        # interactive container shell
```

Outputs land in `build-web/` on the host (the repo is bind-mounted into the
container at `/src`, so artifacts persist after the container exits).

The native build is unchanged and continues to use the host toolchain:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

The two build trees are independent — switching targets does not require
cleaning the other.

## Bumping the Emscripten version

Edit the `FROM` tag in `Dockerfile`, then run `platforms/web/build.sh` —
the image rebuilds automatically. Commit the new tag once verified.

## Layout (target)

```
platforms/web/
├── README.md            ← this file
├── shell.html           ← HTML entry point (Phase 3)
├── loader.js            ← preRun fetch → MEMFS writer (Phase 3)
└── manifest.example.json ← schema example for per-game manifests (Phase 3)
```
