#include <rwcore.h>

class CGtRandom {
public:
	RwInt32 mnHigh;
	RwInt32 mnLow;

	void SetSeed(unsigned int luSeed);
};