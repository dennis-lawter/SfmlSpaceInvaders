#include "Player.hpp"

Player::Player()
	: GameObject(resources::textures["defender"], 60.f, 300.f) {
	pewSound.setBuffer(resources::soundFile["defenderpew"]);
	startingPosition = getPosition();
	this->sprite.setTextureRect(IntRect(0, 0, 8, 8));
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

void Player::defenderExplode() {
	agePercentage = ((float)age) / timeToLive;

	age++;

	initialColor = this->sprite.getColor();
	if (initialColor == finalColor) return;

	Color color;
	color.r = util::lerp(initialColor.r, finalColor.r, agePercentage);
	color.g = util::lerp(initialColor.g, finalColor.g, agePercentage);
	color.b = util::lerp(initialColor.b, finalColor.b, agePercentage);
	color.a = util::lerp(initialColor.a, finalColor.a, agePercentage);

	this->sprite.setColor(color);
}

void Player::curved() {
	if (bullet->getX() + 0.2 < this->getX() + 3) {
		bullet->shift = SHIFT_SPEED; //((bullet->getY() - this->getY()) / (bullet->getX() - this->getX())) * (MAX_SHIFT_SPEED - this->getX());
	} else if (bullet->getX() - 0.2 > this->getX() + 3) {
		bullet->shift = -SHIFT_SPEED;
	} else
		bullet->shift = 0;
}

void Player::testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers, ParticleGroup& particles) {
	if (!bullet) {
		return;
	}
	if (baddies.testOneForCollision(bullet, true)) {
		// bullet hits a baddie
		int randomBloodOnScreen = util::rangedRand(6, 10);
		score::score += 100;
		//blood pop
		Color blood(0xff0000bb);
		for (int i = 0; i < 30; i++) {
			blood.r = util::rangedRand(128, 255);
			particles.createParticleObject({
				bullet->getPosition(),
				{
					util::rangedRandFloat(-0.2f, 0.2f, 100),
					util::rangedRandFloat(-0.2f, 0.2f, 100)
				},
				{
					util::rangedRandFloat(-0.008f, 0.008f, 100),
					util::rangedRandFloat(0.002f, 0.008f, 100)
				},
				60,
				blood,
				Color(0xff000000)
				});
		};
		//blood on screen
		blood.a = 19;
		for (int i = 0; i < randomBloodOnScreen; i++) {
			blood.r = util::rangedRand(128, 255);
			particles.createParticleObject({
				{bullet->getX() + util::rangedRandFloat(-40.0f, 40.0f, 100) - 5,
				bullet->getY() + util::rangedRandFloat(-15.0f, 40.0f, 100) - 10},
				{0.f, util::rangedRandFloat(0.02f, 0.05f, 100)},
				{0.f, -0.0005f},
				120,
				blood,
				Color(0xff000000),
				10.f
				});
		}
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
	if (playerIsMovingLeft && !playerIsMovingRight) {
		if (getX() > 0) {
			sprite.move(-speed, 0);
		}
	}
	if (playerIsMovingRight && !playerIsMovingLeft) {
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
	if (isInvuln) {
		View view = window.getView();
		Vector2f center = view.getCenter();
		center.x += util::rangedRandFloat(-0.8f, 0.8f, 100);
		center.y += util::rangedRandFloat(-0.4f, 0.4f, 100);
		view.setCenter(center);
		window.setView(view);
	}
	if (animationSwap && animationBuffer > animationTimer) {
		this->sprite.setTextureRect(IntRect(8, 0, 8, 8));
		animationSwap = !animationSwap;
		animationBuffer = 0;
	} else if (!animationSwap && animationBuffer > animationTimer) {
		this->sprite.setTextureRect(IntRect(0, 0, 8, 8));
		animationSwap = !animationSwap;
		animationBuffer = 0;
	}
	animationBuffer++;
	GameObject::draw(window);
}
