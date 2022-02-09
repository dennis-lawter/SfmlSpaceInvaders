#ifndef BADDIE_HPP_
#define BADDIE_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Baddie : public GameObject {
public:
	Baddie(Texture& texture, int x = 0, int y = 0) : GameObject(texture, 0, 0) {}
	void update();
};

#endif