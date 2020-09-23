#pragma once

#include "../../../../GameShared/Common/System/GtTimer.h"

class CBoTimer : public CGtTimer {
public:
	using CGtTimer::mrTimeStep;

	using CGtTimer::PrepareTimerServices;
	using CGtTimer::NextFrame;

	void Construct();
	void Update();
	void SetAllowSlowMo(bool);
};