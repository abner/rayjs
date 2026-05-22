/*******************************************************************************************
*
*   rayjs [box2d] example - One-way platforms via b2World_SetPreSolveCallback
*
*   Three horizontal platforms stacked at different heights. The player (a dynamic body
*   controlled with the arrow keys) can jump straight through them from below, but lands
*   on top normally. Implemented with a pre-solve callback that returns false (cancels
*   the contact) when the player is moving upward into the platform from below.
*
*   Two requirements caught while building this:
*     1. Every shape involved in the test must set shapeDef.enablePreSolveEvents = true.
*     2. The platform's userData must carry its top-edge y so the callback can decide
*        which side of it the player is on.
*
*   Controls: ←/→ move, ↑ or Space jump, R reset.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawRectangle, DrawRectanglePro, DrawText,
  IsKeyDown, IsKeyPressed,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_SPACE, KEY_R,
  Vector2, Rectangle,
  BLACK, DARKGRAY, RED, GREEN, BROWN, SKYBLUE,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step, b2World_SetPreSolveCallback,
  b2CreateBody, b2DefaultBodyDef, b2_dynamicBody,
  b2CreatePolygonShape, b2MakeBox,
  b2DefaultShapeDef,
  b2Body_GetPosition, b2Body_GetLinearVelocity, b2Body_SetLinearVelocity,
  b2Shape_GetBody,
  b2Vec2,
} from "rayjs:box2d"

import {
  b2Body_SetUserData, b2Body_GetUserData, b2ClearAllUserData,
} from "rayjs:ext:box2d_userdata"

const SCREEN_W  = 800
const SCREEN_H  = 600
const SCALE     = 30       // pixels per metre
const GROUND_PX = 560

function toScreenX(mx) { return SCREEN_W / 2 + mx * SCALE }
function toScreenY(my) { return GROUND_PX - my * SCALE }

const PLAYER_HALF_W = 0.4
const PLAYER_HALF_H = 0.55
const PLATFORM_HALF_W = 2.0
const PLATFORM_HALF_H = 0.15
const MOVE_SPEED = 6
const JUMP_VEL   = 12

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D one-way platforms (PreSolve)")
SetTargetFPS(60)

let worldId, playerId
let platforms = []  // { id, x, y }

function buildWorld() {
  b2ClearAllUserData()
  const worldDef = b2DefaultWorldDef()
  worldDef.gravity = new b2Vec2(0, -20)
  worldId = b2CreateWorld([worldDef])

  // Ground
  const groundDef = b2DefaultBodyDef()
  const groundId  = b2CreateBody(worldId, [groundDef])
  const groundShape = b2DefaultShapeDef()
  groundShape.enablePreSolveEvents = true  // must be on for every shape that participates
  b2CreatePolygonShape(groundId, [groundShape], [b2MakeBox(SCREEN_W / 2 / SCALE, 0.5)])
  b2Body_SetUserData(groundId, { kind: "ground" })

  // Three platforms stacked vertically. UserData tags them as one-way and records
  // the world-y of their top surface (centre.y + halfH).
  platforms = []
  const heights = [3, 6, 9]
  for (const h of heights) {
    const def = b2DefaultBodyDef()
    def.position = new b2Vec2(0, h)
    const id = b2CreateBody(worldId, [def])
    const s = b2DefaultShapeDef()
    s.enablePreSolveEvents = true
    s.material.friction = 0.6
    b2CreatePolygonShape(id, [s], [b2MakeBox(PLATFORM_HALF_W, PLATFORM_HALF_H)])
    b2Body_SetUserData(id, { kind: "oneway", topY: h + PLATFORM_HALF_H })
    platforms.push({ id, x: 0, y: h })
  }

  // Player
  const pdef = b2DefaultBodyDef()
  pdef.type          = b2_dynamicBody
  pdef.fixedRotation = true
  pdef.position      = new b2Vec2(-5, 1)
  playerId = b2CreateBody(worldId, [pdef])
  const pshape = b2DefaultShapeDef()
  pshape.enablePreSolveEvents = true
  pshape.material.friction    = 0.0   // don't grip walls; we overwrite velocity each frame
  pshape.density              = 1.0
  b2CreatePolygonShape(playerId, [pshape], [b2MakeBox(PLAYER_HALF_W, PLAYER_HALF_H)])
  b2Body_SetUserData(playerId, { kind: "player" })

  // Pre-solve callback. Box2D doesn't tell us which contact is the player and which is
  // the platform — we inspect both shapes' userData. If one side is "oneway" and the
  // other side is "player", cancel the contact when the player's centre is below the
  // platform's top OR the player is moving upward.
  b2World_SetPreSolveCallback(worldId, (shapeIdA, shapeIdB, _manifold) => {
    /** @type {any} */
    const dataA = b2Body_GetUserData(b2Shape_GetBody(shapeIdA))
    /** @type {any} */
    const dataB = b2Body_GetUserData(b2Shape_GetBody(shapeIdB))
    if (!dataA || !dataB) return true

    let platform, player
    if (dataA.kind === "oneway" && dataB.kind === "player") { platform = dataA; player = playerId }
    else if (dataB.kind === "oneway" && dataA.kind === "player") { platform = dataB; player = playerId }
    else return true

    const pos = b2Body_GetPosition(player)
    const vel = b2Body_GetLinearVelocity(player)
    // Player passes through if its feet are still below the platform top, or it's moving up.
    const playerFeet = pos.y - PLAYER_HALF_H
    if (playerFeet < platform.topY - 0.05 || vel.y > 0.1) return false
    return true
  })
}

buildWorld()

let grounded = false

while (!WindowShouldClose()) {
  if (IsKeyPressed(KEY_R)) {
    b2DestroyWorld(worldId)
    buildWorld()
    grounded = false
  }

  // Cheap "is grounded" heuristic — vertical velocity ≈ 0.
  const vel = b2Body_GetLinearVelocity(playerId)
  grounded = Math.abs(vel.y) < 0.05

  let vx = 0
  if (IsKeyDown(KEY_LEFT))  vx -= MOVE_SPEED
  if (IsKeyDown(KEY_RIGHT)) vx += MOVE_SPEED
  let vy = vel.y
  if (grounded && (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE))) vy = JUMP_VEL
  b2Body_SetLinearVelocity(playerId, new b2Vec2(vx, vy))

  b2World_Step(worldId, 1 / 60, 4)

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(SKYBLUE)
  DrawRectangle(0, GROUND_PX, SCREEN_W, 30, DARKGRAY)

  for (const p of platforms) {
    const pos = b2Body_GetPosition(p.id)
    const w = PLATFORM_HALF_W * 2 * SCALE
    const h = PLATFORM_HALF_H * 2 * SCALE
    DrawRectanglePro(
      new Rectangle(toScreenX(pos.x), toScreenY(pos.y), w, h),
      new Vector2(w / 2, h / 2),
      0, BROWN,
    )
  }

  const ppos = b2Body_GetPosition(playerId)
  const pw = PLAYER_HALF_W * 2 * SCALE
  const ph = PLAYER_HALF_H * 2 * SCALE
  DrawRectanglePro(
    new Rectangle(toScreenX(ppos.x), toScreenY(ppos.y), pw, ph),
    new Vector2(pw / 2, ph / 2),
    0, grounded ? GREEN : RED,
  )

  DrawText("Arrows move - Up/Space jump - R reset", 12, 12, 18, BLACK)
  DrawText("Jump up through platforms, land on top from above", 12, 36, 14, DARKGRAY)
  EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
