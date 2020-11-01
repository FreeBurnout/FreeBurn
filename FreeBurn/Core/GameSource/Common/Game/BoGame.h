#include <rwcore.h>

#include "BoGameMode.h"
#include "BoAsyncDataLoader.h"
#include "BoPlayer.h"
#include "BoSettings.h"
#include "BoFrontEnd.h"
#include "BoOnlineStage.h"
#include "BoInputManager.h"
#include "BoTimer.h"
#include "Challenge/BoChallenge.h"
#include "Challenge/BoTurnBasedCrashChallenge.h"
#include "Logic/BoCrashModeLogic.h"
#include "Logic/Single/BoSingleRaceLogic.h"
#include "Logic/Single/BoSingleRevengeLogic.h"
#include "Logic/Single/BoSingleRoadRageLogic.h"
#include "Logic/BoMultiplayerRoadRageLogic.h"
#include "Logic/Online/BoOnlineSingleRaceLogic.h"
#include "Logic/Online/BoOnlineRevengeLogic.h"
#include "Logic/Online/BoOnlineRoadRageLogic.h"
#include "Logic/Online/BoOnlineCrashModeLogic.h"
#include "Logic/BoCarViewerLogic.h"
#include "../Camera/BoPlayerCameraManager.h"
#include "../Game/Logic/BoStageLogic.h"
#include "../../../SharedClasses/BoProgressionDataStruct.h"
#include "../../../SharedClasses/BoDataLists.h"
#include "../../../../GameShared/PC/Numeric/GtMathPC.h"
#include "../../../../GameShared/PC/Graphical/GtTexturePC.h"
#include "../../../../GameShared/Common/Numeric/GtRandom.h"
#include "../../../../GameShared/Common/System/GtFramerateManager.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"
#include "../../../../GameShared/Common/System/GtMemoryCardManager.h"
#include "../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"

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

class CBoSecondaryRewardsManager {

};

class CBoGame {
public:
	CBoGame();

	void ConstructHardware();
	bool PrepareHardware();
	void CheckPowerOff();
	void PreparePowerOff();
	bool CheckFatalDiskError();
	void SetFrontendFrameRate(bool);
	void BootNFLStreet2Demo();

	void     Construct();
	void     SetDemoPath(char *);
	bool     Prepare();
	void     Update();
	bool     IsSimulationPaused();
	bool     RestartGameModeUpdateCode();
	bool     PrepareWorld();
	void     SleepToAllowWorkerThreadsToRun();
	void     UpdatePreSimulation();
	void     UpdateSimulation();
	void     UpdatePostSimulation();
	RwInt32  GetNumSimulationUpdatesRequired();
	void     Render();
	void     DisplayInsertControllerMessage();
	void     Release();
	void     Destruct();
	bool     ResetGameMode();
	void     RequestNewGameMode(CBoGameMode *);
	bool     IsTurnBasedCrash();
	bool     Is2PlayerSplitScreen();
	bool     IsMultiplayerMode();
	void     CalculateSendRecvFigures();
	void     DrawQuickLoadScreen();
	RwChar * GetDemoPath();

private:
    CBoSettings*            mSettings;
    CBoTimer*               mTimer;
    CBoInputManager*        mInputManager;
    CGtFileSystem            mpFileSystem;
    CGtValueDatabase         mValueDatabase;
    CBoAsyncDataLoader       mAsyncDataLoader;
    CGtCommsToolBase         mCommsManager;
    CBoPlayer                maPlayers[2];
    CBoPlayerCameraManager   maPlayerCamera[2];
    CMemoryDeviceBase        mMemoryCard; // Originally CMemoryDevicePS2.
    CGtRandom                mNonDeterministicRNG;
    CGtTexture               mpGlobalTextureDictionary;
    bool                     mbGlobalTextureDictionaryLoaded;
    CBoProgressionDataStruct mpProgressionData;
    bool                     mbProgressionDataLoaded;
    CBoVehicleList           mVehicleList;
    CBoTrackList             mTrackList;
    bool                     mbVehicleListLoaded;
    bool                     mbTrackListLoaded;
    bool                     mbInputManagerPrepared;

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

    void             SetQuitNow();
    bool             WillQuitNow();
    void             SetBootNFLStreet2DemoNow();
    bool             WillBootNFLStreet2DemoNow();
    CBoGameMode *    GetCurrentGameMode();
    CBoStageLogic *  GetCurrentStageLogic();
    CBoGameMode *    GetRequestedGameMode();
    void             RequestPause(int);
    void             RequestResume(int);
    bool             IsPaused();
    bool             IsPauseRequested();
    bool             IsResumeRequested();
    RwInt32          GetPausePlayerIndex();
    void             RequestWorldPrepare(bool);
    void             ClearFrameBufferDuringWorldPrepare(GtMathPC::CGtV4d);
    bool             IsWorldPrepared();
    void             RequestHalfFramerate(bool);
    bool             GetHalfFramerate();
    void             RequestFramerateType(EGtFramerateType);
    EGtFramerateType GetFramerateType();
    bool             OnlineUpdate();
    bool             OfflineUpdate();
    RwReal           GetNumSimulationUpdatesThisRenderFrame();
    void             RequestGameUpdateState(EGameUpdateState);
    EGameUpdateState GetRequestedGameUpdateState();
    EGameUpdateState GetCurrentGameUpdateState();
    bool             IsNewRequestedGameUpdateState();
    bool             IsCrashMode();
    void             SetIsCrashMode(bool);
    void             SetIsLapEliminatorMode(bool);
    bool             IsTrafficAttackMode();
    void             SetIsTrafficAttackMode(bool);
    bool             IsRoadRageMode();
    void             SetIsRoadRageMode(bool);
    bool             IsLapEliminatorMode();
	bool             IsInChampionship();
    RwReal           GetCameraTimeStep() const;
    RwReal           GetCameraTimeStepNoSlowMo() const;
    RwInt32          GetSimulationUpdateCount() const;
    void             AttemptToInsertExtraSimulationUpdates(int);
    void             RequestSimulationPause();
    void             RequestSimulationUnpause();

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