#pragma once 

#include "../../../../../GameShared/Common/System/GtFSM.h"
#include "../../../../../GameShared/Common/System/GtTimer.h"

class CBoMenuFlowManager : public CGtFSM {
public:
	void Construct(void * lpOwner, CGtStateOffset * lpOffsetTable, CGtTimer * lpStateTimer);
	void Update();
	CGtStateOffset * GetOffsetTable();
};

class CBoPreviewEventState : CGtState {

};

extern CBoMenuFlowManager gMenuFlowManager;