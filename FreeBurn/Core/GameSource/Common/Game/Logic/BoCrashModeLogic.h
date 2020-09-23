#pragma once

#include "BoStageLogic.h"

class CBoCrashModeLogic : CBoStageLogic {
public:
	void Construct();
};

class CBoCompCrashModeLogic : CBoCrashModeLogic {
public:
	void Construct();
};

class CBoPartyCrashModeLogic : CBoCrashModeLogic {
public:
	void Construct();
};

class CBoTourCrashModeLogic : CBoCrashModeLogic {
public:
	void Construct();
};

