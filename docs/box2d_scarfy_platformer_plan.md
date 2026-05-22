# Plan: Boy Platformer — a rayjs:box2d × rayjs:ext:tiled showcase

> The JS file is still called `platformer_scarfy.js` for backwards compatibility
> with earlier doc drafts and CLAUDE.md references. The character was switched
> from Scarfy to the `boy.webp` sprite mid-development; renaming the file is a
> trivial follow-up but deferred so cross-references stay stable.

## Goal

Port a slice of an external C++ raylib + Box2D platformer into a self-contained rayjs
example at `examples/box2d/platformer_scarfy.js`. Three things make this demo distinct
from `examples/box2d/hello_physics.js`:

1. **Tiled-driven world geometry.** The static collision world comes from a `.tmj` map
   loaded via `rayjs:ext:tiled`, not from hand-coded rectangles. Solid tiles become
   Box2D static bodies; object-layer markers become spawn points and pickups.
2. **A real character controller.** The player is a dynamic body with fixed rotation,
   driven by velocity overwrite, with **ground detection via `b2World_CastRay`**
   (textbook v3 approach, now bound — see
   [`box2d_api_coverage_plan.md`](./box2d_api_coverage_plan.md)).
3. **Event-driven gameplay.** Coin pickup uses `b2World_GetSensorEvents`; the existing
   Tiled object-layer "Coin" pickup is the trigger. This exercises the persistent-event
   path that is now also bound.

Assets used by this example:
`examples/box2d/boy.webp` (the 4×4 character spritesheet — source) /
`examples/box2d/boy.png` (PNG copy actually loaded, since raylib's built-in image
loader doesn't bundle WebP) and `examples/platformTilesheet.png` (the tileset used
by `examples/tiled/tiled_map.js` to render the world). Crates are drawn as plain
coloured rectangles rather than tilesheet sprites — see "Implementation findings"
below for why.

The progression of `examples/box2d/` becomes: `hello_physics.js` (minimal — one ball,
one ground) → `platformer_scarfy.js` (this demo — full character + tilemap world +
sensor events + raycast).

---

## What changed since the previous draft of this plan

The earlier draft assumed several Box2D APIs were still ignored and proposed velocity
heuristics as fallbacks. They are now bound, so the plan is tightened:

| Concern in previous draft | Now bound? | Resolution |
|---|---|---|
| Ground detection without callbacks | `b2World_CastRay` ✅ | Use a short downward ray under the feet each frame. |
| Coin pickup without sensor events | `b2World_GetSensorEvents` ✅ | Sensor shape on coin + per-step event read. |
| World geometry hand-coded | Tiled module already had it | Pull static colliders from `getTiledCollisionRects`. |
| Friction/Restitution callbacks | `b2World_SetFrictionCallback`, `b2World_SetRestitutionCallback` ✅ | Not needed for v1, but called out in stretch goals. |

These bindings live in `src/box2d_helpers.h` (the hand-written trampolines) and are
wired up in `src/modules/js_box2d.h`. The example uses them through their standard
JS-facing names with no native-side changes required.

---

## Asset inventory

| Asset | Path | Notes |
|---|---|---|
| Boy spritesheet (source) | `examples/box2d/boy.webp` | 256×256, 4×4 grid of 64×64 frames. Row 0 idle/down, **row 1 walk left**, **row 2 walk right**, row 3 walk up. Only rows 1 and 2 are used. |
| Boy spritesheet (loaded) | `examples/box2d/boy.png` | **512×512** — `boy.webp` decoded then **2x upscaled with nearest-neighbour** so frames are 128×128. raylib's built-in image loader doesn't include WebP, hence the PNG step; the 2x is for pixel-art crispness at the in-game render size. Regenerate with: `sips -s format png boy.webp --out boy_tmp.png && ffmpeg -i boy_tmp.png -vf "scale=iw*2:ih*2:flags=neighbor" -update 1 -frames:v 1 -y boy.png && rm boy_tmp.png`. Nearest-neighbour is intentional — AI upscalers (ESRGAN, waifu2x) tend to blur pixel art by softening its hard edges. |
| Platform tilesheet | `examples/platformTilesheet.png` | 896×448, 12×7 grid of 64×64 tiles. Loaded transitively via the tileset entry in `map.tmj`; this example reuses it for the world background but not for crates. |
| Tiled map | `examples/tiled/resources/map.tmj` | 20×10 tiles, 64 px each → 1280×640 world. `Ground` tile layer is solid; `Objects` layer has a `spawn` and a `pickup` (the coin). Reused **verbatim**. |

