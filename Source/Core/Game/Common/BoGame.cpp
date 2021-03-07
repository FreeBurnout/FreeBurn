#include "BoDebugManager.h"
#include "BoGame.h"
#include "BoLanguageManager.h"
#include "BoMemoryCardManager.h"
#include "BoNormalGameModes.h"
#include "BoProfileManager.h"
#include "BoTimer.h"
#include "../../Camera/Behaviours/BoBehaviourAttachCam.h"
#include "../../Camera/Behaviours/BoBehaviourCluster.h"
#include "../../Camera/Behaviours/BoBehaviourShot.h"
#include "../../Camera/BoPlayerCameraManager.h"
#include "../../Camera/Crash/Camera Directors/BoCrashModeCrashCameraDirector.h"
#include "../../Graphics/PC/BoGraphicsManagerPC.h"
#include "../../Menu/Apt/AptManager/BoAptManager.h"
#include "../../Menu/BoFlashEffectManager.h"
#include "../../Menu/BoFlashMovieManager.h"
#include "../../Menu/States/BoMenuFlowManager.h"
#include "../../Network/Common/BoNetworkManager.h"
#include "../../World/Common/BoWorld.h"
#include "../../../Shared/System/PC/GtThreadMgrPC.h"
#include "../../../Shared/System/PC/GtHiResSystemTimerPC.h"
#include "../../Sound/Common/BoSoundManager.h"
#include "BoSaveGameDataManager.h"

RwReal lrTotalSleepTimeMs = 0.6f;
RwReal lrTotalSleepTimeMsLoading = 2.5f;
RwReal lrTotalSleepTimeMsMenus = 1.8f;

char* kpacStringFilenameEnglish = "Data/GlobalEn.bin";
char* kpacStringFilenameDutch = "Data/GlobalDu.bin";
char* kpacStringFilenameSpanish = "Data/GlobalSp.bin";
char* kpacStringFilenameSwedish = "Data/GlobalSw.bin";
char* kpacStringFilenameUSEnglish = "Data/GlobalUs.bin";
char* kpacStringFilenameJapanese = "Data/GlobalJa.bin";
char* kpacStringFilenameFrench = "Data/GlobalFr.bin";
char* kpacStringFilenameGerman = "Data/GlobalGe.bin";
char* kpacStringFilenameItalian = "Data/GlobalIt.bin";

char* kpacHeadingStringFilenameEnglish = "Data/HeadEn.bin";
char* kpacHeadingStringFilenameDutch = "Data/HeadDu.bin";
char* kpacHeadingStringFilenameSpanish = "Data/HeadSp.bin";
char* kpacHeadingStringFilenameSwedish = "Data/HeadSw.bin";
char* kpacHeadingStringFilenameUSEnglish = "Data/HeadUs.bin";
char* kpacHeadingStringFilenameJapanese = "Data/HeadJa.bin";
char* kpacHeadingStringFilenameFrench = "Data/HeadFr.bin";
char* kpacHeadingStringFilenameGerman = "Data/HeadGe.bin";
char* kpacHeadingStringFilenameItalian = "Data/HeadIt.bin";

CBoMemoryManagerPC gMemoryManager;

CBoGame::CBoGame() {
	for (int i = 1; i > -1; i--) {
		maPlayerCamera[i].Construct();
	}
}

