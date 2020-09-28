#include "../../../../GameShared/PC/Graphical/GtTexturePC.h"

namespace BoIm3d {
	enum class EBlendMode {
		Normal = 0,
		Additive = 1
	};

	void SetTexture(CGtTexture * lpTexture);
	void SetBlendMode(EBlendMode leBlendMode);
}