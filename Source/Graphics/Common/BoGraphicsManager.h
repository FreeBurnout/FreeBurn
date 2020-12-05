#ifndef BOGRAPHICSMANAGER_H
#define BOGRAPHICSMANAGER_H

#include <rwcore.h>

enum EBoViewportSelection {
	eBoViewportMain = 0,
	eBoViewportPlayer1 = 1,
	eBoViewportPlayer2 = 2
};
enum EBoVideoMode {
	eBoVideoModeNTSC = 0, 
	eBoVideoModeHDTV = 1, 
	eBoVideoModePAL = 2, 
	eBoVideoModeMax = 3
};
enum EBoFullScreenPassBlendMode {
	eBoFSPBM_Normal = 0, 
	eBoFSPBM_Additive = 1, 
	eBoFSPBM_AdditiveDestAlpha = 2, 
	eBoFSPBM_Subtractive = 3, 
	eBoFSPBM_Max = 4
};

class CBoGraphicsManagerBase {
public:
	void Downsample(
		RwUInt32 luFrameBufferAddress, 
		RwUInt32 luFrameBufferWidth, 
		RwUInt32 luWorkspaceAddress, 
		RwUInt32 luWorkspaceWidth, 
		RwInt32 lnTopLeftX, 
		RwInt32 lnTopLeftY, 
		RwInt32 lnSizeX, 
		RwInt32 lnSizeY
	);

	void DrawBootLoadingScreen(RwReal lrProgress);
};

#endif // !#define BOGRAPHICSMANAGER_H