void CBoGame::Construct() {
	int iVar2;

	mbShutterClosed = true;
	mbProgressionPage = false;
	mbQuickWorldPrepare = false;
	mbClearFrameBufferDuringWorldPrepare = false;
	mbPowerOffTriggered = false;
	mbDev9Loaded = false;
	mbRequestRestartGameModeWithNewConfig = false;
	mbPlay = true;
	mbRequestSimulationPause = false;
	mbRequestSimulationUnpause = false;
	mpGlobalTextureDictionary = nullptr;
	mbGlobalTextureDictionaryLoaded = false;
	mVehicleList.mnVehicleCount = 0;
	mTrackList.mnTrackCount = 0;
	mbVehicleListLoaded = false;
	mbTrackListLoaded = false;
	mNonDeterministicRNG.SetSeed(0x2b9d6f8);
	ConstructHardware();
	PreparePowerOff();
	CheckPowerOff();
	CGtThreadMgr::Open();
	CGtThreadMgr::EnableVBlankWait();
	gMemoryManager.Construct();
	mSettings.Construct();
	CGtHiResSystemTimer::Construct();

	if (gGame.mSettings.mgb50Hz) {
		gFrameTime = 1/50.f;
	}

	CGtTimer::PrepareTimerServices(1/gFrameTime);
	mFramerateManager.Construct(gFrameTime * 1000, 0);

	mTimer.SetAllowSlowMo(false);
	mTimer.Construct();

	gCPUMonitors.Construct();
	gGPUMonitors.Construct();
	gCPUMonitors.mnFreeCPU = 0;
	gCPUMonitors.mnUpdateCost = 0;
	gCPUMonitors.mnCameraCost = 0;
	gCPUMonitors.mnAICost = 0;
	gCPUMonitors.mnGraphicsCost = 0;
	gCPUMonitors.mnNetworkCost = 0;
	gCPUMonitors.mnPhysicsCost = 0;
	gCPUMonitors.mnSoundCost = 0;
	gCPUMonitors.mnTrafficCost = 0;
	gCPUMonitors.mnDebugManagerCost = 0;
	gCPUMonitors.mnSleepCost = 0;
	gCPUMonitors.mnEffectsCost = 0;

	gGPUMonitors.mnSky = 0;
	gGPUMonitors.mnBackdrops = 0;
	gGPUMonitors.mnChevrons = 0;
	gGPUMonitors.mnTrack = 0;
	gGPUMonitors.mnInstances = 0;
	gGPUMonitors.mnProps = 0;
	gGPUMonitors.mnTraffic = 0;
	gGPUMonitors.mnRaceCars = 0;
	gGPUMonitors.mnEffects = 0;
	gGPUMonitors.mnFog = 0;
	gGPUMonitors.mnBloom = 0;
	gGPUMonitors.mnBlur = 0;

	gBoMemCardManager.Construct();
	gLanguageManager.Construct();
	mCommsManager.Construct(nullptr);
	mAsyncDataLoader.Construct();
	gGraphicsManager.Construct();
	gDebugManager.Construct();
	gNetworkManager.Construct();
	gWorld.Construct();
	gDebugMenuPageManager.Construct();
	gEATraxDisplay.Construct();
	CGtStateOffset offTab = *gMenuFlowManager.GetOffsetTable();
	gMenuFlowManager.Construct(this, &offTab, &mTimer);
	gFlashMovieManager.Construct();
	gAptManager.Construct();
	gFlashEffectManager.Construct();
	gProfileManager.Construct();
	mpCurrentGameMode = nullptr;
	mpRequestedGameMode = nullptr;
	mbQuitNow = false;
	mpGlobalTextureDictionary = nullptr;

	mGameModeFrontEnd.Construct();
	mGameModeOnePlayerRace.Construct();
	mGameModeTwoPlayerRace.Construct();
	mGameModeOnlineRace.Construct();
	mOfflineSingleRaceLogic.Construct();
	mOfflineCrashModeLogic.Construct();
	mOfflineSingleRevengeLogic.Construct();
	mOfflineSingleBurningLapLogic.Construct();
	mOfflineSingleRoadRageLogic.Construct();
	mOfflineMultiplayerRoadRageLogic.Construct();
	mOfflineSingleEliminatorLogic.Construct();
	mOnlineSingleRaceLogic.Construct();
	mOnlineGolfCrashModeLogic.Construct();
	mOnlineCompCrashModeLogic.Construct();
	mOnlinePartyCrashModeLogic.Construct();
	mOnlineRevengeLogic.Construct();
	mOnlineRoadRageModeLogic.Construct();
	mCarViewerLogic.Construct();
	mSingleChallenge.Construct();
	mChampionshipChallenge.Construct();
	mTurnBasedCrashPartyChallenge.Construct();
	mTurnBasedCrashTourChallenge.Construct();
	mSecondaryRewardsManager.Construct();

	maPlayers[0].Construct();
	maPlayers[1].Construct();

	maPlayerCamera[0].Construct();
	maPlayerCamera[1].Construct();

	mnGamePausedByPlayer = -1;
	mnRequestPause = -1;
	mnRequestResume = -1;
	mePrepareState = EGtPrepareState::eGtPSConstructed;
	mbWorldPrepared = false;
	mbInputManagerPrepared = false;
	mbIsRoadRageMode = false;
	meHardwarePrepareState = EGtPrepareState::eGtPSConstructed;
	mbIsTrafficAttackMode = false;
	meRequestedUpdateState = EGameUpdateState::eGameUpdateStateConstructed;
	meUpdateState = EGameUpdateState::eGameUpdateStateConstructed;
	SetDemoPath("");
}

