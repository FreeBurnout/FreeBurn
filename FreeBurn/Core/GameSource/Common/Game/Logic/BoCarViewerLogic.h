#pragma once

#include "BoStageLogic.h"

class CBoCarViewerLogic : CBoStageLogic {
public:
	void Construct();
	void SetColour(int);
	void ViewRaceCar();
	void ViewTrafficCar();
};