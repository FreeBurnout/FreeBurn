#include "../../Common/Game/BoGame.h"
#include "../../Common/Game/BoLanguageManager.h"
#include "../../Common/Game/BoMemoryCardManager.h"
#include "../../Common/Game/BoProfileManager.h"
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

void CBoGame::Update() {
    EGtFramerateType EVar1;
    int iVar2;
    CGtTimer * this_00;
    EGtGameUpdateState uVar3;
    CBoGameMode * gameMode;
    CGtState * lVar4 = nullptr;
    unsigned long uVar5;
    CBoInputManager * this_01;

    iVar2 = mNonDeterministicRNG.mnHigh;
    iVar2 = (iVar2 << 0x10) + (iVar2 >> 0x10) + mNonDeterministicRNG.mnLow;
    mNonDeterministicRNG.mnHigh = iVar2;
    mNonDeterministicRNG.mnLow += iVar2;

    gDebugManager.UpdateStartOfFrame();
    mbRequestSimulationPause = false;
    mbRequestSimulationUnpause = false;

    if (!gGame.IsSimulationPaused() && (meUpdateState != meRequestedUpdateState)) {
        meUpdateState = meRequestedUpdateState;
    }

    mAsyncDataLoader.Update();
    gMemoryManager.Update();
    iVar2 = gGraphicsManager.GetVBlankCount();
    CGtHiResSystemTimer::Update(iVar2);
    CheckPowerOff();
    this_00 = &mTimer;
    gSaveGameDataManager.mrPlayingTimeSecsCounter += mTimer.mrTimeStep;
    switch (meUpdateState) {
    case EGtGameUpdateState::Prepared:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        Update();
        gWorld.mTimer.Update();
        gameMode = mpRequestedGameMode;
        mpRequestedGameMode = nullptr;
        break;
    default:
        goto LAB_0010430c;
    case EGtGameUpdateState::SimulationPrepare:
        goto switchD_00103ce0_caseD_4;
    case EGtGameUpdateState::SimulationUpdate:
        goto switchD_00103ce0_caseD_5;
    case EGtGameUpdateState::ChangeGameMode:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        Update();
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
        /*
        TODO: uhhhhhhhhhhhhhhhhhhhh
        iVar2 = *(int *)(*(int *)(mpCurrentGameMode) + 0xc);
        (**(code **)(iVar2 + 0x2c))(*(int *)(mpCurrentGameMode) + (int)*(short *)(iVar2 + 0x28));
        */
        gameMode = mpRequestedGameMode;
        mpRequestedGameMode = nullptr;
        mbRequestForceHalfFramerate = false;
        break; 
    case EGtGameUpdateState::RestartGameMode:
    case EGtGameUpdateState::RestartGameModeNewLevelRestarting:
        if (RestartGameModeUpdateCode()) {
            goto LAB_0010430c;
        } else {
            uVar3 = EGtGameUpdateState::SimulationPrepare;
            goto LAB_00103f04;
        }
    case EGtGameUpdateState::RestartGameModeNewLevelInit:
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        Update();
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
        goto LAB_0010430c;
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
            uVar3 = EGtGameUpdateState::StartReplay;
        LAB_00103f04:
            meUpdateState = uVar3;
            meRequestedUpdateState = uVar3;
        }
        goto LAB_0010430c;
    case EGtGameUpdateState::StartReplay:
        /*
        iVar2 = *(int *)(*(int *)(this + 0x57c18) + 0xc);
        (**(code **)(iVar2 + 0x34))(*(int *)(this + 0x57c18) + (int)*(short *)(iVar2 + 0x30));*/
        meUpdateState = EGtGameUpdateState::SimulationPrepare;
        meRequestedUpdateState = EGtGameUpdateState::SimulationPrepare;
        goto switchD_00103ce0_caseD_4;
    }
    mpCurrentGameMode = gameMode;
    gMenuFlowManager.Update();
    meRequestedUpdateState = EGtGameUpdateState::RestartGameMode;
