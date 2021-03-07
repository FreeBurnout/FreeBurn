#ifndef GTMATH
#define GTMATH

#include <cstdint>
#include <rwcore.h>

union USplitBits {
public:
	RwReal mrReal;
	RwUInt32 mxBits;
	
	USplitBits(RwReal mrReal) {
		this->mrReal = mrReal;
		mxBits = *(RwUInt32*)(&this->mrReal);
	};

	USplitBits(uint32_t mxBits) {
		this->mxBits = mxBits;
		mrReal = *(RwReal*)(&this->mxBits);
	};
};

#endif // !#define GTMATH
