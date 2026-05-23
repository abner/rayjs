# Branch: `feat/web-wasm` — Emscripten / WebAssembly target

**Goal.** Add a web build target that produces a browser-runnable rayjs runtime
(WebAssembly + JS glue + HTML shell) **without changing how user game scripts
are written**. The same `examples/*.js` source — including its synchronous
`while (!WindowShouldClose()) { ... }` main loop — must run unchanged on both
the native binary and in the browser.

**Branched from.** `feat/update-deps-varhar` (Box2D v3 + quickjs-ng + raylib 6
in flight). If those land on main before this work merges, we rebase.

---

## Core design constraints

1. **JS source is runtime-determined.** The rayjs wasm runtime ships once and
   is game-agnostic; each game's `*.js` + assets are fetched at page load,
   not baked into the binary. This rules out the `--preload-file` build-time
   bundling approach as the *primary* strategy for both dev and release.
2. **Existing examples run unchanged.** The synchronous main-loop pattern
   (`while (!windowShouldClose())`) must keep working on both targets. On
   web this requires **Asyncify**, which is a wasm-link-time feature only
   — it has zero footprint in the native build (see "Asyncify boundary"
   below).
3. **Single CMakeLists.txt** with a one-line conditional include of
   `cmake/web.cmake`. No duplication of the existing dep-configure blocks.
4. **No `#ifdef __EMSCRIPTEN__` sprawl in C source.** Any platform-specific
   code goes in a new `src/platform_web.c` compiled only when targeting wasm;
   `src/rayjs.c` gets at most 2–3 small guards (skip `argv` parsing, skip
   the standalone-bytecode loader, replace the `main()` body).

---

## Final deploy shape

```
dist/web/
├── index.html        ← canvas + module bootstrap (from platforms/web/shell.html)
├── rayjs.js          ← emscripten glue (auto-generated)
├── rayjs.wasm        ← engine: quickjs+raylib+raygui+box2d (+mimalloc off by default)
├── loader.js         ← fetches manifest.json, populates MEMFS in Module.preRun
└── game/             ← served as static assets, referenced by manifest.json
    ├── manifest.json ← list of game files (entrypoint + assets) to fetch
    ├── main.js
    ├── assets/...
    └── maps/*.tmj
```

`rayjs.wasm` + `rayjs.js` + `loader.js` + `index.html` are the **runtime**
— built once, shipped to a CDN. The `game/` tree is swapped per-game; users
edit `manifest.json` and the JS/asset files without rebuilding wasm.

### Loading sequence

1. Browser fetches `index.html` → fetches `rayjs.js` + `loader.js`.
2. `loader.js` registers a `Module.preRun` hook that:
   a. fetches `game/manifest.json`,
   b. for each listed file, fetches it and writes it into MEMFS at the
      same relative path (so `LoadTexture("assets/dino.png")` works
      identically to the native build),
   c. sets `Module.arguments = ["game/main.js"]` (or whatever the manifest
      entrypoint is) so the existing `rayjs.c` arg handling Just Works.
3. Emscripten boots wasm, calls `main`, rayjs reads the entrypoint from
   `argv`, the module loader pulls it from MEMFS, the game runs.
4. The game's synchronous main loop yields via Asyncify on every
   `EndDrawing` / `WaitTime` so the browser stays responsive.

---

## Asyncify boundary

Asyncify is what lets the synchronous main loop pattern keep working on the
web. It is **purely a wasm-link-time concern**:

| Layer                 | What changes for web                                | Native impact |
| --------------------- | --------------------------------------------------- | ------------- |
| User game JS          | nothing                                             | none          |
| `lib/*.js` ext mods   | nothing                                             | none          |
| `src/rayjs*.c`        | nothing for Asyncify (the two guards mentioned in   | none          |
|                       | Phase 2 are for getopt/standalone-mode, unrelated)  |               |
| raylib upstream src   | nothing — raylib already wraps its yield calls      | none          |
|                       | (`emscripten_sleep(0)` in `EndDrawing` / `WaitTime`)|               |
|                       | in `#ifdef __EMSCRIPTEN__`                          |               |
| Box2D / mimalloc / qjs | nothing                                            | none          |
| `cmake/web.cmake`     | adds `-sASYNCIFY -sASYNCIFY_STACK_SIZE=...` to the  | none —        |
|                       | emscripten linker invocation                        | included only |
|                       |                                                    | when `EMSCRIPTEN` |

What this means in practice:

- **Same C source, same JS source** compile/run on both targets. No
  Asyncify-driven `#ifdef`s in any rayjs file.
