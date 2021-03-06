#ifndef BOGRAPHICSMANAGERPC_H
#define BOGRAPHICSMANAGERPC_H

#include <SDL.h>

#include <bacamera.h>

#include "../Common/BoGraphicsManager.h"
#include "../../World/Common/BoRaceCar.h"
#include "../../../Shared/Numeric/Math/PC/GtMathPC.h"

extern SDL_Window* window;

using namespace GtMathPC;

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	void BuildCustomCameraData(ERaceCarIndex);
	void BuildFrontEndSphereMapData();
	void BuildInGameSphereMapData();
	void ClearOffscreenBuffer(uint32_t);
	void ClearScreen();
	void Construct();
	void CreateWorkBuffers();
	void DistortEnvmapBuffersIntoSphereMap();
	RwUInt32 GetVBlankCount();
	void OpenRenderWare();
	void OpenViewport(EBoViewportSelection) override;
	bool Prepare();
	bool PrepareSpheremapWarpData();
	void PresentDrawBuffer();
	void ReleaseSpheremapWarpData();
	void RelockAllLockedRasters();
	void RenderFullScreenBrightnessFilter(float);
	void RenderFullScreenPass(CGtV4d, EBoFullScreenPassBlendMode);
	void RenderFullScreenSpecular(CGtV3d, float);
	void RenderPalOrHdtvContrastFilter();
	void SetVideoMode(EBoVideoMode);
	void SetVideoModeParams(RwVideoMode*);
};

static CBoGraphicsManager gGraphicsManager;

#endif // !#define BOGRAPHICSMANAGERPC_H
