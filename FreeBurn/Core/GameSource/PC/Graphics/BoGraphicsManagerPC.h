#include <SDL.h>
#include <rwcore.h>
#include "../../Common/Graphics/BoGraphicsManager.h"
#include "../../../../GameShared/PC/Numeric/GtV4dPC.h"

extern SDL_Renderer * renderer;

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	CBoViewport mMainViewport = CBoViewport(); // get rid of this initializer asap
	EBoRenderableCamera meCurrentRenderableCamera;
	int manSpheremapFaceHeights_Pow2[5];

	void Construct();
	void PresentDrawBuffer();
	void OpenViewport(EBoViewportSelection leViewportSelection);
	void RenderFullScreenPass(CGtV4d lColour, EBoFullScreenPassBlendMode leBlendMode);
	RwUInt32 GetVBlankCount();
};

extern CBoGraphicsManager gGraphicsManager;