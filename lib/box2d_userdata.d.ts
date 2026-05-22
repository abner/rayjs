// Type declarations for rayjs:ext:box2d_userdata
import type { b2WorldId, b2BodyId, b2ShapeId, b2JointId } from "rayjs:box2d"

export function b2World_SetUserData(worldId: b2WorldId, value: unknown): void
export function b2World_GetUserData<T = unknown>(worldId: b2WorldId): T | null
export function b2World_DeleteUserData(worldId: b2WorldId): void

export function b2Body_SetUserData(bodyId: b2BodyId, value: unknown): void
export function b2Body_GetUserData<T = unknown>(bodyId: b2BodyId): T | null
export function b2Body_DeleteUserData(bodyId: b2BodyId): void

export function b2Shape_SetUserData(shapeId: b2ShapeId, value: unknown): void
export function b2Shape_GetUserData<T = unknown>(shapeId: b2ShapeId): T | null
export function b2Shape_DeleteUserData(shapeId: b2ShapeId): void

export function b2Joint_SetUserData(jointId: b2JointId, value: unknown): void
export function b2Joint_GetUserData<T = unknown>(jointId: b2JointId): T | null
export function b2Joint_DeleteUserData(jointId: b2JointId): void

export function b2ClearAllUserData(): void
export function b2GetUserDataCount(): number
