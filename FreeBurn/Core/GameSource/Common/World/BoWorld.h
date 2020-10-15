#pragma once

#include "../Game/BoTimer.h"

class CBoWorld {
public:
	CBoTimer mTimer;

	bool mbPausedForNetworkSync;
	bool mbPausedForStreamSync;
	bool mbIsReplaying;
	bool mbRequestReplay;

	void Construct();
	bool Prepare(bool lbQuickPrepare);
	void Release();
	void Update();
	void UpdateSound();
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