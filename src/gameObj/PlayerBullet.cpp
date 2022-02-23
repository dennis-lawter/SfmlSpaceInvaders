#include "PlayerBullet.hpp"

PlayerBullet::PlayerBullet(float x)
	: GameObject(resources::textures["bullet"], x, 112) {}

void PlayerBullet::update() {
    this->sprite.move(0, -speed);
}