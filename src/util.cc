#include "util.hh"
#include <iostream>

namespace util {
	float lerp(float x0, float x1, float p) {
		// x0 = 5
		// x1 = 9
		// p = .75f
		// 5 + ((9 - 5) * .75)
		// 5 + (4 * .75)
		// 5 + 3
		// 8
		p = (p > 1) ? 1 : p;
		p = (p < 0) ? 0 : p;
		return x0 + ((x1 - x0) * p);
	}

	Vector2f tween(Vector2f start, Vector2f end, float p) {
		float x = lerp(start.x, end.x, p);
		float y = lerp(start.y, end.y, p);
		return Vector2f(x, y);
	}

	int rangedRand(int min, int max) {
		if (max < min) {
			swap(max, min);
		}
		return rand() % ((max + 1) - min) + min;
	}
}