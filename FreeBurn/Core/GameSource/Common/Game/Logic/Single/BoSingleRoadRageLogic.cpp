#include "BoSingleRoadRageLogic.h"
#include "../BoStageLogic.h"

void CBoSingleRoadRageLogic::Construct() {
	((CBoStageLogic *)this)->Construct();
	mnStageIndex = -1;
}
