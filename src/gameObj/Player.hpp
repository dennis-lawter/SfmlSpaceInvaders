#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace std;
using namespace sf;

class Player : public GameObject {
public:
	float speed = 0.7;
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;

	Player();

	bool testManyForCollision(vector<GameObject>& objs);
	void update();
};

#endif