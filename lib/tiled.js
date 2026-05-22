// Tiled map (JSON format) loader and renderer for rayjs.
// Supports: tile layers, group layers, object groups, external tilesets (.tsj),
//           animated tiles, all tile flip/rotation combinations.
// Limitation: base64 and compressed tile data are not supported — save maps
//             with CSV or plain array encoding in Tiled's export settings.

import { loadFile } from "qjs:std"
import {
  LoadTexture, UnloadTexture,
  DrawTextureRec, DrawTexturePro,
  GetDirectoryPath,
  CheckCollisionRecs, CheckCollisionPointPoly,
  Rectangle, Vector2,
  ColorAlpha, WHITE,
} from "rayjs:raylib"

const FLIP_H   = 0x80000000
const FLIP_V   = 0x40000000
const FLIP_D   = 0x20000000
const GID_MASK = 0x1FFFFFFF

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

/** Load and return a TiledMap from a .tmj or .json file. */
export function loadTiledMap(path) {
  const text = loadFile(path)
  if (text === null) throw new Error(`tiled: failed to load map: ${path}`)
  const raw = JSON.parse(/** @type {string} */ (text))
  const dir = GetDirectoryPath(path)

  const tilesets = raw.tilesets.map(entry => _loadTileset(entry, dir))

  // Build per-GID animation state for every animated tile.
  const animState = {}
  for (const ts of tilesets) {
    for (const idStr of Object.keys(ts.animations)) {
      animState[ts.firstgid + Number(idStr)] = { frameIndex: 0, elapsed: 0 }
    }
  }

  return {
    width:           raw.width,
    height:          raw.height,
    tilewidth:       raw.tilewidth,
    tileheight:      raw.tileheight,
    orientation:     raw.orientation    || "orthogonal",
    renderorder:     raw.renderorder    || "right-down",
    backgroundcolor: raw.backgroundcolor ?? null,
    layers:          raw.layers,
    tilesets,
    _animState:      animState,
  }
}

/** Advance animated tiles. Call once per frame with delta time in seconds. */
export function updateTiledMap(map, dt) {
  const dtMs = dt * 1000
  for (const gidStr of Object.keys(map._animState)) {
    const gid = Number(gidStr)
    const state = map._animState[gid]
    const ts = _tilesetForGid(map.tilesets, gid)
    if (!ts) continue
    const frames = ts.animations[gid - ts.firstgid]
    if (!frames || frames.length === 0) continue
    state.elapsed += dtMs
    // Advance frames, handling multi-frame skips for slow machines.
    while (state.elapsed >= frames[state.frameIndex].duration) {
      state.elapsed -= frames[state.frameIndex].duration
      state.frameIndex = (state.frameIndex + 1) % frames.length
    }
  }
}

/** Draw all visible layers at (posX, posY). Object and image layers are skipped. */
export function drawTiledMap(map, posX, posY, tint) {
  _drawLayers(map, map.layers, posX, posY, tint ?? WHITE)
}

/** Unload all tileset textures. */
export function unloadTiledMap(map) {
  for (const ts of map.tilesets) UnloadTexture(ts.texture)
}

/** Find a layer by name, searching recursively through group layers. */
export function getTiledLayer(map, name) {
  return _findLayer(map.layers, name)
}

/** Return the objects array from a named objectgroup layer, or [] if not found. */
export function getTiledObjects(map, layerName) {
  const layer = _findLayer(map.layers, layerName)
  if (!layer || layer.type !== "objectgroup") return []
  return layer.objects ?? []
}

/**
 * Check if `rect` overlaps any non-empty tile in a tile layer.
 * Returns `{ hit: true, tileX, tileY, tileRect }` for the first colliding tile
 * (top-left raster order), or `{ hit: false }`.
 *
 * The returned `tileRect` is the tile's world-space rectangle — use it to
 * resolve the overlap:
 *   - Landing (velY > 0): snap playerY = tileRect.y - playerHeight
 *   - Ceiling (velY < 0): snap playerY = tileRect.y + tileRect.height
 *   - Right wall (velX > 0): snap playerX = tileRect.x - playerWidth
 *   - Left wall  (velX < 0): snap playerX = tileRect.x + tileRect.width
 */
