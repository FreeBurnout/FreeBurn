#pragma once

#include <rwcore.h>

#include "BoCarViewerDebug.h"

class CBoDebugManager {
public:
	static bool gmbRequestStopAll;
	static bool gmbRequestStopUpdate;
	static bool gmbRequestStepAll;
	static bool gmbRequestStepCameras;
	static bool gmbRequestPlayAll;
	static bool gmbRequestPlayCameras;
	static RwReal gmrGpuMonitorOpacity;
	static bool gmbDrawGpuTextAsTable;
	static RwReal gmrGpuTextTableOffset;

	bool mbPlay;
	bool mbPlayCameras;
	bool mbStepping;
	bool mbSteppingCameras;
	CBoCarViewerDebug mCarViewerDebug;

	void Construct();
	void Update();
	void UpdateStartOfFrame();
	void RenderOverlays();
};

extern CBoDebugManager gDebugManager;

class CBoNetworkCPUMonitors {
public:
	RwInt32 mnNetCarPhysicsUpdate;
	RwInt32 mnB4NetManagerUpdate;
	RwInt32 mnB4NetManagerPostUpdate;
	RwInt32 mnGtNetPlayerManagerUpdate;
	RwInt32 mnGtNetAdapterUpdate;
	RwInt32 mnB4NetPlayersUpdate;
	RwInt32 mnGtLobbyUpdate;
	RwInt32 mnGtBuddiesUpdate;
	RwInt32 mnVoIPUpdate;
	RwInt32 mnNATUpdate;
	RwInt32 mnAddCrashTrafficMonitor;
	RwInt32 mnCheckForMessagesMonitor;
	RwInt32 mnApplyDataMonitor;
	RwInt32 mnApplyTrafficMonitor;
	RwInt32 mnGtNetPlayerMonitor;
	RwInt32 mnApplyNetCarDataMonitor;
	RwInt32 mnApplyTrafficDataMonitor;
	RwInt32 mnCalcTrafficDiffsMonitor;
	RwInt32 mnApplyTrafficDiffsMonitor;

	void Construct();
};

class CBoCPUMonitors {
public:
	void Construct();

	int mnFreeCPU;
	int mnUpdateCost;
	int mnCameraCost;
	int mnAICost;
	int mnGraphicsCost;
	int mnNetworkCost;
	int mnPhysicsCost;
	int mnSoundCost;
	int mnTrafficCost;
	int mnDebugManagerCost;
	int mnSleepCost;
	int mnEffectsCost;
};

extern CBoCPUMonitors gCPUMonitors;

class CBoGPUMonitors {
public:
	void Construct();

	int mnSky;
	int mnBackdrops;
	int mnChevrons;
	int mnTrack;
	int mnInstances;
	int mnProps;
	int mnTraffic;
	int mnRaceCars;
	int mnEffects;
	int mnFog;
	int mnBloom;
	int mnBlur;
};

extern CBoGPUMonitors gGPUMonitors;