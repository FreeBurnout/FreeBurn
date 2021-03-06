#ifndef GTTIMER_H
#define GTTIMER_H

#include <rwcore.h>

class CGtTimer {
public:
	float mrTimeStep;

	void NextFrame();
	void Update();
	static bool PrepareTimerServices(RwInt32 lnBaseFrameRate);
};

#endif // !#define GTTIMER_H
