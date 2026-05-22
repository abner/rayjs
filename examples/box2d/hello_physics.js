import { InitWindow, BeginDrawing, EndDrawing, ClearBackground, CloseWindow, WindowShouldClose,
         DrawCircleV, DrawRectangle, Vector2, BLACK, WHITE, DARKGRAY } from "rayjs:raylib"
import { b2CreateWorld, b2DefaultWorldDef, b2CreateBody, b2DefaultBodyDef,
         b2_dynamicBody, b2CreateCircleShape, b2CreatePolygonShape,
         b2DefaultShapeDef, b2Body_GetPosition, b2World_Step, b2DestroyWorld,
         b2Circle, b2Vec2, b2MakeBox } from "rayjs:box2d"

const SCREEN_W = 800
const SCREEN_H = 600
const SCALE = 30        // pixels per metre
const GROUND_PX = 550   // screen-y of the ground surface

function toScreenX(px) { return SCREEN_W / 2 + px * SCALE }
function toScreenY(py) { return GROUND_PX - py * SCALE }

InitWindow(SCREEN_W, SCREEN_H, "Box2D bouncing ball")

const worldDef = b2DefaultWorldDef()
const worldId = b2CreateWorld([worldDef])

// Ground — static body at y=0, half-thickness 0.5 m
const groundDef = b2DefaultBodyDef()  // static by default
const groundId = b2CreateBody(worldId, [groundDef])
const groundBox = b2MakeBox(SCREEN_W / 2 / SCALE, 0.5)
const groundShapeDef = b2DefaultShapeDef()
b2CreatePolygonShape(groundId, [groundShapeDef], [groundBox])

// Ball — dynamic circle, starts 10 m above ground
const bodyDef = b2DefaultBodyDef()
bodyDef.type = b2_dynamicBody
bodyDef.position = new b2Vec2(0, 10)
const bodyId = b2CreateBody(worldId, [bodyDef])

const circle = new b2Circle()
circle.radius = 0.5

const shapeDef = b2DefaultShapeDef()
shapeDef.material.restitution = 0.75   // bouncy — restitution lives in material, not on ShapeDef directly
b2CreateCircleShape(bodyId, [shapeDef], [circle])

const BALL_R_PX = circle.radius * SCALE
const GROUND_THICK = 30

while (!WindowShouldClose()) {
    b2World_Step(worldId, 1 / 60, 4)

    const pos = b2Body_GetPosition(bodyId)
    const bx = toScreenX(pos.x)
    const by = toScreenY(pos.y)

    BeginDrawing()
    ClearBackground(BLACK)
    DrawRectangle(0, GROUND_PX, SCREEN_W, GROUND_THICK, DARKGRAY)
    DrawCircleV(new Vector2(bx, by), BALL_R_PX, WHITE)
    EndDrawing()
}

b2DestroyWorld(worldId)
CloseWindow()
