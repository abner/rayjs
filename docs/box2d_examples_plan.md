# Plan: Box2D + raylib examples for the new API surface

`examples/box2d/` currently has one file (`hello_physics.js`) that demonstrates the basic
world/body/step/draw loop. With Categories A–E of [`box2d_api_coverage_plan.md`](./box2d_api_coverage_plan.md)
complete, the following APIs are now exposed but have no example coverage:

| API | Category |
|---|---|
| `b2World_SetFrictionCallback`, `b2World_SetRestitutionCallback` | A |
| `b2World_OverlapAABB`, `b2World_OverlapShape`, `b2World_CastRay`, `b2World_CastShape`, `b2World_CollideMover` | B |
| `b2World_SetCustomFilterCallback`, `b2World_SetPreSolveCallback` | C |
| `b2World_CastMover` | D (no callback) |
| `b2World_SetUserData`, `b2Body_SetUserData`, `b2Shape_SetUserData`, `b2Joint_SetUserData` (+ `_Get`/`_Delete`) | E (`rayjs:ext:box2d_userdata`) |

This document proposes six self-contained examples — one per technique — that together exercise
every new API. Each is a single `.js` file in `examples/box2d/`, no shared helpers.

---

## Conventions

Match the existing `hello_physics.js`:

- **Scale:** `const SCALE = 30  // px per metre`
- **Screen-space helpers:** `toScreenX(px)` / `toScreenY(py)` inline at the top of each file
- **Window:** `800 × 600` for consistency
- **Imports:** named imports from `rayjs:raylib` and `rayjs:box2d`. `rayjs:ext:box2d_userdata`
  only when userData is needed.
- **Body creation:** match the array-wrapping pattern (`b2CreateBody(world, [bodyDef])`) used
  in `hello_physics.js`.
- **Comments:** keep them short. One block at the top explaining the technique; line comments
  only at the genuinely non-obvious lines.
- **No shared helpers file** — each example is fully readable on its own. Some 4–6 line
  duplication (toScreen, drawCircleBody) is acceptable.

---

## Proposed examples

### 1. `box2d_mouse_picking.js` — pick bodies with the mouse

**Demonstrates:** `b2World_OverlapAABB`, `b2Body_SetUserData` / `b2Body_GetUserData`.

**Mechanics:** A handful of dynamic shapes fall onto a static floor. Hovering the mouse
highlights the body under the cursor; clicking and dragging moves it (teleport — no
mouse joint, to keep the example small).

**Pseudocode for the pick query:**

```js
const m = b2GetMouseWorldVec2()
const eps = 0.01  // ~half a centimetre
const aabb = new b2AABB(new b2Vec2(m.x - eps, m.y - eps), new b2Vec2(m.x + eps, m.y + eps))
let pickedBody = null
b2World_OverlapAABB(world, aabb, b2DefaultQueryFilter(), (shapeId) => {
    pickedBody = b2Shape_GetBody(shapeId)
    return false  // stop scanning at the first hit
})
```

Returning `false` from the callback ends the traversal — that's the documented Box2D contract,
already supported by our trampoline.

**Estimated size:** ~90 lines.

---

### 2. `box2d_raycast_vision.js` — guard with a vision ray

**Demonstrates:** `b2World_CastRay`, userData tagging.

**Mechanics:** A static "guard" body in the centre sweeps a ray through ±60° at a slow rate.
A dynamic "player" body is controlled with WASD. Walls are tagged `{type: "wall"}`, the player
`{type: "player"}` via `b2Body_SetUserData`. When the ray's first hit is the player, the
guard "spots" them and the screen flashes.

**Cast callback returns:**
- `-1` → ignore this shape, keep going
- `0` → terminate immediately
- `fraction` → clip the ray to this fraction (closest-hit mode)
- `1` → continue without clipping

For "first hit closest" semantics we return `fraction` and read out the closest one.

**Estimated size:** ~120 lines.

---

### 3. `box2d_one_way_platforms.js` — jump-through platforms

**Demonstrates:** `b2World_SetPreSolveCallback`, userData, shape `enablePreSolveEvents`.

**Mechanics:** Three horizontal platforms stacked vertically. A dynamic player body controlled
with arrow keys (or use `b2Body_SetLinearVelocity` for direct control). Platforms tagged
`{oneway: true, top: y_meters}`. The PreSolve callback inspects the contact: if the platform
is one-way and the player's velocity is upward (or its centre is below the platform top),
the callback returns `false` to cancel the contact — the player passes through.

**Key requirement:** every shape involved in the test must have `shapeDef.enablePreSolveEvents = true`
set at creation time. This was the gotcha caught while verifying Category C.

