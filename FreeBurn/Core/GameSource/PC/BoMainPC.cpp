#include <iostream>
#include <SDL.h>
#include "Graphics/BoGraphicsManagerPC.h"
#include "../Common/Game/BoGame.h"
#include "../../../GameShared/PC/System/GtThreadMgrPC.h"
#include <spdlog\spdlog.h>

SDL_Window * window = SDL_CreateWindow("FreeBurn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

void __main() {
    
}

int main(int argc, char * argv[]) {
    __main();

    gGame.Construct();

    gGraphicsManager.DrawBootLoadingScreen(-1.0);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1.0);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1.0);
    gGraphicsManager.PresentDrawBuffer();
    gGraphicsManager.DrawBootLoadingScreen(-1.0);
    gGraphicsManager.PresentDrawBuffer();

    while (!gGame.Prepare()) {
        CGtThreadMgr::SleepThreadTillVBlank();
        gGraphicsManager.DrawBootLoadingScreen(-1.0);
        gGraphicsManager.PresentDrawBuffer();
    }

    //DbVariableRegisterString(gBuildString, "Build", "ID");

    while (!gGame.mbQuitNow) {
        gGame.Update();
        for (int i = 14; i > -1; i--) {
            
        }
    }

    gGame.Release();
    gGame.Destruct();

    return 0;
}