#include <rwcore.h>

#include "../../GameShared/Common/Core/GtID.h"
#include "../GameSource/Common/Menu/States/BoMenuFlowManager.h"

enum class EChallengeType {
	None = 0,
	Race = 1,
	Crash = 2,
	RoadRage = 3,
	TrafficAttack = 4,
	Eliminator = 5,
	BurningLap = 6,
	GrandPrix = 7,
	CrashTour = 8,
	CrashbreakerRace = 9,
	PreviewLap = 10,
	Count = 11
};

enum class ENormalOfflineGameModes {
	SingleRace = 0,
	LapEliminator = 1,
	BattleRace = 2,
	RoadRage = 3,
	Revenge = 4,
	TwoPlayerGameModeNumber = 5,
	BurningLap = 5,
	Survival = 6,
	Crash = 7,
	Number = 8
};

enum class EBoVehicleUpgradeType {
	Locked = 0,
	SpecA = 1,
	SpecB = 2,
	SpecC = 3,
	Max = 4
};

enum class EBoPlayerVehicleClass{
	None = 0,
	Race = 1,
	Muscle = 2,
	Crash = 3,
	Super = 4,
	Count = 5
};

struct CBoChallengeEntryRequirementDataStruct {
public:
	GtID mVehicleID;
	EBoVehicleUpgradeType meVehicleUpgradeType;
	EBoPlayerVehicleClass meVehicleClass;
	EBoTrackLocale meVehicleLocale;
	RwUInt8 mu8FirstPlaceChallengesCompleted; 
	RwUInt8 mu8SecondPlaceChallengesCompleted;
	RwUInt8 mu8ThirdPlaceChallengesCompleted; 
	RwUInt8 mu8ChallengesCompletedAreLocal;
};

struct CBoStageDataStruct {
	GtID mTrackID; 
	GtID mStageID; 
	ENormalOfflineGameModes meType; 
	RwUInt8 mx8DirectionFlag; 
	unsigned char mau8Pad[3];
};

struct CBoRevengeThresholdDataStruct {
public:
	RwInt32 mnID;
	RwInt32 mnRankID; 
	RwInt32 mnRevengePointsNeeded;
	GtID mNameID;
};

struct CBoRevengeRankDataStruct {
public:
	CBoRevengeThresholdDataStruct * mpRevengeThresholds;
	RwInt32 mnNumRevengeThresholds;
	RwInt32 mnID;
	RwInt32 mnRevengePointsNeeded;
	GtID mNameID;
};

struct CBoChallengeDataStruct {
public:
	CBoChallengeEntryRequirementDataStruct mEntryRequirement;
	GtID mUniqueChallengeID; 
	EChallengeType meType;
	RwInt32 mnRevengePointsThresholdID; 
	RwUInt32 mnRevengePointsRankID; 
	GtID mRewardVehicleID; 
	CBoStageDataStruct mpStages;
	RwUInt32 muNumStages;
	RwInt32 mxFlags;
	RwInt8 mn8AllowCrashbreaker;
};

struct CBoVehicleUpgradeTableDataStruct {
	unsigned char maau8ChallengesCompleted[3][5];
	unsigned char maau8ChallengesCompletedAreLocal[3][5];
};

struct CBoChampionshipDataStruct {
public:
	CBoChallengeDataStruct * mpChallenges;
	RwUInt32 muNumChallenges;
	CBoVehicleUpgradeTableDataStruct mVehicleUpgradeTable;
};

struct CBoRevengeMeterDataStruct {
public:
	CBoRevengeRankDataStruct * mpRevengeRanks;
	RwInt32 mnNumRevengeRanks;
};

struct CBoProgressionDataStruct {
public:
	RwUInt32 mu32VersionNumber;
	CBoChampionshipDataStruct * mpChampionships;
	RwUInt32 muNumChampionships;
	CBoRevengeMeterDataStruct mRevengeMeter;
	RwUInt32 muProgresionDataSize;
};