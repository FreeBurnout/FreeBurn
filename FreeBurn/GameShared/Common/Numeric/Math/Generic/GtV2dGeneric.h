struct CGtV2d {
public:
	float marValues[2];

	CGtV2d() {
		CGtV2d(0, 0);
	}

	CGtV2d(float a, float b) {
		marValues[0] = a;
		marValues[1] = b;
	}
};