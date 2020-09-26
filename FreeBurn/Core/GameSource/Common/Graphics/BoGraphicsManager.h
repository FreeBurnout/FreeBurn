#include <SDL.h>

extern SDL_Renderer * renderer;

class CBoGraphicsManagerBase {
public:
	void DrawBootLoadingScreen(float lrProgress);
	void CloseViewport();
    void Update();
};

enum class EBoFullScreenPassBlendMode {
    Normal = 0, 
    Additive = 1,
    AdditiveDestAlpha = 2, 
    Subtractive = 3, 
    Max = 4
};

class CBoEATraxDisplay {
public:
	void Construct();
	void Render();
};

extern CBoEATraxDisplay gEATraxDisplay;