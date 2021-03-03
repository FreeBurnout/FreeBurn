#ifndef BOACTIVEBODY_H
#define BOACTIVEBODY_H

#include <rwcore.h>

#include "../../Shared/Geometric/GtIntersection.h"
#include "../../Shared/Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

enum EBoActiveBodyType : RwInt8 {
	eABT_AICar = 0,
	eABT_NetworkCar = 1,
	eABT_PlayerCar = 2,
	eABT_Traffic = 3,
	eABT_CrashingTraffic = 4,
	eABT_CheckedTraffic = 5,
	eABT_StaticProp = 6,
	eABT_DynamicProp = 7,
	eABT_BodyPart = 8,
	eABT_Camera = 9,
	eABT_NumActiveBodyTypes = 10
};

class CBoActiveBody {
public:
	CGtV3d maExtent[2];
	CGtMatrix3x4 mpMatrix;
	CGtAxisAlignedBox* mpBox;
	void* mpBodyData;
	EBoActiveBodyType meType;
	RwUInt8 mu8Index;
	bool mbRemove;
};

#endif // !BOACTIVEBODY_H
