#pragma once

struct GtThreadHandle {

};

class CGtThreadMgr {
public:
	static void SleepThreadTillVBlank();
	static void EnableVBlankWait();
	static void DisableVBlankWait();
	static void Close();
	static GtThreadHandle Open();
};