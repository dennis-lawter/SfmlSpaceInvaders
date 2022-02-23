#ifndef PLAYERBULLET_HPP_
#define PLAYERBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class PlayerBullet : public GameObject {
public:
	float speed = 2.0;
	
	PlayerBullet(float x);

	void update();
};

#endif