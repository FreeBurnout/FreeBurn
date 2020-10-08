#include "BoControllerMapping.h"
#include "../../../../GameShared/PC/System/Input/GtInputDevicePCPad2.h"
#include <rwcore.h>

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
	RwInt8 GetLockedPlayersPort(signed char ln8Player);
	void UpdateRumble();
	void GetAvailableControllers(CBoControllerMapping ** lapControllerMappingsOut, signed char ln8PortIndex);
	void UnlockPlayerPort(signed char ln8Player);
	void Update();
	void UpdateFE();
};

extern CBoInputManager gInputManager;