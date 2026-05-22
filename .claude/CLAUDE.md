# rayjs — Claude context

## Project context

- [`docs/project_overview.md`](../docs/project_overview.md) — What rayjs is, the fork history,
  architecture overview (QuickJS + raylib + raygui + mimalloc + Box2D), the three phases of
  dependency modernization (quickjs-ng migration → raylib 6.0 → current branch), and how the
  binding generator and ext module system fit together.

- [`docs/branch_feat_update_deps_varhar.md`](../docs/branch_feat_update_deps_varhar.md) — The
  active development branch: all four submodule versions bumped, Box2D v3 integrated as
  `rayjs:box2d`, complete list of changed files, all 6 generator bugs discovered and fixed
  during integration, key JS API facts, and a pointer to the remaining API coverage gaps.

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
