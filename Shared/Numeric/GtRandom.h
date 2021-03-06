#ifndef GTRANDOM_H
#define GTRANDOM_H

#include <rwcore.h>

class CGtRandom {
public:
	RwInt32 mnHigh;
	RwInt32 mnLow;

	void SetSeed(RwUInt32 luSeed);
};

#endif // !#define GTRANDOM_H