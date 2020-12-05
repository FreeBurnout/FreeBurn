#ifndef BOGAME_H
#define BOGAME_H

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
/* Not allowed - aw!
	bool mbBootNFLStreet2Demo;
	void BootNFLStreet2Demo();
	void SetBootNFLStreet2DemoNow();
	bool WillBootNFLStreet2DemoNow();
	*/
class CBoGame {
public:
	CBoGame();
	void AttemptToInsertExtraSimulationUpdates(int param);
	void CalculateSendRecvFigures();
	bool CheckFatalDiskError();
	void CheckPowerOff();
	void ClearFrameBufferDuringWorldPrepare(CGtV4d param);
	void Construct();
	void ConstructHardware();
	void Destruct();
	void DisplayInsertControllerMessage();
	void DrawQuickLoadScreen();
	RwReal GetCameraTimeStep() const;
	RwReal GetCameraTimeStepNoSlowMo() const;
	CBoGameMode* GetCurrentGameMode();
	EGameUpdateState GetCurrentGameUpdateState();
	CBoStageLogic* GetCurrentStageLogic();
	RwChar* GetDemoPath();
	EGtFramerateType GetFramerateType();
	bool GetHalfFramerate();
	RwInt32 GetNumSimulationUpdatesRequired();
	RwReal GetNumSimulationUpdatesThisRenderFrame();
	RwInt32 GetPausePlayerIndex();
	CBoGameMode* GetRequestedGameMode();
	EGameUpdateState GetRequestedGameUpdateState();
	void GetSendRecvFigures(RwInt32* lpnBytesSentToWireLastSecond, RwInt32* lpnBytesRecvdFromWireLastSecond, RwInt32* lpnBytesSubmittedForSendLastSecond, RwInt32* lpnBytesPassedToAppByRecvLastSecond, RwInt32** lppanAvgBytesSubmittedForSendMsgTypeThisSecond, RwInt32** lppanAvgBytesPassedToAppByRecvMsgTypeThisSecond);
	RwInt32 GetSimulationUpdateCount() const;
	bool Is2PlayerSplitScreen();
	bool IsCrashMode();
	bool IsInChampionship();
	bool IsLapEliminatorMode();
	bool IsMultiplayerMode();
	bool IsNewRequestedGameUpdateState();
	bool IsPaused();
	bool IsPauseRequested();
	bool IsResumeRequested();
	bool IsRoadRageMode();
	bool IsSimulationPaused();
	bool IsTrafficAttackMode();
	bool IsTurnBasedCrash();
	bool IsWorldPrepared();
	bool OfflineUpdate();
	bool OnlineUpdate();
	bool Prepare();
	bool PrepareHardware();
	void PreparePowerOff();
	bool PrepareWorld();
	void Release();
	void Render();
	void RequestFramerateType(EGtFramerateType param);
	void RequestGameUpdateState(EGameUpdateState param);
	void RequestHalfFramerate(bool param);
	void RequestNewGameMode(CBoGameMode* lpNewGameMode);
	void RequestPause(int param);
	void RequestResume(int param);
	void RequestSimulationPause();
	void RequestSimulationUnpause();
	void RequestWorldPrepare(bool param);
	bool ResetGameMode();
	bool RestartGameModeUpdateCode();
	void SetDemoPath(char* lpacPath);
	void SetFrontendFrameRate(bool param);
	void SetIsCrashMode(bool param);
	void SetIsLapEliminatorMode(bool param);
	void SetIsRoadRageMode(bool param);
	void SetIsTrafficAttackMode(bool param);
	void SetQuitNow();
	void SleepToAllowWorkerThreadsToRun();
	void Update();
	void UpdatePostSimulation();
	void UpdatePreSimulation();
	void UpdateSimulation();
	void UpdateVideoCapture();
	bool WillQuitNow();

