#pragma once

#include <rwcore.h>

#include "../Physics/BoVehiclePhysics.h"

enum class EBoViewingCarType {
	RaceCar = 0,
	TrafficCar = 1,
	Trailer = 2
};

class CBoCarViewerDebug {
public:
	EBoViewingCarType meCarType;
	RwInt32 mnCurrentColour;
	RwInt32 mnCurrentTrafficCar;

	void ViewPrevVehicle();
	bool IsActive();
	void SetColour(RwInt32 lnColour);
	void ViewRaceCar();
	void UpdateCamera(RwReal mrTimeStep);
	void ViewTrafficCar();
	void ViewNextPayload(CBoVehiclePhysics * param_1);
};