**Estimated size:** ~120 lines.

---

### 4. `box2d_team_bullets.js` — team-based collision filtering

**Demonstrates:** `b2World_SetCustomFilterCallback`, userData.

**Mechanics:** Two clusters of dynamic bodies, one red team on the left, one blue on the right.
Spacebar fires a "bullet" (small fast dynamic body) from a randomly-chosen body towards the
opposing cluster. Bullets are tagged with their team; the custom filter returns `false` for
any (bullet, body) pair where both share the same team — so a bullet never hits its own
teammates.

The filter callback only fires when a contact pair is first evaluated (cached after that),
so this works cleanly without re-evaluation pressure.

**Estimated size:** ~140 lines.

---

### 5. `box2d_material_friction.js` — different surface materials on a slope

**Demonstrates:** `b2World_SetFrictionCallback`, `b2World_SetRestitutionCallback`, `userMaterialId`.

**Mechanics:** A tilted ramp built from three side-by-side polygon segments: ice (low friction),
wood (medium), rubber (high friction, high restitution). Each segment's shape definition gets
a distinct `material.userMaterialId` (1/2/3). The friction callback receives both materials'
IDs and looks up a table to return the pair's effective friction; restitution callback does
the same for bounciness.

A dynamic ball drops on each segment in turn (or three balls roll across all three) — visibly
slides on ice, settles on rubber.

**Estimated size:** ~130 lines.

---

### 6. `box2d_character_mover.js` — kinematic capsule using the mover API

**Demonstrates:** `b2World_CastMover`, `b2World_CollideMover`.

**Mechanics:** A capsule character (not a body — just a `b2Capsule` shape position the example
maintains itself) walks with WASD over a small terrain of static polygons. Each frame:

1. Compute desired translation from input + gravity.
2. `b2World_CastMover(world, capsule, translation, filter)` → fraction of the move that's
   collision-free. Move that far.
3. `b2World_CollideMover(world, capsule, filter, (shapeId, plane) => { ... })` → gather
   contact planes; project remaining velocity onto them to slide along walls.

This is the trickiest example — it deliberately demonstrates the technique Box2D recommends
for character controllers in v3, which avoids the "stick on slope" and "fall through corners"
problems of using a dynamic body.

**Estimated size:** ~180 lines.

---

## Priority order

Implement in this order to spread coverage and finish the simple ones first:

| # | Example | New API exercised | Complexity |
|---|---|---|---|
| 1 | `box2d_mouse_picking.js` | `b2World_OverlapAABB`, userData | low |
| 2 | `box2d_one_way_platforms.js` | `b2World_SetPreSolveCallback`, userData | medium |
| 3 | `box2d_raycast_vision.js` | `b2World_CastRay`, userData | medium |
| 4 | `box2d_team_bullets.js` | `b2World_SetCustomFilterCallback`, userData | medium |
| 5 | `box2d_material_friction.js` | `b2World_SetFrictionCallback`, `b2World_SetRestitutionCallback` | medium |
| 6 | `box2d_character_mover.js` | `b2World_CastMover`, `b2World_CollideMover` | high |

After #1–5 we'd have all the callback APIs visually demonstrated. #6 is the most involved
and could be deferred or replaced with a simpler `b2World_CastShape` demo (e.g., a thrown
projectile preview line — "where will this grenade land?") if scope needs trimming.

**Not in this plan:**
- `b2World_OverlapShape` and `b2World_CastShape` — covered by the same trampoline as their
  AABB/Ray counterparts; an explicit example would just be the same code with a different
  query primitive. Skipping unless requested.
- `b2World_SetCustomFilterCallback` interaction with `enablePreSolveEvents` — could be a
  follow-up example combining both, but each is shown standalone first.

---

## Open questions for the author

Things worth confirming before implementation:

1. **Mouse joint vs teleport in `mouse_picking`?** Teleport keeps the example short (~90 lines)
   but a `b2MouseJoint` is more realistic. If the user wants the joint version, expect
   ~120 lines and a brief touch on `b2CreateMouseJoint`.

2. **WASD vs arrow keys?** `hello_physics.js` has no input; the existing convention is unset.
   Proposal: arrow keys (no IME issues, works on every keyboard layout).

3. **Tiled background?** The `lib/tiled.js` module exists. Could `raycast_vision` use a Tiled
   map for the walls instead of inline rectangles? Adds value but doubles the example length.
   Default plan: inline rectangles for self-containment.

4. **Do we want an `examples/box2d/README.md`?** No other examples folder has one. Skipping
   unless requested.