The same `map.tmj` is shared between the existing `examples/tiled/tiled_map.js` (which
does manual AABB physics) and this new `examples/box2d/platformer_scarfy.js` (which
does the same scene with Box2D). That contrast is the implicit teaching of the demo:
"here's the same map, simulated with Box2D instead of by hand."

---

## Demo scope

- Window 1280×640 (matches `tiled_map.js` and `map.tmj` dimensions).
- World loaded from `examples/tiled/resources/map.tmj` via `loadTiledMap`. Tiled
  `Ground` tile layer → static Box2D bodies built by merging horizontal runs of
  solid tiles in each row (one wide `b2MakeBox` per run, not one box per tile —
  see "Implementation findings"). `Objects` layer → spawn point + coin pickup.
- Two **invisible static boundary walls** sit just off the left and right edges
  of the map. They're sized so the *sprite* (not just the collider) stays
  fully on screen — the player's collider stops at `SPRITE_DRAW_W / 2` from
  each map edge, where the centred sprite would otherwise begin leaving the
  viewport. Bodies are positioned outside the visible map so they never
  render.
- **Player (boy)** is a dynamic Box2D body with fixed rotation and **zero friction**
  (see "Implementation findings"). Spawns at the `Player` object position. Runs
  the 4-frame walk cycle when horizontally moving, idles on frame 0. **Direction
  comes from the spritesheet row** (row 1 = left, row 2 = right), not from a
  horizontal flip. The sprite is anchored at its bottom-centre to the body's
  collision bottom so visual feet sit on the floor.
- **3–4 dynamic crates** spawn at scripted positions above the floor — visibly
  stackable, tumblable. Drawn as brown `DrawRectanglePro` rectangles, rotated by
  the body's `b2Rot`.
- **1 coin** (the existing `pickup` object in `map.tmj`). Implemented as a static
  body with a sensor-only shape; collected via `b2World_GetSensorEvents`. On pickup,
  coin disappears and a counter increments.
- Horizontal-following camera, vertical lock — same pattern as `tiled_map.js`.
- `R` resets the world; `F1` toggles debug body outlines.

### Controls

| Key | Action |
|---|---|
| ← / A | Move left |
| → / D | Move right |
| Space / ↑ / W | Jump |
| 1 | Switch to **small** player profile (64×64 sprite, 0.25/0.35 half-extents) |
| 2 | Switch to **large** player profile (96×96 sprite, 0.40/0.55 half-extents) |
| R | Reset world (rebuild bodies from the loaded map) |
| F1 | Toggle debug body outlines + HUD |
| Esc | Quit |

---

## Architecture

### Coordinate convention

Tiled is in pixels (64 px tiles) with Y down. Box2D is in metres with Y up. Pick a
single conversion: `PPM = 64` (1 tile = 1 metre), giving a world that is 20 m × 10 m.

```js
const PPM        = 64
const WORLD_W_M  = map.width  * map.tilewidth  / PPM   // 20
const WORLD_H_M  = map.height * map.tileheight / PPM   // 10
const pxToM      = (px) => px / PPM
const mToPx      = (m)  => m * PPM
// Box2D Y is up; Tiled Y is down. Flip on conversion to/from metres.
const worldYFromTileY = (tyPx) => WORLD_H_M - tyPx / PPM
const screenYFromWorldY = (wy)  => (WORLD_H_M - wy) * PPM
```

This keeps the math clean: every solid tile at Tiled `(col, row)` becomes a static
Box2D box at world `((col + 0.5), WORLD_H_M - (row + 0.5))` with half-extents
`(0.5, 0.5)`.

### Building static bodies from the Tiled `Ground` layer

