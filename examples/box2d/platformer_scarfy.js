/*******************************************************************************************
*
*   rayjs [box2d] example - Boy platformer (Box2D physics + Tiled world)
*
*   Companion examples:
*     - examples/box2d/hello_physics.js   (minimal Box2D: one ball, one ground)
*     - examples/tiled/tiled_map.js       (same map.tmj, manual AABB physics)
*
*   This example demonstrates:
*     - Building a static collision world from a Tiled tile layer
*     - A dynamic body with fixed rotation as a character controller,
*       driven by velocity overwrite (not forces) for snappy platforming
*     - Ground detection via b2World_CastRay (short downward ray from feet)
*     - Coin pickup via b2World_GetSensorEvents (sensor begin-event each step)
*     - Dynamic crates rendered with body rotation
*
*   Player sprite: boy.webp, a 4×4 sheet of 64×64 frames.
*     Row 0: idle / facing camera     Row 1: walking left
*     Row 2: walking right            Row 3: facing away
*   Only rows 1 (left) and 2 (right) are used in this demo.
*
*   Controls: ←/→ or A/D move,  Space/↑/W jump,  1/2 small/large player,
*             R reset,  F1 debug,  Esc quit
*
********************************************************************************************/

import {
  InitWindow, CloseWindow, WindowShouldClose, SetTargetFPS, GetFrameTime,
  BeginDrawing, EndDrawing, ClearBackground,
  BeginMode2D, EndMode2D,
  LoadTexture, UnloadTexture,
  DrawTexturePro, DrawRectanglePro, DrawText, DrawFPS, DrawCircle, DrawRectangleLines, DrawLine,
  IsKeyDown, IsKeyPressed,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_SPACE, KEY_A, KEY_D, KEY_W, KEY_R, KEY_F1,
  KEY_ONE, KEY_TWO,
  Camera2D, Rectangle, Vector2,
  SKYBLUE, WHITE, BLACK, YELLOW, RED, GREEN, GOLD, DARKGRAY, LIME, BROWN,
} from "rayjs:raylib"

import {
  b2CreateWorld, b2DestroyWorld, b2DefaultWorldDef, b2World_Step,
  b2CreateBody, b2DefaultBodyDef, b2_dynamicBody,
  b2CreatePolygonShape, b2CreateCircleShape, b2MakeBox,
  b2DefaultShapeDef, b2DefaultQueryFilter,
  b2Body_GetPosition, b2Body_GetRotation,
  b2Body_GetLinearVelocity, b2Body_SetLinearVelocity,
  b2World_CastRay, b2World_GetSensorEvents, b2StoreShapeId,
  b2Vec2, b2Circle,
} from "rayjs:box2d"

import {
  loadTiledMap, unloadTiledMap, drawTiledMap, updateTiledMap,
  getTiledLayer, getTiledObjects,
} from "rayjs:ext:tiled"

// ─── Tunables ────────────────────────────────────────────────────────────────
const SCREEN_W       = 1280
const SCREEN_H       = 640
const PPM            = 64        // 1 tile = 1 metre; keeps Tiled ↔ Box2D math trivial
// Two player-size profiles, switchable at runtime with the 1 / 2 keys.
// Each profile pairs a rendered sprite size with a matching collider so the
// AABB still tracks the visible character inside the frame. Switching emits
// a world rebuild (same path as R-reset) so the new collider takes effect.
// Source frames are 128×128; raylib's default point filter keeps the downscale
// crisp at any integer-ish render size.
const SIZES = {
  small: { spriteW: 64, spriteH: 64, halfW: 0.25, halfH: 0.35 },
  large: { spriteW: 96, spriteH: 96, halfW: 0.40, halfH: 0.55 },
}
let currentSize = SIZES.large
const PLAYER_SPEED   = 6         // m/s
const JUMP_VEL       = 11        // m/s, positive = up (Box2D Y is up)
const GRAVITY_Y      = -25       // m/s² — punchier than default −10 for sprite-scale worlds
const CRATE_HALF     = 0.45      // 0.9 m × 0.9 m crate
const ANIM_FPS       = 8         // boy walk cycle is shorter (4 frames) than scarfy's (6)
const ANIM_FRAMES    = 4         // frames per row in boy.webp
const ROW_LEFT       = 1         // boy.webp row index for "walking left" frames
const ROW_RIGHT      = 2         // boy.webp row index for "walking right" frames
const CAST_DOWN      = 0.18      // ray length below feet (m) for ground detection

