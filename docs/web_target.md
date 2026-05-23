# rayjs in the browser

rayjs can be compiled to WebAssembly and run in a browser tab — the
*same* JavaScript game source you'd run with the `./rayjs` native binary
runs unchanged in the browser, including the synchronous
`while (!WindowShouldClose())` main-loop pattern. This document
explains what the web target does, the architectural ideas that made
it possible, and how to build, run, and add games.

For the implementation phase plan and every non-obvious gotcha
discovered during the bring-up, see
[`branch_feat_web_wasm.md`](branch_feat_web_wasm.md). For what does
*not* port, see [`platforms/web/CAVEATS.md`](../platforms/web/CAVEATS.md).

---

## What it does

A working web build produces four static files:

```
dist/
├── index.html      HTML shell + canvas + "Click to start" button
├── loader.js       fetches the game manifest + populates MEMFS
├── rayjs.js        emscripten glue (~250 KB)
└── rayjs.wasm      the engine: quickjs + raylib + raygui + box2d (~5 MB)
```

Plus a per-game payload under `games/<name>/`:

```
games/<name>/
├── manifest.json   { "entrypoint": "...", "files": [...] }
└── ... game.js, assets, tilemaps, fonts ...
```

You serve `dist/` as static files (no server-side logic, no
COOP/COEP headers, no SharedArrayBuffer needed). Visit
`/?game=<name>` in any modern browser, click "Start", and a full rayjs
runtime boots, populates an in-memory filesystem from the manifest,
and runs the game. Five smoke examples ship in `platforms/web/example_games/`:

| URL | Bindings exercised |
|---|---|
| `?game=dino` | `rayjs:raylib`, `rayjs:ext:tiled` (Tiled .tmj + tileset PNG) |
| `?game=platformer` | + `rayjs:box2d` (world step, ray cast, sensors) |
| `?game=audio` | + miniaudio → Web Audio (WAV / OGG decode) |
| `?game=raygui` | + `rayjs:raygui` (single value-box widget) |
| `?game=raygui_full` | + full controls suite + 12 themable styles |

The runtime is **game-agnostic** — the same `rayjs.wasm` artifact
serves every game. To swap games you change the manifest, not the
wasm.

---

## How it was possible

Three architectural ideas carry the design.

### 1. Asyncify — keep the synchronous main loop

raylib games conventionally drive themselves with a synchronous loop:

```js
while (!WindowShouldClose()) {
    BeginDrawing();
    // ...
    EndDrawing();
}
```

This is a non-starter in a browser because the page event loop can
never block — but Emscripten's **Asyncify** instruments the compiled
wasm so that designated functions (here, raylib's `EndDrawing`,
`WaitTime`, etc., which already call `emscripten_sleep(0)` on web)
can yield to JavaScript and resume later. The wasm stack is saved to
a side stack in linear memory at yield points and restored on the next
animation frame. To the JavaScript world it looks fully async; to the
rayjs game it looks fully synchronous.

The cost is paid only by the wasm artifact: ~30–50% larger binary,
single-digit percent CPU per yield, and the side-stack memory budget
(set in `cmake/web.cmake` at 128 KB). The native build doesn't link
any Asyncify runtime — it doesn't exist outside emscripten — so the
toggle is invisible to native.

This is what lets the same example JS file run on both targets
without `#ifdef WEB` everywhere.

### 2. MEMFS-mirrored game payload

rayjs's existing file loaders (`fopen`/`LoadTexture`/`LoadSound` etc.)
expect to read assets relative to the script's directory. On the web
there is no host filesystem, so `platforms/web/loader.js` runs in
`Module.preRun` and:

1. fetches `games/<name>/manifest.json`,
2. fetches each file the manifest lists,
3. writes each one into Emscripten's in-memory filesystem (**MEMFS**)
   at the **same relative path** declared in the manifest.

