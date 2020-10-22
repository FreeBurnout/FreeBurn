#include "BoFlashEffectBase.h"

void CBoFlashEffectBase::Construct() {

}

bool CBoFlashEffectBase::Prepare() {
	mPosition = CGtV2d();
	mSize = CGtV2d();
	return true;
}
