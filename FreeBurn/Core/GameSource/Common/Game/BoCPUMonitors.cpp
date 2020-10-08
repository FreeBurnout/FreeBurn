#include "BoDebugManager.h"

CBoCPUMonitors gCPUMonitors;
CBoGPUMonitors gGPUMonitors;

// DONE
void CBoNetworkCPUMonitors::Construct() {
	mnNetCarPhysicsUpdate = -1;
	mnB4NetManagerUpdate = -1;
	mnB4NetManagerPostUpdate = -1;
	mnGtNetPlayerManagerUpdate = -1;
	mnGtNetAdapterUpdate = -1;
	mnB4NetPlayersUpdate = -1;
	mnGtLobbyUpdate = -1;
	mnGtBuddiesUpdate = -1;
	mnVoIPUpdate = -1;
	mnNATUpdate = -1;
	mnAddCrashTrafficMonitor = -1;
	mnCheckForMessagesMonitor = -1;
	mnApplyDataMonitor = -1;
	mnApplyTrafficMonitor = -1;
	mnGtNetPlayerMonitor = -1;
	mnApplyNetCarDataMonitor = -1;
	mnApplyTrafficDataMonitor = -1;
	mnCalcTrafficDiffsMonitor = -1;
	mnApplyTrafficDiffsMonitor = -1;
}
