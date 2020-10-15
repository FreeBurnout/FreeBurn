#include "GtVideoDecoderPC.h"

void CGtVideoDecoder::Abort() {
	mbStop = true;
}

void CGtVideoDecoder::Construct() {

};

bool CGtVideoDecoder::ViBufIsEmpty() {
	return false;
}
