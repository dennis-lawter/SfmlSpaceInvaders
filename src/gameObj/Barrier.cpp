#include "Barrier.hpp"

Barrier::Barrier(int x, int y)
	: GameObject(resources::textures["barrier"], x, y + 100) {
		startingPosition = getPosition();
		destination = {x, y};
	}