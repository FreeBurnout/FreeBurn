#include "BoGraphicsManager.h"

void CBoSunRenderer::Construct() {
	mpCoronaTexture = 0;
	mpEnvmapCoronaTexture = 0;
};

CGtTexture * CBoSunRenderer::mpCoronaTexture;
CGtTexture * CBoSunRenderer::mpEnvmapCoronaTexture;