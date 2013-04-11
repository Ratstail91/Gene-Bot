#ifndef MATHUTILITIES_H_
#define MATHUTILITIES_H_

#include <cmath>

#ifndef Squared
#define Squared(x) ((x)*(x))
#endif

inline float Distance(float x1, float y1, float x2, float y2) {
	return sqrt(Squared(x2 - x1) + Squared(y2 - y1));
}

inline float DistanceSquared(float x1, float y1, float x2, float y2) {
	return Squared(x2 - x1) + Squared(y2 - y1);
}

#endif
