#include "BoDebugManager.h"

void CBoDebugManager::Construct() {

}

void CBoDebugManager::Destruct() {

}

void CBoDebugManager::Update() {

}

void CBoDebugManager::UpdateStartOfFrame() {
    if (gmbRequestStopAll) {
        mbPlay = false;
        mbSteppingCameras = true;
        mbStepping = true;
        mbPlayCameras = false;
    }
    if (gmbRequestStopUpdate) {
        mbPlay = false;
        mbStepping = true;
    }
    if (gmbRequestPlayAll) {
        mbStepping = false;
        mbPlayCameras = true;
        mbSteppingCameras = false;
        mbPlay = true;
    }
    if (gmbRequestPlayCameras) {
        mbSteppingCameras = false;
        mbPlayCameras = true;
    }
    if (mbStepping) {
        mbPlay = gmbRequestStepAll;
        gmbRequestStepCameras = gmbRequestStepAll;
    }
    if (mbSteppingCameras) {
        mbPlayCameras = gmbRequestStepCameras;
    }
    gmbRequestStopAll = 0;
    gmbRequestStopUpdate = 0;
    gmbRequestStepAll = 0;
    gmbRequestStepCameras = 0;
    gmbRequestPlayAll = 0;
    gmbRequestPlayCameras = 0;
}

void CBoDebugManager::RenderOverlays() {

}

void CBoCPUMonitors::Construct() {

}

void CBoGPUMonitors::Construct() {

}

bool CBoDebugManager::gmbRequestStopAll;
bool CBoDebugManager::gmbRequestStopUpdate;
bool CBoDebugManager::gmbRequestStepAll;
bool CBoDebugManager::gmbRequestStepCameras;
bool CBoDebugManager::gmbRequestPlayAll;
bool CBoDebugManager::gmbRequestPlayCameras;
RwReal CBoDebugManager::gmrGpuMonitorOpacity;
bool CBoDebugManager::gmbDrawGpuTextAsTable;
RwReal CBoDebugManager::gmrGpuTextTableOffset;

CBoDebugManager gDebugManager;