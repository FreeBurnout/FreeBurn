#pragma once

struct GtThreadHandle {

};

class CGtThreadMgr {
public:
	static void SleepThreadTillVBlank();
	static void EnableVBlankWait();
	static GtThreadHandle Open();
};