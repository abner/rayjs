/*******************************************************************************************
*
*   rayjs [box2d] example - Team-based custom collision filter
*
*   Two clusters of dynamic bodies — RED on the left, BLUE on the right. Press SPACE
*   to fire a small fast bullet from a random body on each team toward the opposing
*   cluster. Bullets are tagged with their team via userData.
*
*   A custom filter callback rejects collision pairs where one side is a bullet and
*   the other side belongs to the same team — so bullets fly through teammates and
*   only impact the opposing team.
*
*   Box2D evaluates the custom filter once per contact pair and caches the result, so
*   this works cleanly without re-evaluation pressure.
*
*   Controls: Space to fire one bullet from each team, R to reset.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawCircleV, DrawRectangle, DrawText,
  IsKeyPressed,
  KEY_SPACE, KEY_R,
  Vector2,
  BLACK, DARKGRAY, RAYWHITE, RED, BLUE, MAROON, DARKBLUE,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step, b2World_SetCustomFilterCallback,
  b2CreateBody, b2DefaultBodyDef, b2DestroyBody, b2_dynamicBody,
  b2CreateCircleShape,
  b2DefaultShapeDef,
  b2Body_GetPosition, b2Body_SetLinearVelocity,
  b2Shape_GetBody,
  b2Vec2, b2Circle,
} from "rayjs:box2d"

import {
  b2Body_SetUserData, b2Body_GetUserData, b2Body_DeleteUserData, b2ClearAllUserData,
} from "rayjs:ext:box2d_userdata"

const SCREEN_W = 800
const SCREEN_H = 600
const SCALE    = 30       // pixels per metre
const ORIGIN_X = SCREEN_W / 2
const ORIGIN_Y = SCREEN_H / 2

function toScreenX(x) { return ORIGIN_X + x * SCALE }
function toScreenY(y) { return ORIGIN_Y - y * SCALE }

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D team bullets (CustomFilter)")
SetTargetFPS(60)

const RED_TEAM  = "red"
const BLUE_TEAM = "blue"

let worldId
let units   = []   // { id, team, radius }
let bullets = []   // { id, team, radius, lifeFrames }

function buildWorld() {
  b2ClearAllUserData()
  const worldDef   = b2DefaultWorldDef()
  worldDef.gravity = new b2Vec2(0, 0)
  worldId          = b2CreateWorld([worldDef])

  units   = []
  bullets = []

  // Custom filter — reject contact when bullet and target share a team.
  b2World_SetCustomFilterCallback(worldId, (shapeIdA, shapeIdB) => {
    /** @type {any} */
    const a = b2Body_GetUserData(b2Shape_GetBody(shapeIdA))
    /** @type {any} */
    const b = b2Body_GetUserData(b2Shape_GetBody(shapeIdB))
    if (!a || !b) return true
    // Either side a bullet and same team => no collision.
    const sameTeam = a.team === b.team
    const oneIsBullet = a.kind === "bullet" || b.kind === "bullet"
    if (oneIsBullet && sameTeam) return false
    return true
  })

  // Spawn two clusters — 6 units per team, slight random jitter for visual interest.
  for (let i = 0; i < 6; i++) {
    const yJitter = (Math.random() - 0.5) * 2
    spawnUnit(-6, -3 + i * 1.0 + yJitter * 0.2, RED_TEAM)
    spawnUnit( 6, -3 + i * 1.0 + yJitter * 0.2, BLUE_TEAM)
  }
}

function spawnUnit(x, y, team) {
  const def = b2DefaultBodyDef()
  def.type           = b2_dynamicBody
  def.position       = new b2Vec2(x, y)
  def.linearDamping  = 2
  def.angularDamping = 2
  const id = b2CreateBody(worldId, [def])
  const s  = b2DefaultShapeDef()
  s.material.friction = 0.3
  s.density           = 1.0
  const c  = new b2Circle()
  c.radius = 0.4
  b2CreateCircleShape(id, [s], [c])
  b2Body_SetUserData(id, { kind: "unit", team })
  units.push({ id, team, radius: c.radius })
}

