#include "BoHUDComponent.h"
#include "BoHUDText2dObject.h"

CGtV4d CBoHUDText2dObject::mgLightTextColour = CGtV4d(192, 192, 192, 255);
CGtV4d CBoHUDText2dObject::mgDarkTextColour = CGtV4d(64, 64, 64, 255);

CBoHUDText2dObject::CBoHUDText2dObject(uint16_t param_1, uint16_t param_2) {
	if (param_1 == 0 || param_2 != -1) {
		return;
	}
	
	kHUDV4d_HUDDarkGreyTextColour = CGtV4d(0x78, 0x78, 0x78, 0xFF);
	kHUDV4d_HUDM2LightTextColour = CGtV4d(0xD2, 0x13, 0x08, 0xFF);
	kHUDV4d_HUDM2DarkTextColour = CGtV4d(0x78, 0x0A, 0x02, 0xFF);

	CGtV4d kaHUDV4d_HUDDarkTextColours[10] = {
		CGtV4d(0xE9, 0xB6, 0x2F, 0xFF) / 255.f,
		CGtV4d(0x99, 0x00, 0x00, 0xFF) / 255.f,
		CGtV4d(0x99, 0x66, 0x00, 0xFF) / 255.f,
		CGtV4d(0xCC, 0x99, 0x33, 0xFF) / 255.f,
		CGtV4d(0x00, 0x66, 0x99, 0xFF) / 255.f,
		CGtV4d(0x33, 0x33, 0x66, 0xFF) / 255.f,
		CGtV4d(0x33, 0x00, 0x33, 0xFF) / 255.f,
		CGtV4d(0x66, 0x33, 0x00, 0xFF) / 255.f,
		CGtV4d(0x66, 0x33, 0x33, 0xFF) / 255.f,
		CGtV4d(0x2F, 0x2C, 0x55, 0xFF) / 255.f
	};

	kHUDText2dObjectEmbossOffset = CGtV2d(-1.25, 1.25);

	CGtV4d kaVGradientEmbossBaseColours[2] = {
		CGtV4d(0xFF, 0xFF, 0xFF, 0xFF) / 255.f,
		CGtV4d(0xFF, 0x98, 0x7C, 0xFF) / 255.f
	}; 

	kBoHUDText2dObjectM1ZoomPoint = CGtV2d(0.5, 0.8);
	kM1OutExtraZoomPoint = CGtV2d(0.5, 0.4);
	kM3MoveDist = CGtV2d(0.0, 120.0);

	CGtV4d mgaPlayerListColours[5] = {
		CGtV4d(0xDC, 0xDC, 0xDC, 0xFF) / 255.f,
		CGtV4d(0x5E, 0x32, 0x2E, 0xFF) / 255.f,
		CGtV4d(0x5E, 0x58, 0xAA, 0xFF) / 255.f,
		CGtV4d(0x00, 0x00, 0x00, 0x00) / 255.f,
		CGtV4d(0xDC, 0x78, 0x00, 0xFF) / 255.f
	};
}

void CBoHUDText2dObject::Prepare() {

}

void CBoHUDText2dObject::Prepare(const CGtV2d&, const CGtV2d&, float, EStyle leStyle, const GtUTF16* lpString) {

}