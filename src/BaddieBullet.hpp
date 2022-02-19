#ifndef BADDIEBULLET_HPP_
#define BADDIEBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class BaddieBullet : public GameObject {
public:
	BaddieBullet(float baddieCurrentX, float baddieCurrentY)
		: GameObject(resources::textures["bullet"], baddieCurrentX, baddieCurrentY) {}

	bool offScreen();
	void update();
};

#endif