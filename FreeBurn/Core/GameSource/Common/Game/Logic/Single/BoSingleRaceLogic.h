#pragma once

#include "../BoStageLogic.h"

class CBoSingleRaceLogic : protected CBoStageLogic {
public:
	void Construct();
};

class CBoBurningLapLogic : CBoSingleRaceLogic {
public:
	void Construct();
};

class CBoEliminatorLogic : CBoSingleRaceLogic {
public:
	void Construct();
};