function spawnBullet(team) {
  const myTeam = units.filter(u => u.team === team)
  if (myTeam.length === 0) return
  const src    = myTeam[Math.floor(Math.random() * myTeam.length)]
  const srcPos = b2Body_GetPosition(src.id)

  // Fire toward the *centre* of the opposing cluster, with a small spread.
  const enemies = units.filter(u => u.team !== team)
  if (enemies.length === 0) return
  let tx = 0, ty = 0
  for (const e of enemies) {
    const p = b2Body_GetPosition(e.id)
    tx += p.x; ty += p.y
  }
  tx /= enemies.length; ty /= enemies.length
  const dx = tx - srcPos.x + (Math.random() - 0.5) * 0.6
  const dy = ty - srcPos.y + (Math.random() - 0.5) * 0.6
  const len = Math.hypot(dx, dy) || 1
  const SPEED = 14
  const vx = dx / len * SPEED, vy = dy / len * SPEED

  const def = b2DefaultBodyDef()
  def.type     = b2_dynamicBody
  def.isBullet = true
  def.position = new b2Vec2(srcPos.x + dx / len * (src.radius + 0.15),
                             srcPos.y + dy / len * (src.radius + 0.15))
  const id = b2CreateBody(worldId, [def])
  const s  = b2DefaultShapeDef()
  s.density = 0.2
  const c  = new b2Circle()
  c.radius = 0.12
  b2CreateCircleShape(id, [s], [c])
  b2Body_SetUserData(id, { kind: "bullet", team })
  b2Body_SetLinearVelocity(id, new b2Vec2(vx, vy))
  bullets.push({ id, team, radius: c.radius, lifeFrames: 180 })
}

buildWorld()

while (!WindowShouldClose()) {
  if (IsKeyPressed(KEY_SPACE)) {
    spawnBullet(RED_TEAM)
    spawnBullet(BLUE_TEAM)
  }
  if (IsKeyPressed(KEY_R)) {
    // Drop the persistent JS callback ref before destroying the world.
    b2World_SetCustomFilterCallback(worldId, null)
    b2DestroyWorld(worldId)
    buildWorld()
  }

  // Tick down bullet lifetimes; destroy when expired or out-of-bounds.
  for (let i = bullets.length - 1; i >= 0; i--) {
    const b = bullets[i]
    b.lifeFrames--
    const p = b2Body_GetPosition(b.id)
    if (b.lifeFrames <= 0 || Math.abs(p.x) > 14 || Math.abs(p.y) > 10) {
      b2Body_DeleteUserData(b.id)
      b2DestroyBody(b.id)
      bullets.splice(i, 1)
    }
  }

  b2World_Step(worldId, 1 / 60, 4)

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(RAYWHITE)
  DrawRectangle(0, 0, SCREEN_W, 50, DARKGRAY)
  DrawText("SPACE to fire   R to reset   bullets pass through their own team",
           12, 14, 18, RAYWHITE)

  for (const u of units) {
    const p = b2Body_GetPosition(u.id)
    DrawCircleV(new Vector2(toScreenX(p.x), toScreenY(p.y)), u.radius * SCALE,
                u.team === RED_TEAM ? MAROON : DARKBLUE)
  }
  for (const b of bullets) {
    const p = b2Body_GetPosition(b.id)
    DrawCircleV(new Vector2(toScreenX(p.x), toScreenY(p.y)), b.radius * SCALE,
                b.team === RED_TEAM ? RED : BLUE)
  }
  DrawText(`bullets in flight: ${bullets.length}`, 12, SCREEN_H - 30, 16, BLACK)
  EndDrawing()
}

b2World_SetCustomFilterCallback(worldId, null)
b2DestroyWorld(worldId)
CloseWindow()
