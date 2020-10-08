#include "GtLinearMalloc.h"

void CGtLinearMalloc::Construct() {
	mpAlloc = nullptr;
	*this = (CGtLinearMalloc)0x0;
	SetAlignment(this, 4);
}