`rayjs:ext:tiled` exposes `getTiledCollisionRects(layerName)` but that helper only
returns rectangles for **objectgroup** layers (`layer.type === "objectgroup"`); the
shared `map.tmj` has its solid geometry in a **tile layer** named `Ground`, so the
helper returns `[]` for it. The right call is `getTiledLayer(map, "Ground")` to get
the layer, then iterate `layer.data[row * width + col]` directly.

Naïvely making one static box per solid tile produces a **tile-seam snag**: the
player's leading-bottom corner catches on the vertical face of the next tile when
crossing a seam (a classic Box2D internal-edge artefact). The fix is to merge
horizontal runs of consecutive solid tiles in each row into a single wide static
box. This is **not just an optimisation** — without it the example is unplayable.

```js
const layer = getTiledLayer(map, "Ground")
const data  = layer.data
const lw    = layer.width
const lh    = layer.height
for (let row = 0; row < lh; row++) {
  let col = 0
  while (col < lw) {
    if (!data[row * lw + col]) { col++; continue }
    const runStart = col
    while (col < lw && data[row * lw + col]) col++
    const runLen = col - runStart
    const def = b2DefaultBodyDef()                  // static by default
    def.position = new b2Vec2(runStart + runLen / 2, WORLD_H_M - (row + 0.5))
    const id = b2CreateBody(worldId, [def])
    b2CreatePolygonShape(id, [b2DefaultShapeDef()], [b2MakeBox(runLen / 2, 0.5)])
  }
}
```

Vertical-run merging would help further when the map has tall solid columns; the
current map's solid region is the bottom three rows, so per-row merging is enough
to make the surface smooth from the player's perspective.

Two extra invisible static walls sit just off the left and right map edges to
keep the *sprite* fully on screen. The walls' inner faces are at
`SPRITE_DRAW_W / 2 - PLAYER_HALF_W` (left) and
`WORLD_W_M - SPRITE_DRAW_W / 2 + PLAYER_HALF_W` (right), which is where the
player's collider must stop so the centred 128 px sprite has both edges still
inside the 1280 px viewport. The wall bodies themselves are placed entirely
outside the visible area, so the viewer never sees them.

### Player (boy) body

- `b2_dynamicBody`, `bodyDef.fixedRotation = true`.
- Position from the `Objects` layer's `spawn` object:
  ```js
  const spawn = getTiledObjects(map, "Objects").find(o => o.type === "spawn")
  bodyDef.position = new b2Vec2(pxToM(spawn.x + 32), worldYFromTileY(spawn.y + 32))
  ```
- Collider: read from the active size profile (see "Size toggle" below). Two
  profiles ship: **small** (`b2MakeBox(0.25, 0.35)` + 64×64 sprite, 1:2
  downscale from the 128 px source) and **large** (`b2MakeBox(0.40, 0.55)` +
  96×96 sprite). Each profile pairs a sprite size with a collider tuned to the
  visible character inside that frame size, not the whole frame. The sprite
  is **anchored at bottom-centre**, with that anchor placed at
  the body's collision bottom (`pos.y - PLAYER_HALF_H` in world space). Centring
  the sprite on the body instead drops its visible feet below the floor line;
  bottom-anchoring keeps the player planted on the visible grass top.
- Shape def: `density = 1.0`, `material.friction = 0.0`, `material.restitution = 0.0`.
  **Friction = 0 is intentional and load-bearing** — see "Implementation findings".
  Per the bug noted in `hello_physics.js`, restitution lives on `shapeDef.material`,
  not directly on the shape def.
- Movement is **velocity-overwrite**, not force-based: each frame, read
  `b2Body_GetLinearVelocity(player)`, replace `vx` with `±PLAYER_SPEED_MPS` (or 0),
  keep `vy`, write back with `b2Body_SetLinearVelocity(player, ...)`. This gives
  responsive, non-slidey platformer feel.
- Jump on press (edge-triggered) sets `vy = JUMP_VEL_MPS` (positive in world frame
  where up is +Y) **only when `grounded` is true**.

### Ground detection via `b2World_CastRay`

Each frame, after `b2World_Step`, cast a short ray straight down from a point just
above the player's feet. The ray starts slightly inside the player to tolerate
solver penetration, then looks for an upward-facing surface below.

