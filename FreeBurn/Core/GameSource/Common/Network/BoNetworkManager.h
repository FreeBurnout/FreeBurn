#include <rwcore.h>

class CBoNetworkManager {
public:
	static RwUInt32 muFrameCount;

	bool mbIsOnline;
	bool mbUppingInterface;

	void Construct();
	void Update();
	void PostUpdate();
};

extern CBoNetworkManager gNetworkManager;