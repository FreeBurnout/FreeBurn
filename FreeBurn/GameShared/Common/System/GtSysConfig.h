#pragma once

enum class EGtAspectRatio {
	Standard = 0,
	Widescreen = 1
};

class CGtSysConfig {
public:
	static EGtAspectRatio GetAspectRatio();
};