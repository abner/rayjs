# rayjs — Claude context

## Project context

- [`docs/project_overview.md`](../docs/project_overview.md) — What rayjs is, the fork history,
  architecture overview (QuickJS + raylib + raygui + mimalloc + Box2D), the three phases of
  dependency modernization (quickjs-ng migration → raylib 6.0 → current branch), and how the
  binding generator and ext module system fit together.

- [`docs/branch_feat_update_deps_varhar.md`](../docs/branch_feat_update_deps_varhar.md) — The
  previous development branch: all four submodule versions bumped, Box2D v3 integrated as
  `rayjs:box2d`, complete list of changed files, all 6 generator bugs discovered and fixed
  during integration, key JS API facts, and a pointer to the remaining API coverage gaps.

- [`docs/branch_feat_web_wasm.md`](../docs/branch_feat_web_wasm.md) — The current active
  branch (`feat/web-wasm`): adds an Emscripten/WebAssembly build target. Containerised
  toolchain via `platforms/web/Dockerfile` + `build.sh`, one-line conditional
  `include(cmake/web.cmake)` from the root CMakeLists, multi-game runtime payload selected
  by `?game=<name>` URL param. Covers the Asyncify boundary (zero impact on native), the
  per-dep wiring, the source-level guards needed (REPL, lightmapper, glad/GLFW, sighandler/
  environ), the systemic `memoryStore` bindings fix, and per-phase status with every
  smoke test that's been verified in the browser.

- [`platforms/web/CAVEATS.md`](../platforms/web/CAVEATS.md) — What does NOT port to the web
  target (lightmapper, workers, standalone-bytecode mode, REPL), what behaves differently
  (file I/O against MEMFS, module path normalization, audio-context unlock), and the
  Asyncify perf trade-off.

## Planning documents

- [`docs/box2d_api_coverage_plan.md`](../docs/box2d_api_coverage_plan.md) — Plan to increase
  Box2D API coverage: classifies the 27 ignored functions into 8 categories (simple callbacks,
  per-call query callbacks, persistent world callbacks, userData, contact data arrays,
  b2DebugDraw, and internal-only items), with implementation strategy, effort estimate, and
  priority ordering for each. **Categories A–E complete**, F & G pending.

- [`docs/box2d_examples_plan.md`](../docs/box2d_examples_plan.md) — Plan for six standalone
  `examples/box2d/*.js` files that exercise the newly-bound Categories A–E APIs (mouse
  picking, raycast vision, one-way platforms, team-based filtering, material friction,
  kinematic mover). Implementation pending.

## Developer reference

- [`docs/adding_native_module.md`](../docs/adding_native_module.md) — Full walkthrough for
  adding a native C library as a `rayjs:<name>` module: git submodule → CMakeLists.txt →
  binding generator (`bindings/src/index.js`) → runtime registration. Includes all generator
  bugs discovered and fixed during the Box2D v3 integration, common customization patterns,
  and Box2D-specific JS API notes.

- [`docs/ext_modules.md`](../docs/ext_modules.md) — How `lib/*.js` files are embedded into
  the binary as `rayjs:ext:<name>` built-in modules. Covers the cmake generation pipeline
  (`cmake/gen_ext_modules.cmake`), runtime loader wiring in `src/rayjs_base.c` and
  `src/rayjs.c`, TypeScript declaration generation, and how to add a new extension module.

- [`docs/tilemap_system.md`](../docs/tilemap_system.md) — Two-approach reference for
  tile-based rendering with raylib: editor-authored `.tmj` maps via `rayjs:ext:tiled` (main,
  used by `examples/tiled/tiled_map.js`) and procedural generation (appendix, from the
  C++ `platformer-raylib` port). Covers the GID encoding scheme, the full `lib/tiled.js`
  API surface, an annotated walkthrough of the example, and the shared `DrawTextureRec`
  primitive. A styled HTML version with an interactive GID decoder is at
  `docs/tilemap_system.html`.
