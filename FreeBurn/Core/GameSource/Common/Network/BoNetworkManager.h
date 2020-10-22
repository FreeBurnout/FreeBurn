#include <rwcore.h>

class CBoNetworkManager {
public:
	static RwUInt32 muFrameCount;

	bool mbIsOnline;
	bool mbIsOnlineMenus;
	bool mbUppingInterface;

	void Construct();
	void Destruct();
	void Release();
	void Update();
	void PostUpdate();
};

extern CBoNetworkManager gNetworkManager;