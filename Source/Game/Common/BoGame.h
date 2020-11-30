#include <rwcore.h>

#include "BoAsyncDataLoader.h"
#include "BoGameMode.h"
#include "BoPlayer.h"
#include "BoSettings.h"
#include "BoFrontEnd.h"
#include "BoOnlineStage.h"
#include "BoInputManager.h"
#include "BoProgressionManager.h"
#include "BoTimer.h"
#include "Challenge/BoChallenge.h"
#include "Challenge/BoTurnBasedCrashChallenge.h"
#include "Logic/BoCrashModeLogic.h"
#include "Logic/BoCarViewerLogic.h"
#include "Logic/BoMultiplayerRoadRageLogic.h"
#include "Logic/BoStageLogic.h"
#include "Logic/Single/BoSingleRaceLogic.h"
#include "Logic/Single/BoSingleRevengeLogic.h"
#include "Logic/Single/BoSingleRoadRageLogic.h"
#include "Logic/Online/BoOnlineSingleRaceLogic.h"
#include "Logic/Online/BoOnlineRevengeLogic.h"
#include "Logic/Online/BoOnlineRoadRageLogic.h"
#include "Logic/Online/BoOnlineCrashModeLogic.h"
#include "Progression/BoProgressionDataStruct.h"
#include "../../Camera/BoPlayerCameraManager.h"
#include "../../World/Common/BoDataLists.h"
#include "../../../../Shared/Numeric/Math/PC/GtMathPC.h"
#include "../../../../Shared/Graphical/PC/GtTexturePC.h"
#include "../../../../Shared/Numeric/GtRandom.h"
#include "../../../../Shared/System/Common/GtFramerateManager.h"
#include "../../../../Shared/System/Common/FileSystem/GTFileSystem.h"
#include "../../../../Shared/System/Common/GtMemoryCardManager.h"
#include "../../../../Shared/Development/CommsTool/GtCommsDatabase.h"
#include "../../../../Shared/Graphical/Common/GtColour.h"
#include "../../../../Shared/System/Common/GtFSM.h"

using namespace GtMathPC;

enum class EGameUpdateState {
    eGameUpdateStateConstructed = 0,
    eGameUpdateStatePrepared = 1,
    eGameUpdateStateReleased = 2,
    eGameUpdateStateDestructed = 3,
    eGameUpdateStateSimulationPrepare = 4,
    eGameUpdateStateSimulationUpdate = 5,
    eGameUpdateStateChangeGameMode = 6,
    eGameUpdateStateRestartGameMode = 7,
    eGameUpdateStateRestartGameModeNewLevelInit = 8,
    eGameUpdateStateRestartGameModeNewLevelRestarting = 9,
    eGameUpdateStateRestartGameModeWithNewConfigInit = 10,
    eGameUpdateStateRestartGameModeWithNewConfigRestarting = 11,
    eGameUpdateStateStartReplay = 12
};

class CBoGame {
public:
	CBoGame();
	void ConstructHardware();
	bool PrepareHardware();
	void CheckPowerOff();
	void PreparePowerOff();
	bool CheckFatalDiskError();
	void SetFrontendFrameRate(bool param);
	void BootNFLStreet2Demo();
	void Construct();
	void SetDemoPath(char * lpacPath);
	bool Prepare();
	void Update();
	bool IsSimulationPaused();
	bool RestartGameModeUpdateCode();
	bool PrepareWorld();
	void SleepToAllowWorkerThreadsToRun();
	RwInt32 GetNumSimulationUpdatesRequired();
	void Render();
	void DisplayInsertControllerMessage();
	void Release();
	void Destruct();
	bool ResetGameMode();
	void RequestNewGameMode(CBoGameMode * lpNewGameMode);
	bool IsTurnBasedCrash();
	bool Is2PlayerSplitScreen();
	bool IsMultiplayerMode();
	void CalculateSendRecvFigures();
	void DrawQuickLoadScreen();
	RwChar * GetDemoPath();

private:
    CBoSettings* mSettings;
    CBoTimer* mTimer;
    CBoInputManager* mInputManager;
    CGtFileSystem mpFileSystem;
    CGtValueDatabase mValueDatabase;
    CBoAsyncDataLoader mAsyncDataLoader;
    CGtCommsToolBase mCommsManager;
    CBoPlayer maPlayers[2];
    CBoPlayerCameraManager maPlayerCamera[2];
    CMemoryDeviceBase mMemoryCard; // Originally CMemoryDevicePC.
    CGtRandom mNonDeterministicRNG;
    CGtTexture mpGlobalTextureDictionary;
    bool mbGlobalTextureDictionaryLoaded;
    CBoProgressionDataStruct mpProgressionData;
    bool mbProgressionDataLoaded;
    CBoVehicleList mVehicleList;
    CBoTrackList mTrackList;
    bool mbVehicleListLoaded;
    bool mbTrackListLoaded;
    bool mbInputManagerPrepared;

#pragma region Logic
    CBoFrontEnd                  mGameModeFrontEnd;
    CBoOnePlayerStage            mGameModeOnePlayerRace;
    CBoTwoPlayerSplitScreenStage mGameModeTwoPlayerRace;
    CBoOnlineStage               mGameModeOnlineRace;
    CBoSingleRaceLogic           mOfflineSingleRaceLogic;
    CBoCrashModeLogic            mOfflineCrashModeLogic;
    CBoSingleRevengeLogic        mOfflineSingleRevengeLogic;
    CBoSingleRoadRageLogic       mOfflineSingleRoadRageLogic;
    CBoMultiplayerRoadRageLogic  mOfflineMultiplayerRoadRageLogic;
    CBoBurningLapLogic           mOfflineSingleBurningLapLogic;
    CBoEliminatorLogic           mOfflineSingleEliminatorLogic;
    CBoCompCrashModeLogic        mOfflineCompCrashModeLogic;
    CBoPartyCrashModeLogic       mOfflinePartyCrashModeLogic;
    CBoTourCrashModeLogic        mOfflineTourCrashModeLogic;
    CBoOnlineSingleRaceLogic     mOnlineSingleRaceLogic;
    CBoOnlineRevengeLogic        mOnlineRevengeLogic;
    CBoOnlineRoadRageLogic       mOnlineRoadRageModeLogic;
    CBoOnlineGolfCrashModeLogic  mOnlineGolfCrashModeLogic;
    CBoOnlineCompCrashModeLogic  mOnlineCompCrashModeLogic;
    CBoOnlinePartyCrashModeLogic mOnlinePartyCrashModeLogic;
    CBoCarViewerLogic            mCarViewerLogic;
    CBoSingleChallenge           mSingleChallenge;
    CBoChampionshipChallenge     mChampionshipChallenge;
    CBoTurnBasedCrashParty       mTurnBasedCrashPartyChallenge;
    CBoTurnBasedCrashTour        mTurnBasedCrashTourChallenge;
    CBoSecondaryRewardsManager   mSecondaryRewardsManager;
#pragma endregion

