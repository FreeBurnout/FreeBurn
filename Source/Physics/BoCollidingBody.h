#ifndef BOCOLLIDINGBODY_H
#define BOCOLLIDINGBODY_H

#include <rwcore.h>

#include "BoActiveBody.h"
#include "BoConvexHull.h"
#include "../World/Common/BoCrashCombo.h"
#include "../World/Common/Traffic/BoTrafficVehicle.h"
#include "BoDrivableVehiclePhysics.h"
#include "BoVehicleWorldTriangleCacheManager.h"
#include "../../Shared/Numeric/Math/PC/GtMatrix3x4PC.h"
#include "../../Shared/Numeric/Math/PC/GtMathPC.h"
#include "../../Shared/Geometric/PC/GtSpherePC.h"
#include "../../Shared/Geometric/GtIntersection.h"

using namespace GtMathPC;

enum ECollidingBodyType {
	eCRB_NONE = 0, 
	eCRB_PLAYERCAR = 1, 
	eCRB_AICAR = 2, 
	eCRB_NETWORKCAR = 3, 
	eCRB_TRAFFICCAR = 4, 
	eCRB_TRAFFICARTICULATED = 5, 
	eCRB_CHECKEDTRAFFIC = 6, 
	eCRB_PROP = 7, 
	eCRB_BODYPART = 8
};
enum EBoBoundingShape {
	eBoundingSphere = 0, 
	eBoundingBox = 1, 
	eBoundingConvexHull = 2
};

class CBoTensor { };

class CBoWorldCollisionInfo { };

class CBoCollidingBody {
public:
	bool _mbCacheOverflowed;
	CBoVehicleWorldTriangleCache _mGlobalWorldTriangleCache;
	CBoTensor mInverseInertiaTensorLocal;
	CBoTensor mInverseInertiaTensorWorld;
	CGtMatrix3x4 mInverseMatrix;
	CGtV3dPlus mLinearVelocityAndSpeed;
	CGtV3d mVelocityDir;
	CGtV3d mAngularVelocity;
	CGtV3d mAngularMomentum;
	CGtV3d mTotalForce;
	CGtV3d mTotalTorque;
	CGtV3d mTotalImpulse;
	CGtV3d mTotalImpulseAngular;
	CGtV3d mTotalTranslation;
	CGtV3d mSkewerExitDir;
	CGtV3d mLastBodyCollisionPoint;
	CBoWorldCollisionInfo mWorldCollisionInfo;
	CGtSphere mBoundingSphere;
	CGtAxisAlignedBox mBoundingBox;
	RwReal mrMass;
	RwReal mrCOGHeight;
	RwReal mrCoeffOfRestitution;
	RwReal mrCoeffOfFriction;
	CBoWorldTriangleCacheBase* mpCollisionCache;
	CGtMatrix3x4* mpMatrix;
	void* mpBoundingShape;
	RwUInt8 meBoundingShape;
	bool mbStopDead;
	bool mbNonImpulse;
	bool mbCrashing;
	bool mbBodyCollision;
	bool mbWorldCollision;
	bool mbWorldImpulse;
	bool mbSkewered;
	RwInt8 me8Type;
	RwInt8 mn8CurrentWorldUnit;
	RwInt8 mn8CollisionWorldIndex;
	RwUInt8 mu8CrashIndex;
	CBoActiveBody* mpActiveBody;

	void Construct();
	bool Prepare();
	void Update(float);
	void Integrate(float);
	void ApplyTotalTranslation();
	void Release();
	void Destruct();
	void SetInitialMatrix(const CGtMatrix3x4&);
	void SetRealisticMomentsOfInertia();
	void CacheWorldTriangles(CGtSphere);
	bool AddCachedWorldTriangle(const CGtPolygonIntersectionResult&);
	void StartCrashing(unsigned char, CBoCrashStartInfo*);
	void StopCrashing();
	void CollideWithWorld(int);
	void StopImmediately();
	void ClearAccumulatedValues();
	RwReal CalculateCollisionImpulseWithBody(CBoCollidingBody&, CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*);
	RwReal CalculateCollisionImpulseWithTraffic(CBoTrafficVehicle*, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*);
	RwReal CalculateCollisionImpulseWithInanimateObject(CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*);
	RwBool HasFallenThroughWorld();
	void SetMatrix(const CGtMatrix3x4&);
	CGtMatrix3x4 GetMatrix() const;
	CGtMatrix3x4* GetInverseMatrix() const;
	void SetMomentOfInertia(float, float, float);
	void SetBoundingBox(const CGtAxisAlignedBox&);
	void GetBoundingBox(CGtAxisAlignedBox*);
	void WorldPointToLocalPoint(CGtV3d, CGtV3d*);
	void LocalPointToWorldPoint(CGtV3d, CGtV3d*);
	void LocalVectorToWorldVector(CGtV3d, CGtV3d*);
	void WorldVectorToLocalVector(CGtV3d, CGtV3d*);
	void ApplyPositionedImpulse(CGtV3d, CGtV3d, EBoForceType);
	void ApplyPositionedForce(CGtV3d, CGtV3d, EBoForceType);
	void ApplyCOMForce(CGtV3d, EBoForceType);
	void ApplyCOMImpulse(CGtV3d, EBoForceType);
	void ApplyTorque(CGtV3d);
	void Translate(CGtV3d);
	void NeutralizeAtComponentOfAngularMomentum();
	bool IsStoppedDead() const;
	void SetStoppedDead(bool);
	bool IsCrashing() const;
	CGtV3d GetPointVelocity(CGtV3d);
	CGtV3d GetLinearVelocity() const;
	CGtV3d GetAngularVelocity() const;
	CGtV3d GetVelocityDir() const;
	CGtV3d GetPosition() const;
	// GetAngularMomentum(); TODO: return type
	RwReal GetSpeedKPH() const;
	RwReal GetSpeedMPH() const;
	RwReal GetSpeedMPS() const;
	RwInt32 GetCurrentWorldUnit() const;
	RwUInt64 GetCrashIndex() const;
	ECollidingBodyType GetType() const;
	bool IsVehicle() const;
	bool GetWorldCollision() const;
	CBoWorldCollisionInfo GetWorldCollisionInfo();
	RwReal GetMass() const;
	void CalculateTorqueFromPositionedForce(CGtV3d*, CGtV3d, CGtV3d);
	RwInt32 GetCollisionWorldIndex() const;
	void SetCollisionWorldIndex(int);
	bool GetBodyCollision() const;
	CBoConvexHull* GetConvexHull();
	CGtV4d GetBoundingSphere();
	void SetLinearVelocity(CGtV3d);
	bool IsOutsideCollision();
	EBoBoundingShape GetBoundingShape() const;
	RwReal CalculateEnergyFromCollisionImpulse(CBoCollidingBody*, CBoCollidingBody*, CGtV3d, float);
	CBoActiveBody* GetActiveBody();
	void SetActiveBody(CBoActiveBody*);
	bool HasHadBodyCollision() const;
	bool HasHadWorldCollision() const;
	bool HasHadCollision() const;
	bool DebugCheckWorldIntersection();
	void OutputForcesDebug(char*, EBoForceType, const CGtV3d*, const CGtV3d*);
}; 

#endif // !define BOCOLLIDINGBODY_H