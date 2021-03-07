#ifndef BOFRONTEND_H
#define BOFRONTEND_H

#include "BoGameMode.h"
#include "../../../Shared/Core/GtID.h"
#include "../../World/Common/BoGameData.h"

class CBoFrontEnd : CBoGameMode {
public:
	CBoGameDataStruct* mpStageHeaderList;
	bool mbIsBootMemoryCardTest;
	bool mbIsAutoSaving;
	EGtPrepareState mePrepareState;
	GtID mInitialMenu;
	RwInt8 mn8NextStageIndex;
	bool mbStageHeaderListLoaded;
	bool mbFirstPass;

	void Construct();
	bool Prepare();
	void Update();
	void Render();
	void Release();
	void Destruct();
	void SetInitialMenu(GtID);
	GtID GetInitialMenu() const;
};

#endif // !BOFRONTEND_H
