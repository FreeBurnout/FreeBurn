#include <SDL.h>
#include <rwcore.h>

#include "../../../../GameShared/Common/Numeric/Math/Generic/GtV2dGeneric.h"
#include "../../../../GameShared/Common/Graphical/Camera/GtViewport.h"
#include "../../../../GameShared/PC/Graphical/GtTexturePC.h"

extern SDL_Renderer * renderer;
extern "C" void _RpSkyRenderStateSet(RwRenderState, void *);

enum class EBoVideoMode {
    NTSC = 0,
    HDTV = 1,
    PAL = 2,
    Max = 3
};

enum class EBoViewportSelection {
    Main = 0,
    Player1 = 1,
    Player2 = 2
};

class CBoViewport : public CGtViewport {
public:
    RwCamera * mpRwCamera;
};

class CBoViewportParams {
public:
    RwReal mrFogDistance;
};

class CBoDebugMipMaps {
public:
    void Construct();
};

class CBoFogBase {
public:
    static void CalculateClipPlanes(RwReal * lprNearClipOut, RwReal * lprFarClipOut, RwReal lrFogDistance);
};

class CBoFog : CBoFogBase {

};

class CBoSunRenderer {
public:
    static CGtTexture * mpCoronaTexture;
    static CGtTexture * mpEnvmapCoronaTexture;

    void Construct();
};

class CBoGraphicsManagerBase {
public:
    float marLodSwitchDistances[5];
    CGtV2d mFrameBufferOffset;
    CBoViewport maPlayerViewports[2];
    CBoViewportParams maPlayerViewportParams[2];
    CBoViewportParams * mpCurrentViewportParams;
    CBoViewport * mpCurrentViewport;
    CGtScreenCentre mScreenPosition;
    CGtV2d mScreenPositionData;
    CGtV2d mScreenPositionDataOld;
    RwInt32 mnScreenWidth;
    RwInt32 mnScreenHeight;
    EBoVideoMode meCurrentVideoMode;
    bool mbWidescreen;

    void Construct();
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

enum class EBoRenderableCamera {
    None = -1,
    Main = 0,
    EnvMap1 = 1,
    EnvMap2 = 2,
    EnvMap3 = 3,
    InGameCount = 4,
    EnvMap4 = 4,
    EnvMap5 = 5,
    FrontEndCount = 6
};

extern uint64_t _gau64Alpha1;

extern CBoEATraxDisplay gEATraxDisplay;