#include "BoNetworkingService.h"
#include "../../../States/BoMenuFlowManager.h"
#include "../../../States/Online/DirtySock/BoOpenInterfaceMenuStateDS.h"

void CBoOpenInterfaceService::AbortDNAS(void) {
	gMenuFlowManager.mOpenInterfaceMenuState.AbortDNAS();
}