#include <vcruntime_string.h>

#include "BoPlayerCameraManager.h"
#include "../World/BoPlayerCar.h"

void CBoPlayerCameraManager::Construct() {
}

// DONE
void CBoPlayerCameraManager::SetCutThisFrame(bool lbCutThisFrame) {
	mbCutThisFrame = lbCutThisFrame;
}

// DONE
void CBoPlayerCameraManager::Update() {
	CGtFSM::Update();
}

void CBoPlayerCameraManager::Update(float) {

}

// DONE
bool CBoFlags::Prepare() {
	memset(&maxBits, 0, sizeof(maxBits));
	return true;
}

