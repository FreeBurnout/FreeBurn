#include "../PC/BoGraphicsManagerPC.h"
#include "../../Game/Common/BoGame.h"
#include "../../Game/Common/BoLanguageManager.h"
#include "../../HUD/BoHUDText2dObject.h"
#include "../../Network/Common/BoNetworkManager.h"
#include "../../../Shared/Graphical/Common/2D/Gt2dScene.h"

CBoGraphicsManager gGraphicsManager;

GtUTF16 kaaLoadingStrings[][8] = {
	u"LOADING"
};

void CBoGraphicsManagerBase::Downsample(RwUInt32 luFrameBufferAddress, RwUInt32 luFrameBufferWidth, RwUInt32 luWorkspaceAddress, RwUInt32 luWorkspaceWidth, RwInt32 lnTopLeftX, RwInt32 lnTopLeftY, RwInt32 lnSizeX, RwInt32 lnSizeY) {
}

void CBoGraphicsManagerBase::DrawBootLoadingScreen(RwReal lrProgress) {
    bool bVar1;
    float fVar2;
    int iVar3;
    GtUTF16* pwVar4;
    undefined8 unaff_s0;
    undefined8 unaff_s1;
    undefined8 unaff_s2;
    undefined8 unaff_s3;
    undefined8 unaff_s4;
    undefined8 unaff_s5;
    undefined8 unaff_s6;
    undefined8 unaff_s7;
    undefined8 unaff_s8;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    undefined4 local_220;
    undefined4 local_21c;
    undefined4 local_218;
    undefined4 local_214;
    float local_210;
    float local_20c;
    float local_208;
    float fStack516;
    float local_200;
    float local_1fc;
    float local_1f8;
    float fStack500;
    float local_1f0;
    float fStack492;
    float fStack488;
    float fStack484;
    float local_1e0;
    float fStack476;
    float fStack472;
    float fStack468;
    float local_1d0;
    float fStack460;
    float fStack456;
    float fStack452;
    float local_1c0;
    float fStack444;
    float fStack440;
    float fStack436;
    CGtV4d local_1b0;
    undefined4 local_1a8;
    undefined4 local_1a4;
    float local_1a0;
    float fStack412;
    float fStack408;
    float fStack404;
    float local_190;
    float fStack396;
    float fStack392;
    float fStack388;
    undefined auStack384[28];
    code* local_164;
    float local_160;
    float local_15c;
    float local_158;
    float fStack340;
    float local_150;
    float fStack332;
    float fStack328;
    float fStack324;
    undefined8 local_140;
    float local_130;
    float fStack300;
    float fStack296;
    float fStack292;
    float* local_120;
    float* local_11c;
    float* local_118;
    float local_110;
    float fStack268;
    float fStack264;
    float fStack260;
    float local_100;
    float fStack252;
    float fStack248;
    float fStack244;

    fVar5 = gGraphicsManager.mnScreenWidth * 0.0015625; // Ratio to 640, 
    fVar6 = gGraphicsManager.mnScreenHeight * 0.00208333333; // Ratio to 480
    local_218 = 0.5;
    local_214 = 1.0;
    local_220 = 0;
    local_130 = 0.5;
    fStack300 = 0.5;
    fStack296 = 0.5;
    fStack292 = 1.0;
    local_11c = &local_1f8;
    local_21c = 0;
    local_118 = &local_1f0;
    local_120 = &local_200;

    RwReal lrFull = 0;

    if (lrFull < lrProgress) {
        lrFull = lrProgress;
    }

    if (gGame.mbInputManagerPrepared && !gNetworkManager.mbUppingInterface) {
        gGame.mInputManager.Update();
        gGame.mInputManager.UpdateFE();
    }

    RwCameraClear(gGraphicsManager.mMainViewport.mpRwCamera, 0, 3);
    OpenViewport(eBoViewportMain);
    Gt2dRenderer::Begin();
    if (gLanguageManager.mbIsBigFontLoaded) {
        pwVar4 = kaaLoadingStrings[0];
        local_1b0.mData[0] = 320.0;
        local_1b0.mData[1] = 400.0;
        for (int i = 0; i > -1; i--) {
            if (*pwVar4 != u'\0') {
                CBoHUDText2dObject::Prepare(0x41d00000, &local_1a0, &local_1b0, 0x1c2d740, CBoHUDText2dObject::eStyleBigMessage, pwVar4);
                local_158 = fStack408 * fVar5;
                fStack340 = fStack404 * fVar6;
                local_160 = local_1a0 * fVar5;
                local_15c = fStack412 * fVar6;
                local_140 = CONCAT44(fStack340, local_158);
                local_150 = local_190 * local_130;
                fStack332 = fStack396 * fStack300;
                fStack328 = fStack392 * fStack296;
                fStack324 = fStack388 * fStack292;
                (*local_164)(&local_160, auStack384);
                local_1b0._4_4_ -= 34.0;
            }
            pwVar4 += 0x10;
        }
    }
    local_1a8 = 0.91;
    local_1a4 = 0.97;
    fVar10 = 240.0;
    fVar9 = 2.0;
    local_208 = fVar5 * 400.0;
    fStack516 = fVar6 * 435.0;
    local_210 = fVar5 * 240.0;
    fVar12 = 423.75;
    local_20c = fVar6 * 420.0;
    local_1b0 = CONCAT44(fStack516, local_208);
    Gt2dRenderer::RenderSpritesUntex(0x3f4000003f800000, &local_220, 1, &local_210);
    local_1a8 = 0;
    local_1a4 = 1.0;
    fVar11 = 160.0;
    local_208 = (400.0 - 1.0 / fVar5) * fVar5;
    fStack516 = (435.0 - 1.0 / fVar6) * fVar6;
    local_210 = (1.0 / fVar5 + fVar10) * fVar5;
    local_20c = (1.0 / fVar6 + 420.0) * fVar6;
    local_1b0 = CONCAT44(fStack516, local_208);
    Gt2dRenderer::RenderSpritesUntex(0, &local_220, 1, &local_210);
    local_1f0 = _18CB4HUDText2dObject$mgDarkTextColour._0_4_ * local_130;
    fStack492 = _18CB4HUDText2dObject$mgDarkTextColour._4_4_ * fStack300;
    fStack488 = _18CB4HUDText2dObject$mgDarkTextColour._8_4_ * fStack296;
    fStack484 = _18CB4HUDText2dObject$mgDarkTextColour._12_4_ * fStack292;
    local_1e0 = _18CB4HUDText2dObject$mgLightTextColour._0_4_ * local_130;
    fStack476 = _18CB4HUDText2dObject$mgLightTextColour._4_4_ * fStack300;
    fStack472 = _18CB4HUDText2dObject$mgLightTextColour._8_4_ * fStack296;
    fStack468 = _18CB4HUDText2dObject$mgLightTextColour._12_4_ * fStack292;
    local_208 = fVar9 / fVar5 + fVar10;
    local_1f8 = fVar9 / fVar5 + fVar10 + lrFull * (fVar11 - 4.0 / fVar5);
    local_11c[1] = fVar12;
    local_210 = local_208 * fVar5;
    local_20c = (fVar9 / fVar6 + 420.0) * fVar6;
    local_208 = local_208 * fVar5;
    fStack516 = fVar12 * fVar6;
    local_200 = local_1f8 * fVar5;
    local_1fc = (fVar9 / fVar6 + 420.0) * fVar6;
    local_1f8 = local_1f8 * fVar5;
    fStack500 = fStack500 * fVar6;
    local_1b0 = CONCAT44(fStack500, local_1f8);
    local_1d0 = local_1f0;
    fStack460 = fStack492;
    fStack456 = fStack488;
    fStack452 = fStack484;
    local_1c0 = local_1e0;
    fStack444 = fStack476;
    fStack440 = fStack472;
    fStack436 = fStack468;
    local_110 = local_1e0;
    fStack268 = fStack476;
    fStack264 = fStack472;
    fStack260 = fStack468;
    local_100 = local_1f0;
    fStack252 = fStack492;
    fStack248 = fStack488;
    fStack244 = fStack484;

    Gt2dRenderer::RenderTriStripGouraudUntex(&local_220, 4, &local_210, local_118);
    fVar2 = lrFull;
    local_1d0 = local_110;
    fStack460 = fStack268;
    fStack456 = fStack264;
    fStack452 = fStack260;
    local_1c0 = local_100;
    fStack444 = fStack252;
    fStack440 = fStack248;
    fStack436 = fStack244;
    local_1f0 = local_110;
    fStack492 = fStack268;
    fStack488 = fStack264;
    fStack484 = fStack260;
    local_1e0 = local_100;
    fStack476 = fStack252;
    fStack472 = fStack248;
    fStack468 = fStack244;
    fVar7 = fVar9 / fVar5 + fVar10;
    fVar8 = lrFull * (fVar11 - 4.0 / fVar5);
    local_120[1] = fVar12;
    local_210 = (fVar9 / fVar5 + fVar10) * fVar5;
    local_208 = fVar7 * fVar5;
    local_20c = fVar12 * fVar6;
    fStack516 = (435.0 - fVar9 / fVar6) * fVar6;
    fStack500 = (435.0 - fVar9 / fVar6) * fVar6;
    local_200 = (fVar7 + fVar8) * fVar5;
    local_1fc = local_1fc * fVar6;
    local_1f8 = (fVar9 / fVar5 + fVar10 + fVar2 * (fVar11 - 4.0 / fVar5)) * fVar5;
    local_1b0 = CONCAT44(fStack500, local_1f8);

    Gt2dRenderer::RenderTriStripGouraudUntex(&local_220, 4, &local_210, local_118);
    Gt2dRenderer::End();
    if (lrFull < 1.0) {
        lrFull += (1.0 - lrFull) * 0.009;
    }
    gGraphicsManager.CloseViewport();
}

void CBoGraphicsManagerBase::OpenViewport(EBoViewportSelection) {
}
