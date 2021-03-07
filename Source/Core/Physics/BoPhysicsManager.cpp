#include <rwcore.h>

#include "BoVehiclePhysics.h"
#include "BoPhysicsManager.h"
#include "BoCheckedTrafficPhysics.h"
#include "BoBodyPartPhysics.h"
#include "../World/Common/Traffic/BoTrafficVehicle.h"
#include "../World/Common/BoRaceCar.h"
#include "../World/Common/BoPropType.h"
#include "../World/Common/BoPlayerCar.h"
#include "../World/Common/BoCrashCombo.h"
#include "../Camera/Behaviours/BoCameraBehaviour.h"
#include "../../Shared/Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

RwReal krSpeedDiff = 17.8816; // In m/s. Default value 17.8816 m/s = 40 mph.

bool CBoPhysicsManager::ActuallyCrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char) {
    return false;
}

CBoBodyPartPhysics* CBoPhysicsManager::AddBodyPart(CBoVehiclePhysics*, int, EBodyPartType) {
    return nullptr;
}

CBoCameraPhysics* CBoPhysicsManager::AddCamera(EPlayerCarIndex, CBoCameraBehaviour*, CGtMatrix3x4*, CGtV3d, CGtV3d) {
    return nullptr;
}

void CBoPhysicsManager::AddRaceCar(CBoRaceCar*, int) {
}

CBoActiveBody* CBoPhysicsManager::AddStaticProp(CBoPropInstance*, CGtMatrix3x4*) {
    return nullptr;
}

void CBoPhysicsManager::AddTrafficVehicle(CBoTrafficVehicle*) {
}

void CBoPhysicsManager::ApplySafePositionedImpulse(CBoCollidingBody*, CGtV3d, CGtV3d, EBoForceType) {
}

void CBoPhysicsManager::ApplyShuntOrSlamReaction(CBoCollidingPair*, float*, float*, float*) {
}

void CBoPhysicsManager::ApplyShuntReaction(CBoDrivableVehiclePhysics*, CBoDrivableVehiclePhysics*, CGtV3d, CGtV3d, float, ESlamShuntComboState) {
}

void CBoPhysicsManager::ApplySlamReaction(CBoDrivableVehiclePhysics*, CBoDrivableVehiclePhysics*, CGtV3d, CGtV3d, float, ESlamShuntComboState) {
}

void CBoPhysicsManager::BodyBodyResponse(CBoCollidingPair*, bool) {
}

void CBoPhysicsManager::BodyBodyResponse_ApplyImpulse(CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*, CGtV3d, CGtV3d, CGtV3d, EPhysicsInteractionType, EPhysicsInteractionType) {
}

void CBoPhysicsManager::BodyBodyResponse_CalculateImpulse(CGtV3d*, CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*) {
}

bool CBoPhysicsManager::BodyBodyResponse_CanCollide(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB) {
    return !((lpBodyA->meType == eABT_CrashingTraffic && lpBodyB->meType == eABT_CrashingTraffic) && 
        (*(int*)((int)lpBodyA->mpBodyData + 0x3704) == (int)lpBodyB->mpBodyData));
}

void CBoPhysicsManager::BodyBodyResponse_CheckForDynamicPropCrash(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB) {

}

void CBoPhysicsManager::BodyBodyResponse_CheckForPropHitEvent(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB, CBoCollidingBody*, CBoCollidingBody*) {
}

void CBoPhysicsManager::BodyBodyResponse_CheckForUnpausing(CBoActiveBody* lpBodyA, CBoActiveBody*) {
}

bool CBoPhysicsManager::BodyBodyResponse_Collision(CBoCollidingPair*, CBoHullCollideParams*) {
    return false;
}

void CBoPhysicsManager::BodyBodyResponse_CrashRaceCar(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB, CGtV3d*, bool) {
}

void CBoPhysicsManager::BodyBodyResponse_DeformTwoVehicles(CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CGtV3d*) {
}

