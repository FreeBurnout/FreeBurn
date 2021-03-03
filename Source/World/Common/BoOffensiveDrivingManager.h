#include <rwcore.h>

#include "BoLapManager.h"

enum EScoreCategoryType {
	eCategoryAir = 0,
	eCategoryOncoming = 1,
	eCategoryDrifting = 2,
	eCategoryRubbing = 3,
	eCategoryTailgating = 4,
	eCategoryGrinding = 5,
	eCategoryNearMiss = 6,
	eCategoryCheckedTraffic = 7,
	eCategoryBoost = 8,
	eCategoryCount = 9
};
enum EBoScoreFinishState {
	eScoreFinishStateNotFinished = 0,
	eScoreFinishStateCrossedLine = 1,
	eScoreFinishStateTimedOut = 2,
	eScoreFinishStateRetired = 3,
	eScoreFinishStateDestroyed = 4,
	eScoreFinishStateShutdown = 5,
	eScoreFinishStateVictorious = 6,
	eScoreFinishStateCrashed = 7,
	eScoreFinishStateDisconnected = 8,
	eScoreFinishStateEliminated = 9,
	eScoreFinishStateLoser = 10,
	eScoreFinishStateAIDidNotFinish = 11,
};
enum EBoScoreSlamType {
	eScoreSlamNormal = 0,
	eScoreSlamNoseToRear = 1,
	eScoreSlamRearToSide = 2,
	eScoreSlamCount = 3
};

class CBoScoreCategory {
	CBoLapManager* mpLapManager;
	RwReal mrValue;
	RwReal mrPrevTime;
	RwReal mrPrevValue;
	RwReal* mprCategoryArray;
	bool mbActive;
	RwInt8 mn8Category;
	RwInt8 mn8PrevCategory;
	RwInt8 mn8MaxCategory;
	EScoreCategoryType meType;

	void Prepare(EScoreCategoryType, const float*, int, const CBoLapManager*);
	void Stopped();
	void UpdateValue(float);

};

class CBoOffensiveDrivingManager {
public:
	RwReal krSlamChainMaxTimeBetweenSlams = 15.0f;

	RwReal gmrAirMinimumDistanceValue            = 5.0f;
	RwReal gmrAirDistanceBurnValue               = 2.0f;
	RwReal gmrOncomingMinimumSpeed               = 30.0f;
	RwReal gmrOncomingMinimumDistanceValue       = 10.0f;
	RwReal gmrOncomingDistanceBurnValue          = 0.3f;
	RwReal gmrDriftMinimumSpeed                  = 30.0f;
	RwReal gmrDriftMinimumDistanceValue          = 10.0f;
	RwReal gmrDriftDistanceBurnValue             = 1.0f;
	RwReal gmrMaxNearMissDistance                = 2.0f;
	RwReal gmrNearMissMinimumSpeed               = 30.0f;
	RwReal gmrNearMissMinimumChainSpeed          = 30.0f;
	RwReal gmrNearMissBurnValue                  = 60.0f;
	RwReal gmrNearMissChainTime                  = 5.0f;
	RwReal gmrCrashClassCheckingTrafficBurnValue = 30.0f;
	RwReal gmrRaceClassCheckingTrafficBurnLoss   = 70.0f;
	RwReal gmrCheckingTrafficTime                = 2.0f;
	RwReal gmrCrashEscapeRadius                  = 8.0f;
	RwReal gmrCrashNearMissChainTime             = 1.0f;
	RwReal gmrCrashEscapeMinClearTime            = 3.0f;
	RwReal gmrCrashEscapeMinimumSpeed            = 70.0f;
	RwReal gmrCrashEscapeBurnValue               = 120.0f;
	RwReal gmrBurnRatioLostInCrash               = 0.5f;
	RwReal gmrMaxSlamBurnValue                   = 360.0f;
	RwReal gmrRubbingMinTime                     = 0.3f;
	RwReal gmrRubbingBurnValue                   = 15.0f;
	RwReal gmrBoostStartBurnValue                = 50.0f;
	RwReal gmrTakedownBurnValue                  = 720.0f;
	RwReal gmrTakedownWaitTime                   = 1.0f;
	RwReal gmrTakedownCrashTime                  = 1.0f;
	RwReal gmrTakedownCrashTimeOnline            = 3.0f;
	RwReal gmrTakedownCrashTimeNoSlam            = 0.5f;
	RwReal gmrTakedownCollideTimeNoSlam          = 0.5f;
	RwReal gmrTakedownCollideTimeNoSlamOnline    = 1.0f;
	RwReal gmrTakedownTimeAfterAfterSlam         = 0.5f;
	RwReal gmrDoubleTakedownTime                 = 1.0f;
	RwReal gmrSpreeTakedownTime                  = 30.0f;
	RwReal gmrDoubleRevengeTakedownTime          = 60.0f;
	RwReal gmrPropHitChainTime                   = 2.0f;
	RwReal gmrPropHitBurnValue                   = 3.0f;
	RwReal gmrTradingPaintBurnValue              = 3.0f;
	RwInt32 gmnPropHitBP                         = 10;
	RwInt32 gmnRubbingBP                         = 5;
	RwInt32 gmnTradingPaintBP                    = 25;
	RwInt32 gmnBoostStartBP                      = 50;
	RwInt32 gmnCrashEscapeBP                     = 100;