```js
const pos = b2Body_GetPosition(player)
const origin = new b2Vec2(pos.x, pos.y - PLAYER_HALF_H + 0.05)
const translation = new b2Vec2(0, -0.18)

let grounded = false
b2World_CastRay(worldId, origin, translation, b2DefaultQueryFilter(),
  (shapeId, point, normal, fraction) => {
    if (normal.y > 0.5) {            // ground-like surface
      grounded = true
      return 0                       // stop here
    }
    return 1                         // skip non-ground (own bottom face, walls,
                                     // ceilings) and keep looking
  })
```

The callback's return value follows Box2D v3's `b2CastResultFcn` contract:
`0` terminates, `1` continues past the hit, a positive `fraction` clips the
ray for closer hits. Returning `1` on non-ground hits is **load-bearing**: the
ray origin sits inside the player's collider, so the player's own bottom face
(normal `(0, -1)`) reports first when the player is in contact with a dynamic
body underneath. A naïve `return 0` would terminate there and never reach the
crate below — see "Implementation findings" §6.

### Size toggle (1 / 2 keys)

The four constants that control "how big is the player" — sprite render width
and height, collider half-width and half-height — are bundled into two
profiles, `SIZES.small` and `SIZES.large`. A module-level `let currentSize`
picks the active one (defaults to `large`). Every reference site reads
`currentSize.spriteW / spriteH / halfW / halfH` instead of a fixed constant:

- player shape creation (`b2MakeBox(currentSize.halfW, currentSize.halfH)`),
- ground-detection ray origin (`pos.y - currentSize.halfH + 0.05`),
- boundary wall positioning (depends on `currentSize.spriteW / 2`),
- sprite draw (destination rect + bottom-centre anchor),
- debug-overlay AABB outline.

Pressing `1` / `2` reassigns `currentSize`, then triggers the same
destroy-world-and-rebuild path that `R`-reset uses. The world rebuild is
necessary because Box2D doesn't expose a "resize this shape" call — the new
collider extents only take effect on a freshly created shape. This is the
simplest implementation that's correct under all gameplay states (in air,
mid-jump, pushing a crate); the alternative — destroy just the player and
re-spawn — would be slightly more efficient but introduces a small race with
in-flight contacts on the destroyed shape.

The source PNG is 128 px per frame regardless of profile; raylib downscales
to 64 or 96 with point filtering (raylib's default for `LoadTexture`), so
both sizes stay crisp. Switching profiles mid-air would put the larger
collider in the same world position, occasionally overlapping geometry — the
rebuild-from-spawn behaviour sidesteps that.

### Crates (dynamic boxes)

- `b2_dynamicBody`, `b2MakeBox(0.45, 0.45)` (0.9 m × 0.9 m).
- `density = 0.6`, `material.friction = 0.5`, `material.restitution = 0.05`.
- Rendered as a brown rectangle via `DrawRectanglePro` with rotation from the
  body's `b2Rot`:
  ```js
  const pos = b2Body_GetPosition(crate)
  const rot = b2Body_GetRotation(crate)          // {c, s}
  const angleDeg = Math.atan2(rot.s, rot.c) * 180 / Math.PI
  const sidePx   = CRATE_HALF * 2 * PPM
  DrawRectanglePro(
    new Rectangle(mToPx(pos.x), screenYFromWorldY(pos.y), sidePx, sidePx),
    new Vector2(sidePx / 2, sidePx / 2),     // origin = centre → rotation pivots correctly
    angleDeg, BROWN,
  )
  ```
- Spawn 4 crates at scripted world positions ((6.5, 4.5), (7.5, 4.5), (11.5, 4.5),
  (15.5, 4.5)) to make a stack the player walks into. A previous draft of this
  plan called for a crate tile from `platformTilesheet.png` instead — see
  "Implementation findings" for why that approach was dropped.

### Coin pickup via `b2World_GetSensorEvents`

The existing `map.tmj` already has a `pickup` object at (320, 192) with type `pickup`.

- Create a static body at that position, attach a single shape with
  `shapeDef.isSensor = true`. Save the shape id in a map: `coinShapeId → coinIndex`.
- Each frame, after `b2World_Step`:
  ```js
  const events = b2World_GetSensorEvents(worldId)
  for (const e of events.beginEvents) {
    // e.sensorShapeId is the coin; e.visitorShapeId is whatever entered it.
    const coinIdx = coinIndexByShape.get(b2StoreShapeId(e.sensorShapeId))
    if (coinIdx !== undefined && coinsCollected[coinIdx] === false) {
      coinsCollected[coinIdx] = true
      coinCounter++
    }
  }
  ```
  *Note*: the exact field names and how a shape id is used as a Map key depend on
  the generated bindings — confirmed during step 1 of implementation. If shape ids
  are objects (not primitives) we encode them to a string key (`${idx}:${gen}`) or
  iterate a small array.

The coin is drawn as a yellow circle at the object's position (no sprite needed for
v1). It disappears when `coinsCollected[i] === true`. A `Coins: N/M` counter sits
in the HUD.

