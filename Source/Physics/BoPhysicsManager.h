#ifndef BOPHYSICSMANAGER_H
#define BOPHYSICSMANAGER_H

#include <rwcore.h>

#include "BoActiveBody.h"
#include "BoActiveBodyManager.h"
#include "BoBodyPartPhysics.h"
#include "BoCameraPhysics.h"
#include "BoCheckedTrafficPhysics.h"
#include "BoCollidingBody.h"
#include "BoCollisionDetector.h"
#include "BoDrivableVehiclePhysics.h"
#include "BoInterval.h"
#include "BoPropPhysics.h"
#include "../World/Common/BoRaceCar.h"
#include "../World/Common/BoPropType.h"
#include "BoRaceCarPhysics.h"
#include "BoTrafficPhysics.h"
#include "BoVehicleParams.h"
#include "BoVehiclePhysics.h"
#include "../Camera/Behaviours/BoCameraBehaviour.h"

using namespace GtMathPC;

static RwInt32 _gnWorldCollisionPCID = -1;
static RwInt32 _gnBodyCollisionPCID = -1;
static RwInt32 _gnBodyUpdatePCID = -1;
static RwInt32 _gnBodyUpdatePlayerCarPCID = -1;
static RwInt32 _gnBodyUpdateAICarPCID = -1;
static RwInt32 _gnBodyUpdateNetworkCarPCID = -1;
static RwInt32 _gnBodyUpdateTrafficCarPCID = -1;
static RwInt32 _gnBodyUpdatePropPCID = -1;
static RwInt32 _gnBodyUpdateBodyPartsPCID = -1;
static RwInt32 _gnVehicleDeformationPCID = -1;
static RwInt32 _gnClipPolyWithConvexHullPCID = -1;
static RwInt32 _gnBoxWorldCollisionPCID = -1;
static RwInt32 _gnBoxBoxCollisionPCID = -1;
static RwInt32 _gnHullWorldCollisionPCID = -1;
static RwInt32 _gnHullHullCollisionPCID = -1;
static RwInt32 _gnDoDrivingWorldCollisionPCID = -1;
static RwInt32 _gnCollideWheelsPCID = -1;
static RwInt32 _gnUpdateSuspensionPCID = -1;
static RwInt32 _gnApplyDrivingForcesPCID = -1;
static RwInt32 _gnCollidingBodyUpdatePCID = -1;
static RwInt32 _gnBodyUpdateVehiclePCID = -1;
static RwInt32 _gnBodyUpdateRaceCarPCID = -1;
static RwInt32 _gnClipPolyWithAABBPCID = -1;
static RwInt32 gnWorldLineCost = -1;
static RwInt32 gnWorldSphereCost = -1;

enum EPhysicsInteractionType {
	ePhysicsInteractNormal = 0,
	ePhysicsInteractAsWorld = 1,
	ePhysicsInteractNone = 2,
	ePhysicsInteractMax = 3
};
enum EShuntSlamType {
	eSST_None = 0,
	eSST_ASlammedIntoB = 1,
	eSST_AShuntedIntoB = 2,
	eSST_BSlammedIntoA = 3,
	eSST_BShuntedIntoA = 4,
	eSST_NumShuntSlamTypes = 5
};

#undef RemoveProp // Mmhmm.

