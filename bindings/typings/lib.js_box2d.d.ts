declare module "rayjs:box2d" {
interface b2Version {
major: number,
minor: number,
revision: number,
}
var b2Version: {
prototype: b2Version
new(major?: number, minor?: number, revision?: number): b2Version
}
interface b2Vec2 {
x: number,
y: number,
}
var b2Vec2: {
prototype: b2Vec2
new(x?: number, y?: number): b2Vec2
}
interface b2CosSin {
cosine: number,
sine: number,
}
var b2CosSin: {
prototype: b2CosSin
new(cosine?: number, sine?: number): b2CosSin
}
interface b2Rot {
c: number,
s: number,
}
var b2Rot: {
prototype: b2Rot
new(c?: number, s?: number): b2Rot
}
interface b2Transform {
p: b2Vec2,
q: b2Rot,
}
var b2Transform: {
prototype: b2Transform
new(p?: b2Vec2, q?: b2Rot): b2Transform
}
interface b2Mat22 {
cx: b2Vec2,
cy: b2Vec2,
}
var b2Mat22: {
prototype: b2Mat22
new(cx?: b2Vec2, cy?: b2Vec2): b2Mat22
}
interface b2AABB {
lowerBound: b2Vec2,
upperBound: b2Vec2,
}
var b2AABB: {
prototype: b2AABB
new(lowerBound?: b2Vec2, upperBound?: b2Vec2): b2AABB
}
interface b2Plane {
normal: b2Vec2,
offset: number,
}
var b2Plane: {
prototype: b2Plane
new(normal?: b2Vec2, offset?: number): b2Plane
}
interface b2SimplexCache {
count: uint16_t,
indexA: [number,number,number],
indexB: [number,number,number],
}
var b2SimplexCache: {
prototype: b2SimplexCache
new(count?: uint16_t, indexA?: [number,number,number], indexB?: [number,number,number]): b2SimplexCache
}
interface b2Hull {
}
var b2Hull: {
prototype: b2Hull
new(): b2Hull
}
interface b2RayCastInput {
origin: b2Vec2,
translation: b2Vec2,
maxFraction: number,
}
var b2RayCastInput: {
prototype: b2RayCastInput
new(origin?: b2Vec2, translation?: b2Vec2, maxFraction?: number): b2RayCastInput
}
interface b2ShapeProxy {
}
var b2ShapeProxy: {
prototype: b2ShapeProxy
new(): b2ShapeProxy
}
interface b2ShapeCastInput {
proxy: b2ShapeProxy,
translation: b2Vec2,
maxFraction: number,
canEncroach: boolean,
}
var b2ShapeCastInput: {
prototype: b2ShapeCastInput
new(proxy?: b2ShapeProxy, translation?: b2Vec2, maxFraction?: number, canEncroach?: boolean): b2ShapeCastInput
}
interface b2CastOutput {
normal: b2Vec2,
point: b2Vec2,
fraction: number,
iterations: number,
hit: boolean,
}
var b2CastOutput: {
prototype: b2CastOutput
new(normal?: b2Vec2, point?: b2Vec2, fraction?: number, iterations?: number, hit?: boolean): b2CastOutput
}
interface b2MassData {
mass: number,
center: b2Vec2,
rotationalInertia: number,
}
var b2MassData: {
prototype: b2MassData
new(mass?: number, center?: b2Vec2, rotationalInertia?: number): b2MassData
}
interface b2Circle {
center: b2Vec2,
radius: number,
}
var b2Circle: {
prototype: b2Circle
new(center?: b2Vec2, radius?: number): b2Circle
}
interface b2Capsule {
center1: b2Vec2,
center2: b2Vec2,
radius: number,
}
var b2Capsule: {
prototype: b2Capsule
new(center1?: b2Vec2, center2?: b2Vec2, radius?: number): b2Capsule
}
interface b2Polygon {
}
var b2Polygon: {
prototype: b2Polygon
new(): b2Polygon
}
interface b2Segment {
/** / The centroid of the polygon */
point1: b2Vec2,
/** / The external radius for rounded polygons */
point2: b2Vec2,
}
var b2Segment: {
prototype: b2Segment
new(point1?: b2Vec2, point2?: b2Vec2): b2Segment
}
interface b2ChainSegment {
ghost1: b2Vec2,
segment: b2Segment,
ghost2: b2Vec2,
chainId: number,
}
var b2ChainSegment: {
prototype: b2ChainSegment
new(ghost1?: b2Vec2, segment?: b2Segment, ghost2?: b2Vec2, chainId?: number): b2ChainSegment
}
interface b2SegmentDistanceResult {
closest1: b2Vec2,
closest2: b2Vec2,
fraction1: number,
fraction2: number,
distanceSquared: number,
}
var b2SegmentDistanceResult: {
prototype: b2SegmentDistanceResult
new(closest1?: b2Vec2, closest2?: b2Vec2, fraction1?: number, fraction2?: number, distanceSquared?: number): b2SegmentDistanceResult
}
interface b2DistanceInput {
proxyA: b2ShapeProxy,
proxyB: b2ShapeProxy,
transformA: b2Transform,
transformB: b2Transform,
useRadii: boolean,
}
var b2DistanceInput: {
prototype: b2DistanceInput
new(proxyA?: b2ShapeProxy, proxyB?: b2ShapeProxy, transformA?: b2Transform, transformB?: b2Transform, useRadii?: boolean): b2DistanceInput
}
interface b2DistanceOutput {
/** /< Closest point on shapeA */
pointA: b2Vec2,
/** /< Closest point on shapeB */
pointB: b2Vec2,
/** /< Normal vector that points from A to B. Invalid if distance is zero. */
normal: b2Vec2,
/** /< The final distance, zero if overlapped */
distance: number,
/** /< Number of GJK iterations used */
iterations: number,
/** /< The number of simplexes stored in the simplex array */
simplexCount: number,
}
var b2DistanceOutput: {
prototype: b2DistanceOutput
new(pointA?: b2Vec2, pointB?: b2Vec2, normal?: b2Vec2, distance?: number, iterations?: number, simplexCount?: number): b2DistanceOutput
}
interface b2SimplexVertex {
/** /< support point in proxyA */
wA: b2Vec2,
/** /< support point in proxyB */
wB: b2Vec2,
/** /< wB - wA */
w: b2Vec2,
/** /< barycentric coordinate for closest point */
a: number,
/** /< wA index */
indexA: number,
/** /< wB index */
indexB: number,
}
var b2SimplexVertex: {
prototype: b2SimplexVertex
new(wA?: b2Vec2, wB?: b2Vec2, w?: b2Vec2, a?: number, indexA?: number, indexB?: number): b2SimplexVertex
}
interface b2Simplex {
/** /< vertices */
v1: b2SimplexVertex,
v2: b2SimplexVertex,
v3: b2SimplexVertex,
/** /< number of valid vertices */
count: number,
}
var b2Simplex: {
prototype: b2Simplex
new(v1?: b2SimplexVertex, v2?: b2SimplexVertex, v3?: b2SimplexVertex, count?: number): b2Simplex
}
interface b2ShapeCastPairInput {
/** /< The proxy for shape A */
proxyA: b2ShapeProxy,
/** /< The proxy for shape B */
proxyB: b2ShapeProxy,
/** /< The world transform for shape A */
transformA: b2Transform,
/** /< The world transform for shape B */
transformB: b2Transform,
/** /< The translation of shape B */
translationB: b2Vec2,
/** /< The fraction of the translation to consider, typically 1 */
maxFraction: number,
/** /< Allows shapes with a radius to move slightly closer if already touching */
canEncroach: boolean,
}
var b2ShapeCastPairInput: {
prototype: b2ShapeCastPairInput
new(proxyA?: b2ShapeProxy, proxyB?: b2ShapeProxy, transformA?: b2Transform, transformB?: b2Transform, translationB?: b2Vec2, maxFraction?: number, canEncroach?: boolean): b2ShapeCastPairInput
}
interface b2Sweep {
/** /< Local center of mass position */
localCenter: b2Vec2,
/** /< Starting center of mass world position */
c1: b2Vec2,
/** /< Ending center of mass world position */
c2: b2Vec2,
/** /< Starting world rotation */
q1: b2Rot,
/** /< Ending world rotation */
q2: b2Rot,
}
var b2Sweep: {
prototype: b2Sweep
new(localCenter?: b2Vec2, c1?: b2Vec2, c2?: b2Vec2, q1?: b2Rot, q2?: b2Rot): b2Sweep
}
interface b2TOIInput {
/** /< The proxy for shape A */
proxyA: b2ShapeProxy,
/** /< The proxy for shape B */
proxyB: b2ShapeProxy,
/** /< The movement of shape A */
sweepA: b2Sweep,
/** /< The movement of shape B */
sweepB: b2Sweep,
/** /< Defines the sweep interval [0, maxFraction] */
maxFraction: number,
}
var b2TOIInput: {
prototype: b2TOIInput
new(proxyA?: b2ShapeProxy, proxyB?: b2ShapeProxy, sweepA?: b2Sweep, sweepB?: b2Sweep, maxFraction?: number): b2TOIInput
}
interface b2TOIOutput {
/** /< The type of result */
state: b2TOIState,
/** /< The sweep time of the collision */
fraction: number,
}
var b2TOIOutput: {
prototype: b2TOIOutput
new(state?: b2TOIState, fraction?: number): b2TOIOutput
}
interface b2ManifoldPoint {
point: b2Vec2,
anchorA: b2Vec2,
anchorB: b2Vec2,
separation: number,
normalImpulse: number,
tangentImpulse: number,
totalNormalImpulse: number,
normalVelocity: number,
id: uint16_t,
persisted: boolean,
}
var b2ManifoldPoint: {
prototype: b2ManifoldPoint
new(point?: b2Vec2, anchorA?: b2Vec2, anchorB?: b2Vec2, separation?: number, normalImpulse?: number, tangentImpulse?: number, totalNormalImpulse?: number, normalVelocity?: number, id?: uint16_t, persisted?: boolean): b2ManifoldPoint
}
interface b2Manifold {
normal: b2Vec2,
rollingImpulse: number,
points: [b2ManifoldPoint,b2ManifoldPoint],
pointCount: number,
}
var b2Manifold: {
prototype: b2Manifold
new(normal?: b2Vec2, rollingImpulse?: number, points?: [b2ManifoldPoint,b2ManifoldPoint], pointCount?: number): b2Manifold
}
interface b2TreeStats {
nodeVisits: number,
leafVisits: number,
}
var b2TreeStats: {
prototype: b2TreeStats
new(nodeVisits?: number, leafVisits?: number): b2TreeStats
}
interface b2PlaneResult {
plane: b2Plane,
point: b2Vec2,
hit: boolean,
}
var b2PlaneResult: {
prototype: b2PlaneResult
new(plane?: b2Plane, point?: b2Vec2, hit?: boolean): b2PlaneResult
}
interface b2CollisionPlane {
plane: b2Plane,
pushLimit: number,
push: number,
clipVelocity: boolean,
}
var b2CollisionPlane: {
prototype: b2CollisionPlane
new(plane?: b2Plane, pushLimit?: number, push?: number, clipVelocity?: boolean): b2CollisionPlane
}
interface b2PlaneSolverResult {
translation: b2Vec2,
iterationCount: number,
}
var b2PlaneSolverResult: {
prototype: b2PlaneSolverResult
new(translation?: b2Vec2, iterationCount?: number): b2PlaneSolverResult
}
interface b2WorldId {
index1: uint16_t,
generation: uint16_t,
}
var b2WorldId: {
prototype: b2WorldId
new(index1?: uint16_t, generation?: uint16_t): b2WorldId
}
interface b2BodyId {
index1: number,
world0: uint16_t,
generation: uint16_t,
}
var b2BodyId: {
prototype: b2BodyId
new(index1?: number, world0?: uint16_t, generation?: uint16_t): b2BodyId
}
interface b2ShapeId {
index1: number,
world0: uint16_t,
generation: uint16_t,
}
var b2ShapeId: {
prototype: b2ShapeId
new(index1?: number, world0?: uint16_t, generation?: uint16_t): b2ShapeId
}
interface b2ChainId {
index1: number,
world0: uint16_t,
generation: uint16_t,
}
var b2ChainId: {
prototype: b2ChainId
new(index1?: number, world0?: uint16_t, generation?: uint16_t): b2ChainId
}
interface b2JointId {
index1: number,
world0: uint16_t,
generation: uint16_t,
}
var b2JointId: {
prototype: b2JointId
new(index1?: number, world0?: uint16_t, generation?: uint16_t): b2JointId
}
interface b2RayResult {
shapeId: b2ShapeId,
point: b2Vec2,
normal: b2Vec2,
fraction: number,
nodeVisits: number,
leafVisits: number,
hit: boolean,
}
var b2RayResult: {
prototype: b2RayResult
new(shapeId?: b2ShapeId, point?: b2Vec2, normal?: b2Vec2, fraction?: number, nodeVisits?: number, leafVisits?: number, hit?: boolean): b2RayResult
}
interface b2WorldDef {
gravity: b2Vec2,
restitutionThreshold: number,
hitEventThreshold: number,
contactHertz: number,
contactDampingRatio: number,
maxContactPushSpeed: number,
maximumLinearSpeed: number,
enableSleep: boolean,
enableContinuous: boolean,
workerCount: number,
}
var b2WorldDef: {
prototype: b2WorldDef
new(gravity?: b2Vec2, restitutionThreshold?: number, hitEventThreshold?: number, contactHertz?: number, contactDampingRatio?: number, maxContactPushSpeed?: number, maximumLinearSpeed?: number, enableSleep?: boolean, enableContinuous?: boolean, workerCount?: number): b2WorldDef
}
interface b2BodyDef {
type: b2BodyType,
position: b2Vec2,
rotation: b2Rot,
linearVelocity: b2Vec2,
angularVelocity: number,
linearDamping: number,
angularDamping: number,
gravityScale: number,
sleepThreshold: number,
name: string,
enableSleep: boolean,
isAwake: boolean,
fixedRotation: boolean,
isBullet: boolean,
isEnabled: boolean,
allowFastRotation: boolean,
}
var b2BodyDef: {
prototype: b2BodyDef
new(type?: b2BodyType, position?: b2Vec2, rotation?: b2Rot, linearVelocity?: b2Vec2, angularVelocity?: number, linearDamping?: number, angularDamping?: number, gravityScale?: number, sleepThreshold?: number, name?: string, enableSleep?: boolean, isAwake?: boolean, fixedRotation?: boolean, isBullet?: boolean, isEnabled?: boolean, allowFastRotation?: boolean): b2BodyDef
}
interface b2Filter {
categoryBits: number,
maskBits: number,
groupIndex: number,
}
var b2Filter: {
prototype: b2Filter
new(categoryBits?: number, maskBits?: number, groupIndex?: number): b2Filter
}
interface b2QueryFilter {
categoryBits: number,
maskBits: number,
}
var b2QueryFilter: {
prototype: b2QueryFilter
new(categoryBits?: number, maskBits?: number): b2QueryFilter
}
interface b2SurfaceMaterial {
friction: number,
restitution: number,
rollingResistance: number,
tangentSpeed: number,
userMaterialId: number,
customColor: number,
}
var b2SurfaceMaterial: {
prototype: b2SurfaceMaterial
new(friction?: number, restitution?: number, rollingResistance?: number, tangentSpeed?: number, userMaterialId?: number, customColor?: number): b2SurfaceMaterial
}
interface b2ShapeDef {
material: b2SurfaceMaterial,
density: number,
filter: b2Filter,
isSensor: boolean,
enableSensorEvents: boolean,
enableContactEvents: boolean,
enableHitEvents: boolean,
enablePreSolveEvents: boolean,
invokeContactCreation: boolean,
updateBodyMass: boolean,
}
var b2ShapeDef: {
prototype: b2ShapeDef
new(material?: b2SurfaceMaterial, density?: number, filter?: b2Filter, isSensor?: boolean, enableSensorEvents?: boolean, enableContactEvents?: boolean, enableHitEvents?: boolean, enablePreSolveEvents?: boolean, invokeContactCreation?: boolean, updateBodyMass?: boolean): b2ShapeDef
}
interface b2ChainDef {
points: b2Vec2[],
count: number,
materials: b2SurfaceMaterial[],
materialCount: number,
filter: b2Filter,
isLoop: boolean,
enableSensorEvents: boolean,
}
var b2ChainDef: {
prototype: b2ChainDef
new(points?: b2Vec2[], count?: number, materials?: b2SurfaceMaterial[], materialCount?: number, filter?: b2Filter, isLoop?: boolean, enableSensorEvents?: boolean): b2ChainDef
}
interface b2Profile {
step: number,
pairs: number,
collide: number,
solve: number,
mergeIslands: number,
prepareStages: number,
solveConstraints: number,
prepareConstraints: number,
integrateVelocities: number,
warmStart: number,
solveImpulses: number,
integratePositions: number,
relaxImpulses: number,
applyRestitution: number,
storeImpulses: number,
splitIslands: number,
transforms: number,
hitEvents: number,
refit: number,
bullets: number,
sleepIslands: number,
sensors: number,
}
var b2Profile: {
prototype: b2Profile
new(step?: number, pairs?: number, collide?: number, solve?: number, mergeIslands?: number, prepareStages?: number, solveConstraints?: number, prepareConstraints?: number, integrateVelocities?: number, warmStart?: number, solveImpulses?: number, integratePositions?: number, relaxImpulses?: number, applyRestitution?: number, storeImpulses?: number, splitIslands?: number, transforms?: number, hitEvents?: number, refit?: number, bullets?: number, sleepIslands?: number, sensors?: number): b2Profile
}
interface b2Counters {
bodyCount: number,
shapeCount: number,
contactCount: number,
jointCount: number,
islandCount: number,
stackUsed: number,
staticTreeHeight: number,
treeHeight: number,
byteCount: number,
taskCount: number,
colorCounts: [number,number,number,number,number,number,number,number,number,number,number,number],
}
var b2Counters: {
prototype: b2Counters
new(bodyCount?: number, shapeCount?: number, contactCount?: number, jointCount?: number, islandCount?: number, stackUsed?: number, staticTreeHeight?: number, treeHeight?: number, byteCount?: number, taskCount?: number, colorCounts?: [number,number,number,number,number,number,number,number,number,number,number,number]): b2Counters
}
interface b2DistanceJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
localAnchorA: b2Vec2,
localAnchorB: b2Vec2,
length: number,
enableSpring: boolean,
hertz: number,
dampingRatio: number,
enableLimit: boolean,
minLength: number,
maxLength: number,
enableMotor: boolean,
maxMotorForce: number,
motorSpeed: number,
collideConnected: boolean,
}
var b2DistanceJointDef: {
prototype: b2DistanceJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, localAnchorA?: b2Vec2, localAnchorB?: b2Vec2, length?: number, enableSpring?: boolean, hertz?: number, dampingRatio?: number, enableLimit?: boolean, minLength?: number, maxLength?: number, enableMotor?: boolean, maxMotorForce?: number, motorSpeed?: number, collideConnected?: boolean): b2DistanceJointDef
}
interface b2MotorJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
linearOffset: b2Vec2,
angularOffset: number,
maxForce: number,
maxTorque: number,
correctionFactor: number,
collideConnected: boolean,
}
var b2MotorJointDef: {
prototype: b2MotorJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, linearOffset?: b2Vec2, angularOffset?: number, maxForce?: number, maxTorque?: number, correctionFactor?: number, collideConnected?: boolean): b2MotorJointDef
}
interface b2MouseJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
target: b2Vec2,
hertz: number,
dampingRatio: number,
maxForce: number,
collideConnected: boolean,
}
var b2MouseJointDef: {
prototype: b2MouseJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, target?: b2Vec2, hertz?: number, dampingRatio?: number, maxForce?: number, collideConnected?: boolean): b2MouseJointDef
}
interface b2FilterJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
}
var b2FilterJointDef: {
prototype: b2FilterJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId): b2FilterJointDef
}
interface b2PrismaticJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
localAnchorA: b2Vec2,
localAnchorB: b2Vec2,
localAxisA: b2Vec2,
referenceAngle: number,
targetTranslation: number,
enableSpring: boolean,
hertz: number,
dampingRatio: number,
enableLimit: boolean,
lowerTranslation: number,
upperTranslation: number,
enableMotor: boolean,
maxMotorForce: number,
motorSpeed: number,
collideConnected: boolean,
}
var b2PrismaticJointDef: {
prototype: b2PrismaticJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, localAnchorA?: b2Vec2, localAnchorB?: b2Vec2, localAxisA?: b2Vec2, referenceAngle?: number, targetTranslation?: number, enableSpring?: boolean, hertz?: number, dampingRatio?: number, enableLimit?: boolean, lowerTranslation?: number, upperTranslation?: number, enableMotor?: boolean, maxMotorForce?: number, motorSpeed?: number, collideConnected?: boolean): b2PrismaticJointDef
}
interface b2RevoluteJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
localAnchorA: b2Vec2,
localAnchorB: b2Vec2,
referenceAngle: number,
targetAngle: number,
enableSpring: boolean,
hertz: number,
dampingRatio: number,
enableLimit: boolean,
lowerAngle: number,
upperAngle: number,
enableMotor: boolean,
maxMotorTorque: number,
motorSpeed: number,
drawSize: number,
collideConnected: boolean,
}
var b2RevoluteJointDef: {
prototype: b2RevoluteJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, localAnchorA?: b2Vec2, localAnchorB?: b2Vec2, referenceAngle?: number, targetAngle?: number, enableSpring?: boolean, hertz?: number, dampingRatio?: number, enableLimit?: boolean, lowerAngle?: number, upperAngle?: number, enableMotor?: boolean, maxMotorTorque?: number, motorSpeed?: number, drawSize?: number, collideConnected?: boolean): b2RevoluteJointDef
}
interface b2WeldJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
localAnchorA: b2Vec2,
localAnchorB: b2Vec2,
referenceAngle: number,
linearHertz: number,
angularHertz: number,
linearDampingRatio: number,
angularDampingRatio: number,
collideConnected: boolean,
}
var b2WeldJointDef: {
prototype: b2WeldJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, localAnchorA?: b2Vec2, localAnchorB?: b2Vec2, referenceAngle?: number, linearHertz?: number, angularHertz?: number, linearDampingRatio?: number, angularDampingRatio?: number, collideConnected?: boolean): b2WeldJointDef
}
interface b2WheelJointDef {
bodyIdA: b2BodyId,
bodyIdB: b2BodyId,
localAnchorA: b2Vec2,
localAnchorB: b2Vec2,
localAxisA: b2Vec2,
enableSpring: boolean,
hertz: number,
dampingRatio: number,
enableLimit: boolean,
lowerTranslation: number,
upperTranslation: number,
enableMotor: boolean,
maxMotorTorque: number,
motorSpeed: number,
collideConnected: boolean,
}
var b2WheelJointDef: {
prototype: b2WheelJointDef
new(bodyIdA?: b2BodyId, bodyIdB?: b2BodyId, localAnchorA?: b2Vec2, localAnchorB?: b2Vec2, localAxisA?: b2Vec2, enableSpring?: boolean, hertz?: number, dampingRatio?: number, enableLimit?: boolean, lowerTranslation?: number, upperTranslation?: number, enableMotor?: boolean, maxMotorTorque?: number, motorSpeed?: number, collideConnected?: boolean): b2WheelJointDef
}
interface b2ExplosionDef {
maskBits: number,
position: b2Vec2,
radius: number,
falloff: number,
impulsePerLength: number,
}
var b2ExplosionDef: {
prototype: b2ExplosionDef
new(maskBits?: number, position?: b2Vec2, radius?: number, falloff?: number, impulsePerLength?: number): b2ExplosionDef
}
interface b2SensorBeginTouchEvent {
sensorShapeId: b2ShapeId,
visitorShapeId: b2ShapeId,
}
var b2SensorBeginTouchEvent: {
prototype: b2SensorBeginTouchEvent
new(sensorShapeId?: b2ShapeId, visitorShapeId?: b2ShapeId): b2SensorBeginTouchEvent
}
interface b2SensorEndTouchEvent {
sensorShapeId: b2ShapeId,
visitorShapeId: b2ShapeId,
}
var b2SensorEndTouchEvent: {
prototype: b2SensorEndTouchEvent
new(sensorShapeId?: b2ShapeId, visitorShapeId?: b2ShapeId): b2SensorEndTouchEvent
}
interface b2SensorEvents {
beginEvents: b2SensorBeginTouchEvent[],
endEvents: b2SensorEndTouchEvent[],
beginCount: number,
endCount: number,
}
var b2SensorEvents: {
prototype: b2SensorEvents
new(beginEvents?: b2SensorBeginTouchEvent[], endEvents?: b2SensorEndTouchEvent[], beginCount?: number, endCount?: number): b2SensorEvents
}
interface b2ContactBeginTouchEvent {
shapeIdA: b2ShapeId,
shapeIdB: b2ShapeId,
manifold: b2Manifold,
}
var b2ContactBeginTouchEvent: {
prototype: b2ContactBeginTouchEvent
new(shapeIdA?: b2ShapeId, shapeIdB?: b2ShapeId, manifold?: b2Manifold): b2ContactBeginTouchEvent
}
interface b2ContactEndTouchEvent {
shapeIdA: b2ShapeId,
shapeIdB: b2ShapeId,
}
var b2ContactEndTouchEvent: {
prototype: b2ContactEndTouchEvent
new(shapeIdA?: b2ShapeId, shapeIdB?: b2ShapeId): b2ContactEndTouchEvent
}
interface b2ContactHitEvent {
shapeIdA: b2ShapeId,
shapeIdB: b2ShapeId,
point: b2Vec2,
normal: b2Vec2,
approachSpeed: number,
}
var b2ContactHitEvent: {
prototype: b2ContactHitEvent
new(shapeIdA?: b2ShapeId, shapeIdB?: b2ShapeId, point?: b2Vec2, normal?: b2Vec2, approachSpeed?: number): b2ContactHitEvent
}
interface b2ContactEvents {
beginEvents: b2ContactBeginTouchEvent[],
endEvents: b2ContactEndTouchEvent[],
hitEvents: b2ContactHitEvent[],
beginCount: number,
endCount: number,
hitCount: number,
}
var b2ContactEvents: {
prototype: b2ContactEvents
new(beginEvents?: b2ContactBeginTouchEvent[], endEvents?: b2ContactEndTouchEvent[], hitEvents?: b2ContactHitEvent[], beginCount?: number, endCount?: number, hitCount?: number): b2ContactEvents
}
interface b2BodyMoveEvent {
transform: b2Transform,
bodyId: b2BodyId,
fellAsleep: boolean,
}
var b2BodyMoveEvent: {
prototype: b2BodyMoveEvent
new(transform?: b2Transform, bodyId?: b2BodyId, fellAsleep?: boolean): b2BodyMoveEvent
}
interface b2BodyEvents {
moveEvents: b2BodyMoveEvent[],
moveCount: number,
}
var b2BodyEvents: {
prototype: b2BodyEvents
new(moveEvents?: b2BodyMoveEvent[], moveCount?: number): b2BodyEvents
}
interface b2ContactData {
shapeIdA: b2ShapeId,
shapeIdB: b2ShapeId,
manifold: b2Manifold,
}
var b2ContactData: {
prototype: b2ContactData
new(shapeIdA?: b2ShapeId, shapeIdB?: b2ShapeId, manifold?: b2Manifold): b2ContactData
}
/** / @return the total bytes allocated by Box2D */
function b2GetByteCount(): number/** / Get the current version of Box2D */
function b2GetVersion(): b2Version/** / Get the absolute number of system ticks. The value is platform specific. */
function b2GetTicks(): number/** / Get the milliseconds passed from an initial tick value. */
function b2GetMilliseconds(ticks: number): number/** / Yield to be used in a busy loop. */
function b2Yield(): void/** / Is this a valid number? Not NaN or infinity. */
function b2IsValidFloat(a: number): boolean/** / Is this a valid vector? Not NaN or infinity. */
function b2IsValidVec2(v: b2Vec2): boolean/** / Is this a valid rotation? Not NaN or infinity. Is normalized. */
function b2IsValidRotation(q: b2Rot): boolean/** / Is this a valid bounding box? Not Nan or infinity. Upper bound greater than or equal to lower bound. */
function b2IsValidAABB(aabb: b2AABB): boolean/** / Is this a valid plane? Normal is a unit vector. Not Nan or infinity. */
function b2IsValidPlane(a: b2Plane): boolean/** / @return the minimum of two integers */
function b2MinInt(a: number, b: number): number/** / @return the maximum of two integers */
function b2MaxInt(a: number, b: number): number/** / @return the absolute value of an integer */
function b2AbsInt(a: number): number/** / @return an integer clamped between a lower and upper bound */
function b2ClampInt(a: number, lower: number, upper: number): number/** / @return the minimum of two floats */
function b2MinFloat(a: number, b: number): number/** / @return the maximum of two floats */
function b2MaxFloat(a: number, b: number): number/** / @return the absolute value of a float */
function b2AbsFloat(a: number): number/** / @return a float clamped between a lower and upper bound */
function b2ClampFloat(a: number, lower: number, upper: number): number/** /	Accurate to around 0.0023 degrees */
function b2Atan2(y: number, x: number): number/** / for cross-platform determinism. */
function b2ComputeCosSin(radians: number): b2CosSin/** / Vector dot product */
function b2Dot(a: b2Vec2, b: b2Vec2): number/** / Vector cross product. In 2D this yields a scalar. */
function b2Cross(a: b2Vec2, b: b2Vec2): number/** / Perform the cross product on a vector and a scalar. In 2D this produces a vector. */
function b2CrossVS(v: b2Vec2, s: number): b2Vec2/** / Perform the cross product on a scalar and a vector. In 2D this produces a vector. */
function b2CrossSV(s: number, v: b2Vec2): b2Vec2/** / Get a left pointing perpendicular vector. Equivalent to b2CrossSV(1.0f, v) */
function b2LeftPerp(v: b2Vec2): b2Vec2/** / Get a right pointing perpendicular vector. Equivalent to b2CrossVS(v, 1.0f) */
function b2RightPerp(v: b2Vec2): b2Vec2/** / Vector addition */
function b2Add(a: b2Vec2, b: b2Vec2): b2Vec2/** / Vector subtraction */
function b2Sub(a: b2Vec2, b: b2Vec2): b2Vec2/** / Vector negation */
function b2Neg(a: b2Vec2): b2Vec2/** / https://fgiesen.wordpress.com/2012/08/15/linear-interpolation-past-present-and-future/ */
function b2Lerp(a: b2Vec2, b: b2Vec2, t: number): b2Vec2/** / Component-wise multiplication */
function b2Mul(a: b2Vec2, b: b2Vec2): b2Vec2/** / Multiply a scalar and vector */
function b2MulSV(s: number, v: b2Vec2): b2Vec2/** / a + s * b */
function b2MulAdd(a: b2Vec2, s: number, b: b2Vec2): b2Vec2/** / a - s * b */
function b2MulSub(a: b2Vec2, s: number, b: b2Vec2): b2Vec2/** / Component-wise absolute vector */
function b2Abs(a: b2Vec2): b2Vec2/** / Component-wise minimum vector */
function b2Min(a: b2Vec2, b: b2Vec2): b2Vec2/** / Component-wise maximum vector */
function b2Max(a: b2Vec2, b: b2Vec2): b2Vec2/** / Component-wise clamp vector v into the range [a, b] */
function b2Clamp(v: b2Vec2, a: b2Vec2, b: b2Vec2): b2Vec2/** / Get the length of this vector (the norm) */
function b2Length(v: b2Vec2): number/** / Get the distance between two points */
function b2Distance(a: b2Vec2, b: b2Vec2): number/** / todo MSVC is not inlining this function in several places per warning 4710 */
function b2Normalize(v: b2Vec2): b2Vec2/** / Determines if the provided vector is normalized (norm(a) == 1). */
function b2IsNormalized(a: b2Vec2): boolean/** / outputs the length. */
function b2GetLengthAndNormalize(length: number[], v: b2Vec2): b2Vec2/** / Normalize rotation */
function b2NormalizeRot(q: b2Rot): b2Rot/** / @param deltaAngle the angular displacement in radians */
function b2IntegrateRotation(q1: b2Rot, deltaAngle: number): b2Rot/** / Get the length squared of this vector */
function b2LengthSquared(v: b2Vec2): number/** / Get the distance squared between points */
function b2DistanceSquared(a: b2Vec2, b: b2Vec2): number/** / Make a rotation using an angle in radians */
function b2MakeRot(radians: number): b2Rot/** / Compute the rotation between two unit vectors */
function b2ComputeRotationBetweenUnitVectors(v1: b2Vec2, v2: b2Vec2): b2Rot/** / Is this rotation normalized? */
function b2IsNormalizedRot(q: b2Rot): boolean/** /	https://web.archive.org/web/20170825184056/http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/ */
function b2NLerp(q1: b2Rot, q2: b2Rot, t: number): b2Rot/** / @param inv_h inverse time step */
function b2ComputeAngularVelocity(q1: b2Rot, q2: b2Rot, inv_h: number): number/** / Get the angle in radians in the range [-pi, pi] */
function b2Rot_GetAngle(q: b2Rot): number/** / Get the x-axis */
function b2Rot_GetXAxis(q: b2Rot): b2Vec2/** / Get the y-axis */
function b2Rot_GetYAxis(q: b2Rot): b2Vec2/** / Multiply two rotations: q * r */
function b2MulRot(q: b2Rot, r: b2Rot): b2Rot/** / Transpose multiply two rotations: qT * r */
function b2InvMulRot(q: b2Rot, r: b2Rot): b2Rot/** / relative angle between b and a (rot_b * inv(rot_a)) */
function b2RelativeAngle(b: b2Rot, a: b2Rot): number/** / Convert any angle into the range [-pi, pi] */
function b2UnwindAngle(radians: number): number/** / Rotate a vector */
function b2RotateVector(q: b2Rot, v: b2Vec2): b2Vec2/** / Inverse rotate a vector */
function b2InvRotateVector(q: b2Rot, v: b2Vec2): b2Vec2/** / Transform a point (e.g. local space to world space) */
function b2TransformPoint(t: b2Transform, p: b2Vec2): b2Vec2/** / Inverse transform a point (e.g. world space to local space) */
function b2InvTransformPoint(t: b2Transform, p: b2Vec2): b2Vec2/** /    = (A.q * B.q).Rot(v1) + A.q.Rot(B.p) + A.p */
function b2MulTransforms(A: b2Transform, B: b2Transform): b2Transform/** /    = A.q' * B.q * v1 + A.q' * (B.p - A.p) */
function b2InvMulTransforms(A: b2Transform, B: b2Transform): b2Transform/** / Multiply a 2-by-2 matrix times a 2D vector */
function b2MulMV(A: b2Mat22, v: b2Vec2): b2Vec2/** / Get the inverse of a 2-by-2 matrix */
function b2GetInverse22(A: b2Mat22): b2Mat22/** / than computing the inverse in one-shot cases. */
function b2Solve22(A: b2Mat22, b: b2Vec2): b2Vec2/** / Does a fully contain b */
function b2AABB_Contains(a: b2AABB, b: b2AABB): boolean/** / Get the center of the AABB. */
function b2AABB_Center(a: b2AABB): b2Vec2/** / Get the extents of the AABB (half-widths). */
function b2AABB_Extents(a: b2AABB): b2Vec2/** / Union of two AABBs */
function b2AABB_Union(a: b2AABB, b: b2AABB): b2AABB/** / Do a and b overlap */
function b2AABB_Overlaps(a: b2AABB, b: b2AABB): boolean/** / Compute the bounding box of an array of circles */
function b2MakeAABB(points: b2Vec2[], count: number, radius: number): b2AABB/** / Signed separation of a point from a plane */
function b2PlaneSeparation(plane: b2Plane, point: b2Vec2): number/** / that doesn't require transcendental functions. */
function b2SpringDamper(hertz: number, dampingRatio: number, position: number, velocity: number, timeStep: number): number/** / @warning This must be modified before any calls to Box2D */
function b2SetLengthUnitsPerMeter(lengthUnits: number): void/** / Get the current length units per meter. */
function b2GetLengthUnitsPerMeter(): number/** / Validate ray cast input data (NaN, etc) */
function b2IsValidRay(input: b2RayCastInput[]): boolean/** / @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull */
function b2MakePolygon(hull: b2Hull[], radius: number): b2Polygon/** / @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull */
function b2MakeOffsetPolygon(hull: b2Hull[], position: b2Vec2, rotation: b2Rot): b2Polygon/** / @warning Do not manually fill in the hull data, it must come directly from b2ComputeHull */
function b2MakeOffsetRoundedPolygon(hull: b2Hull[], position: b2Vec2, rotation: b2Rot, radius: number): b2Polygon/** / @param halfWidth the half-width */
function b2MakeSquare(halfWidth: number): b2Polygon/** / @param halfHeight the half-height (y-axis) */
function b2MakeBox(halfWidth: number, halfHeight: number): b2Polygon/** / @param radius the radius of the rounded extension */
function b2MakeRoundedBox(halfWidth: number, halfHeight: number, radius: number): b2Polygon/** / @param rotation the local rotation of the box */
function b2MakeOffsetBox(halfWidth: number, halfHeight: number, center: b2Vec2, rotation: b2Rot): b2Polygon/** / @param radius the radius of the rounded extension */
function b2MakeOffsetRoundedBox(halfWidth: number, halfHeight: number, center: b2Vec2, rotation: b2Rot, radius: number): b2Polygon/** / Transform a polygon. This is useful for transferring a shape from one body to another. */
function b2TransformPolygon(transform: b2Transform, polygon: b2Polygon[]): b2Polygon/** / Compute mass properties of a circle */
function b2ComputeCircleMass(shape: b2Circle[], density: number): b2MassData/** / Compute mass properties of a capsule */
function b2ComputeCapsuleMass(shape: b2Capsule[], density: number): b2MassData/** / Compute mass properties of a polygon */
function b2ComputePolygonMass(shape: b2Polygon[], density: number): b2MassData/** / Compute the bounding box of a transformed circle */
function b2ComputeCircleAABB(shape: b2Circle[], transform: b2Transform): b2AABB/** / Compute the bounding box of a transformed capsule */
function b2ComputeCapsuleAABB(shape: b2Capsule[], transform: b2Transform): b2AABB/** / Compute the bounding box of a transformed polygon */
function b2ComputePolygonAABB(shape: b2Polygon[], transform: b2Transform): b2AABB/** / Compute the bounding box of a transformed line segment */
function b2ComputeSegmentAABB(shape: b2Segment[], transform: b2Transform): b2AABB/** / Test a point for overlap with a circle in local space */
function b2PointInCircle(point: b2Vec2, shape: b2Circle[]): boolean/** / Test a point for overlap with a capsule in local space */
function b2PointInCapsule(point: b2Vec2, shape: b2Capsule[]): boolean/** / Test a point for overlap with a convex polygon in local space */
function b2PointInPolygon(point: b2Vec2, shape: b2Polygon[]): boolean/** / Ray cast versus circle shape in local space. Initial overlap is treated as a miss. */
function b2RayCastCircle(input: b2RayCastInput[], shape: b2Circle[]): b2CastOutput/** / Ray cast versus capsule shape in local space. Initial overlap is treated as a miss. */
function b2RayCastCapsule(input: b2RayCastInput[], shape: b2Capsule[]): b2CastOutput/** / the left side being treated as a miss. */
function b2RayCastSegment(input: b2RayCastInput[], shape: b2Segment[], oneSided: boolean): b2CastOutput/** / Ray cast versus polygon shape in local space. Initial overlap is treated as a miss. */
function b2RayCastPolygon(input: b2RayCastInput[], shape: b2Polygon[]): b2CastOutput/** / Shape cast versus a circle. Initial overlap is treated as a miss. */
function b2ShapeCastCircle(input: b2ShapeCastInput[], shape: b2Circle[]): b2CastOutput/** / Shape cast versus a capsule. Initial overlap is treated as a miss. */
function b2ShapeCastCapsule(input: b2ShapeCastInput[], shape: b2Capsule[]): b2CastOutput/** / Shape cast versus a line segment. Initial overlap is treated as a miss. */
function b2ShapeCastSegment(input: b2ShapeCastInput[], shape: b2Segment[]): b2CastOutput/** / Shape cast versus a convex polygon. Initial overlap is treated as a miss. */
function b2ShapeCastPolygon(input: b2ShapeCastInput[], shape: b2Polygon[]): b2CastOutput/** / @warning Do not modify a hull once it has been computed */
function b2ComputeHull(points: b2Vec2[], count: number): b2Hull/** / This is expensive and should not be called at runtime. */
function b2ValidateHull(hull: b2Hull[]): boolean/** / Compute the distance between two line segments, clamping at the end points if needed. */
function b2SegmentDistance(p1: b2Vec2, q1: b2Vec2, p2: b2Vec2, q2: b2Vec2): b2SegmentDistanceResult/** / Initially touching shapes are treated as a miss. */
function b2ShapeCast(input: b2ShapeCastPairInput[]): b2CastOutput/** / Make a proxy for use in overlap, shape cast, and related functions. This is a deep copy of the points. */
function b2MakeProxy(points: b2Vec2[], count: number, radius: number): b2ShapeProxy/** / Make a proxy with a transform. This is a deep copy of the points. */
function b2MakeOffsetProxy(points: b2Vec2[], count: number, radius: number, position: b2Vec2, rotation: b2Rot): b2ShapeProxy/** / Evaluate the transform sweep at a specific time. */
function b2GetSweepTransform(sweep: b2Sweep[], time: number): b2Transform/** / again. */
function b2TimeOfImpact(input: b2TOIInput[]): b2TOIOutput/** / Compute the contact manifold between two circles */
function b2CollideCircles(circleA: b2Circle[], xfA: b2Transform, circleB: b2Circle[], xfB: b2Transform): b2Manifold/** / Compute the contact manifold between a capsule and circle */
function b2CollideCapsules(capsuleA: b2Capsule[], xfA: b2Transform, capsuleB: b2Capsule[], xfB: b2Transform): b2Manifold/** / Compute the contact manifold between two polygons */
function b2CollidePolygons(polygonA: b2Polygon[], xfA: b2Transform, polygonB: b2Polygon[], xfB: b2Transform): b2Manifold/** / Constructing the tree initializes the node pool. */
function b2DynamicTree_Create(): b2DynamicTree/** / Destroy the tree, freeing the node pool. */
function b2DynamicTree_Destroy(tree: b2DynamicTree[]): void/** / Create a proxy. Provide an AABB and a userData value. */
function b2DynamicTree_CreateProxy(tree: b2DynamicTree[], aabb: b2AABB, categoryBits: number, userData: number): number/** / Destroy a proxy. This asserts if the id is invalid. */
function b2DynamicTree_DestroyProxy(tree: b2DynamicTree[], proxyId: number): void/** / Move a proxy to a new AABB by removing and reinserting into the tree. */
function b2DynamicTree_MoveProxy(tree: b2DynamicTree[], proxyId: number, aabb: b2AABB): void/** / Enlarge a proxy and enlarge ancestors as necessary. */
function b2DynamicTree_EnlargeProxy(tree: b2DynamicTree[], proxyId: number, aabb: b2AABB): void/** / Modify the category bits on a proxy. This is an expensive operation. */
function b2DynamicTree_SetCategoryBits(tree: b2DynamicTree[], proxyId: number, categoryBits: number): void/** / Get the category bits on a proxy. */
function b2DynamicTree_GetCategoryBits(tree: b2DynamicTree[], proxyId: number): number/** / Get the height of the binary tree. */
function b2DynamicTree_GetHeight(tree: b2DynamicTree[]): number/** / Get the ratio of the sum of the node areas to the root area. */
function b2DynamicTree_GetAreaRatio(tree: b2DynamicTree[]): number/** / Get the bounding box that contains the entire tree */
function b2DynamicTree_GetRootBounds(tree: b2DynamicTree[]): b2AABB/** / Get the number of proxies created */
function b2DynamicTree_GetProxyCount(tree: b2DynamicTree[]): number/** / Rebuild the tree while retaining subtrees that haven't changed. Returns the number of boxes sorted. */
function b2DynamicTree_Rebuild(tree: b2DynamicTree[], fullBuild: boolean): number/** / Get the number of bytes used by this tree */
function b2DynamicTree_GetByteCount(tree: b2DynamicTree[]): number/** / Get proxy user data */
function b2DynamicTree_GetUserData(tree: b2DynamicTree[], proxyId: number): number/** / Get the AABB of a proxy */
function b2DynamicTree_GetAABB(tree: b2DynamicTree[], proxyId: number): b2AABB/** / Validate this tree. For testing. */
function b2DynamicTree_Validate(tree: b2DynamicTree[]): void/** / Validate this tree has no enlarged AABBs. For testing. */
function b2DynamicTree_ValidateNoEnlarged(tree: b2DynamicTree[]): void/** / @param count the number of collision planes */
function b2SolvePlanes(targetDelta: b2Vec2, planes: b2CollisionPlane[], count: number): b2PlaneSolverResult/** / set to false are skipped. */
function b2ClipVector(vector: b2Vec2, planes: b2CollisionPlane[], count: number): b2Vec2/** / Store a world id into a uint32_t. */
function b2StoreWorldId(id: b2WorldId): number/** / Load a uint32_t into a world id. */
function b2LoadWorldId(x: number): b2WorldId/** / Store a body id into a uint64_t. */
function b2StoreBodyId(id: b2BodyId): number/** / Load a uint64_t into a body id. */
function b2LoadBodyId(x: number): b2BodyId/** / Store a shape id into a uint64_t. */
function b2StoreShapeId(id: b2ShapeId): number/** / Load a uint64_t into a shape id. */
function b2LoadShapeId(x: number): b2ShapeId/** / Store a chain id into a uint64_t. */
function b2StoreChainId(id: b2ChainId): number/** / Load a uint64_t into a chain id. */
function b2LoadChainId(x: number): b2ChainId/** / Store a joint id into a uint64_t. */
function b2StoreJointId(id: b2JointId): number/** / Load a uint64_t into a joint id. */
function b2LoadJointId(x: number): b2JointId/** / @ingroup world */
function b2DefaultWorldDef(): b2WorldDef/** / @ingroup body */
function b2DefaultBodyDef(): b2BodyDef/** / @ingroup shape */
function b2DefaultFilter(): b2Filter/** / @ingroup shape */
function b2DefaultQueryFilter(): b2QueryFilter/** / @ingroup shape */
function b2DefaultSurfaceMaterial(): b2SurfaceMaterial/** / @ingroup shape */
function b2DefaultShapeDef(): b2ShapeDef/** / @ingroup shape */
function b2DefaultChainDef(): b2ChainDef/** / @ingroup distance_joint */
function b2DefaultDistanceJointDef(): b2DistanceJointDef/** / @ingroup motor_joint */
function b2DefaultMotorJointDef(): b2MotorJointDef/** / @ingroup mouse_joint */
function b2DefaultMouseJointDef(): b2MouseJointDef/** / @ingroup filter_joint */
function b2DefaultFilterJointDef(): b2FilterJointDef/** / @ingroupd prismatic_joint */
function b2DefaultPrismaticJointDef(): b2PrismaticJointDef/** / @ingroup revolute_joint */
function b2DefaultRevoluteJointDef(): b2RevoluteJointDef/** / @ingroup weld_joint */
function b2DefaultWeldJointDef(): b2WeldJointDef/** / @ingroup wheel_joint */
function b2DefaultWheelJointDef(): b2WheelJointDef/** / @ingroup world */
function b2DefaultExplosionDef(): b2ExplosionDef/** / of the drawing functions. */
function b2DefaultDebugDraw(): b2DebugDraw/** / @return the world id. */
function b2CreateWorld(def: b2WorldDef[]): b2WorldId/** / Destroy a world */
function b2DestroyWorld(worldId: b2WorldId): void/** / World id validation. Provides validation for up to 64K allocations. */
function b2World_IsValid(id: b2WorldId): boolean/** / @param subStepCount The number of sub-steps, increasing the sub-step count can increase accuracy. Usually 4. */
function b2World_Step(worldId: b2WorldId, timeStep: number, subStepCount: number): void/** / Get the body events for the current time step. The event data is transient. Do not store a reference to this data. */
function b2World_GetBodyEvents(worldId: b2WorldId): b2BodyEvents/** / Get sensor events for the current time step. The event data is transient. Do not store a reference to this data. */
function b2World_GetSensorEvents(worldId: b2WorldId): b2SensorEvents/** / Get contact events for this current time step. The event data is transient. Do not store a reference to this data. */
function b2World_GetContactEvents(worldId: b2WorldId): b2ContactEvents/** / This is less general than b2World_CastRay() and does not allow for custom filtering. */
function b2World_CastRayClosest(worldId: b2WorldId, origin: b2Vec2, translation: b2Vec2, filter: b2QueryFilter): b2RayResult/** / @see b2WorldDef */
function b2World_EnableSleeping(worldId: b2WorldId, flag: boolean): void/** / Is body sleeping enabled? */
function b2World_IsSleepingEnabled(worldId: b2WorldId): boolean/** / @see b2WorldDef */
function b2World_EnableContinuous(worldId: b2WorldId, flag: boolean): void/** / Is continuous collision enabled? */
function b2World_IsContinuousEnabled(worldId: b2WorldId): boolean/** / @see b2WorldDef */
function b2World_SetRestitutionThreshold(worldId: b2WorldId, value: number): void/** / Get the the restitution speed threshold. Usually in meters per second. */
function b2World_GetRestitutionThreshold(worldId: b2WorldId): number/** / @see b2WorldDef::hitEventThreshold */
function b2World_SetHitEventThreshold(worldId: b2WorldId, value: number): void/** / Get the the hit event speed threshold. Usually in meters per second. */
function b2World_GetHitEventThreshold(worldId: b2WorldId): number/** / @see b2WorldDef */
function b2World_SetGravity(worldId: b2WorldId, gravity: b2Vec2): void/** / Get the gravity vector */
function b2World_GetGravity(worldId: b2WorldId): b2Vec2/** / @param explosionDef The explosion definition */
function b2World_Explode(worldId: b2WorldId, explosionDef: b2ExplosionDef[]): void/** / @note Advanced feature */
function b2World_SetContactTuning(worldId: b2WorldId, hertz: number, dampingRatio: number, pushSpeed: number): void/** / Set the maximum linear speed. Usually in m/s. */
function b2World_SetMaximumLinearSpeed(worldId: b2WorldId, maximumLinearSpeed: number): void/** / Get the maximum linear speed. Usually in m/s. */
function b2World_GetMaximumLinearSpeed(worldId: b2WorldId): number/** / warm starting greatly reduces stability and provides no performance gain. */
function b2World_EnableWarmStarting(worldId: b2WorldId, flag: boolean): void/** / Is constraint warm starting enabled? */
function b2World_IsWarmStartingEnabled(worldId: b2WorldId): boolean/** / Get the number of awake bodies. */
function b2World_GetAwakeBodyCount(worldId: b2WorldId): number/** / Get the current world performance profile */
function b2World_GetProfile(worldId: b2WorldId): b2Profile/** / Get world counters and sizes */
function b2World_GetCounters(worldId: b2WorldId): b2Counters/** / Dump memory stats to box2d_memory.txt */
function b2World_DumpMemoryStats(worldId: b2WorldId): void/** / This is for internal testing */
function b2World_RebuildStaticTree(worldId: b2WorldId): void/** / This is for internal testing */
function b2World_EnableSpeculative(worldId: b2WorldId, flag: boolean): void/** / @warning This function is locked during callbacks. */
function b2CreateBody(worldId: b2WorldId, def: b2BodyDef[]): b2BodyId/** / Do not keep references to the associated shapes and joints. */
function b2DestroyBody(bodyId: b2BodyId): void/** / Body identifier validation. Can be used to detect orphaned ids. Provides validation for up to 64K allocations. */
function b2Body_IsValid(id: b2BodyId): boolean/** / Get the body type: static, kinematic, or dynamic */
function b2Body_GetType(bodyId: b2BodyId): b2BodyType/** / properties regardless of the automatic mass setting. */
function b2Body_SetType(bodyId: b2BodyId, type: b2BodyType): void/** / Set the body name. Up to 31 characters excluding 0 termination. */
function b2Body_SetName(bodyId: b2BodyId, name: string): void/** / Get the body name. May be null. */
function b2Body_GetName(bodyId: b2BodyId): string/** / Get the world position of a body. This is the location of the body origin. */
function b2Body_GetPosition(bodyId: b2BodyId): b2Vec2/** / Get the world rotation of a body as a cosine/sine pair (complex number) */
function b2Body_GetRotation(bodyId: b2BodyId): b2Rot/** / Get the world transform of a body. */
function b2Body_GetTransform(bodyId: b2BodyId): b2Transform/** / @see b2BodyDef::position and b2BodyDef::angle */
function b2Body_SetTransform(bodyId: b2BodyId, position: b2Vec2, rotation: b2Rot): void/** / Get a local point on a body given a world point */
function b2Body_GetLocalPoint(bodyId: b2BodyId, worldPoint: b2Vec2): b2Vec2/** / Get a world point on a body given a local point */
function b2Body_GetWorldPoint(bodyId: b2BodyId, localPoint: b2Vec2): b2Vec2/** / Get a local vector on a body given a world vector */
function b2Body_GetLocalVector(bodyId: b2BodyId, worldVector: b2Vec2): b2Vec2/** / Get a world vector on a body given a local vector */
function b2Body_GetWorldVector(bodyId: b2BodyId, localVector: b2Vec2): b2Vec2/** / Get the linear velocity of a body's center of mass. Usually in meters per second. */
function b2Body_GetLinearVelocity(bodyId: b2BodyId): b2Vec2/** / Get the angular velocity of a body in radians per second */
function b2Body_GetAngularVelocity(bodyId: b2BodyId): number/** / Set the linear velocity of a body. Usually in meters per second. */
function b2Body_SetLinearVelocity(bodyId: b2BodyId, linearVelocity: b2Vec2): void/** / Set the angular velocity of a body in radians per second */
function b2Body_SetAngularVelocity(bodyId: b2BodyId, angularVelocity: number): void/** / This will automatically wake the body if asleep. */
function b2Body_SetTargetTransform(bodyId: b2BodyId, target: b2Transform, timeStep: number): void/** / Get the linear velocity of a local point attached to a body. Usually in meters per second. */
function b2Body_GetLocalPointVelocity(bodyId: b2BodyId, localPoint: b2Vec2): b2Vec2/** / Get the linear velocity of a world point attached to a body. Usually in meters per second. */
function b2Body_GetWorldPointVelocity(bodyId: b2BodyId, worldPoint: b2Vec2): b2Vec2/** / @param wake Option to wake up the body */
function b2Body_ApplyForce(bodyId: b2BodyId, force: b2Vec2, point: b2Vec2, wake: boolean): void/** / @param wake also wake up the body */
function b2Body_ApplyForceToCenter(bodyId: b2BodyId, force: b2Vec2, wake: boolean): void/** / @param wake also wake up the body */
function b2Body_ApplyTorque(bodyId: b2BodyId, torque: number, wake: boolean): void/** / use a force instead, which will work better with the sub-stepping solver. */
function b2Body_ApplyLinearImpulse(bodyId: b2BodyId, impulse: b2Vec2, point: b2Vec2, wake: boolean): void/** / use a force instead, which will work better with the sub-stepping solver. */
function b2Body_ApplyLinearImpulseToCenter(bodyId: b2BodyId, impulse: b2Vec2, wake: boolean): void/** / use a force instead, which will work better with the sub-stepping solver. */
function b2Body_ApplyAngularImpulse(bodyId: b2BodyId, impulse: number, wake: boolean): void/** / Get the mass of the body, usually in kilograms */
function b2Body_GetMass(bodyId: b2BodyId): number/** / Get the rotational inertia of the body, usually in kg*m^2 */
function b2Body_GetRotationalInertia(bodyId: b2BodyId): number/** / Get the center of mass position of the body in local space */
function b2Body_GetLocalCenterOfMass(bodyId: b2BodyId): b2Vec2/** / Get the center of mass position of the body in world space */
function b2Body_GetWorldCenterOfMass(bodyId: b2BodyId): b2Vec2/** / body type changes. */
function b2Body_SetMassData(bodyId: b2BodyId, massData: b2MassData): void/** / Get the mass data for a body */
function b2Body_GetMassData(bodyId: b2BodyId): b2MassData/** / Note that sensor shapes may have mass. */
function b2Body_ApplyMassFromShapes(bodyId: b2BodyId): void/** / Adjust the linear damping. Normally this is set in b2BodyDef before creation. */
function b2Body_SetLinearDamping(bodyId: b2BodyId, linearDamping: number): void/** / Get the current linear damping. */
function b2Body_GetLinearDamping(bodyId: b2BodyId): number/** / Adjust the angular damping. Normally this is set in b2BodyDef before creation. */
function b2Body_SetAngularDamping(bodyId: b2BodyId, angularDamping: number): void/** / Get the current angular damping. */
function b2Body_GetAngularDamping(bodyId: b2BodyId): number/** / @see b2BodyDef::gravityScale */
function b2Body_SetGravityScale(bodyId: b2BodyId, gravityScale: number): void/** / Get the current gravity scale */
function b2Body_GetGravityScale(bodyId: b2BodyId): number/** / @return true if this body is awake */
function b2Body_IsAwake(bodyId: b2BodyId): boolean/** / which can be expensive and possibly unintuitive. */
function b2Body_SetAwake(bodyId: b2BodyId, awake: boolean): void/** / Enable or disable sleeping for this body. If sleeping is disabled the body will wake. */
function b2Body_EnableSleep(bodyId: b2BodyId, enableSleep: boolean): void/** / Returns true if sleeping is enabled for this body */
function b2Body_IsSleepEnabled(bodyId: b2BodyId): boolean/** / Set the sleep threshold, usually in meters per second */
function b2Body_SetSleepThreshold(bodyId: b2BodyId, sleepThreshold: number): void/** / Get the sleep threshold, usually in meters per second. */
function b2Body_GetSleepThreshold(bodyId: b2BodyId): number/** / Returns true if this body is enabled */
function b2Body_IsEnabled(bodyId: b2BodyId): boolean/** / Disable a body by removing it completely from the simulation. This is expensive. */
function b2Body_Disable(bodyId: b2BodyId): void/** / Enable a body by adding it to the simulation. This is expensive. */
function b2Body_Enable(bodyId: b2BodyId): void/** / Set this body to have fixed rotation. This causes the mass to be reset in all cases. */
function b2Body_SetFixedRotation(bodyId: b2BodyId, flag: boolean): void/** / Does this body have fixed rotation? */
function b2Body_IsFixedRotation(bodyId: b2BodyId): boolean/** / against dynamic bodies (but not other bullets). */
function b2Body_SetBullet(bodyId: b2BodyId, flag: boolean): void/** / Is this body a bullet? */
function b2Body_IsBullet(bodyId: b2BodyId): boolean/** / @warning changing this at runtime may cause mismatched begin/end touch events */
function b2Body_EnableContactEvents(bodyId: b2BodyId, flag: boolean): void/** / @see b2ShapeDef::enableHitEvents */
function b2Body_EnableHitEvents(bodyId: b2BodyId, flag: boolean): void/** / Get the world that owns this body */
function b2Body_GetWorld(bodyId: b2BodyId): b2WorldId/** / Get the number of shapes on this body */
function b2Body_GetShapeCount(bodyId: b2BodyId): number/** / @returns the number of shape ids stored in the user array */
function b2Body_GetShapes(bodyId: b2BodyId, shapeArray: b2ShapeId[], capacity: number): number/** / Get the number of joints on this body */
function b2Body_GetJointCount(bodyId: b2BodyId): number/** / @returns the number of joint ids stored in the user array */
function b2Body_GetJoints(bodyId: b2BodyId, jointArray: b2JointId[], capacity: number): number/** / Get the maximum capacity required for retrieving all the touching contacts on a body */
function b2Body_GetContactCapacity(bodyId: b2BodyId): number/** / If there are no shapes attached then the returned AABB is empty and centered on the body origin. */
function b2Body_ComputeAABB(bodyId: b2BodyId): b2AABB/** / @return the shape id for accessing the shape */
function b2CreateCircleShape(bodyId: b2BodyId, def: b2ShapeDef[], circle: b2Circle[]): b2ShapeId/** / @return the shape id for accessing the shape */
function b2CreateSegmentShape(bodyId: b2BodyId, def: b2ShapeDef[], segment: b2Segment[]): b2ShapeId/** / @return the shape id for accessing the shape */
function b2CreateCapsuleShape(bodyId: b2BodyId, def: b2ShapeDef[], capsule: b2Capsule[]): b2ShapeId/** / @return the shape id for accessing the shape */
function b2CreatePolygonShape(bodyId: b2BodyId, def: b2ShapeDef[], polygon: b2Polygon[]): b2ShapeId/** /	@see b2Body_ApplyMassFromShapes */
function b2DestroyShape(shapeId: b2ShapeId, updateBodyMass: boolean): void/** / Shape identifier validation. Provides validation for up to 64K allocations. */
function b2Shape_IsValid(id: b2ShapeId): boolean/** / Get the type of a shape */
function b2Shape_GetType(shapeId: b2ShapeId): b2ShapeType/** / Get the id of the body that a shape is attached to */
function b2Shape_GetBody(shapeId: b2ShapeId): b2BodyId/** / Get the world that owns this shape */
function b2Shape_GetWorld(shapeId: b2ShapeId): b2WorldId/** / sensor events. */
function b2Shape_IsSensor(shapeId: b2ShapeId): boolean/** / @see b2ShapeDef::density, b2Body_ApplyMassFromShapes */
function b2Shape_SetDensity(shapeId: b2ShapeId, density: number, updateBodyMass: boolean): void/** / Get the density of a shape, usually in kg/m^2 */
function b2Shape_GetDensity(shapeId: b2ShapeId): number/** / @see b2ShapeDef::friction */
function b2Shape_SetFriction(shapeId: b2ShapeId, friction: number): void/** / Get the friction of a shape */
function b2Shape_GetFriction(shapeId: b2ShapeId): number/** / @see b2ShapeDef::restitution */
function b2Shape_SetRestitution(shapeId: b2ShapeId, restitution: number): void/** / Get the shape restitution */
function b2Shape_GetRestitution(shapeId: b2ShapeId): number/** / @see b2ShapeDef::material */
function b2Shape_SetMaterial(shapeId: b2ShapeId, material: number): void/** / Get the shape material identifier */
function b2Shape_GetMaterial(shapeId: b2ShapeId): number/** / Set the shape surface material */
function b2Shape_SetSurfaceMaterial(shapeId: b2ShapeId, surfaceMaterial: b2SurfaceMaterial): void/** / Get the shape surface material */
function b2Shape_GetSurfaceMaterial(shapeId: b2ShapeId): b2SurfaceMaterial/** / Get the shape filter */
function b2Shape_GetFilter(shapeId: b2ShapeId): b2Filter/** / @see b2ShapeDef::filter */
function b2Shape_SetFilter(shapeId: b2ShapeId, filter: b2Filter): void/** / @see b2ShapeDef::enableSensorEvents */
function b2Shape_EnableSensorEvents(shapeId: b2ShapeId, flag: boolean): void/** / Returns true if sensor events are enabled. */
function b2Shape_AreSensorEventsEnabled(shapeId: b2ShapeId): boolean/** / @warning changing this at run-time may lead to lost begin/end events */
function b2Shape_EnableContactEvents(shapeId: b2ShapeId, flag: boolean): void/** / Returns true if contact events are enabled */
function b2Shape_AreContactEventsEnabled(shapeId: b2ShapeId): boolean/** / @see b2PreSolveFcn */
function b2Shape_EnablePreSolveEvents(shapeId: b2ShapeId, flag: boolean): void/** / Returns true if pre-solve events are enabled */
function b2Shape_ArePreSolveEventsEnabled(shapeId: b2ShapeId): boolean/** / @see b2WorldDef.hitEventThreshold */
function b2Shape_EnableHitEvents(shapeId: b2ShapeId, flag: boolean): void/** / Returns true if hit events are enabled */
function b2Shape_AreHitEventsEnabled(shapeId: b2ShapeId): boolean/** / Test a point for overlap with a shape */
function b2Shape_TestPoint(shapeId: b2ShapeId, point: b2Vec2): boolean/** / Ray cast a shape directly */
function b2Shape_RayCast(shapeId: b2ShapeId, input: b2RayCastInput[]): b2CastOutput/** / Get a copy of the shape's circle. Asserts the type is correct. */
function b2Shape_GetCircle(shapeId: b2ShapeId): b2Circle/** / Get a copy of the shape's line segment. Asserts the type is correct. */
function b2Shape_GetSegment(shapeId: b2ShapeId): b2Segment/** / Asserts the type is correct. */
function b2Shape_GetChainSegment(shapeId: b2ShapeId): b2ChainSegment/** / Get a copy of the shape's capsule. Asserts the type is correct. */
function b2Shape_GetCapsule(shapeId: b2ShapeId): b2Capsule/** / Get a copy of the shape's convex polygon. Asserts the type is correct. */
function b2Shape_GetPolygon(shapeId: b2ShapeId): b2Polygon/** / @see b2Body_ApplyMassFromShapes */
function b2Shape_SetCircle(shapeId: b2ShapeId, circle: b2Circle[]): void/** / @see b2Body_ApplyMassFromShapes */
function b2Shape_SetCapsule(shapeId: b2ShapeId, capsule: b2Capsule[]): void/** / Allows you to change a shape to be a segment or update the current segment. */
function b2Shape_SetSegment(shapeId: b2ShapeId, segment: b2Segment[]): void/** / @see b2Body_ApplyMassFromShapes */
function b2Shape_SetPolygon(shapeId: b2ShapeId, polygon: b2Polygon[]): void/** / returns b2_nullChainId. */
function b2Shape_GetParentChain(shapeId: b2ShapeId): b2ChainId/** / Get the maximum capacity required for retrieving all the touching contacts on a shape */
function b2Shape_GetContactCapacity(shapeId: b2ShapeId): number/** / @returns the required capacity to get all the overlaps in b2Shape_GetSensorOverlaps */
function b2Shape_GetSensorCapacity(shapeId: b2ShapeId): number/** / @warning overlaps may contain destroyed shapes so use b2Shape_IsValid to confirm each overlap */
function b2Shape_GetSensorOverlaps(shapeId: b2ShapeId, overlaps: b2ShapeId[], capacity: number): number/** / Get the current world AABB */
function b2Shape_GetAABB(shapeId: b2ShapeId): b2AABB/** / Get the mass data for a shape */
function b2Shape_GetMassData(shapeId: b2ShapeId): b2MassData/** / todo need sample */
function b2Shape_GetClosestPoint(shapeId: b2ShapeId, target: b2Vec2): b2Vec2/** / @see b2ChainDef for details */
function b2CreateChain(bodyId: b2BodyId, def: b2ChainDef[]): b2ChainId/** / Destroy a chain shape */
function b2DestroyChain(chainId: b2ChainId): void/** / Get the world that owns this chain shape */
function b2Chain_GetWorld(chainId: b2ChainId): b2WorldId/** / Get the number of segments on this chain */
function b2Chain_GetSegmentCount(chainId: b2ChainId): number/** / the actual number of segments returned. */
function b2Chain_GetSegments(chainId: b2ChainId, segmentArray: b2ShapeId[], capacity: number): number/** / @see b2ChainDef::friction */
function b2Chain_SetFriction(chainId: b2ChainId, friction: number): void/** / Get the chain friction */
function b2Chain_GetFriction(chainId: b2ChainId): number/** / @see b2ChainDef::restitution */
function b2Chain_SetRestitution(chainId: b2ChainId, restitution: number): void/** / Get the chain restitution */
function b2Chain_GetRestitution(chainId: b2ChainId): number/** / @see b2ChainDef::material */
function b2Chain_SetMaterial(chainId: b2ChainId, material: number): void/** / Get the chain material */
function b2Chain_GetMaterial(chainId: b2ChainId): number/** / Chain identifier validation. Provides validation for up to 64K allocations. */
function b2Chain_IsValid(id: b2ChainId): boolean/** / Destroy a joint */
function b2DestroyJoint(jointId: b2JointId): void/** / Joint identifier validation. Provides validation for up to 64K allocations. */
function b2Joint_IsValid(id: b2JointId): boolean/** / Get the joint type */
function b2Joint_GetType(jointId: b2JointId): b2JointType/** / Get body A id on a joint */
function b2Joint_GetBodyA(jointId: b2JointId): b2BodyId/** / Get body B id on a joint */
function b2Joint_GetBodyB(jointId: b2JointId): b2BodyId/** / Get the world that owns this joint */
function b2Joint_GetWorld(jointId: b2JointId): b2WorldId/** / Set the local anchor on bodyA */
function b2Joint_SetLocalAnchorA(jointId: b2JointId, localAnchor: b2Vec2): void/** / Get the local anchor on bodyA */
function b2Joint_GetLocalAnchorA(jointId: b2JointId): b2Vec2/** / Set the local anchor on bodyB */
function b2Joint_SetLocalAnchorB(jointId: b2JointId, localAnchor: b2Vec2): void/** / Get the local anchor on bodyB */
function b2Joint_GetLocalAnchorB(jointId: b2JointId): b2Vec2/** / Get the joint reference angle in radians (revolute, prismatic, and weld) */
function b2Joint_GetReferenceAngle(jointId: b2JointId): number/** / Set the joint reference angle in radians, must be in [-pi,pi]. (revolute, prismatic, and weld) */
function b2Joint_SetReferenceAngle(jointId: b2JointId, angleInRadians: number): void/** / Set the local axis on bodyA (prismatic and wheel) */
function b2Joint_SetLocalAxisA(jointId: b2JointId, localAxis: b2Vec2): void/** / Get the local axis on bodyA (prismatic and wheel) */
function b2Joint_GetLocalAxisA(jointId: b2JointId): b2Vec2/** / Toggle collision between connected bodies */
function b2Joint_SetCollideConnected(jointId: b2JointId, shouldCollide: boolean): void/** / Is collision allowed between connected bodies? */
function b2Joint_GetCollideConnected(jointId: b2JointId): boolean/** / Wake the bodies connect to this joint */
function b2Joint_WakeBodies(jointId: b2JointId): void/** / Get the current constraint force for this joint. Usually in Newtons. */
function b2Joint_GetConstraintForce(jointId: b2JointId): b2Vec2/** / Get the current constraint torque for this joint. Usually in Newton * meters. */
function b2Joint_GetConstraintTorque(jointId: b2JointId): number/** / Get the current linear separation error for this joint. Does not consider admissible movement. Usually in meters. */
function b2Joint_GetLinearSeparation(jointId: b2JointId): number/** / Get the current angular separation error for this joint. Does not consider admissible movement. Usually in meters. */
function b2Joint_GetAngularSeparation(jointId: b2JointId): number/** / Get the joint constraint tuning. Advanced feature. */
function b2Joint_GetConstraintTuning(jointId: b2JointId, hertz: number[], dampingRatio: number[]): void/** / @param dampingRatio the non-dimensional damping ratio (one for critical damping) */
function b2Joint_SetConstraintTuning(jointId: b2JointId, hertz: number, dampingRatio: number): void/** / @see b2DistanceJointDef for details */
function b2CreateDistanceJoint(worldId: b2WorldId, def: b2DistanceJointDef[]): b2JointId/** / @param length The new distance joint length */
function b2DistanceJoint_SetLength(jointId: b2JointId, length: number): void/** / Get the rest length of a distance joint */
function b2DistanceJoint_GetLength(jointId: b2JointId): number/** / Enable/disable the distance joint spring. When disabled the distance joint is rigid. */
function b2DistanceJoint_EnableSpring(jointId: b2JointId, enableSpring: boolean): void/** / Is the distance joint spring enabled? */
function b2DistanceJoint_IsSpringEnabled(jointId: b2JointId): boolean/** / Set the spring stiffness in Hertz */
function b2DistanceJoint_SetSpringHertz(jointId: b2JointId, hertz: number): void/** / Set the spring damping ratio, non-dimensional */
function b2DistanceJoint_SetSpringDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the spring Hertz */
function b2DistanceJoint_GetSpringHertz(jointId: b2JointId): number/** / Get the spring damping ratio */
function b2DistanceJoint_GetSpringDampingRatio(jointId: b2JointId): number/** / and the limit has no effect. */
function b2DistanceJoint_EnableLimit(jointId: b2JointId, enableLimit: boolean): void/** / Is the distance joint limit enabled? */
function b2DistanceJoint_IsLimitEnabled(jointId: b2JointId): boolean/** / Set the minimum and maximum length parameters of a distance joint */
function b2DistanceJoint_SetLengthRange(jointId: b2JointId, minLength: number, maxLength: number): void/** / Get the distance joint minimum length */
function b2DistanceJoint_GetMinLength(jointId: b2JointId): number/** / Get the distance joint maximum length */
function b2DistanceJoint_GetMaxLength(jointId: b2JointId): number/** / Get the current length of a distance joint */
function b2DistanceJoint_GetCurrentLength(jointId: b2JointId): number/** / Enable/disable the distance joint motor */
function b2DistanceJoint_EnableMotor(jointId: b2JointId, enableMotor: boolean): void/** / Is the distance joint motor enabled? */
function b2DistanceJoint_IsMotorEnabled(jointId: b2JointId): boolean/** / Set the distance joint motor speed, usually in meters per second */
function b2DistanceJoint_SetMotorSpeed(jointId: b2JointId, motorSpeed: number): void/** / Get the distance joint motor speed, usually in meters per second */
function b2DistanceJoint_GetMotorSpeed(jointId: b2JointId): number/** / Set the distance joint maximum motor force, usually in newtons */
function b2DistanceJoint_SetMaxMotorForce(jointId: b2JointId, force: number): void/** / Get the distance joint maximum motor force, usually in newtons */
function b2DistanceJoint_GetMaxMotorForce(jointId: b2JointId): number/** / Get the distance joint current motor force, usually in newtons */
function b2DistanceJoint_GetMotorForce(jointId: b2JointId): number/** / @see b2MotorJointDef for details */
function b2CreateMotorJoint(worldId: b2WorldId, def: b2MotorJointDef[]): b2JointId/** / Set the motor joint linear offset target */
function b2MotorJoint_SetLinearOffset(jointId: b2JointId, linearOffset: b2Vec2): void/** / Get the motor joint linear offset target */
function b2MotorJoint_GetLinearOffset(jointId: b2JointId): b2Vec2/** / so the motor will drive along the shortest arc. */
function b2MotorJoint_SetAngularOffset(jointId: b2JointId, angularOffset: number): void/** / Get the motor joint angular offset target in radians */
function b2MotorJoint_GetAngularOffset(jointId: b2JointId): number/** / Set the motor joint maximum force, usually in newtons */
function b2MotorJoint_SetMaxForce(jointId: b2JointId, maxForce: number): void/** / Get the motor joint maximum force, usually in newtons */
function b2MotorJoint_GetMaxForce(jointId: b2JointId): number/** / Set the motor joint maximum torque, usually in newton-meters */
function b2MotorJoint_SetMaxTorque(jointId: b2JointId, maxTorque: number): void/** / Get the motor joint maximum torque, usually in newton-meters */
function b2MotorJoint_GetMaxTorque(jointId: b2JointId): number/** / Set the motor joint correction factor, usually in [0, 1] */
function b2MotorJoint_SetCorrectionFactor(jointId: b2JointId, correctionFactor: number): void/** / Get the motor joint correction factor, usually in [0, 1] */
function b2MotorJoint_GetCorrectionFactor(jointId: b2JointId): number/** / @see b2MouseJointDef for details */
function b2CreateMouseJoint(worldId: b2WorldId, def: b2MouseJointDef[]): b2JointId/** / Set the mouse joint target */
function b2MouseJoint_SetTarget(jointId: b2JointId, target: b2Vec2): void/** / Get the mouse joint target */
function b2MouseJoint_GetTarget(jointId: b2JointId): b2Vec2/** / Set the mouse joint spring stiffness in Hertz */
function b2MouseJoint_SetSpringHertz(jointId: b2JointId, hertz: number): void/** / Get the mouse joint spring stiffness in Hertz */
function b2MouseJoint_GetSpringHertz(jointId: b2JointId): number/** / Set the mouse joint spring damping ratio, non-dimensional */
function b2MouseJoint_SetSpringDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the mouse joint damping ratio, non-dimensional */
function b2MouseJoint_GetSpringDampingRatio(jointId: b2JointId): number/** / Set the mouse joint maximum force, usually in newtons */
function b2MouseJoint_SetMaxForce(jointId: b2JointId, maxForce: number): void/** / Get the mouse joint maximum force, usually in newtons */
function b2MouseJoint_GetMaxForce(jointId: b2JointId): number/** / @see b2FilterJointDef for details */
function b2CreateFilterJoint(worldId: b2WorldId, def: b2FilterJointDef[]): b2JointId/** / @see b2PrismaticJointDef for details */
function b2CreatePrismaticJoint(worldId: b2WorldId, def: b2PrismaticJointDef[]): b2JointId/** / Enable/disable the joint spring. */
function b2PrismaticJoint_EnableSpring(jointId: b2JointId, enableSpring: boolean): void/** / Is the prismatic joint spring enabled or not? */
function b2PrismaticJoint_IsSpringEnabled(jointId: b2JointId): boolean/** / runs at 60Hz then the joint stiffness should be 15Hz or less. */
function b2PrismaticJoint_SetSpringHertz(jointId: b2JointId, hertz: number): void/** / Get the prismatic joint stiffness in Hertz */
function b2PrismaticJoint_GetSpringHertz(jointId: b2JointId): number/** / Set the prismatic joint damping ratio (non-dimensional) */
function b2PrismaticJoint_SetSpringDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the prismatic spring damping ratio (non-dimensional) */
function b2PrismaticJoint_GetSpringDampingRatio(jointId: b2JointId): number/** / Set the prismatic joint spring target angle, usually in meters */
function b2PrismaticJoint_SetTargetTranslation(jointId: b2JointId, translation: number): void/** / Get the prismatic joint spring target translation, usually in meters */
function b2PrismaticJoint_GetTargetTranslation(jointId: b2JointId): number/** / Enable/disable a prismatic joint limit */
function b2PrismaticJoint_EnableLimit(jointId: b2JointId, enableLimit: boolean): void/** / Is the prismatic joint limit enabled? */
function b2PrismaticJoint_IsLimitEnabled(jointId: b2JointId): boolean/** / Get the prismatic joint lower limit */
function b2PrismaticJoint_GetLowerLimit(jointId: b2JointId): number/** / Get the prismatic joint upper limit */
function b2PrismaticJoint_GetUpperLimit(jointId: b2JointId): number/** / Set the prismatic joint limits */
function b2PrismaticJoint_SetLimits(jointId: b2JointId, lower: number, upper: number): void/** / Enable/disable a prismatic joint motor */
function b2PrismaticJoint_EnableMotor(jointId: b2JointId, enableMotor: boolean): void/** / Is the prismatic joint motor enabled? */
function b2PrismaticJoint_IsMotorEnabled(jointId: b2JointId): boolean/** / Set the prismatic joint motor speed, usually in meters per second */
function b2PrismaticJoint_SetMotorSpeed(jointId: b2JointId, motorSpeed: number): void/** / Get the prismatic joint motor speed, usually in meters per second */
function b2PrismaticJoint_GetMotorSpeed(jointId: b2JointId): number/** / Set the prismatic joint maximum motor force, usually in newtons */
function b2PrismaticJoint_SetMaxMotorForce(jointId: b2JointId, force: number): void/** / Get the prismatic joint maximum motor force, usually in newtons */
function b2PrismaticJoint_GetMaxMotorForce(jointId: b2JointId): number/** / Get the prismatic joint current motor force, usually in newtons */
function b2PrismaticJoint_GetMotorForce(jointId: b2JointId): number/** / Get the current joint translation, usually in meters. */
function b2PrismaticJoint_GetTranslation(jointId: b2JointId): number/** / Get the current joint translation speed, usually in meters per second. */
function b2PrismaticJoint_GetSpeed(jointId: b2JointId): number/** / @see b2RevoluteJointDef for details */
function b2CreateRevoluteJoint(worldId: b2WorldId, def: b2RevoluteJointDef[]): b2JointId/** / Enable/disable the revolute joint spring */
function b2RevoluteJoint_EnableSpring(jointId: b2JointId, enableSpring: boolean): void/** / It the revolute angular spring enabled? */
function b2RevoluteJoint_IsSpringEnabled(jointId: b2JointId): boolean/** / Set the revolute joint spring stiffness in Hertz */
function b2RevoluteJoint_SetSpringHertz(jointId: b2JointId, hertz: number): void/** / Get the revolute joint spring stiffness in Hertz */
function b2RevoluteJoint_GetSpringHertz(jointId: b2JointId): number/** / Set the revolute joint spring damping ratio, non-dimensional */
function b2RevoluteJoint_SetSpringDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the revolute joint spring damping ratio, non-dimensional */
function b2RevoluteJoint_GetSpringDampingRatio(jointId: b2JointId): number/** / Set the revolute joint spring target angle, radians */
function b2RevoluteJoint_SetTargetAngle(jointId: b2JointId, angle: number): void/** / Get the revolute joint spring target angle, radians */
function b2RevoluteJoint_GetTargetAngle(jointId: b2JointId): number/** / @see b2RevoluteJointDef::referenceAngle */
function b2RevoluteJoint_GetAngle(jointId: b2JointId): number/** / Enable/disable the revolute joint limit */
function b2RevoluteJoint_EnableLimit(jointId: b2JointId, enableLimit: boolean): void/** / Is the revolute joint limit enabled? */
function b2RevoluteJoint_IsLimitEnabled(jointId: b2JointId): boolean/** / Get the revolute joint lower limit in radians */
function b2RevoluteJoint_GetLowerLimit(jointId: b2JointId): number/** / Get the revolute joint upper limit in radians */
function b2RevoluteJoint_GetUpperLimit(jointId: b2JointId): number/** / and that -0.99 * B2_PI <= lower && upper <= -0.99 * B2_PI. */
function b2RevoluteJoint_SetLimits(jointId: b2JointId, lower: number, upper: number): void/** / Enable/disable a revolute joint motor */
function b2RevoluteJoint_EnableMotor(jointId: b2JointId, enableMotor: boolean): void/** / Is the revolute joint motor enabled? */
function b2RevoluteJoint_IsMotorEnabled(jointId: b2JointId): boolean/** / Set the revolute joint motor speed in radians per second */
function b2RevoluteJoint_SetMotorSpeed(jointId: b2JointId, motorSpeed: number): void/** / Get the revolute joint motor speed in radians per second */
function b2RevoluteJoint_GetMotorSpeed(jointId: b2JointId): number/** / Get the revolute joint current motor torque, usually in newton-meters */
function b2RevoluteJoint_GetMotorTorque(jointId: b2JointId): number/** / Set the revolute joint maximum motor torque, usually in newton-meters */
function b2RevoluteJoint_SetMaxMotorTorque(jointId: b2JointId, torque: number): void/** / Get the revolute joint maximum motor torque, usually in newton-meters */
function b2RevoluteJoint_GetMaxMotorTorque(jointId: b2JointId): number/** / @see b2WeldJointDef for details */
function b2CreateWeldJoint(worldId: b2WorldId, def: b2WeldJointDef[]): b2JointId/** / Set the weld joint linear stiffness in Hertz. 0 is rigid. */
function b2WeldJoint_SetLinearHertz(jointId: b2JointId, hertz: number): void/** / Get the weld joint linear stiffness in Hertz */
function b2WeldJoint_GetLinearHertz(jointId: b2JointId): number/** / Set the weld joint linear damping ratio (non-dimensional) */
function b2WeldJoint_SetLinearDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the weld joint linear damping ratio (non-dimensional) */
function b2WeldJoint_GetLinearDampingRatio(jointId: b2JointId): number/** / Set the weld joint angular stiffness in Hertz. 0 is rigid. */
function b2WeldJoint_SetAngularHertz(jointId: b2JointId, hertz: number): void/** / Get the weld joint angular stiffness in Hertz */
function b2WeldJoint_GetAngularHertz(jointId: b2JointId): number/** / Set weld joint angular damping ratio, non-dimensional */
function b2WeldJoint_SetAngularDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the weld joint angular damping ratio, non-dimensional */
function b2WeldJoint_GetAngularDampingRatio(jointId: b2JointId): number/** / @see b2WheelJointDef for details */
function b2CreateWheelJoint(worldId: b2WorldId, def: b2WheelJointDef[]): b2JointId/** / Enable/disable the wheel joint spring */
function b2WheelJoint_EnableSpring(jointId: b2JointId, enableSpring: boolean): void/** / Is the wheel joint spring enabled? */
function b2WheelJoint_IsSpringEnabled(jointId: b2JointId): boolean/** / Set the wheel joint stiffness in Hertz */
function b2WheelJoint_SetSpringHertz(jointId: b2JointId, hertz: number): void/** / Get the wheel joint stiffness in Hertz */
function b2WheelJoint_GetSpringHertz(jointId: b2JointId): number/** / Set the wheel joint damping ratio, non-dimensional */
function b2WheelJoint_SetSpringDampingRatio(jointId: b2JointId, dampingRatio: number): void/** / Get the wheel joint damping ratio, non-dimensional */
function b2WheelJoint_GetSpringDampingRatio(jointId: b2JointId): number/** / Enable/disable the wheel joint limit */
function b2WheelJoint_EnableLimit(jointId: b2JointId, enableLimit: boolean): void/** / Is the wheel joint limit enabled? */
function b2WheelJoint_IsLimitEnabled(jointId: b2JointId): boolean/** / Get the wheel joint lower limit */
function b2WheelJoint_GetLowerLimit(jointId: b2JointId): number/** / Get the wheel joint upper limit */
function b2WheelJoint_GetUpperLimit(jointId: b2JointId): number/** / Set the wheel joint limits */
function b2WheelJoint_SetLimits(jointId: b2JointId, lower: number, upper: number): void/** / Enable/disable the wheel joint motor */
function b2WheelJoint_EnableMotor(jointId: b2JointId, enableMotor: boolean): void/** / Is the wheel joint motor enabled? */
function b2WheelJoint_IsMotorEnabled(jointId: b2JointId): boolean/** / Set the wheel joint motor speed in radians per second */
function b2WheelJoint_SetMotorSpeed(jointId: b2JointId, motorSpeed: number): void/** / Get the wheel joint motor speed in radians per second */
function b2WheelJoint_GetMotorSpeed(jointId: b2JointId): number/** / Set the wheel joint maximum motor torque, usually in newton-meters */
function b2WheelJoint_SetMaxMotorTorque(jointId: b2JointId, torque: number): void/** / Get the wheel joint maximum motor torque, usually in newton-meters */
function b2WheelJoint_GetMaxMotorTorque(jointId: b2JointId): number/** / Get the wheel joint current motor torque, usually in newton-meters */
function b2WheelJoint_GetMotorTorque(jointId: b2JointId): number/**  */
var b2_toiStateUnknown: number/**  */
var b2_toiStateFailed: number/**  */
var b2_toiStateOverlapped: number/**  */
var b2_toiStateHit: number/**  */
var b2_toiStateSeparated: number/**  */
var b2_staticBody: number/**  */
var b2_kinematicBody: number/**  */
var b2_dynamicBody: number/**  */
var b2_bodyTypeCount: number/**  */
var b2_circleShape: number/**  */
var b2_capsuleShape: number/**  */
var b2_segmentShape: number/**  */
var b2_polygonShape: number/**  */
var b2_chainSegmentShape: number/**  */
var b2_shapeTypeCount: number/**  */
var b2_distanceJoint: number/**  */
var b2_filterJoint: number/**  */
var b2_motorJoint: number/**  */
var b2_mouseJoint: number/**  */
var b2_prismaticJoint: number/**  */
var b2_revoluteJoint: number/**  */
var b2_weldJoint: number/**  */
var b2_wheelJoint: number/**  */
var b2_colorAliceBlue: number/**  */
var b2_colorAntiqueWhite: number/**  */
var b2_colorAqua: number/**  */
var b2_colorAquamarine: number/**  */
var b2_colorAzure: number/**  */
var b2_colorBeige: number/**  */
var b2_colorBisque: number/**  */
var b2_colorBlack: number/**  */
var b2_colorBlanchedAlmond: number/**  */
var b2_colorBlue: number/**  */
var b2_colorBlueViolet: number/**  */
var b2_colorBrown: number/**  */
var b2_colorBurlywood: number/**  */
var b2_colorCadetBlue: number/**  */
var b2_colorChartreuse: number/**  */
var b2_colorChocolate: number/**  */
var b2_colorCoral: number/**  */
var b2_colorCornflowerBlue: number/**  */
var b2_colorCornsilk: number/**  */
var b2_colorCrimson: number/**  */
var b2_colorCyan: number/**  */
var b2_colorDarkBlue: number/**  */
var b2_colorDarkCyan: number/**  */
var b2_colorDarkGoldenRod: number/**  */
var b2_colorDarkGray: number/**  */
var b2_colorDarkGreen: number/**  */
var b2_colorDarkKhaki: number/**  */
var b2_colorDarkMagenta: number/**  */
var b2_colorDarkOliveGreen: number/**  */
var b2_colorDarkOrange: number/**  */
var b2_colorDarkOrchid: number/**  */
var b2_colorDarkRed: number/**  */
var b2_colorDarkSalmon: number/**  */
var b2_colorDarkSeaGreen: number/**  */
var b2_colorDarkSlateBlue: number/**  */
var b2_colorDarkSlateGray: number/**  */
var b2_colorDarkTurquoise: number/**  */
var b2_colorDarkViolet: number/**  */
var b2_colorDeepPink: number/**  */
var b2_colorDeepSkyBlue: number/**  */
var b2_colorDimGray: number/**  */
var b2_colorDodgerBlue: number/**  */
var b2_colorFireBrick: number/**  */
var b2_colorFloralWhite: number/**  */
var b2_colorForestGreen: number/**  */
var b2_colorFuchsia: number/**  */
var b2_colorGainsboro: number/**  */
var b2_colorGhostWhite: number/**  */
var b2_colorGold: number/**  */
var b2_colorGoldenRod: number/**  */
var b2_colorGray: number/**  */
var b2_colorGreen: number/**  */
var b2_colorGreenYellow: number/**  */
var b2_colorHoneyDew: number/**  */
var b2_colorHotPink: number/**  */
var b2_colorIndianRed: number/**  */
var b2_colorIndigo: number/**  */
var b2_colorIvory: number/**  */
var b2_colorKhaki: number/**  */
var b2_colorLavender: number/**  */
var b2_colorLavenderBlush: number/**  */
var b2_colorLawnGreen: number/**  */
var b2_colorLemonChiffon: number/**  */
var b2_colorLightBlue: number/**  */
var b2_colorLightCoral: number/**  */
var b2_colorLightCyan: number/**  */
var b2_colorLightGoldenRodYellow: number/**  */
var b2_colorLightGray: number/**  */
var b2_colorLightGreen: number/**  */
var b2_colorLightPink: number/**  */
var b2_colorLightSalmon: number/**  */
var b2_colorLightSeaGreen: number/**  */
var b2_colorLightSkyBlue: number/**  */
var b2_colorLightSlateGray: number/**  */
var b2_colorLightSteelBlue: number/**  */
var b2_colorLightYellow: number/**  */
var b2_colorLime: number/**  */
var b2_colorLimeGreen: number/**  */
var b2_colorLinen: number/**  */
var b2_colorMagenta: number/**  */
var b2_colorMaroon: number/**  */
var b2_colorMediumAquaMarine: number/**  */
var b2_colorMediumBlue: number/**  */
var b2_colorMediumOrchid: number/**  */
var b2_colorMediumPurple: number/**  */
var b2_colorMediumSeaGreen: number/**  */
var b2_colorMediumSlateBlue: number/**  */
var b2_colorMediumSpringGreen: number/**  */
var b2_colorMediumTurquoise: number/**  */
var b2_colorMediumVioletRed: number/**  */
var b2_colorMidnightBlue: number/**  */
var b2_colorMintCream: number/**  */
var b2_colorMistyRose: number/**  */
var b2_colorMoccasin: number/**  */
var b2_colorNavajoWhite: number/**  */
var b2_colorNavy: number/**  */
var b2_colorOldLace: number/**  */
var b2_colorOlive: number/**  */
var b2_colorOliveDrab: number/**  */
var b2_colorOrange: number/**  */
var b2_colorOrangeRed: number/**  */
var b2_colorOrchid: number/**  */
var b2_colorPaleGoldenRod: number/**  */
var b2_colorPaleGreen: number/**  */
var b2_colorPaleTurquoise: number/**  */
var b2_colorPaleVioletRed: number/**  */
var b2_colorPapayaWhip: number/**  */
var b2_colorPeachPuff: number/**  */
var b2_colorPeru: number/**  */
var b2_colorPink: number/**  */
var b2_colorPlum: number/**  */
var b2_colorPowderBlue: number/**  */
var b2_colorPurple: number/**  */
var b2_colorRebeccaPurple: number/**  */
var b2_colorRed: number/**  */
var b2_colorRosyBrown: number/**  */
var b2_colorRoyalBlue: number/**  */
var b2_colorSaddleBrown: number/**  */
var b2_colorSalmon: number/**  */
var b2_colorSandyBrown: number/**  */
var b2_colorSeaGreen: number/**  */
var b2_colorSeaShell: number/**  */
var b2_colorSienna: number/**  */
var b2_colorSilver: number/**  */
var b2_colorSkyBlue: number/**  */
var b2_colorSlateBlue: number/**  */
var b2_colorSlateGray: number/**  */
var b2_colorSnow: number/**  */
var b2_colorSpringGreen: number/**  */
var b2_colorSteelBlue: number/**  */
var b2_colorTan: number/**  */
var b2_colorTeal: number/**  */
var b2_colorThistle: number/**  */
var b2_colorTomato: number/**  */
var b2_colorTurquoise: number/**  */
var b2_colorViolet: number/**  */
var b2_colorWheat: number/**  */
var b2_colorWhite: number/**  */
var b2_colorWhiteSmoke: number/**  */
var b2_colorYellow: number/**  */
var b2_colorYellowGreen: number/**  */
var b2_colorBox2DRed: number/**  */
var b2_colorBox2DBlue: number/**  */
var b2_colorBox2DGreen: number/**  */
var b2_colorBox2DYellow: number/** / Simple djb2 hash function for determinism testing */
var B2_HASH_INIT: number/** / https://en.wikipedia.org/wiki/Pi */
var B2_PI: number/** / don't use more vertices. */
var B2_MAX_POLYGON_VERTICES: number/**  */
var B2_DEFAULT_CATEGORY_BITS: number}