### Sprite animation

`boy.webp` is a 4×4 spritesheet with 64×64 frames. Each direction has its own
row, so direction is encoded in the **source-rect Y**, not via a horizontal
flip:

| Row | Use |
|---|---|
| 0 | Idle / facing camera (down). Unused. |
| 1 | Walking **left** (used when `facingLeft === true`). |
| 2 | Walking **right** (used when `facingLeft === false`). |
| 3 | Walking away (up). Unused. |

- `src = new Rectangle(animFrame * FRAME_W, (facingLeft ? 1 : 2) * FRAME_H, FRAME_W, FRAME_H)`.
- Advance `animFrame` over `0..3` every 1/8 s while `Math.abs(vx) > 0` *and*
  `grounded`; hold frame 0 (and the current row) when idle or airborne.
- No `DrawTexturePro` negative-width flip needed — the row swap is cleaner
  and avoids the "which way does the sprite natively face" question entirely.

### Camera

Same shape as `tiled_map.js`: target follows player X, locked at `map.height / 2`
vertically. Offset is screen centre. Allows side-scrolling within the 1280-wide map
when the player approaches an edge.

### Rendering pipeline (per frame)

```
poll input
b2World_Step(worldId, 1/60, 4)
update grounded via downward CastRay
overwrite player velocity from input + jump state
drain b2World_GetSensorEvents → mark collected coins
advance boy animation from current vx

BeginDrawing()
  ClearBackground(SKYBLUE)
  BeginMode2D(camera)
    drawTiledMap(map, 0, 0, WHITE)              // background tiles
    for each uncollected coin: DrawCircle
    for each crate:            DrawRectanglePro (rotated)
    draw boy with DrawTexturePro (row picked by facingLeft)
    if debug: draw body outlines + cast ray
  EndMode2D()
  HUD: coin count, controls hint, FPS, grounded:T/F
EndDrawing()
```

---

## File layout

```
examples/
├── box2d/
│   ├── hello_physics.js          (existing — minimal)
│   ├── boy.webp                  (player spritesheet — source)
│   ├── boy.png                   (PNG copy — what actually loads)
│   └── platformer_scarfy.js      (this example)
├── platformTilesheet.png         (existing — reused as-is)
└── tiled/
    └── resources/
        └── map.tmj               (existing — shared with tiled_map.js)
```

No CMake, generator, or native-code changes required. All bindings used are already
exposed.

---

## Implementation steps

1. **Binding probe** (5 min): confirm the exact JS-facing names and field shapes for
   `b2World_GetSensorEvents`, `b2World_CastRay`, and how shape ids round-trip
   through `Map` keys (object vs primitive). Inspect generated `js_box2d.h` and any
   helpers in `src/box2d_helpers.h`.
2. **Skeleton** (15 min): copy `hello_physics.js` to `examples/box2d/platformer_scarfy.js`,
   change window size, load tilemap + player + tilesheet textures, run the existing
   draw loop with a placeholder camera.
3. **Static world from tiles** (25 min): iterate `getTiledLayer(map, "Ground").data`
   directly (the `getTiledCollisionRects` helper does not handle tile layers), merge
   horizontal runs of solid cells per row, create one wide static Box2D body per
   run. Verify visually by toggling F1 debug and confirming the merged outlines
   line up with the rendered tile layer and that the player can walk across the
   floor without snagging.
