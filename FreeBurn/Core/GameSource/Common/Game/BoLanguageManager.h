#pragma once

#include "../../../../GameShared/Common/Containers/GtArray.h"
#include "../../../../GameShared/Common/Graphical/2D/Gt2dFont.h"
#include "../../../../GameShared/Common/System/GtUnicode.h"


class CBoLanguageManager {
public:
	CGt2dFont * mpSmallFont;

	void Construct();
	GtUTF16 * FindString(const char * lpcStringID);
};

class CBoStrings {
public:
	CGtStringArrayUnicode * mpStringsArray;
};

extern CBoLanguageManager gLanguageManager;
