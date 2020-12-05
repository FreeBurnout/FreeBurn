enum EBoLoadingScreenTypes {
	eBoLoadingScreenTypeBootup = 0, 
	eBoLoadingScreenTypeSimple = 1, 
	eBoLoadingScreenTypeTip = 2, 
	eBoLoadingScreenTypeReplay = 3, 
	eBoLoadingScreenTypeNum = 4
};
enum EBoMenuCarClasses {
	eBoMenuCarClassCompact = 0,
	eBoMenuCarClassMuscle = 1,
	eBoMenuCarClassCoupe = 2,
	eBoMenuCarClassSport = 3,
	eBoMenuCarClassSuper = 4,
	eBoMenuCarClassRaceSpecial = 5,
	eBoMenuCarClassHeavyweight = 6,
	eBoMenuCarClassTraffic = 7,
	eBoMenuCarClassTrafficSpecial = 8,
	eBoMenuCarClassNumber = 9
};

class CBoMenuChoices {
public:
	EBoLoadingScreenTypes meBoLoadingScreenType;
};

extern CBoMenuChoices gMenuChoices;