- The native build doesn't link any "asyncify runtime" — it doesn't exist
  outside emscripten. `build/rayjs` is byte-for-byte unaffected by anything
  in this branch other than the two `#ifndef __EMSCRIPTEN__` guards in
  `rayjs.c` (which only *remove* code paths on web, never add to native).
- Asyncify's cost — ~30–50% wasm binary size, small CPU tax per
  instrumented call, the side-stack memory budget — is paid only by the
  `build-web/` artifact.
- If a future Phase wants to *also* offer a non-Asyncify web build (using
  `emscripten_set_main_loop` instead, for max performance), that becomes a
  CMake option toggled inside `web.cmake`. The native build still doesn't
  notice.

This is why both `dist/web/rayjs.wasm` and the native `build/rayjs` binary
can be produced from the same `git checkout` without any source-level
divergence beyond the two guards already called out in Phase 2.

---

## Renderer & platform details

| Subsystem | Native        | Web                                                   |
| --------- | ------------- | ----------------------------------------------------- |
| Graphics  | OpenGL 3.3    | **WebGL 2** via emscripten GLES3 (`-sUSE_WEBGL2=1`)   |
| Audio     | miniaudio     | miniaudio → Web Audio API (needs user-gesture unlock) |
| Input     | OS events     | emscripten HTML5 events (kbd/mouse/touch/gamepad)     |
| Window    | GLFW          | HTML `<canvas id="canvas">`                           |
| FS        | OS filesystem | MEMFS, populated by `loader.js` in `preRun`           |
| Threads   | pthreads      | single-threaded (avoids COOP/COEP headers)            |

Choosing WebGL 2 over 1: 96%+ browser support, gives float textures and
proper GLES3 path. raylib's upstream web examples default to WebGL 1 but the
PLATFORM_WEB CMake target supports both.

---

## Phase plan

### Phase 0 — scaffolding (no compilation yet) — **COMPLETE (2026-05-23)**

- [x] `cmake/web.cmake` — initially empty stub
- [x] `platforms/web/` directory with `README.md` placeholder
- [x] Bottom of root `CMakeLists.txt`:
      `if(EMSCRIPTEN) include(${CMAKE_SOURCE_DIR}/cmake/web.cmake) endif()`
- [x] `docs/branch_feat_web_wasm.md` (this file) checked in
- [x] Verify native build still configures and builds unchanged
      (verified by configuring a fresh `build_phase0_verify/` — web include
      correctly did not fire; no new warnings or errors)
- [ ] *(deferred to Phase 5)* Add `.claude/CLAUDE.md` reference once a
      working build exists

### Phase 1 — toolchain wiring + dep-by-dep compile — **IN PROGRESS**

The mechanical "does it even compile under emcc" phase. Native build must
continue to work after every step.

- [ ] Document emsdk install in `platforms/web/README.md` (`emsdk install
      latest && emsdk activate latest && source emsdk_env.sh`)