export function checkCollisionTiledLayer(map, layerName, rect) {
  const layer = _findLayer(map.layers, layerName)
  if (!layer || layer.type !== "tilelayer" || !Array.isArray(layer.data)) return { hit: false }

  const tw = map.tilewidth, th = map.tileheight
  const lw = layer.width, lh = layer.height
  const data = layer.data

  const minCol = Math.max(0, Math.floor(rect.x / tw))
  const maxCol = Math.min(lw - 1, Math.floor((rect.x + rect.width  - 1) / tw))
  const minRow = Math.max(0, Math.floor(rect.y / th))
  const maxRow = Math.min(lh - 1, Math.floor((rect.y + rect.height - 1) / th))

  for (let row = minRow; row <= maxRow; row++) {
    for (let col = minCol; col <= maxCol; col++) {
      if (!((data[row * lw + col] || 0) & GID_MASK)) continue
      const tileRect = new Rectangle(col * tw, row * th, tw, th)
      if (CheckCollisionRecs(rect, tileRect)) {
        return { hit: true, tileX: col, tileY: row, tileRect }
      }
    }
  }
  return { hit: false }
}

/**
 * Check if `rect` overlaps any object in a named objectgroup layer.
 * Supports rectangle, ellipse (as AABB), and polygon objects.
 * Returns the first colliding `TiledObject`, or `null`.
 */
export function checkCollisionTiledObjects(map, layerName, rect) {
  const layer = _findLayer(map.layers, layerName)
  if (!layer || layer.type !== "objectgroup") return null

  for (const obj of (layer.objects ?? [])) {
    if (!obj.visible) continue
    if (obj.point) continue

    if (obj.polygon) {
      // Polygon: check if any corner of rect is inside, or any polygon vertex is inside rect.
      const pts = obj.polygon.map(p => new Vector2(obj.x + p.x, obj.y + p.y))
      const rectPts = [
        new Vector2(rect.x, rect.y),
        new Vector2(rect.x + rect.width, rect.y),
        new Vector2(rect.x + rect.width, rect.y + rect.height),
        new Vector2(rect.x, rect.y + rect.height),
      ]
      const hit = rectPts.some(p => CheckCollisionPointPoly(p, pts, pts.length)) ||
                  pts.some(p => CheckCollisionRecs(new Rectangle(p.x, p.y, 0, 0), rect))
      if (hit) return obj
      continue
    }

    // Rectangle and ellipse treated as AABB.
    const objRect = new Rectangle(obj.x, obj.y, obj.width || map.tilewidth, obj.height || map.tileheight)
    if (CheckCollisionRecs(rect, objRect)) return obj
  }
  return null
}

/**
 * Return all rectangle objects from a named objectgroup as `Rectangle[]`.
 * Useful for pre-computing a static collision list once at load time.
 * Ellipses and polygons are excluded (use `checkCollisionTiledObjects` for those).
 */
export function getTiledCollisionRects(map, layerName) {
  const layer = _findLayer(map.layers, layerName)
  if (!layer || layer.type !== "objectgroup") return []
  return (layer.objects ?? [])
    .filter(o => o.visible && !o.ellipse && !o.point && !o.polygon && !o.polyline)
    .map(o => new Rectangle(o.x, o.y, o.width || map.tilewidth, o.height || map.tileheight))
}

// ---------------------------------------------------------------------------
// Internals
// ---------------------------------------------------------------------------

function _resolvePath(dir, filename) {
  return dir ? dir + "/" + filename : filename
}

function _loadTileset(entry, dir) {
  let ts = entry
  if (entry.source) {
    const tsPath = _resolvePath(dir, entry.source)
    const text = loadFile(tsPath)
    if (text === null) throw new Error(`tiled: failed to load tileset: ${tsPath}`)
    ts = Object.assign(JSON.parse(/** @type {string} */ (text)), { firstgid: entry.firstgid })
  }

  const texture = LoadTexture(_resolvePath(dir, ts.image))

  // Index animations by local tile id.
  const animations = {}
  if (ts.tiles) {
    for (const tile of ts.tiles) {
      if (tile.animation) animations[tile.id] = tile.animation
    }
  }

  return {
    firstgid:   ts.firstgid,
    name:       ts.name,
    tilewidth:  ts.tilewidth,
    tileheight: ts.tileheight,
    spacing:    ts.spacing  || 0,
    margin:     ts.margin   || 0,
    columns:    ts.columns,
    texture,
    animations,
  }
}

/** Return the tileset that owns `gid` (last tileset whose firstgid <= gid). */
function _tilesetForGid(tilesets, gid) {
  for (let i = tilesets.length - 1; i >= 0; i--) {
    if (tilesets[i].firstgid <= gid) return tilesets[i]
  }
  return null
}

function _findLayer(layers, name) {
  for (const layer of layers) {
    if (layer.name === name) return layer
    if (layer.type === "group" && layer.layers) {
      const found = _findLayer(layer.layers, name)
      if (found) return found
    }
  }
  return null
}

