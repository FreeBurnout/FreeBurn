#include <cstdint>

class CGtLinearMalloc {
public:
	bool mbCreated;
	void * mpAlloc;

	size_t mnStartAddress;
	size_t mnEndAddress;
	size_t mnNextAddress;
	size_t mnAlignment;
	uint32_t mpLastAlloc;
	CGtLinearMalloc * mpActiveRWAllocator;
	//mCachedMemoryFuncs:/0236:_15CGtLinearMalloc$mCachedMemoryFuncs;

	void Construct();
	void SetAlignment(size_t lnAlignment);
};