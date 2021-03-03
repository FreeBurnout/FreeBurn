#include <rwcore.h>

#include "BoCollidingBody.h"
#include "../World/Common/BoCrashCombo.h"
#include "../World/Common/Traffic/BoTrafficVehicle.h"
#include "BoDrivableVehiclePhysics.h"

void CBoCollidingBody::Construct() {
}

bool CBoCollidingBody::Prepare() {
    return false;
}

void CBoCollidingBody::Update(float) {
}

void CBoCollidingBody::Integrate(float) {
}

void CBoCollidingBody::ApplyTotalTranslation() {
}

void CBoCollidingBody::Release() {
}

void CBoCollidingBody::Destruct() {
}

void CBoCollidingBody::SetInitialMatrix(const CGtMatrix3x4&) {
}

void CBoCollidingBody::SetRealisticMomentsOfInertia() {
}

void CBoCollidingBody::CacheWorldTriangles(CGtSphere) {
}

bool CBoCollidingBody::AddCachedWorldTriangle(const CGtPolygonIntersectionResult&) {
    return false;
}

void CBoCollidingBody::StartCrashing(unsigned char, CBoCrashStartInfo*) {
}

void CBoCollidingBody::StopCrashing() {
}

void CBoCollidingBody::CollideWithWorld(int) {
}

void CBoCollidingBody::StopImmediately() {
}

void CBoCollidingBody::ClearAccumulatedValues() {
}

RwReal CBoCollidingBody::CalculateCollisionImpulseWithBody(CBoCollidingBody&, CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*) {
    return RwReal();
}

RwReal CBoCollidingBody::CalculateCollisionImpulseWithTraffic(CBoTrafficVehicle*, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*) {
    return RwReal();
}

RwReal CBoCollidingBody::CalculateCollisionImpulseWithInanimateObject(CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*) {
    return RwReal();
}

RwBool CBoCollidingBody::HasFallenThroughWorld() {
    return RwBool();
}

void CBoCollidingBody::SetMatrix(const CGtMatrix3x4&) {
}

CGtMatrix3x4 CBoCollidingBody::GetMatrix() const {
    return CGtMatrix3x4();
}

CGtMatrix3x4* CBoCollidingBody::GetInverseMatrix() const {
    return nullptr;
}

void CBoCollidingBody::SetMomentOfInertia(float, float, float) {
}

void CBoCollidingBody::SetBoundingBox(const CGtAxisAlignedBox&) {
}

void CBoCollidingBody::GetBoundingBox(CGtAxisAlignedBox*) {
}

void CBoCollidingBody::WorldPointToLocalPoint(CGtV3d, CGtV3d*) {
}

void CBoCollidingBody::LocalPointToWorldPoint(CGtV3d, CGtV3d*) {
}

void CBoCollidingBody::LocalVectorToWorldVector(CGtV3d, CGtV3d*) {
}

void CBoCollidingBody::WorldVectorToLocalVector(CGtV3d, CGtV3d*) {
}

void CBoCollidingBody::ApplyPositionedImpulse(CGtV3d, CGtV3d, EBoForceType) {
}

void CBoCollidingBody::ApplyPositionedForce(CGtV3d, CGtV3d, EBoForceType) {
}

void CBoCollidingBody::ApplyCOMForce(CGtV3d, EBoForceType) {
}

void CBoCollidingBody::ApplyCOMImpulse(CGtV3d, EBoForceType) {
}

void CBoCollidingBody::ApplyTorque(CGtV3d) {
}

void CBoCollidingBody::Translate(CGtV3d) {
}

void CBoCollidingBody::NeutralizeAtComponentOfAngularMomentum() {
}

bool CBoCollidingBody::IsStoppedDead() const {
    return false;
}

void CBoCollidingBody::SetStoppedDead(bool) {
}

bool CBoCollidingBody::IsCrashing() const {
    return false;
}

CGtV3d CBoCollidingBody::GetPointVelocity(CGtV3d) {
    return CGtV3d();
}

CGtV3d CBoCollidingBody::GetLinearVelocity() const {
    return CGtV3d();
}

CGtV3d CBoCollidingBody::GetAngularVelocity() const {
    return CGtV3d();
}

CGtV3d CBoCollidingBody::GetVelocityDir() const {
    return CGtV3d();
}

CGtV3d CBoCollidingBody::GetPosition() const {
    return CGtV3d();
}

RwReal CBoCollidingBody::GetSpeedKPH() const {
    return RwReal();
}

RwReal CBoCollidingBody::GetSpeedMPH() const {
    return RwReal();
}

RwReal CBoCollidingBody::GetSpeedMPS() const {
    return RwReal();
}

RwInt32 CBoCollidingBody::GetCurrentWorldUnit() const {
    return RwInt32();
}

RwUInt64 CBoCollidingBody::GetCrashIndex() const {
    return RwUInt64();
}

ECollidingBodyType CBoCollidingBody::GetType() const {
    return ECollidingBodyType();
}

bool CBoCollidingBody::IsVehicle() const {
    return false;
}

bool CBoCollidingBody::GetWorldCollision() const {
    return false;
}

CBoWorldCollisionInfo CBoCollidingBody::GetWorldCollisionInfo() {
    return CBoWorldCollisionInfo();
}

RwReal CBoCollidingBody::GetMass() const {
    return RwReal();
}

void CBoCollidingBody::CalculateTorqueFromPositionedForce(CGtV3d*, CGtV3d, CGtV3d) {
}

RwInt32 CBoCollidingBody::GetCollisionWorldIndex() const {
    return RwInt32();
}

void CBoCollidingBody::SetCollisionWorldIndex(int) {
}

bool CBoCollidingBody::GetBodyCollision() const {
    return false;
}

CBoConvexHull* CBoCollidingBody::GetConvexHull() {
    return nullptr;
}

CGtV4d CBoCollidingBody::GetBoundingSphere() {
    return CGtV4d();
}

void CBoCollidingBody::SetLinearVelocity(CGtV3d) {
}

bool CBoCollidingBody::IsOutsideCollision() {
    return false;
}

EBoBoundingShape CBoCollidingBody::GetBoundingShape() const {
    return EBoBoundingShape();
}

RwReal CBoCollidingBody::CalculateEnergyFromCollisionImpulse(CBoCollidingBody*, CBoCollidingBody*, CGtV3d, float) {
    return RwReal();
}

CBoActiveBody* CBoCollidingBody::GetActiveBody() {
    return nullptr;
}

void CBoCollidingBody::SetActiveBody(CBoActiveBody*) {
}

bool CBoCollidingBody::HasHadBodyCollision() const {
    return false;
}

bool CBoCollidingBody::HasHadWorldCollision() const {
    return false;
}

bool CBoCollidingBody::HasHadCollision() const {
    return false;
}

bool CBoCollidingBody::DebugCheckWorldIntersection() {
    return false;
}

void CBoCollidingBody::OutputForcesDebug(char*, EBoForceType, const CGtV3d*, const CGtV3d*) {
}
