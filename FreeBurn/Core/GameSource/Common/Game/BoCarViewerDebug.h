#pragma once

#include <rwcore.h>

class CBoCarViewerDebug {
public:
	bool IsActive();
	void UpdateCamera(RwReal mrTimeStep);
};