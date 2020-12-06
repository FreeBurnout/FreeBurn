#ifndef BOLANGUAGEMANAGER_H
#define BOLANGUAGEMANAGER_H

#include <rwcore.h>

#include "../../../Shared/System/Common/GtLocalisation.h"
#include "../../../Shared/Core/GtID.h"
#include "../../../Shared/System/Common/GtFSM.h"
#include "../../../Shared/Graphical/Common/2D/Gt2dFont.h"
#include "../../../Shared/System/Common/Unicode/GtUnicode.h"

extern char* gaLanguageCodePostfix[];

char16_t kaDollarString[] = u"$";
char16_t kaDollarSpaceString[] = u"$ ";
char16_t kaSpaceDollarString[] = u" $";
char16_t kaEmptyString[] = u"";

class CBoLanguageManager {
public:
	EGtPrepareState mePrepareState;
	EGtPrepareState meFontsPrepareState;
	CGtHashIDStringArray* mpMainStrings;
	CGt2dFont* mpBigFont;
	CGt2dFont* mpSmallFont;
	CGt2dFont* mpDigitalFont;
	GtUTF16* mpNoStringString;
	GtUTF16* mpHeadDollarStringString;
	GtUTF16* mpTailDollarStringString;
	EGtLanguage meLanguage;
	bool mbIsDollarOnLeft;
	bool mbFileLoaded;
	bool mbIsBigFontLoaded;
	bool mbIsSmallFontLoaded;

	void Construct();
	void SetLanguage(EGtLanguage leLanguage);
	bool Prepare();
	EGtLanguage GetSKUHardwareLanguage();
	GtUTF16* FindString(const char* lpcStringID); const
	void ReleaseStrings();
	bool PrepareInGame();
	void ReleaseInGame();
	void SetNumericSeperators();
	void PrepareDollarStrings();
	void GenerateCrashHoleStringID(GtID lTrackID, RwInt32 lnHole, bool lbEasyHole, char* lacStringID);
	void GenerateTrackStringID(GtID lTrackID, char* lacStringID);

};

extern CBoLanguageManager gLanguageManager;

#endif // !#define BOLANGUAGEMANAGER_H

