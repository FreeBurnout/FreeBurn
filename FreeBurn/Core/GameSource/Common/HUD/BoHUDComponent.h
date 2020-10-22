#pragma once

#include "BoHUDManager.h"
#include "../../../../GameShared/Common/Graphical/2D/Gt2dObject.h"
#include "../../../../GameShared/Common/Numeric/Math/Generic/GtV2dGeneric.h"
#include "../../../../GameShared/PC/Graphical/GtTexturePC.h"

extern CGtV2d kHUDV2d_ZeroZero;

class CBoHUDComponent {
public:
	CGtTexture * mpBoostBlueFlameTexture;
	CBoHUDManager * mpHUDManager;
};

class CBoHUDTrafficAttackBar {
public:
	void Update(float param);
};

class CBoHUDTrafficAttackBar2dObject : CGt2dObject {
public:
	void Update(float param);
};