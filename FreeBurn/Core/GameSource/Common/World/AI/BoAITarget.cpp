#include "BoAITarget.h"

void CBoAITarget::Construct() {
	if (_gnAITargetMonitorID == -1) {
		_gnAITargetMonitorID = 0;
	}
	mSpline.Construct();
	mAggression.Construct();
}

void CBoAITargetSpline::Construct() {

}
