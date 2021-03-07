#include "GtFramerateManager.h"

void CGtFramerateManager::Construct(RwReal lrSimulationTimeStep, RwReal lrFramerateToleranceTimeMs) {

}

void CGtFramerateManager::Prepare() {

}

void CGtFramerateManager::StartUpdateFrame(EGtFramerateType, bool) {

}

RwInt32 CGtFramerateManager::UpdatePostRenderWait(RwInt32 lnMinSimulationSteps, RwInt32 lnMaxSimulationSteps) {
    return RwInt32();
}

void CGtFramerateManager::AttemptToInsertExtraSimulationUpdates(int) {

}

void CGtFramerateManager::Destroy() {

}

void CGtFramerateManager::SetNumSimulationStepsAchieved(int) {

}
