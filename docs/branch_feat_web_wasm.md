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

### Phase 1 — toolchain wiring + dep-by-dep compile — **COMPLETE (2026-05-23)**

The mechanical "does it even compile under emcc" phase. Native build must
continue to work after every step.

**Toolchain decision (2026-05-23):** the emsdk toolchain runs inside a
container (`platforms/web/Dockerfile` based on `emscripten/emsdk:3.1.74`
+ pip-installed cmake 3.30.5 for raylib 6's >=3.25 requirement), driven by
`platforms/web/build.sh`. The host machine only needs Docker (or colima).
Rationale: keeps the host clean, makes builds reproducible across machines,
and pins the emcc/cmake versions per-commit.

**Final artifact:** `build-web/dist/rayjs.{html,js,wasm}` — 19 KB shell +
243 KB glue + 5.1 MB wasm (uncompressed; ~1.5–2 MB gzipped expected).

- [x] Containerised emsdk: `platforms/web/Dockerfile` + `build.sh` wrapper
- [x] Document Docker workflow in `platforms/web/README.md`
- [x] `cmake/web.cmake` with `rayjs_web_pre()` / `rayjs_web_post()` split
      (early hook sets raylib/Box2D/mimalloc cache options; late hook
      applies Asyncify + WebGL 2 + FS-export linker flags and redirects
      output to `build-web/dist/`)
- [x] Per-dep wiring in root `CMakeLists.txt` — four `EMSCRIPTEN`-guarded
      branches: OpenGL define for raylib subdir, OpenGL define for rayjs
      target, mimalloc subdir add, mimalloc-static link
- [x] Source-level fixes for emscripten:
      - `src/modules/quickjs-libc.c` — add `__EMSCRIPTEN__` block declaring
        `sighandler_t` typedef + `extern char **environ` (mirrors Solaris
        pattern); guard `js_postMessage` on `USE_WORKER` and add a no-op
        stub for thread-less builds
      - `src/rayjs_base.c` — guard `#include <mimalloc.h>` behind
        `RAYJS_NO_MIMALLOC` and alias `mi_*` to standard libc when set
      - `src/rayjs.c` — add `<wchar.h>` for `wint_t` in raylib bindings;
        guard `<external/glad.h>` + `<GLFW/glfw3.h>` +
        `modules/js_rlightmapper.h` includes behind `!__EMSCRIPTEN__`
      - `src/rayjs_base.c` — guard `js_init_module_rlightmapper` call
        behind `!__EMSCRIPTEN__`
- [x] Drive-by fix in root `CMakeLists.txt`: strip literal quotes from
      `-D...="..."` args in the `gen_ext_modules.cmake` `execute_process` /
      `add_custom_command` invocations (those quotes leaked into the value
      under emcmake/Linux and created a spurious `"/src/src/js_ext_modules.h"`
      path; harmless but ugly — also a latent native bug)
- [x] Smoke link verified: `rayjs.wasm` emitted, recognised by `file` as
      a WebAssembly binary module; native build re-verified end-to-end
      (configure on a fresh `/tmp/rayjs-native-check` succeeds with no
      new warnings)

**Lightmapper status.** The `rayjs:rlightmapper` module is disabled on the
web target. It depends on desktop OpenGL (GLAD-loaded function pointers
into `glGen*` / FBO / VAO) which isn't available through emscripten's GLES3
path. Re-enabling for web would require porting the lightmapper to use
raylib's `rlgl` abstraction (which compiles to GLES3) — out of scope for
Phase 1 but a clean follow-up.
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

### Phase 2 — rayjs runtime entry point on web — **ABSORBED INTO PHASES 1 & 3**

The originally planned `src/platform_web.c` turned out to be unnecessary:
the existing `src/rayjs.c` `main()` compiles cleanly under emcc and the
standalone-bytecode `fopen(argv[0])` silently no-ops on web (no such
file in MEMFS). Only one targeted guard ended up needed:

- [x] `src/rayjs.c` — `#ifdef __EMSCRIPTEN__` guard around the
      `interactive` REPL fallback (without stdin, the QuickJS REPL
      recurses through Asyncify-wrapped readline and blows the JS call
      stack). Replaced with a clear "no entrypoint supplied" message.
- [x] Asyncify + supporting linker flags live in `cmake/web.cmake`
      (`-sASYNCIFY`, `-sASYNCIFY_STACK_SIZE=131072`,
      `-sSTACK_SIZE=4194304` for the wasm linear-memory stack — see
      Phase 3 notes for why the latter is critical).
- [x] rayjs.wasm + rayjs.js emit and boot under the loader without
      errors.

### Phase 3 — HTML shell + runtime asset loader — **COMPLETE (2026-05-23)**

- [x] `platforms/web/shell.html`: `<canvas>`, "Click to start" button,
      includes `loader.js` then `rayjs.js`
- [x] `platforms/web/loader.js`: defines `window.Module` with
      `noInitialRun: true`, a `preRun` hook that fetches
      `game/manifest.json`, then each listed asset, writes them into
      MEMFS at the same relative path, and sets
      `Module.arguments = [manifest.entrypoint]`. Click handler calls
      `Module.callMain(...)` once the runtime is ready.
- [x] `platforms/web/manifest.example.json` documenting the schema
- [x] Bundled into `dist/` by `build.sh`'s `cmd_dist` (not via cmake
      install — keeps cmake focused on the wasm artifact). The
      `example_game/` directory mirrors the MEMFS layout it produces,
      so it's copied verbatim with `cp -R`.

