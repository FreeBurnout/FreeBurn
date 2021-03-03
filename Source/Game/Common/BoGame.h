#ifndef BOGAME_H
#define BOGAME_H

#include <rwcore.h>

#include "BoAsyncDataLoader.h"
#include "BoFrontEnd.h"
#include "BoGameMode.h"
#include "BoInputManager.h"
#include "BoOnlineStage.h"
#include "BoPlayer.h"
#include "BoProgressionManager.h"
#include "BoSettings.h"
#include "BoTimer.h"
#include "Challenge/BoChallenge.h"
#include "Challenge/BoTurnBasedCrashChallenge.h"
#include "Logic/BoCarViewerLogic.h"
#include "Logic/BoCrashModeLogic.h"
#include "Logic/BoMultiplayerRoadRageLogic.h"
#include "Logic/BoStageLogic.h"
#include "Logic/Online/BoOnlineCrashModeLogic.h"
#include "Logic/Online/BoOnlineRevengeLogic.h"
#include "Logic/Online/BoOnlineRoadRageLogic.h"
#include "Logic/Online/BoOnlineSingleRaceLogic.h"
#include "Logic/Single/BoSingleRaceLogic.h"
#include "Logic/Single/BoSingleRevengeLogic.h"
#include "Logic/Single/BoSingleRoadRageLogic.h"
#include "Progression/BoProgressionDataStruct.h"
#include "../../../Shared/Development/CommsTool/GtCommsDatabase.h"
#include "../../../Shared/Graphical/Common/GtColour.h"
#include "../../../Shared/Graphical/Common/GtTextureDictionary.h"
#include "../../../Shared/Numeric/GtRandom.h"
#include "../../../Shared/System/Common/GtFramerateManager.h"
#include "../../../Shared/System/Common/GtMemoryCardManager.h"
#include "../../World/Common/BoDataLists.h"

using namespace GtComms;
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

enum EBoMemoryBlock {
	eMB_Cameras = 0,
	eMB_RaceCar = 1,
	eMB_TrafficCar = 2,
	eMB_SunCorona = 3,
	eMB_EnvironmentData = 4,
	eMB_StaticTrack = 5,
	eMB_StreamedTrackHighDetail = 6,
	eMB_StreamedTrackLodCollision = 7,
	eMB_GameData = 8,
	eMB_MainStrings = 9,
	eMB_ProgressionData = 10,
	eMB_PropManager = 11,
	eMB_GlobalTextureDictionary = 12,
	eMB_SoundWaveObject = 13,
	eMB_SoundRwaBlock = 14,
	eMB_CommonFlashMoviesLoadingScreens = 15,
	eMB_FrontEndFlashMoviesCafeCommon = 16,
	eMB_FrontEndFlashMovies = 17,
	eMB_FrontEndFlashTextureDic = 18,
	eMB_FrontEndMPEG = 19,
	eMB_FrontEndStageHeaders = 20,
	eMB_FrontSaveGameData = 21,
	eMB_FrontEndAptData = 22,
	eMB_InGameAptData = 23,
	eMB_InGameFlashMovies = 24,
	eMB_CarIcons = 25,
	eMB_LoadingBackground = 26,
	eMB_GinsuDistillerBuffer = 27,
	eMB_BigFont = 28,
	eMB_SmallFont = 29,
	eMB_DigitalFont = 30,
	eMB_PeristentLobbyBuffer = 31,
	eMB_FrontEndLobby = 32,
	eMB_FrontEndDNASElfOrRaceCar = 33,
	eMB_RwDmaFifo = 34,
	eMB_SphereMapBuffer = 35
};

enum EBoMemoryLayout {
	eBoMemoryLayout_Common = -1,
	eBoMemoryLayout_Frontend = 0,
	eBoMemoryLayout_Game1Player = 1,
	eBoMemoryLayout_Game2Player = 2,
	eBoMemoryLayout_Game2PlayerCrash = 3
};

static float gFrameTime = 1/24.f; // 24Hz, "safe" refresh rate.

class CBoManagedMemoryBlock {
public:
	RwInt32 mnReferenceCount;
	RwInt32 mnMemoryLayout;
	RwInt32 mnSize;
	void* mpMemoryBlock;
	
	void Construct(void* lpMemoryBlock, RwInt32 lnMemoryLayout, RwInt32 lnSize);
	void Destruct();
	void* GetMemoryBlock(RwInt32 lnCurrentMemoryLayout);
	void ReleaseMemoryBlock(RwInt32);
	void Update(RwInt32);
	void* QueryMemoryBlock(RwInt32) const;
	RwInt32 GetBlockSize() const;
	bool IsAcquired();
};

class CBoMemoryManager {

};

class CBoMemoryManagerPC : CBoMemoryManager {
public:
	void Construct();
};

extern CBoMemoryManagerPC gMemoryManager;

class CBoGame {
public:
	/* Not allowed - aw!
	bool mbBootNFLStreet2Demo;
	void BootNFLStreet2Demo();
	void SetBootNFLStreet2DemoNow();
	bool WillBootNFLStreet2DemoNow();
	*/
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
	void GetSendRecvFigures(
		RwInt32* lpnBytesSentToWireLastSecond, 
		RwInt32* lpnBytesRecvdFromWireLastSecond,
		RwInt32* lpnBytesSubmittedForSendLastSecond, 
		RwInt32* lpnBytesPassedToAppByRecvLastSecond, 
		RwInt32** lppanAvgBytesSubmittedForSendMsgTypeThisSecond, 
		RwInt32** lppanAvgBytesPassedToAppByRecvMsgTypeThisSecond
	);
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
	CBoInputManager mInputManager;
	CBoMultiplayerRoadRageLogic mOfflineMultiplayerRoadRageLogic;
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
	CBoSettings mSettings;
	CBoSingleChallenge mSingleChallenge;
	CBoSingleRaceLogic mOfflineSingleRaceLogic;
	CBoSingleRevengeLogic mOfflineSingleRevengeLogic;
	CBoSingleRoadRageLogic mOfflineSingleRoadRageLogic;
	CBoTimer mTimer;
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
	CGtTextureDictionary* mpGlobalTextureDictionary;
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