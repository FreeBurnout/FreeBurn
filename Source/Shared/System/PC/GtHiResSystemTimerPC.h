#ifndef GTHIRESSYSTEMTIMER_H
#define GTHIRESSYSTEMTIMER_H

#include <rwcore.h>

class CGtHiResSystemTimer {
public:
	static void Construct();
	static void Update(RwInt32 lnVsyncCount);
};

#endif // !#define GTHIRESSYSTEMTIMER_H
