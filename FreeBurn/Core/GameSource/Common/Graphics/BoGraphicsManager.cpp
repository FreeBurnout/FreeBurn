#include "BoGraphicsManager.h"

#include <SDL.h>

void CBoGraphicsManagerBase::Construct() {

}

void CBoGraphicsManagerBase::Destruct() {

}

// DONE
void CBoGraphicsManagerBase::Update() {
    if (
        (mScreenPositionData.marValues[0] != mScreenPositionDataOld.marValues[0]) || 
        (mScreenPositionData.marValues[1] != mScreenPositionDataOld.marValues[1])
        ) {
        mScreenPosition.MoveScreen(
            mScreenPositionData.marValues[0] - mScreenPositionDataOld.marValues[0], 
            mScreenPositionData.marValues[1] - mScreenPositionDataOld.marValues[1]
        );
        *mScreenPositionDataOld.marValues = *mScreenPositionData.marValues;
    }
}

// DONE
void CBoGraphicsManagerBase::CloseViewport() {
    RwCameraEndUpdate(mpCurrentViewport->mpRwCamera);
    mpCurrentViewportParams = nullptr;
    mpCurrentViewport = nullptr;
}

void CBoGraphicsManagerBase::DrawBootLoadingScreen(float lrProgress) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
}