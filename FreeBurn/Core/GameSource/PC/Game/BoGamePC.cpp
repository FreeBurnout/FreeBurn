#include "../../Common/Game/BoGame.h"
#include "../../Common/Game/BoLanguageManager.h"
#include "../../Common/Game/BoMemoryCardManager.h"
#include "../../Common/Game/BoProfileManager.h"
#include "../../Common/Game/BoLanguageManager.h"
#include "../../Common/Graphics/BoIm3d.h"
#include "../../Common/Network/BoNetworkManager.h"
#include "../../Common/Menu/DebugMenu/Pages/BoDebugDebugMenuPage.h"
#include "../../Common/Menu/Apt/AptManager/BoAptManager.h"
#include "../../Common/Menu/States/BoMenuFlowManager.h"
#include "../../Common/Menu/BoFlashMovieManager.h"
#include "../../Common/Menu/BoFlashEffectManager.h"
#include "../../Common/Sound/BoSoundManager.h"
#include "../../Common/Game/BoSaveGameDataManager.h"
#include "../../Common/World/BoWorld.h"
#include "../../Common/Game/BoDebugManager.h"
#include "../../PC/Graphics/BoGraphicsManagerPC.h"
#include "../../../../GameShared/Common/System/GtFSM.h"
#include "../../../../GameShared/PC/System/GtThreadMgrPC.h"
#include "../../../../GameShared/PC/System/GtHiResSystemTimerPC.h"
#include "../../../../GameShared/Common/System/GtTimer.h"
#include <spdlog\spdlog.h>
#include <string>

void CBoGame::Construct() {
    CGtStateOffset * pCVar1;

    mbShutterClosed = true;
    mbPlay = true;
    mbDev9Loaded = false;
    mbPowerOffTriggered = false;
    mbRequestSimulationPause = false;
    mbRequestSimulationUnpause = false;
    mbGlobalTextureDictionaryLoaded = false;
    mpGlobalTextureDictionary = nullptr;
    mVehicleList.mnVehicleCount = 0;
    mbVehicleListLoaded = false;
    mTrackList.mnTrackCount = 0;
    mbTrackListLoaded = false;
    mbRequestRestartGameModeWithNewConfig = false;
    mbProgressionPage = false;
    mbQuickWorldPrepare = false;
    mbClearFrameBufferDuringWorldPrepare = false;
    mNonDeterministicRNG.SetSeed(0x2b9d6f8);
    ConstructHardware();
    PreparePowerOff();
    CheckPowerOff();
    CGtThreadMgr::Open();
    CGtThreadMgr::EnableVBlankWait();
    gMemoryManager.Construct();
    mSettings.Construct();
    CGtHiResSystemTimer::Construct();

    if (!mSettings.mgb50Hz) {
        mTimer.PrepareTimerServices(60);
        mFramerateManager.Construct(16.666666, 0);
    } else {
        mTimer.PrepareTimerServices(50);
        mFramerateManager.Construct(20.0, 0);
    }

    mTimer.SetAllowSlowMo(false);
    mTimer.Construct();

    gCPUMonitors.Construct();
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

    gGPUMonitors.Construct();
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
    pCVar1 = gMenuFlowManager.GetOffsetTable();
    gMenuFlowManager.Construct(this, pCVar1, (CGtTimer *)(&gGame.mTimer));
    gFlashMovieManager.Construct();
    gAptManager.Construct();
    gFlashEffectManager.Construct();
    gProfileManager.Construct();
    mbQuitNow = false;
    mpCurrentGameMode = nullptr;
    mpRequestedGameMode = nullptr;
    mpGlobalTextureDictionary = nullptr;

    mGameModeFrontEnd.Construct();
    mGameModeOnePlayerRace.Construct();
    mGameModeTwoPlayerRace.Construct();
    mGameModeOnlineRace.Construct();
    mOfflineSingleRaceLogic.Construct();
    mOfflineCrashModeLogic.Construct();
    mOfflineSingleRevengeLogic.Construct();
    mOfflineSingleBurningLapLogic.Construct();
    mOfflineSingleEliminatorLogic.Construct();
    mOfflineSingleRaceLogic.Construct();
    mOfflineSingleRoadRageLogic.Construct();
    mOfflineMultiplayerRoadRageLogic.Construct();
    mOnlineSingleRaceLogic.Construct();
    mOnlineGolfCrashModeLogic.Construct();
    mOnlineCompCrashModeLogic.Construct();
    mOnlinePartyCrashModeLogic.Construct();
    mOnlineRevengeLogic.Construct();
    mCarViewerLogic.Construct();
    mTurnBasedCrashPartyChallenge.Construct();
    mTurnBasedCrashTourChallenge.Construct();

    mSecondaryRewardsManager.Construct();
    maPlayers[0].Construct();
    maPlayers[1].Construct();
    maPlayerCamera[0].Construct();
    maPlayerCamera[1].Construct();
    mnGamePausedByPlayer = 0xFFFFFFFF;
    mnRequestPause = 0xFFFFFFFF;
    mnRequestResume = 0xFFFFFFFF;
    mbWorldPrepared = false;
    mbInputManagerPrepared = false;
    mbIsRoadRageMode = false;
    meUpdateState = EGtGameUpdateState::Constructed;
    meRequestedUpdateState = EGtGameUpdateState::Constructed;
    mbIsTrafficAttackMode = false;
    meHardwarePrepareState = EGtPrepareState::Constructed;
    mePrepareState = EGtPrepareState::Constructed;
    SetDemoPath("");
}

