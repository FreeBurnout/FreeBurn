#ifndef BOGAMEMODE_H
#define BOGAMEMODE_H

#include "Challenge/BoChallenge.h"
#include "Logic/BoStageLogic.h"

class CBoGameMode {
public:
	CBoStageLogic * mpStageLogic;
	CBoChallenge *  mpChallenge;
	bool            mbDoFullPrepare;

	void    Construct();
	bool    Prepare();
	void    Update();
	void    Release();
	void    Destruct();
	bool    StartReplay();
	RwInt32 GetNumLaps();

private:
	void            RequestResetWithFullPrepare();
	void            SetStageLogic(CBoStageLogic * lpStageLogic);
	CBoStageLogic * GetStageLogic();
	void            SetChallenge(CBoChallenge * lpChallenge);
	CBoChallenge *  GetChallenge();
};

class CBoOnePlayerStage : CBoGameMode {

};

class CBoTwoPlayerSplitScreenStage : CBoGameMode {

};

#endif // !BOGAMEMODE_H
