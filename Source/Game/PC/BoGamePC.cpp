#include "../Common/BoGame.h"

void CBoGame::ConstructHardware() {

}

bool CBoGame::PrepareHardware() {
	return false;
}

void CBoGame::CheckPowerOff() {

}

void PowerOffHandler(void* lpArgs) {

}

void CBoGame::PreparePowerOff() {

}

bool CBoGame::CheckFatalDiskError() {
	return false;
}

void CBoGame::SetFrontendFrameRate(bool) {

}

void CBoGame::SetQuitNow() {

}

bool CBoGame::WillQuitNow() {
	return false;
}

CBoGame gGame;