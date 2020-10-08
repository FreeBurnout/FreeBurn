#include "rwcore.h"

class CBoSaveGameDataManager {
public:
	bool mbLastProfileIsEmptyStatus;
	unsigned int munLastCheckSum;
	RwReal mrPlayingTimeSecsCountAtLastLoad;
	RwReal mrPlayingTimeSecsCounter;

	void Init();
};

extern CBoSaveGameDataManager gSaveGameDataManager;