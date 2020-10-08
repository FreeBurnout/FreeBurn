#pragma once

#include "Logic/BoStageLogic.h"
#include "Challenge/BoChallenge.h"

class CBoGameMode {
public:
	bool mbDoFullPrepare;
	CBoChallenge * mpChallenge;
	CBoStageLogic * mpStageLogic;

	void vf();
	void Construct();
};

class CBoOnePlayerStage : CBoGameMode {
public:
	void Construct();
};

class CBoTwoPlayerSplitScreenStage : CBoGameMode {
public:
	void Construct();
};

