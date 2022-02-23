#include "Player.hpp"

Player::Player()
	: GameObject(resources::textures["defender"], 60, 120) {}

bool Player::testManyForCollision(vector<GameObject>& objs) {
	for (auto obj = objs.begin(); obj != objs.end(); obj++) {
		if (testCollision(*obj)) {
			objs.erase(obj);
			return true;
		}
	}
	return false;
}

void Player::update() {
	if (this->playerIsMovingLeft) {
		if (this->getX() > 0) {
			this->sprite.move(-speed, 0);
		}
	}
	if (this->playerIsMovingRight) {
		if (this->getX() < 120) {
			this->sprite.move(speed, 0);
		}
	}
}