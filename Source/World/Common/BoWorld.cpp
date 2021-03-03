#include "BoPlayerCar.h"
#include "BoRaceCar.h"
#include "BoWorld.h"

CBoWorld gWorld;

char kacAIDriverOneString[] = "DRIVER1";
char kacAIDriverTwoString[] = "DRIVER2";
char kacAIDriverThreeString[] = "DRIVER3";
char kacAIDriverFourString[] = "DRIVER4";
char kacAIDriverFiveString[] = "DRIVER5";

char* kacpAIDriverString[5] = {
	kacAIDriverOneString,
	kacAIDriverTwoString,
	kacAIDriverThreeString,
	kacAIDriverFourString,
	kacAIDriverFiveString
};

CBoWorld::CBoWorld() {}

void CBoWorld::Construct() {}

void CBoWorld::DecrementLeadingAdjustedAICar() {}

void CBoWorld::DecrementNumActiveRaceCars() {}

void CBoWorld::DecrementNumAdjustedAICars() {}

void CBoWorld::Destruct() {}

CBoAICar* CBoWorld::GetAICar(EAICarIndex) {
    return nullptr;
}

RwInt32 CBoWorld::GetInitialWorldFrame() {
    return RwInt32();
}

RwInt32 CBoWorld::GetLeadingAdjustedAICar() {
    return RwInt32();
}

RwInt32 CBoWorld::GetMaxRaceCarStreams() const {
    return RwInt32();
}

CBoNetworkCar* CBoWorld::GetNetworkCar(ENetworkCarIndex) {
    return nullptr;
}

RwInt32 CBoWorld::GetNumActiveRaceCars() {
    return RwInt32();
}

RwInt32 CBoWorld::GetNumAdjustedAICars() {
    return RwInt32();
}

EPlayerCarIndex CBoWorld::GetNumAICars() {
    return EPlayerCarIndex();
}

EPlayerCarIndex CBoWorld::GetNumNetworkCars() {
    return EPlayerCarIndex();
}

EPlayerCarIndex CBoWorld::GetNumPlayerCars() {
    return EPlayerCarIndex();
}

ERaceCarIndex CBoWorld::GetNumRaceCars() {
    return ERaceCarIndex();
}

CBoPlayerCar* CBoWorld::GetPlayerCar(EPlayerCarIndex) {
    return nullptr;
}

CBoVehiclePhysics CBoWorld::GetRaceCar(ERaceCarIndex) {
    return CBoVehiclePhysics();
}

CBoVehicleData CBoWorld::GetRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {
    return CBoVehicleData();
}

bool CBoWorld::GetReplayRequestStatus() {
    return false;
}

RwReal CBoWorld::GetTimeBeforeAutomaticTimeout() {
    return RwReal();
}

CGtV3d CBoWorld::GetTrackCentre() {
    return CGtV3d();
}

void CBoWorld::GetTrackExtents(CGtV3d*, CGtV3d*) {}

GtID CBoWorld::GetTrackID() {
    return GtID();
}

void CBoWorld::IncrementLeadingAdjustedAICar() {}

bool CBoWorld::IsCrashAftermath() const {
    return false;
}

bool CBoWorld::IsCrashIntro() const {
    return false;
}

bool CBoWorld::IsMarathon() {
    return false;
}

bool CBoWorld::IsMultiPlayer() {
    return false;
}

bool CBoWorld::IsPointToPoint() {
    return false;
}

bool CBoWorld::IsReplaying() {
    return false;
}

bool CBoWorld::IsRightHandDrive() {
    return false;
}

bool CBoWorld::IsSinglePlayer() {
    return false;
}

bool CBoWorld::LoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {
    return false;
}

void CBoWorld::NetworkCatchupUpdate() {}

void CBoWorld::PauseForNetworkSync(bool) {}

void CBoWorld::PauseForStreamSync(bool) {}

bool CBoWorld::Prepare(bool lbQuickPrepare) {
    return false;
}

void CBoWorld::Release() {}

void CBoWorld::Render(EPlayerCarIndex) {}

void CBoWorld::RenderCarUnlockEffects() {}

void CBoWorld::RenderFrontEnd(ERaceCarIndex) {}

void CBoWorld::RenderFullScreenPoly(EPlayerCarIndex) {}

void CBoWorld::RenderOnePlayer() {}

void CBoWorld::RenderRaceCars(EPlayerCarIndex, EPlayerCarIndex) {}

void CBoWorld::RenderTwoPlayer() {}

void CBoWorld::SetCarNumbers(RwInt32 lnNumPlayerCars, RwInt32 lnNumAICars, RwInt32 lnNumNetworkCars, RwInt32 lnNumAdjustedAICars) {}

void CBoWorld::SetCrashAftermath(bool) {}

void CBoWorld::SetCrashIntro(bool) {}

void CBoWorld::SetNumActiveRaceCars(int) {}

void CBoWorld::SetNumLeadingCars(int) {}

void CBoWorld::SetReplayRequestStatus(bool) {}

void CBoWorld::SetTrackID(GtID lnID) {}

void CBoWorld::SetUpTrackExtents() {}

void CBoWorld::UnLoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex) {}

void CBoWorld::Update() {}

void CBoWorld::UpdateSound() {}

void CBoWorld::UpdateTrack() {}

bool CBoWorld::WeArePausedForNetworkOrStreamSync() {
    return false;
}
