#include <rwcore.h>

class CB4Flags32 {
public:
	RwUInt32 muFlags;
	
	void Construct();
	bool Prepare();
	void Destruct();
	void Release();
	bool IsBitSet() const;
	void SetBit(unsigned int);
	void UnSetBit(unsigned int);
	bool IsZero() const;
};

