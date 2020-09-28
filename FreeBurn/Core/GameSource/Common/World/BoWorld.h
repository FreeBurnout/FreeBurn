#pragma once

#include "../Game/BoTimer.h"

class CBoWorld {
public:
	CBoTimer mTimer;

	bool mbPausedForNetworkSync;
	bool mbPausedForStreamSync;
	bool mbIsReplaying;
	bool mbRequestReplay;

	void Construct();
	void UpdateSound();
	void Release();
	void Update();
};

extern CBoWorld gWorld;