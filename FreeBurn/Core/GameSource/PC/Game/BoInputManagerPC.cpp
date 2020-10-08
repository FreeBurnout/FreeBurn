#pragma once

#include "../../Common/Game/BoInputManager.h"
#include "../../Common/Game/BoControllerMapping.h"
#include "../../../../GameShared/PC/System/Input/GtInputDevicePCLogitechWheel.h"

CBoInputManager gInputManager;

void CBoInputManager::ResetState() {
    if (!mbIsPaused) {
        SetPause(false);
    }
    StopRumble();
    UpdateRumble();
}

void CBoInputManager::SetPause(bool lbPaused) {
    mInputManagerPCPad2.SetPause(lbPaused);
    /* TODO: this stuff
    SetPause((CGtInputManagerPCLogitechWheel *)(this + 0x94c), lbPaused);
    */
    mbIsPaused = lbPaused;
}

void CBoInputManager::StopRumble() {
    for (int i = 0; i < 2; i++) {
        StopPlayerRumble(i);
    }
}

void CBoInputManager::StopPlayerRumble(signed char ln8PlayerIndex) {
    CBoControllerMapping * paMaps[4];
    CBoControllerMapping ** pMap = paMaps;
    mabClearRumble[ln8PlayerIndex] = true;
    GetAvailableControllers(paMaps, ln8PlayerIndex);
    for (int i = 0; i < 2; i++) {
        if (*pMap != nullptr && (*pMap)->WheelIsValid()) {
            (*pMap)->mpWheel->SetRumble(0.0, 1.0);
        }
        pMap++;
    }
}

RwInt8 CBoInputManager::GetLockedPlayersPort(signed char ln8Player) {
    return RwInt8();
}

void CBoInputManager::UpdateRumble() {

}

void CBoInputManager::GetAvailableControllers(CBoControllerMapping ** lapControllerMappingsOut, signed char ln8PortIndex) {

}

void CBoInputManager::UnlockPlayerPort(signed char ln8Player) {

}

void CBoInputManager::Update() {

}

void CBoInputManager::UpdateFE() {

}

