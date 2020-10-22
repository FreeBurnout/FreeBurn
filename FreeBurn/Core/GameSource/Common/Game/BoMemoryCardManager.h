#pragma once

#include <rwcore.h>

enum class EDebugSubstate {
	Init = 0,
	DisplayChoiceMessage = 1,
	Poll = 2,
	Finished = 3,
	Max = 4
};

class CBoMemoryCardManager {
public:
	EDebugSubstate meDebugSubstate;
	bool mbIsFinished;

	RwInt32 GetSelection();
	void ClearMessage();
	void StartBootCheckFlow();
	void StartBootLoadProfileFlow();
	void StartSaveProfileFlow();
	void StartLoadProfileFlow();
	void Construct();
	void Release();
	void SetMessage(RwChar * lpMessage);
	void SetOptions(RwChar * lpOptions0, RwChar * lpOptions1, RwChar * lpOptions2, RwChar * lpOptions3);
	void UpdateDebugFlow();
};

static CBoMemoryCardManager gBoMemCardManager;