// Crates are drawn as plain coloured rectangles to keep the demo independent of
// guessing a tile slot in platformTilesheet.png. To use a tilesheet sprite instead,
// pick a src rect and swap the DrawRectanglePro call below for DrawTexturePro.

// ─── Boot ────────────────────────────────────────────────────────────────────
InitWindow(SCREEN_W, SCREEN_H, "rayjs - Box2D platformer (Boy + Tiled)")
SetTargetFPS(60)

// boy.webp is the source asset; raylib's built-in image loader doesn't include
// WebP (needs libwebp as an extra dependency), so we load a PNG copy of the
// same sheet — regenerate with: sips -s format png boy.webp --out boy.png
const boyTex  = LoadTexture("./boy.png")
const FRAME_W = boyTex.width  / 4    // 4 columns
const FRAME_H = boyTex.height / 4    // 4 rows

const map        = loadTiledMap("../tiled/resources/map.tmj")
const WORLD_W_M  = map.width                  // 20
const WORLD_H_M  = map.height                 // 10
const WORLD_W_PX = WORLD_W_M * map.tilewidth  // 1280

// Tiled has +Y down; Box2D has +Y up. Convert via the world's height in metres.
const pxToM        = (px) => px / PPM
const tileYToWorld = (yPx) => WORLD_H_M - yPx / PPM
const mToScreenX   = (mx) => mx * PPM
const mToScreenY   = (my) => (WORLD_H_M - my) * PPM