**Several non-obvious things that came up:**

- emcc's default 64 KB wasm linear-memory stack was nowhere near enough
  for the QuickJS interpreter (C-stack-recursive). QuickJS's own
  overflow check fired and threw `RangeError: Maximum call stack size
  exceeded` deep inside raylib init. Bumped via `-sSTACK_SIZE=4194304`
  (4 MB).
- raylib's `src/CMakeLists.txt:71` adds
  `-sEXPORTED_RUNTIME_METHODS=ccall` as a **PUBLIC** link option, which
  propagates to consumers AFTER their own link options (emcc keeps the
  last value). Without intervention this stripped `callMain` and
  `FS`/`cwrap` from the runtime exports. `rayjs_web_post()` now strips
  raylib's narrower flag from its `INTERFACE_LINK_OPTIONS` before
  adding our full list.
- `Module.callMain` must be in `EXPORTED_RUNTIME_METHODS` (the default
  doesn't expose it). Required because we set `noInitialRun: true` and
  invoke main from the click handler.
- emcc's `-z stack-size` was a long-standing source of confusion vs
  `ASYNCIFY_STACK_SIZE`. They're two completely separate stacks:
  - `STACK_SIZE`: the wasm linear-memory C stack. Local variables,
    spilled registers, return addresses for non-async paths.
  - `ASYNCIFY_STACK_SIZE`: a side stack in linear memory used only to
    save/restore wasm state across suspend points.
- Path resolution discipline: rayjs's `chdir(dirname(argv[1]))` (in
  `src/rayjs.c:650`) makes CWD = `dirname(entrypoint)` before the JS
  runs. So if the entrypoint is `game/main.js`, CWD becomes `/game/`,
  and the example's hard-coded `../../../examples/platformTilesheet.png`
  inside the .tmj resolves to `/examples/platformTilesheet.png` —
  which is why `example_game/examples/platformTilesheet.png` lives
  outside of `example_game/game/`. Same physical layout works on web
  and would work on native if you cd'd into a comparable scratch dir.
- Source-level guard added in `src/rayjs.c`: when no entrypoint is
  supplied and `interactive` mode would otherwise kick in, on
  `__EMSCRIPTEN__` we print a clear error and exit instead of dropping
  into the QuickJS REPL — which would recurse on the Asyncify-wrapped
  readline and blow the JS call stack.

**Smoke tests — both end-to-end in the browser:**

- `examples/tiled/dino_on_blocks.js` (selectable via `?game=dino`,
  default). Exercises `rayjs:raylib` + `rayjs:ext:tiled`: window opens,
  tilemap renders, animated dino tile, keyboard input
  (←→/WASD, ↑/space, ↓/S, T scale toggle).
- `examples/box2d/platformer_scarfy.js` (selectable via
  `?game=platformer`). Exercises `rayjs:raylib` + `rayjs:ext:tiled` +
  **`rayjs:box2d`**: full Box2D world step every frame, sensor events,
  ray casting (`b2World_CastRay`), polygon/circle shapes, dynamic
  bodies with gravity, sprite animation tied to body velocity. Confirms
  the Box2D v3 wasm path works at runtime, not just at link time.

This closes both the tiled and Box2D items that were originally
scheduled for the "broader example coverage" phase — they fell out
naturally from the smoke tests.

### Multi-game layout (added during Phase 3)

`platforms/web/example_games/` holds one subdirectory per shipped game.
Each game's subdirectory mirrors the MEMFS layout it expects:

