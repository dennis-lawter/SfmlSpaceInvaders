#include "Powerup.hpp"

Powerup::Powerup(defines::PowerUp powerupSelect, float ufoPosition)
	: GameObject(resources::textures[defines::POWER_UP_LIST[powerupSelect]], ufoPosition, 16) {
	//powerupSound.setBuffer(resources::soundFile[powerupSelect]);
	this->powerupSelect = powerupSelect;

}

void Powerup::oneUp() {
	if (score::currentLives < defines::LIVES_CAP) {
		score::currentLives++;
	} else {
		score::score += 1000;
	}
}

bool Powerup::isOffScreen() {
	return (this->getY() > defines::HEIGHT);
}

void Powerup::grantPowerUp() {
	switch (powerupSelect) {
	case defines::PowerUp::OneUp:
		oneUp();
		break;
	default:
		break;
	}
}

void Powerup::update() {
	this->sprite.move(0, speed);
}