#pragma once

#include "../Core/GtID.h"

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
	
};