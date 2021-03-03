#ifndef GTVECTORELEMENTSPC_H
#define GTVECTORELEMENTSPC_H

namespace GtMathPC {
	class GtAxisTypePC {
	public:
		float lVector[4];
	};

	class GtXAxisTypePC : public GtAxisTypePC {
	public:
		inline GtXAxisTypePC& operator =(GtXAxisTypePC) {}

		inline GtXAxisTypePC() {}
		inline GtXAxisTypePC(const GtXAxisTypePC&) {}
		inline GtXAxisTypePC(float[4]) {}

		inline GtXAxisTypePC operator -() const {}
	};

	class GtYAxisTypePC : public GtAxisTypePC {
	public:
		inline GtYAxisTypePC& operator =(GtYAxisTypePC) {}

		inline GtYAxisTypePC() {}
		inline GtYAxisTypePC(const GtYAxisTypePC&) {}
		inline GtYAxisTypePC(float[4]) {}

		inline GtYAxisTypePC operator -() const {}
	};

	class GtZAxisTypePC : public GtAxisTypePC {
	public:
		inline GtZAxisTypePC& operator =(GtZAxisTypePC) {}

		inline GtZAxisTypePC() {}
		inline GtZAxisTypePC(const GtZAxisTypePC&) {}
		inline GtZAxisTypePC(float[4]) {}

		inline GtZAxisTypePC operator -() const {}
	};

	class GtWAxisTypePC : public GtAxisTypePC {
	public:
		inline GtWAxisTypePC& operator =(GtWAxisTypePC) {}

		inline GtWAxisTypePC() {}
		inline GtWAxisTypePC(const GtWAxisTypePC&) {}
		inline GtWAxisTypePC(float[4]) {}

		inline GtWAxisTypePC operator -() const {}
	};
}
#endif // !#define GTVECTORELEMENTSPC_H