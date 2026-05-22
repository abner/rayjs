import {
  InitWindow, CloseWindow, WindowShouldClose,
  BeginDrawing, EndDrawing, ClearBackground,
  BeginMode2D, EndMode2D,
  DrawTextureRec, DrawText, DrawFPS,
  GetFrameTime, IsKeyDown, IsKeyPressed,
  GetColor, SetTargetFPS,
  KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_SPACE,
  Camera2D, Rectangle, Vector2,
  WHITE, RAYWHITE, BLUE,
} from "rayjs:raylib"
import {
  loadTiledMap, updateTiledMap, drawTiledMap, unloadTiledMap,
  getTiledObjects, checkCollisionTiledLayer,
} from "rayjs:ext:tiled"

const SCREEN_W     = 1280
const SCREEN_H     = 640
const PLAYER_SPEED = 220   // px/s horizontal
const JUMP_VEL     = -480  // px/s initial jump
const GRAVITY      = 900   // px/s²

// 3rd tall sprite (64×128) from row 6 of the image.
// Row 6 starts at y = 5×64 = 320; tall sprites start at col 5 (x=320).
const PLAYER_SRC = new Rectangle(448, 320, 64, 128)
const PW = PLAYER_SRC.width
const PH = PLAYER_SRC.height

InitWindow(SCREEN_W, SCREEN_H, "rayjs - Tiled map")
SetTargetFPS(60)

const map  = loadTiledMap("resources/map.tmj")
const mapW = map.width  * map.tilewidth
const mapH = map.height * map.tileheight

const spawn = getTiledObjects(map, "Objects").find(o => o.type === "spawn")
let playerX  = spawn ? spawn.x : 64
let playerY  = spawn ? spawn.y : mapH - map.tileheight * 3 - PH
let velY     = 0
let onGround = false

const camera = new Camera2D(
  new Vector2(SCREEN_W / 2, SCREEN_H / 2),
  new Vector2(playerX + PW / 2, mapH / 2),
  0, 1,
)

while (!WindowShouldClose()) {
  const dt = GetFrameTime()

  // --- Horizontal movement ---
  let moveX = 0
  if (IsKeyDown(KEY_LEFT))  moveX = -PLAYER_SPEED
  if (IsKeyDown(KEY_RIGHT)) moveX =  PLAYER_SPEED

  playerX += moveX * dt
  playerX  = Math.max(0, Math.min(mapW - PW, playerX))

  // Resolve X against solid tiles (use a vertically inset rect to avoid sticking on wall tops).
  const rxRect = new Rectangle(playerX, playerY + 2, PW, PH - 4)
  const hx = checkCollisionTiledLayer(map, "Ground", rxRect)
  if (hx.hit) {
    if (moveX > 0) playerX = hx.tileRect.x - PW
    else           playerX = hx.tileRect.x + hx.tileRect.width
  }

  // --- Jump ---
  if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && onGround) {
    velY = JUMP_VEL
    onGround = false
  }

  // --- Gravity + vertical movement ---
  velY    += GRAVITY * dt
  playerY += velY * dt

  // Clamp vertically to map.
  playerY = Math.min(mapH - PH, playerY)

  // Resolve Y against solid tiles (use a horizontally inset rect to avoid sticking on wall sides).
  onGround = false
  const ryRect = new Rectangle(playerX + 2, playerY, PW - 4, PH)
  const hy = checkCollisionTiledLayer(map, "Ground", ryRect)
  if (hy.hit) {
    if (velY >= 0) {
      playerY  = hy.tileRect.y - PH
      velY     = 0
      onGround = true
    } else {
      playerY = hy.tileRect.y + hy.tileRect.height
      velY    = 0
    }
  }

  // Camera follows player horizontally, locked vertically.
  camera.target.x = playerX + PW / 2

  updateTiledMap(map, dt)

  // --- Draw ---
  BeginDrawing()
    if (map.backgroundcolor) {
      const hex = parseInt(map.backgroundcolor.slice(1), 16)
      ClearBackground(GetColor((hex << 8) | 0xff))
    } else {
      ClearBackground(RAYWHITE)
    }

    BeginMode2D(camera)
      drawTiledMap(map, 0, 0, WHITE)
      DrawTextureRec(map.tilesets[0].texture, PLAYER_SRC, new Vector2(playerX, playerY), WHITE)
    EndMode2D()

    DrawFPS(8, 8)
    DrawText(
      `x:${Math.floor(playerX)} y:${Math.floor(playerY)}  ${onGround ? "grounded" : "airborne"}`,
      8, 28, 14, BLUE,
    )
  EndDrawing()
}

unloadTiledMap(map)
CloseWindow()
