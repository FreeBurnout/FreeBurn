#include "../BoMenuFlowManager.h"
#include "../../BoFlashMovieManager.h"
#include "../../../Game/Persistence/BoProfile.h"
#include "../../../Game/BoProfileManager.h"
#include "../../../Network/BoNetworkManager.h"
#include "../../../Game/BoGame.h"
#include "../../../Sound/BoSoundManager.h"

GtID kB4MainMenuStateID = 0x961F57619210C87F;

void CBoMainMenuState::Action(EGtStateAction leAction, /*void * param_3,*/ int param_4) {
    if (leAction == EGtStateAction::Enter) {
        gNetworkManager.mbIsOnlineMenus = false;
        gProfileManager.mpActiveProfile->mProgression.SortProgressionData();
        gGame.mInputManager.UnlockPlayerPort(0);
        gGame.mInputManager.UnlockPlayerPort(1);
        gSoundManager.mGameModeManager.mRadio.mbReachedMainMenu = true;
        gFlashMovieManager.PlayMovie(EFlashMovie::Test, true);
    }
    else if ((leAction == EGtStateAction::Event) /*&& ((undefined *)param_3 == &GS_ST)*/) {
        switch (param_4) {
        case 0:
            InitiateConfirm(0x962400355e616cb8); // kB4RankSelectStateID
            break;
        case 1:
            InitiateConfirm(0x94413fd35bb72f40);
            break;
        case 2:
            InitiateConfirm(0x96218d07638bcf02);
            break;
        case 3:
            InitiateConfirm(0x9617741639bd5871); // kB4DriverDetailsMenuStateID
            break;
        }
    }
}

void CBoMainMenuState::InitiateConfirm(GtID lDestinationState) {

}
