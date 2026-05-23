![rayjs logo](./doc/logo.png)
# rayjs - Javascript + Raylib
QuickJS based Javascript bindings for raylib in a single ~3mb executable

## What is this?
rayjs is small ES2020 compliant Javascript interpreter based on [QuickJS](https://bellard.org/quickjs/) with bindings for [Raylib](https://www.raylib.com/). You can use it to develop tiny desktop games with Javascript.

## What this is not
rayjs is not a binding for NodeJS nor is it running in the browser, or phone (yet). It's comes with its own Javascript engine (QuickJS) similar to how NodeJS comes with the V8 engine. That makes it much easier to run and distribute rayjs programs as all you need to run a program / game is the small rayjs executable. No installation, no dlls or additional files are needed.

## Features
* Compiles into a single, small executable without any dependencies for easy distribution
* Use modern Javascript features like classes or async/await
* In-depth auto-complete with definitions for the whole API

## Getting started
1. Download the binary for your platform from the [release section](https://github.com/RealVarHar/rayjs/releases).
2. Unzip the executable to a folder and create a new text file in the same folder. Rename the file to `main.js`
3. Open the file with a text-editor (e.g. Notepad) and add the following code
    ```javascript
    const screenWidth = 800;
    const screenHeight = 450;

    initWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    setTargetFPS(60);   
    while (!windowShouldClose()) {
        beginDrawing();

            clearBackground(RAYWHITE);

            drawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        endDrawing();
    }
    closeWindow();
    ```
4. Run the `rayjs` executable
5. Congratulations, you have created your first rayjs app. 

## Running code
rayjs application shares usage options with QJS, with help avaliable through rayjs.exe -help
```
usage: rayjs [options] [file [args]]
-h  --help         list options
-e  --eval EXPR    evaluate EXPR
-i  --interactive  go to interactive mode
-m  --module       load as ES6 module (default=autodetect)
--script       load as ES6 script (default=autodetect)
-I  --include file include an additional file
--std          make 'std','os','bjson','raylib' available to the loaded script
-T  --trace        trace memory allocation
-d  --dump         dump the memory usage stats
-D  --dump-flags   flags for dumping debug data -D=<bitmask> (see DUMP_* defines)
--memory-limit n       limit the memory usage to 'n' Kbytes
--stack-size n         limit the stack size to 'n' Kbytes
--unhandled-rejection  dump unhandled promise rejections
-q  --quit         just instantiate the interpreter and quit
```


## API support

For the full rundown of every function, type, and constant exposed by rayjs
(raylib + raygui + Box2D + ext modules), open
[`docs/cheatsheet.html`](docs/cheatsheet.html) — a single styled page modelled
after [raylib's own cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html),
with cross-linked types. Regenerate it any time the bindings change with
`node bindings/gen_cheatsheet.js`.

The following raylib APIs are supported so far (with a few exceptions):

- core (no VR support yet)
- shapes
- textures
- text (no support for GlyphInfo yet)
- models (no animation support)
- shaders
- audio
- raymath
- rcamera
- rlights
- raygui
- reasings
- box2d (via `rayjs:box2d` — see below)

Similar to including a header in C and for your convenience, all types/functions are provided globally. They are additionally available in a module called 'raylib'

To check which API functions are not available (yet) check `/bindings/src/index.js` for `ignore` statements.

## Additional APIs

Rayjs comes with bindings to [lightmapper.h](https://github.com/ands/lightmapper/tree/master) and [Box2D v3](https://box2d.org/). See below for more information.

## Box2D physics (`rayjs:box2d`)

Rayjs includes the full [Box2D v3](https://box2d.org/) 2D physics engine as the built-in module `rayjs:box2d`. The entire public C API is available from JavaScript with no extra files or installation.

### Quick start

```javascript
import { InitWindow, BeginDrawing, EndDrawing, ClearBackground, CloseWindow,
         WindowShouldClose, DrawCircleV, DrawRectangle, Vector2,
         BLACK, WHITE, DARKGRAY } from "rayjs:raylib"
import { b2CreateWorld, b2DefaultWorldDef, b2CreateBody, b2DefaultBodyDef,
         b2_dynamicBody, b2CreateCircleShape, b2CreatePolygonShape,
         b2DefaultShapeDef, b2Body_GetPosition, b2World_Step, b2DestroyWorld,
         b2Circle, b2Vec2, b2MakeBox } from "rayjs:box2d"

const SCALE = 30  // pixels per metre
const GROUND_PX = 550

InitWindow(800, 600, "Box2D demo")

const worldId = b2CreateWorld(b2DefaultWorldDef())

// Static ground
const groundId = b2CreateBody(worldId, b2DefaultBodyDef())
b2CreatePolygonShape(groundId, b2DefaultShapeDef(), b2MakeBox(400 / SCALE, 0.5))

// Dynamic bouncing ball
const bodyDef = b2DefaultBodyDef()
bodyDef.type = b2_dynamicBody
bodyDef.position = new b2Vec2(0, 10)
const bodyId = b2CreateBody(worldId, bodyDef)

const circle = new b2Circle()
circle.radius = 0.5
const shapeDef = b2DefaultShapeDef()
shapeDef.material.restitution = 0.75  // bouncy
b2CreateCircleShape(bodyId, shapeDef, circle)

while (!WindowShouldClose()) {
    b2World_Step(worldId, 1 / 60, 4)
    const pos = b2Body_GetPosition(bodyId)
    BeginDrawing()
    ClearBackground(BLACK)
    DrawRectangle(0, GROUND_PX, 800, 20, DARKGRAY)
    DrawCircleV(new Vector2(400 + pos.x * SCALE, GROUND_PX - pos.y * SCALE), circle.radius * SCALE, WHITE)
    EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
```

```
./rayjs examples/box2d/hello_physics.js
```

### API notes

- **Enum values** are exported individually — use `b2_dynamicBody`, `b2_staticBody`, `b2_kinematicBody` directly (not `b2BodyType.b2_dynamicBody`).
- **Struct position fields** require a struct instance: `bodyDef.position = new b2Vec2(x, y)`, not a plain `{x, y}` object.
- **Restitution** (bounciness) lives on the shape's surface material, not on the shape def itself: `shapeDef.material.restitution = 0.8`.
- **Nested struct fields** (like `material` above) return a live proxy — mutations write back to the parent struct directly.
- **Coordinate system**: Box2D uses Y-up (positive Y is up). Raylib uses Y-down (positive Y is down the screen). Flip the Y axis when converting to screen coordinates.
- **`b2Default*` factories** (`b2DefaultWorldDef`, `b2DefaultBodyDef`, `b2DefaultShapeDef`) initialize structs with safe defaults and should always be used instead of constructing structs manually.

To check which functions are ignored see the `box2d` customization block in `bindings/src/index.js`.

### UserData helper (`rayjs:ext:box2d_userdata`)

Box2D's native `userData` slot is a raw C `void*` pointer and is unsafe to expose directly to JS. The bundled extension module `rayjs:ext:box2d_userdata` provides a safe JS-side replacement that attaches arbitrary JS values to bodies / shapes by id:

| Function | Description |
|---|---|
| `b2Body_SetUserData(bodyId, value)` | Attach any JS value to a body |
| `b2Body_GetUserData(bodyId)` | Read it back (returns `undefined` if unset) |
| `b2Body_DeleteUserData(bodyId)` | Remove the entry (call when destroying a body) |
| `b2Shape_SetUserData` / `b2Shape_GetUserData` / `b2Shape_DeleteUserData` | Same, for shapes |
| `b2ClearAllUserData()` | Drop the entire JS-side table — call after `b2DestroyWorld` to avoid leaks across resets |

Used by most of the examples below to tag bodies/shapes (team, colour, sensor type, top-edge y, …) that callbacks then read back.

### Examples

All examples live in `examples/box2d/` and run with `./rayjs examples/box2d/<file>.js`. Each one is intentionally focused on a single Box2D feature so the relevant API surface is easy to lift into your own project.

| Example | What it demonstrates | Key Box2D APIs |
|---|---|---|
| **`hello_physics.js`** | Minimal "one ball, one ground" sanity demo. World setup, dynamic vs static body, restitution on the surface material, the fixed-timestep loop. | `b2CreateWorld`, `b2CreateBody`, `b2CreateCircleShape`, `b2CreatePolygonShape`, `b2MakeBox`, `b2DefaultShapeDef.material.restitution`, `b2World_Step`, `b2Body_GetPosition` |
| **`box2d_mouse_picking.js`** | Click-and-drag picking: cursor → world coords → tiny AABB overlap query to find the body under the mouse, then teleport it. Each body carries a colour tag via userData. | `b2World_OverlapAABB` (per-call query callback), `b2AABB`, `b2DefaultQueryFilter`, `b2Body_SetTransform`, `b2Shape_GetBody`, `rayjs:ext:box2d_userdata` |
| **`box2d_raycast_vision.js`** | Top-down stealth scene: a guard sweeps a 6 m vision ray ±60°. Walls occlude line-of-sight; when the ray's first hit is the player, an alert overlay fires. Demonstrates closest-hit semantics via cast-callback return values (`-1` skip, `0` stop, `fraction` clip, `1` continue). | `b2World_CastRay` (per-call query callback with fraction return), `b2DefaultQueryFilter`, `b2Shape_GetBody`, `rayjs:ext:box2d_userdata` |
| **`box2d_one_way_platforms.js`** | Three stacked horizontal platforms that the player jumps *through* from below and lands on from above. Implemented in a pre-solve callback that returns `false` to cancel contacts when the player approaches a platform from underneath. | `b2World_SetPreSolveCallback` (persistent world callback), `shapeDef.enablePreSolveEvents`, `rayjs:ext:box2d_userdata` (stores each platform's top-edge y for the callback) |
| **`box2d_team_bullets.js`** | RED vs BLUE clusters. Press SPACE to fire bullets; a custom filter rejects same-team collisions so bullets pass through teammates. Box2D evaluates the filter once per pair and caches the result. | `b2World_SetCustomFilterCallback` (persistent world callback), `b2DestroyBody`, `b2Shape_GetBody`, `rayjs:ext:box2d_userdata` (team tag per body) |
| **`box2d_material_friction.js`** | Tilted ramp with ICE / WOOD / RUBBER segments (different `userMaterialId` per surface material). Three balls roll down at once and clearly slide, brake, or bounce based on a JS-side material-pair table looked up inside the friction & restitution callbacks. | `b2World_SetFrictionCallback`, `b2World_SetRestitutionCallback` (persistent world callbacks), `b2DefaultSurfaceMaterial`, `b2MakeOffsetBox`, `b2Rot` |
| **`box2d_character_mover.js`** | Kinematic capsule character controller — the player is *not* a Box2D body. Each frame: cast the capsule along the desired translation to find the safe fraction, then walk the contact planes and project remaining velocity onto each one for clean wall/slope sliding. The Box2D v3 recommended pattern, free of the "snag on slope" / "fall through corner" failure modes of dynamic-body characters. | `b2World_CastMover`, `b2World_CollideMover`, `b2Capsule`, `b2DefaultQueryFilter` |
| **`platformer_scarfy.js`** | Full small platformer: static collision world built from a Tiled tile layer, a fixed-rotation dynamic body driven by velocity overwrite (not forces), grounded-check via a short downward ray, and coin pickup via per-step sensor events. Also shows dynamic crates rendered using each body's `b2Rot`. Companion to `examples/tiled/tiled_map.js` (same map, manual AABB physics). | `b2World_CastRay`, `b2World_GetSensorEvents`, `b2StoreShapeId`, `b2Body_GetRotation`, `b2Body_GetLinearVelocity`, `b2Body_SetLinearVelocity`, fixed-rotation body |

## Built-in Extension Modules (`rayjs:ext:*`)

Rayjs embeds a set of JavaScript modules directly into the binary. They are available via the `rayjs:ext:<name>` import specifier — no relative path, no external files needed at runtime.

### `rayjs:ext:tiled` — Tiled map loader, renderer & collision

Loads and renders maps created with the [Tiled map editor](https://www.mapeditor.org/) (`.tmj` / `.json` format). Includes tile-layer collision and object-group helpers suitable for platformers and top-down games.

#### Tiled export requirements

Open your map in Tiled and set the following before exporting:

| Setting | Required value |
|---|---|
| File → Export As | `.tmj` or `.json` |
| Map → Tile Layer Format | **CSV** or **XML** (not Base64) |
| Compression | **None** |

#### Quick start

```javascript
import {
  loadTiledMap, updateTiledMap, drawTiledMap, unloadTiledMap,
} from "rayjs:ext:tiled"

InitWindow(1280, 640, "My game")
SetTargetFPS(60)

const map = loadTiledMap("resources/map.tmj")

while (!WindowShouldClose()) {
  updateTiledMap(map, GetFrameTime())   // advance tile animations

  BeginDrawing()
    ClearBackground(RAYWHITE)
    drawTiledMap(map, 0, 0, WHITE)
  EndDrawing()
}

unloadTiledMap(map)
CloseWindow()
```

See `examples/tiled/tiled_map.js` for a full platformer example with physics, a scrolling camera, and tile collision.

#### API reference

| Function | Description |
|---|---|
| `loadTiledMap(path)` | Parse map file, load all tileset textures into GPU memory |
| `updateTiledMap(map, dt)` | Advance animated tile timers — call once per frame before drawing |
| `drawTiledMap(map, posX, posY, tint)` | Draw all visible tile layers; object groups are skipped |
| `unloadTiledMap(map)` | Free all tileset textures from GPU memory |
| `getTiledLayer(map, name)` | Find a layer by name (recursive through group layers) |
| `getTiledObjects(map, layerName)` | Return objects from a named `objectgroup` layer |
| `checkCollisionTiledLayer(map, layerName, rect)` | AABB check against non-empty tiles; returns `{ hit, tileX, tileY, tileRect }` |
| `checkCollisionTiledObjects(map, layerName, rect)` | Check `rect` against objects (rectangle, ellipse, polygon); returns the hit object or `null` |
| `getTiledCollisionRects(map, layerName)` | Return all rectangle objects as `Rectangle[]` for pre-computed static collision |

Type declarations are available for IDE auto-complete — see the [Auto-Complete](#auto-complete--intellisense) section.

#### Collision example

```javascript
import { checkCollisionTiledLayer } from "rayjs:ext:tiled"

// Move X, resolve, then move Y, resolve (split-axis platformer pattern).
playerX += velX * dt
const hx = checkCollisionTiledLayer(map, "Ground", new Rectangle(playerX, playerY + 2, PW, PH - 4))
if (hx.hit) {
  playerX = velX > 0 ? hx.tileRect.x - PW : hx.tileRect.x + hx.tileRect.width
  velX = 0
}

velY    += GRAVITY * dt
playerY += velY * dt
const hy = checkCollisionTiledLayer(map, "Ground", new Rectangle(playerX + 2, playerY, PW - 4, PH))
if (hy.hit) {
  playerY  = velY >= 0 ? hy.tileRect.y - PH : hy.tileRect.y + hy.tileRect.height
  velY     = 0
  onGround = velY >= 0
}
```

The 2 px inset on the perpendicular axis (`playerY + 2` for X checks, `playerX + 2` for Y checks) prevents the player from catching on tile corners when sliding along a wall or floor.

---

### Adding a new extension module

1. **Create `lib/<name>.js`** — a standard ES module. Import raylib via `rayjs:raylib` and std utilities via `qjs:std` / `qjs:os` as needed:

   ```javascript
   // lib/mymodule.js
   import { DrawText } from "rayjs:raylib"

   export function hello() {
     DrawText("Hello from mymodule!", 10, 10, 20, WHITE)
   }
   ```

2. **Optionally create `lib/<name>.d.ts`** — TypeScript declarations for IDE auto-complete. Write the declarations as plain exports (no `declare module` wrapper needed):

   ```typescript
   // lib/mymodule.d.ts
   export function hello(): void
   ```

   At configure time and on every rebuild, `cmake/gen_ext_modules.cmake` reads `lib/<name>.d.ts`, wraps it in `declare module "rayjs:ext:<name>" { … }`, and writes the result to `bindings/typings/lib.js_ext_<name>.d.ts`. That file is picked up by the TypeScript language server automatically (it is already on the `tsconfig.json` include path).

   If you later delete `lib/<name>.js`, the corresponding `bindings/typings/lib.js_ext_<name>.d.ts` is removed by the same script so stale declarations do not accumulate.

3. **Re-run CMake** (or just rebuild). The script `cmake/gen_ext_modules.cmake` scans `lib/*.js` at configure time and on every rebuild, embeds each file into `src/js_ext_modules.h`, and generates the matching `.d.ts` in `bindings/typings/`. No manual registration is needed.

4. **Import in your game**:

   ```javascript
   import { hello } from "rayjs:ext:mymodule"
   hello()
   ```

The module name is the file stem: `lib/mymodule.js` → `rayjs:ext:mymodule`.



## Auto-Complete / Intellisense

rayjs comes with full auto-complete support in the form of the definitions file `lib.raylib.d.ts`. These will work with Typescript and Javascript. In order to use them with Javascript you should create a Typescript configuration file in the project root (even if you are not using Typescript) called `tsconfig.json` with the following configuration
```json
{
  "compilerOptions": {
    "allowJs": true,
    "target": "es2020",
    "lib": [
      "ES2020"
    ]
  }
}
```
After that put the `lib.raylib.d.ts` file in the same folder and optionally restart your IDE. Auto-complete should be working:
![](doc/auto-complete.png)

## Examples

Some official raylib examples were already ported to Javascript and can be found in the `examples` folder. 

Additional examples are described here.

```
./rayjs examples/js_example_project
```
Barebones example project on how to structure a project that uses Javascript
```
./rayjs examples/js_mesh_generation.js
```
Shows how to create a mesh from Javascript ArrayBuffers
```
./rayjs examples/shaders/js_shaders_gradient_lighting.js
```
Creates a gradient and uses it as lighting for a 3d scene
```
./rayjs examples/ts_dungeon
```
Small example game that uses Typescript with Webpack for transpilation and bundling
```
./rayjs examples/ts_game
```
Example how to integrate existing JS libraries. This example integrates the Inkjs library to compile and play a game written in the Ink interactive fiction language.


### Lightmapper usage
Rayjs integrates the [lightmapper.h](https://github.com/ands/lightmapper/tree/master) library to render baked lighting. 
The example demonstrates it's usage.
```
./rayjs examples/js_lightmapper.js
```

Meshes must have unwrapped lightmap uvs in the second UV channel.

![](2023-07-20-13-08-52.png)

The example uses an environment that is uniform white which will lead to baking pure ambient occlusion. To bake other light sources, lower the amount of ambient lighting and everything that is rendered with a color other than black will become an emissive lightsource during baking. Rendering will just work as usual and custom shaders are supported. E.g. while the raylib default shader does not support color intensities greater than 1.0, the lightmapper does support them for higher intensity lighting.

The example will try to bake lighting alongside the render loop which is still buggy and leads to artifacts. Baking before rendering works better.

## Performance
QuickJS is one of the [faster JS interpreters](https://bellard.org/quickjs/bench.html). I'm getting about 13000 bunnys in the unmodified bunnmark before dropping any frames on my 2020 Macbook Air M1 which seems pretty good.
![Bunnymark](doc/bunny.png) 

## Building
Here are some basic steps if you want to compile rayjs yourself.

### Check out required files
```bash
git clone https://github.com/RealVarHar/rayjs.git
git submodule update --init --recursive
```
### Build bindings
Rayjs builds bindings from sources, to refresh those, run
```bash
cd rayjs
qjs.exe bindings/src/index.js
```
qjs.exe can be aquired from https://github.com/quickjs-ng/quickjs or rayjs.exe itself can be used

### Submodule patches
CMakeLists.txt overlays patched copies of `quickjs.h`/`quickjs.c` (and raylib/raygui
headers when mimalloc is enabled) onto the submodule directories at configure time via
`configure_file`. This means `thirdparty/quickjs` will appear dirty after configuring —
that is expected. See [`src/overrides/quickjs/PATCHES.md`](src/overrides/quickjs/PATCHES.md)
for a description of every patch and instructions for updating.

### Build with cmake
Make sure you have cmake installed and in your path.
```bash
cd rayjs
mkdir build
cd build
cmake ..
make
```
For windows mingw is recommended, builds are tested with https://winlibs.com
```bash
cd rayjs
mkdir build
cd build
cmake ..
mingw32-make
```


