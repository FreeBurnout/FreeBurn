#include <boost/multiprecision/cpp_int.hpp>
#include <cstdint>
#include <rwcore.h>
#include "../../../PC/Graphical/GtTexturePC.h"
#include "../../../PC/Numeric/GtV4dPC.h"

using namespace boost::multiprecision;

namespace Gt2dRenderer {
	RwUInt32 * _gpuNLoops; 
	uint128_t _gau128Buffer[510];
	RwUInt64 * _gpu64Current;
	RwInt32 _guCurrentPrimType;
	uint64_t _gau64PrimRegs[10];
	uint128_t _gu128SetPrimGIFTag;
	uint128_t _gu128SetPrimRGBAQGIFTag;
	uint128_t _gau128RegListGIFTags[10];
	uint128_t _gu128ADDRDATAGIFTag;
	uint128_t _gau128ALPHA_1Regs[8];
	uint128_t _gau128CLAMP_1Regs[4];
	uint128_t _gu128Alpha_1;
	uint128_t _gu128Tex1_1;
	uint128_t _gu128Clamp_1;
	uint128_t _gu128Frame_1;
	uint128_t _gu128Scissor_1;
	RwInt32 _gnCurrentTexturePalette;
	CGtTexture * _gpCurrentTexture;
	RwInt32 _gnZ;
	RwInt32 _gnNearZ;
	RwInt32 _gnUserDefinedZ;
	bool _gbIsZTestEnabled;
	RwInt32 _gnGSOffX;
	RwInt32 _gnGSOffY;
	CGtV4d _gGsOffsetXYXY;
	CGtV4d kUntexturedColourScale;
	RwUInt64 _gu64CurrentRGBAQ;
}