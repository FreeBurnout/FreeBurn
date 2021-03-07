#ifndef GTUNICODE_H
#define GTUNICODE_H

#include <ostypes.h>

typedef char16_t GtUTF16; // Somehow it was originally unsigned short. This is practically the same, anyway.

class CGtUnicode {
	template <typename ... T>
	unsigned short * PrintStringN(int, GtUTF16 *, const GtUTF16 *, const T& ... args);
}; 
#endif