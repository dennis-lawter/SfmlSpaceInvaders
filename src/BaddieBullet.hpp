#ifndef BADDIEBULLET_HPP_
#define BADDIEBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
using namespace sf;

class BaddieBullet : public GameObject {
public:
	BaddieBullet(Texture& texture, float baddieCurrentX, float baddieCurrentY) : GameObject(texture, baddieCurrentX, baddieCurrentY) {}

	void update();
};

#endif