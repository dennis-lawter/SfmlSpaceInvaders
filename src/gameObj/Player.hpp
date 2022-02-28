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
	PlayerBullet* bullet = nullptr;
	float speed = 0.7;
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;


	Player();

	void fire();
	void testBulletCollisions(BaddieGroup& baddies, BarrierGroup& barriers);
	bool testManyForCollision(vector<GameObject>& objs);
	void update();
	void draw(RenderWindow& window);
};

#endif