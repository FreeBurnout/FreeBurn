#include "GtLinearMalloc.h"

void CGtLinearMalloc::Construct() {
	mpAlloc = nullptr;
	// *this = (CGtLinearMalloc)0x0; // nope
	SetAlignment(4);
}

void CGtLinearMalloc::SetAlignment(size_t lnAlignment) {

}
