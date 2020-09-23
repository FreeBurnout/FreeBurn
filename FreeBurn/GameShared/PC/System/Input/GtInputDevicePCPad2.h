#pragma once

class CGtInputDevice {

};

class CGtInputDeviceGamePad : CGtInputDevice {

};

class CGtInputDevicePCPad2 : CGtInputDeviceGamePad {

};

class CGtInputManagerPCPad2 {
public:
	void SetPause(bool lbPaused);
};