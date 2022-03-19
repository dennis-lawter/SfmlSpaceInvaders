#ifndef BADDIE_HPP_
#define BADDIE_HPP_
#include "GameObject.hpp"

class Baddie : public GameObject {
private:
	const float ADVANCE_DISTANCE = 12;
	int animationTimer = 30;
	int animationBuffer = 0;
	const int KAMI_RANDOM = 100000;
	int gettingAngry = 0;
	float gettingAngryShakes = 15.f;
	bool animationSwap = true;
	bool ohHeMad = false;
	bool isUpright = true;

	void kamikaze();
public:
	int animationFinishTime;
	int animationPlayerDead;
	float speed = 0.03;
	bool eesComing = false;
	Vector2f destination;
	Vector2f startingPosition;

	Baddie(Texture& texture, int x, int y);

	void moveRight();
	void moveLeft();
	void moveDown();

	void draw(RenderWindow& window);
	void update();
};

#endif
