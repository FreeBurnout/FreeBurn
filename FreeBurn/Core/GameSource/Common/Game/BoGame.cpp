#include "BoGame.h"
#include "../Game/BoMemoryCardManager.h"
#include "../Game/BoDebugManager.h"
#include "../Graphics/BoGraphicsManager.h"
#include "../Menu/BoFlashMovieManager.h"
#include "../Network/BoNetworkManager.h"
#include "../Sound/BoSoundManager.h"
#include "../World/BoBurn.h"
#include "../World/BoWorld.h"
#include "../../PC/Graphics/BoGraphicsManagerPC.h"
#include "../../../../GameShared/Common/System/GtFSM.h"
#include "../../../../GameShared/PC/System/GtHiResSystemTimerPC.h"
#include "../../../../GameShared/PC/System/GtThreadMgrPC.h"

CBoPCMemoryBuffers _gMemoryBlock;
CBoPCMemoryBuffers * _gpWholeMemoryBlock;
CBoGame gGame;
CGtRandom gRandom;

void CBoGame::Destruct() {
	mAsyncDataLoader.Destruct();
	((CBoGraphicsManagerBase)gGraphicsManager).Destruct();
	gSoundManager.Destruct();
	gDebugManager.Destruct();
	gFlashMovieManager.Destruct();
	gWorld.Destruct();
	gMenuFlowManager.Destruct();
	gNetworkManager.Destruct();
	Destruct();
	mbQuitNow = false;
	mpCurrentGameMode = nullptr;
	mpRequestedGameMode = nullptr;
	// (**(code **)(*(int *)(this + 0x22394) + 0x14))(this + (int)*(short *)(*(int *)(this + 0x22394) + 0x10) + 0x22380);
	// (**(code **)(*(int *)(this + 0x242d4) + 0x14))(this + (int)*(short *)(*(int *)(this + 0x242d4) + 0x10) + 0x242c0);
	mSettings.Destruct();
	gMemoryManager.Destruct();
	CGtHiResSystemTimer::Destruct();
	meRequestedUpdateState = EGtGameUpdateState::Destructed;
	meUpdateState = EGtGameUpdateState::Destructed;
	CGtThreadMgr::DisableVBlankWait();
	CGtThreadMgr::Close();
}

void CBoGame::Release() {
	CBoBurn::UnregisterStaticVariables();
	CBoRumbleAttribs::UnregisterStaticVariables();
	CBoStageLogic::UnRegisterStaticVariables();
	gNetworkManager.Release();
	gSoundManager.Release();
	Release();
	meRequestedUpdateState = EGtGameUpdateState::Released;
	meUpdateState = EGtGameUpdateState::Released;
	if (mpCurrentGameMode != nullptr) {
		//(*(int *)(iVar1 + 0xc) + 0x2c))(iVar1 + *(short *)(*(int *)(iVar1 + 0xc) + 0x28));
	}
	gFlashMovieManager.Release();
	gBoMemCardManager.Release();
}

void CBoGame::Render() {

}

bool CBoGame::Prepare() {
	return true;
}

void CGtRandom::SetSeed(RwUInt32 luSeed) {
	mnHigh = ~luSeed;
	mnLow = luSeed;
}