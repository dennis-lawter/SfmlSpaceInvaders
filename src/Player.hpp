#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "BaddieBullet.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class BaddieBullet;

class Player : public GameObject {
public:
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;
	bool playerIsFire = false;
	int playerLives = 3;
	//todo add damage indicator, death "animation", score
	Player(Texture& texture) : GameObject(texture, 60, 120) {}
	bool testHit(vector<BaddieBullet>& pew);
	void update();
};

#endif