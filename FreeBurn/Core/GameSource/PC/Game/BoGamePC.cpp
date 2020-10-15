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

void CBoGame::ConstructHardware() {
}

void CBoGame::PreparePowerOff() {
}

// DONE
RwChar * CBoGame::GetDemoPath() {
    return mpacDemoPath;
}

// DONE
bool CBoGame::PrepareWorld() {
    return gWorld.Prepare(mbQuickWorldPrepare);
}

void CBoGame::CheckPowerOff() {
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
        if (gMenuFlowManager.mpState->mID != 0 && gMenuFlowManager.mpState->mID != gMenuFlowManager.maOffsetTable[28].mID) {
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

void CBoGame::UpdateSimulation() {

}

void CBoGame::SleepToAllowWorkerThreadsToRun() {

}

// DONE
bool CBoGame::IsSimulationPaused() {
    return !mbPlay || !gDebugManager.mbPlay;
}

bool CBoGame::ResetGameMode() {
    return false;
}

void __renderStuff(CBoGame * game) {
    gGraphicsManager.OpenViewport(EBoViewportSelection::Main);
    if (!(*game).mbWorldPrepared && (*game).mbClearFrameBufferDuringWorldPrepare) {
        gGraphicsManager.RenderFullScreenPass((*game).mClearFrameBufferColour, EBoFullScreenPassBlendMode::Additive);
    }
    else {
        gDebugMenuPageManager.Render();
        gAptManager.Render(gGame.mTimer.mrTimeStep * (float)gGame.mnSimulationUpdateCount);
        gEATraxDisplay.Render();
    }
    if (!(*game).mInputManager.AreLockedPlayersConnected() && (*game).mbWorldPrepared) {
        (*game).DisplayInsertControllerMessage();
    }
    gDebugManager.RenderOverlays();
    gGraphicsManager.CloseViewport();
    gGraphicsManager.PresentDrawBuffer();
    (*game).maPlayerCamera[0].SetCutThisFrame(false);
    (*game).maPlayerCamera[1].SetCutThisFrame(false);
}

void CBoGame::Update() {
    EGtFramerateType EVar1;
    int uVar3;
    long lVar4;
    int iVar2 = 0;
    mNonDeterministicRNG.mnHigh = (mNonDeterministicRNG.mnHigh << 0x10) + (mNonDeterministicRNG.mnHigh >> 0x10) + mNonDeterministicRNG.mnLow;
    mNonDeterministicRNG.mnLow += mNonDeterministicRNG.mnHigh;
    gDebugManager.UpdateStartOfFrame();
    mbPlay = !mbRequestSimulationPause && mbRequestSimulationUnpause;
    mbRequestSimulationPause = false;
    mbRequestSimulationUnpause = false;
    if ((!gGame.IsSimulationPaused()) && (meUpdateState != meRequestedUpdateState)) {
        meUpdateState = meRequestedUpdateState;
    }
    mAsyncDataLoader.Update();
    gMemoryManager.Update();
    int vbCount = gGraphicsManager.GetVBlankCount();
    CGtHiResSystemTimer::Update(vbCount);
    CheckPowerOff();
    gSaveGameDataManager.mrPlayingTimeSecsCounter += mTimer.mrTimeStep;
    switch (meUpdateState) {
    case EGtGameUpdateState::Prepared:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        mTimer.Update();
        gWorld.Update();
        uVar3 = (int)mpRequestedGameMode;
        mpRequestedGameMode = 0;
        mpCurrentGameMode = (CBoGameMode *)uVar3;
        gMenuFlowManager.Update();
        meRequestedUpdateState = EGtGameUpdateState::RestartGameMode;
        break;
    
    case EGtGameUpdateState::SimulationUpdate:
        UpdatePreSimulation();
        EVar1 = meDebugFramerateType;
        if (EVar1 == EGtFramerateType::Max) {
            EVar1 = meFramerateType;
        }
        mFramerateManager.StartUpdateFrame(EVar1, !(mnGamePausedByPlayer == -1 && !gGame.IsSimulationPaused()));
        iVar2 = 0;
        if (mnSimulationUpdateCount > 0) {
            if (mnRequestPause == -1) {
                while (mnRequestPause == -1) {
                    mTimer.NextFrame();
                    gNetworkManager.muFrameCount++;
                    mTimer.Update();
                    gWorld.mTimer.Update();
                    if (!gNetworkManager.mbUppingInterface) {
                        mInputManager.Update();
                        if ((!mInputManager.AreLockedPlayersConnected() && gGame.mnGamePausedByPlayer == -1) && !gNetworkManager.mbIsOnline) {
                            lVar4 = 0x6d6123044330fccf;
                            if (gMenuFlowManager.mpState != nullptr) {
                                lVar4 = (*gMenuFlowManager.mpState).mID;
                            }
                            if (lVar4 == gMenuFlowManager.maOffsetTable[3].mID) {
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
                    if (((meRequestedUpdateState != EGtGameUpdateState::SimulationUpdate) || mbRequestSimulationPause) || ((iVar2++, mbRequestSimulationUnpause || (mnSimulationUpdateCount <= iVar2)))) {
                        UpdatePostSimulation();
                        // _rwDMAWaitQueue();
                        uVar3 = GetNumSimulationUpdatesRequired();
                        mnSimulationUpdateCount = uVar3;
                        Render();
                        __renderStuff(this);
                        return;
                    }
                }
                mFramerateManager.mnPrevNumSimulationStepsRequired = iVar2;
            }
            else {
                mFramerateManager.mnPrevNumSimulationStepsRequired = 0;
            }
        }
        UpdatePostSimulation();
        // _rwDMAWaitQueue();
        mnSimulationUpdateCount = GetNumSimulationUpdatesRequired();
        Render();
        __renderStuff(this);
        return;
    case EGtGameUpdateState::ChangeGameMode:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        mTimer.Update();
        gWorld.mTimer.Update();
        mnRequestResume = 0xffffffff;
        mnGamePausedByPlayer = 0xffffffff;
        mnRequestPause = 0xffffffff;
        if (!gNetworkManager.mbUppingInterface) {
            mInputManager.ResetState();
            mInputManager.Update();
        }
        gWorld.Release();
        mbWorldPrepared = false;
        /*iVar2 = *(int *)(*(int *)(this + 0x57c18) + 0xc);
         (**(code **)(iVar2 + 0x2c))(*(int *)(this + 0x57c18) + (int)*(short *)(iVar2 + 0x28));*/
        uVar3 = (int)mpRequestedGameMode;
        mpRequestedGameMode = 0;
        mbRequestForceHalfFramerate = false;
        mpCurrentGameMode = (CBoGameMode *)uVar3;
        gMenuFlowManager.Update();
        meRequestedUpdateState = EGtGameUpdateState::RestartGameMode;
        break;
    case EGtGameUpdateState::RestartGameModeNewLevelInit:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        mTimer.Update();
        gWorld.mTimer.Update();
        mnRequestResume = 0xffffffff;
        mnGamePausedByPlayer = 0xffffffff;
        mnRequestPause = 0xffffffff;
        mInputManager.ResetState();
        gSoundManager.StopAll();
        gWorld.Release();
        mbWorldPrepared = false;
        mpCurrentGameMode->mbDoFullPrepare = true;
        meUpdateState = EGtGameUpdateState::RestartGameModeNewLevelRestarting;
        meRequestedUpdateState = EGtGameUpdateState::RestartGameModeNewLevelRestarting;
        __renderStuff(this);
        return;
    case EGtGameUpdateState::RestartGameMode:
    case EGtGameUpdateState::RestartGameModeNewLevelRestarting:
        if (!RestartGameModeUpdateCode()) {
            meUpdateState = EGtGameUpdateState::SimulationPrepare;
            meRequestedUpdateState = EGtGameUpdateState::SimulationPrepare;
        }
        __renderStuff(this);
        return;
    case EGtGameUpdateState::RestartGameModeWithNewConfigInit:
        mnRequestResume = 0xffffffff;
        mnGamePausedByPlayer = 0xffffffff;
        mnRequestPause = 0xffffffff;
        mInputManager.ResetState();
        gSoundManager.StopAll();
        gWorld.Release();
        mbWorldPrepared = false;
        mpCurrentGameMode->mbDoFullPrepare = true;
        meUpdateState = EGtGameUpdateState::RestartGameModeWithNewConfigRestarting;
        meRequestedUpdateState = EGtGameUpdateState::RestartGameModeWithNewConfigRestarting;
    case EGtGameUpdateState::RestartGameModeWithNewConfigRestarting:
        if (RestartGameModeUpdateCode()) {
            meUpdateState = EGtGameUpdateState::StartReplay;
            meRequestedUpdateState = EGtGameUpdateState::StartReplay;
        }
        __renderStuff(this);
        return;
    case EGtGameUpdateState::StartReplay:
        /*iVar2 = *(int *)(*(int *)(this + 0x57c18) + 0xc);
         (**(code **)(iVar2 + 0x34))(*(int *)(this + 0x57c18) + (int)*(short *)(iVar2 + 0x30));*/
        meUpdateState = EGtGameUpdateState::SimulationPrepare;
        meRequestedUpdateState = EGtGameUpdateState::SimulationPrepare;
        break;
    default:
        __renderStuff(this);
        return;
    }
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
    } else {
        mbQuickWorldPrepare = false;
        mbClearFrameBufferDuringWorldPrepare = false;
        if (mpCurrentGameMode != nullptr && mpCurrentGameMode->mpStageLogic != nullptr) {
            // (**(code **)(*(int *)(iVar2 + 0xd4) + 0x1dc))(iVar2 + *(short *)(*(int *)(iVar2 + 0xd4) + 0x1d8));
        }
        mFramerateManager.Prepare();
        meUpdateState = EGtGameUpdateState::SimulationUpdate;
        meRequestedUpdateState = EGtGameUpdateState::SimulationUpdate;
        if (!gWorld.mbIsReplaying && !gWorld.mbRequestReplay) {
            gMenuFlowManager.SetInitialMenuState();
        }
        UpdatePreSimulation();
        EVar1 = meDebugFramerateType;
        if (EVar1 == EGtFramerateType::Max) {
            EVar1 = meFramerateType;
        }
        mFramerateManager.StartUpdateFrame(EVar1, !(mnGamePausedByPlayer == -1 && !gGame.IsSimulationPaused()));
        if (mnSimulationUpdateCount > 0) {
            if (mnRequestPause == -1) {
                while (mnRequestPause == -1) {
                    mTimer.NextFrame();
                    gNetworkManager.muFrameCount++;
                    mTimer.Update();
                    gWorld.mTimer.Update();
                    if (!gNetworkManager.mbUppingInterface) {
                        mInputManager.Update();
                        if ((!mInputManager.AreLockedPlayersConnected() && gGame.mnGamePausedByPlayer == -1) && !gNetworkManager.mbIsOnline) {
                            lVar4 = 0x6d6123044330fccf;
                            if (gMenuFlowManager.mpState != nullptr) {
                                lVar4 = (*gMenuFlowManager.mpState).mID;
                            }
                            if (lVar4 == gMenuFlowManager.maOffsetTable[3].mID) {
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
                    if (((meRequestedUpdateState != EGtGameUpdateState::SimulationUpdate) || mbRequestSimulationPause) || ((iVar2++, mbRequestSimulationUnpause != false || (mnSimulationUpdateCount <= iVar2)))) {
                        UpdatePostSimulation();
                        // _rwDMAWaitQueue();
                        mnSimulationUpdateCount = GetNumSimulationUpdatesRequired();
                        Render();
                        __renderStuff(this);
                        return;
                    }
                }
                mFramerateManager.mnPrevNumSimulationStepsRequired = iVar2;
            }
            else {
                mFramerateManager.mnPrevNumSimulationStepsRequired = 0;
            }

        }
        UpdatePostSimulation();
        // _rwDMAWaitQueue();
        mnSimulationUpdateCount = GetNumSimulationUpdatesRequired();
        Render();
    }
    __renderStuff(this);
}



void CBoGame::DisplayInsertControllerMessage() {

}
