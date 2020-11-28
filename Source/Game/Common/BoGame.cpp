#include "BoGame.h"
#include "BoTimer.h"
#include "../../Camera/BoPlayerCameraManager.h"
#include "../../Camera/Behaviours/BoBehaviourAttachCam.h"
#include "../../Camera/Behaviours/BoBehaviourShot.h"
#include "../../Camera/Behaviours/BoBehaviourCluster.h"
#include "../../Camera/Crash/Camera Directors/BoCrashModeCrashCameraDirector.h"
#include "../../../../Shared/Numeric/GtRandom.h"
#include "../../../../Shared/System/Common/Unicode/GtUnicode.h"
#include "../../../../Shared/Numeric/Math/PS2/GtMathPS2.h"

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

CBoGame::CBoGame() {

}

void CBoGame::Construct() {

}

void CBoGame::SetDemoPath(char * lpacPath) {

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

void CBoGame::RequestNewGameMode(CBoGameMode * lpNewGameMode) {

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

void CBoGame::RequestPause(int param) {
	 
}	 
	 
void CBoGame::RequestResume(int param) {
	 
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
	 
void CBoGame::RequestWorldPrepare(bool param) {
	 
}	 
	 
void CBoGame::ClearFrameBufferDuringWorldPrepare(GtMathPS2::CGtV4d param) {
	 
}	 
	 
bool CBoGame::IsWorldPrepared() {
	return false;
}	 
	 
void CBoGame::RequestHalfFramerate(bool param) {
	 
}	 
	 
bool CBoGame::GetHalfFramerate() {
	return false;
}	 
	 
void CBoGame::RequestFramerateType(EGtFramerateType param) {

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

void CBoGame::RequestGameUpdateState(EGameUpdateState param) {

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

void CBoGame::SetIsCrashMode(bool param) {
 
}

void CBoGame::SetIsLapEliminatorMode(bool param) {

}

bool CBoGame::IsTrafficAttackMode() {
	return false;
}

void CBoGame::SetIsTrafficAttackMode(bool param) {

}

bool CBoGame::IsRoadRageMode() {
	return false;
}

void CBoGame::SetIsRoadRageMode(bool param) {

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

void CBoGame::AttemptToInsertExtraSimulationUpdates(int param) {
	 
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
unsigned short * CGtUnicode::PrintStringN(RwInt32 lnBufferLength, GtUTF16 * lpTargetString, const GtUTF16 * lpFormatString, const int& lV1) {
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

void CGtRandom::SetSeed(RwUInt32 luSeed) {

}

void CBoTimer::SetAllowSlowMo(bool lbAllowSlowmo) {

}