#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "groups/BaddieGroup.hpp"
#include "groups/BarrierGroup.hpp"
#include "PlayerBullet.hpp"
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
	PlayerBullet* bullet = nullptr;
	float speed = 0.7;
	int buffer = 0;
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;
	bool isInvuln = false;
	bool isPunch = false;
	float bulletSpeed = 2.0;
	float bulletSpeedModifier = 1.0;

	Player();

	void fire();
	void invincible();
	void testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers);
	bool testManyForCollision(vector<GameObject>& objs);
	void update();
	void draw(RenderWindow& window);
};

#endif