#include "Baddie.hpp"

Baddie::Baddie(Texture& texture, int x, int y)
	: GameObject(texture, x, y) {}

void Baddie::moveRight() {
	this->sprite.move(speed, 0);
}

void Baddie::moveLeft() {
	this->sprite.move(-(speed), 0);
}

void Baddie::moveDown() {
	this->sprite.move(0, ADVANCE_DISTANCE);
}