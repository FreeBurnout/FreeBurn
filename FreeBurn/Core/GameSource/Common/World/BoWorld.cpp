#include "BoPlayerCar.h"
#include "BoRaceCar.h"
#include "BoWorld.h"
#include "../../Common/World/BoWrongWayWall.h"
#include "../../Common/World/BoPropManager.h"
#include "../../Common/World/AI/BoAIArbitrator.h"
#include "../../Common/World/AI/BoAITarget.h"
#include "../../Common/World/Traffic/BoTrafficSystem.h"
#include "../../Common/Physics/BoCheckedTrafficPhysics.h"
#include "../../Common/Physics/BoCollidingBody.h"
#include "../../Common/Physics/BoPhysicsManager.h"
#include "../../Common/Physics/BoVehicleParams.h"

void CBoWorld::Construct() {

}

bool CBoWorld::Prepare(bool lbQuickPrepare) {
	return false;
}

bool CBoWorld::LoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {
	return false;
}

CBoVehicleData CBoWorld::GetRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {
	return CBoVehicleData();
}

CBoVehiclePhysics CBoWorld::GetRaceCar(ERaceCarIndex) {
	return CBoVehiclePhysics();
}

void CBoWorld::SetUpTrackExtents() {

}

void CBoWorld::Update() {

}

void CBoWorld::UpdateTrack() {

}

void CBoWorld::Release() {

}

void CBoWorld::SetTrackID(GtID lnID) {

}

void CBoWorld::UnLoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {

}

void CBoWorld::Destruct() {

}

void CBoWorld::SetCarNumbers(RwInt32 lnNumPlayerCars, RwInt32 lnNumAICars, RwInt32 lnNumNetworkCars, RwInt32 lnNumAdjustedAICars) {

}

void CBoWorld::UpdateSound() {

}

RwInt32 _VehicleDistanceQSortCallback(const void * lpData1, const void * lpData2) {
	return 0;
}

void CBoWorld::RenderRaceCars(EPlayerCarIndex, EPlayerCarIndex) {
	
}

void CBoWorld::RenderFullScreenPoly(EPlayerCarIndex) {

}

void BoWorldResetPlayerDetourInfo() {

}

void CBoWorld::RenderCarUnlockEffects() {

}

CBoVehicleParams::CBoVehicleParams() {

}

CBoTrafficSystem::CBoTrafficSystem() {

}

CBoCollidingBody::CBoCollidingBody() {

}

CBoVehiclePhysics::CBoVehiclePhysics() {

}

CBoWrongWayWall::CBoWrongWayWall() {

}

CBoCheckedTrafficPhysics::CBoCheckedTrafficPhysics() {

}

CBoPhysicsManager::CBoPhysicsManager() {

}

CBoPropManager::CBoPropManager() {

}

CBoRaceCar::CBoRaceCar() {

}

CBoAITargetSpline::CBoAITargetSpline() {

}

CBoAIArbitrator::CBoAIArbitrator() {

}

CBoWorld::CBoWorld() {

}

GtID CBoWorld::GetTrackID() {
	return GtID();
}

ERaceCarIndex CBoWorld::GetNumRaceCars() {
	return ERaceCarIndex();
}

RwInt32 CBoWorld::GetNumActiveRaceCars() {
	return RwInt32();
}

EPlayerCarIndex CBoWorld::GetNumPlayerCars() {
	return EPlayerCarIndex();
}

EPlayerCarIndex CBoWorld::GetNumAICars() {
	return EPlayerCarIndex();
}

EPlayerCarIndex CBoWorld::GetNumNetworkCars() {
	return EPlayerCarIndex();
}

RwInt32 CBoWorld::GetNumAdjustedAICars() {
	return RwInt32();
}

void CBoWorld::DecrementNumAdjustedAICars() {

}

RwInt32 CBoWorld::GetLeadingAdjustedAICar() {
	return RwInt32();
}

void CBoWorld::IncrementLeadingAdjustedAICar() {

}

void CBoWorld::DecrementLeadingAdjustedAICar() {

}

void CBoWorld::SetNumLeadingCars(int) {

}

CBoPlayerCar * CBoWorld::GetPlayerCar(EPlayerCarIndex) {
	return nullptr;
}

CBoAICar * CBoWorld::GetAICar(EAICarIndex) {
	return nullptr;
}

CBoNetworkCar * CBoWorld::GetNetworkCar(ENetworkCarIndex) {
	return nullptr;
}

bool CBoWorld::IsPointToPoint() {
	return false;
}

bool CBoWorld::IsMarathon() {
	return false;
}

bool CBoWorld::IsRightHandDrive() {
	return false;
}

GtMathPC::CGtV3d CBoWorld::GetTrackCentre() {
	return GtMathPC::CGtV3d();
}

void CBoWorld::GetTrackExtents(GtMathPC::CGtV3d *, GtMathPC::CGtV3d *) {

}

void CBoWorld::SetNumActiveRaceCars(int) {

}

void CBoWorld::DecrementNumActiveRaceCars() {

}

bool CBoWorld::IsCrashIntro() const {
	return false;
}

void CBoWorld::SetCrashIntro(bool) {

}

bool CBoWorld::IsCrashAftermath() const {
	return false;
}

void CBoWorld::SetCrashAftermath(bool) {

}

RwReal CBoWorld::GetTimeBeforeAutomaticTimeout() {
	return RwReal();
}

RwInt32 CBoWorld::GetInitialWorldFrame() {
	return RwInt32();
}

RwInt32 CBoWorld::GetMaxRaceCarStreams() const {
	return RwInt32();
}

bool CBoWorld::IsMultiPlayer() {
	return false;
}

bool CBoWorld::IsSinglePlayer() {
	return false;
}
