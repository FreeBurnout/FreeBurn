#include <rwcore.h>

#include "BoInGameRatingManager.h"

void CBoInGameRatingManager::Construct() {
	mrRatingBalance = 1.0;
	mrCurrentRatingRatio = 0.5;
    meProgressionRating = EBoProgressionRating::OK;
    meDebugProgressionRating = EBoProgressionRating::None;
}