class CBoPhysicsManager {
public:
	bool ActuallyCrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char);
	CBoBodyPartPhysics* AddBodyPart(CBoVehiclePhysics*, int, EBodyPartType);
	CBoCameraPhysics* AddCamera(EPlayerCarIndex, CBoCameraBehaviour*, CGtMatrix3x4*, CGtV3d, CGtV3d);
	void AddRaceCar(CBoRaceCar*, int);
	CBoActiveBody* AddStaticProp(CBoPropInstance*, CGtMatrix3x4*);
	void AddTrafficVehicle(CBoTrafficVehicle*);
	void ApplySafePositionedImpulse(CBoCollidingBody*, CGtV3d, CGtV3d, EBoForceType);
	void ApplyShuntOrSlamReaction(CBoCollidingPair*, float*, float*, float*);
	void ApplyShuntReaction(CBoDrivableVehiclePhysics*, CBoDrivableVehiclePhysics*, CGtV3d, CGtV3d, float, ESlamShuntComboState);
	void ApplySlamReaction(CBoDrivableVehiclePhysics*, CBoDrivableVehiclePhysics*, CGtV3d, CGtV3d, float, ESlamShuntComboState);
	void BodyBodyResponse(CBoCollidingPair*, bool);
	void BodyBodyResponse_ApplyImpulse(CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*, CGtV3d, CGtV3d, CGtV3d, EPhysicsInteractionType, EPhysicsInteractionType);
	void BodyBodyResponse_CalculateImpulse(CGtV3d*, CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*);
	bool BodyBodyResponse_CanCollide(CBoActiveBody* lpBodyA, CBoActiveBody* lpBodyB);
	void BodyBodyResponse_CheckForDynamicPropCrash(CBoActiveBody*, CBoActiveBody*);
	void BodyBodyResponse_CheckForPropHitEvent(CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*);
	void BodyBodyResponse_CheckForUnpausing(CBoActiveBody*, CBoActiveBody*);
	bool BodyBodyResponse_Collision(CBoCollidingPair*, CBoHullCollideParams*);
	void BodyBodyResponse_CrashRaceCar(CBoActiveBody*, CBoActiveBody*, CGtV3d*, bool);
	void BodyBodyResponse_DeformTwoVehicles(CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CGtV3d*);
	RwReal BodyBodyResponse_DeformVehicle(CBoActiveBody*, CBoActiveBody*, CGtV3d, CGtV3d, float, float, float*);
	bool BodyBodyResponse_ModifyInteraction(CBoActiveBody*, CBoActiveBody*, EPhysicsInteractionType*, EPhysicsInteractionType*);
	bool BodyBodyResponse_RaceCarShouldCrash(CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*, float, CGtV3d, bool);
	void BodyBodyResponse_Translation(CBoCollidingPair*, CBoHullCollideParams*, CBoActiveBody*, CBoActiveBody*, CBoCollidingBody*, CBoCollidingBody*, EPhysicsInteractionType, EPhysicsInteractionType);
	void BodyCameraResponse(CBoCollidingPair*);
	void BodyPropResponse(CBoCollidingPair*);
	void BodyTrafficResponse(CBoCollidingPair*);
	void CalculateAndApplyCheckingImpulse(CBoVehiclePhysics*, CBoVehiclePhysics*, CBoCollidingPair*, CBoHullCollideParams*, bool);
	bool CalculateAndApplyImpulse(CBoCollidingPair*, CBoHullCollideParams*, float*, float*);
	EShuntSlamType CalculateShuntOrSlam(CBoCollidingPair*, float, float, float, float&, bool&, bool&);
	bool CanCheckCheckedTraffic(CBoRaceCarPhysics*, CBoCheckedTrafficPhysics*);
	bool CanCheckTraffic(CBoCollidingPair*, CBoRaceCarPhysics*, CBoTrafficVehicle*);
	bool CanCrashTrafficBody();
	void CheckedTrafficWithCheckedTrafficResponse(CBoCollidingPair*);
	void CheckedTrafficWithCrashingTrafficResponse(CBoCollidingPair*);
	void CheckedTrafficWithTrafficResponse(CBoCollidingPair*, CBoHullCollideParams*);
	CBoCheckedTrafficPhysics* CheckTrafficBody(CBoActiveBody*, ERaceCarIndex, CGtV3d, bool);
	bool ClearSpaceForCheckedTraffic(const CGtMatrix3x4*, const CGtMatrix3x4*);
	void CollideAndRespondPair(CBoCollidingPair*);
	void Construct();
	bool CrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char);
	bool CrashFurthestAwayCheckedTraffic(const CGtMatrix3x4*, const CGtMatrix3x4*);
	bool CrashTrafficBody(CBoActiveBody*, ERaceCarIndex, unsigned char, bool, bool, bool);
	void Destruct();
	bool DetectAerialTakeDown(CBoRaceCarPhysics*, CBoRaceCarPhysics*, CGtV3d);
	bool DetectTBoneTakeDown(CBoRaceCarPhysics*, CBoRaceCarPhysics*, float, float);
	void DoCrashBreaker(CBoVehiclePhysics*, float, bool, bool);
	void DoTrafficHomingBehaviour(CBoVehiclePhysics*, bool, bool);
	RwInt32 FindFreeTrafficBody();
	CBoActiveBody* GetActiveBody(int);
	void GetBodyProjectionsOfCollisionPoint(CBoCollidingPair*, float*, float*);
	CBoCheckedTrafficPhysics* GetCheckedTrafficPhysics(int); const
	CBoInterval GetDynamicIntervalRange(float, float, int*); const
	RwInt32 GetMaxNumBodies();
	CBoRaceCarPhysics* GetRaceCarPhysics(ERaceCarIndex);
	CBoInterval* GetStaticIntervalRange(float, float, int*); const
	void HandleTrafficBodyImpact(CBoTrafficPhysics*, CBoVehicleParams*, CBoRaceCarPhysics*, bool);
	CBoTrafficPhysics* InduceTrafficVehicleCrash(CBoTrafficVehicle*, CBoVehiclePhysics*, bool);
	void InheritBodyParts(CBoVehiclePhysics*, CBoVehiclePhysics*);
	bool IsBodyPartCollidingWithOwnerVehicle(CBoActiveBody*, CBoActiveBody*);
	bool IsInCollidingPairs(CBoActiveBody*);
	bool MakePropDynamic(CBoActiveBody*, ERaceCarIndex);
	void MakePropStatic(CBoPropPhysics*);
	bool NetworkCrashCheckedTrafficBody(CBoCheckedTrafficPhysics*, unsigned char);
	void PostEffectsUpdate();
	bool Prepare();
	void RaceCarRaceCarResponse(CBoCollidingPair*);
	void RaceCarWithCheckableTraffic(CBoCollidingPair*, CBoHullCollideParams*);
	void RaceCarWithCheckedTrafficResponse(CBoCollidingPair*);
	void Release();
	bool Remove(CBoActiveBody*, bool);
	void RemoveCamera(CBoCameraPhysics*);
	void RemoveFromCheckedTrafficArray(CBoCheckedTrafficPhysics*);
	void RemoveOrphanBodyParts();
	bool RemoveProp(CBoPropInstance*); 
	void RemoveTrafficVehicle(CBoTrafficVehicle*);
	void RemoveVehiclesDetachedBodyParts(CBoVehiclePhysics*);
	void ResetCollisionBools();
	bool ResolvePenetration(CBoCollidingPair*, CBoHullCollideParams*, float*, float*);
	void StopRaceCarBodyPartsCrashing(ERaceCarIndex);
	void TranslatePhysicsObjects();
	void Update(float);
	void UpdateNearMissArray();
	void UpdatePhysicsObjects(float);
	void UpdateSphereTree();
	void VehicleTrafficResponse(CBoCollidingPair*);
	void VehicleTrafficResponseWithoutChecking(CBoCollidingPair*, CBoHullCollideParams*);
	void WorldSafeBodyTranslations(CBoCollidingPair*, CGtV3d*, CGtV3d*);

};



#endif // !#define BOPHYSICSMANAGER_H