#include <rwcore.h>

#include "BoAsyncDataLoader.h"

void CBoAsyncDataLoader::Construct() {

}

void CBoAsyncDataLoader::Destruct() {

}

void CBoAsyncDataLoader::Update() {}

RwUInt32 CBoAsyncDataLoader::QueueLoadRequest(const char * lpcName, bool * lpbCompletionReturn, void * lpBuffer, RwUInt32 luReadLen) {
	return RwUInt32();
}

bool CBoAsyncDataLoader::Abort(unsigned int) {
	return false;
}

void CBoAsyncDataLoader::AbortAll() {

}

bool CBoAsyncDataLoader::IsBusy() {
	return false;
}
