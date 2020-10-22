#include <SDL.h>
#include <rwcore.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "../../Common/Graphics/BoGraphicsManager.h"
#include "../../../../GameShared/PC/Numeric/GtV4dPC.h"

using namespace boost::multiprecision;

extern RwInt32 lnRotate;
extern RwInt32 _gnNextBlit;
extern SDL_Renderer * renderer;

class CBlit {
public:
	static uint128_t * BuildPacket(uint32_t luScreenWidth, uint32_t luScreenHeight, uint32_t luDisplayHeight, uint32_t luBrightness, uint32_t luAlpha, uint32_t luUOffset, uint32_t luVOffset, uint64_t lu64DimX, bool lbMirror);
};

extern CBlit _gaBlit[3];
extern CBlit * _gapBlits[3];

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	
	EBoRenderableCamera meCurrentRenderableCamera;
	int manSpheremapFaceHeights_Pow2[5];
	int128_t * mpDMABuffer;
	int128_t * mpSpheremapDMAMemory;
	RwInt32 mnSpheremapDMAMemoryUsageQW;
	RwInt32 mnBlitOffsetU;
	RwInt32 mnBlitOffsetV;
	void Construct();
	void Destruct();
	void PresentDrawBuffer();
	void OpenViewport(EBoViewportSelection leViewportSelection);
	void OpenRenderWare();
	void CreateWorkBuffers();
	void RenderPalOrHdtvContrastFilter();
	void RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode);
	RwUInt32 GetVBlankCount();
};

extern CBoGraphicsManager gGraphicsManager;