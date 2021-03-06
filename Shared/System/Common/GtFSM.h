#ifndef GTFSM_H
#define GTFSM_H

#include <rwcore.h>

#include "../../Core/GtID.h"

enum class EGtPrepareState {
	eGtPSNone = 0,
	eGtPSConstructed = 1,
	eGtPSPreparedStage1 = 2,
	eGtPSPreparedStage2 = 3,
	eGtPSPreparedStage3 = 4,
	eGtPSPreparedStage4 = 5,
	eGtPSPreparedStage5 = 6,
	eGtPSPreparedStage6 = 7,
	eGtPSPreparedStage7 = 8,
	eGtPSPreparedStage8 = 9,
	eGtPSPreparedStage9 = 10,
	eGtPSPreparedStage10 = 11,
	eGtPSPreparedStage11 = 12,
	eGtPSPreparedStage12 = 13,
	eGtPSPreparedStage13 = 14,
	eGtPSPreparedStage14 = 15,
	eGtPSPreparedStage15 = 16,
	eGtPSPreparedStage16 = 17,
	eGtPSPreparedStage17 = 18,
	eGtPSPreparedStage18 = 19,
	eGtPSPreparedStage19 = 20,
	eGtPSPreparedStage20 = 21,
	eGtPSPreparedStage21 = 22,
	eGtPSPreparedStage22 = 23,
	eGtPSPreparedStage23 = 24,
	eGtPSPreparedStage24 = 25,
	eGtPSPreparedStage25 = 26,
	eGtPSPreparedResources = 27,
	eGtPSPreparedFully = 28,
	eGtPSReleasedStage1 = 29,
	eGtPSReleasedStage2 = 30,
	eGtPSReleasedStage3 = 31,
	eGtPSReleasedStage4 = 32,
	eGtPSReleasedStage5 = 33,
	eGtPSReleasedStage6 = 34,
	eGtPSReleasedStage7 = 35,
	eGtPSReleasedStage8 = 36,
	eGtPSReleasedStage9 = 37,
	eGtPSReleasedStage10 = 38,
	eGtPSReleasedStage11 = 39,
	eGtPSReleasedStage12 = 40,
	eGtPSReleasedStage13 = 41,
	eGtPSReleasedStage14 = 42,
	eGtPSReleasedStage15 = 43,
	eGtPSReleasedStage16 = 44,
	eGtPSReleasedStage17 = 45,
	eGtPSReleasedStage18 = 46,
	eGtPSReleasedStage19 = 47,
	eGtPSReleasedStage20 = 48,
	eGtPSReleasedStage21 = 49,
	eGtPSReleasedStage22 = 50,
	eGtPSReleasedStage23 = 51,
	eGtPSReleasedStage24 = 52,
	eGtPSReleasedStage25 = 53,
	eGtPSReleasedResources = 54,
	eGtPSReleasedFully = 55,
	eGtPSReleased = 56,
	eGtPSDestructed = 57
};
enum class EGtStateAction {
	eGtStateActionConstruct = 0,
	eGtStateActionDestruct = 1,
	eGtStateActionLeave = 2,
	eGtStateActionEnter = 3,
	eGtStateActionUpdate = 4,
	eGtStateActionEvent = 5
};

class CGtState {
public:
	GtID mID;
	RwReal mrTimeStateEntered;

	GtID GetID();
	RwReal GetStateEnteredTime();
	virtual void Action(EGtStateAction leAction, void* param_2, void* param_3, void* param_4) = 0;
};

class CGtFSM {
public:
	CGtState* mpState;
};

struct CGtStateOffset {
public:
	GtID mID;
	RwInt32 mnOffset;
};

#endif // !#define GTFSM_H
