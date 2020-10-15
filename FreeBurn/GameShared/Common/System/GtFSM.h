#pragma once

#include <rwcore.h>

#include "../Core/GtID.h"

enum class EGtStateAction {
	Construct = 0,
	Destruct = 1,
	Leave = 2,
	Enter = 3,
	Update = 4,
	Event = 5
};

class CGtState {
public:
	GtID mID;
};

class CGtFSM {
public:
	CGtState * mpState;

	void SetInitialMenuState();
	void Update();
};

class CGtStateOffset {
public:
	GtID mID;
	RwInt32 mnOffset;
};