RwReal CBoPhysicsManager::BodyBodyResponse_DeformVehicle(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB, CGtV3d, CGtV3d, float, float, float*) {
    return RwReal();
}

bool CBoPhysicsManager::BodyBodyResponse_ModifyInteraction(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB, EPhysicsInteractionType*, EPhysicsInteractionType*) {
    return false;
}

bool CBoPhysicsManager::BodyBodyResponse_RaceCarShouldCrash(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB, CBoCollidingBody*, CBoCollidingBody*, float, CGtV3d, bool) {
    return false;
}

void CBoPhysicsManager::BodyBodyResponse_Translation(CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*, EPhysicsInteractionType, EPhysicsInteractionType) {
}

void CBoPhysicsManager::BodyCameraResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::BodyPropResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::BodyTrafficResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::CalculateAndApplyCheckingImpulse(CBoVehiclePhysics*, CBoVehiclePhysics*, CBoCollidingPair*, CBoHullCollideParams*, bool) {
}

bool CBoPhysicsManager::CalculateAndApplyImpulse(CBoCollidingPair*, CBoHullCollideParams*, float*, float*) {
    return false;
}

EShuntSlamType CBoPhysicsManager::CalculateShuntOrSlam(CBoCollidingPair*, float, float, float, float&, bool&, bool&) {
    return EShuntSlamType();
}

bool CBoPhysicsManager::CanCheckCheckedTraffic(CBoRaceCarPhysics*, CBoCheckedTrafficPhysics*) {
    return false;
}

bool CBoPhysicsManager::CanCheckTraffic(CBoCollidingPair*, CBoRaceCarPhysics*, CBoTrafficVehicle*) {
    return false;
}

bool CBoPhysicsManager::CanCrashTrafficBody() {
    return false;
}

void CBoPhysicsManager::CheckedTrafficWithCheckedTrafficResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::CheckedTrafficWithCrashingTrafficResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::CheckedTrafficWithTrafficResponse(CBoCollidingPair*, CBoHullCollideParams*) {
}

CBoCheckedTrafficPhysics* CBoPhysicsManager::CheckTrafficBody(CBoActiveBody* lpBodyA, ERaceCarIndex, CGtV3d, bool) {
    return nullptr;
}

bool CBoPhysicsManager::ClearSpaceForCheckedTraffic(const CGtMatrix3x4*, const CGtMatrix3x4*) {
    return false;
}

void CBoPhysicsManager::CollideAndRespondPair(CBoCollidingPair*) {
}

void CBoPhysicsManager::Construct() {
}

bool CBoPhysicsManager::CrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char) {
    return false;
}

bool CBoPhysicsManager::CrashFurthestAwayCheckedTraffic(const CGtMatrix3x4*, const CGtMatrix3x4*) {
    return false;
}

bool CBoPhysicsManager::CrashTrafficBody(CBoActiveBody* lpBodyA, ERaceCarIndex, unsigned char, bool, bool, bool) {
    return false;
}

void CBoPhysicsManager::Destruct() {
}

bool CBoPhysicsManager::DetectAerialTakeDown(CBoRaceCarPhysics*, CBoRaceCarPhysics*, CGtV3d) {
    return false;
}

bool CBoPhysicsManager::DetectTBoneTakeDown(CBoRaceCarPhysics*, CBoRaceCarPhysics*, float, float) {
    return false;
}

void CBoPhysicsManager::DoCrashBreaker(CBoVehiclePhysics*, float, bool, bool) {
}

void CBoPhysicsManager::DoTrafficHomingBehaviour(CBoVehiclePhysics*, bool, bool) {
}

RwInt32 CBoPhysicsManager::FindFreeTrafficBody() {
    return RwInt32();
}

CBoActiveBody* CBoPhysicsManager::GetActiveBody(int) {
    return nullptr;
}

void CBoPhysicsManager::GetBodyProjectionsOfCollisionPoint(CBoCollidingPair*, float*, float*) {
}

