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

void CBoMemoryCardManager::SetMessage(RwChar * lpMessage) {

}

void CBoMemoryCardManager::SetOptions(RwChar * lpOptions0, RwChar * lpOptions1, RwChar * lpOptions2, RwChar * lpOptions3) {

}

void CBoMemoryCardManager::UpdateDebugFlow() {
    int uVar2;
    EDebugSubstate iVar1 = meDebugSubstate;
    if (iVar1 == EDebugSubstate::DisplayChoiceMessage) {
        SetMessage("Memory Card Debug\nSelect Appropriate Flow");
        SetOptions("Bootup Check", "Bootup Load/Create", "Manual Save Profile", "Manual Load Profile");
        uVar2 = 2;
    }
    else {
        if (meDebugSubstate < EDebugSubstate::Poll) {
            if (iVar1 == EDebugSubstate::Init) {
                meDebugSubstate = EDebugSubstate::DisplayChoiceMessage;
                return;
            }
            meDebugSubstate = EDebugSubstate::Finished;
            return;
        }
        if (iVar1 != EDebugSubstate::Poll) {
            if (iVar1 != EDebugSubstate::Finished) {
                meDebugSubstate = EDebugSubstate::Finished;
                return;
            }
            mbIsFinished = true;
            return;
        }
        uVar2 = GetSelection();
        switch (uVar2) {
        case 0:
            ClearMessage();
            StartBootCheckFlow();
            uVar2 = 3;
            break;
        case 1:
            ClearMessage();
            StartBootLoadProfileFlow();
            uVar2 = 3;
            break;
        case 2:
            ClearMessage();
            StartSaveProfileFlow();
            uVar2 = 3;
            break;
        case 3:
            ClearMessage();
            StartLoadProfileFlow();
            uVar2 = 3;
            break;
        default:
            return;
        }
    }
    meDebugSubstate = (EDebugSubstate)uVar2;
}
