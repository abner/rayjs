/*******************************************************************************************
*
*   rayjs [box2d] example - Guard with a sweeping vision ray (b2World_CastRay)
*
*   Top-down world with no gravity. A static "guard" sweeps a 6 m ray through ±60°.
*   Walls block line of sight to the player (small dynamic body, arrow keys to move).
*   When the ray's first hit is the player, the guard "spots" them: red overlay flashes.
*
*   Cast-callback return values:
*     -1       ignore this hit, keep going
*      0       terminate the cast immediately
*    fraction  clip the ray to this fraction (closest-hit mode)
*      1       continue without clipping
*
*   Closest-hit semantics used here: return fraction every time, read closest on return.
*
*   Controls: arrow keys move the player.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS, GetFrameTime,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawCircle, DrawRectangle, DrawLineEx, DrawText, DrawCircleV,
  IsKeyDown,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
  Vector2, Color,
  BLACK, DARKGRAY, RAYWHITE, RED, GREEN, ORANGE, YELLOW, GRAY,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step, b2World_CastRay,
  b2CreateBody, b2DefaultBodyDef, b2_dynamicBody,
  b2CreatePolygonShape, b2CreateCircleShape, b2MakeBox,
  b2DefaultShapeDef, b2DefaultQueryFilter,
  b2Body_GetPosition, b2Body_SetLinearVelocity,
  b2Shape_GetBody,
  b2Vec2, b2Circle,
} from "rayjs:box2d"

import {
  b2Body_SetUserData, b2Body_GetUserData,
} from "rayjs:ext:box2d_userdata"

const SCREEN_W = 800
const SCREEN_H = 600
const SCALE    = 30       // pixels per metre
const ORIGIN_X = SCREEN_W / 2
const ORIGIN_Y = SCREEN_H - 60

function toScreenX(x) { return ORIGIN_X + x * SCALE }
function toScreenY(y) { return ORIGIN_Y - y * SCALE }

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D vision ray (CastRay)")
SetTargetFPS(60)

const worldDef   = b2DefaultWorldDef()
worldDef.gravity = new b2Vec2(0, 0)   // top-down, no gravity
const worldId    = b2CreateWorld([worldDef])

// Static wall geometry. Two lists serve two purposes: the array goes into Box2D
// for collision, and the same array is used for drawing — keeping the visible
// rectangles and the physical bodies trivially in sync.
const wallList = [
  { cx:  0,  cy: 9,   hw: 12,   hh: 0.25 },   // top
  { cx:  0,  cy: -0.5, hw: 12,   hh: 0.25 },  // bottom
  { cx: -12, cy: 4.5, hw: 0.25, hh: 5 },      // left
  { cx:  12, cy: 4.5, hw: 0.25, hh: 5 },      // right
  { cx: -5,  cy: 3,   hw: 2,    hh: 0.25 },
  { cx:  5,  cy: 5.5, hw: 2,    hh: 0.25 },
  { cx: -2,  cy: 6.5, hw: 0.25, hh: 1.5 },
  { cx:  2,  cy: 2,   hw: 0.25, hh: 1.5 },
]
for (const w of wallList) {
  const def = b2DefaultBodyDef()
  def.position = new b2Vec2(w.cx, w.cy)
  const id = b2CreateBody(worldId, [def])
  b2CreatePolygonShape(id, [b2DefaultShapeDef()], [b2MakeBox(w.hw, w.hh)])
  b2Body_SetUserData(id, { kind: "wall" })
}

// Guard — static, in the middle of the room.
const GX = 0, GY = 5
const guardDef    = b2DefaultBodyDef()
guardDef.position = new b2Vec2(GX, GY)
const guardId     = b2CreateBody(worldId, [guardDef])
b2Body_SetUserData(guardId, { kind: "guard" })

// Player — dynamic circle, near-zero friction in zero gravity.
const playerDef          = b2DefaultBodyDef()
playerDef.type           = b2_dynamicBody
playerDef.fixedRotation  = true
playerDef.position       = new b2Vec2(-7, 1.5)
playerDef.linearDamping  = 4
const playerId           = b2CreateBody(worldId, [playerDef])
const playerCircle       = new b2Circle()
playerCircle.radius      = 0.4
const playerShapeDef     = b2DefaultShapeDef()
playerShapeDef.density   = 1.0
b2CreateCircleShape(playerId, [playerShapeDef], [playerCircle])
b2Body_SetUserData(playerId, { kind: "player" })

const SWEEP_HALF_ANGLE = Math.PI / 3      // ±60°
const SWEEP_HZ         = 0.4              // cycles per second
const RAY_RANGE        = 6
const MOVE_SPEED       = 5
const ALERT_COLOUR     = new Color(255, 80, 80, 60)

let t        = 0
let spotted  = false
let rayEnd   = { x: GX, y: GY }

while (!WindowShouldClose()) {
  const dt = GetFrameTime()
  t += dt

  // Move the player.
  let vx = 0, vy = 0
  if (IsKeyDown(KEY_LEFT))  vx -= 1
  if (IsKeyDown(KEY_RIGHT)) vx += 1
  if (IsKeyDown(KEY_UP))    vy += 1
  if (IsKeyDown(KEY_DOWN))  vy -= 1
  if (vx || vy) {
    const len = Math.hypot(vx, vy)
    vx = vx / len * MOVE_SPEED
    vy = vy / len * MOVE_SPEED
  }
  b2Body_SetLinearVelocity(playerId, new b2Vec2(vx, vy))

  b2World_Step(worldId, 1 / 60, 4)

  // Sweep the vision direction. Centre = -y (toward the room below the guard);
  // oscillate ±SWEEP_HALF_ANGLE around that axis.
  const angle = Math.sin(t * SWEEP_HZ * 2 * Math.PI) * SWEEP_HALF_ANGLE
  const dirX  =  Math.sin(angle)
  const dirY  = -Math.cos(angle)
  const origin      = new b2Vec2(GX, GY)
  const translation = new b2Vec2(dirX * RAY_RANGE, dirY * RAY_RANGE)

  let closestFrac   = 1
  let closestPlayer = false
  b2World_CastRay(worldId, origin, translation, b2DefaultQueryFilter(),
    (shapeId, _point, _normal, fraction) => {
      /** @type {any} */
      const data = b2Body_GetUserData(b2Shape_GetBody(shapeId))
      if (!data) return -1
      if (data.kind === "guard") return -1   // never collide with self
      if (fraction < closestFrac) {
        closestFrac   = fraction
        closestPlayer = (data.kind === "player")
      }
      return fraction   // clip — only closer hits will be reported afterwards
    })

  spotted = closestPlayer
  rayEnd  = { x: GX + translation.x * closestFrac, y: GY + translation.y * closestFrac }

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(RAYWHITE)
  if (spotted) DrawRectangle(0, 0, SCREEN_W, SCREEN_H, ALERT_COLOUR)

  for (const w of wallList) {
    DrawRectangle(toScreenX(w.cx - w.hw), toScreenY(w.cy + w.hh),
                  w.hw * 2 * SCALE, w.hh * 2 * SCALE, DARKGRAY)
  }

  DrawLineEx(
    new Vector2(toScreenX(GX), toScreenY(GY)),
    new Vector2(toScreenX(rayEnd.x), toScreenY(rayEnd.y)),
    3, spotted ? RED : YELLOW,
  )

  // Guard — orange ring with a black centre.
  DrawCircle(toScreenX(GX), toScreenY(GY), 14, ORANGE)
  DrawCircle(toScreenX(GX), toScreenY(GY), 6, BLACK)

  // Player
  const ppos = b2Body_GetPosition(playerId)
  DrawCircleV(new Vector2(toScreenX(ppos.x), toScreenY(ppos.y)),
              playerCircle.radius * SCALE, GREEN)

  DrawText("Arrows move - sneak past the guard", 12, 12, 18, BLACK)
  DrawText(spotted ? "SPOTTED" : "hidden", 12, 36, 18, spotted ? RED : GRAY)
  EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