    bool mbShutterClosed;
    bool mbProgressionPage;
    bool mbFrontEndFlow;
    bool mbLaunchedDemo;
    CGtRGBA mClearFrameBufferColour;
    CGtFramerateManager mFramerateManager;
    char mpacDemoPath[256];
    CBoGameMode * mpCurrentGameMode;
    CBoGameMode * mpRequestedGameMode;
    bool mbQuitNow;
    RwInt32 mnGamePausedByPlayer;
    RwInt32 mnRequestPause;
    RwInt32 mnRequestResume;
    EGtPrepareState mePrepareState;
    bool mbWorldPrepared;
    bool mbQuickWorldPrepare;
    bool mbClearFrameBufferDuringWorldPrepare;
    bool mbRequestForceHalfFramerate;
    bool mbForceHalfFramerate;
    EGtFramerateType meFramerateType;
    EGtFramerateType meDebugFramerateType;
    EGtPrepareState  meHardwarePrepareState;
    void * mpProgressionDataBuffer;
    bool mbPowerOffTriggered;
    bool mbDev9Loaded;
    bool mbRequestRestartGameModeWithNewConfig;
    bool mbIsCrashMode;
    bool mbIsLapEliminatorMode;
    bool mbIsTrafficAttackMode;
    bool mbIsRoadRageMode;
    RwInt32 mnSimulationUpdateCount;
    RwReal mrCameraTimeStep;
    EGameUpdateState meRequestedUpdateState;
    EGameUpdateState meUpdateState;
    bool mbPlay;
    bool mbRequestSimulationPause;
    bool mbRequestSimulationUnpause;
    bool mbBootNFLStreet2Demo;
    char macMainVDBBuffer[51200];
    RwReal mrGamePlayTime;
    RwReal mrMaxGamePlayTime;
           
    void UpdatePreSimulation();
    void UpdateSimulation();
    void UpdatePostSimulation();
    void SetQuitNow();
    bool WillQuitNow();
    void SetBootNFLStreet2DemoNow();
    bool WillBootNFLStreet2DemoNow();
    CBoGameMode * GetCurrentGameMode();
    CBoStageLogic * GetCurrentStageLogic();
    CBoGameMode * GetRequestedGameMode();
    void RequestPause(int param);
    void RequestResume(int param);
    bool IsPaused();
    bool IsPauseRequested();
    bool IsResumeRequested();
    RwInt32 GetPausePlayerIndex();
    void RequestWorldPrepare(bool param);
    void ClearFrameBufferDuringWorldPrepare(CGtV4d param);
    bool IsWorldPrepared();
    void RequestHalfFramerate(bool param);
    bool GetHalfFramerate();
    void RequestFramerateType(EGtFramerateType param);
    EGtFramerateType GetFramerateType();
    bool OnlineUpdate();
    bool OfflineUpdate();
    RwReal GetNumSimulationUpdatesThisRenderFrame();
    void RequestGameUpdateState(EGameUpdateState param);
    EGameUpdateState GetRequestedGameUpdateState();
    EGameUpdateState GetCurrentGameUpdateState();
    bool IsNewRequestedGameUpdateState();
    bool IsCrashMode();
    void SetIsCrashMode(bool param);
    void SetIsLapEliminatorMode(bool param);
    bool IsTrafficAttackMode();
    void SetIsTrafficAttackMode(bool param);
    bool IsRoadRageMode();
    void SetIsRoadRageMode(bool param);
    bool IsLapEliminatorMode();
	bool IsInChampionship();
    RwReal GetCameraTimeStep() const;
    RwReal GetCameraTimeStepNoSlowMo() const;
    RwInt32 GetSimulationUpdateCount() const;
    void AttemptToInsertExtraSimulationUpdates(int param);
    void RequestSimulationPause();
    void RequestSimulationUnpause();

    void GetSendRecvFigures(
        RwInt32 * lpnBytesSentToWireLastSecond, 
        RwInt32 * lpnBytesRecvdFromWireLastSecond,
        RwInt32 * lpnBytesSubmittedForSendLastSecond,
        RwInt32 * lpnBytesPassedToAppByRecvLastSecond,
        RwInt32 ** lppanAvgBytesSubmittedForSendMsgTypeThisSecond,
        RwInt32 ** lppanAvgBytesPassedToAppByRecvMsgTypeThisSecond
    );

    void UpdateVideoCapture();
};