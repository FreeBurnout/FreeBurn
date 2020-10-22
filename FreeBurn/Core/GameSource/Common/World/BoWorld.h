#pragma once

#include "../Game/BoTimer.h"
#include "../Physics/BoPhysicsManager.h"
#include "BoEnvironmentManager.h"
#include "Track/BoStaticTrack.h"
#include "../Camera/Crash/BoCrashAnalyser.h"

class CBoWorld {
public:
	CBoTimer mTimer;
	CBoPhysicsManager mPhysicsManager;
	bool mbPausedForNetworkSync;
	bool mbPausedForStreamSync;
	bool mbIsReplaying;
	bool mbRequestReplay;
	RwInt32 mnNumRaceCars;
	CBoEnvironmentManager gEnvironmentManager;
	CBoStaticTrack mStaticTrack;
	CBoCrashAnalyser maPlayerCrashAnalysers[2];

	void Construct();
	void Destruct();
	bool Prepare(bool lbQuickPrepare);
	void Release();
	void Update();
	void UpdateSound();
	void UpdateTrack();
};

class CBoRacePosition {
public:
	void Construct();
};

class CBoStartPositionStruct {
public:
	void Construct();
};

class CBoStartPoint {
public:
	CBoStartPositionStruct * mpStartPositionStruct;

	void Construct();
};

struct CBoPlanarTriggerStruct {

};

class CBoSpatialTrigger {
public:
	CBoPlanarTriggerStruct * mpPlanarTriggerData;

	void Construct();
};

extern CBoWorld gWorld;