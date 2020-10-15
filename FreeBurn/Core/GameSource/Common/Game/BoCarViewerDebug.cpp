#include <rwcore.h>

#include "BoCarViewerDebug.h"

bool CBoCarViewerDebug::IsActive() {
	return false;
}

void CBoCarViewerDebug::SetColour(RwInt32 lnColour) {

}

void CBoCarViewerDebug::ViewRaceCar() {

}

void CBoCarViewerDebug::UpdateCamera(RwReal mrTimeStep) {

}

void CBoCarViewerDebug::ViewTrafficCar() {

}

void CBoCarViewerDebug::ViewNextPayload(CBoVehiclePhysics * param_1) {

}

// DONE
void CBoCarViewerDebug::ViewPrevVehicle() {
    if (meCarType != EBoViewingCarType::RaceCar) {
        mnCurrentColour = 0;
        if (mnCurrentTrafficCar < 1) {
            ViewRaceCar();
            SetColour(0);
        }
        else {
            mnCurrentTrafficCar--;
            ViewTrafficCar();
        }
    }
}