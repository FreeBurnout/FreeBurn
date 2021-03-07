#ifndef GTSYSCONFIG_H
#define GTSYSCONFIG_H

#include <rwcore.h>

class CGtTimeStamp {
	RwUInt32 muValue;

	bool operator==(const CGtTimeStamp& param);
	bool operator!=(const CGtTimeStamp& param);
	bool operator>(const CGtTimeStamp& param);
	bool operator<(const CGtTimeStamp& param);
	bool operator>=(const CGtTimeStamp& param);
	bool operator<=(const CGtTimeStamp& param);
};

#endif // !#define GTSYSCONFIG_H
