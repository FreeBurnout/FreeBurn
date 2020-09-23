#pragma once

#include "rwcore.h"

class CGtTimer {
public:
	RwReal mrTimeStep;

	bool PrepareTimerServices(int lnBaseFrameRate);
	void NextFrame();
};