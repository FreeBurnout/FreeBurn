#pragma once

#include <rwcore.h>

#include "BoAsyncDataLoader.h"
#include "BoFrontEnd.h"
#include "BoGameMode.h"
#include "BoInputManager.h"
#include "BoOnlineStage.h"
#include "BoPlayer.h"
#include "BoSettings.h"
#include "BoTimer.h"
#include "Logic/BoCarViewerLogic.h"
#include "Logic/BoCrashModeLogic.h"
#include "Logic/BoMultiplayerRoadRageLogic.h"
#include "Logic/Single/BoSingleRaceLogic.h"
#include "Logic/Single/BoSingleRevengeLogic.h"
#include "Logic/Single/BoSingleRoadRageLogic.h"
#include "Logic/Online/BoOnlineCrashModeLogic.h"
#include "Logic/Online/BoOnlineRevengeLogic.h"
#include "Logic/Online/BoOnlineSingleRaceLogic.h"
#include "Challenge/BoTurnBasedCrashChallenge.h"
#include "../Camera/BoPlayerCameraManager.h"
#include "../../../SharedClasses/BoDataLists.h"
#include "../../../../GameShared/Common/Graphical/GtColour.h"
#include "../../../../GameShared/Common/Numeric/GtRandom.h"
#include "../../../../GameShared/Common/System/GtFramerateManager.h"
#include "../../../../GameShared/Common/System/GtUnicodeBuffer.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"
#include "../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"
#include "../../../../GameShared/Common/Containers/GtArray.h"

extern CBoGame gGame;
extern CBoMemoryManager gMemoryManager;

enum class EBoTrackLocale {
	Invalid = -1,
	Detroit = 0,
	Tokyo = 1,
	Rome = 2,
	LosAngeles = 3,
	Montana = 4,
	Florida = 5,
	Switzerland = 6,
	HongKong = 7,
	Count = 8,
	None = 8
}; 

enum class EGtGameUpdateState {
	Constructed = 0,
	Prepared = 1,
	Released = 2,
	Destructed = 3,
	SimulationPrepare = 4,
	SimulationUpdate = 5,
	ChangeGameMode = 6,
	RestartGameMode = 7,
	RestartGameModeNewLevelInit = 8,
	RestartGameModeNewLevelRestarting = 9,
	RestartGameModeWithNewConfigInit = 10,
	RestartGameModeWithNewConfigRestarting = 11,
	StartReplay = 12
};

class CBoSecondaryRewardsManager {
public:
	void Construct();
};

class CBoGame {
public:
	char mpacDemoPath[256];
	CBoVehicleList mVehicleList;
	CBoTrackList mTrackList;
	CGtRandom mNonDeterministicRNG;
	CGtFramerateManager mFramerateManager;
	CBoInputManager mInputManager;
	bool mbQuitNow;
	bool mbShutterClosed;
	bool mbPlay;
	bool mbDev9Loaded;
	bool mbPowerOffTriggered;
	bool mbRequestSimulationPause;
	bool mbRequestSimulationUnpause;
	bool mbGlobalTextureDictionaryLoaded;
	void * mpGlobalTextureDictionary;
	bool mbVehicleListLoaded;
	bool mbTrackListLoaded;
	bool mbRequestRestartGameModeWithNewConfig;
	bool mbProgressionPage;
	bool mbQuickWorldPrepare;
	EGtFramerateType meFramerateType;
	EGtFramerateType meDebugFramerateType;
	bool mbClearFrameBufferDuringWorldPrepare;
	RwInt32 mnGamePausedByPlayer;
	RwInt32 mnRequestPause;
	RwInt32 mnRequestResume;
	RwInt32 mnSimulationUpdateCount;
	bool mbWorldPrepared;
	bool mbForceHalfFramerate;
	bool mbInputManagerPrepared;
	bool mbIsRoadRageMode;
	RwReal mrCameraTimeStep;
	bool mbIsTrafficAttackMode;
	CGtRGBA mClearFrameBufferColour;
	bool mbRequestForceHalfFramerate;
	CBoGameMode * mpCurrentGameMode;
	CBoGameMode * mpRequestedGameMode;
	CBoFrontEnd mGameModeFrontEnd;
	CBoSettings mSettings;
	CBoOnePlayerStage mGameModeOnePlayerRace;
	CBoTwoPlayerSplitScreenStage mGameModeTwoPlayerRace;
	CBoOnlineStage mGameModeOnlineRace;
	CBoSingleRaceLogic mOfflineSingleRaceLogic;
	CBoCrashModeLogic mOfflineCrashModeLogic;
	CBoSingleRevengeLogic mOfflineSingleRevengeLogic;
	CBoBurningLapLogic mOfflineSingleBurningLapLogic;
	CBoEliminatorLogic mOfflineSingleEliminatorLogic;
	CBoSingleRoadRageLogic mOfflineSingleRoadRageLogic;
	CBoMultiplayerRoadRageLogic mOfflineMultiplayerRoadRageLogic;
	CBoOnlineSingleRaceLogic mOnlineSingleRaceLogic;
	CBoOnlineCompCrashModeLogic mOnlineGolfCrashModeLogic;
	CBoOnlineCompCrashModeLogic mOnlineCompCrashModeLogic;
	CBoOnlinePartyCrashModeLogic mOnlinePartyCrashModeLogic;
	CBoOnlineRevengeLogic mOnlineRevengeLogic;
	CBoCarViewerLogic mCarViewerLogic;
	CBoTurnBasedCrashParty mTurnBasedCrashPartyChallenge;
	CBoTurnBasedCrashTour mTurnBasedCrashTourChallenge;
	CBoSecondaryRewardsManager mSecondaryRewardsManager;
	EGtPrepareState mePrepareState;
	EGtGameUpdateState meUpdateState;
	EGtGameUpdateState meRequestedUpdateState;
	CBoTimer mTimer;
	CBoPlayer maPlayers[2];
	CBoPlayerCameraManager maPlayerCamera[2];
	EGtPrepareState meHardwarePrepareState;
	GtComms::CGtCommsToolBase mCommsManager;
	CBoAsyncDataLoader mAsyncDataLoader;

	void Construct();
	void ConstructHardware();
	void PreparePowerOff();
	bool PrepareWorld();
	void CheckPowerOff();
	void Destruct();
	void Release();
	void Render();
	bool Prepare();
	bool IsSimulationPaused();
	bool ResetGameMode();
	void Update();
	void DisplayInsertControllerMessage();
	RwChar * GetDemoPath();
	void SetDemoPath(RwChar *);
	void UpdatePreSimulation();
	void UpdatePostSimulation();
	bool RestartGameModeUpdateCode();
	RwInt32 GetNumSimulationUpdatesRequired();
	void UpdateSimulation();
	void SleepToAllowWorkerThreadsToRun();
};

class CBoMemoryManager {
public:
	void Construct();
	void Update();
};

class CBoStrings {
public:
	CGtStringArrayUnicode * mpStringsArray;
};