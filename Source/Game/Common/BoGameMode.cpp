#include <rwcore.h>

#include "BoGameMode.h"
#include "Logic/BoStageLogic.h"
#include "Challenge/BoChallenge.h"

void CBoGameMode::Construct() {

}

bool CBoGameMode::Prepare() {
    return false;
}

void CBoGameMode::Update() {

}

void CBoGameMode::Release() {

}

void CBoGameMode::Destruct() {

}

bool CBoGameMode::StartReplay() {
    return false;
}

RwInt32 CBoGameMode::GetNumLaps() {
    return RwInt32();
}

void CBoGameMode::RequestResetWithFullPrepare() {

}

void CBoGameMode::SetStageLogic(CBoStageLogic * lpStageLogic) {

}

CBoStageLogic * CBoGameMode::GetStageLogic() {
    return nullptr;
}

void CBoGameMode::SetChallenge(CBoChallenge * lpChallenge) {

}

CBoChallenge * CBoGameMode::GetChallenge() {
    return nullptr;
}

void CBoOnePlayerStage::Construct() {
}

void CBoTwoPlayerSplitScreenStage::Construct() {
}
