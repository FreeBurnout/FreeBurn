#include "BoGraphicsManagerPC.h"
#include "../../Common/Game/BoSettings.h"
#include "../../../../GameShared/Common/System/GtSysConfig.h"

void CBoFogBase::CalculateClipPlanes(RwReal * lprNearClipOut, RwReal * lprFarClipOut, RwReal lrFogDistance) {

}

void CBoGraphicsManager::Construct() {

}

void CBoGraphicsManager::PresentDrawBuffer() {
	SDL_RenderPresent(renderer);
}

void CBoGraphicsManager::OpenViewport(EBoViewportSelection leViewportSelection) {
    float local_30;
    float local_2c;
    switch (leViewportSelection) {
    case EBoViewportSelection::Main:
        *mpCurrentViewport = mMainViewport;
        *mpCurrentViewportParams = maPlayerViewportParams[0];
        break;
    case EBoViewportSelection::Player1:
        *mpCurrentViewport = maPlayerViewports[0];
        *mpCurrentViewportParams = maPlayerViewportParams[0];
        CBoFogBase::CalculateClipPlanes(&local_30, &local_2c, maPlayerViewportParams[0].mrFogDistance);
        mpCurrentViewport->mrNearClipDistance = local_30;
        mpCurrentViewport->mrFarClipDistance = local_2c;
        RwCameraSetNearClipPlane(mpCurrentViewport->mpRwCamera, local_30);
        RwCameraSetFarClipPlane(mpCurrentViewport->mpRwCamera, local_2c);
        break;
    case EBoViewportSelection::Player2:
        *mpCurrentViewport = maPlayerViewports[1];
        *mpCurrentViewportParams = maPlayerViewportParams[1];
        CBoFogBase::CalculateClipPlanes(&local_30, &local_2c, maPlayerViewportParams[1].mrFogDistance);
        mpCurrentViewport->mrNearClipDistance = local_30;
        mpCurrentViewport->mrFarClipDistance = local_2c;
        RwCameraSetNearClipPlane(mpCurrentViewport->mpRwCamera, local_30);
        RwCameraSetFarClipPlane(mpCurrentViewport->mpRwCamera, local_2c);
        break;
    }
    RwCameraBeginUpdate(mpCurrentViewport->mpRwCamera);
    //RpSkyRenderStateSet(RwRenderState::rwRENDERSTATETEXTUREADDRESSV, &local_30);
    //(*ourGlobals._32_4_)(0x10, 1);
    //(*ourGlobals._32_4_)(0xf, 0);
}

void CBoGraphicsManager::RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode) {

}

RwUInt32 CBoGraphicsManager::GetVBlankCount() {
	return RwUInt32();
}

uint64_t _gau64Alpha1;

CBoGraphicsManager gGraphicsManager;


