#include "Powerup.hpp"

Powerup::Powerup(defines::PowerUp powerupSelect, float ufoPosition)
	: GameObject(resources::textures[defines::POWER_UP_LIST[powerupSelect]], ufoPosition, 16) {
		//powerupSound.setBuffer(resources::soundFile[powerupSelect]);
	}

bool Powerup::isOffScreen() {
	return (this->getY() > defines::HEIGHT);
}

void Powerup::update() {
	this->sprite.move(0,speed);
}