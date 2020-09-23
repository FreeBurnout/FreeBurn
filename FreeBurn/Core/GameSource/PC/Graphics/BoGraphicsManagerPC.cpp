#include "BoGraphicsManagerPC.h"

void CBoGraphicsManagerBase::DrawBootLoadingScreen(float lrProgress) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
}

void CBoGraphicsManagerBase::CloseViewport() {

}

void CBoGraphicsManager::Construct() {
	
}

void CBoGraphicsManager::PresentDrawBuffer() {
	SDL_RenderPresent(renderer);
}

void CBoGraphicsManager::OpenViewport(EBoViewportSelection leViewportSelection) {

}

void CBoGraphicsManager::RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode) {

}

RwUInt32 CBoGraphicsManager::GetVBlankCount() {
	return RwUInt32();
}
