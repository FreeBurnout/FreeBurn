#include <rwcore.h>

#include "BoFlashEffectBase.h"

enum class EFlameState {
	None = 0, 
	RampUp = 1, 
	Constant = 2, 
	RampDown = 3,
	Done = 4, 
	Max = 5
};

class CBoFlamingIcon : CBoFlashEffectBase {
	RwReal mrAnimationTime;
	RwReal mrCurrentTime;
	CGtV2d mDrawSize;
	CGtV2d mDrawSizeDiff;
	RwInt32 mnNumFramesRampUp;
	RwInt32 mnNumFramesRampDown;
	RwInt32 mnFrame;
	EFlameState meFlameState;
};