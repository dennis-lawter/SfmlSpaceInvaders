#include "PlayerBullet.hpp"

PlayerBullet::PlayerBullet(float x)
	: GameObject(resources::textures["bullet"], x, 112) {}

bool PlayerBullet::isOffScreen() {
	return (this->getY() <= 8);
}

void PlayerBullet::update() {
    this->sprite.move(0, -speed);
}