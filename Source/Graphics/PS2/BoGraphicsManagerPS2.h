#include "../../Common/Graphics/BoGraphicsManager.h"

class CBoGraphicsManager {
enum class EClutID {
    eClutId_Clouds = 0,
    eClutId_EnvMapClouds = 1,
    eClutId_BrokenGlass = 2,
    eClutId_UnbrokenGlassTexture = 3,
    eClutId_VehicleUnderside = 4,
    eClutId_Unused1 = 5,
    eClutId_SunOcclusionPalette = 6,
    eClutId_FogLookup = 7,
    eClutId_Max = 8
};

public:
    bool Prepare();
    bool PrepareSpheremapWarpData();
    void BuildCustomCameraData(ERaceCarIndex leRaceCarIndex);
    void BuildFrontEndSphereMapData();
    void CBoCameraData::Construct(RwCamera* lpCamera);

    int128_t* CBoCameraData::ConstructEnvMap(
        CGtMatrix3x4 lMatrix, 
        EBoRenderableCamera leCamera, 
        bool lbCubeMap,
        RwInt32 lnWidth,
        RwInt32 lnHeight,
        RwUInt32 luMemoryOffset
    );

    void CBoCameraData::SendRegistersToGS(); const

    int128_t* CBlit::BuildPacket(
        RwUInt32 luScreenWidth,
        RwUInt32 luScreenHeight,
        RwUInt32 luDisplayHeight,
        RwUInt32 luBrightness,
        RwUInt32 luAlpha,
        RwUInt32 luUOffset,
        RwUInt32 luVOffset,
        RwUInt64 lu64DimX,
        bool lbMirror
    );

    void ClearOffscreenBuffer(unsigned int);
    void ClearScreen();
    void Construct();
    int128_t Copy4BitTextureAsPSMT4H(CGtTexture*, unsigned int, EClutID, bool, unsigned int);
    int128_t Copy8BitTextureAsPSMT8H(CGtTexture*, unsigned int, EClutID, unsigned int)
    int128_t CopyTextureAs32Bit(CGtTexture*, unsigned int, unsigned int);
    void CreateWorkBuffers();
    void DistortEnvmapBuffersIntoSphereMap();
    RwUInt32 GetVBlankCount();
    void OpenRenderWare();
    void OpenViewport(EB4ViewportSelection);
    void PresentDrawBuffer();
    void ReleaseSpheremapWarpData();
    void RelockAllLockedRasters();
    void RenderFullScreenBrightnessFilter(float);
    void RenderFullScreenPass(CGtV4d, EBoFullScreenPassBlendMode);
    void RenderFullScreenSpecular(CGtV3d, float);
    void RenderPalOrHdtvContrastFilter();
    void SetDmaFifoMemoryFreeThisFrame(unsigned int);
    void SetVideoMode(EBoVideoMode);
    void SetVideoModeParams(RwSkyVideoMode*);
    void BuildInGameSphereMapData();
};
