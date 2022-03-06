#ifndef POWERUP_HPP_
#define POWERUP_HPP_
#include "GameObject.hpp"

class Powerup : public GameObject {
private:
	Sound powerupSound;
	defines::PowerUp powerupSelect;

	float speed = 0.8;
public:

	Powerup(defines::PowerUp powerupSelect, float ufoPosition);

	void oneUp();

	void grantPowerUp();

	bool isOffScreen();
	void update();
};

#endif