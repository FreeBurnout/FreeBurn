#include <rwcore.h>

class CBoPayloadPropManager {
public:
	RwUInt16 mu16NumTotalPayloads;
	RwUInt16 mu16NextIndex;
	RwUInt16 mu16NumPropTypes;
	RwUInt16 mu16FirstPayloadPropType;

	void Construct();
};