// DONE
RwChar * CBoGame::GetDemoPath() {
    return mpacDemoPath;
}

// DONE
bool CBoGame::PrepareWorld() {
    gWorld.Prepare(mbQuickWorldPrepare);
}

// DONE
void CBoGame::SetDemoPath(RwChar * lpacPath) {
    snprintf(mpacDemoPath, 0x100, "%s", lpacPath);
}

void CBoGame::UpdatePreSimulation() {
    if (mnGamePausedByPlayer < 0 && !gWorld.mbPausedForStreamSync && !gWorld.mbPausedForNetworkSync) {
        if (gGame.IsSimulationPaused()) {
            gWorld.mTimer.Stop();
        } else {
            gWorld.mTimer.Start();
        }
    }
    if (gDebugManager.mbPlay) {
        if (mbForceHalfFramerate != mbRequestForceHalfFramerate) {
            mbForceHalfFramerate = mbRequestForceHalfFramerate;
            //_rwDMAMinVsyncCntSet(1 << mbRequestForceHalfFramerate);
        }
        if (mnRequestPause != -1) {
            mnGamePausedByPlayer = mnRequestPause;
            gWorld.mTimer.Stop();
            gSoundManager.Pause();
            mInputManager.SetPause(true);
            mnRequestPause = 0xffffffff;
            mnRequestResume = 0xffffffff;
        }
        if ((mnGamePausedByPlayer != -1) && (mnRequestResume != -1)) {
            if (mnGamePausedByPlayer == mnRequestResume) {
                mnGamePausedByPlayer = 0xffffffff;
                gSoundManager.Unpause();
                mInputManager.SetPause(false);
                gWorld.mTimer.Start();
            }
            mnRequestResume = 0xffffffff;
            mnRequestPause = 0xffffffff;
        }
    }
}

// DONE
void CBoGame::UpdatePostSimulation() {
    if (gDebugManager.mbPlay) {
        Update();
        if (gMenuFlowManager.mpState->mID != 0 && gMenuFlowManager.mpState->mID != -0x69e9ee0f73c29348) {
            gMenuFlowManager.Update();
        }
    }
    gWorld.UpdateSound();
    gSoundManager.Update();
    mrCameraTimeStep = gWorld.mTimer.mrTimeStep * mnSimulationUpdateCount;
    if ((mnGamePausedByPlayer == -1) && (!gDebugManager.mbPlayCameras)) {
        if (!gDebugManager.mCarViewerDebug.IsActive()) {
            maPlayerCamera[0].Update(mrCameraTimeStep);
            maPlayerCamera[1].Update(mrCameraTimeStep);
        }
        else {
            gDebugManager.mCarViewerDebug.UpdateCamera(mrCameraTimeStep);
        }
    }
}

// DONE
bool CBoGame::RestartGameModeUpdateCode() {
    mTimer.NextFrame();
    gNetworkManager.muFrameCount++;
    mTimer.Update();
    gWorld.mTimer.Update();
    bool reset = ResetGameMode();
    gMenuFlowManager.Update();
    return reset;
}

// DONE
RwInt32 CBoGame::GetNumSimulationUpdatesRequired() {
    return mFramerateManager.UpdatePostRenderWait(1 << mbForceHalfFramerate, 4 << mbForceHalfFramerate);
}

// DONE
bool CBoGame::IsSimulationPaused() {
    return !mbPlay || !gDebugManager.mbPlay;
}
