#ifndef BOSETTINGS_H
#define BOSETTINGS_H

#include <rwcore.h>

#include "BoLanguageManager.h"
#include "../../../Shared/Networking/Common/GtNetworkHeadsetBase.h"

enum EOptionServicePartySecurity {
	ePartySecurityPublic = 0,
	ePartySecurityPrivate = 1,
	ePartySecurityClosed = 2,
	ePartySecurityMax = 3
};

enum EBoSpeakerConfig {
	eSpeakerStereo = 0,
	eSpeakerSurround = 1,
	eSpeakerMono = 2,
	eSpeakerConfigNumEntries = 3
};

class CBoSettings {
public:
	char maun8SongFlags[40];
	bool mabRumble[2];
	RwInt8 mn8ScreenOffsetX;
	RwInt8 mn8ScreenOffsetY;
	RwInt8 mbPad0;
	RwInt8 mn8SoundConfig;
	RwInt8 mn8SFXVolume;
	RwInt8 mn8MusicVolume;
	RwInt8 mn8DJVolume;
	RwInt8 mn8SongIndex;
	RwInt8 mn8SoundtrackIndex;
	RwInt8 mgb50Hz;
	RwInt8 mgbProgressiveScan;
	RwInt8 mn8RadioOn;
	RwInt8 mbPlayModeRandom;
	RwInt8 mn8TakedownCamMode;
	RwInt8 mbCrashAutoSlowMo;
	bool mabExternalCam[2];
	RwInt8 mbAutoSaveIsOn;
	RwInt8 mbViewedRaceTraining;
	RwInt8 mbViewedTrafficAttackTraining;
	RwInt8 mbViewedCrashTraining;
	RwInt8 mbViewedRoadRageTraining;
	RwInt8 mbViewedRevengeTraining;
	EGtLanguage mgeLanguage;
	EOptionServicePartySecurity mePartySecurity;
	EGtNetworkHeadsetOutputMode mePartyHeadsetOutputMode;
	bool mbPartyAppearanceOnline;
	char macPartyPassword[16];
	
	void Construct();
	void Destruct();
	void Activate();
	void InGameActivate();
	void TraxActivate();
	void SetFXVolume(RwInt8);
	RwInt8 ChangeFXVolume(RwInt8);
	void SetMusicVolume(RwInt8);
	RwInt8 ChangeMusicVolume(RwInt8);
	void SetSpeakerConfig(EBoSpeakerConfig);
	bool UseMetricUnits();
};

#endif // !#define BOSETTINGS_H

