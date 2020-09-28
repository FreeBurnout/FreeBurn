#include <SDL.h>
#include <rwcore.h>

#include "../../../../GameShared/Common/Numeric/Math/Generic/GtV2dGeneric.h"
#include "../../../../GameShared/Common/Graphical/Camera/GtViewport.h"

extern SDL_Renderer * renderer;

class CBoViewport : CGtViewport {
public:
    RwCamera * mpRwCamera;
};

class CBoViewportParams {

};

class CBoGraphicsManagerBase {
public:
    CBoViewportParams * mpCurrentViewportParams;
    CBoViewport * mpCurrentViewport;
    CGtScreenCentre mScreenPosition;
    CGtV2d mScreenPositionData;
    CGtV2d mScreenPositionDataOld;
    RwInt32 mnScreenWidth;
    RwInt32 mnScreenHeight;

	void DrawBootLoadingScreen(float lrProgress);
	void CloseViewport();
    void Update();
};

enum class EBoFullScreenPassBlendMode {
    Normal = 0, 
    Additive = 1,
    AdditiveDestAlpha = 2, 
    Subtractive = 3, 
    Max = 4
};

class CBoEATraxDisplay {
public:
	void Construct();
	void Render();
};

extern CBoEATraxDisplay gEATraxDisplay;