// User-data store for box2d entities.
//
// Box2D's C API attaches arbitrary `void*` to worlds, bodies, shapes and joints
// via b2World_SetUserData / b2Body_SetUserData / etc. The `void*` has no
// meaningful JS representation, so the C bindings ignore those 8 functions.
//
// This module reimplements the same idea in pure JS: a Map keyed by the
// entity's id fields (index1, generation, world0). Each entity type gets a
// distinct prefix so the same numeric index across types doesn't collide.
//
// IMPORTANT: entries are NOT auto-cleaned when entities are destroyed.
// Call the matching b2*_DeleteUserData after b2DestroyBody/Shape/Joint, or
// call b2ClearAllUserData when reloading a level.

const _store = new Map()

function _key(prefix, id) {
    // b2WorldId has no world0 field — fall back to 0 so the key shape is uniform.
    const world0 = id.world0 ?? 0
    return `${prefix}|${world0}|${id.index1}|${id.generation}`
}

// ── World ────────────────────────────────────────────────────────────────────

export function b2World_SetUserData(worldId, value) {
    _store.set(_key('w', worldId), value)
}
export function b2World_GetUserData(worldId) {
    const v = _store.get(_key('w', worldId))
    return v === undefined ? null : v
}
export function b2World_DeleteUserData(worldId) {
    _store.delete(_key('w', worldId))
}

// ── Body ─────────────────────────────────────────────────────────────────────

export function b2Body_SetUserData(bodyId, value) {
    _store.set(_key('b', bodyId), value)
}
export function b2Body_GetUserData(bodyId) {
    const v = _store.get(_key('b', bodyId))
    return v === undefined ? null : v
}
export function b2Body_DeleteUserData(bodyId) {
    _store.delete(_key('b', bodyId))
}

// ── Shape ────────────────────────────────────────────────────────────────────

export function b2Shape_SetUserData(shapeId, value) {
    _store.set(_key('s', shapeId), value)
}
export function b2Shape_GetUserData(shapeId) {
    const v = _store.get(_key('s', shapeId))
    return v === undefined ? null : v
}
export function b2Shape_DeleteUserData(shapeId) {
    _store.delete(_key('s', shapeId))
}

// ── Joint ────────────────────────────────────────────────────────────────────

export function b2Joint_SetUserData(jointId, value) {
    _store.set(_key('j', jointId), value)
}
export function b2Joint_GetUserData(jointId) {
    const v = _store.get(_key('j', jointId))
    return v === undefined ? null : v
}
export function b2Joint_DeleteUserData(jointId) {
    _store.delete(_key('j', jointId))
}

// ── Bulk operations ──────────────────────────────────────────────────────────

/** Remove all stored user data. Useful between level loads. */
export function b2ClearAllUserData() {
    _store.clear()
}

/** Current number of entries — for debugging or leak diagnostics. */
export function b2GetUserDataCount() {
    return _store.size
}
