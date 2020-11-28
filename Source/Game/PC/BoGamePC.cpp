#include "../Common/BoGame.h"

void CBoGame::ConstructHardware() {

}

bool CBoGame::PrepareHardware() {
	return false;
}

void CBoGame::CheckPowerOff() {

}

void PowerOffHandler(void * lpArgs) {

}

void CBoGame::PreparePowerOff() {

}

bool CBoGame::CheckFatalDiskError() {
	return false;
}

void CBoGame::SetFrontendFrameRate(bool) {

}

void CBoGame::BootNFLStreet2Demo() {
    long lVar1;
    int iVar2;

    while (lVar1 < 0) {
        lVar1 = sceDevctl(0x48c460, 0x4402, 0, 0, 0, 0);
        if (lVar1 == -0x13) break;
    }
    gaacArgumentArray = gacElfFileName;
    iVar2 = 0x14;
    while (iVar2 > 0) {
        iVar2 = iVar2 + -1;
        _rwDMAForceBufferSwap();
        _rwDMAWaitQueue();
        sceGsSyncV(0);
        sceGsSyncV(0);
    }
    sceCdInit(5);
    sceSifExitCmd();
    LoadExecPS2(0x48c488, 1, 0x54ad30);
}

void CBoGame::SetQuitNow() {

}

bool CBoGame::WillQuitNow() {
	return false;
}

void CBoGame::SetBootNFLStreet2DemoNow() {

}

bool CBoGame::WillBootNFLStreet2DemoNow() {
	return false;
}