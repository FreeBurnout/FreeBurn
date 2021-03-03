#ifndef BODRIVABLEVEHICLEPHYSICS_H
#define BODRIVABLEVEHICLEPHYSICS_H
class CBoDrivableVehiclePhysics {

};
enum class EBoForceType {
	eBoForceTypeAirRam = 0,
	eBoForceTypeAirResistance = 1,
	eBoForceTypeBlowOut = 2,
	eBoForceTypeBodyCollision = 3,
	eBoForceTypeBoostStart = 4,
	eBoForceTypeBrake = 5,
	eBoForceTypeBraking = 6,
	eBoForceTypeCrashbreaker = 7,
	eBoForceTypeDrag = 8,
	eBoForceTypeDrift = 9,
	eBoForceTypeDrivingForces = 10,
	eBoForceTypeExplosion = 11,
	eBoForceTypeFriction = 12,
	eBoForceTypeGravity = 13,
	eBoForceTypeLowSpeedDriving = 14,
	eBoForceTypeSlamReaction = 15,
	eBoForceTypeStandingOnEnd = 16,
	eBoForceTypeSuspension = 17,
	eBoForceTypeSurfaceFriction = 18,
	eBoForceTypeTrailer = 19,
	eBoForceTypeTranslation = 20,
	eBoForceTypeWheelCollision = 21,
	eBoForceTypeWheelFriction = 22,
	eBoForceTypeWheelLateral = 23,
	eBoForceTypeWheelLongitudinal = 24,
	eBoForceTypeWheelTurning = 25,
	eBoForceTypeWind = 26,
	eBoForceTypeWindDefiance = 27,
	eBoForceTypeWindResistance = 28,
	eBoForceTypeWorldFriction = 29,
	eBoForceTypeWorldCollision = 30,
	eBoForceTypeWrongWayWall = 31,
	eBoForceTypeCount = 32
};
#endif // !#define BODRIVABLEVEHICLEPHYSICS_H
