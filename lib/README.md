# rayjs/lib

Reusable JavaScript modules for rayjs. Import with relative paths — no build step required.

---

## tiled.js — Tiled map loader, renderer & collision

Loads and renders maps created with the [Tiled map editor](https://www.mapeditor.org/) using its JSON export format (`.tmj` / `.json`). Includes tile-layer and object-group collision helpers suitable for 2D platformers and top-down games.

### Tiled export requirements

Open your map in Tiled and ensure the following before exporting:

| Setting | Required value |
|---|---|
| File → Export As | `.tmj` or `.json` |
| Map → Tile Layer Format | **CSV** or **XML** (not Base64) |
| Compression | **None** |

Base64-encoded and compressed tile data will throw a clear error at load time directing you to change these settings.

### Quick start

```js
import { loadTiledMap, updateTiledMap, drawTiledMap, unloadTiledMap }
  from "../../lib/tiled.js"

InitWindow(1280, 640, "My game")
const map = loadTiledMap("resources/map.tmj")

while (!WindowShouldClose()) {
  updateTiledMap(map, GetFrameTime())  // advance animations

  BeginDrawing()
    drawTiledMap(map, 0, 0, WHITE)
  EndDrawing()
}

unloadTiledMap(map)
CloseWindow()
```

---

### Loading & lifecycle

#### `loadTiledMap(path: string): TiledMap`

Parses the map file and loads all tileset textures into GPU memory.

- External tilesets (`.tsj` files) are resolved relative to the map file's directory.
- The returned `TiledMap` object mirrors the Tiled JSON structure — `layers`, `tilesets`, `width`, `height`, etc. are all plain JS properties you can read directly.
- Throws if the file cannot be read, if a tileset is missing, or if a tile layer uses unsupported encoding.

#### `updateTiledMap(map: TiledMap, dt: number): void`

Advances all animated tile frame timers. Call once per frame **before** drawing, passing `GetFrameTime()` (delta time in seconds).

#### `drawTiledMap(map: TiledMap, posX: number, posY: number, tint: Color): void`

Draws all visible tile layers at world position `(posX, posY)`.

- Layer `opacity` and `offsetx`/`offsety` are respected.
- Group layers are traversed recursively.
- **Object groups and image layers are not drawn** — handle those yourself using `getTiledObjects`.
- All eight tile flip/rotation combinations (horizontal, vertical, diagonal) are rendered correctly via `DrawTexturePro`.

#### `unloadTiledMap(map: TiledMap): void`

Unloads all tileset textures from GPU memory. Call when the map is no longer needed.

---

### Querying map data

Because `loadTiledMap` returns the raw Tiled JSON structure, you can read any property directly:

```js
const map = loadTiledMap("resources/map.tmj")
console.log(map.width, map.height)           // tile dimensions
console.log(map.tilewidth, map.tileheight)   // tile size in pixels
console.log(map.backgroundcolor)             // "#rrggbb" or null
```

#### `getTiledLayer(map, name): TiledLayer | null`

Finds a layer by name, searching recursively through group layers. Returns `null` if not found.

```js
const foreground = getTiledLayer(map, "Foreground")
if (foreground) drawTiledMap(map, 0, 0, WHITE)  // can draw specific layers too
```

#### `getTiledObjects(map, layerName): TiledObject[]`

Returns all objects from a named `objectgroup` layer, or `[]` if the layer does not exist.

```js
const spawns  = getTiledObjects(map, "Objects").filter(o => o.type === "spawn")
const pickups = getTiledObjects(map, "Objects").filter(o => o.type === "pickup")

// Each object has: id, name, type, x, y, width, height, rotation, visible,
// and optionally: gid (tile objects), ellipse, point, polygon, polyline, properties
```

---

### Collision

The collision helpers work directly against the map data — no preprocessing required.

#### Tile-layer collision — `checkCollisionTiledLayer`

```js
checkCollisionTiledLayer(map, layerName, rect): TileHit

type TileHit =
  | { hit: false }
  | { hit: true; tileX: number; tileY: number; tileRect: Rectangle }
```

Checks whether `rect` overlaps any non-empty tile in the named tile layer. Returns the **first colliding tile** in top-left raster order along with its world-space `tileRect`.

Only the tiles that geometrically intersect `rect`'s bounding box are tested — no full-layer scan.

**Resolving the overlap** (standard split-axis platformer pattern):

```js
// Move X first, then resolve, then move Y and resolve.

playerX += velX * dt
const hx = checkCollisionTiledLayer(map, "Ground", new Rectangle(playerX, playerY + 2, PW, PH - 4))
if (hx.hit) {
  playerX = velX > 0
    ? hx.tileRect.x - PW            // right wall: snap left edge to tile's left
    : hx.tileRect.x + hx.tileRect.width  // left wall: snap right edge to tile's right
  velX = 0
}

velY   += GRAVITY * dt
playerY += velY * dt
const hy = checkCollisionTiledLayer(map, "Ground", new Rectangle(playerX + 2, playerY, PW - 4, PH))
if (hy.hit) {
  if (velY >= 0) {
    playerY  = hy.tileRect.y - PH   // landing: snap feet to tile top
    onGround = true
  } else {
    playerY  = hy.tileRect.y + hy.tileRect.height  // ceiling: snap head to tile bottom
  }
  velY = 0
}
```

The 2 px inset on the axis **perpendicular** to movement (`playerY + 2` for X checks, `playerX + 2` for Y checks) prevents the player from catching on tile corners when sliding along a wall or floor.

#### Object-group collision — `checkCollisionTiledObjects`

```js
checkCollisionTiledObjects(map, layerName, rect): TiledObject | null
```

Checks `rect` against all visible objects in the named `objectgroup` layer. Supports **rectangles**, **ellipses** (tested as AABB), and **polygons**. Returns the first colliding object or `null`.

Typical use: trigger zones, hazards, doors, pickup areas.

```js
const hit = checkCollisionTiledObjects(map, "Triggers", playerRect)
if (hit?.type === "door") loadNextLevel(hit.name)
if (hit?.type === "hazard") killPlayer()
```

#### Pre-computed rectangle list — `getTiledCollisionRects`

```js
getTiledCollisionRects(map, layerName): Rectangle[]
```

Returns all rectangle objects from an `objectgroup` as a plain `Rectangle[]`. Useful when you want to cache static collision geometry at load time and run your own loop with `CheckCollisionRecs`.

```js
const walls = getTiledCollisionRects(map, "Collisions")  // once at load

// each frame:
for (const wall of walls) {
  if (CheckCollisionRecs(playerRect, wall)) { /* ... */ }
}
```

---

### Tile flip & rotation

Tiled encodes flip/rotation in the top 3 bits of each GID. All eight combinations are handled transparently by `drawTiledMap`:

| Flags | Visual result |
|---|---|
| H | Mirror horizontal |
| V | Mirror vertical |
| H + V | Rotate 180° |
| D + H | Rotate 90° CW |
| D + V | Rotate 90° CCW |
| D | Transpose (90° CW + H mirror) |
| D + H + V | 90° CCW + H mirror |

No action required — flip flags are stripped from GIDs before tileset lookup and applied via `DrawTexturePro` automatically.

---

### TypeScript

Type declarations are in `lib/tiled.d.ts`. With `"./lib"` included in `tsconfig.json` (already configured in this project), imports are fully typed:

```ts
import type { TiledMap, TiledObject, TileHit } from "../../lib/tiled.js"
```
