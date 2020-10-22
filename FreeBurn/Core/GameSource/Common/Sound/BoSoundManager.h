#include "Core/BoSoundGameModeManager.h"
#include "../../../../GameShared/Common/Sound/GtSoundManager.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"

class CBoSoundManager : CGtSoundManager {
public:
	EGtPrepareState mePrepareState;
	CBoSoundGameModeManager mGameModeManager;

	void StopAll();
	void Destruct();
	void Release();
	void Update();
	void Unpause();
	void Pause();
};

extern CBoSoundManager gSoundManager;