CBoCheckedTrafficPhysics* CBoPhysicsManager::GetCheckedTrafficPhysics(int) {
    return nullptr;
}

const CBoInterval CBoPhysicsManager::GetDynamicIntervalRange(float, float, int*) {
    return CBoInterval();
}

const RwInt32 CBoPhysicsManager::GetMaxNumBodies() {
    return RwInt32();
}

CBoRaceCarPhysics* CBoPhysicsManager::GetRaceCarPhysics(ERaceCarIndex) {
    return nullptr;
}

CBoInterval* CBoPhysicsManager::GetStaticIntervalRange(float, float, int*) {
    return nullptr;
}

const void CBoPhysicsManager::HandleTrafficBodyImpact(CBoTrafficPhysics*, CBoVehicleParams*, CBoRaceCarPhysics*, bool) {
    return void();
}

CBoTrafficPhysics* CBoPhysicsManager::InduceTrafficVehicleCrash(CBoTrafficVehicle*, CBoVehiclePhysics*, bool) {
    return nullptr;
}

void CBoPhysicsManager::InheritBodyParts(CBoVehiclePhysics*, CBoVehiclePhysics*) {
}

bool CBoPhysicsManager::IsBodyPartCollidingWithOwnerVehicle(CBoActiveBody* lpBodyA, CBoActiveBody*) {
    return false;
}

bool CBoPhysicsManager::IsInCollidingPairs(CBoActiveBody*) {
    return false;
}

bool CBoPhysicsManager::MakePropDynamic(CBoActiveBody* lpBodyA, ERaceCarIndex) {
    return false;
}

void CBoPhysicsManager::MakePropStatic(CBoPropPhysics*) {
}

bool CBoPhysicsManager::NetworkCrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char) {
    return false;
}

void CBoPhysicsManager::PostEffectsUpdate() {
}

bool CBoPhysicsManager::Prepare() {
    return false;
}

void CBoPhysicsManager::RaceCarRaceCarResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::RaceCarWithCheckableTraffic(CBoCollidingPair*, CBoHullCollideParams*) {
}

void CBoPhysicsManager::RaceCarWithCheckedTrafficResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::Release() {
}

bool CBoPhysicsManager::Remove(CBoActiveBody* lpBodyA, bool) {
    return false;
}

void CBoPhysicsManager::RemoveCamera(CBoCameraPhysics*) {
}

void CBoPhysicsManager::RemoveFromCheckedTrafficArray(CBoCheckedTrafficPhysics*) {
}

void CBoPhysicsManager::RemoveOrphanBodyParts() {
}
#undef RemoveProp
bool CBoPhysicsManager::RemoveProp(CBoPropInstance*) {
    return false;
}
#define RemoveProp
void CBoPhysicsManager::RemoveTrafficVehicle(CBoTrafficVehicle*) {
}

void CBoPhysicsManager::RemoveVehiclesDetachedBodyParts(CBoVehiclePhysics*) {
}

void CBoPhysicsManager::ResetCollisionBools() {
}

bool CBoPhysicsManager::ResolvePenetration(CBoCollidingPair*, CBoHullCollideParams*, float*, float*) {
    return false;
}

void CBoPhysicsManager::StopRaceCarBodyPartsCrashing(ERaceCarIndex) {
}

void CBoPhysicsManager::TranslatePhysicsObjects() {
}

void CBoPhysicsManager::Update(float) {
}

void CBoPhysicsManager::UpdateNearMissArray() {
}

void CBoPhysicsManager::UpdatePhysicsObjects(float) {
}

void CBoPhysicsManager::UpdateSphereTree() {
}

void CBoPhysicsManager::VehicleTrafficResponse(CBoCollidingPair*) {
}

void CBoPhysicsManager::VehicleTrafficResponseWithoutChecking(CBoCollidingPair*, CBoHullCollideParams*) {
}

void CBoPhysicsManager::WorldSafeBodyTranslations(CBoCollidingPair*, CGtV3d*, CGtV3d*) {
}
