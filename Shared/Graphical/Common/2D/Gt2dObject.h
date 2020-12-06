#include "../../../Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

class CGt2dObject {
public:
	class CGt2dObjectSpace { };

	static void Prepare(const CGtV2d&, const CGtV2d&, CGtV4d, void (*)(const CGt2dObject::CGt2dObjectSpace&, const void*), unsigned int, unsigned int);
};

class CGt2dObjectText {

};

class COutlineDropShadow {
public:
	CGtV4d mDropShadowColour;
	CGtV2d mDropShadowOffset;
	CGtV2d mOutlineOffset;
};