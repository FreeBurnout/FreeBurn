#include "BoHUDManager.h"
#include "../../../../GameShared/Common/Graphical/2D/Gt2dObject.h"

class CBoHUDComponent {
public:
	CBoHUDManager * mpHUDManager;
};

class CBoHUDTrafficAttackBar {
public:
	void Update(float param);
};

class CBoHUDTrafficAttackBar2dObject : CGt2dObject {
public:
	void Update(float param);
};