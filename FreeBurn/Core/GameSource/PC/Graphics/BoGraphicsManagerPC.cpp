#include <rwcore.h>
#include <rwplcore.h>
#include <SDL_syswm.h>

#include "BoGraphicsManagerPC.h"
#include "../../Common/Game/BoSettings.h"
#include "../../../../GameShared/Common/System/GtSysConfig.h"
#include "../../Common/Menu/BoMenuChoices.h"

RwInt32 lnRotate;
RwInt32 _gnNextBlit;

void CBoFogBase::CalculateClipPlanes(RwReal * lprNearClipOut, RwReal * lprFarClipOut, RwReal lrFogDistance) {
    lrFogDistance *= 0.0003;
    float fVar1 = (float)((int)lrFogDistance * (uint32_t)(0.003 < lrFogDistance) | (uint32_t)(0.003 >= lrFogDistance) * 0x3b449ba6);
    *(uint32_t *)lprNearClipOut = (int)fVar1 * (uint32_t)(fVar1 < 0.4) | (uint32_t)(fVar1 >= 0.4) * 0x3ecccccd;
    *lprFarClipOut = 10000.0;
}

void CBoGraphicsManager::Construct() {
    meCurrentVideoMode = (EBoVideoMode)(CBoSettings::mgb50Hz << 1); // 2 if true, 0 if false.
    mpDMABuffer = nullptr;
    int * puVar4 = manSpheremapFaceHeights_Pow2;
    mbWidescreen = (bool)CGtSysConfig::GetAspectRatio();
    for (int i = 4; i > -1; i--) {
        puVar4[-10] = 0;
        puVar4[-5] = 0;
        puVar4[0] = 0;
        puVar4++;
    }
    mpSpheremapDMAMemory = nullptr;
    mnSpheremapDMAMemoryUsageQW = 0;
    OpenRenderWare();
    CreateWorkBuffers();
    ((CBoGraphicsManagerBase)*this).Construct();
    _gapBlits[0] = &_gaBlit[0];
    _gapBlits[1] = &_gaBlit[1];
    _gapBlits[2] = &_gaBlit[2];
}

void CBoGraphicsManager::Destruct() {

}

void CBoGraphicsManager::PresentDrawBuffer() {
    uint32_t uVar4;
    if (gMenuChoices.mn8ContrastFilterOn) {
        RenderPalOrHdtvContrastFilter();
    }
    int iVar1 = lnRotate + 1;
    int iVar6 = lnRotate + (1 << ((iVar1 <= -1) << 1));
    lnRotate = iVar1 + (iVar6 >> 2) * -4;
    uint32_t * puVar2 = (uint32_t *)&_gapBlits + _gnNextBlit;
    float fVar3 = maPlayerViewportParams[0].mrMotionBlur * 96.0;
    float fVar5 = maPlayerViewportParams[0].mrBrightness * 256.0 + 0.5;
    if ((char)((uint32_t)fVar3 >> 0x17) < 0x9e) {
        iVar6 = (int)fVar3;
    } else {
        iVar6 = 0x7fffffff + !!fVar3; // iVar6 is 0x80000000 if true, else 0x7FFFFFFF
    }
    if ((char)((uint32_t)fVar5 >> 0x17) < 0x9e) {
        uVar4 = (uint32_t)fVar5;
    } else {
        uVar4 = 0x7fffffff + !!fVar5;
    }
    if (uVar4 > 0xff) {
        uVar4 = 0xff;
    }
    _gnNextBlit = (_gnNextBlit + 1) % 3;
    // _rwDMAFlipData._960_4_ = CBlit::BuildPacket(*puVar2 | 0x30000000, mnScreenWidth, mnScreenHeight, mnDisplayHeight, uVar4, 0x80 - iVar6, mnBlitOffsetU, (long)mnBlitOffsetV, SUB81(*(undefined8 *)(lau64DimXA.9559 + lnRotate.9560 * 8), 0));
    // _rwDMAFlipData._964_4_ = _rwDMAFlipData._960_4_;
    // _rwDMAFlipData._968_4_ = _rwDMAFlipData._960_4_;
    // _rwDMAFlipData._972_4_ = _rwDMAFlipData._960_4_;

    // TODO PUT THIS SOMEWHERE BETTER
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(window, &wmInfo);
    HWND hwnd = wmInfo.info.win.window;

    RwCameraShowRaster(mMainViewport.mpRwCamera, hwnd, 1);
    SDL_RenderPresent(renderer);
}

void CBoGraphicsManager::OpenViewport(EBoViewportSelection leViewportSelection) {
    float lrNearClipPlane;
    float lrFarClipPlane;
    *mpCurrentViewportParams = maPlayerViewportParams[(int)leViewportSelection >> 1];
    if (leViewportSelection == EBoViewportSelection::Main) {
        *mpCurrentViewport = mMainViewport;
    } else {
        *mpCurrentViewport = maPlayerViewports[(int)leViewportSelection >> 1];
        CBoFogBase::CalculateClipPlanes(&lrNearClipPlane, &lrFarClipPlane, maPlayerViewportParams[(int)leViewportSelection >> 1].mrFogDistance);
        mpCurrentViewport->mrNearClipDistance = lrNearClipPlane;
        mpCurrentViewport->mrFarClipDistance = lrFarClipPlane;
        RwCameraSetNearClipPlane(mpCurrentViewport->mpRwCamera, lrNearClipPlane);
        RwCameraSetFarClipPlane(mpCurrentViewport->mpRwCamera, lrFarClipPlane);
    }
    RwCameraBeginUpdate(mpCurrentViewport->mpRwCamera);
    RwRenderStateSet(RwRenderState::rwRENDERSTATETEXTUREADDRESSV, &lrNearClipPlane);
    RwStandardFunc(1);
    RwCameraBeginUpdate(nullptr);
}

void CBoGraphicsManager::OpenRenderWare() {
}

void CBoGraphicsManager::CreateWorkBuffers() {
}

void CBoGraphicsManager::RenderPalOrHdtvContrastFilter() {
}

void CBoGraphicsManager::RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode) {

}

RwUInt32 CBoGraphicsManager::GetVBlankCount() {
	return RwUInt32();
}

CBlit _gaBlit[3];
CBlit * _gapBlits[3];
uint64_t _gau64Alpha1;

CBoGraphicsManager gGraphicsManager;

uint128_t * CBlit::BuildPacket(uint32_t luScreenWidth, uint32_t luScreenHeight, uint32_t luDisplayHeight, uint32_t luBrightness, uint32_t luAlpha, uint32_t luUOffset, uint32_t luVOffset, uint64_t lu64DimX, bool lbMirror) {
    return nullptr;
}
