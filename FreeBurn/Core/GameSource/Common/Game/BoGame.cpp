#include "BoGame.h"
#include "../../../../GameShared/Common/System/GtFSM.h"

void CBoGame::Destruct() {

}

void CBoGame::Release() {

}

bool CBoGame::Prepare() {
	return true;
}

void CGtRandom::SetSeed(RwUInt32 luSeed) {

}

void CBoMemoryManager::Construct() {

}

CBoGame gGame;
CGtRandom gRandom;