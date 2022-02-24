#include "Player.hpp"

Player::Player()
	: GameObject(resources::textures["defender"], 60, 120) {}

void Player::deleteBullet() {
	delete bullet;
	bullet = nullptr;
}

void Player::fire() {
	if (!bullet) {
		bullet = new PlayerBullet(getX() + 3);
	}
}

void Player::testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers) {
	if (!bullet) {
		return;
	}
	if (baddies.testOneForCollision(*bullet, true)) {
		// bullet hits a baddie
		deleteBullet();
		score::score += 100;
	} else if (barriers.testOneForCollision(*bullet, true)) {
		// bullet hits a barrier
		deleteBullet();
	} else if (bullet->isOffScreen()) {
		//deletes bullet when it leaves screen
		deleteBullet();
	}
}

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
	if (bullet) {
		bullet->update();
	}
	if (playerIsMovingLeft) {
		if (getX() > 0) {
			sprite.move(-speed, 0);
		}
	}
	if (playerIsMovingRight) {
		if (getX() < 120) {
			sprite.move(speed, 0);
		}
	}
}

void Player::draw(RenderWindow& window) {
	if (bullet) {
		bullet->draw(window);
	}
	GameObject::draw(window);
}