4. **Player body + input** (30 min): build dynamic body at spawn point, wire
   velocity-overwrite movement and jump. Tune `PLAYER_SPEED_MPS` (~6 m/s) and
   `JUMP_VEL_MPS` (~10 m/s). Set `worldDef.gravity = (0, -25)` for tight platformer
   feel (default −10 m/s² is too floaty for sprite-scale worlds).
5. **CastRay ground detection** (20 min): implement the downward-ray approach above.
   Display `grounded:T/F` in HUD for tuning.
6. **Sprite animation** (15 min): port the 6-frame logic, gate on `|vx|`, add
   horizontal flip via negative source-rect width.
7. **Crates** (25 min): spawn 4 dynamic crate bodies at the world positions listed
   above, render each as a brown `DrawRectanglePro` rectangle with per-body
   rotation (`atan2(rot.s, rot.c)`). A previous version of this step picked a
   crate sprite from `platformTilesheet.png` instead, but that requires picking
   the right `(col, row)` by eye and the sheet's tile assignments are ambiguous
   from the image alone — see "Implementation findings".
8. **Sensor coin** (20 min): static body + sensor shape at the `pickup` object's
   position. Drain `b2World_GetSensorEvents` per step, flip `collected[i]`,
   increment counter, hide the coin's draw.
9. **Camera + reset** (15 min): horizontal-follow camera from `tiled_map.js`.
   On `R`, call `b2DestroyWorld` and re-run `setupWorld()` — the player and all
   crates re-spawn at their initial positions, coins reset to uncollected.
10. **Debug overlay + polish** (15 min): F1 toggles outlines + cast-ray drawing +
    HUD detail. Sky-blue background, controls hint text, FPS, header comment
    explaining the demo and pointing at `hello_physics.js` and `tiled_map.js`.
11. **Run + verify** (10 min): execute, confirm the golden path — walk, jump, push
    crates, collect coin, reset — and the edge cases — jump into ceiling, push
    crate into wall, run off edge. Iterate constants until it feels right.

Estimated total: **~3 hours** of focused work.

---

## Implementation findings

Things the running build revealed that the plan didn't predict. Each item is paired
with the concrete fix that landed in `examples/box2d/platformer_scarfy.js`.

### 1. Tile-seam snag → must merge collinear ground tiles

**Symptom**: with one static box per solid tile (the plan's original approach),
Scarfy "froze" at the seam between adjacent floor tiles while walking. Jumping
let him pass the boundary; on the return walk he froze again at the same x.

**Cause**: Box2D's solver treats the seam between two collinear static boxes as
an internal edge. The player's leading-bottom corner clips the next box's
vertical face as it crosses, producing a contact impulse that opposes horizontal
motion. This is the well-known Box2D "internal edge" / "tile seam" artefact and
is not specific to v3.

**Fix**: per-row run-merge in `setupWorld`. For each row of the `Ground` tile
layer, sweep left-to-right, collect each maximal run of consecutive solid cells,
emit one static body covering the whole run (`b2MakeBox(runLen / 2, 0.5)`).
The previous plan listed this as a stretch optimisation; it is in fact required
for correctness with axis-aligned box colliders.

**Where in the code**: see step 1 of `setupWorld()` in `platformer_scarfy.js`.

### 2. Wall-friction stickiness → player friction must be 0

**Symptom**: jumping into a wall (or jumping while pressing toward one) made
Scarfy hover mid-air against the wall as if frozen, even though `grounded: no`.
Releasing horizontal input let him fall normally.

**Cause**: the character controller uses velocity overwrite — every frame, `vx`
is set to `±PLAYER_SPEED` from the input axis. When the player's collider is in
contact with a wall and input is held into it, the velocity overwrite produces a
sustained "push into the wall" each frame. Box2D's solver resolves the normal
component (no penetration), but the tangential (vertical) contact applies
friction proportional to the normal impulse. The longer you hold the input
into the wall, the more friction brakes the jump, which can stop vertical
motion entirely while horizontal input is held.

**Fix**: set the player shape's `material.friction = 0`. With zero friction at
the player↔wall contact (Box2D mixes via `sqrt(f₁·f₂)`, so any zero zeroes
the pair), only the normal impulse resolves the contact and vertical motion is
unaffected by wall hugging. Crates still receive normal impulses when pushed,
so this does not break crate interaction.

**Alternative considered**: detecting wall contact and zeroing the velocity-
overwrite's into-wall component would also fix it, but needs per-body contact
data and is more invasive than a single friction value.

**Where in the code**: `playerShape.material.friction = 0.0` in `setupWorld()`.
Confirmed by play-testing — jumping while moving over the brown crates now
clears them without the mid-air freeze.

### 3. Sprite-foot misalignment → anchor sprite at bottom-centre

**Symptom**: with the sprite centred on the body, Scarfy's visible feet rendered
~5 px below the floor line — character looked half-buried.

**Cause**: the sprite (drawn at 80×80) is taller than twice the collider's
half-height (`2 × 0.55 m × 64 px/m = 70 px`), so centring the sprite on the
body extends it below the body's collision bottom.

**Fix**: anchor `DrawTexturePro`'s origin at `(spriteW/2, spriteH)` (the sprite's
bottom-centre) and pass the screen position of the body's collision bottom
(`mToScreenY(pos.y - PLAYER_HALF_H)`) as the destination point. Sprite bottom
now sits exactly on the visible floor.

