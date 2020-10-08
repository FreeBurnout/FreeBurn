#include "BoLapManager.h"

RwReal CBoLapManager::gmrPerfectLapBurnValue = 120.0;
RwReal CBoLapManager::gmrBurnoutLapBurnValue = 240.0;
RwInt32 CBoLapManager::gmnPerfectLapBP = 2000;
RwInt32 CBoLapManager::gmnBurnoutLapBP = 4000;

int CBoLapManager::gmanBestRacePositionBP[5] = {
	500, 400, 300, 200, 100
};