#ifndef BOSINGLERACELOGIC_H
#define BOSINGLERACELOGIC_H

#include "../BoStageLogic.h"

class CBoSingleRaceLogic : CBoStageLogic {
public:
	void Construct();
};

class CBoBurningLapLogic : CBoSingleRaceLogic {
public:
	void Construct();
}; 

class CBoEliminatorLogic : CBoSingleRaceLogic {
public:
	void Construct();
}; 

#endif // !BOSINGLERACELOGIC_H