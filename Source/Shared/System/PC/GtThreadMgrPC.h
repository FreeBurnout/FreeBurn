#ifndef GTTHREADMGRPC_H
#define GTTHREADMGRPC_H

class CGtThreadMgr {
public:
	static void SleepThreadTillVBlank();
	static void Open();
	static void EnableVBlankWait();
};

#endif // !#define GTTHREADMGRPC_H
