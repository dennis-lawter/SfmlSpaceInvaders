#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "groups/BaddieGroup.hpp"
#include "groups/BarrierGroup.hpp"
#include "PlayerBullet.hpp"
#include "BaddieBullet.hpp"
#include "GameObject.hpp"
#include "../score.hh"
using namespace std;
using namespace sf;

class Player : public GameObject {
private:
	void deleteBullet();
	Sound pewSound;
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
	Vector2f startingPosition = {60, 300};


	Player();

	void fire();
	void invincible();
	void curved();
	void testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers);
	bool testManyForCollisionWithBaddieBullet(vector<BaddieBullet>& objs);
	void update();
	void draw(RenderWindow& window);
	void animateIntro(int framesElapsed);
	void animateOutro(int framesElapsed);
};

#endif