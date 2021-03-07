#ifndef BOSAVEGAMEDATAMANAGER_H
#define BOSAVEGAMEDATAMANAGER_H

#include <rwcore.h>

#include "../../../Shared/System/Common/Unicode/GtUnicode.h"
#include "../../../Shared/System/Common/GtSysConfig.h"
#include "Persistence/BoProfile.h"

class CBoSaveGameData {
	RwInt32 mnDataVersion; 
	RwInt32 mnRankID; 
	RwInt32 mnNumUnlockedEvents; 
	RwInt32 mnNumGoldMedals; 
	RwInt32 mnPercentComplete; 
	RwReal mrTotalPlayingTime;
	CGtTimeStamp mSaveDateTimeStamp;
	CBoSettings mSettings; 
	CBoProfile mPlayerProfile;
	RwUInt32 munCheckSum;

	bool IsChecksumValid();
	RwUInt32 CalcChecksum();
};

class CBoSaveGameDataManager {
public:
	RwUInt32 munLastCheckSum;
	CGtTimeStamp munLastTimeStamp;
	RwInt8 mbLastProfileIsEmptyStatus;
	RwReal mrPlayingTimeSecsCountAtLastLoad;
	RwReal mrPlayingTimeSecsCounter;
	CBoSaveGameData mSaveGameData;

	void Init();
	void BuildDataForSave(GtUTF16* lpProfileName, RwBool lbIsNewGame);
	void SetCurrent();
	void SetProfileAsEmpty();
	CBoSaveGameData* GetSaveGameData();
	void IncrementPlayingTimeCounter(float);
};

static CBoSaveGameDataManager gSaveGameDataManager;

#endif // !BOSAVEGAMEDATAMANAGER_H
