#ifndef BOHUDTEXT2DOBJECT_H
#define BOHUDTEXT2DOBJECT_H

#include "../../../Shared/Graphical/Common/2D/Gt2dObject.h"
#include "../../../Shared/Numeric/Math/PC/GtV4dPC.h"
#include "../../../Shared/System/Common/Unicode/GtUnicode.h"

static CGtV4d kaHUDV4d_HUDDarkTextColours[10];
static CGtV4d kaVGradientEmbossBaseColours[2];
static CGtV4d kHUDV4d_HUDM2LightTextColour;
static CGtV4d kHUDV4d_HUDM2DarkTextColour;
static CGtV4d kHUDV4d_HUDDarkGreyTextColour;
static CGtV2d kHUDText2dObjectEmbossOffset;
static CGtV2d kBoHUDText2dObjectM1ZoomPoint;
static CGtV2d kM1OutExtraZoomPoint;
static CGtV2d kM3MoveDist;

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

	static CGtV4d mgLightTextColour;
	static CGtV4d mgDarkTextColour;
	static CGtV4d mgaPlayerListColours[5];
	static CGtV4d mgaVGradientEmbossGradientColours[4];

	static void Prepare(void);
	static void Prepare(const CGtV2d&, const CGtV2d&, float, EStyle, const GtUTF16*);
};

#endif // !#define BOHUDTEXT2DOBJECT_H
