// Dino on Blocks — a small platformer using a Tiled map whose ground layer
// borrows the platformTilesheet blocks and whose object layer holds a single
// "spawn" point for an animated dino character.
//
// The dino's 14-frame animation is defined inside the dino tileset's
// `tiles[0].animation` array in the .tmj file. The lib auto-advances animated
// tiles on tile layers; for tile objects (which the lib does not auto-draw),
// the example consults map._animState to substitute the current frame.
//
// Controls:
//   ← → / A D     move
//   ↑ / SPACE     jump
//   T             toggle dino sprite scale (2x ↔ 4x)

import {
  InitWindow, CloseWindow, WindowShouldClose,
  BeginDrawing, EndDrawing, ClearBackground,
  BeginMode2D, EndMode2D,
  DrawTexturePro, DrawText, DrawFPS,
  GetColor, GetFrameTime,
  IsKeyDown, IsKeyPressed, SetTargetFPS,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_SPACE, KEY_A, KEY_D, KEY_T,
  Camera2D, Rectangle, Vector2,
  WHITE, RAYWHITE, BLUE, DARKGRAY,
} from "rayjs:raylib"
import {
  loadTiledMap, updateTiledMap, drawTiledMap, unloadTiledMap,
  getTiledObjects, checkCollisionTiledLayer,
} from "rayjs:ext:tiled"

const SCREEN_W     = 1280
const SCREEN_H     = 640
const PLAYER_SPEED = 220   // px/s
const JUMP_VEL     = -620
const GRAVITY      = 900

// generated map with sprite from https://arks.itch.io/dino-characters
const MAP_PATHS = {
  "2x": "resources/dino_on_blocks_2x.tmj",
  "4x": "resources/dino_on_blocks_4x.tmj",
}

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Dino on Blocks")
SetTargetFPS(60)

/** @param {any[]} tilesets @param {number} gid */
function tilesetForGid(tilesets, gid) {
  for (let i = tilesets.length - 1; i >= 0; i--) {
    if (tilesets[i].firstgid <= gid) return tilesets[i]
  }
  return null
}

// Resolve a GID to a source rectangle. If `overrideLocalId` is given, that
// frame is used directly; otherwise the lib's animation state for `gid` is
// consulted (this mirrors what _drawTileLayer does internally for tile-layer
// cells — needed here because tile objects are not auto-drawn by the lib).
/** @param {any} map @param {number} gid @param {number} [overrideLocalId] */
function currentSrcRect(map, gid, overrideLocalId) {
  const ts = tilesetForGid(map.tilesets, gid)
  if (!ts) return null
  let localId
  if (overrideLocalId !== undefined) {
    localId = overrideLocalId
  } else {
    localId = gid - ts.firstgid
    const anim = map._animState[gid]
    if (anim) {
      const frames = ts.animations[localId]
      if (frames) localId = frames[anim.frameIndex].tileid
    }
  }
  const col = localId % ts.columns
  const row = Math.floor(localId / ts.columns)
  return {
    texture: ts.texture,
    srcRect: new Rectangle(col * ts.tilewidth,  row * ts.tileheight,
                           ts.tilewidth, ts.tileheight),
  }
}

// 4th sprite (0-indexed = 3) is the standing/idle pose.
const IDLE_LOCAL_ID = 3

// Visible dino body fills only the bottom-center of its sprite tile — the
// rest is transparent padding (head spikes, side margins). Using the full
// sprite rect for physics makes the character "stand on air" at platform
// edges and bump invisible walls/ceilings near nearby tiles. The hitbox is
// centered horizontally and bottom-aligned within the sprite.
const HITBOX_W_FRAC = 0.5
const HITBOX_H_FRAC = 0.8

// jumping next to a platform side should now work, and walking 
// past a platform edge should drop you cleanly. 
// If 0.5 / 0.8 feels too generous (the dino slides too far off edges before falling) 
// tighten them to 0.4 / 0.85; 
// if it feels too tight (he falls when he visually shouldn't) widen to 0.6 / 0.75.

let currentScale = "2x"
let map = loadTiledMap(MAP_PATHS[currentScale])
let mapW = map.width  * map.tilewidth
let mapH = map.height * map.tileheight

// Dino state. Tile-object x/y is bottom-left; convert to top-left for physics.
let spawn = getTiledObjects(map, "Objects").find(o => o.type === "spawn")
let dinoGid = spawn.gid
let dinoW   = spawn.width
let dinoH   = spawn.height
let dinoX   = spawn.x
let dinoY   = spawn.y - dinoH
let velY    = 0
let onGround = false
let facing   = 1            // 1 = right, -1 = left
let jumpKeyDown = false
let jumpBuffer  = 0

const camera = new Camera2D(
  new Vector2(SCREEN_W / 2, SCREEN_H / 2),
  new Vector2(dinoX + dinoW / 2, mapH / 2),
  0, 1,
)

