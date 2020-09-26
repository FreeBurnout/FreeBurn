#include "BoGraphicsManager.h"

#include <SDL.h>

void CBoGraphicsManagerBase::Update() {

}

void CBoGraphicsManagerBase::CloseViewport() {

}

void CBoGraphicsManagerBase::DrawBootLoadingScreen(float lrProgress) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
}