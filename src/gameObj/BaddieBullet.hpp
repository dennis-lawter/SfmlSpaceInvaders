#ifndef BADDIEBULLET_HPP_
#define BADDIEBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class BaddieBullet : public GameObject {
public:
	float speed = 1;

	BaddieBullet(float x, float y);

	bool isOffScreen();
	void update();
};

#endif