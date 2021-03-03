#ifndef GT2DOBJECT_H
#define GT2DOBJECT_H

#include <cstdint>
#include "../../../Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

class CGt2dObject {
public:
	class CGt2dObjectSpace {

	};

	static void Prepare(const CGtV2d&, const CGtV2d&, CGtV4d, void (*)(const CGt2dObjectSpace&, const void*), uint32_t, uint32_t);
};

class CGt2dObjectText {

};

class COutlineDropShadow {
public:
	CGtV4d mDropShadowColour;
	CGtV2d mDropShadowOffset;
	CGtV2d mOutlineOffset;
};

#endif // !#define GT2DOBJECT_H