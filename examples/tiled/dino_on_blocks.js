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
//   ↓ / S         duck (hold)
//   T             toggle dino sprite scale (2x ↔ 4x)

import {
  InitWindow, CloseWindow, WindowShouldClose,
  BeginDrawing, EndDrawing, ClearBackground,
  BeginMode2D, EndMode2D,
  DrawTexturePro, DrawText, DrawFPS,
  GetColor, GetFrameTime,
  IsKeyDown, IsKeyPressed, SetTargetFPS,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_SPACE,
  KEY_A, KEY_D, KEY_S, KEY_T,
  Camera2D, Rectangle, Vector2,
  WHITE, RAYWHITE, BLUE, DARKGRAY,
} from "rayjs:raylib"
import {
  loadTiledMap, updateTiledMap, drawTiledMap, unloadTiledMap,
  getTiledObjects, checkCollisionTiledLayer,
} from "rayjs:ext:tiled"

// Local prettifier for the raylib Color so `console.log(color)` prints
// something readable instead of just enumerating r/g/b/a. We reach the
// Color class via any existing instance's constructor (WHITE here) to
// avoid having to also import the class name from rayjs:raylib.
WHITE.constructor.prototype.toString = function () {
  const h = (n) => n.toString(16).padStart(2, "0")
  return `Color(r=${this.r}, g=${this.g}, b=${this.b}, a=${this.a}` +
         ` #${h(this.r)}${h(this.g)}${h(this.b)}${h(this.a)})`
}

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

let hasLoggedMapBgColor = false

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
// 15th sprite (0-indexed = 14) shows the dino upright with legs tucked —
// the closest match in this sheet to an "in the air" pose. Requires the
// dino tileset in the .tmj to expose at least 15 frames (columns >= 15).
const JUMP_LOCAL_ID = 14
// Frames 17-22 are the duck-run cycle; frame 23 is the static crouch idle.
// (Including the idle pose in the run cycle introduced a visible twitch each
// loop, so it's used only when the player isn't moving while ducked.)
const DUCK_LOCAL_ID = 23
const DUCK_WALK_FRAMES   = [17, 18, 19, 20, 21, 22]
const DUCK_FRAME_SECONDS = 0.08
// Movement while ducked is slowed so the duck pose reads as cautious.
const DUCK_SPEED_FRAC = 0.4

// Visible dino body fills only the bottom-center of its sprite tile — the
// rest is transparent padding (head spikes, side margins). Using the full
// sprite rect for physics makes the character "stand on air" at platform
// edges and bump invisible walls/ceilings near nearby tiles. The hitbox is
// centered horizontally and bottom-aligned within the sprite.
const HITBOX_W_FRAC      = 0.5
const HITBOX_H_FRAC      = 0.8
// Ducked hitbox is short enough that the 4x dino fits under the 1-tile gap
// above the lower platform clusters but the standing hitbox does not — so
// the 4x dino *must* crouch to crawl under those blocks, while the 2x dino
// fits standing either way. 0.4 leaves ~25 px of clearance below the block
// for the 4x dino, comfortably avoiding edge-of-tile sticking.
const HITBOX_H_FRAC_DUCK = 0.4
// The arks dino sheet has a few rows of transparent padding below the
// visible feet, so the sprite-tile bottom sits below the dino's actual feet.
// We keep physics aligned to the sprite tile (so the hitbox bottom = ground
// top), but shift the *visible* draw down by this many tile-fractions to
// make the visible feet rest on the ground. Tweak if the feet still hover
// (raise) or sink into the ground (lower).
const SPRITE_FOOT_PAD_FRAC = 0.15

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
let jumping  = false        // true only when airborne due to an intentional jump
let facing   = 1            // 1 = right, -1 = left
let jumpKeyDown = false
let jumpBuffer  = 0
let duckAnimTime  = 0   // accumulated dt for the ducked walk-cycle
let duckAnimIndex = 0   // index into DUCK_WALK_FRAMES

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
  // Hitbox X dimensions don't depend on the duck state, so compute them
  // first — the auto-stay-ducked probe below needs hbW / hbOffX.
  const hbW    = dinoW * HITBOX_W_FRAC
  const hbOffX = (dinoW - hbW) / 2

  // Ducking is allowed while on the ground or passively falling — but never
  // during an intentional jump (the jump pose / hitbox win there). Allowing
  // duck-through-fall keeps the small hitbox active when the player duck-
  // walks off a ledge: otherwise the hitbox would pop back to the standing
  // size mid-air and snag on any block whose underside is at duck height.
  const wantsDuck = !jumping && (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
  let ducking = wantsDuck
  // If the player releases ↓ while standing under a low block (the standing
  // hitbox would clip the block bottom), keep ducking — otherwise the vertical
  // collision resolve would pop the dino on top of the block. Only checked
  // when the player isn't already requesting duck.
  if (!ducking && onGround) {
    const standH    = dinoH * HITBOX_H_FRAC
    const standOffY = dinoH - standH
    const standProbe = new Rectangle(
      dinoX + hbOffX + 2, dinoY + standOffY + 2, hbW - 4, standH - 4,
    )
    if (checkCollisionTiledLayer(map, "Ground", standProbe).hit) ducking = true
  }
  const speed = ducking ? PLAYER_SPEED * DUCK_SPEED_FRAC : PLAYER_SPEED
  let moveX = 0
  if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) { moveX = -speed; facing = -1 }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { moveX =  speed; facing =  1 }

  // Advance the ducked walk-cycle only while the player is actually moving
  // while ducked; reset it otherwise so the next duck-walk begins on frame 0.
  if (ducking && moveX !== 0) {
    duckAnimTime += dt
    while (duckAnimTime >= DUCK_FRAME_SECONDS) {
      duckAnimTime  -= DUCK_FRAME_SECONDS
      duckAnimIndex  = (duckAnimIndex + 1) % DUCK_WALK_FRAMES.length
    }
  } else {
    duckAnimTime  = 0
    duckAnimIndex = 0
  }

