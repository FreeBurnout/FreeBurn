#ifndef BOTIMER_H
#define BOTIMER_H

#include "../../../Shared/System/Common/GtTimer.h"

class CBoTimer : public CGtTimer {
public:
	void Construct();
	void SetAllowSlowMo(bool lbAllowSlowmo);
};

#endif // !#define BOTIMER_H