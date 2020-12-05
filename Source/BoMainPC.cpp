#include <rwcore.h>
#include <iostream>

#include "Menu/BoMenuChoices.h"
#include "Game/Common/BoGame.h"
#include "Graphics/PC/BoGraphicsManagerPC.h"
#include "../Shared/System/PC/GtThreadMgrPC.h"

SDL_Window* window;

void __main() {

}

int main(int argc, char ** argv) {
	SDL_Event winEvt;
	window = SDL_CreateWindow("FreeBurn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 854, 480, SDL_WINDOW_OPENGL);

    __main();

    gGame.Construct();

    /*
    gGraphicsManager.DrawBootLoadingScreen(-1);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1);
    gGraphicsManager.PresentDrawBuffer();
    */

    

    while (/*!*/gGame.Prepare()) {
        CGtThreadMgr::SleepThreadTillVBlank();
        gGraphicsManager.DrawBootLoadingScreen(-1);
        gGraphicsManager.PresentDrawBuffer();
        SDL_PollEvent(&winEvt);
    }

    while (!gGame.mbQuitNow) {
        gGame.Update();
        for (int i = 14; i > -1; i--) {
            // hello
        }
        SDL_PollEvent(&winEvt);
        if (winEvt.type == SDL_QUIT) {
            gGame.mbQuitNow = true;
        }
    }

    gGame.Release();
    gGame.Destruct();

    // gNetworkManager.BootNetGui();

	return 0;
}

