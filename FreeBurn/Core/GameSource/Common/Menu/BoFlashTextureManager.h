#include <rwcore.h>

extern char * gapcTextureDictionaryNames[4];

extern CBoFlashTextureManager gFlashTextureManager;

enum class ETextureDictionary {
	World = 0,
	Detroit = 1,
	Tokyo = 2,
	HongKong = 3,
	Max = 4
};

class CBoFlashTextureManager {
public:
	EGtPrepareState meFlashTexturePrepareState;
	ETextureDictionary meTextureDictionary;
	char * macFlashTextureFileName;

	char * SetTextureDictionary(ETextureDictionary leDictionary);
	bool PrepareTextureDictionary();
};
