#include "../../Common/Graphics/BoGraphicsManager.h"

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	void PresentDrawBuffer();
};

static CBoGraphicsManager gGraphicsManager;