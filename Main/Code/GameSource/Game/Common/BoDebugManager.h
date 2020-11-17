class CBoNetworkCPUMonitors {
public:
	void Construct();

private:
	RwInt32 mnNetCarPhysicsUpdate;
	RwInt32 mnBoNetManagerUpdate;
	RwInt32 mnBoNetManagerPostUpdate;
	RwInt32 mnGtNetPlayerManagerUpdate;
	RwInt32 mnGtNetAdapterUpdate;
	RwInt32 mnBoNetPlayersUpdate;
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

	void Destruct();
};

class CBoCPUMonitors {
public:
	void Construct();

private:
	void Destruct();

	RwInt32 mnFreeCPU;
	RwInt32 mnUpdateCost;
	RwInt32 mnCameraCost;
	RwInt32 mnAICost;
	RwInt32 mnGraphicsCost;
	RwInt32 mnNetworkCost;
	RwInt32 mnPhysicsCost;
	RwInt32 mnSoundCost;
	RwInt32 mnTrafficCost;
	RwInt32 mnDebugManagerCost;
	RwInt32 mnSleepCost;
	RwInt32 mnEffectsCost;
	CBoNetworkCPUMonitors mNet;
};

class CBoGPUMonitors {
public:
	void Construct();

private:
	RwInt32 mnSky;
	RwInt32 mnBackdrops;
	RwInt32 mnChevrons;
	RwInt32 mnTrack;
	RwInt32 mnInstances;
	RwInt32 mnProps;
	RwInt32 mnTraffic;
	RwInt32 mnRaceCars;
	RwInt32 mnEffects;
	RwInt32 mnFog;
	RwInt32 mnBloom;
	RwInt32 mnBlur;
};

CBoCPUMonitors gCPUMonitors;
CBoGPUMonitors gGPUMonitors;