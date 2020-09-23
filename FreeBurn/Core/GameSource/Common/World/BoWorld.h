#pragma once

#include "../Game/BoTimer.h"

class CBoWorld {
public:
	CBoTimer mTimer;

	bool mbIsReplaying;
	bool mbRequestReplay;

	void Construct();
	void Release();
};

extern CBoWorld gWorld;