#include "GtID.h"

GtID GtIDCompress(const char* lcpString) {
    long lVar2 = 0;
    long lVar4 = 0;
    int iVar5 = 0;
    while (*lcpString != '\0') {
        char cVar1 = *lcpString;
        lVar4 = (lVar2 + lVar4) * 8;

        int iVar3 = (int)cVar1;
        if (cVar1 == 0x5F) {
            lVar4 += 0x27;
        }
        else if (cVar1 >= 0x61) {
            lVar4 += (iVar3 - 0x54);
        }
        else if (cVar1 >= 0x41) {
            lVar4 += (iVar3 - 0x34);
        }
        else if (cVar1 >= 0x2F) {
            lVar4 += (iVar3 - 0x2D);
        }
        else if (cVar1 == 0x2F) {
            lVar4 += 2;
        }
        else if (cVar1 == 0x2D) {
            lVar4++;
        }

        iVar5++;
        lcpString++;
        if (iVar5 > 11) {
            return lVar4;
        }
        lVar2 = lVar4 << 2;
    }
    while (iVar5 < 12) {
        iVar5++;
        lVar4 *= 0x28;
    }
    return lVar4;
}

void GtIDUnCompress(GtID lID, char* lcpString) {
    char cVar1;
    char cVar2;
    for (int i = 11; i > -1; i--) {
        cVar1 = lID % 0x28;
        if (cVar1 == '\'') {
            cVar2 = '_';
        }
        else if (cVar1 >= 0x72) {
            cVar2 = cVar1 + '4';
        }
        else if (cVar1 >= 0x03) {
            cVar2 = cVar1 + '-';
        }
        else if (cVar1 == 0x00) {
            cVar2 = ' ';
        }
        else {
            cVar2 = '\0';
        }
        *(char*)(lcpString + i) = cVar2;
        lID /= 0x28;
    }
    lcpString[12] = 0;
}

GtID GtIDMaskCharacters(GtID lID, RwInt32 lnStartIndex, RwInt32 lnEndIndex) {
	if (lnStartIndex > 0) {
		lID %= (unsigned long)(gaGtIDCharacterMasks + (12 - (int)lnStartIndex) * 8);
	}
	if (lnEndIndex < 11) {
		lID -= lID % (unsigned long)(gaGtIDCharacterMasks + (11 - (int)lnEndIndex) * 8);
	}
	return lID;
}

GtID GtIDScroll(GtID, int) {
	return GtID();
}

GtID GtIDConcatenate(GtID, GtID) {
	return GtID();
}

RwInt32 GtIDGetLength(GtID) {
	return RwInt32();
}

void GtIDConvertToString(GtID lID, char* lpcString) {
	GtIDUnCompress(lID, lpcString);
	char* lpcTemp = lpcString + 0xb;
	if ((lpcString[0xb] == ' ') && (lpcString <= lpcTemp)) {
		*lpcTemp = '\0';
		while (true) {
			lpcTemp--;
			if ((*lpcTemp != ' ') || (lpcTemp < lpcString)) {
				break;
			}
			*lpcTemp = '\0';
		}
	}
}

RwInt32 GtIDExtractTrailingNumber(GtID) {
    return 0;
}