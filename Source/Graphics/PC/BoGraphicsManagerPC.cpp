#include "BoGraphicsManagerPC.h"
#include "../../../Shared/Numeric/Math/PC/GtMathPC.h"

void CBoGraphicsManager::PresentDrawBuffer() {
}

void CBoGraphicsManager::ReleaseSpheremapWarpData() {}

void CBoGraphicsManager::RelockAllLockedRasters() {}

void CBoGraphicsManager::RenderFullScreenBrightnessFilter(float) {}

void CBoGraphicsManager::RenderFullScreenPass(CGtV4d, EBoFullScreenPassBlendMode) {}

void CBoGraphicsManager::RenderFullScreenSpecular(CGtV3d, float) {}

void CBoGraphicsManager::RenderPalOrHdtvContrastFilter() {}

void CBoGraphicsManager::SetVideoMode(EBoVideoMode) {}

void CBoGraphicsManager::SetVideoModeParams(RwVideoMode*) {}

void CBoGraphicsManager::OpenViewport(EBoViewportSelection) {

}

bool CBoGraphicsManager::Prepare() {
    return false;
}

bool CBoGraphicsManager::PrepareSpheremapWarpData() {
    return false;
}

void CBoGraphicsManager::BuildCustomCameraData(ERaceCarIndex) {}

void CBoGraphicsManager::BuildFrontEndSphereMapData() {}

void CBoGraphicsManager::BuildInGameSphereMapData() {}

void CBoGraphicsManager::ClearOffscreenBuffer(RwUInt32 luBufferID) {}

void CBoGraphicsManager::ClearScreen() {

}

void CBoGraphicsManager::Construct() {}

void CBoGraphicsManager::CreateWorkBuffers() {}

void CBoGraphicsManager::DistortEnvmapBuffersIntoSphereMap() {}

RwUInt32 CBoGraphicsManager::GetVBlankCount() {
    return RwUInt32();
}

void CBoGraphicsManager::OpenRenderWare() {}