// ─── World construction (also runs on R-reset) ───────────────────────────────
function setupWorld() {
  const worldDef = b2DefaultWorldDef()
  worldDef.gravity = new b2Vec2(0, GRAVITY_Y)
  const worldId = b2CreateWorld([worldDef])

  // 1) Static ground — merge horizontal runs of solid tiles in each row into a single
  //    wide static box. Naively making one box per tile causes the player's leading-
  //    bottom corner to snag on the vertical face of the next tile when crossing a
  //    seam — a classic Box2D "internal edge" / tile-seam artefact. Merging eliminates
  //    those internal seams entirely.
  const groundLayer = getTiledLayer(map, "Ground")
  const gdata = groundLayer.data
  const lw    = groundLayer.width
  const lh    = groundLayer.height
  for (let row = 0; row < lh; row++) {
    let col = 0
    while (col < lw) {
      if (!gdata[row * lw + col]) { col++; continue }
      const runStart = col
      while (col < lw && gdata[row * lw + col]) col++
      const runLen = col - runStart
      const def = b2DefaultBodyDef()
      def.position = new b2Vec2(runStart + runLen / 2, WORLD_H_M - (row + 0.5))
      const id = b2CreateBody(worldId, [def])
      b2CreatePolygonShape(id, [b2DefaultShapeDef()], [b2MakeBox(runLen / 2, 0.5)])
    }
  }

  // 1b) Invisible boundary walls — keep the player (and crates) inside the
  //     visible map. The walls are positioned so the *sprite*, not just the
  //     body, stays fully on screen: the player's collider stops at
  //     currentSize.spriteW / 2 from each map edge, which is where the centred
  //     sprite would otherwise begin leaving the viewport. Wall bodies sit
  //     just outside the visible map so they never render.
  const SPRITE_HALF_M = (currentSize.spriteW / 2) / PPM
  for (const side of [-1, 1]) {
    const wallRightFaceX = side < 0
      ? SPRITE_HALF_M - currentSize.halfW           // left wall's right face
      : WORLD_W_M - SPRITE_HALF_M + currentSize.halfW   // right wall's left face
    const def = b2DefaultBodyDef()
    def.position = new b2Vec2(
      wallRightFaceX + side * 0.5,              // wall centre, half-width 0.5 m
      WORLD_H_M / 2,
    )
    const id = b2CreateBody(worldId, [def])
    b2CreatePolygonShape(id, [b2DefaultShapeDef()], [b2MakeBox(0.5, WORLD_H_M / 2 + 2)])
  }

  // 2) Player — dynamic body at the Tiled "spawn" point.
  const objects = getTiledObjects(map, "Objects")
  const spawn = objects.find(o => o.type === "spawn") ?? { x: 64, y: 320, width: 64, height: 64 }
  const playerDef = b2DefaultBodyDef()
  playerDef.type          = b2_dynamicBody
  playerDef.fixedRotation = true
  playerDef.position      = new b2Vec2(
    pxToM(spawn.x + spawn.width / 2),
    tileYToWorld(spawn.y + spawn.height / 2),
  )
  const playerId = b2CreateBody(worldId, [playerDef])
  const playerShape = b2DefaultShapeDef()
  playerShape.density              = 1.0
  // Friction = 0 on the player itself so we don't stick to walls during jumps.
  // The velocity-overwrite keeps vx = ±PLAYER_SPEED every frame, which would
  // otherwise create a sustained "push into wall" → vertical friction that
  // brakes the jump and freezes the character mid-air. Zero friction here means
  // the wall contact resolves purely via the normal impulse and the player
  // slides freely upward along it. Crates still get pushed (normal impulse).
  playerShape.material.friction    = 0.0
  playerShape.material.restitution = 0.0
  b2CreatePolygonShape(playerId, [playerShape], [b2MakeBox(currentSize.halfW, currentSize.halfH)])

  // 3) Dynamic crates — scripted positions over the floor, all 1 m × 1 m boxes.
  const crateSpawns = [
    { x: 6.5,  y: 4.5 },
    { x: 7.5,  y: 4.5 },
    { x: 11.5, y: 4.5 },
    { x: 15.5, y: 4.5 },
  ]
  const crates = crateSpawns.map(({ x, y }) => {
    const def = b2DefaultBodyDef()
    def.type     = b2_dynamicBody
    def.position = new b2Vec2(x, y)
    const id = b2CreateBody(worldId, [def])
    const shape = b2DefaultShapeDef()
    shape.density              = 0.6
    shape.material.friction    = 0.5
    shape.material.restitution = 0.05
    b2CreatePolygonShape(id, [shape], [b2MakeBox(CRATE_HALF, CRATE_HALF)])
    return { bodyId: id }
  })

  // 4) Coins — static sensor shape per Tiled "pickup" object. Sensor begin-events
  //    are fired into the per-step event list; we map them back to coin index via
  //    the stored shape id (a BigInt that round-trips through Map keys with ===).
  const coins           = []
  const coinByShapeKey  = new Map()
  for (const obj of objects.filter(o => o.type === "pickup")) {
    const def = b2DefaultBodyDef()
    def.position = new b2Vec2(
      pxToM(obj.x + obj.width / 2),
      tileYToWorld(obj.y + obj.height / 2),
    )
    const id = b2CreateBody(worldId, [def])
    const shape = b2DefaultShapeDef()
    shape.isSensor           = true
    shape.enableSensorEvents = true
    const circle = new b2Circle()
    circle.radius = 0.3
    const shapeId = b2CreateCircleShape(id, [shape], [circle])
    coinByShapeKey.set(b2StoreShapeId(shapeId), coins.length)
    coins.push({ x: def.position.x, y: def.position.y, collected: false })
  }

  return { worldId, playerId, crates, coins, coinByShapeKey, coinCount: 0 }
}

let state = setupWorld()

// ─── Per-frame state (lives across resets) ───────────────────────────────────
let grounded   = false
let facingLeft = false
let animFrame  = 0
let animTimer  = 0
let debugDraw  = false
let rayHitPt   = null        // last ground-cast hit, for debug viz

const camera = new Camera2D(
  new Vector2(SCREEN_W / 2, SCREEN_H / 2),
  new Vector2(SCREEN_W / 2, SCREEN_H / 2),
  0, 1,
)

