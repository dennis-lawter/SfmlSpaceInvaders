#include "util.hh"
#include <iostream>

namespace util {
	float lerp(float x0, float x1, float p) {
		p = clamp(p, 0.f, 1.f);
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
