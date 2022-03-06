#include "Ufo.hpp"

Ufo::Ufo()
	: GameObject(resources::textures["ufo"], 0, 8) {
	if (rand() % 2 == 0) {
		this->sprite.setPosition(defines::WIDTH, 8);
		isMovingLeft = true;
	} else {
		this->sprite.setPosition(-this->getWidth(), 8);
		isMovingLeft = false;
	}
}

void Ufo::move() {
	if (isMovingLeft) {
		this->sprite.move(-speed, 0);
	} else {
		this->sprite.move(speed, 0);
	}
}

bool Ufo::isOffScreen() {
	return (this->getX() < -this->getWidth() - 1 || this->getX() > defines::WIDTH + 1);
}

void Ufo::update() {
	move();
}