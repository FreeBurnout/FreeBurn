#ifndef GTFRAMERATEMANAGER_H
#define GTFRAMERATEMANAGER_H

#include <rwcore.h>

enum EGtFramerateType {
	eGtFramerateConstant = 0,
	eGtFramerateVariableRelative = 1,
	eGtFramerateVariableAbsolute = 2,
	eGtFramerateVariableMax = 3
};

class CGtTimeCounter {

};

class CGtFramerateManager {
public:
	EGtFramerateType meFramerateType;
	CGtTimeCounter mPrevFrameTime;
	CGtTimeCounter mTotalTime;
	RwInt64 mn64FramerateToleranceCycles;
	RwInt64 mn64SimulationTimeStepCycles;
	RwInt32 mnPrevNumSimulationStepsRequired;
	RwInt32 mnNumSimulationSteps;
	RwInt32 mnNumExtraSimulationUpdatesRequested;
	bool mbPaused;

	void Construct(RwReal lrSimulationTimeStep, RwReal lrFramerateToleranceTimeMs);
	void Prepare();
	void StartUpdateFrame(EGtFramerateType, bool);
	RwInt32 UpdatePostRenderWait(RwInt32 lnMinSimulationSteps, RwInt32 lnMaxSimulationSteps);
	void AttemptToInsertExtraSimulationUpdates(int);
	void Destroy();
	void SetNumSimulationStepsAchieved(int);

};

#endif // !#define GTFRAMERATEMANAGER_H
