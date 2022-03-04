#ifndef BADDIE_HPP_
#define BADDIE_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class Baddie : public GameObject {
private:
	const float ADVANCE_DISTANCE = 12;
public:
	float speed = 0.03;

	Baddie(Texture& texture, int x, int y);

	void moveRight();
	void moveLeft();
	void moveDown();
};

#endif