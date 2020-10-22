#include "BoPhysicsManager.h"
#include "../World/BoRaceCar.h"
#include "../../Common/Physics/BoRaceCarPhysics.h"

CBoCheckedTrafficPhysics CBoPhysicsManager::GetCheckedTrafficPhysics(int) {
    return CBoCheckedTrafficPhysics();
}

void CBoPhysicsManager::Update(float) {

}

CBoRaceCarPhysics CBoPhysicsManager::GetRaceCarPhysics(ERaceCarIndex leRaceCarIndex) {
    return CBoRaceCarPhysics();
}
