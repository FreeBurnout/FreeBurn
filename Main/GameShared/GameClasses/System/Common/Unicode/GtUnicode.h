typedef unsigned short * GtUTF16;

class CGtUnicode {
	template <typename ... T>
	unsigned short * PrintStringN(int, GtUTF16 *, const GtUTF16 *, const T& ... args);
};