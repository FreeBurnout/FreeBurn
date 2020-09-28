#include <rwcore.h>

enum class EGtFramerateType {
	Constant = 0,
	VariableRelative = 1,
	VariableAbsolute = 2,
	Max = 3
};

class CGtFramerateManager {
public:
	void Construct(RwReal lrSimulationTimeStep, RwReal lrFramerateToleranceTimeMs);
	void Prepare();
	void StartUpdateFrame(EGtFramerateType leFramerateType, bool a);
	RwInt32 UpdatePostRenderWait(RwInt32 lnMinSimulationSteps, RwInt32 lnMaxSimulationSteps);
	RwInt32 mnPrevNumSimulationStepsRequired;
};