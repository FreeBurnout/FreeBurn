#include <rwcore.h>
#include <boost\circular_buffer\base.hpp>

class CGtVideoImage {
public:
	
};

class CGtVideoDecoder {
public:
	bool mbStop;
	boost::circular_buffer<int, int> mRingBuffer;
	RwInt32 mnDecodeImageBuffer;
	CGtVideoImage * maVideoImages;

	void Abort();
	void Construct();
	bool ViBufIsEmpty();
};