#pragma once

#include "../../../../GameShared/Common/System/GtFSM.h"

enum class EBoPlayerCameraBehaviour {
	DebugFlyAround = 0,
	EditorFlyAround = 1,
	InGameRotate = 2,
	InGameLooseRotate = 3,
	InGamePassCam = 4,
	InGameAttachCam = 5,
	InGameCameraCarCam = 6,
	InGameHandyCam = 7,
	InGameAftertouch = 8,
	InGameFollow = 9,
	InGameFollow2 = 10,
	InGameLookBack = 11,
	InGameBumper = 12,
	RaceBreaker = 13,
	PeekCamera = 14,
	Shot = 15,
	HeliCam = 16,
	CrashCluster = 17,
	CrashJump = 18,
	CrashbreakerCamera = 19,
	Controlled = 20,
	CrashHelicopter = 21,
	CrashClusterInterp = 22,
	Interpolate = 23,
	SecondTearInterpolate = 24,
	KeyFrameA = 25,
	KeyFrameB = 26,
	KeyFrameC = 27,
	KeyFrameD = 28,
	KeyFrameE = 29,
	LookAt = 30,
	Effect = 31,
	WindPulse = 32,
	HighSpeedShake = 33,
	Number = 34
};

class CBoFlags {
public:
	char maxBits[152];

	bool Prepare();
};

class CBoPlayerCameraManager : CGtFSM {
public:
	bool mbCutThisFrame;
	EBoPlayerCameraBehaviour meForwardBehaviour;
	
	void Construct();
	void SetCutThisFrame(bool lbCutThisFrame);
	void Update();
	void Update(float);
};

class CBoCameraEditor {
public:
	void Construct(CBoPlayerCameraManager * param);
};