/*
┌─────────────────────────┬─────────────────────────────────┬──────────────────────────────┐
│          State          │             Trigger             │            Sprite            │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ jumping                 │ Press ↑ / SPACE while on ground │ Frame 14 (legs tucked)       │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ ducking, still          │ Hold ↓ / S, no horizontal input │ Frame 23 (crouch idle)       │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ ducking, moving         │ Hold ↓ / S + ← → / A D          │ Crouch walk (frames 17–22)   │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ onGround && moveX === 0 │ Standing still                  │ Frame 3 (idle)               │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ Walking off an edge     │ onGround → false without a jump │ Walk animation continues     │
├─────────────────────────┼─────────────────────────────────┼──────────────────────────────┤
│ Walking on ground       │ onGround && moveX != 0          │ Walk animation (frames 4–9)  │
└─────────────────────────┴─────────────────────────────────┴──────────────────────────────┘

 > jumping is set only by the intentional jump path and cleared on landing.
   Walking off a platform edge transitions onGround to false via the ground probe
   without ever setting jumping, so the walk cycle keeps playing through the brief fall.
 > ducking disables jumps and slows horizontal speed (× DUCK_SPEED_FRAC). When the player
   releases ↓ underneath a low block, the auto-stay-ducked probe keeps ducking true so
   the vertical-resolve doesn't teleport the dino on top of the block.
 > ducking persists through passive falls (walked off an edge while ↓ held) so the small
   hitbox doesn't snag on overhead blocks mid-fall. Intentional jumps still suppress it.
 > The upright walk cycle (4–9) is .tmj-animated via tiles[0].animation; the duck-run
   cycle (17–22) is timed manually here using DUCK_FRAME_SECONDS.
*/
  const jumpHeld = IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)
  const jumpTriggered = jumpHeld && !jumpKeyDown
  jumpKeyDown = jumpHeld
  jumpBuffer = Math.max(0, jumpBuffer - dt)
  if (jumpTriggered) jumpBuffer = 0.12
  if (jumpBuffer > 0 && onGround && !ducking) {
    velY = JUMP_VEL
    onGround = false
    jumping  = true
    jumpBuffer = 0
  }

  // Hitbox H depends on duck state — shrunk while ducked so the 4x dino fits
  // under the 1-tile gap above the lower platform clusters. (hbW / hbOffX
  // were computed above so the auto-stay-ducked probe could use them.)
  // Inset by 2px on the cross-axis (per axis-resolve step) to avoid the
  // corner of one rect catching the edge of a tile during the other axis.
  const hbH    = dinoH * (ducking ? HITBOX_H_FRAC_DUCK : HITBOX_H_FRAC)
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
  // Apply gravity only when airborne — otherwise sub-pixel drift each
  // frame (velY * dt accumulates, then collision snaps back) makes the
  // sprite visibly shake while standing still.
  if (!onGround) velY += GRAVITY * dt
  dinoY   += velY * dt
  dinoY    = Math.min(mapH - dinoH, dinoY)

  const ryRect = new Rectangle(dinoX + hbOffX + 2, dinoY + hbOffY, hbW - 4, hbH)
  const hy = checkCollisionTiledLayer(map, "Ground", ryRect)
  if (hy.hit) {
    if (velY >= 0) {
      dinoY = hy.tileRect.y - dinoH                          // foot flush with tile top
    } else {
      dinoY = hy.tileRect.y + hy.tileRect.height - hbOffY    // hitbox top flush with ceiling
    }
    velY = 0
  }

  // Ground probe: 1px below the hitbox tells us if there is still ground
  // under our feet. Updated AFTER vertical resolution so jumping off the
  // ground (velY < 0) immediately registers as airborne.
  const probeRect = new Rectangle(
    dinoX + hbOffX + 2, dinoY + hbOffY + 1, hbW - 4, hbH,
  )
  onGround = velY >= 0 &&
             checkCollisionTiledLayer(map, "Ground", probeRect).hit
  if (onGround) jumping = false      // landed — clear the jump pose flag

  // ── camera follows horizontally ───────────────────────
  camera.target.x = Math.max(SCREEN_W / 2,
                    Math.min(mapW - SCREEN_W / 2, dinoX + dinoW / 2))

  updateTiledMap(map, dt)        // advance animated-tile timers

  // ── draw ──────────────────────────────────────────────
  BeginDrawing()
    if (map.backgroundcolor) {
      const hex = parseInt(map.backgroundcolor.slice(1), 16)
      const backgroundColor = GetColor((hex << 8) | 0xff);
      if (!hasLoggedMapBgColor) {
        console.log("map bg color:", backgroundColor)
        hasLoggedMapBgColor = true
      }
      ClearBackground(GetColor((hex << 8) | 0xff))
    } else {
      ClearBackground(RAYWHITE)
    }

    BeginMode2D(camera)
      drawTiledMap(map, 0, 0, WHITE)

      // Pose priority:
      //   jumping (intentional, airborne) → JUMP frame
      //   ducking + moving                → DUCK-walk cycle (frames 17–22)
      //   ducking + still                 → DUCK-idle frame (17)
      //   on the ground, no input         → IDLE frame
      //   otherwise (walking, or falling
      //   passively off an edge)          → let the walk-cycle animation play
      const overrideLocalId =
        jumping                            ? JUMP_LOCAL_ID
        : (ducking && moveX !== 0)         ? DUCK_WALK_FRAMES[duckAnimIndex]
        : ducking                          ? DUCK_LOCAL_ID
        : (onGround && moveX === 0)        ? IDLE_LOCAL_ID
        : undefined
      const tile = currentSrcRect(map, dinoGid, overrideLocalId)
      if (tile) {
        const src = tile.srcRect
        // Mirror by negating source width (raylib convention).
        const mirroredSrc = new Rectangle(
          src.x, src.y, src.width * facing, src.height,
        )
        // Visual-only shift: pushes the sprite down so the dino's visible
        // feet sit on the ground top. Physics/hitbox still use the unshifted
        // dinoY, so collision and ground probe remain tile-aligned.
        const drawDy = dinoH * SPRITE_FOOT_PAD_FRAC
        DrawTexturePro(
          tile.texture,
          mirroredSrc,
          new Rectangle(dinoX, dinoY + drawDy, dinoW, dinoH),
          new Vector2(0, 0), 0, WHITE,
        )
      }
    EndMode2D()

    DrawFPS(8, 8)
    DrawText(`scale: ${currentScale}    [T] toggle 2x / 4x`, 8, 28, 16, DARKGRAY)
    DrawText("← → / A D move    ↑ / SPACE jump    ↓ / S duck", 8, 48, 14, BLUE)
  EndDrawing()
}

unloadTiledMap(map)
CloseWindow()
