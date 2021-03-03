#ifndef BOAPTFLYINGTEXT_H
#define BOAPTFLYINGTEXT_H

#include "BoFlashEffectBase.h"
#include "../../HUD/BoHUDText2dObject.h"

CBoHUDText2dObject::EStyle keFlyingTextStyle = CBoHUDText2dObject::EStyle::eStylePanelMessagePM1;

class CBoFlyingTextEffect : CBoFlashEffectBase {
public:
	void Render() override;
};

#endif // !#define BOAPTFLYINGTEXT_H
