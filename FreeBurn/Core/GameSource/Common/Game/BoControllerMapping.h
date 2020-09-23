#pragma once

#include "../../../../GameShared/PC/System/Input/GtInputDevicePCLogitechWheel.h"

class CBoControllerMapping {
public:
	CGtInputDevicePCLogitechWheel * mpWheel;

	bool WheelIsValid();
};