- [ ] In `cmake/web.cmake`: set `RAYJS_USE_MIMALLOC OFF` for web (mimalloc
      compiles to wasm but threading model adds complexity we don't need)
- [ ] Force-disable `MI_BUILD_*` mimalloc subdirectory entirely on web
      (use `EXCLUDE_FROM_ALL` already in place; just don't link against it)
- [ ] **quickjs-ng**: should compile clean; verify the patched `quickjs.c`
      in `build/quickjs-patched/` handles the emcc compile (no
      `<sys/mman.h>` issues etc.). May need `-DEMSCRIPTEN` define passthrough.
- [ ] **raylib**: pass `PLATFORM=Web` and `GRAPHICS=GRAPHICS_API_OPENGL_ES3`
      to the raylib subdir; verify it produces `libraylib.a` for wasm
- [ ] **raygui**: header-only, no action
- [ ] **Box2D v3**: portable C, should be clean; verify
- [ ] **Smoke test**: build a no-op `int main(){return 0;}` linked against
      all five static libs to confirm the link step works

### Phase 2 — rayjs runtime entry point on web

- [ ] Create `src/platform_web.c` with a new `main()` that:
      - skips the `getopt`/`argv` flag-parsing loop (no CLI on web)
      - skips `is_standalone(argv[0])` / `load_standalone_module`
      - reads entrypoint path from `Module.arguments[0]` (already in argv)
      - calls into the existing `rayjs_init_context` / module-loader setup
- [ ] In `src/rayjs.c`, guard the standalone/getopt code with
      `#ifndef __EMSCRIPTEN__` rather than copying the whole file
- [ ] Asyncify linker flags in `cmake/web.cmake` (wasm-only — these
      flags never reach the native toolchain, see "Asyncify boundary"):
      ```
      -sASYNCIFY
      -sASYNCIFY_STACK_SIZE=32768
      -sASYNCIFY_IMPORTS=['emscripten_sleep']
      ```
- [ ] Verify rayjs.wasm + rayjs.js are emitted and load without errors
      (no JS execution yet, just process startup)

### Phase 3 — HTML shell + runtime asset loader

- [ ] `platforms/web/shell.html`:
      - `<canvas id="canvas">`
      - "Click to start" overlay (needed to unlock Web Audio)
      - includes `rayjs.js` (emscripten glue) and `loader.js`
- [ ] `platforms/web/loader.js`:
      - defines `Module.preRun` that fetches `game/manifest.json`,
      - for each entry, `fetch().arrayBuffer()` → `FS.writeFile(path, bytes)`,
      - sets `Module.arguments = [manifest.entrypoint]`
- [ ] `platforms/web/manifest.example.json` showing the schema
- [ ] Install step in `cmake/web.cmake` that copies these three files into
      the output `dist/web/` next to the emcc artifacts

### Phase 4 — first example end-to-end

Pick something small from `examples/` that **does not** use Box2D, tiled, or
audio — probably one of the simplest raylib drawing examples. Verify:

- [ ] Page loads, canvas appears
- [ ] Click-to-start triggers the rayjs entrypoint
- [ ] Asyncify-suspended main loop runs at ~60fps in browser
- [ ] Keyboard / mouse input reaches the JS code
- [ ] Closing the tab cleanly aborts (no console errors)

This is the gate that proves the architecture works.

### Phase 5 — broader example coverage

- [ ] Tiled map example (verifies `.tmj` + tileset PNG flow through MEMFS
      and `lib/tiled.js` works unchanged)
- [ ] Box2D example (verifies the new `rayjs:box2d` module on wasm)
- [ ] Audio example (verifies miniaudio → Web Audio with the click unlock)
- [ ] Document any examples that *can't* port (e.g. anything reading stdin,
      anything spawning a child process) in `platforms/web/README.md`

### Phase 6 — dev workflow + docs

- [ ] `platforms/web/serve.sh` (or `package.json` script) — `python3 -m
      http.server` over `dist/web/` for local testing
- [ ] `npm run web:build` script that runs `emcmake cmake -B build-web` and
      `cmake --build build-web`
- [ ] Iteration loop: edit `game/main.js` → reload page (no rebuild)
- [ ] Update `docs/project_overview.md` with the web target as a fourth
      modernization phase
- [ ] Add `docs/branch_feat_web_wasm.md` reference to `.claude/CLAUDE.md`

---

## Open questions / decisions deferred

- **Asyncify stack size.** Start at 32 KB; bump if we see stack overflows
  on deep raylib call chains. Costs RAM, not binary size.
- **WebGL 2 vs 1.** Going with 2 by default per the table above. Easy to
  flip back if we hit a target browser issue.
- **Audio unlock UX.** Click overlay is the simplest pattern. Could later
  attempt to auto-resume AudioContext on first keypress instead.
- **mimalloc on web.** Keeping OFF for now. If profiling shows the system
  allocator is a bottleneck, revisit — mimalloc has a wasm-supported path
  but pulls in build complexity we don't need yet.
- **Source maps.** Defer until phase 4 works; emcc can emit DWARF debug info
  that Chrome reads natively.
- **Bundle size budget.** TBD; expect ~4–6 MB wasm with Asyncify, gzipped to
  ~1.5–2 MB. Will revisit if it crosses 8 MB raw.

---

## Risks & known-hard bits

1. **Asyncify correctness with raylib's internal loops.** raylib has a
   couple of internal busy-waits (`WaitTime`, vsync sleep). They need to
   route through `emscripten_sleep`. raylib's upstream PLATFORM_WEB already
   does this; verify it survived the v6 bump.
2. **MEMFS lifetime.** Files written in `preRun` persist for the lifetime
   of the page. Refresh = full re-fetch. That's fine, but worth knowing.
3. **CORS on `fetch`.** Local dev with `file://` won't work — must run
   through an HTTP server (covered by phase 6).
4. **Standalone bytecode mode.** `load_standalone_module` (rayjs.c:87)
   appends to the executable. Inapplicable on web — disable cleanly with
   `#ifndef __EMSCRIPTEN__`; don't try to port it.
5. **Box2D + Asyncify.** Box2D's solver is pure compute, no yields. Should
   be transparent, but if a single physics step takes >16 ms the browser
   will jank. Same as native — just more visible.