	int gmanSlamBP[3] = {
		20, 20, 50
	};

	int gmanSuperSlamBP[3] = {
		30, 30, 50
	};

	RwInt32 gmnTakedownBP             = 1000;
	RwInt32 gmnRevengeBP              = 350;
	RwInt32 gmnPsycheOutBP            = 150;
	RwInt32 gmnAftertouchTakedownBP   = 250;
	RwInt32 gmnAerialTakedownBP       = 400;
	RwInt32 gmnTBoneTakedownBP        = 150;
	RwInt32 gmnCrashbreakerTakedownBP = 250;
	RwInt32 gmnNearMissBP             = 20;
	RwInt32 gmnYouWereLuckyBP         = 15;
	RwInt32 gmnDeniedBP               = 10;
	RwInt32 gmnCheckedTrafficBP       = 20;

	int gmanAirBP[4] = {
		100, 250, 500, 1000
	};

	int gmanOncomingBP[4] = {
		100, 250, 500, 1000
	};

	int gmanDriftBP[4] = {
		100, 250, 500, 1000
	};

	int gmanTailgateBP[3] = {
		5, 10, 15
	};

	int gmanRubbingBP[3] = {
		5, 10, 15
	};

	int gmanGrindingBP[3] = {
		5, 10, 15
	};

	int gmanNearMissBP[4] = {
		5, 10, 15, 25
	};

	int gmanDoubleTakedownBP[4] = {
		300, 500, 750, 100
	};

	int gmanSpreeTakedownBP[4] = {
		300, 500, 750, 1000
	};

	int gmanDoubleRevengeTakedownBP[3] = {
		300, 500, 0
	};

	int gmanRoadRageTakedownBP[8] = {
		100, 250, 500, 1000, 1250, 1500, 1750, 2000
	};

	float gmarMinAir[4] = {
		15.0f, 30.0f, 60.0f, 90.0f
	};

	float gmarMinOncoming[4] = {
		50.0f, 100.0f, 200.0f, 300.0f
	};

	float gmarMinDrift[4] = {
		45.0f, 90.0f, 180.0f, 270.0f
	};

	float gmarMinTailgate[3] = {
		1.0f, 5.0, 10.0f
	};

	float gmarMinRubbing[3] = {
		0.1f, 4.0f, 8.0f
	};

	float gmarMinGrinding[3] = {
		0.1f, 4.0f, 8.0f
	};

	float gmarMinNearMiss[4] = {
		999.0f, 2.0f, 5.0f, 9.0f
	};

	float gmarMinCheckedTraffic[4] = {
		1.0f, 2.0f, 3.0f, 4.0f
	};

	RwReal gmrTailgateMaxDistance       = 15.0f;
	RwReal gmrTailgatePsycheOutDistance = 7.5f;
	RwReal gmrTailgateConeAngle         = 15.0f;
	RwReal gmrTailgateExtraBurnValue    = 15.0f;
	RwReal gmrTailgateInitialTime       = 0.5f;
	RwReal gmrGrindingExtraBurnValue    = 15.0f;
};