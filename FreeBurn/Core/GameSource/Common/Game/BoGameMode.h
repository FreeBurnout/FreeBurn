#pragma once

class CBoGameMode {
public:
	bool mbDoFullPrepare;
};

class CBoOnePlayerStage : CBoGameMode {
public:
	void Construct();
};

class CBoTwoPlayerSplitScreenStage : CBoGameMode {
public:
	void Construct();
};

