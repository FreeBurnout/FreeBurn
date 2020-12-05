#ifndef BOGRAPHICSMANAGERPC_H
#define BOGRAPHICSMANAGERPC_H

#include <SDL.h>

#include <src\bacamera.h>

#include "../Common/BoGraphicsManager.h"
#include "../../World/Common/BoRaceCar.h"
#include "../../../Shared/Numeric/Math/PC/GtV3dPC.h"
#include "../../../Shared/Numeric/Math/PC/GtV4dPC.h"

extern SDL_Window* window;

using namespace GtMathPC;

class CBoGraphicsManager : public CBoGraphicsManagerBase {
public:
	void BuildCustomCameraData(ERaceCarIndex);
	void BuildFrontEndSphereMapData();
	void BuildInGameSphereMapData();
	void ClearOffscreenBuffer(unsigned int);
	void ClearScreen();
	void Construct();
	void CreateWorkBuffers();
	void DistortEnvmapBuffersIntoSphereMap();
	
	RwUInt32 GetVBlankCount();
	void OpenRenderWare();
	void OpenViewport(EBoViewportSelection);
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

extern CBoGraphicsManager gGraphicsManager;

#endif // !#define BOGRAPHICSMANAGERPC_H