LAB_0010430c:
    gGraphicsManager.OpenViewport(EBoViewportSelection::Main);
    if (!mbWorldPrepared && mbRequestSimulationUnpause) {
        gGraphicsManager.RenderFullScreenPass(mClearFrameBufferColour, EBoFullScreenPassBlendMode::Additive);
    }
    else {
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
    return;
switchD_00103ce0_caseD_4:
    mbWorldPrepared = PrepareWorld();
    if (!mbWorldPrepared) {
        mTimer.NextFrame();
        gNetworkManager.muFrameCount++;
        Update();
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
        mbRequestSimulationPause = false;
        mbRequestSimulationUnpause = false;
        /*
        if ((*(int **)(this + 0x57c18) != (int *)0x0) && (iVar2 = **(int **)(this + 0x57c18), iVar2 != 0)) {
            (**(code **)(*(int *)(iVar2 + 0xd4) + 0x1dc))(iVar2 + *(short *)(*(int *)(iVar2 + 0xd4) + 0x1d8));
        }*/
        mFramerateManager.Prepare();
        meUpdateState = EGtGameUpdateState::SimulationUpdate;
        meRequestedUpdateState = EGtGameUpdateState::SimulationUpdate;
        if (!(gWorld.mbIsReplaying || !gWorld.mbRequestReplay)) {
            gMenuFlowManager.SetInitialMenuState();
        }
    switchD_00103ce0_caseD_5:
        UpdatePreSimulation();
        EVar1 = meDebugFramerateType;
        if (EVar1 == EGtFramerateType::Max) {
            EVar1 = meFramerateType;
        }
        mFramerateManager.StartUpdateFrame(EVar1, mnGamePausedByPlayer == -1 && gGame.IsSimulationPaused() == 0);
        iVar2 = 0;
        this_01 = &mInputManager;
        if (mnSimulationUpdateCount > 0) {
            if (mnRequestPause == -1) {
                while (mnRequestPause == -1) {
                    mTimer.NextFrame();
                    gNetworkManager.muFrameCount++;
                    Update();
                    gWorld.mTimer.Update();
                    if (!gNetworkManager.mbUppingInterface) {
                        Update();
                        if (!mInputManager.AreLockedPlayersConnected() && gGame.mnGamePausedByPlayer == -1 && !gNetworkManager.mbIsOnline) {
                            lVar4->mID = 0x6d6123044330fccf;
                            if (gMenuFlowManager.mpState != nullptr) {
                                lVar4 = gMenuFlowManager.mpState;
                            }
                            if (lVar4->mID == -0x6bb7c5da87bef9af) {
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
                    if (mnGamePausedByPlayer == -1) {
                        if (gDebugManager.mbPlay) {
                            UpdateSimulation();
                            goto LAB_00104264;
                        }
                    }
                    else {
                    LAB_00104264:
                        if (gDebugManager.mbPlay) {
                            gMenuFlowManager.Update();
                        }
                    }
                    gDebugMenuPageManager.Update();
                    if (meRequestedUpdateState != EGtGameUpdateState::SimulationUpdate || mbRequestSimulationPause || mbRequestSimulationUnpause || mnSimulationUpdateCount <= ++iVar2 ) {
                        goto LAB_001042dc;
                    }
                }
                mFramerateManager.mnPrevNumSimulationStepsRequired = iVar2;
            }
            else {
                mFramerateManager.mnPrevNumSimulationStepsRequired = 0;
            }
        }
    LAB_001042dc:
        UpdatePostSimulation();
        //_rwDMAWaitQueue();
        mnSimulationUpdateCount = GetNumSimulationUpdatesRequired();
        Render();
    }
    goto LAB_0010430c;
}

void CBoGame::ConstructHardware() {

}

void CBoGame::CheckPowerOff() {

}

void CBoGame::PreparePowerOff() {

}

bool CBoGame::PrepareWorld() {
    return false;
}

void CBoGame::DisplayInsertControllerMessage() {

}

void CBoGame::SetDemoPath(RwChar * lpacPath) {

}

void CBoGame::UpdatePreSimulation() {

}

void CBoGame::UpdatePostSimulation() {

}

bool CBoGame::RestartGameModeUpdateCode() {
    return false;
}

RwInt32 CBoGame::GetNumSimulationUpdatesRequired() {
    return RwInt32();
}

void CBoGame::UpdateSimulation() {

}

void CBoGame::SleepToAllowWorkerThreadsToRun() {

}

void CBoGame::Render() {

}

bool CBoGame::IsSimulationPaused() {
    return false;
}