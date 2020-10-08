#include "BoSettings.h"
#include "BoGame.h"
#include "../../PC/Graphics/BoGraphicsManagerPC.h"
#include "../../../../GameShared/Common/System/GtLocalisation.h"

bool CBoSettings::mgb50Hz;
bool CBoSettings::mgbProgressiveScan;
EGtLanguage CBoSettings::mgeLanguage;

// DONE
void CBoSettings::Activate() {
    for (int i = 0; i < 2; i++) {
        gGame.maPlayerCamera[i].meForwardBehaviour = EBoPlayerCameraBehaviour::InGameBumper;
        if (mabExternalCam[i]) {
            gGame.maPlayerCamera[i].meForwardBehaviour = EBoPlayerCameraBehaviour::InGameFollow;
        }
    }
    gGraphicsManager.mScreenPositionData.marValues[0] = mn8ScreenOffsetX * 0.0075;
    gGraphicsManager.mScreenPositionData.marValues[1] = mn8ScreenOffsetY * -0.0075;
    InGameActivate();
}

void CBoSettings::Construct() {
    mgb50Hz = false;
    mgbProgressiveScan = false;
    mn8ScreenOffsetX = 0;
    mn8ScreenOffsetY = 0;
    mn8SoundConfig = 0;
    mn8SFXVolume = 0x5A;
    mn8MusicVolume = 0x5A;
    mn8DJVolume = 0x5A;
    mn8SongIndex = 0;
    mn8SoundtrackIndex = 0;
    mn8RadioOn = 1;
    mbPlayModeRandom = true;
    mn8TakedownCamMode = 1;
    mbCrashAutoSlowMo = true;
    mabExternalCam[0] = true;
    mabExternalCam[1] = true;
    mbAutoSaveIsOn = false;
    mbViewedRaceTraining = false;
    mbViewedTrafficAttackTraining = false;
    mbViewedCrashTraining = false;
    mbViewedRoadRageTraining = true;
    mbViewedRevengeTraining = false;
    mePartySecurity = EOptionServicePartySecurity::Public;
    mePartyHeadsetOutputMode = EGtNetworkHeadsetOutputMode::Headset;
    mbPartyAppearanceOnline = true;
    mgeLanguage = EGtLanguage::USEnglish;
    memset(this, 0xF, 0x28);
    for (int i = 0; i < 2; i++) {
        mabRumble[i] = true;
    }
}

void CBoSettings::InGameActivate() {

}
