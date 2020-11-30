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
	RwReal gmrAirMinimumDistanceValue            = 5.0;
	RwReal gmrAirDistanceBurnValue               = 2.0;
	RwReal gmrOncomingMinimumSpeed               = 30.0;
	RwReal gmrOncomingMinimumDistanceValue       = 10.0;
	RwReal gmrOncomingDistanceBurnValue          = 0.3;
	RwReal gmrDriftMinimumSpeed                  = 30.0;
	RwReal gmrDriftMinimumDistanceValue          = 10.0;
	RwReal gmrDriftDistanceBurnValue             = 1.0;
	RwReal gmrMaxNearMissDistance                = 2.0;
	RwReal gmrNearMissMinimumSpeed               = 30.0;
	RwReal gmrNearMissMinimumChainSpeed          = 30.0;
	RwReal gmrNearMissBurnValue                  = 60.0;
	RwReal gmrNearMissChainTime                  = 5.0;
	RwReal gmrCrashClassCheckingTrafficBurnValue = 30.0;
	RwReal gmrRaceClassCheckingTrafficBurnLoss   = 70.0;
	RwReal gmrCheckingTrafficTime                = 2.0;
	RwReal gmrCrashEscapeRadius                  = 8.0;
	RwReal gmrCrashNearMissChainTime             = 1.0;
	RwReal gmrCrashEscapeMinClearTime            = 3.0;
	RwReal gmrCrashEscapeMinimumSpeed            = 70.0;
	RwReal gmrCrashEscapeBurnValue               = 120.0;
	RwReal gmrBurnRatioLostInCrash               = 0.5;
	RwReal gmrMaxSlamBurnValue                   = 360.0;
	RwReal gmrRubbingMinTime                     = 0.3;
	RwReal gmrRubbingBurnValue                   = 15.0;
	RwReal gmrBoostStartBurnValue                = 50.0;
	RwReal gmrTakedownBurnValue                  = 720.0;
	RwReal gmrTakedownWaitTime                   = 1.0;
	RwReal gmrTakedownCrashTime                  = 1.0;
	RwReal gmrTakedownCrashTimeOnline            = 3.0;
	RwReal gmrTakedownCrashTimeNoSlam            = 0.5;
	RwReal gmrTakedownCollideTimeNoSlam          = 0.5;
	RwReal gmrTakedownCollideTimeNoSlamOnline    = 1.0;
	RwReal gmrTakedownTimeAfterAfterSlam         = 0.5;
	RwReal gmrDoubleTakedownTime                 = 1.0;
	RwReal gmrSpreeTakedownTime                  = 30.0;
	RwReal gmrDoubleRevengeTakedownTime          = 60.0;
	RwReal gmrPropHitChainTime                   = 2.0;
	RwReal gmrPropHitBurnValue                   = 3.0;
	RwReal gmrTradingPaintBurnValue              = 3.0;
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
		15.0, 30.0, 60.0, 90.0
	};

	float gmarMinOncoming[4] = {
		50.0, 100.0, 200.0, 300.0
	};

	float gmarMinDrift[4] = {
		45.0, 90.0, 180.0, 270.0
	};

	float gmarMinTailgate[3] = {
		1.0, 5.0, 10.0
	};

	float gmarMinRubbing[3] = {
		0.1, 4.0, 8.0
	};

	float gmarMinGrinding[3] = {
		0.1, 4.0, 8.0
	};

	float gmarMinNearMiss[4] = {
		999.0, 2.0, 5.0, 9.0
	};

	float gmarMinCheckedTraffic[4] = {
		1.0, 2.0, 3.0, 4.0
	};

	RwReal gmrTailgateMaxDistance       = 15.0;
	RwReal gmrTailgatePsycheOutDistance = 7.5;
	RwReal gmrTailgateConeAngle         = 15.0;
	RwReal gmrTailgateExtraBurnValue    = 15.0;
	RwReal gmrTailgateInitialTime       = 0.5;
	RwReal gmrGrindingExtraBurnValue    = 15.0;

	RwReal krSlamChainMaxTimeBetweenSlams;
};