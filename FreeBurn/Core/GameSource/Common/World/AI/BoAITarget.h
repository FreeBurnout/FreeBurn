#include "BoAIBehaviourManager.h"

class CBoAITarget {
public:
	CBoAIAggressionBehaviour mAggression;
	CBoAITargetSpline mSpline;

	void Construct();
};

class CBoAITargetSpline {
public:
	void Construct();
};