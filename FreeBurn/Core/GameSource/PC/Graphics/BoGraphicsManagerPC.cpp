#include "BoGraphicsManagerPC.h"



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

CBoGraphicsManager gGraphicsManager;