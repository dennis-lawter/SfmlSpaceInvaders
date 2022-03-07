#include "Powerup.hpp"

Powerup::Powerup(defines::PowerUp powerupSelect, float ufoPosition, Player& defender)
	: GameObject(resources::textures[defines::POWER_UP_LIST[powerupSelect]], ufoPosition, 16) {
	//powerupSound.setBuffer(resources::soundFile[powerupSelect]);
	this->powerupSelect = powerupSelect;
	this->defender = &defender;
}

void Powerup::oneUp() {
	if (score::currentLives < defines::LIVES_CAP) {
		score::currentLives++;
	} else {
		score::score += 1000;
	}
}

void Powerup::coin() {
	score::score += 1000;
}

void Powerup::coinOffScreen() {
	score::score -= 1000;
}

void Powerup::speedUp() {
	defender->speed *= 1.2;
}

void Powerup::speedDown() {
	defender->speed *= 0.8;
}

void Powerup::punch() {
	defender->isPunch = true;
}

void Powerup::bomb() {
	score::currentLives--;
	defender->isInvuln = true;
}

bool Powerup::isOffScreen() {
	return (this->getY() > defines::HEIGHT);
}

void Powerup::grantPowerUp() {
	switch (powerupSelect) {
	case defines::PowerUp::OneUp:
		oneUp();
		break;
	case defines::PowerUp::Coin:
		coin();
		break;
	case defines::PowerUp::SpeedUp:
		speedUp();
		break;
	case defines::PowerUp::SpeedDown:
		speedDown();
		break;
	case defines::PowerUp::Punch:
		punch();
		break;
	case defines::PowerUp::Bomb:
		bomb();
		break;
	default:
		break;
	}
}

void Powerup::update() {
	this->sprite.move(0, speed);
	if (powerupSelect == defines::Coin && isOffScreen()) {
		coinOffScreen();
	}
}