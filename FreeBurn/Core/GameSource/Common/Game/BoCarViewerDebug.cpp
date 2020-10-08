#include "BoCarViewerDebug.h"

#include <rwcore.h>


bool CBoCarViewerDebug::IsActive() {
	return false;
}

void CBoCarViewerDebug::UpdateCamera(RwReal mrTimeStep) {

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