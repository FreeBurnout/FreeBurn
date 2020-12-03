#ifndef BOGAMEDATA_H
#define BOGAMEDATA_H
#include <rwcore.h>

#include "BoCrashPickup.h"
#include "BoCrashRamp.h"
#include "BoPlayerCar.h"
#include "BoStartFinishLine.h"
#include "AI/BoAIDriver.h"
#include "AI/BoAILaneStruct.h"
#include "Track/BoStaticTrackData.h"
#include "Traffic/BoTrafficSystem.h"
#include "../../Camera/BoPlayerCameraManager.h"
#include "../../Game/Common/Progression/BoSignatureTakedowns.h"
#include "../../../Shared/Core/GtID.h"
#include "../../../Shared/System/Common/GtFSM.h"
#include "../../../Shared/Graphical/PC/GtTexturePC.h"
#include "../../../Shared/Numeric/Math/PC/GtV3dPC.h"

using namespace GtMathPC;

struct CBoGameDataStruct {
	RwUInt32 muVersionNumber;
	GtID maStageDataIDs[200];
	int manStageDataOffsets[200];
	RwInt32 mnNumStages;
	RwInt32 mnSingleRaceDataOffset;
	RwInt32 mnTrackDataOffset;
	RwInt32 mnTrafficDataOffset;
	RwInt32 mnTrafficLanesDataOffset;
	RwInt32 mnAILanesDataOffset;
	RwInt32 mnCameraDataOffset;
	RwInt32 mnDetourDataOffset;

	void FixUp();
};
struct CBoGameStageDataStruct {
	CBoAIDriverStruct maDrivers[6];
	GtID mTrackID;
	GtID mStageID;
	RwReal mrGoldThreshold;
	RwReal mrSilverThreshold;
	RwReal mrBronzeThreshold;
	RwReal mrTimeLimit;
	RwInt32 mnNumDrivers;
	RwInt32 mnNumLaps;
	RwInt32 mnTrackDataSetSize;
	RwInt32 mnTrackDataSetOffset;
	RwInt32 mnTrafficDataSetSize;
	RwInt32 mnTrafficDataSetOffset;
	RwInt32 mnTrafficLanesSetSize;
	RwInt32 mnTrafficLanesSetOffset;
	RwInt32 mnAILanesSetSize;
	RwInt32 mnAILanesSetOffset;
	RwInt32 mnCameraDataSetSize;
	RwInt32 mnCameraDataSetOffset;
	RwUInt8 mu8HardStart;
	RwInt8 mn8CrashGolfPar;
	unsigned char mau8Pad[2];
	RwInt32 mnCrashGolfTarget;

	void FixUp();
};
struct CBoSingleRaceDataStruct {
	CBoAIDriverStruct maaDrivers[9][6];
	int manNumDrivers[9];

	void FixUp();
};

enum EGameDataAISet {
	eGameDataAISetGeneric = 0,
	eGameDataAISetCompact = 1,
	eGameDataAISetSport = 2,
	eGameDataAISetCoupe = 3,
	eGameDataAISetMuscle = 4,
	eGameDataAISetSuper = 5,
	eGameDataAISetHeavy = 6,
	eGameDataAISetSuperHeavy = 7,
	eGameDataAISetSpecialHeavy = 8,
	eGameDataAISetNumber = 9
};
enum EGameDataDifficulty {
	eBoTrafficDifficultyEasy = 0,
	eBoTrafficDifficultyMedium = 1,
	eBoTrafficDifficultyHard = 2,
	eBoTrafficDifficultyCount = 3
};

class CBoGameData {
public:
	void    Construct();
	bool    Prepare();
	bool    IsFileStreamReady();
	RwInt32 GetNumStartLines();
	RwInt32 GetNumFinishLines();
	RwInt32 GetNumSplitTimeCheckpoints();
	void    Update();
	void    Release();
	void    Destruct();
	void    SetGameDataFileName(char* lpacGameDataFileName);
	void    SetStageID(GtID lID);
	void    Draw(EPlayerCarIndex param);
	RwInt32 GetNumLaps();
	void    GetGameDataThreshold(float* lprBronze, float* lprSilver, float* lprGold);
	void    GetGameDataThreshold(int* lpnBronze, int* lpnSilver, int* lpnGold);
	void    GetWindGameData(float* lprDirection, float* lprSpeed, signed char ln8Difficulty);
	void    GetCrashThreshold(signed char* lpn8Par, int* lpnTarget);
	RwInt32 GetIntroSequence(signed char param) const;
	RwReal  GetTimeLimit() const;

	EBoSignatureTakedownType GetSignatureTakedownType(CGtV3d lTakedownPosition);

private:
	CBoCrashPickup            maCrashPickups[20];
	CBoCrashRamp              maCrashRamps[5];
	CBoStartPoint             maStartPoints[6];
	CBoStartFinishLine        maStartLine[4];
	CBoStartFinishLine        maFinishLine[4];
	CBoSplitTimeCheckpoint    maSplitTimeCheckpoints[12];
	ECrashModeRampType        maeActiveRamps[2];
	CGtTexture                mapPickupTextures[10];
	CGtTexture*               mpRampTexture;
	bool                      mbIsSingleRace;
	CBoCameraMovieManager     mMovieManager;
	char                      macGameDataFilePath[256];
	GtID                      mStageID;
	CBoGameDataStruct*        mpGameDataStruct;
	CBoGameStageDataStruct*   mpStageDataStruct;
	CBoSingleRaceDataStruct*  mpSingleDataStruct;
	CBoTrackDataStruct*       mpTrackDataStruct;
	CBoTrafficLanesStruct*    mpTrafficLanesData;
	CBoAILanesDataStruct*     mpAILanesData;
	intptr_t                  mpInStream;
	RwInt32                   mnGameDataMemoryUsed;
	EGameDataAISet            meSingleRaceAIData;
	EGameDataDifficulty       meSingleRaceTrafficDifficulty;
	EGtPrepareState           mePrepareState;
	bool                      mbGameDataLoaded;
	bool                      mbFilePathSetup;
	bool                      mbStageDataIDSetup;
	RwUInt8                   mu8NumActivePickups;

	RwUInt64                   GetNumPickups();
	RwUInt64                   GetDifficultyIndex();
	RwInt32                    GetNumSignatureTakedownZones();
	CBoSignatureTakedownStruct GetSignatureTakedownData(int);
	CBoGameStageDataStruct     GetGameStageData();

};
#endif // !#define BOGAMEDATA_H