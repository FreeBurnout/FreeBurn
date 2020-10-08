#include "BoSaveGameDataManager.h"

CBoSaveGameDataManager gSaveGameDataManager;

void CBoSaveGameDataManager::Init() {
	mrPlayingTimeSecsCounter = 0;
	mbLastProfileIsEmptyStatus = true;
	munLastCheckSum = 0;
	mrPlayingTimeSecsCountAtLastLoad = 0;
}
