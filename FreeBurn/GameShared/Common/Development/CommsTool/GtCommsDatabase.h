#pragma once

namespace GtComms {
	class CGtCommsDatabase {
	public:
		void AddEntry(int *,   const char *, const char *, const char *, int, int,   int,   int);
		void AddEntry(float *, const char *, const char *, const char *, int, float, float, int);
		void RemoveEntry(float *);
	};

	class CGtCommsToolBase {
	public:
		static CGtCommsToolBase * mpToolBase;
		CGtCommsDatabase mDatabase;

		void Construct(const char * lpcFileServerRoot);
	};
}
