#include "BoAITarget.h"

void CBoAITarget::Construct() {
	if (_gnAITargetMonitorID == &_heap_size) {
		_gnAITargetMonitorID = (undefined *)0x0;
	}
	mSpline.Construct();
	mAggression.Construct();
}

void CBoAITargetSpline::Construct() {

}
