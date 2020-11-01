#include "BoGame.h"
#include "../Game/BoTimer.h"
#include "../Camera/BoPlayerCameraManager.h"
#include "../Camera/Behaviours/BoBehaviourAttachCam.h"
#include "../Camera/Behaviours/BoBehaviourShot.h"
#include "../Camera/Behaviours/BoBehaviourCluster.h"
#include "../Camera/Crash/Camera Directors/BoCrashModeCrashCameraDirector.h"
#include "../../../../GameShared/Common/Numeric/GtRandom.h"
#include "../../../../GameShared/Common/System/GtUnicode.h"
#include "../../../../GameShared/PC/Numeric/GtMathPC.h"

CBoGame gGame;

RwReal lrTotalSleepTimeMs        = 0.6;
RwReal lrTotalSleepTimeMsLoading = 2.5;
RwReal lrTotalSleepTimeMsMenus   = 1.8;

char * kpacStringFilenameEnglish   = "Data/GlobalEn.bin";
char * kpacStringFilenameDutch     = "Data/GlobalDu.bin";
char * kpacStringFilenameSpanish   = "Data/GlobalSp.bin";
char * kpacStringFilenameSwedish   = "Data/GlobalSw.bin";
char * kpacStringFilenameUSEnglish = "Data/GlobalUs.bin";
char * kpacStringFilenameJapanese  = "Data/GlobalJa.bin";
char * kpacStringFilenameFrench    = "Data/GlobalFr.bin";
char * kpacStringFilenameGerman    = "Data/GlobalGe.bin";
char * kpacStringFilenameItalian   = "Data/GlobalIt.bin";

char * kpacHeadingStringFilenameEnglish   = "Data/HeadEn.bin";
char * kpacHeadingStringFilenameDutch     = "Data/HeadDu.bin";
char * kpacHeadingStringFilenameSpanish   = "Data/HeadSp.bin";
char * kpacHeadingStringFilenameSwedish   = "Data/HeadSw.bin";
char * kpacHeadingStringFilenameUSEnglish = "Data/HeadUs.bin";
char * kpacHeadingStringFilenameJapanese  = "Data/HeadJa.bin";
char * kpacHeadingStringFilenameFrench    = "Data/HeadFr.bin";
char * kpacHeadingStringFilenameGerman    = "Data/HeadGe.bin";
char * kpacHeadingStringFilenameItalian   = "Data/HeadIt.bin";

CBoGame::CBoGame(void) {

}

void CBoGame::Construct() {

}

void CBoGame::SetDemoPath(char *) {

}

bool CBoGame::Prepare() {
	return false;
}

void CBoGame::Update() {

}

bool CBoGame::IsSimulationPaused() {
	return false;
}

bool CBoGame::RestartGameModeUpdateCode() {
	return false;
}

bool CBoGame::PrepareWorld() {
	return false;
}

void CBoGame::SleepToAllowWorkerThreadsToRun() {

}

void CBoGame::UpdatePreSimulation() {

}

void CBoGame::UpdateSimulation() {

}

void CBoGame::UpdatePostSimulation() {

}

RwInt32 CBoGame::GetNumSimulationUpdatesRequired() {
	return 0;
}

void CBoGame::Render() {

}

void CBoGame::DisplayInsertControllerMessage() {

}

void CBoGame::Release() {

}

void CBoGame::Destruct() {

}

bool CBoGame::ResetGameMode() {
	return false;
}

void CBoGame::RequestNewGameMode(CBoGameMode *) {

}

bool CBoGame::IsTurnBasedCrash() {
	return false;
}

bool CBoGame::Is2PlayerSplitScreen() {
	return false;
}

bool CBoGame::IsMultiplayerMode() {
	return false;
}

void CBoGame::CalculateSendRecvFigures() {

}

void CBoGame::DrawQuickLoadScreen() {

}

RwChar * CBoGame::GetDemoPath() {
	return "";
}

CBoGameMode * CBoGame::GetCurrentGameMode() {
	return nullptr;
}

CBoStageLogic * CBoGame::GetCurrentStageLogic() {
	return nullptr;
}

CBoGameMode * CBoGame::GetRequestedGameMode() {
	return nullptr;
}

void CBoGame::RequestPause(int) {
	 
}	 
	 
