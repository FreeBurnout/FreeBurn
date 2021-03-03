#ifndef BOMENUFLOWMANAGER_H
#define BOMENUFLOWMANAGER_H

#include "../../../Shared/System/Common/GtFSM.h"
#include "../../../Shared/System/Common/GtTimer.h"

class CBoMenuFlowManager {
public:
	void Construct(void* lpOwner, const CGtStateOffset* lpOffsetTable, CGtTimer* lpStateTimer);
	CGtStateOffset* GetOffsetTable();

	CGtStateOffset maOffsetTable[2] = {

	};
};

class CBoDebugMenuPageManager {
public:
	void Construct();
};

extern CBoMenuFlowManager gMenuFlowManager;
extern CBoDebugMenuPageManager gDebugMenuPageManager;

#endif // !BOMENUFLOWMANAGER_H