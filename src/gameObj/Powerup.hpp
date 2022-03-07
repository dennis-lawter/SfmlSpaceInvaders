#ifndef POWERUP_HPP_
#define POWERUP_HPP_
#include "GameObject.hpp"
#include "Player.hpp"

class Powerup : public GameObject {
private:
	Sound powerupSound;
	defines::PowerUp powerupSelect;
	Player* defender = nullptr;

	float speed = 0.8;
public:

	Powerup(defines::PowerUp powerupSelect, float ufoPosition, Player& defender);

	void oneUp();
	void coin();
	void coinOffScreen();
	void speedUp();
	void speedDown();
	void punch();

	void grantPowerUp();

	bool isOffScreen();
	void update();
};

#endif