function swapMap() {
  // Preserve the dino's normalized world position (as a fraction of map size).
  const fx = (dinoX + dinoW / 2) / mapW
  const fy = (dinoY + dinoH / 2) / mapH

  unloadTiledMap(map)
  currentScale = currentScale === "2x" ? "4x" : "2x"
  map  = loadTiledMap(MAP_PATHS[currentScale])
  mapW = map.width  * map.tilewidth
  mapH = map.height * map.tileheight

  spawn   = getTiledObjects(map, "Objects").find(o => o.type === "spawn")
  dinoGid = spawn.gid
  dinoW   = spawn.width
  dinoH   = spawn.height
  // Keep the player at roughly the same spot when toggling scales.
  dinoX = fx * mapW - dinoW / 2
  dinoY = fy * mapH - dinoH / 2
  velY  = 0
}

while (!WindowShouldClose()) {
  const dt = GetFrameTime()

  if (IsKeyPressed(KEY_T)) swapMap()

  // ── input ──────────────────────────────────────────────
  let moveX = 0
  if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) { moveX = -PLAYER_SPEED; facing = -1 }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { moveX =  PLAYER_SPEED; facing =  1 }

  const jumpHeld = IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)
  const jumpTriggered = jumpHeld && !jumpKeyDown
  jumpKeyDown = jumpHeld
  jumpBuffer = Math.max(0, jumpBuffer - dt)
  if (jumpTriggered) jumpBuffer = 0.12
  if (jumpBuffer > 0 && onGround) {
    velY = JUMP_VEL
    onGround = false
    jumpBuffer = 0
  }

  // Hitbox derived from the sprite size, centered X, bottom-aligned Y.
  // Inset by 2px on the cross-axis (per axis-resolve step) to avoid the
  // corner of one rect catching the edge of a tile during the other axis.
  const hbW = dinoW * HITBOX_W_FRAC
  const hbH = dinoH * HITBOX_H_FRAC
  const hbOffX = (dinoW - hbW) / 2
  const hbOffY = dinoH - hbH

  // ── horizontal move + resolve ─────────────────────────
  dinoX += moveX * dt
  dinoX  = Math.max(-hbOffX, Math.min(mapW - hbOffX - hbW, dinoX))
  const rxRect = new Rectangle(dinoX + hbOffX, dinoY + hbOffY + 2, hbW, hbH - 4)
  const hx = checkCollisionTiledLayer(map, "Ground", rxRect)
  if (hx.hit) {
    if (moveX > 0)      dinoX = hx.tileRect.x - hbOffX - hbW
    else if (moveX < 0) dinoX = hx.tileRect.x + hx.tileRect.width - hbOffX
  }

  // ── gravity + vertical move + resolve ─────────────────
  velY    += GRAVITY * dt
  dinoY   += velY * dt
  dinoY    = Math.min(mapH - dinoH, dinoY)

  onGround = false
  const ryRect = new Rectangle(dinoX + hbOffX + 2, dinoY + hbOffY, hbW - 4, hbH)
  const hy = checkCollisionTiledLayer(map, "Ground", ryRect)
  if (hy.hit) {
    if (velY >= 0) {
      dinoY    = hy.tileRect.y - dinoH                       // foot still flush with tile top
      velY     = 0
      onGround = true
    } else {
      dinoY = hy.tileRect.y + hy.tileRect.height - hbOffY    // hitbox top flush with ceiling
      velY  = 0
    }
  }

  // ── camera follows horizontally ───────────────────────
  camera.target.x = Math.max(SCREEN_W / 2,
                    Math.min(mapW - SCREEN_W / 2, dinoX + dinoW / 2))

  updateTiledMap(map, dt)        // advance animated-tile timers

  // ── draw ──────────────────────────────────────────────
  BeginDrawing()
    if (map.backgroundcolor) {
      const hex = parseInt(map.backgroundcolor.slice(1), 16)
      ClearBackground(GetColor((hex << 8) | 0xff))
    } else {
      ClearBackground(RAYWHITE)
    }

    BeginMode2D(camera)
      drawTiledMap(map, 0, 0, WHITE)

      // When idle (no horizontal input), pin to the standing sprite — frame 6
      // (the 7th in the sheet). Otherwise let the tileset animation cycle.
      const tile = currentSrcRect(map, dinoGid,
                                  moveX === 0 ? IDLE_LOCAL_ID : undefined)
      if (tile) {
        const src = tile.srcRect
        // Mirror by negating source width (raylib convention).
        const mirroredSrc = new Rectangle(
          src.x, src.y, src.width * facing, src.height,
        )
        DrawTexturePro(
          tile.texture,
          mirroredSrc,
          new Rectangle(dinoX, dinoY, dinoW, dinoH),
          new Vector2(0, 0), 0, WHITE,
        )
      }
    EndMode2D()

    DrawFPS(8, 8)
    DrawText(`scale: ${currentScale}    [T] toggle 2x / 4x`, 8, 28, 16, DARKGRAY)
    DrawText("← → / A D move    ↑ / SPACE jump", 8, 48, 14, BLUE)
  EndDrawing()
}

unloadTiledMap(map)
CloseWindow()
