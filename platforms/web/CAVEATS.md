# rayjs web target — caveats & non-portable features

The web target reuses 95%+ of the native source unchanged (see
`docs/branch_feat_web_wasm.md` "Asyncify boundary" for the layer-by-layer
impact). A small number of features either don't work on the web target or
behave differently. This file is the canonical list.

## Disabled outright on web

### `rayjs:rlightmapper`
The lightmapper depends on GLAD-loaded desktop OpenGL (`glGenVertexArrays`,
FBO blits, etc.). emscripten provides GLES3 directly via WebGL 2, so GLAD
is not linked. Native builds export `rayjs:rlightmapper`; web builds skip
both the module include in `src/rayjs.c` and its registration in
`src/rayjs_base.c` behind `#ifndef __EMSCRIPTEN__`. Re-enabling for web
would require porting the lightmapper's GL calls to raylib's `rlgl`
abstraction.

### Workers / `os.Worker`
The whole web build is single-threaded (no `-pthread`, no
SharedArrayBuffer, no COOP/COEP). `js_postMessage` (which raylib's
auto-generated trace-log bridges call into) is stubbed as a no-op when
`USE_WORKER` is undefined — see the guard in `src/modules/quickjs-libc.c`.
Importing or using `os.Worker` will not error but will not deliver
messages; trace callbacks that route through workers silently drop their
output.

### Standalone-bytecode mode (`rayjs --compile`)
Native rayjs can append compiled bytecode to its own executable and
self-extract on startup (`is_standalone(argv[0])` in `src/rayjs.c`). On
the web there is no executable file to append to, and the existing
`fopen(argv[0])` returns NULL on emscripten because the URL doesn't
appear in MEMFS. The code path still compiles but is dead.

### QuickJS REPL (`-i` / interactive fallback)
When no entrypoint is supplied, native rayjs falls into QuickJS's
interactive REPL. The browser has no `stdin`; the REPL's readline would
recurse through Asyncify-wrapped reads and blow the JS call stack. The
web build guards the fallback with `#ifdef __EMSCRIPTEN__` and prints a
clear "no entrypoint supplied" message instead. So passing the wasm
without populating `Module.arguments` in `loader.js` is a clean error,
not a hang.

## Different behaviour, not disabled

### File I/O
All `fopen()`/`fread()` operates against MEMFS, not the host filesystem.
The user-facing payload (game JS, assets, tilemaps) is fetched at page
load by `platforms/web/loader.js` from `games/<name>/...` and written into
MEMFS at the path declared in the per-game `manifest.json`. There is no
write-back to disk and no persistence across reloads — every reload
re-fetches.

Local-disk APIs that read paths outside what the manifest declared
(`SaveFileText`, `SaveFileData`, `LoadFileText` on absolute host paths)
work against MEMFS only. Saved data is lost on page close unless the
calling code explicitly downloads it via the browser (not built in).

### Module path resolution
QuickJS's default normalizer (`js_default_module_normalize_name` in
`thirdparty/quickjs/quickjs.c`) strips the leading `/` when resolving
`../x` from a path one level deep. The web loader absolutises
`Module.arguments[0]` so QuickJS's base name has a leading slash, but
imports of the form `import "../something/x.js"` from a script directly
at `/game/main.js` would still drop the slash and miss `/something/`.

Workaround: lay out games so the entrypoint is at least two directories
deep (e.g. `game/<scriptdir>/main.js` and a sibling `game/<sharedstuff>/`).
Then `../sharedstuff/` from `<scriptdir>/main.js` resolves cleanly within
`/game/`. The `raygui_full` example follows this pattern.

### Audio device unlock
Browsers require a user gesture before any `AudioContext` can start. The
shipped `shell.html` has a "Click to start" button that doubles as both
the `Module.callMain()` trigger and the gesture that unlocks Web Audio.
Audio APIs called before the click will silently no-op until the
AudioContext resumes.

### Performance under Asyncify
Every synchronous yield (`emscripten_sleep(0)` inside raylib's
`EndDrawing` / `WaitTime`, plus any imported JS call) is wrapped by
Asyncify's save/restore. Cost: ~30–50% wasm binary size, single-digit
percent CPU overhead per call. The synchronous main-loop pattern
(`while (!WindowShouldClose())`) keeps working without any source
changes. If you want max perf, a future toggle in `cmake/web.cmake`
could switch to a non-Asyncify `emscripten_set_main_loop` build — at the
cost of forcing every example to be rewritten.

## Things that "just work" but might surprise you

- **GLFW desktop key codes** (e.g. `KEY_LEFT_CONTROL`, `KEY_RIGHT_SHIFT`)
  map cleanly through emscripten's HTML5 keyboard layer.
- **Gamepad support** works via the Web Gamepad API on Chromium/Firefox
  — gamepad must be connected after page load, often after a button press.
- **`GetFrameTime()`** is honest (driven by the browser's requestAnimationFrame
  cadence). `SetTargetFPS(60)` is also honoured.
- **Box2D v3** runs at native speed within wasm — the solver is pure compute,
  no JS callbacks per body. Heavy worlds (thousands of bodies) are
  CPU-bound on the main thread.