void CBoGame::SetDemoPath(char* lpacPath) {

}

bool CBoGame::Prepare() {
	return true;
}

// Hell.
void CBoGame::Update() {
	char cVar1;
	int iVar2;

	mNonDeterministicRNG.mnHigh = (mNonDeterministicRNG.mnHigh << 0x10) + (mNonDeterministicRNG.mnHigh >> 0x10) + mNonDeterministicRNG.mnLow;
	mNonDeterministicRNG.mnLow += mNonDeterministicRNG.mnHigh;

	gDebugManager.UpdateStartOfFrame();

	if (mbRequestSimulationPause) {
		mbPlay = 0;
	} else if (mbRequestSimulationUnpause) {
		mbPlay = 1;
	}

	mbRequestSimulationPause = 0;
	mbRequestSimulationUnpause = 0;

	if (!IsSimulationPaused() && (meUpdateState != meRequestedUpdateState)) {
		meUpdateState = meRequestedUpdateState;
	}

	mAsyncDataLoader.Update();
	gMemoryManager.Update();
	RwUInt32 vbCount = gGraphicsManager.GetVBlankCount();
	CGtHiResSystemTimer::Update(vbCount);
	CheckPowerOff();
	gSaveGameDataManager.mrPlayingTimeSecsCounter += mTimer.mrTimeStep;

	switch (meUpdateState) {
	case eGameUpdateStatePrepared:
		mTimer.NextFrame();
		gNetworkManager.muFrameCount++;
		mTimer.Update();
		gWorld.mTimer.Update();
		mpCurrentGameMode = mpRequestedGameMode;
		mpRequestedGameMode = nullptr;
		gMenuFlowManager.Update();
		meRequestedUpdateState = eGameUpdateStateRestartGameMode;
		break;
	case 12:
		/* TODO
		iVar2 = *(int*)(*(int*)mpCurrentGameMode + 0xc);
		(**(code**)(iVar2 + 0x34))(*(int*)mpCurrentGameMode + (int)*(short*)(iVar2 + 0x30));
		*/
		meUpdateState = eGameUpdateStateSimulationPrepare;
		meRequestedUpdateState = eGameUpdateStateSimulationPrepare;
	case 4:
		mbWorldPrepared = PrepareWorld();
		if (!mbWorldPrepared) {
			mTimer.NextFrame();
			gNetworkManager.muFrameCount++;
			mTimer.Update();
			gWorld.mTimer.Update();
			gMenuFlowManager.Update();
			if (!gNetworkManager.mbUppingInterface) {
				mInputManager.ResetState();
				mInputManager.Update();
			}
			gSoundManager.Update();
			gNetworkManager.Update();
			gNetworkManager.PostUpdate();
			SleepToAllowWorkerThreadsToRun();
		}
		else {
			mbQuickWorldPrepare = false;
			mbClearFrameBufferDuringWorldPrepare = false;
			if ((mpCurrentGameMode != nullptr) && (iVar2 = (int)mpCurrentGameMode->mpStageLogic, iVar2 != 0)) {
				// (**(code**)(*(int*)(iVar2 + 0xd4) + 0x1dc)) (iVar2 + *(short*)(*(int*)(iVar2 + 0xd4) + 0x1d8)); // TODO
			}
			mFramerateManager.Prepare();
			meUpdateState = eGameUpdateStateSimulationUpdate;
			meRequestedUpdateState = eGameUpdateStateSimulationUpdate;
			if (!gWorld.mbIsReplaying && !gWorld.mbRequestReplay) {
				gMenuFlowManager.SetInitialMenuState();
			}
	case 5:
			UpdatePreSimulation();

			EGtFramerateType updateFpsType = meDebugFramerateType;
			if (meDebugFramerateType == eGtFramerateVariableMax) {
				updateFpsType = meFramerateType;
			}

			mFramerateManager.StartUpdateFrame(
				updateFpsType, (mnGamePausedByPlayer == -1) && !IsSimulationPaused()
			);

			int i = 0;
			if (mnSimulationUpdateCount > 0) {
				while (mnRequestPause == -1) {
					mTimer.NextFrame();
					gNetworkManager.muFrameCount++;
					mTimer.Update();
					gWorld.mTimer.Update();

					if (!gNetworkManager.mbUppingInterface) {
						mInputManager.Update();
						if (!mInputManager.AreLockedPlayersConnected() && gGame.mnGamePausedByPlayer == -1 && !gNetworkManager.mbIsOnline) {
							// lVar5 = 0x6d6123044330fccf; // FSM_NOSTATE_
							if (gMenuFlowManager.mpState != nullptr && gMenuFlowManager.mpState->mID == -0x6bb7c5da87bef9af) { // MF_GAMESTATE
								gGame.mnRequestPause = 0;
							}
						}
						if (!gAptManager.mbEnabled) {
							mInputManager.UpdateFE();
						}
					}

					maPlayers[0].Update();
					maPlayers[1].Update();
					gDebugManager.Update();

					if (gDebugManager.mbPlay) {
						if (mnGamePausedByPlayer == -1) {
							UpdateSimulation();
						}
						gMenuFlowManager.Update();
					}

					gDebugMenuPageManager.Update();
					if (
						(
							(meRequestedUpdateState != eGameUpdateStateSimulationUpdate) || (mbRequestSimulationPause)
							) || 
						(
							(i++, mbRequestSimulationUnpause || (mnSimulationUpdateCount <= i))
							)
						) {
						break;
					}
				};

				if (mnRequestPause != -1) {
					mFramerateManager.mnPrevNumSimulationStepsRequired = i;
				}
			}
			UpdatePostSimulation();
			// _rwDMAWaitQueue();
			mnSimulationUpdateCount = GetNumSimulationUpdatesRequired();
			Render();
		}
		break;
	case eGameUpdateStateChangeGameMode:
		mTimer.NextFrame(
			// (&switchD_00103ce0::switchdataD_00489da0)[meUpdateState - 1] // what the fuck?
		);
		gNetworkManager.muFrameCount++;
		mTimer.Update();
		gWorld.mTimer.Update();
		mnGamePausedByPlayer = -1;
		mnRequestPause = -1;
		mnRequestResume = -1;
		if (!gNetworkManager.mbUppingInterface) {
			mInputManager.ResetState();
			mInputManager.Update();
		}
		gWorld.Release();
		mbWorldPrepared = false;

		mpCurrentGameMode->Release();

		mbRequestForceHalfFramerate = false;
		mpCurrentGameMode = mpRequestedGameMode;
		mpRequestedGameMode = nullptr;
		gMenuFlowManager.Update();
		meRequestedUpdateState = eGameUpdateStateRestartGameMode;
		break;
	case 7:
	case 9:
	case 11:
		if (RestartGameModeUpdateCode()) {
			if (meUpdateState == eGameUpdateStateRestartGameModeWithNewConfigRestarting) {
				meUpdateState = eGameUpdateStateStartReplay;
			} else {
				meUpdateState = eGameUpdateStateSimulationPrepare;
			}
			meRequestedUpdateState = meUpdateState;
		}
		break;
	case 8:
		mTimer.NextFrame();
		gNetworkManager.muFrameCount++;
		mTimer.Update();
		gWorld.mTimer.Update();
	case 10:
		mnGamePausedByPlayer = -1;
		mnRequestPause = -1;
		mnRequestResume = -1;
		mInputManager.ResetState();
		gSoundManager.StopAll();
		gWorld.Release();
		mbWorldPrepared = false;
		mpCurrentGameMode->mbDoFullPrepare = true;
		meUpdateState = (EGameUpdateState)(meUpdateState + 1);
		meRequestedUpdateState = meUpdateState;
		break;
	}

	gGraphicsManager.OpenViewport(eBoViewportMain);
	if (!mbWorldPrepared && mbClearFrameBufferDuringWorldPrepare) {
		gGraphicsManager.RenderFullScreenPass(mClearFrameBufferColour, eBoFSPBM_Additive);
	} else {
		gDebugMenuPageManager.Render();
		gAptManager.Render(gGame.mTimer.mrTimeStep * (float)gGame.mnSimulationUpdateCount);
		gEATraxDisplay.Render();
	}
	if (!mInputManager.AreLockedPlayersConnected() && mbWorldPrepared) {
		DisplayInsertControllerMessage();
	}
	gDebugManager.RenderOverlays();
	gGraphicsManager.CloseViewport();
	gGraphicsManager.PresentDrawBuffer();
	maPlayerCamera[0].SetCutThisFrame(false);
	maPlayerCamera[1].SetCutThisFrame(false);
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

void CBoGame::RequestNewGameMode(CBoGameMode* lpNewGameMode) {

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

RwChar* CBoGame::GetDemoPath() {
	return "";
}

CBoGameMode* CBoGame::GetCurrentGameMode() {
	return nullptr;
}

CBoStageLogic* CBoGame::GetCurrentStageLogic() {
	return nullptr;
}

CBoGameMode* CBoGame::GetRequestedGameMode() {
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

void CBoGame::ClearFrameBufferDuringWorldPrepare(GtMathPC::CGtV4d param) {

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
	RwInt32* lpnBytesSentToWireLastSecond,
	RwInt32* lpnBytesRecvdFromWireLastSecond,
	RwInt32* lpnBytesSubmittedForSendLastSecond,
	RwInt32* lpnBytesPassedToAppByRecvLastSecond,
	RwInt32** lppanAvgBytesSubmittedForSendMsgTypeThisSecond,
	RwInt32** lppanAvgBytesPassedToAppByRecvMsgTypeThisSecond
) {

}

void CBoGame::UpdateVideoCapture() {

}

template <>
unsigned short* CGtUnicode::PrintStringN(RwInt32 lnBufferLength, GtUTF16* lpTargetString, const GtUTF16* lpFormatString, const int& lV1) {
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

void CBoTimer::Construct() {}

void CBoTimer::SetAllowSlowMo(bool lbAllowSlowmo) {

}

void CBoManagedMemoryBlock::Construct(void* lpMemoryBlock, RwInt32 lnMemoryLayout, RwInt32 lnSize) {}

void CBoManagedMemoryBlock::Destruct() {
}

void* CBoManagedMemoryBlock::GetMemoryBlock(RwInt32 lnCurrentMemoryLayout) {
    return nullptr;
}

void CBoManagedMemoryBlock::ReleaseMemoryBlock(RwInt32) {}

void CBoManagedMemoryBlock::Update(RwInt32) {}

void* CBoManagedMemoryBlock::QueryMemoryBlock(RwInt32) const {
    return nullptr;
}

RwInt32 CBoManagedMemoryBlock::GetBlockSize() const {
	return RwInt32();
}

bool CBoManagedMemoryBlock::IsAcquired() {
	return false;
}