function _drawLayers(map, layers, posX, posY, tint) {
  for (const layer of layers) {
    if (!layer.visible) continue
    const ox = posX + (layer.offsetx || 0)
    const oy = posY + (layer.offsety || 0)
    // Multiply accumulated opacity: parent opacity already baked into tint.a.
    const lt = (layer.opacity ?? 1) < 1
      ? ColorAlpha(tint, (layer.opacity) * (tint.a / 255))
      : tint
    if (layer.type === "tilelayer") {
      _drawTileLayer(map, layer, ox, oy, lt)
    } else if (layer.type === "group" && layer.layers) {
      _drawLayers(map, layer.layers, ox, oy, lt)
    }
    // objectgroup and imagelayer are intentionally not auto-drawn.
  }
}

function _drawTileLayer(map, layer, posX, posY, tint) {
  const data = layer.data
  if (!Array.isArray(data)) {
    throw new Error(
      `tiled: layer "${layer.name}" uses ${layer.compression ? "compressed " : ""}base64 encoding. ` +
      `Re-export the map with CSV or plain array tile encoding.`
    )
  }

  const lw = layer.width
  const lh = layer.height

  for (let row = 0; row < lh; row++) {
    for (let col = 0; col < lw; col++) {
      const rawGid = data[row * lw + col]
      if (!rawGid) continue  // 0 = empty cell

      const gid = rawGid & GID_MASK
      const ts  = _tilesetForGid(map.tilesets, gid)
      if (!ts) continue

      let localId = gid - ts.firstgid

      // Substitute animated frame if this tile is animated.
      const anim = map._animState[gid]
      if (anim) {
        const frames = ts.animations[localId]
        if (frames) localId = frames[anim.frameIndex].tileid
      }

      // Source rectangle in the tileset image.
      const srcCol = localId % ts.columns
      const srcRow = Math.floor(localId / ts.columns)
      const srcX   = ts.margin + srcCol * (ts.tilewidth  + ts.spacing)
      const srcY   = ts.margin + srcRow * (ts.tileheight + ts.spacing)

      _drawTile(
        ts, srcX, srcY,
        map.tilewidth, map.tileheight,
        posX + col * map.tilewidth,
        posY + row * map.tileheight,
        rawGid, tint,
      )
    }
  }
}

/**
 * Draw a single tile, handling all 8 flip/rotation combinations.
 *
 * Tiled flip bit → DrawTexturePro mapping:
 *   H only        negative source width
 *   V only        negative source height
 *   H+V           both negative
 *   D+H           90° CW  (origin at bottom-left of dest)
 *   D+V           90° CCW (origin at top-right of dest)
 *   D             90° CW + H-flip (transpose)
 *   D+H+V         90° CCW + H-flip
 */
function _drawTile(ts, srcX, srcY, tileW, tileH, dstX, dstY, rawGid, tint) {
  const flipH = (rawGid & FLIP_H) !== 0
  const flipV = (rawGid & FLIP_V) !== 0
  const flipD = (rawGid & FLIP_D) !== 0

  if (!flipH && !flipV && !flipD) {
    DrawTextureRec(
      ts.texture,
      new Rectangle(srcX, srcY, tileW, tileH),
      new Vector2(dstX, dstY),
      tint,
    )
    return
  }

  // Source rectangle: negative dimension = flip that axis.
  let sX = srcX, sY = srcY, sW = tileW, sH = tileH
  let oX = 0, oY = 0, rotation = 0

  if (flipD) {
    // Diagonal flip maps to a 90° rotation, with optional H flip on top.
    // Rotation is applied around the dest origin, so origin is adjusted
    // to keep the tile inside its grid cell after rotation.
    if (flipH && !flipV) {
      // 90° CW
      rotation = 90; oY = tileH
    } else if (!flipH && flipV) {
      // 90° CCW
      rotation = -90; oX = tileW
    } else if (!flipH) {
      // Transpose (= 90° CW + H flip)
      rotation = 90; oY = tileH
      sX = srcX + tileW; sW = -tileW
    } else {
      // D+H+V (= 90° CCW + H flip)
      rotation = -90; oX = tileW
      sX = srcX + tileW; sW = -tileW
    }
  } else {
    if (flipH) { sX = srcX + tileW; sW = -tileW }
    if (flipV) { sY = srcY + tileH; sH = -tileH }
  }

  DrawTexturePro(
    ts.texture,
    new Rectangle(sX, sY, sW, sH),
    new Rectangle(dstX, dstY, tileW, tileH),
    new Vector2(oX, oY),
    rotation,
    tint,
  )
}
