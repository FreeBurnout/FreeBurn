#include "../PC/BoGraphicsManagerPC.h"
#include "../../HUD/BoHUDComponent.h"
#include "../../HUD/BoHUDText2dObject.h"
#include "../../Game/Common/BoGame.h"
#include "../../Game/Common/BoLanguageManager.h"
#include "../../Network/Common/BoNetworkManager.h"
#include "../../../Shared/Numeric/Math/PC/GtMathPC.h"
#include "../../../Shared/Graphical/Common/2D/Gt2dRenderer.h"

using namespace GtMathPC;

CBoGraphicsManager gGraphicsManager;

GtUTF16 kaaLoadingStrings[][8] = {
	u"LOADING"
};

void CBoGraphicsManagerBase::CloseViewport() {}

void CBoGraphicsManagerBase::Downsample(RwUInt32 luFrameBufferAddress, RwUInt32 luFrameBufferWidth, RwUInt32 luWorkspaceAddress, RwUInt32 luWorkspaceWidth, RwInt32 lnTopLeftX, RwInt32 lnTopLeftY, RwInt32 lnSizeX, RwInt32 lnSizeY) {

}

RwReal lrFull = 0;
void CBoGraphicsManagerBase::DrawBootLoadingScreen(RwReal lrProgress) {
	float fStack244 = 0;
	float fStack248 = 0;
	float fStack252 = 0;
	float fStack260 = 0;
	float fStack264 = 0;
	float fStack268 = 0;
	float fStack324 = 0;
	float fStack328 = 0;
	float fStack332 = 0;
	float fStack340 = 0;
	float fStack388 = 0;
	float fStack392 = 0;
	float fStack396 = 0;
	float fStack404 = 0;
	float fStack408 = 0;
	float fStack412 = 0;
	float fStack436 = 0;
	float fStack440 = 0;
	float fStack444 = 0;
	float fStack452 = 0;
	float fStack456 = 0;
	float fStack460 = 0;
	float fStack468 = 0;
	float fStack472 = 0;
	float fStack476 = 0;
	float fStack500 = 0;
	
	float fVar2;
	float fVar8;
	float fVar12;

	float local_150 = 0;
	float local_158 = 0;
	float local_15c = 0;
	float local_160 = 0;
	float local_190 = 0;
	float local_1a0 = 0;

	float local_1f8 = 0;
	float local_1fc = 0;
	float local_200 = 0;

	float scrnXScale = gGraphicsManager.mnScreenWidth / 640;
	float scrnYScale = gGraphicsManager.mnScreenHeight / 480;
	 
	CGtV4d unkVec99 = CGtV4d(0, 0, 0.5, 1); 
	CGtV4d unkVec0 = CGtV4d(0.5, 0.5, 0.5, 1.0);

	CGtV4d unkVec1; // 1f0, 492, 488, 484

	float* local_120 = &local_200;
	float* local_11c = &local_1f8;
	CGtV2d* local_118 = &(CGtV2d)(unkVec1);

	if (lrFull < lrProgress) {
		lrFull = lrProgress;
	}

	if (gGame.mbInputManagerPrepared && !gNetworkManager.mbUppingInterface) {
		gGame.mInputManager.Update();
		gGame.mInputManager.UpdateFE();
	}

	CGtV4d local_1b0 = CGtV4d(0, 0, 0, 0);
	RwCameraClear(gGraphicsManager.mMainViewport.mpRwCamera, (RwRGBA*)&local_1b0, 3);
	gGraphicsManager.OpenViewport(eBoViewportMain);
	Gt2dRenderer::Begin();

	if (gLanguageManager.mbIsBigFontLoaded) {
		local_1b0 = CGtV4d(400, 320, 0, 0);

		for (int i = sizeof(kaaLoadingStrings) - 1; i > -1; i--) {
			if (*kaaLoadingStrings[i] == L'\0') {
				continue;
			}

			CBoHUDText2dObject::Prepare(local_1b0, kHUDV2d_HalfHalf, 26.f, CBoHUDText2dObject::eStyleBigMessage, kaaLoadingStrings[i]);

			float local_160 = local_1a0 * scrnXScale;
			float local_15c = fStack412 * scrnYScale;
			float local_158 = fStack408 * scrnXScale;
			float fStack340 = fStack404 * scrnYScale;

			CGtV2d local_140 = CGtV2d(local_158, fStack340);

			float fStack324 = fStack388 * unkVec0[0];
			float fStack328 = fStack392 * unkVec0[1];
			float fStack332 = fStack396 * unkVec0[2];
			float local_150 = local_190 * unkVec0[3];

			local_1b0[1] -= 34.0;
		}
	}

	local_1b0.z = 0.91;
	local_1b0.w = 0.97;

	CGtV4d unkVec5 = CGtV4d(); // 516, 208, 20c, 210

	unkVec5[0] = scrnXScale * 400.0;
	unkVec5[1] = scrnYScale * 420.0;
	unkVec5[2] = scrnXScale * 240.0;
	unkVec5[3] = scrnYScale * 435.0;

	fVar12 = 423.75;

	local_1b0 = CGtV4d(unkVec5[0], unkVec5[3], 0, 1.0);

	Gt2dRenderer::RenderSpritesUntex(unkVec99, CGtV2d(1.0, 0.5),  1, &CGtV2d(unkVec5));

	unkVec5[0] = (400.0 - 1.0 / scrnXScale) * scrnXScale;
	unkVec5[1] = (1.0 / scrnYScale + 420.0) * scrnYScale;
	unkVec5[2] = (1.0 / scrnXScale + 240.0) * scrnXScale;
	unkVec5[3] = (435.0 - 1.0 / scrnYScale) * scrnYScale;

	local_1b0.x = unkVec5[3];
	local_1b0.y = unkVec5[0];

	Gt2dRenderer::RenderSpritesUntex((CGtV4d)0, unkVec99, 1, &(CGtV2d)unkVec5);

	unkVec1[0] = CBoHUDText2dObject::mgDarkTextColour[0] * unkVec0[3];
	unkVec1[1] = CBoHUDText2dObject::mgDarkTextColour[1] * unkVec0[2];
	unkVec1[2] = CBoHUDText2dObject::mgDarkTextColour[2] * unkVec0[1];
	unkVec1[3] = CBoHUDText2dObject::mgDarkTextColour[3] * unkVec0[0];

	CGtV4d unkVec4; // 1e0, 476, 472, 468

	unkVec4[0] = CBoHUDText2dObject::mgLightTextColour[0] * unkVec0[3];
	unkVec4[1] = CBoHUDText2dObject::mgLightTextColour[1] * unkVec0[2];
	unkVec4[2] = CBoHUDText2dObject::mgLightTextColour[2] * unkVec0[1];
	unkVec4[3] = CBoHUDText2dObject::mgLightTextColour[3] * unkVec0[0];

	unkVec5[0] = 2.0 / scrnXScale + 240.0;
	local_1f8 = 2.0 / scrnXScale + 240.0 + lrFull * (160.0 - 4.0 / scrnXScale);
	local_11c[1] = fVar12;

	unkVec5[1] = (2.0 / scrnYScale + 420.0) * scrnYScale;
	unkVec5[2] = unkVec5[0] * scrnXScale;
	unkVec5[3] = fVar12 * scrnYScale;
	unkVec5[0] *= scrnXScale;

	local_200 = local_1f8 * scrnXScale;
	local_1fc = (2.0 / scrnYScale + 420.0) * scrnYScale;
	local_1f8 *= scrnXScale;
	fStack500 *= scrnYScale;

	local_1b0.x = fStack500;
	local_1b0.y = local_1f8;

	CGtV4d unkVec7 = unkVec1;
	CGtV4d unkVec8 = unkVec4;
	CGtV4d unkVec3 = unkVec4; // 110, 268, 264, 260
	CGtV4d unkVec6 = unkVec1; // 100, 252, 248, 244

	Gt2dRenderer::RenderTriStripGouraudUntex(unkVec99, 4, (CGtV2d*)&unkVec5[2], local_118);
	fVar2 = lrFull;

	unkVec7 = unkVec3;
	unkVec8 = unkVec6;
	unkVec1 = unkVec3;
	unkVec4 = unkVec6;

	float fVar7 = 2.0 / scrnXScale + 240.0;
	fVar8 = lrFull * (160.0 - 4.0 / scrnXScale);
	local_120[1] = fVar12;

	unkVec5[0] = fVar7 * scrnXScale;
	unkVec5[1] = fVar12 * scrnYScale;
	unkVec5[2] = (2.0 / scrnXScale + 240.0) * scrnXScale;
	unkVec5[3] = (435.0 - 2.0 / scrnYScale) * scrnYScale;

	local_200 = (fVar7 + fVar8) * scrnXScale;
	local_1fc *= scrnYScale;

	local_1b0.x = unkVec5[3];
	local_1b0.y = (2.0 / scrnXScale + 240.0 + fVar2 * (160.0 - 4.0 / scrnXScale)) * scrnXScale;

	Gt2dRenderer::RenderTriStripGouraudUntex(unkVec99, 4, &CGtV2d(unkVec5), local_118);
	Gt2dRenderer::End();

	if (lrFull < 1.0) {
		lrFull += (1.0 - lrFull) * 0.009;
	}

	gGraphicsManager.CloseViewport();
}

void CBoGraphicsManagerBase::OpenViewport(EBoViewportSelection) {

}