	bool mbClearFrameBufferDuringWorldPrepare;
	bool mbDev9Loaded;
	bool mbForceHalfFramerate;
	bool mbFrontEndFlow;
	bool mbGlobalTextureDictionaryLoaded;
	bool mbInputManagerPrepared;
	bool mbIsCrashMode;
	bool mbIsLapEliminatorMode;
	bool mbIsRoadRageMode;
	bool mbIsTrafficAttackMode;
	bool mbLaunchedDemo;
	bool mbPlay;
	bool mbPowerOffTriggered;
	bool mbProgressionDataLoaded;
	bool mbProgressionPage;
	bool mbQuickWorldPrepare;
	bool mbQuitNow;
	bool mbRequestForceHalfFramerate;
	bool mbRequestRestartGameModeWithNewConfig;
	bool mbRequestSimulationPause;
	bool mbRequestSimulationUnpause;
	bool mbShutterClosed;
	bool mbTrackListLoaded;
	bool mbVehicleListLoaded;
	bool mbWorldPrepared;
	CBoAsyncDataLoader mAsyncDataLoader;
	CBoBurningLapLogic mOfflineSingleBurningLapLogic;
	CBoCarViewerLogic mCarViewerLogic;
	CBoChampionshipChallenge mChampionshipChallenge;
	CBoCompCrashModeLogic mOfflineCompCrashModeLogic;
	CBoCrashModeLogic mOfflineCrashModeLogic;
	CBoEliminatorLogic mOfflineSingleEliminatorLogic;
	CBoFrontEnd mGameModeFrontEnd;
	CBoGameMode* mpCurrentGameMode;
	CBoGameMode* mpRequestedGameMode;
	CBoInputManager* mInputManager;
	CBoMultiplayerRoadRageLogic  mOfflineMultiplayerRoadRageLogic;
	CBoOnePlayerStage mGameModeOnePlayerRace;
	CBoOnlineCompCrashModeLogic mOnlineCompCrashModeLogic;
	CBoOnlineGolfCrashModeLogic mOnlineGolfCrashModeLogic;
	CBoOnlinePartyCrashModeLogic mOnlinePartyCrashModeLogic;
	CBoOnlineRevengeLogic mOnlineRevengeLogic;
	CBoOnlineRoadRageLogic mOnlineRoadRageModeLogic;
	CBoOnlineSingleRaceLogic mOnlineSingleRaceLogic;
	CBoOnlineStage mGameModeOnlineRace;
	CBoPartyCrashModeLogic mOfflinePartyCrashModeLogic;
	CBoPlayer maPlayers[2];
	CBoPlayerCameraManager maPlayerCamera[2];
	CBoProgressionDataStruct mpProgressionData;
	CBoSecondaryRewardsManager mSecondaryRewardsManager;
	CBoSettings* mSettings;
	CBoSingleChallenge mSingleChallenge;
	CBoSingleRaceLogic mOfflineSingleRaceLogic;
	CBoSingleRevengeLogic mOfflineSingleRevengeLogic;
	CBoSingleRoadRageLogic mOfflineSingleRoadRageLogic;
	CBoTimer* mTimer;
	CBoTourCrashModeLogic mOfflineTourCrashModeLogic;
	CBoTrackList mTrackList;
	CBoTurnBasedCrashParty mTurnBasedCrashPartyChallenge;
	CBoTurnBasedCrashTour mTurnBasedCrashTourChallenge;
	CBoTwoPlayerSplitScreenStage mGameModeTwoPlayerRace;
	CBoVehicleList mVehicleList;
	CGtCommsToolBase mCommsManager;
	CGtFileSystem mpFileSystem;
	CGtFramerateManager mFramerateManager;
	CGtRandom mNonDeterministicRNG;
	CGtRGBA mClearFrameBufferColour;
	CGtTexture mpGlobalTextureDictionary;
	CGtValueDatabase mValueDatabase;
	char macMainVDBBuffer[51200];
	char mpacDemoPath[256];
	CMemoryDeviceBase mMemoryCard; // Originally CMemoryDevicePS2.
	EGameUpdateState meRequestedUpdateState;
	EGameUpdateState meUpdateState;
	EGtFramerateType meDebugFramerateType;
	EGtFramerateType meFramerateType;
	EGtPrepareState  meHardwarePrepareState;
	EGtPrepareState mePrepareState;
	RwInt32 mnGamePausedByPlayer;
	RwInt32 mnRequestPause;
	RwInt32 mnRequestResume;
	RwInt32 mnSimulationUpdateCount;
	RwReal mrCameraTimeStep;
	RwReal mrGamePlayTime;
	RwReal mrMaxGamePlayTime;
	void* mpProgressionDataBuffer;
};

extern CBoGame gGame;

#endif // !#define BOGAME_H