So when the game later calls `LoadTexture("resources/dino_2x.png")`,
the file is already in MEMFS at `/game/resources/dino_2x.png` (after
rayjs `chdir`s to the entrypoint's directory). No code changes needed
in `lib/tiled.js`, no special asset preprocessing, no per-call URL
fetch. The MEMFS layout intentionally mirrors what the game would see
on disk.

### 3. Single-threaded, single binary

The web build deliberately does *not* use pthreads. That means no
SharedArrayBuffer, no COOP/COEP headers, no cross-origin isolation
gymnastics. Trade-off: heavy compute (Box2D solver, image decode) runs
on the main thread and can jank the frame if you push it too hard. Same
ceiling as the native single-threaded path; just more visible because
the browser keeps the renderer on the same thread.

---

## How to build

The Emscripten toolchain runs inside a Docker container, so the host
machine only needs Docker (or [colima](https://github.com/abiosoft/colima)
on macOS — far lighter than Docker Desktop).

```sh
# one-time on macOS
brew install colima docker
colima start
```

Then, from the repo root:

```sh
platforms/web/build.sh all      # configure + build + assemble dist/
platforms/web/build.sh serve    # http://localhost:8080
```

The first invocation pulls `emscripten/emsdk:3.1.74` (~1 GB,
one-time) and builds a small project image on top. Subsequent builds
are fast (incremental, mounted volume).

Other `build.sh` commands:

| | |
|---|---|
| `configure` | Run cmake configure only |
| `build` | Run cmake build + assemble dist/ |
| `dist` | Re-assemble dist/ from `example_games/` (no wasm rebuild) |
| `serve` | Serve `dist/` on `http://localhost:8080` via `npx http-server -c-1` |
| `clean` | Remove `build-web/` |
| `shell` | Drop into an interactive container shell |

The native build is unchanged and continues to use:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

The two trees are independent — switching targets does not require
cleaning the other.

---

## How to add a new game

1. **Create the directory** under `platforms/web/example_games/<name>/`,
   laid out the way the game expects to see its files at runtime
   (the layout becomes the MEMFS layout):

    ```
    example_games/myname/
    ├── manifest.json
    ├── game/
    │   ├── main.js         your entrypoint
    │   └── assets/...      whatever your code references
    └── (any other dirs your relative imports need)
    ```

2. **Write `manifest.json`**, listing every file by its MEMFS-relative
   path:

    ```json
    {
        "entrypoint": "game/main.js",
        "files": [
            "game/main.js",
            "game/assets/sprite.png"
        ]
    }
    ```

3. **(Optional) Add a picker link** in `platforms/web/shell.html`:

    ```html
    <a href="?game=myname">my game</a>
    ```

4. **Reassemble** — no wasm rebuild needed:

    ```sh
    platforms/web/build.sh dist
    ```

5. **Open** `http://localhost:8080/?game=myname` and click Start.

That's it. Edit `main.js` and reload the page to iterate; the loader
re-fetches the manifest and files on every reload.

### Path-resolution gotcha

If your entrypoint uses `import "../somewhere/x.js"`, lay out the
files so the entrypoint is **at least two directories deep** inside
`game/` (e.g. `game/myscript/main.js` with siblings at `game/shared/`).
The default QuickJS module normalizer strips leading slashes when
resolving `../` from a one-level-deep path, so an entrypoint at
`game/main.js` doing `import "../x"` would fail to find `/x` at
runtime. The `raygui_full` example follows this pattern — see its
`game/controls_test_suite/main.js` + `game/styles/` layout. Full
explanation in [`CAVEATS.md`](../platforms/web/CAVEATS.md).

---

## How it's wired into the build

The web target is a single conditional include at the bottom of the
root `CMakeLists.txt`:

```cmake
if(EMSCRIPTEN)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/web.cmake)
endif()
```

`cmake/web.cmake` exposes two functions (`rayjs_web_pre` /
`rayjs_web_post`) invoked at two points in the root CMakeLists — pre
sets raylib's `PLATFORM=Web` + GLES3 cache options before its
`add_subdirectory`, post applies Asyncify + WebGL 2 + FS-export linker
flags after the target is fully wired. The `EMSCRIPTEN` flag is set
automatically by emcmake's toolchain file and is never seen by
clang/gcc, so the native build is byte-for-byte unaffected.

Four small `#ifdef __EMSCRIPTEN__` / `#ifndef __EMSCRIPTEN__` guards
in `src/rayjs.c`, `src/rayjs_base.c`, and `src/modules/quickjs-libc.c`
disable code paths that can't work on web (REPL fallback,
lightmapper, glad/GLFW desktop includes, signal/environ on
musl-without-GNU-extensions). Everything else is shared source.

For the full layer-by-layer impact analysis, see the "Asyncify
boundary" section of [`branch_feat_web_wasm.md`](branch_feat_web_wasm.md).

---

## Production deploy

`dist/` is a directory of static files. Host it anywhere that serves
files (S3 + CloudFront, GitHub Pages, Netlify, plain nginx). No
server-side logic required. Three things to know:

- **gzip / brotli on `.wasm`**: the wasm compresses to ~1.5–2 MB
  gzipped. Configure your host to serve `.wasm` with
  `Content-Encoding: gzip` (or pre-compress and serve `.wasm.gz`).
- **`Cache-Control`**: the wasm + glue change with every rebuild but
  the file URLs are stable. Cache them aggressively
  (`max-age=31536000, immutable`) and version-bust by appending a
  query string to the `<script src="rayjs.js?v=...">` in `index.html`
  if you cut releases.
- **No special headers required.** Single-threaded build → no
  COOP/COEP → works on any static host.

---

## Where to read more

- [`branch_feat_web_wasm.md`](branch_feat_web_wasm.md) — implementation
  plan with every phase, every non-obvious bug fix, and the rationale
  for each architectural decision.
- [`platforms/web/CAVEATS.md`](../platforms/web/CAVEATS.md) — what
  doesn't port and what behaves differently from native.
- [`platforms/web/README.md`](../platforms/web/README.md) — quick
  reference for the build scripts and Docker workflow.
