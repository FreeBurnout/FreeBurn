#include "../BoMenuFlowManager.h"
#include "../../BoFlashMovieManager.h"
#include "../../../Menu/BoMenuChoices.h"
#include "../../../../Common/Menu/BoFlashTextureManager.h"
#include "../../../../../../GameShared/Common/System/GtFSM.h"

// DONE
void CBoLocationSelectState::Action(EGtStateAction leAction) {
	if (leAction == EGtStateAction::Enter) {
		EBoTrackLocale locale = gMenuChoices.GetChosenCity();
		mbDictionaryPrepared = false;
		LoadTextureDictionaryForCity(locale);
	} else if (!mbDictionaryPrepared) {
		bool dictPrepared = gFlashTextureManager.PrepareTextureDictionary();
		mbDictionaryPrepared = dictPrepared;
		if (dictPrepared) {
			gFlashMovieManager.PlayMovie(EFlashMovie::LocationSelect, true);
		}
	}
}

// DONE
void CBoLocationSelectState::LoadTextureDictionaryForCity(EBoTrackLocale leSelection) {
	switch (leSelection) {
	case EBoTrackLocale::Invalid:
	case EBoTrackLocale::None:
		return;
	case EBoTrackLocale::Detroit:
		gFlashTextureManager.SetTextureDictionary(ETextureDictionary::Detroit);
		break;
	case EBoTrackLocale::Tokyo:
		gFlashTextureManager.SetTextureDictionary(ETextureDictionary::Tokyo);
		break;
	default:
		gFlashTextureManager.SetTextureDictionary(ETextureDictionary::HongKong);
		break;
	}
}