#pragma once

#include "../Menu/States/BoMenuFlowManager.h"

class CBoMenuChoices {
public:
	RwInt8 mn8ContrastFilterOn;

	EBoTrackLocale GetChosenCity();
};

extern CBoMenuChoices gMenuChoices;