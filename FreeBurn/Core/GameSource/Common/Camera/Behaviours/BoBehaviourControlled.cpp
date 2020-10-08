#include "BoBehaviourControlled.h"

void CBoBehaviourControlled::Zoom(float lrZoom) {
    float fVar1 = (float)(
        (int)(mrZoomInterpolation + lrZoom) * (0.0 < mrZoomInterpolation) + lrZoom
    );
    mrZoomInterpolation = (int)fVar1 * ((int)(fVar1 < 1.0) | (int)(fVar1 >= 1.0)) * 1.0;
}
