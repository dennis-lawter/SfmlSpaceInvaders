#ifndef BADDIE_HPP_
#define BADDIE_HPP_
#include "GameObject.hpp"

class Baddie : public GameObject {
private:
	const float ADVANCE_DISTANCE = 12;
	int animationTimer = 30;
	int animationBuffer = 0;
	bool animationSwap = true;
public:
	int animationFinishTime;
	float speed = 0.03;
	Vector2f startingPosition;

	Baddie(Texture& texture, int x, int y);

	void moveRight();
	void moveLeft();
	void moveDown();

	void draw(RenderWindow& window);
};

#endif
