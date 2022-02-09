#ifndef BULLET_HPP_
#define BULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Bullet : public GameObject {
public:
	bool playerIsFire = false;
	Bullet(Texture& texture, float fired) : GameObject(texture, fired, 112) {}
	void update();
};

#endif