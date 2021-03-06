#ifndef GT2DRENDERER_H
#define GT2DRENDERER_H

#if WIN32
#include "../../../Numeric/Math/PC/GtMathPC.h"
#include "../../../Graphical/PC/GtTexturePC.h"
using namespace GtMathPC;
#endif 

namespace Gt2dRenderer {
	enum EGt2dRendererBlend {
		eBlendNormal = 0,
		eBlendAdditive = 1,
		eBlendSubtractive = 2,
		eBlendSourceRGB = 3,
		eBlendDestAlpha = 4,
		eBlendDestAlphaAdditive = 5,
		eBlendDestAlphaSubtractive = 6,
		eBlendWriteAlpha = 7,
		eBlendNum = 8
	};
	enum EGt2dRendererFilter {
		eFilterBilinear = 0,
		eFilterNearest = 1,
		eFilterNum = 2
	};
	enum EGt2dRendererTexAddress {
		eTexAddressClamp = 0,
		eTexAddressTile = 1,
		eTexAddressClampUTileV = 2,
		eTexAddressTileUClampV = 3,
		eTexAddressNum = 4
	};

	static void Begin() {}

	static void Construct() {}

	static void EnableZTest(bool) {}

	static void End() {}

	static void RenderSpritesTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

	static void RenderSpritesUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

	static void RenderTriListFlatTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

	static void RenderTriListFlatUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

	static void RenderTriListGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*, const CGtV4d*) {}

	static void RenderTriListGouraudUntex(const CGtV2d&, int, const CGtV2d*, const CGtV4d*) {}

	static void RenderTriStripFlatTex(CGtV4d, const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

	static void RenderTriStripFlatUntex(CGtV4d, const CGtV2d&, int, const CGtV2d*) {}

	static void RenderTriStripGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

	static void RenderTriStripGouraudUntex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*) {}

	static void ResetClipRegion() {}

	static void Resume() {}

	static void SetTexture(CGtTexture*, int) {}

	static void SetZ(float, float, float) {}

	static void Suspend() {}

	static void _Dispatch() {}
}

#endif // !#define GT2DRENDERER_H
