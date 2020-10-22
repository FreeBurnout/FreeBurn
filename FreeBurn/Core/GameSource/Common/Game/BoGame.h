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
#include "Logic/Online/BoOnlineSingleRaceLogic.h"
#include "Logic/Online/BoOnlineRevengeLogic.h"
#include "Challenge/BoTurnBasedCrashChallenge.h"
#include "../Camera/BoPlayerCameraManager.h"
#include "../../../SharedClasses/BoDataLists.h"
#include "../../../../GameShared/Common/Containers/GtArray.h"
#include "../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"
#include "../../../../GameShared/Common/Graphical/GtColour.h"
#include "../../../../GameShared/Common/Numeric/GtRandom.h"
#include "../../../../GameShared/Common/System/GtFramerateManager.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"
#include "../../../SharedClasses/BoProgressionDataStruct.h"

struct CBoPCCommonMemoryBuffers {
public:
	char mPersistentLobbyBuffer[81920];
	char mGlobalTexdicDataBuffer[945152];
	char mMainStringsBuffer[204800];
	char mProgressionDataBuffer[75776];
	char mSoundWaveObjectBuffer[71680];
	char mSoundRwaBuffer[76800];
	char mCameraBuffer[65536];
	char mDMABuffer[1310720];
	char mSphereMapBuffer[22528];
	char mGinsuDistillerBuffer[1024];
	char mFlashMoviesLoadingScreensBuffer[184320];
	char mBigFontBuffer[40960];
	char mSmallFontBuffer[16384];
	char mDigitalFontBuffer[6144];
}; 

struct CBoPCGameMemoryBuffers2P {

};

struct CBoPCMemoryBuffers {
public:
	CBoPCCommonMemoryBuffers mCommonBlock;
	CBoPCGameMemoryBuffers2P mSwapBlock;
};

extern CBoPCMemoryBuffers _gMemoryBlock;
extern CBoPCMemoryBuffers * _gpWholeMemoryBlock;

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

class CBoManagedMemoryBlock {
public:
	RwInt32 mnReferenceCount;
	RwInt32 mnMemoryLayout;
	RwInt32 mnSize;
	void * mpMemoryBlock;

	void Construct(void * lpMemoryBlock, RwInt32 lnMemoryLayout, RwInt32 lnSize);
};

