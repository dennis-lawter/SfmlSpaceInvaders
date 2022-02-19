#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "BaddieBullet.hpp"
using namespace std;
using namespace sf;

class Player : public GameObject {
public:
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;
	int playerLives = 3;

	Player()
		: GameObject(resources::textures["defender"], 60, 120) {}

	bool testHit(vector<BaddieBullet>& pew);
	void update();
};

#endif