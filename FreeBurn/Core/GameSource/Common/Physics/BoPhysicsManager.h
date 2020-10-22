#include <rwcore.h>

#include "BoCheckedTrafficPhysics.h"
#include "BoRaceCarPhysics.h"
#include "../World/BoRaceCar.h"

class CBoPhysicsManager {
public:
	RwInt32 mnNumCheckedTrafficBodies;
	RwInt32 mnNumTrafficBodies;
	CBoCheckedTrafficPhysics GetCheckedTrafficPhysics(int);
	void Update(float);
	CBoRaceCarPhysics GetRaceCarPhysics(ERaceCarIndex leRaceCarIndex);
};