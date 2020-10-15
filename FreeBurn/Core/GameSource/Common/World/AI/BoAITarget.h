#include <rwcore.h>

#include "BoAIBehaviourManager.h"

RwInt32 _gnAITargetMonitorID;

class CBoAITargetSpline {
public:
	void Construct();
};

class CBoAITarget {
public:
	CBoAIAggressionBehaviour mAggression;
	CBoAITargetSpline mSpline;

	void Construct();
};