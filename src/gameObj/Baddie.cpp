#include "Baddie.hpp"

Baddie::Baddie(Texture& texture, int x, int y)
 	: GameObject(texture, x, y) {
	int quadrant = util::rangedRand(0, 3);
	switch (quadrant) {
	case 0:
	case 1:
		this->startingPosition.x = util::rangedRand(-32, defines::WIDTH + 32);
		this->startingPosition.y = -32;
		break;
	case 2:
		this->startingPosition.x = defines::WIDTH + 32;
		this->startingPosition.y = util::rangedRand(-32, defines::HEIGHT / 2);
		break;
	case 3:
		this->startingPosition.x = -32;
		this->startingPosition.y = util::rangedRand(-32, defines::HEIGHT / 2);
		break;
	}
	this->setPosition(this->startingPosition);
}

void Baddie::moveRight() {
	this->sprite.move(speed, 0);
}

void Baddie::moveLeft() {
	this->sprite.move(-(speed), 0);
}

void Baddie::moveDown() {
	this->sprite.move(0, ADVANCE_DISTANCE);
}