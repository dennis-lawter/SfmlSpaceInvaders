#ifndef UFO_HPP_
#define UFO_HPP_
#include "GameObject.hpp"

class Ufo : public GameObject {
private:
public:
	float speed = 0.4;
	bool isMovingLeft;

	Ufo();

	void move();
	bool isOffScreen();
	void update();
};

#endif