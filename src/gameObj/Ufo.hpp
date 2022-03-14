#ifndef UFO_HPP_
#define UFO_HPP_
#include "GameObject.hpp"

class Ufo : public GameObject {
private:
public:
	float speed = 0.4;
	bool isMovingLeft;
	int ufoFireRandom;
	bool hasFired = false;

	Sound ufoSpawnSound;

	Ufo();

	void move();
	bool isOffScreen();
	void ufoFire();
	void update();
};

#endif
