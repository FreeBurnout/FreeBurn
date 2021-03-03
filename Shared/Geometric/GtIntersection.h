#ifndef GTINTERSECTION_H
#define GTINTERSECTION_H

#include "../Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

class CGtAxisAlignedBox {
public:
	CGtV3d mSup;
	CGtV3d mInf;
};

class CGtPolygonIntersectionResult { };

#endif // !#define GTINTERSECTION_H