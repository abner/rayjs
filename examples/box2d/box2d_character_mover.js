/*******************************************************************************************
*
*   rayjs [box2d] example - Kinematic capsule character (b2World_CastMover + CollideMover)
*
*   The character is NOT a Box2D body — just a b2Capsule whose position the example
*   maintains directly. Each frame:
*
*     1. Compute the desired translation from input + gravity * dt.
*     2. b2World_CastMover(world, capsule, translation, filter) returns a fraction in
*        [0..1]: how much of the desired move is collision-free. Advance by that much.
*     3. b2World_CollideMover walks all contact planes the capsule overlaps after the
*        move. For each plane with v·n < 0, project the remaining velocity onto the
*        plane — this lets the character slide along walls and slopes instead of
*        sticking on corners (the failure mode of using a dynamic body for this).
*
*   The technique is what Box2D v3 recommends for character controllers: avoids the
*   "snag on slope" and "fall through corner" artefacts of dynamic-body characters.
*
*   Controls: A/D move, W or Space jump, R reset.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS, GetFrameTime,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawCircle, DrawRectangle, DrawLineEx, DrawText,
  IsKeyDown, IsKeyPressed,
  KEY_A, KEY_D, KEY_W, KEY_SPACE, KEY_R,
  Vector2,
  BLACK, DARKGRAY, RED, GREEN, BLUE, SKYBLUE, BROWN, GRAY,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step,
  b2World_CastMover, b2World_CollideMover,
  b2CreateBody, b2DefaultBodyDef,
  b2CreatePolygonShape, b2MakeBox,
  b2DefaultShapeDef, b2DefaultQueryFilter,
  b2Vec2, b2Capsule,
} from "rayjs:box2d"

const SCREEN_W = 800
const SCREEN_H = 600
const SCALE    = 30       // pixels per metre
const ORIGIN_X = 50
const GROUND_PX = 560

function toScreenX(x) { return ORIGIN_X + x * SCALE }
function toScreenY(y) { return GROUND_PX - y * SCALE }

const CAPSULE_RADIUS  = 0.25
const CAPSULE_HALF_H  = 0.55   // distance from body-centre to top/bottom of capsule
const MOVE_SPEED      = 6      // m/s horizontal
const JUMP_SPEED      = 9      // m/s vertical
const GRAVITY         = -22    // m/s²

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D character mover (Cast/CollideMover)")
SetTargetFPS(60)

// Terrain — a few static boxes. Includes a ledge, a step, and a sloped piece
// (built from two stacked boxes so the move planes are well-defined).
const terrain = [
  { cx:  0,  cy:  0,   hw: 24, hh: 0.25 },   // floor
  { cx:  6,  cy:  1.5, hw: 1.5, hh: 1.25 },  // low platform
  { cx:  9,  cy:  3,   hw: 1.5, hh: 0.25 },  // mid ledge
  { cx: 13,  cy:  4.5, hw: 1.5, hh: 0.25 },  // high ledge
  { cx: 17,  cy:  1.5, hw: 0.5, hh: 1.25 },  // wall
  { cx:  3,  cy:  2.5, hw: 0.5, hh: 0.5 },   // a small block to slide past
]

let worldId
let pos = { x: 1, y: 1.5 }   // character body-centre, world coords
let vel = { x: 0, y: 0 }
let grounded = false

function buildWorld() {
  const worldDef   = b2DefaultWorldDef()
  worldDef.gravity = new b2Vec2(0, 0)   // we apply gravity ourselves
  worldId          = b2CreateWorld([worldDef])

  for (const t of terrain) {
    const def = b2DefaultBodyDef()
    def.position = new b2Vec2(t.cx, t.cy)
    const id = b2CreateBody(worldId, [def])
    const s  = b2DefaultShapeDef()
    s.material.friction = 0.5
    b2CreatePolygonShape(id, [s], [b2MakeBox(t.hw, t.hh)])
  }

  pos = { x: 1, y: 1.5 }
  vel = { x: 0, y: 0 }
  grounded = false
}

function makeCapsule() {
  // The capsule is upright: two centres on the body's vertical axis, offset by
  // ±(halfH - radius) so the rounded caps land at body_centre ± halfH.
  const off = CAPSULE_HALF_H - CAPSULE_RADIUS
  return new b2Capsule(
    new b2Vec2(pos.x, pos.y - off),
    new b2Vec2(pos.x, pos.y + off),
    CAPSULE_RADIUS,
  )
}

buildWorld()

while (!WindowShouldClose()) {
  if (IsKeyPressed(KEY_R)) { b2DestroyWorld(worldId); buildWorld() }

  const dt = Math.min(GetFrameTime(), 1 / 30)

  // ── Input: set horizontal velocity directly; jump = set vy ───────────────
  let inputX = 0
  if (IsKeyDown(KEY_A)) inputX -= 1
  if (IsKeyDown(KEY_D)) inputX += 1
  vel.x = inputX * MOVE_SPEED
  if (grounded && (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE))) vel.y = JUMP_SPEED

  // Gravity
  vel.y += GRAVITY * dt

  // Desired move this frame
  let moveX = vel.x * dt
  let moveY = vel.y * dt

  // ── 1) CastMover: how much of the move is collision-free? ────────────────
  // Up to a couple of "slide passes" so we don't lose tangential motion when
  // hitting a wall mid-step.
  const filter = b2DefaultQueryFilter()
  for (let pass = 0; pass < 3; pass++) {
    if (Math.abs(moveX) < 1e-5 && Math.abs(moveY) < 1e-5) break
    const capsule = makeCapsule()
    const translation = new b2Vec2(moveX, moveY)
    const fraction = b2World_CastMover(worldId, [capsule], translation, filter)
    // Advance the unblocked portion of the move.
    pos.x += moveX * fraction
    pos.y += moveY * fraction
    const remaining = 1 - fraction
    if (remaining <= 1e-4) { moveX = 0; moveY = 0; break }

    // What's left after the cast — project this onto each contact plane to slide.
    moveX *= remaining
    moveY *= remaining

    // ── 2) CollideMover: contact planes at current pos ───────────────────────
    const probe = makeCapsule()
    let projected = false
    b2World_CollideMover(worldId, probe, filter, (_shapeId, plane) => {
      if (!plane.hit) return true
      const nx = plane.plane.normal.x
      const ny = plane.plane.normal.y
      // Only project if the residual move points into this plane.
      const dot = moveX * nx + moveY * ny
      if (dot < 0) {
        moveX -= dot * nx
        moveY -= dot * ny
        projected = true
      }
      return true   // keep collecting planes
    })

    if (!projected) break   // no plane to slide along → done
  }

  // ── Grounded check: any plane with an up-facing normal touching us? ──────
  grounded = false
  let onSlopeNormalY = 0
  const groundProbe = makeCapsule()
  b2World_CollideMover(worldId, groundProbe, filter, (_shapeId, plane) => {
    if (!plane.hit) return true
    if (plane.plane.normal.y > 0.5) {
      grounded = true
      if (plane.plane.normal.y > onSlopeNormalY) onSlopeNormalY = plane.plane.normal.y
    }
    return true
  })
  // If grounded and falling, kill downward velocity so we don't accumulate it
  // into a phantom impact next frame.
  if (grounded && vel.y < 0) vel.y = 0

  // World-step still runs (no dynamic bodies, but advances internal state cheaply).
  b2World_Step(worldId, 1 / 60, 4)

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(SKYBLUE)

  for (const t of terrain) {
    DrawRectangle(toScreenX(t.cx - t.hw), toScreenY(t.cy + t.hh),
                  t.hw * 2 * SCALE, t.hh * 2 * SCALE, BROWN)
  }

  // Capsule: a rectangle plus two end-caps.
  const off = CAPSULE_HALF_H - CAPSULE_RADIUS
  const x = toScreenX(pos.x)
  const yTop = toScreenY(pos.y + off)
  const yBot = toScreenY(pos.y - off)
  const r = CAPSULE_RADIUS * SCALE
  DrawRectangle(x - r, yTop, r * 2, yBot - yTop, grounded ? GREEN : RED)
  DrawCircle(x, yTop, r, grounded ? GREEN : RED)
  DrawCircle(x, yBot, r, grounded ? GREEN : RED)

  // Velocity arrow (debug viz)
  const vEnd = new Vector2(x + vel.x * SCALE * 0.1, toScreenY(pos.y + vel.y * 0.1))
  DrawLineEx(new Vector2(x, toScreenY(pos.y)), vEnd, 2, BLUE)

  DrawText("A/D move - W or Space jump - R reset", 12, 12, 18, BLACK)
  DrawText(grounded ? "grounded" : "airborne", 12, 36, 16, grounded ? GREEN : GRAY)
  DrawText(`vel: (${vel.x.toFixed(2)}, ${vel.y.toFixed(2)})`, 12, 58, 14, DARKGRAY)
  EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