// ─── Main loop ───────────────────────────────────────────────────────────────
while (!WindowShouldClose()) {
  const dt = GetFrameTime()

  if (IsKeyPressed(KEY_R))  { b2DestroyWorld(state.worldId); state = setupWorld(); grounded = false; animFrame = 0; animTimer = 0 }
  if (IsKeyPressed(KEY_F1)) { debugDraw = !debugDraw }
  // Switch player size. Triggers a rebuild because the new collider extents
  // need to take effect; the simplest path is the same destroy + setupWorld
  // dance as R-reset.
  if (IsKeyPressed(KEY_ONE) && currentSize !== SIZES.small) {
    currentSize = SIZES.small
    b2DestroyWorld(state.worldId); state = setupWorld(); grounded = false; animFrame = 0; animTimer = 0
  }
  if (IsKeyPressed(KEY_TWO) && currentSize !== SIZES.large) {
    currentSize = SIZES.large
    b2DestroyWorld(state.worldId); state = setupWorld(); grounded = false; animFrame = 0; animTimer = 0
  }

  // Step physics (fixed timestep regardless of frame dt — simpler, plenty good for a demo)
  b2World_Step(state.worldId, 1 / 60, 4)
  updateTiledMap(map, dt)

  const pos = b2Body_GetPosition(state.playerId)

  // ─── Ground detection: short downward CastRay from just above the feet ─────
  // The origin sits a hair inside the body to tolerate solver penetration. The
  // callback returns 1 on non-ground hits (player's own bottom face from the
  // inside has normal.y = -1; walls/ceilings have |normal.y| ≤ 0.5) so the
  // cast keeps looking — otherwise terminating at a non-ground hit would mask
  // the real ground sitting just past it. This case matters when the player
  // stands on a dynamic body (e.g. a crate) where shape-iteration order can
  // surface the player's own shape before the supporting body.
  const feetOrigin = new b2Vec2(pos.x, pos.y - currentSize.halfH + 0.05)
  const rayDelta   = new b2Vec2(0, -CAST_DOWN)
  grounded = false
  rayHitPt = null
  b2World_CastRay(state.worldId, feetOrigin, rayDelta, b2DefaultQueryFilter(),
    (shapeId, point, normal, fraction) => {
      if (normal.y > 0.5) {
        grounded = true
        rayHitPt = { x: point.x, y: point.y }
        return 0       // real ground — stop here
      }
      return 1         // not ground — skip past and keep looking
    })

  // ─── Sensor events: drain begin-touch list, flip matching coin to collected ─
  const events = b2World_GetSensorEvents(state.worldId)
  for (const e of events.beginEvents) {
    const idx = state.coinByShapeKey.get(b2StoreShapeId(e.sensorShapeId))
    if (idx !== undefined && !state.coins[idx].collected) {
      state.coins[idx].collected = true
      state.coinCount++
    }
  }

  // ─── Input → velocity overwrite (snappy platformer feel) ───────────────────
  let inputX = 0
  if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) inputX -= 1
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) inputX += 1
  if      (inputX < 0) facingLeft = true
  else if (inputX > 0) facingLeft = false

  const vel    = b2Body_GetLinearVelocity(state.playerId)
  let   nextVy = vel.y
  if (grounded && (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))) {
    nextVy = JUMP_VEL
  }
  b2Body_SetLinearVelocity(state.playerId, new b2Vec2(inputX * PLAYER_SPEED, nextVy))

  // ─── Sprite animation: advance frame while moving on the ground ────────────
  if (Math.abs(inputX) > 0 && grounded) {
    animTimer += dt
    if (animTimer >= 1 / ANIM_FPS) {
      animTimer = 0
      animFrame = (animFrame + 1) % ANIM_FRAMES
    }
  } else {
    animFrame = 0
    animTimer = 0
  }

  // Camera follows player horizontally, clamped so it never reveals past the map edges.
  const playerScreenX = mToScreenX(pos.x)
  camera.target.x = Math.max(SCREEN_W / 2, Math.min(WORLD_W_PX - SCREEN_W / 2, playerScreenX))

  // ─── Draw ─────────────────────────────────────────────────────────────────
  BeginDrawing()
    ClearBackground(SKYBLUE)

    BeginMode2D(camera)
      drawTiledMap(map, 0, 0, WHITE)

      // Coins (uncollected only) — drawn as concentric circles for a cheap "shiny" look.
      for (const coin of state.coins) {
        if (coin.collected) continue
        const cx = mToScreenX(coin.x)
        const cy = mToScreenY(coin.y)
        DrawCircle(cx, cy, 14, GOLD)
        DrawCircle(cx, cy,  9, YELLOW)
      }

      // Crates — rotation comes from each body's b2Rot (cosine, sine). Drawn as a
      // brown rectangle with a darker outline; rotation pivots around the centre.
      for (const crate of state.crates) {
        const cp = b2Body_GetPosition(crate.bodyId)
        const cr = b2Body_GetRotation(crate.bodyId)
        const angleDeg = Math.atan2(cr.s, cr.c) * 180 / Math.PI
        const sidePx   = CRATE_HALF * 2 * PPM
        DrawRectanglePro(
          new Rectangle(mToScreenX(cp.x), mToScreenY(cp.y), sidePx, sidePx),
          new Vector2(sidePx / 2, sidePx / 2),
          angleDeg, BROWN,
        )
        // Outline: draw a slightly smaller darker rectangle on top? Skipped — a
        // single fill keeps the example minimal and reads clearly against SKYBLUE.
      }

      // Boy — anchored at his feet so the visual bottom aligns with the body's
      // collision bottom (sprite_feet = body_bottom = body.y - currentSize.halfH).
      // Direction comes from the *row* in boy.webp, not a horizontal flip: row 1
      // has left-facing frames, row 2 right-facing.
      const px = mToScreenX(pos.x)
      const py = mToScreenY(pos.y)
      const feetScreenY = mToScreenY(pos.y - currentSize.halfH)
      const src = new Rectangle(
        animFrame * FRAME_W,
        (facingLeft ? ROW_LEFT : ROW_RIGHT) * FRAME_H,
        FRAME_W,
        FRAME_H,
      )
      DrawTexturePro(
        boyTex, src,
        new Rectangle(px, feetScreenY, currentSize.spriteW, currentSize.spriteH),
        new Vector2(currentSize.spriteW / 2, currentSize.spriteH),   // origin = bottom-centre
        0, WHITE,
      )

      if (debugDraw) {
        // Player AABB
        const phw = currentSize.halfW * PPM
        const phh = currentSize.halfH * PPM
        DrawRectangleLines(px - phw, py - phh, phw * 2, phh * 2, LIME)
        // Ground cast ray (green when grounded, red otherwise)
        const oX = mToScreenX(feetOrigin.x)
        const oY = mToScreenY(feetOrigin.y)
        const eY = mToScreenY(feetOrigin.y + rayDelta.y)
        DrawLine(oX, oY, oX, eY, rayHitPt ? GREEN : RED)
        // Crate axis-aligned bounding boxes (a generous over-approximation of the rotated box)
        for (const crate of state.crates) {
          const cp  = b2Body_GetPosition(crate.bodyId)
          const cr  = b2Body_GetRotation(crate.bodyId)
          const ext = CRATE_HALF * PPM * (Math.abs(cr.c) + Math.abs(cr.s))
          DrawRectangleLines(mToScreenX(cp.x) - ext, mToScreenY(cp.y) - ext, ext * 2, ext * 2, RED)
        }
      }
    EndMode2D()

    // HUD
    DrawFPS(8, 8)
    DrawText(`Coins: ${state.coinCount} / ${state.coins.length}`, 8, 30, 18, BLACK)
    DrawText(`grounded: ${grounded ? "yes" : "no"}`, 8, 52, 14, DARKGRAY)
    DrawText("←/→ or A/D move    Space/↑/W jump    1/2 size    R reset    F1 debug",
             8, SCREEN_H - 26, 16, BLACK)
  EndDrawing()
}

b2DestroyWorld(state.worldId)
unloadTiledMap(map)
UnloadTexture(boyTex)
CloseWindow()
