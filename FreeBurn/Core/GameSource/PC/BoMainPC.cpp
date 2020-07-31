#include "Graphics/BoGraphicsManagerPC.h"
#include "../Common/Game/BoGame.h"
#include "../../../GameShared/PC/System/GtThreadMgrPC.h"

void __main() {

}

int main() {
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