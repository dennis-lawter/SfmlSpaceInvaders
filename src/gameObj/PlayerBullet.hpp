#ifndef PLAYERBULLET_HPP_
#define PLAYERBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class PlayerBullet : public GameObject {
public:
	
	PlayerBullet(float x, float speed);

	float speed;
	float shift = 0;

	bool isOffScreen();
	void update();
};

#endif