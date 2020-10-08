#pragma once

enum class EGtAspectRatio {
	Standard,
	Widescreen
};

class CGtSysConfig {
public:
	static EGtAspectRatio GetAspectRatio();
};