#ifndef POWERUP_HPP_
#define POWERUP_HPP_
#include "GameObject.hpp"

class Powerup : public GameObject {
private:
	Sound powerupSound;

	float speed = 0.8;
public:

	Powerup(string powerupSelect, float ufoPosition);

	bool isOffScreen();
	void update();
};

#endif