#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "groups/BaddieGroup.hpp"
#include "groups/BarrierGroup.hpp"
#include "groups/ParticleGroup.hpp"
#include "PlayerBullet.hpp"
#include "BaddieBullet.hpp"
#include "GameObject.hpp"

class Player : public GameObject {
private:
	void deleteBullet();
	Sound pewSound;
	bool animationSwap = true;
	int animationBuffer = 0;
	int animationTimer = 40;
public:
	const static int INVULN_TIMER = 120;
	const static int BLINK_SPEED = 5;
	const float SHIFT_SPEED = 0.4;
	PlayerBullet* bullet = nullptr;
	float speed = 0.7;
	int buffer = 0;
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;
	bool isInvuln = false;
	bool isPunch = false;
	bool isBulletCurved = false;
	float bulletSpeed = 2.0;
	float bulletSpeedModifier = 1.0;
	Vector2f startingPosition;


	Player();

	void fire();
	void invincible();
	void curved();
	void testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers, ParticleGroup& particles);
	bool testManyForCollisionWithBaddieBullet(vector<BaddieBullet>& objs);
	void update();
	void draw(RenderWindow& window);
	void animateIntro(int framesElapsed);
	void animateOutro(int framesElapsed);
};

#endif
