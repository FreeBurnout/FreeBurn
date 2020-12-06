#ifndef BOHUDTEXT2DOBJECT_H
#define BOHUDTEXT2DOBJECT_H

#include "../../Shared/Graphical/Common/2D/Gt2dObject.h"

class CBoHUDText2dObject : public CGt2dObject {
public:
	enum EStyle {
		eStyleTitle = 0,
		eStyleSmallMessage = 1,
		eStyleSmallText = 2,
		eStyleGreyText = 3,
		eStyleBigNumber = 4,
		eStyleMediumNumber = 5,
		eStyleBigMessage = 6,
		eStylePanelMessagePM1 = 7,
		eStylePanelMessageNM1 = 8,
		eStylePanelMessagePM2 = 9,
		eStylePanelMessageNM2 = 10,
		eStyleBoostMultiplier = 11,
		eStyleDigitalNumbers = 12,
		eStyleDigitalTimer = 13,
		eStyleWarningText = 14,
		eStyleRatingText = 15,
		eStyleNum = 16
	};

	static void Prepare(const CGtV2d&, const CGtV2d&, float, EStyle, const GtUTF16*);
};

#endif // !#define BOHUDTEXT2DOBJECT_H