```
example_games/
├── dino/
│   ├── manifest.json
│   ├── game/main.js                          ← entrypoint
│   ├── game/resources/...                    ← .tmj + sprite PNGs
│   └── examples/platformTilesheet.png        ← shared tileset, here
│                                               because the .tmj's image
│                                               path resolves to
│                                               /examples/platformTilesheet.png
└── platformer/
    ├── manifest.json
    ├── game/main.js                          ← entrypoint
    ├── game/boy.png, game/boy_scaled_2x.png  ← sprite sheets
    ├── tiled/resources/map.tmj               ← matches the
    │                                           "../tiled/resources/map.tmj"
    │                                           path inside main.js
    └── examples/platformTilesheet.png        ← same tileset shared
```

The whole tree is copied verbatim to `dist/games/<name>/` by
`build.sh`'s `cmd_dist`. **Game selection** is a URL query parameter
parsed by `loader.js`:

- `http://localhost:8080/`              → defaults to `?game=dino`
- `http://localhost:8080/?game=dino`        → loads dino
- `http://localhost:8080/?game=platformer`  → loads platformer

The loader fetches `games/<name>/manifest.json`, then each file listed
under `files`, **prepending `games/<name>/` to the fetch path** but
writing each blob into MEMFS at the unprefixed path. So `manifest.json`
entries stay portable across games: the same `"game/main.js"` value in
two different manifests fetches from two different places on the server
but lands at the same `/game/main.js` in the runtime's MEMFS. The
running game source is completely unaware of which subdirectory it
came from.

`shell.html` includes a small selector strip that highlights the active
choice and lets the user switch between games — clicking just navigates
to `?game=<name>`, which triggers a normal full reload (the rayjs.wasm
caches, but MEMFS reinitialises from the new game's manifest).

**Adding a new game:**

1. Create `platforms/web/example_games/<name>/`
2. Lay out its files in the structure the game expects at runtime
   (entrypoint at `game/main.js`, etc.)
3. Write `manifest.json` with `entrypoint` + `files` listing every path
4. (Optional) add an `<a href="?game=<name>">` link to `shell.html`
5. `bash platforms/web/build.sh dist` — no wasm rebuild needed

### Phase 4 — first example end-to-end — **COMPLETE (2026-05-23)**

Gate criteria from the original plan, all met by the dino smoke during
Phase 3:

- [x] Page loads, canvas appears
- [x] Click-to-start triggers the rayjs entrypoint
- [x] Asyncify-suspended synchronous main loop runs at ~60fps in browser
- [x] Keyboard input reaches the JS code (←→/WASD, ↑/space, ↓/S, T)
- [x] Closing the tab cleanly aborts (no console errors)

### Phase 5 — broader example coverage

- [x] **Tiled map example** — `examples/tiled/dino_on_blocks.js` runs
      end-to-end (2026-05-23). Confirms `.tmj` + tileset PNG flow
      through MEMFS and `lib/tiled.js` works unchanged.
- [x] **Box2D example** — `examples/box2d/platformer_scarfy.js` runs
      end-to-end (2026-05-23). Confirms the new `rayjs:box2d` module
      works at runtime on wasm (world step, sensor events, ray casting,
      dynamic bodies).
- [x] **Audio example** — `examples/audio/audio_sound_loading.js` runs
      end-to-end (2026-05-23). SPACE plays a WAV, ENTER plays an OGG,
      both with no errors. Confirms miniaudio → Web Audio backend and
      that the existing click-to-start button is enough to satisfy the
      browser's autoplay-unlock requirement. Format support is identical
      to native raylib (WAV/OGG/MP3/FLAC/QOA + XM/MOD music) — emcc
      just provides the output path; raylib still decodes the bytes
      itself.
- [ ] Raygui example (verifies immediate-mode UI input routing through
      emscripten HTML5 events)
- [ ] Document any examples that *can't* port (e.g. anything reading
      stdin, anything spawning a child process) in
      `platforms/web/README.md`

### Phase 6 — dev workflow + docs

- [x] `platforms/web/build.sh serve` wraps `npx http-server -p 8080
      -c-1 dist/`. No COOP/COEP needed (single-threaded wasm). The
      `-c-1` disables http-server's default 1-hour cache so rebuilds
      reload cleanly.
- [x] `platforms/web/build.sh all` does configure + build + dist in
      one invocation (no separate npm scripts needed — `build.sh` is
      the single entry point).
- [x] Iteration loop: edit a file in `platforms/web/example_games/<name>/`
      → `build.sh dist` (no wasm rebuild) → reload page.
- [ ] Update `docs/project_overview.md` with the web target as a
      fourth modernization phase.
- [ ] Add `docs/branch_feat_web_wasm.md` reference to
      `.claude/CLAUDE.md` once Phase 5 wraps.

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
