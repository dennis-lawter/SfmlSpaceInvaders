#ifndef BADDIE_HPP_
#define BADDIE_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Baddie : public GameObject {
public:
	float speed = 0.05;
	bool didHitBottom = false;
	Baddie(Texture& texture, int x, int y) : GameObject(texture, x, y) {}
	void moveRight();
	void moveLeft();
	void moveDown();
};

#endif