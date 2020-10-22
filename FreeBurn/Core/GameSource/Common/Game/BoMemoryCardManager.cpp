#include <cstdint>

#include "BoMemoryCardManager.h"

RwInt32 CBoMemoryCardManager::GetSelection() {
    return RwInt32();
}

void CBoMemoryCardManager::ClearMessage() {

}

void CBoMemoryCardManager::StartBootCheckFlow() {

}

void CBoMemoryCardManager::StartBootLoadProfileFlow() {

}

void CBoMemoryCardManager::StartSaveProfileFlow() {

}

void CBoMemoryCardManager::StartLoadProfileFlow() {

}

void CBoMemoryCardManager::Construct() {

}

void CBoMemoryCardManager::Release() {

}

void CBoMemoryCardManager::SetMessage(RwChar * lpMessage) {

}

void CBoMemoryCardManager::SetOptions(RwChar * lpOptions0, RwChar * lpOptions1, RwChar * lpOptions2, RwChar * lpOptions3) {

}

void CBoMemoryCardManager::UpdateDebugFlow() {
    RwInt32 lnRetVal;
    if (meDebugSubstate == EDebugSubstate::DisplayChoiceMessage) {
        SetMessage("Memory Card Debug\nSelect Appropriate Flow");
        SetOptions("Bootup Check", "Bootup Load/Create", "Manual Save Profile", "Manual Load Profile");
        lnRetVal = 2;
    }
    else {
        if (meDebugSubstate < EDebugSubstate::Poll) {
            if (meDebugSubstate == EDebugSubstate::Init) {
                meDebugSubstate = EDebugSubstate::DisplayChoiceMessage;
            } else {
                meDebugSubstate = EDebugSubstate::Finished;
            }
            return;
        }
        if (meDebugSubstate != EDebugSubstate::Poll) {
            if (meDebugSubstate == EDebugSubstate::Finished) {
                mbIsFinished = true;
            }
            meDebugSubstate = EDebugSubstate::Finished;
            return;
        }
        lnRetVal = GetSelection();
        if (lnRetVal >= 0 && lnRetVal <= 3) {
            ClearMessage();
            switch (lnRetVal) {
                case 0: StartBootCheckFlow(); break;
                case 1: StartBootLoadProfileFlow(); break;
                case 2: StartSaveProfileFlow(); break;
                case 3: StartLoadProfileFlow(); break;
            }
            lnRetVal = 3;
        } else {
            return;
        }
    }
    meDebugSubstate = (EDebugSubstate)lnRetVal;
}
