#pragma once

#include <rwcore.h>

#include "../../../../GameShared/Common/System/Networking/GtNetworkHeadsetBase.h"
#include "../../../../GameShared/Common/System/GtLocalisation.h"

enum class EOptionServicePartySecurity {
	Public = 0,
	Private = 1,
	Closed = 2,
	Max = 3
};

class CBoSettings {
public:
	static bool mgb50Hz;
	static bool mgbProgressiveScan;
	static EGtLanguage mgeLanguage;

	RwInt32 mn8SoundConfig;
	RwInt32 mn8SFXVolume;
	RwInt32 mn8MusicVolume;
	RwInt32 mn8DJVolume;
	RwInt32 mn8SongIndex;
	RwInt32 mn8SoundtrackIndex;
	RwInt32 mn8RadioOn;
	RwInt32 mbPlayModeRandom;
	RwInt32 mn8TakedownCamMode;
	bool mbCrashAutoSlowMo;
	bool mbAutoSaveIsOn;
	bool mbViewedRaceTraining;
	bool mbViewedTrafficAttackTraining;
	bool mbViewedCrashTraining;
	bool mbViewedRoadRageTraining;
	bool mbViewedRevengeTraining;
	EOptionServicePartySecurity mePartySecurity;
	EGtNetworkHeadsetOutputMode mePartyHeadsetOutputMode;
	bool mbPartyAppearanceOnline;
	bool mabExternalCam[2];
	bool mabRumble[2];
	char mn8ScreenOffsetX;
	char mn8ScreenOffsetY;

	void Activate();
	void Destruct();
	void Construct();
	void InGameActivate();
};