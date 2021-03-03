#include "../Common/2D/Gt2dScene.h"
#include "../../Numeric/Math/PC/GtMathPC.h"
#include "GtTexturePC.h"

static void Gt2dRenderer::Begin() {}

void Gt2dRenderer::Construct() {}

void Gt2dRenderer::EnableZTest(bool) {}

void Gt2dRenderer::End() {}

void Gt2dRenderer::RenderSpritesTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

void Gt2dRenderer::RenderSpritesUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

void Gt2dRenderer::RenderTriListFlatTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

void Gt2dRenderer::RenderTriListFlatUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

void Gt2dRenderer::RenderTriListGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*, const CGtV4d*) {}

void Gt2dRenderer::RenderTriListGouraudUntex(const CGtV2d&, int, const CGtV2d*, const CGtV4d*) {}

void Gt2dRenderer::RenderTriStripFlatTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

void Gt2dRenderer::RenderTriStripFlatUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

void Gt2dRenderer::RenderTriStripGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

void Gt2dRenderer::RenderTriStripGouraudUntex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

void Gt2dRenderer::ResetClipRegion() {}

void Gt2dRenderer::Resume() {}

void Gt2dRenderer::SetTexture(CGtTexture*, int) {}

void Gt2dRenderer::SetZ(float, float, float) {}

void Gt2dRenderer::Suspend() {}

void Gt2dRenderer::_Dispatch() {}
