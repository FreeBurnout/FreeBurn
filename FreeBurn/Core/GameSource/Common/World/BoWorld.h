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
	void Prepare(bool lbQuickPrepare);
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

class CBoSpatialTrigger {
public:
	CBoPlanarTriggerStruct * mpPlanarTriggerData;

	void Construct();
};

extern CBoWorld gWorld;