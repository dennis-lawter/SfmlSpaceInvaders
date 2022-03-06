#include "Ufo.hpp"

Ufo::Ufo()
	: GameObject(resources::textures["ufo"], 0, 8) {
	ufoFireSound.setBuffer(resources::soundFile["ufoFire"]);
	if (rand() % 2 == 0) {
		this->sprite.setPosition(defines::WIDTH, 8);
		isMovingLeft = true;
	} else {
		this->sprite.setPosition(-this->getWidth(), 8);
		isMovingLeft = false;
	}
	ufoFireRandom = rand() % defines::UFO_FIRE_RANGE + defines::UFO_FIRE_START;
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

void Ufo::ufoFire() {
	if (hasFired) {
		return;
	}
	if (this->getX() + this->getWidth() / 2 < ufoFireRandom && isMovingLeft) {
		ufoFireSound.play();
		hasFired = true;
		return;
	} else if (this->getX() + this->getWidth() / 2 > ufoFireRandom && !isMovingLeft) {
		ufoFireSound.play();
		hasFired = true;
		return;
	}
}

void Ufo::update() {
	move();
	ufoFire();
}