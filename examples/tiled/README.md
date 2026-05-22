# Tiled map example

`tiled_map.js` loads a `.tmj` map authored in the [Tiled](https://www.mapeditor.org/) editor
via the `rayjs:ext:tiled` module, then drives a small platformer player (move, jump, AABB
collision against a named layer).

### Run

```
./build/rayjs examples/tiled/tiled_map.js
```

### Documentation

The dedicated reference for tile-based rendering with raylib lives at
[`docs/tilemap_system.md`](../../docs/tilemap_system.md) (and a styled, browsable
[`docs/tilemap_system.html`](../../docs/tilemap_system.html) with an interactive GID decoder).

Most relevant sections for this example:

- **§5 — The .tmj File Format** — fully annotated walkthrough of [`resources/map.tmj`](resources/map.tmj),
  the GID encoding scheme, and Tiled layer types.
- **§6 — The rayjs:ext:tiled API** — what every function in the module does, with
  `lib/tiled.js` line references.
- **§7 — Walkthrough** — annotated read of this file (`tiled_map.js`), line by line.

The companion procedural approach (used by the sibling C++ `platformer-raylib` project) is
documented in the same file as **Appendix A–F**.

### See also

- [`docs/ext_modules.md`](../../docs/ext_modules.md) — how `rayjs:ext:tiled` is embedded into the binary.
- [`lib/tiled.d.ts`](../../lib/tiled.d.ts) — TypeScript API surface for the module.
- [`lib/tiled.js`](../../lib/tiled.js) — the implementation.