**Where in the code**: the Scarfy `DrawTexturePro` call in the draw loop.

### 4. `getTiledCollisionRects` only handles objectgroups, not tile layers

**Symptom**: calling `getTiledCollisionRects(map, "Ground")` returned `[]`, so
the planned init path built zero static bodies.

**Cause**: `lib/tiled.js`'s `getTiledCollisionRects` filters on
`layer.type === "objectgroup"`. The `Ground` layer in `map.tmj` is a
`tilelayer`, which the helper skips.

**Fix**: use `getTiledLayer(map, "Ground")` (which returns the layer
regardless of type) and iterate `layer.data[row * layer.width + col]` directly.

**Alternative considered**: extending `lib/tiled.js` with a
`getTiledTileCollisionRects` helper. Deferred — keeping the change scoped to
the example file matches the plan's "no changes outside `platformer_scarfy.js`"
rule, and the inline iteration also makes the merge logic visible to the
reader of the example.

### 5. Crate tile in `platformTilesheet.png` is ambiguous → drew rectangles instead

**Symptom**: the first attempt picked `(col 9, row 3)` as the crate sprite. At
runtime the "crates" appeared as green gem icons (matched the F1 debug
outlines), which is visually wrong.

**Cause**: the tilesheet's gid → sprite assignment isn't documented and
guessing by eye from the file produced the wrong slot. Verifying the right
tile requires actually opening the PNG, which is friction the demo should
not impose.

**Fix**: draw crates with `DrawRectanglePro` in `BROWN`. Removes the dependency
on a specific tile slot. A comment in the source documents how to swap back to
a tilesheet sprite if a future contributor identifies the correct tile.

### 6. Cast callback must return 1 (not 0) on non-ground hits, or jumps on dynamic bodies break

**Symptom**: jumping from the static floor worked, but standing on top of a
brown crate (a dynamic body), the jump input was silently swallowed —
`grounded` reported `false` while the player was visibly resting on the crate.
Pushing crates sideways was unaffected.

**Cause**: the ground-detection ray starts a hair inside the player's
collider (a small "inside" margin tolerates solver penetration). The ray's
first reported hit can therefore be the player's own bottom face from the
inside, which has surface normal `(0, -1)` — not ground-like. The original
callback always returned `0`, terminating the cast at that first hit and
never reaching the crate's top face just beyond. The static floor masked
this because of the way slight static-vs-dynamic penetration ordering put
the floor hit before the player's own face; on a crate, the ordering can go
the other way.

**Fix**: make the callback ground-aware. Return `0` only when the hit's
normal qualifies as ground (`normal.y > 0.5`); return `1` for non-ground hits
to skip past them and keep looking. The player's own bottom face (normal
`-1`), walls (normal x = ±1, y ≈ 0), and ceilings (normal `(0, 1)` but cast
direction down means a ceiling above the cast would not be hit) all get
correctly skipped. Cast length extended from 0.12 m to 0.18 m to keep
comfortable margin once we don't terminate on the first non-ground.

**Where in the code**: the `b2World_CastRay` callback in the main loop, and
the `CAST_DOWN` constant.

