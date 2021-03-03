#ifndef BOFLAMINGICON_H
#define BOFLAMINGICON_H

#include <rwcore.h>

#include "BoFlashEffectBase.h"
#include "../../../Shared/Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

enum EFlameState {
	eFlameStateNone = 0, 
	eFlameStateRampUp = 1,
	eFlameStateConstant = 2,
	eFlameStateRampDown = 3,
	eFlameStateDone = 4,
	eFlameStateMax = 5
};

class CBoFlamingIcon : CBoFlashEffectBase {
public:
	RwReal mrAnimationTime;
	RwReal mrCurrentTime;
	CGtV2d mDrawSize;
	CGtV2d mDrawSizeDiff;
	RwInt32 mnNumFramesRampUp;
	RwInt32 mnNumFramesRampDown;
	RwInt32 mnFrame;
	EFlameState meFlameState;

	void Prepare(int param);
};

#endif // !#define BOFLAMINGICON_H