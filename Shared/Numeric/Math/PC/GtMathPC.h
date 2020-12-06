#ifndef GTMATHPC_H
#define GTMATHPC_H

#include "GtV3dPC.h"
#include "GtV4dPC.h"

namespace GtMathPC {
class CGtV2d { 
	float marValues[2];

	inline CGtV2d& operator =(const CGtV2d&) { }

	CGtV2d() { }
	CGtV2d(CGtV2d, const CGtV2d&) { }
	CGtV2d(CGtV2d, float, float) { }

	RwReal X(CGtV2d) const { }
	RwReal Y(CGtV2d) const { }
	RwReal U(CGtV2d) const { }
	RwReal V(CGtV2d) const { }
	void Set(CGtV2d, float, float) { }
	void SetX(CGtV2d, float) { }
	void SetY(CGtV2d, float) { }
	void SetU(CGtV2d, float) { }
	void SetV(CGtV2d, float) { }
	void ConvertToRwV2d(CGtV2d, RwV2d*) const { }
	void SetFromRwV2d(CGtV2d, const RwV2d*) { }

	inline CGtV2d operator +=(const CGtV2d&) { }
	inline CGtV2d operator +=(float) { }

	inline CGtV2d operator +(const CGtV2d&) const { }
	inline CGtV2d operator +(float) const { }

	inline CGtV2d operator -=(const CGtV2d&) { }
	inline CGtV2d operator -=(float) { }

	inline CGtV2d operator -(CGtV2d) const { }
	inline CGtV2d operator -(const CGtV2d&) const { }
	inline CGtV2d operator -(float) const { }

	inline CGtV2d operator *=(const CGtV2d&) { }
	inline CGtV2d operator *=(float) { }

	inline CGtV2d operator *(const CGtV2d&) const { }
	inline CGtV2d operator *(float) const { }

	inline CGtV2d operator /=(const CGtV2d&) { }
	inline CGtV2d operator /=(float) { }

	inline CGtV2d operator /(const CGtV2d&) const { }
	inline CGtV2d operator /(float) const { }

	CGtV2d Zero(CGtV2d) { }
	bool IsZero(CGtV2d) const { }
	bool IsEffectivelyZero(CGtV2d) const { }
	void Normalise(CGtV2d) { }
	RwReal NormaliseGetLength(CGtV2d) { }
	RwReal NormaliseFast(CGtV2d) { }
	RwReal GetLength(CGtV2d) const { }
	RwReal GetSquaredLength(CGtV2d) const { }

	inline bool operator ==(const CGtV2d&) const { }
};
}

#endif // !#define GTMATHPC_H

