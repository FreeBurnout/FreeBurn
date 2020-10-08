#include <rwcore.h>

class CGtViewport {
public:
	RwReal mrNearClipDistance;
	RwReal mrFarClipDistance;
};

class CGtScreenCentre {
public:
	void MoveScreen(RwReal lrShiftX, RwReal lrShiftY);
};