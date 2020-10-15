#pragma once

#include "../Menu/States/BoMenuFlowManager.h"

class CBoMenuChoices {
public:
	EBoTrackLocale GetChosenCity();
};

extern CBoMenuChoices gMenuChoices;