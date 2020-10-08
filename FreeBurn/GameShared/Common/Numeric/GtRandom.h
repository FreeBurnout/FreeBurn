#include <rwcore.h>

class CGtRandom {
public:
	RwInt32 mnHigh;
	RwInt32 mnLow;

	void SetSeed(RwUInt32 luSeed);
};

extern CGtRandom gRandom;