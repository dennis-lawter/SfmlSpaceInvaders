#ifndef BADDIEBOOM_HPP_
#define BADDIEBOOM_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.hpp"
using namespace sf;

class BaddieBoom : public GameObject {
private: 
	Sound baddieDeath;
public:
	const static int DEATH_TIMER = 20;
	const static int BLINK_SPEED = 4;
	const static int ERASE_TIMER = 60;
	int buffer = 0;

	BaddieBoom(float x, float y);

	void update();
	void draw(RenderWindow& window);
};


#endif