#pragma once

#include "BoSingleRaceLogic.h"
#include <rwcore.h>

class CBoSingleRoadRageLogic : CBoSingleRaceLogic {
public:
	RwInt32 mnStageIndex;

	void Construct();
};