#include "../../Common/Graphics/BoGraphicsManager.h"
#include <SDL.h>
#include <rwcore.h>
#include "../../../../GameShared/PC/Numeric/GtV4dPC.h"

extern SDL_Renderer * renderer;

enum class EBoViewportSelection {
	Main = 0,
	Player1 = 1,
	Player2 = 2
};

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	void Construct();
	void PresentDrawBuffer();
	void OpenViewport(EBoViewportSelection leViewportSelection);
	void RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode);
	RwUInt32 GetVBlankCount();
};

extern CBoGraphicsManager gGraphicsManager;