class CBoGame {
public:
	char mpacDemoPath[256];
	CBoVehicleList mVehicleList;
	CBoTrackList mTrackList;
	CGtRandom mNonDeterministicRNG;
	CGtFramerateManager mFramerateManager;
	CBoInputManager mInputManager;
	CBoProgressionDataStruct * mpProgressionData;
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

void __renderStuff(CBoGame * game);

enum class EBoMemoryLayout {
	Common = -1,
	Frontend = 0,
	Game1Player = 1,
	Game2Player = 2,
	Game2PlayerCrash = 3
};

class CBoPCFrontendMemoryBuffers {
public:
	static char maRaceCarBuffer[471040];
	static char mFESunCoronaBuffer[34816];
	static char mFEFlashTextureDicBuffer[2];
	static char mFEStaticWorldBuffer[917504];
	static char mFEFlashMoviesCafeCommonBuffer[1388544];
	static char mFEFlashMoviesBuffer[8464384];
	static char mFEAptDataBuffer[1994752];
	static char mMPEGBuffer[5156864];
	static char mStageHeadersBuffer[450560];
	static char mFrontEndLobbyBuffer[512000];
	static char mDNASElfOrRaceCarBuffer[1843200];
};

class CBoMemoryManager {
public:
	CBoManagedMemoryBlock mGlobalTexdicDataBuffer;
	CBoManagedMemoryBlock mMainStringsBuffer;
	CBoManagedMemoryBlock mProgressionDataBuffer;
	CBoManagedMemoryBlock mSoundWaveObjectBuffer;
	CBoManagedMemoryBlock mSoundRwaBuffer;
	CBoManagedMemoryBlock mCameraBuffer;
	CBoManagedMemoryBlock maCarIconsBuffer[6];
	CBoManagedMemoryBlock mLoadingBackgroundBuffer;
	CBoManagedMemoryBlock mGinsuDistillerBuffer;
	CBoManagedMemoryBlock mBigFontBuffer;
	CBoManagedMemoryBlock mSmallFontBuffer;
	CBoManagedMemoryBlock mDigitalFontBuffer;
	CBoManagedMemoryBlock mFlashMoviesLoadingScreensBuffer;
	CBoManagedMemoryBlock mPersistentLobbyBuffer;
	CBoManagedMemoryBlock ma1PRaceCarBuffer[6];
	CBoManagedMemoryBlock m1PSunCoronaBuffer;
	CBoManagedMemoryBlock m1PStaticTrackBuffer;
	CBoManagedMemoryBlock m1PStreamedTrackHighBuffer[10];
	CBoManagedMemoryBlock m1PStreamedTrackLODColBuffer[18];
	CBoManagedMemoryBlock m1PGameDataBuffer;
	CBoManagedMemoryBlock m1PPropManagerBuffer;
	CBoManagedMemoryBlock ma1PTrafficCarBuffer[12];
	CBoManagedMemoryBlock m1PInGameFlashMoviesBuffer;
	CBoManagedMemoryBlock m1PInGameAptDataBuffer;
	CBoManagedMemoryBlock ma2PRaceCarBuffer[2];
	CBoManagedMemoryBlock m2PSunCoronaBuffer;
	CBoManagedMemoryBlock m2PStaticTrackBuffer;
	CBoManagedMemoryBlock m2PStreamedTrackHighBuffer[19];
	CBoManagedMemoryBlock m2PStreamedTrackLODColBuffer[35];
	CBoManagedMemoryBlock m2PGameDataBuffer;
	CBoManagedMemoryBlock m2PPropManagerBuffer;
	CBoManagedMemoryBlock ma2PTrafficCarBuffer[12];
	CBoManagedMemoryBlock m2PInGameFlashMoviesBuffer;
	CBoManagedMemoryBlock m2PInGameAptDataBuffer;
	CBoManagedMemoryBlock ma2PCrashRaceCarBuffer[3];
	CBoManagedMemoryBlock m2PCrashSunCoronaBuffer;
	CBoManagedMemoryBlock m2PCrashStaticTrackBuffer;
	CBoManagedMemoryBlock m2PCrashStreamedTrackHighBuffer[19];
	CBoManagedMemoryBlock m2PCrashStreamedTrackLODColBuffer[35];
	CBoManagedMemoryBlock m2PCrashGameDataBuffer;
	CBoManagedMemoryBlock m2PCrashPropManagerBuffer;
	CBoManagedMemoryBlock ma2PCrashTrafficCarBuffer[12];
	CBoManagedMemoryBlock m2PCrashInGameFlashMoviesBuffer;
	CBoManagedMemoryBlock m2PCrashInGameAptDataBuffer;
	CBoManagedMemoryBlock maFERaceCarBuffer[3];
	CBoManagedMemoryBlock mFESunCoronaBuffer;
	CBoManagedMemoryBlock mFEEnvironmentDataBuffer;
	CBoManagedMemoryBlock mFEStaticWorldBuffer;
	CBoManagedMemoryBlock mFEFlashMoviesCafeCommonBuffer;
	CBoManagedMemoryBlock mFEFlashMoviesBuffer;
	CBoManagedMemoryBlock mFEFlashTextureDicBuffer;
	CBoManagedMemoryBlock mFESaveGameBuffer;
	CBoManagedMemoryBlock mFEAptDataBuffer;
	CBoManagedMemoryBlock mMPEGBuffer;
	CBoManagedMemoryBlock mStageHeadersBuffer;
	EBoMemoryLayout meCurrentMemoryLayout;
	RwInt32 mnMemoryLayoutCount;

	void Update();
	void Construct(void * lpMemoryBlock, RwInt32 lnMemoryLayout, RwInt32 lnSize);
};

class CBoMemoryManagerPC : public CBoMemoryManager {
public:
	CBoManagedMemoryBlock mSphereMapBuffer;
	CBoManagedMemoryBlock mDNASElfOrRaceCarBuffer;
	CBoManagedMemoryBlock mFrontEndLobbyBuffer;
	CBoManagedMemoryBlock mDMABuffer;

	void Construct();
	void Destruct();
};

extern CBoGame gGame;
extern CBoMemoryManagerPC gMemoryManager;
