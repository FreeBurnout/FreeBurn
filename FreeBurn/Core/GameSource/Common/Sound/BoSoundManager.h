#include "Core/BoSoundGameModeManager.h"
#include "../../../../GameShared/Common/Sound/GtSoundManager.h"

class CBoSoundManager : CGtSoundManager {
public:
	CBoSoundGameModeManager mGameModeManager;

	void StopAll();
	void Update();
	void Unpause();
	void Pause();
};

extern CBoSoundManager gSoundManager;