#include <rwcore.h>

#include "BoOffensiveDrivingManager.h"

bool _gbRegisteredCommsToolValues = false;

RwReal CBoOffensiveDrivingManager::gmrAirMinimumDistanceValue = 5.0;
RwReal CBoOffensiveDrivingManager::gmrAirDistanceBurnValue = 2.0;
RwReal CBoOffensiveDrivingManager::gmrOncomingMinimumSpeed = 30.0;
RwReal CBoOffensiveDrivingManager::gmrOncomingMinimumDistanceValue = 10.0;
RwReal CBoOffensiveDrivingManager::gmrOncomingDistanceBurnValue = 0.3;
RwReal CBoOffensiveDrivingManager::gmrDriftMinimumSpeed = 30.0;
RwReal CBoOffensiveDrivingManager::gmrDriftMinimumDistanceValue = 10.0;
RwReal CBoOffensiveDrivingManager::gmrDriftDistanceBurnValue = 1.0;
RwReal CBoOffensiveDrivingManager::gmrMaxNearMissDistance = 2.0;
RwReal CBoOffensiveDrivingManager::gmrNearMissMinimumSpeed = 30.0;
RwReal CBoOffensiveDrivingManager::gmrNearMissMinimumChainSpeed = 30.0;
RwReal CBoOffensiveDrivingManager::gmrNearMissBurnValue = 60.0;
RwReal CBoOffensiveDrivingManager::gmrNearMissChainTime = 5.0;
RwReal CBoOffensiveDrivingManager::gmrCrashClassCheckingTrafficBurnValue = 30.0;
RwReal CBoOffensiveDrivingManager::gmrRaceClassCheckingTrafficBurnLoss = 70.0;
RwReal CBoOffensiveDrivingManager::gmrCheckingTrafficTime = 2.0;
RwReal CBoOffensiveDrivingManager::gmrCrashEscapeRadius = 8.0;
RwReal CBoOffensiveDrivingManager::gmrCrashNearMissChainTime = 1.0;
RwReal CBoOffensiveDrivingManager::gmrCrashEscapeMinClearTime = 3.0;
RwReal CBoOffensiveDrivingManager::gmrCrashEscapeMinimumSpeed = 70.0;
RwReal CBoOffensiveDrivingManager::gmrCrashEscapeBurnValue = 120.0;
RwReal CBoOffensiveDrivingManager::gmrBurnRatioLostInCrash = 0.5;
RwReal CBoOffensiveDrivingManager::gmrMaxSlamBurnValue = 360.0;
RwReal CBoOffensiveDrivingManager::gmrRubbingMinTime = 0.3;
RwReal CBoOffensiveDrivingManager::gmrRubbingBurnValue = 15.0;
RwReal CBoOffensiveDrivingManager::gmrBoostStartBurnValue = 50.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownBurnValue = 720.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownWaitTime = 1.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownCrashTime = 1.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownCrashTimeOnline = 3.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownCrashTimeNoSlam = 0.5;
RwReal CBoOffensiveDrivingManager::gmrTakedownCollideTimeNoSlam = 0.5;
RwReal CBoOffensiveDrivingManager::gmrTakedownCollideTimeNoSlamOnline = 1.0;
RwReal CBoOffensiveDrivingManager::gmrTakedownTimeAfterAfterSlam = 0.5;
RwReal CBoOffensiveDrivingManager::gmrDoubleTakedownTime = 1.0;
RwReal CBoOffensiveDrivingManager::gmrSpreeTakedownTime = 30.0;
RwReal CBoOffensiveDrivingManager::gmrDoubleRevengeTakedownTime = 60.0;
RwReal CBoOffensiveDrivingManager::gmrPropHitChainTime = 2.0;
RwReal CBoOffensiveDrivingManager::gmrPropHitBurnValue = 3.0;
RwReal CBoOffensiveDrivingManager::gmrTradingPaintBurnValue = 3.0;
RwInt32 CBoOffensiveDrivingManager::gmnPropHitBP = 10;
RwInt32 CBoOffensiveDrivingManager::gmnRubbingBP = 5;
RwInt32 CBoOffensiveDrivingManager::gmnTradingPaintBP = 25;
RwInt32 CBoOffensiveDrivingManager::gmnBoostStartBP = 50;
RwInt32 CBoOffensiveDrivingManager::gmnCrashEscapeBP = 100;
int CBoOffensiveDrivingManager::gmanSlamBP[3] = {
	20, 20, 50
};
int CBoOffensiveDrivingManager::gmanSuperSlamBP[3] = {
	30, 30, 50
};
RwInt32 CBoOffensiveDrivingManager::gmnTakedownBP = 1000;
RwInt32 CBoOffensiveDrivingManager::gmnRevengeBP = 350;
RwInt32 CBoOffensiveDrivingManager::gmnPsycheOutBP = 150;
RwInt32 CBoOffensiveDrivingManager::gmnAftertouchTakedownBP = 250;
RwInt32 CBoOffensiveDrivingManager::gmnAerialTakedownBP = 400;
RwInt32 CBoOffensiveDrivingManager::gmnTBoneTakedownBP = 150;
RwInt32 CBoOffensiveDrivingManager::gmnCrashbreakerTakedownBP = 0xFA;
RwInt32 CBoOffensiveDrivingManager::gmnNearMissBP = 0x14;
RwInt32 CBoOffensiveDrivingManager::gmnYouWereLuckyBP = 0xF;
RwInt32 CBoOffensiveDrivingManager::gmnDeniedBP = 0xA;
RwInt32 CBoOffensiveDrivingManager::gmnCheckedTrafficBP = 0x14;
int CBoOffensiveDrivingManager::gmanAirBP[4] = {
	0x64, 0xFA, 0x1F4, 0x3E8
};
int CBoOffensiveDrivingManager::gmanOncomingBP[4] = {
	0x64, 0xFA, 0x1F4, 0x3E8
};
int CBoOffensiveDrivingManager::gmanDriftBP[4] = {
	0x64, 0xFA, 0x1F4, 0x3E8
};
int CBoOffensiveDrivingManager::gmanTailgateBP[3] = {
	5, 10, 15
};
int CBoOffensiveDrivingManager::gmanRubbingBP[3] = {
	5, 10, 15
};
int CBoOffensiveDrivingManager::gmanGrindingBP[3] = {
	5, 10, 15
};
int CBoOffensiveDrivingManager::gmanNearMissBP[4] = {
	5, 10, 15, 25
};
int CBoOffensiveDrivingManager::gmanDoubleTakedownBP[4] = {
	300, 500, 750, 1000
};
int CBoOffensiveDrivingManager::gmanSpreeTakedownBP[4] = {
	300, 500, 750, 1000
};
int CBoOffensiveDrivingManager::gmanDoubleRevengeTakedownBP[3] = {
	300, 500, 0
};
int CBoOffensiveDrivingManager::gmanRoadRageTakedownBP[8] = {
	100,  250,  500,  1000,
	1250, 1500, 1750, 2000
};
float CBoOffensiveDrivingManager::gmarMinAir[4] = {
	15.0, 30.0, 60.0, 90.0
};
float CBoOffensiveDrivingManager::gmarMinOncoming[4] = {
	50.0, 100.0, 200.0, 300.0
};
float CBoOffensiveDrivingManager::gmarMinDrift[4] = {
	45.0, 90.0, 180.0, 270.0
};
float CBoOffensiveDrivingManager::gmarMinTailgate[3] = {
	1.0, 5.0, 10.0
};
float CBoOffensiveDrivingManager::gmarMinRubbing[3] = {
	0.1, 4.0, 8.0
};
float CBoOffensiveDrivingManager::gmarMinGrinding[3] = {
	0.1, 4.0, 8.0
};
float CBoOffensiveDrivingManager::gmarMinNearMiss[4] = {
	999.0, 2.0, 5.0, 9.0
};
float CBoOffensiveDrivingManager::gmarMinCheckedTraffic[4] = {
	1.0, 2.0, 3.0, 4.0
};
RwReal CBoOffensiveDrivingManager::gmrTailgateMaxDistance = 15.0;
RwReal CBoOffensiveDrivingManager::gmrTailgatePsycheOutDistance = 7.5;
RwReal CBoOffensiveDrivingManager::gmrTailgateConeAngle = 15.0;
RwReal CBoOffensiveDrivingManager::gmrTailgateExtraBurnValue = 15.0;
RwReal CBoOffensiveDrivingManager::gmrTailgateInitialTime = 0.5;
RwReal CBoOffensiveDrivingManager::gmrGrindingExtraBurnValue = 15.0;