void CBoGame::RequestResume(int) {
	 
}	 
	 
bool CBoGame::IsPaused() {
	return false;
}	 
	 
bool CBoGame::IsPauseRequested() {
	return false;
}	 
	 
bool CBoGame::IsResumeRequested() {
	return false;
}

RwInt32 CBoGame::GetPausePlayerIndex() {
	return 0;
}
	 
void CBoGame::RequestWorldPrepare(bool) {
	 
}	 
	 
void CBoGame::ClearFrameBufferDuringWorldPrepare(GtMathPC::CGtV4d) {
	 
}	 
	 
bool CBoGame::IsWorldPrepared() {
	return false;
}	 
	 
void CBoGame::RequestHalfFramerate(bool) {
	 
}	 
	 
bool CBoGame::GetHalfFramerate() {
	return false;
}	 
	 
void CBoGame::RequestFramerateType(EGtFramerateType) {

}

EGtFramerateType CBoGame::GetFramerateType() {
	return EGtFramerateType::eGtFramerateConstant;
}	   
	   
bool CBoGame::OnlineUpdate() {
	return false;
}	   
	   
bool CBoGame::OfflineUpdate() {
	return false;
}	   
	   
RwReal CBoGame::GetNumSimulationUpdatesThisRenderFrame() {
	return 0;
}

void CBoGame::RequestGameUpdateState(EGameUpdateState) {

}

EGameUpdateState CBoGame::GetRequestedGameUpdateState() {
	return EGameUpdateState::eGameUpdateStateConstructed;
}

EGameUpdateState CBoGame::GetCurrentGameUpdateState() {
	return EGameUpdateState::eGameUpdateStateConstructed;
}

bool CBoGame::IsNewRequestedGameUpdateState() {
	return false;
}

bool CBoGame::IsCrashMode() {
	return false;
}

void CBoGame::SetIsCrashMode(bool) {
 
}

void CBoGame::SetIsLapEliminatorMode(bool) {

}

bool CBoGame::IsTrafficAttackMode() {
	return false;
}

void CBoGame::SetIsTrafficAttackMode(bool) {

}

bool CBoGame::IsRoadRageMode() {
	return false;
}

void CBoGame::SetIsRoadRageMode(bool) {

}

bool CBoGame::IsLapEliminatorMode() {
	return false;
}

bool CBoGame::IsInChampionship() {
	return false;
}

RwReal CBoGame::GetCameraTimeStep() const {
	return 0;
}	    
	    
RwReal CBoGame::GetCameraTimeStepNoSlowMo() const {
	return 0;
}	    
	    
RwInt32 CBoGame::GetSimulationUpdateCount() const {
	return 0;
}

void CBoGame::AttemptToInsertExtraSimulationUpdates(int) {
	 
}	 
	 
void CBoGame::RequestSimulationPause() {
	 
}	 
	 
void CBoGame::RequestSimulationUnpause() {
	 
}
	 
void CBoGame::GetSendRecvFigures(
	RwInt32 * lpnBytesSentToWireLastSecond, 
	RwInt32 * lpnBytesRecvdFromWireLastSecond, 
	RwInt32 * lpnBytesSubmittedForSendLastSecond, 
	RwInt32 * lpnBytesPassedToAppByRecvLastSecond, 
	RwInt32 ** lppanAvgBytesSubmittedForSendMsgTypeThisSecond, 
	RwInt32 ** lppanAvgBytesPassedToAppByRecvMsgTypeThisSecond
) {

}	 
	 
void CBoGame::UpdateVideoCapture() {

}

template <>
unsigned short * CGtUnicode::PrintStringN(RwInt32, GtUTF16 *, const GtUTF16 *, const int& lV1) {
	return nullptr;
}

CBoCrashModeCrashCameraDirector::CBoCrashModeCrashCameraDirector() {

}

CBoBehaviourAttachCam::CBoBehaviourAttachCam() {

}

CBoBehaviourShot::CBoBehaviourShot() {

}

CBoBehaviourCluster::CBoBehaviourCluster() {

}

CBoPlayerCameraManager::CBoPlayerCameraManager() {

}

void CGtRandom::SetSeed(unsigned int) {

}

void CBoTimer::SetAllowSlowMo(bool) {

}