#include "BoHUDComponent.h"

void CBoHUDComponent::Construct() {}

bool CBoHUDComponent::Prepare() {
    return false;
}

void CBoHUDComponent::Update() {}

void CBoHUDComponent::Construct(CBoHUDManager*) {}

bool CBoHUDComponent::Prepare(int, int, int, EPlayerCarIndex, EHUDAlign, int) {
    return false;
}

void CBoHUDComponent::UpdateTransition(float, bool, EHUDMode, EHUDMode) {}

void CBoHUDComponent::SetAllLayerVisible(bool) {}

void CBoHUDComponent::StartTransition(bool, EHUDMode, EHUDMode) {}

void CBoHUDComponent::AdjustScalingForSplitScreen() {}

void CBoHUDComponent::UseClipFrame() {}

Gt2dRenderer::CGt2dScene* CBoHUDComponent::GetScene() {
    return nullptr;
}

COutlineDropShadow* CBoHUDComponent::GetOutlineDropShadow(CBoHUDComponent, EOutlineDropShadow) {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetHUDTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetBoostFireCoreTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetBoostFireEdgeTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetBoostFireOverTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetBoostBitsTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetBoostBlueFlameTexture() {
    return nullptr;
}

CGtTexture* CBoHUDComponent::GetHUDTexture(CBoHUDComponent, EHUDTexture) {
    return nullptr;
}

RwInt32 CBoHUDComponent::GetFlags() {
    return RwInt32();
}

EHUDAlign CBoHUDComponent::GetAlign() {
    return EHUDAlign();
}

CGtTexture* CBoHUDComponent::GetBoostStarsTexture() {
    return nullptr;
}

GtUTF16* CBoHUDComponent::GetHUDString(EBoHUDString leHUDString) {
    return nullptr;
}

EPlayerCarIndex CBoHUDComponent::GetPlayerCarIndex() {
    return EPlayerCarIndex();
}
