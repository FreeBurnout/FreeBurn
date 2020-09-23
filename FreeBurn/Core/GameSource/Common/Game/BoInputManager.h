#include "BoControllerMapping.h"
#include "../../../../GameShared/PC/System/Input/GtInputDevicePCPad2.h"

class CBoInputManager {
public:
	bool mbIsPaused;
	bool mabClearRumble[2];
	CGtInputManagerPCPad2 mInputManagerPCPad2;
	bool AreLockedPlayersConnected();
	void ResetState();
	void SetPause(bool lbPaused);
	void StopRumble();
	void StopPlayerRumble(signed char ln8PlayerIndex);
	void UpdateRumble();
	void GetAvailableControllers(CBoControllerMapping ** lapControllerMappingsOut, signed char ln8PortIndex);
	void Update();
	void UpdateFE();
};

extern CBoInputManager gInputManager;