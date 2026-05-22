/*******************************************************************************************
*
*   rayjs [box2d] example - Mouse picking via b2World_OverlapAABB
*
*   Drops a handful of dynamic shapes onto a static floor. The mouse cursor is converted
*   to world coordinates and a tiny AABB (≈1 cm square) is overlapped against the world
*   to find the body under the cursor. Click-and-drag teleports the picked body — no
*   mouse joint, to keep the demo minimal.
*
*   Each dynamic body has a colour tag attached via b2Body_SetUserData, which is read
*   back in the draw loop.
*
*   Controls: hover to highlight, hold left mouse to drag.
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS,
  BeginDrawing, EndDrawing, ClearBackground,
  DrawCircleV, DrawRectangle, DrawRectanglePro, DrawText,
  GetMousePosition, IsMouseButtonDown,
  Vector2, Rectangle,
  BLACK, DARKGRAY, RAYWHITE, RED, GREEN, BLUE, ORANGE, PURPLE, YELLOW,
  MOUSE_BUTTON_LEFT,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step, b2World_OverlapAABB,
  b2CreateBody, b2DefaultBodyDef, b2_dynamicBody,
  b2CreatePolygonShape, b2CreateCircleShape, b2MakeBox,
  b2DefaultShapeDef, b2DefaultQueryFilter,
  b2Body_GetPosition, b2Body_GetRotation, b2Body_SetTransform, b2Body_SetLinearVelocity,
  b2Shape_GetBody,
  b2Vec2, b2Rot, b2Circle, b2AABB,
} from "rayjs:box2d"

import {
  b2Body_SetUserData, b2Body_GetUserData,
} from "rayjs:ext:box2d_userdata"

const SCREEN_W  = 800
const SCREEN_H  = 600
const SCALE     = 30       // pixels per metre
const GROUND_PX = 550

function toScreenX(px) { return SCREEN_W / 2 + px * SCALE }
function toScreenY(py) { return GROUND_PX - py * SCALE }
function fromScreenX(sx) { return (sx - SCREEN_W / 2) / SCALE }
function fromScreenY(sy) { return (GROUND_PX - sy) / SCALE }

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D mouse picking (OverlapAABB)")
SetTargetFPS(60)

const worldDef = b2DefaultWorldDef()
const worldId  = b2CreateWorld([worldDef])

// Ground
const groundDef = b2DefaultBodyDef()
const groundId  = b2CreateBody(worldId, [groundDef])
b2CreatePolygonShape(groundId, [b2DefaultShapeDef()], [b2MakeBox(SCREEN_W / 2 / SCALE, 0.5)])

// Side walls so the bodies don't escape sideways while being dragged.
for (const side of [-1, 1]) {
  const def = b2DefaultBodyDef()
  def.position = new b2Vec2(side * (SCREEN_W / 2 / SCALE), 6)
  const id = b2CreateBody(worldId, [def])
  b2CreatePolygonShape(id, [b2DefaultShapeDef()], [b2MakeBox(0.5, 6)])
}

// Dynamic bodies — a mix of boxes and circles, each tagged with a colour.
const bodies  = []

function spawnBox(x, y, colour, halfW = 0.5, halfH = 0.5) {
  const def = b2DefaultBodyDef()
  def.type     = b2_dynamicBody
  def.position = new b2Vec2(x, y)
  const id = b2CreateBody(worldId, [def])
  const shape = b2DefaultShapeDef()
  shape.material.friction = 0.4
  b2CreatePolygonShape(id, [shape], [b2MakeBox(halfW, halfH)])
  b2Body_SetUserData(id, { kind: "box", colour, halfW, halfH })
  bodies.push(id)
}

function spawnCircle(x, y, colour, radius = 0.5) {
  const def = b2DefaultBodyDef()
  def.type     = b2_dynamicBody
  def.position = new b2Vec2(x, y)
  const id = b2CreateBody(worldId, [def])
  const shape = b2DefaultShapeDef()
  shape.material.friction = 0.4
  const c = new b2Circle()
  c.radius = radius
  b2CreateCircleShape(id, [shape], [c])
  b2Body_SetUserData(id, { kind: "circle", colour, radius })
  bodies.push(id)
}

spawnBox(-4, 10, RED)
spawnBox(-2, 11, GREEN, 0.4, 0.6)
spawnCircle(0, 12, BLUE, 0.55)
spawnBox(2, 11, ORANGE, 0.6, 0.4)
spawnCircle(4, 10, PURPLE, 0.45)
spawnCircle(-1, 14, YELLOW)
spawnBox(1, 15, RED, 0.35, 0.35)

let picked = null  // body id currently under the cursor (or being dragged)

while (!WindowShouldClose()) {
  b2World_Step(worldId, 1 / 60, 4)

  // ── Mouse pick: tiny AABB around the cursor in world coords ──────────────
  const m = GetMousePosition()
  const mx = fromScreenX(m.x)
  const my = fromScreenY(m.y)
  const eps = 0.01
  const aabb = new b2AABB(new b2Vec2(mx - eps, my - eps), new b2Vec2(mx + eps, my + eps))

  picked = null
  b2World_OverlapAABB(worldId, aabb, b2DefaultQueryFilter(), (shapeId) => {
    picked = b2Shape_GetBody(shapeId)
    return false   // stop at first hit
  })

  // Dragging — while the button is held over the picked body, teleport it.
  if (picked && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    b2Body_SetTransform(picked, new b2Vec2(mx, my), new b2Rot(1, 0))
    b2Body_SetLinearVelocity(picked, new b2Vec2(0, 0))
  }

  // ── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
  ClearBackground(RAYWHITE)
  DrawRectangle(0, GROUND_PX, SCREEN_W, 30, DARKGRAY)

  for (const id of bodies) {
    /** @type {any} */
    const data = b2Body_GetUserData(id)
    if (!data) continue
    const pos  = b2Body_GetPosition(id)
    const rot  = b2Body_GetRotation(id)
    const px   = toScreenX(pos.x)
    const py   = toScreenY(pos.y)
    const isPicked = (id === picked)

    if (data.kind === "circle") {
      DrawCircleV(new Vector2(px, py), data.radius * SCALE, data.colour)
      if (isPicked) DrawCircleV(new Vector2(px, py), data.radius * SCALE + 3, BLACK)
    } else {
      const w = data.halfW * 2 * SCALE
      const h = data.halfH * 2 * SCALE
      const angleDeg = Math.atan2(rot.s, rot.c) * 180 / Math.PI
      DrawRectanglePro(
        new Rectangle(px, py, w, h),
        new Vector2(w / 2, h / 2),
        angleDeg, data.colour,
      )
      if (isPicked) {
        DrawRectanglePro(
          new Rectangle(px, py, w + 6, h + 6),
          new Vector2((w + 6) / 2, (h + 6) / 2),
          angleDeg, BLACK,
        )
        // Redraw the body on top of the outline.
        DrawRectanglePro(
          new Rectangle(px, py, w, h),
          new Vector2(w / 2, h / 2),
          angleDeg, data.colour,
        )
      }
    }
  }

  DrawText("Hover to pick - hold LMB to drag", 12, 12, 18, BLACK)
  DrawText(picked ? "picked: yes" : "picked: -", 12, 36, 16, DARKGRAY)
  EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