### 7. Stale `.d.ts` for hand-written Box2D helpers (editor noise, not a runtime issue)

**Symptom**: TypeScript-aware editors flag `b2World_CastRay`, `b2World_OverlapAABB`,
`b2World_GetSensorEvents`, etc. as missing exports from `rayjs:box2d`. The
suggestion offered ("Did you mean `b2World_CastMover`?") is unrelated.

**Cause**: the binding generator scans the C headers it can parse and writes
`bindings/typings/lib.js_box2d.d.ts` from that. The hand-written trampolines
and bridges in `src/box2d_helpers.h` are registered with QuickJS via
`JS_CFUNC_DEF` in `src/modules/js_box2d.h` but are invisible to the generator,
so the `.d.ts` lacks them. At runtime these functions resolve correctly.

**Fix in this example**: none — the example runs fine; the diagnostics are
editor-only. The proper fix is to teach the generator about
`box2d_helpers.h` or maintain a supplemental hand-written `.d.ts`, both
out of scope for this example.

---

## Open questions / decisions deferred to implementation

All resolved during implementation; recorded here as a trail of what was uncertain
and how it landed.

- **Sensor event field shape.** Resolved: `b2World_GetSensorEvents` returns a
  `b2SensorEvents` instance with `beginEvents` and `endEvents` array-like properties;
  each event has `sensorShapeId` and `visitorShapeId` of type `b2ShapeId`. Shape ids
  are class instances, so the example uses `b2StoreShapeId(shapeId)` (a BigInt) as
  the `Map` key for coin lookup.
- **`b2DefaultQueryFilter`.** Resolved: exposed from JS, used directly as the
  filter argument to `b2World_CastRay`.
- **Exact crate tile coordinates** in `platformTilesheet.png`. Abandoned — see
  "Implementation findings" §5 (drew brown rectangles instead).
- **Whether to merge adjacent ground tiles into longer static boxes.** Resolved
  the opposite way from the plan's original call: merging is **required**, not
  optional — see "Implementation findings" §1.

---

## Stretch goals (out of scope for v1)

- **Vertical run-merging** of ground tiles (per-column, in addition to the per-row
  merging that already ships). Would matter for maps with tall solid columns; the
  current `map.tmj` has a flat three-row floor where per-row alone suffices.
- **Identify and use a real crate sprite** from `platformTilesheet.png`. Would
  require opening the PNG to read the tile assignments; once known, swap the
  `DrawRectanglePro` for `DrawTexturePro` with the chosen src rect (see the
  comment near the crate-draw block in `platformer_scarfy.js`).
- **Moving platform** — kinematic body with scripted velocity; ~30 LOC.
- **One-way platforms (jump-through)** — uses
  `b2World_SetPreSolveCallback` (now bound) to disable the contact when the player
  is moving upward through the platform. This would showcase the persistent
  callback layer.
- **Custom restitution per material** — `b2World_SetRestitutionCallback` (now
  bound) to make crates extra-bouncy off the player but not off each other.
- **Joints** — a swing/chain of crates via `b2CreateRevoluteJoint`. Pure visual
  payoff, demonstrates joint creation.

The first three of these now have **all required bindings in place** thanks to the
recent work — they are realistic follow-up examples rather than blocked items.

---

## Success criteria

- Runs from a clean checkout via the standard rayjs run command. The player walks,
  jumps, pushes crates, collects the coin, and `R` cleanly resets — no crashes
  across a one-minute play session.
- Stays under ~300 lines including comments. Reader-orientation comments mark the
  five "interesting" sections: tilemap → static bodies, player setup, CastRay
  ground check, sensor coin loop, camera/render.
- A reader who knows raylib and Tiled but not Box2D can identify exactly where the
  world is constructed from the tile layer, where the player body is stepped, and
  how the sensor event drives the coin pickup. The shared `map.tmj` invites
  side-by-side reading against `examples/tiled/tiled_map.js` to contrast manual-
  AABB physics with Box2D physics on the same scene.
- No changes outside `examples/box2d/platformer_scarfy.js`. If implementation
  uncovers a binding shape that doesn't match the assumptions above, the example
  adapts to what's actually bound — we don't expand scope to native side.
