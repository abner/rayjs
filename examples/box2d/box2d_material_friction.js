/*******************************************************************************************
*
*   rayjs [box2d] example - Material friction / restitution tables
*
*   A tilted ramp made of three side-by-side polygon segments: ICE (low friction, no
*   bounce), WOOD (medium friction, small bounce), RUBBER (high friction, bouncy).
*   Each segment's surface material has a distinct userMaterialId (1/2/3).
*
*   Friction and restitution callbacks receive both materials' ids and look them up
*   in a JS table to return the effective pair value. Three balls roll down at once —
*   you can see them slide on ice, brake on wood, and bounce on rubber.
*
*   Controls: R to drop a fresh set of balls.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawCircleV, DrawText, DrawLineEx,
  IsKeyPressed,
  KEY_R,
  Vector2,
  BLACK, DARKGRAY, RAYWHITE, RED, GREEN, BLUE, GRAY, BROWN, LIGHTGRAY,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step,
  b2World_SetFrictionCallback, b2World_SetRestitutionCallback,
  b2CreateBody, b2DefaultBodyDef, b2_dynamicBody,
  b2CreatePolygonShape, b2CreateCircleShape,
  b2DefaultShapeDef, b2DefaultSurfaceMaterial, b2MakeOffsetBox,
  b2Body_GetPosition,
  b2Vec2, b2Rot, b2Circle,
} from "rayjs:box2d"

const SCREEN_W = 800
const SCREEN_H = 600
const SCALE    = 30       // pixels per metre
const ORIGIN_X = 50
const GROUND_PX = 560

function toScreenX(x) { return ORIGIN_X + x * SCALE }
function toScreenY(y) { return GROUND_PX - y * SCALE }

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D material friction (Friction/RestitutionCallback)")
SetTargetFPS(60)

// Material ids — kept in named constants so the table lookup reads cleanly.
const MAT_ICE    = 1
const MAT_WOOD   = 2
const MAT_RUBBER = 3

// Per-material self-friction / self-restitution (the diagonal of the table).
// Pair values are derived by averaging or min/max to keep the lookup minimal.
const FRICTION = { [MAT_ICE]: 0.02, [MAT_WOOD]: 0.4, [MAT_RUBBER]: 0.9 }
const BOUNCE   = { [MAT_ICE]: 0.0,  [MAT_WOOD]: 0.1, [MAT_RUBBER]: 0.7 }

// b2World_SetFrictionCallback: returns the effective friction for a pair.
// Using the minimum makes ice "win" any pair it touches — a reasonable model.
function frictionFor(_fA, idA, _fB, idB) {
  const a = FRICTION[idA] ?? 0.3
  const b = FRICTION[idB] ?? 0.3
  return Math.min(a, b)
}

// b2World_SetRestitutionCallback: returns the effective bounce for a pair.
// Using the maximum makes rubber dominate — also a reasonable model.
function restitutionFor(_rA, idA, _rB, idB) {
  const a = BOUNCE[idA] ?? 0.0
  const b = BOUNCE[idB] ?? 0.0
  return Math.max(a, b)
}

let worldId
let balls = []   // { id, radius, colour }

function buildWorld() {
  const worldDef   = b2DefaultWorldDef()
  worldDef.gravity = new b2Vec2(0, -18)
  worldId          = b2CreateWorld([worldDef])

  b2World_SetFrictionCallback(worldId, frictionFor)
  b2World_SetRestitutionCallback(worldId, restitutionFor)

  // Ramp — three tilted boxes attached to a single static body, with different
  // userMaterialIds. The materials are picked up by the friction/restitution
  // callbacks above on every contact.
  //
  // Ramp axis goes from upper-left to lower-right. To avoid stitching three
  // separate ramp segments together at fragile seams (where a rolling ball can
  // catch on a tiny vertical edge), each segment is a thin offset box on the
  // same body — all sharing one continuous diagonal line.
  const rampDef    = b2DefaultBodyDef()
  rampDef.position = new b2Vec2(8, 4)   // ramp pivot
  const rampId     = b2CreateBody(worldId, [rampDef])
  const RAMP_LEN   = 16
  const SEG_LEN    = RAMP_LEN / 3
  const RAMP_HALF_THICK = 0.18
  const RAMP_ANGLE = -Math.PI / 9   // ≈ -20°
  const rampRot    = new b2Rot(Math.cos(RAMP_ANGLE), Math.sin(RAMP_ANGLE))

  const segments = [
    { matId: MAT_ICE,    centre: -RAMP_LEN / 2 + SEG_LEN * 0.5, colour: LIGHTGRAY },
    { matId: MAT_WOOD,   centre: -RAMP_LEN / 2 + SEG_LEN * 1.5, colour: BROWN },
    { matId: MAT_RUBBER, centre: -RAMP_LEN / 2 + SEG_LEN * 2.5, colour: GRAY },
  ]
  for (const seg of segments) {
    const def = b2DefaultShapeDef()
    def.material = b2DefaultSurfaceMaterial()
    def.material.userMaterialId = seg.matId
    // Materials still need *some* baseline friction/restitution since the
    // callback's pair values are only consulted; but in this example the
    // callback overrides everything, so per-material values can be anything.
    def.material.friction    = FRICTION[seg.matId]
    def.material.restitution = BOUNCE[seg.matId]
    const offset = new b2Vec2(seg.centre, 0)
    const box    = b2MakeOffsetBox(SEG_LEN / 2, RAMP_HALF_THICK, offset, rampRot)
    b2CreatePolygonShape(rampId, [def], [box])
  }

  // Ground floor (catches everything below the ramp).
  const groundDef = b2DefaultBodyDef()
  groundDef.position = new b2Vec2(SCREEN_W / 2 / SCALE, -0.5)
  const groundId  = b2CreateBody(worldId, [groundDef])
  const groundShape = b2DefaultShapeDef()
  groundShape.material = b2DefaultSurfaceMaterial()
  groundShape.material.userMaterialId = MAT_WOOD
  groundShape.material.friction       = 0.4
  // groundShape.material.restitution = 0  (default)
  b2CreatePolygonShape(groundId, [groundShape],
    [b2MakeOffsetBox(SCREEN_W / 2 / SCALE, 0.25,
                     new b2Vec2(0, 0), new b2Rot(1, 0))])

  // Three balls, each tagged with the material that mirrors the ramp segment
  // it'll first touch. Their own material's id doesn't really matter — the
  // ramp's segment id is what the callback uses to determine the pair friction.
  balls = []
  const ballSpec = [
    { x:  2.5,  y: 12, colour: BLUE,  matId: MAT_WOOD },
    { x:  4.0,  y: 12, colour: GREEN, matId: MAT_WOOD },
    { x:  5.5,  y: 12, colour: RED,   matId: MAT_WOOD },
  ]
  for (const b of ballSpec) {
    const def = b2DefaultBodyDef()
    def.type     = b2_dynamicBody
    def.position = new b2Vec2(b.x, b.y)
    const id = b2CreateBody(worldId, [def])
    const s  = b2DefaultShapeDef()
    s.material = b2DefaultSurfaceMaterial()
    s.material.userMaterialId = b.matId
    s.density = 1.0
    const c  = new b2Circle()
    c.radius = 0.3
    b2CreateCircleShape(id, [s], [c])
    balls.push({ id, radius: c.radius, colour: b.colour })
  }

  return {
    rampPos:   rampDef.position,
    rampAngle: RAMP_ANGLE,
    segments,
    segLen:    SEG_LEN,
    rampLen:   RAMP_LEN,
    halfThick: RAMP_HALF_THICK,
  }
}

let ramp = buildWorld()

while (!WindowShouldClose()) {
  if (IsKeyPressed(KEY_R)) {
    b2World_SetFrictionCallback(worldId, null)
    b2World_SetRestitutionCallback(worldId, null)
    b2DestroyWorld(worldId)
    ramp = buildWorld()
  }

  b2World_Step(worldId, 1 / 60, 4)

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(RAYWHITE)

  // Ground strip
  DrawLineEx(
    new Vector2(toScreenX(0), toScreenY(0)),
    new Vector2(toScreenX(SCREEN_W / SCALE), toScreenY(0)),
    4, DARKGRAY,
  )

  // Ramp segments — drawn as coloured strokes along the ramp axis.
  const cs = Math.cos(ramp.rampAngle), sn = Math.sin(ramp.rampAngle)
  for (const seg of ramp.segments) {
    const a = { x: seg.centre - ramp.segLen / 2, y: 0 }
    const b = { x: seg.centre + ramp.segLen / 2, y: 0 }
    const wa = { x: ramp.rampPos.x + a.x * cs - a.y * sn, y: ramp.rampPos.y + a.x * sn + a.y * cs }
    const wb = { x: ramp.rampPos.x + b.x * cs - b.y * sn, y: ramp.rampPos.y + b.x * sn + b.y * cs }
    DrawLineEx(
      new Vector2(toScreenX(wa.x), toScreenY(wa.y)),
      new Vector2(toScreenX(wb.x), toScreenY(wb.y)),
      ramp.halfThick * 2 * SCALE, seg.colour,
    )
  }

  // Balls
  for (const b of balls) {
    const p = b2Body_GetPosition(b.id)
    DrawCircleV(new Vector2(toScreenX(p.x), toScreenY(p.y)), b.radius * SCALE, b.colour)
  }

  DrawText("Materials: ice (light grey) - wood (brown) - rubber (dark grey)",
           12, 12, 18, BLACK)
  DrawText("R to reset",                                  12, 36, 16, DARKGRAY)
  EndDrawing()
}

b2World_SetFrictionCallback(worldId, null)
b2World_SetRestitutionCallback(worldId, null)
b2DestroyWorld(worldId)
CloseWindow()
