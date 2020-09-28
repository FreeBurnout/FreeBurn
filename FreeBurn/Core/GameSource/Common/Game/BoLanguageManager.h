#pragma once

#include "../../../../GameShared/Common/System/GtUnicode.h"
#include "../../../../GameShared/Common/Graphical/2D/Gt2dFont.h"

class CBoLanguageManager {
public:
	CGt2dFont * mpSmallFont;

	void Construct();
	GtUTF16 * FindString(const char * lpcStringID);
};

extern CBoLanguageManager gLanguageManager;