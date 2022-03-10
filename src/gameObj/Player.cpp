#include "Player.hpp"

Player::Player()
	: GameObject(resources::textures["defender"], startingPosition.x, startingPosition.y) {
	pewSound.setBuffer(resources::soundFile["defenderpew"]);
}

void Player::deleteBullet() {
	delete bullet;
	bullet = nullptr;
}

void Player::fire() {
	if (!bullet) {
		bullet = new PlayerBullet(getX() + 3, bulletSpeed * bulletSpeedModifier);
		pewSound.play();
	}
}

void Player::invincible() {
	if (buffer < INVULN_TIMER) {
		if ((buffer / BLINK_SPEED) % 2) {
			sprite.setColor(Color::White);
		} else {
			sprite.setColor(Color(0xFFFFFF22));
		}
		buffer++;
	} else {
		isInvuln = false;
		buffer = 0;
	}
}

void Player::curved() {
	if (bullet->getX() + 0.2 < this->getX() + 3) {
		bullet->shift = SHIFT_SPEED; //((bullet->getY() - this->getY()) / (bullet->getX() - this->getX())) * (MAX_SHIFT_SPEED - this->getX());
	} else if (bullet->getX() - 0.2 > this->getX() + 3) {
		bullet->shift = -SHIFT_SPEED;
	} else
		bullet->shift = 0;
}

void Player::testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers) {
	if (!bullet) {
		return;
	}
	if (baddies.testOneForCollision(bullet, true)) {
		// bullet hits a baddie
		score::score += 100;
		if (isPunch) {
			return;
		}
		deleteBullet();
	} else if (barriers.testOneForCollision(bullet, true)) {
		// bullet hits a barrier
		if (isPunch) {
			return;
		}
		deleteBullet();
	} else if (bullet->isOffScreen()) {
		//deletes bullet when it leaves screen
		deleteBullet();
	}
}

bool Player::testManyForCollisionWithBaddieBullet(vector<BaddieBullet>& objs) {
	for (auto obj = objs.begin(); obj != objs.end(); obj++) {
		if (testCollision(*obj)) {
			objs.erase(obj--);
			return true;
		}
	}
	return false;
}

void Player::animateIntro(int framesElapsed) {
	Vector2f start = this->startingPosition;
	Vector2f destination = { 60, 120 };
	float percentage = ((float)framesElapsed) / 220;
	this->setPosition(util::tween(start, destination, percentage));
}

void Player::animateOutro(int framesElapsed) {
	this->sprite.move(0, -speed / 20);
	this->speed++;
}

void Player::update() {
	if (bullet) {
		if (isBulletCurved) {
			curved();
		}
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
	if (isInvuln) {
		invincible();
	}
}

void Player::draw(RenderWindow& window) {
	if (bullet) {
		bullet->draw(window);
	}
	GameObject::draw(window);
}
