#include "BaddieBullet.hpp"

bool BaddieBullet::offScreen() {
	return (this->getY() >= 128);
}

void BaddieBullet::update() {
    this->sprite.move(0, 1);
}