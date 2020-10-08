#pragma once

#include "Messages/BoHUDMessageManager.h"

class CBoHUD {
public:
	CBoHUDMessageManager mMessageManager;
};

class CBoHUDManager {
public:
	CBoHUD maHUD[2];
};