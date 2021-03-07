#ifndef BONETWORKMANAGER_H
#define BONETWORKMANAGER_H

#include <rwcore.h>

class CBoNetworkManager {
public:
	bool mbUppingInterface;
	bool mbIsOnline;
	RwUInt32 muFrameCount;

	void Construct();
	void Update();
	void PostUpdate();
};

static CBoNetworkManager gNetworkManager;

#endif // !#define BONETWORKMANAGER_H
