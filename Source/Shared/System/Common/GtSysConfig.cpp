#include "GtSysConfig.h"

bool CGtTimeStamp::operator==(const CGtTimeStamp& param) {
	return muValue == param.muValue;
}

bool CGtTimeStamp::operator!=(const CGtTimeStamp& param) {
	return muValue != param.muValue;
}

bool CGtTimeStamp::operator>(const CGtTimeStamp& param) {
	return muValue > param.muValue;
}

bool CGtTimeStamp::operator<(const CGtTimeStamp& param) {
	return muValue < param.muValue;
}

bool CGtTimeStamp::operator>=(const CGtTimeStamp& param) {
	return muValue >= param.muValue;
}

bool CGtTimeStamp::operator<=(const CGtTimeStamp& param) {
	return muValue <= param.muValue;
}
