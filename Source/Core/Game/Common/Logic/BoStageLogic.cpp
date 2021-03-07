#include "BoStageLogic.h"

char * kapcVehicleClassNames[12] = {
	"Null",
	nullptr,
	nullptr,
	"Lorry",
	"ArticulatedCab",
	nullptr,
	"SpecialHelicopter",
	"SpecialLTrain",
	"MonoRail",
	"SpecialPlane",
	"ArticulatedTrailer"
};

void CBoStageLogic::OnAir(CBoScoreCategory*, EPlayerCarIndex) {
}

void CBoStageLogic::OnBoostStart(EPlayerCarIndex) {
}

void CBoStageLogic::OnBurnoutLap(EPlayerCarIndex) {
}

void CBoStageLogic::OnChallengeInfoFinish() {
}

void CBoStageLogic::OnCheckedTraffic(CBoCheckedTrafficPhysics*, CBoTrafficVehicle*, ERaceCarIndex) {
}

void CBoStageLogic::OnCheckedTrafficBonus(EPlayerCarIndex, CBoScoreCategory*) {
}

void CBoStageLogic::OnCheckedTrafficSwerve(CBoCheckedTrafficPhysics*, float) {
}

void CBoStageLogic::OnCheckpoint(CBoRaceCar*) {
}

void CBoStageLogic::OnComeIntoRangeOfCrashbreaker(EPlayerCarIndex, CGtV3d) {
}

void CBoStageLogic::OnCrashbreaker(EPlayerCarIndex, ECrashbreakerPower) {
}

void CBoStageLogic::OnCrashComboItem(EComboEntryType) {
}

void CBoStageLogic::OnCrashEscape(EPlayerCarIndex, char) {
}

void CBoStageLogic::OnCrashingVehicleExploded(CBoVehiclePhysics*) {
}

void CBoStageLogic::OnCrashStart(CBoVehiclePhysics*, CBoCrashStartInfo*) {
}

void CBoStageLogic::OnDetectedAerialTakeDown(CBoRaceCar*, CBoRaceCar*) {
}

void CBoStageLogic::OnDetectedTBoneTakeDown(CBoRaceCar*, CBoRaceCar*) {
}

void CBoStageLogic::OnDrift(CBoScoreCategory*, EPlayerCarIndex) {
}

void CBoStageLogic::OnGoneOutOfRangeOfCrashbreaker(EPlayerCarIndex) {
}

void CBoStageLogic::OnGrinding(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*) {
}

void CBoStageLogic::OnHostMigration(int, int) {
}

void CBoStageLogic::OnInitialVehicleImpact(CBoVehiclePhysics*, CBoRaceCarPhysics*) {
}

void CBoStageLogic::OnIntroCameraFinished() {
}

void CBoStageLogic::OnIntroFinish() {
}

void CBoStageLogic::OnLargeVehicleImpact(CBoVehiclePhysics*, bool) {
}

void CBoStageLogic::OnLastCutOfTakedownSequence() {
}

void CBoStageLogic::OnLeaveLobby() {
}

void CBoStageLogic::OnMedalAwarded(EBoScoreMedalType, EPlayerCarIndex) {
}

void CBoStageLogic::OnMovingAwayFromCrashbreaker(EPlayerCarIndex) {
}

void CBoStageLogic::OnNearMiss(CBoScoreCategory*, EPlayerCarIndex) {
}

void CBoStageLogic::OnNewBestRacePosition(EPlayerCarIndex, int) {
}

void CBoStageLogic::OnNonFatalTrafficCollision(CBoRaceCarPhysics*, CBoTrafficVehicle*) {
}

void CBoStageLogic::OnOncoming(CBoScoreCategory*, EPlayerCarIndex) {
}

void CBoStageLogic::OnPause() {
}

void CBoStageLogic::OnPayloadReleased(CBoVehiclePhysics*) {
}

void CBoStageLogic::OnPerfectLap(EPlayerCarIndex) {
}

void CBoStageLogic::OnPickupPickedUp(ECrashModePickupType, EPlayerCarIndex) {
}

void CBoStageLogic::OnPlayerResultsFailedToSend(int) {
}

void CBoStageLogic::OnPostCrashReset(CBoRaceCarPhysics*) {
}

void CBoStageLogic::OnPreCrashbreakerFinish(EPlayerCarIndex, ECrashbreakerPower) {
}

void CBoStageLogic::OnPreCrashbreakerStart(EPlayerCarIndex, ECrashbreakerPower) {
}

void CBoStageLogic::OnPreCrashReset(CBoRaceCarPhysics*) {
}

void CBoStageLogic::OnPropHit(EPlayerCarIndex, bool, const CBoPropType*, float, CGtV3d) {
}

void CBoStageLogic::OnRaceCarCrash(CBoRaceCarPhysics*, CBoCrashStartInfo*) {
}

void CBoStageLogic::OnRaceCarFinish(CBoRaceCar*, EBoScoreFinishState) {
}

void CBoStageLogic::OnRaceCarRaceCarCollision(CBoRaceCarPhysics*, CBoRaceCarPhysics*) {
}

void CBoStageLogic::OnRaceCarStartNewLap(CBoRaceCar*) {
}

void CBoStageLogic::OnResultArrived(CBoNetworkPlayer*) {
}

void CBoStageLogic::OnResume() {
}

void CBoStageLogic::OnRetry() {
}

void CBoStageLogic::OnRub(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*) {
}

void CBoStageLogic::OnSlam(CBoRaceCar*, CBoRaceCar*, EBoScoreSlamType, bool) {
}

void CBoStageLogic::OnSplashScreenFinished() {
}

void CBoStageLogic::OnStartBoosting() {
}

void CBoStageLogic::OnStopBoosting() {
}

void CBoStageLogic::OnTailgating(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*) {
}

void CBoStageLogic::OnTakedownDenied(EPlayerCarIndex) {
}

void CBoStageLogic::OnTakedownFinish(CBoRaceCar*, CBoRaceCar*) {
}

void CBoStageLogic::OnTakedownSequenceFinished() {
}

void CBoStageLogic::OnTakedownStart(CBoRaceCar*, CBoRaceCar*, CBoCrashStartInfo*, ETakedownType) {
}

void CBoStageLogic::OnTimeExtension(EPlayerCarIndex) {
}

void CBoStageLogic::OnTimeout() {
}

void CBoStageLogic::OnTradePaint(EPlayerCarIndex, CBoRaceCar*, bool) {
}

void CBoStageLogic::OnTrafficCarCrash(CBoTrafficPhysics*, CBoTrafficVehicle*, ERaceCarIndex, bool) {
}

void CBoStageLogic::OnWorldPrepared() {
}

void CBoStageLogic::OnYouWereLucky(EPlayerCarIndex, CBoRaceCar*) {
}

void CBoStageLogic::Render(EStageLogicRenderType) {
}
