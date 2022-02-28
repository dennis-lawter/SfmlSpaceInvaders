#include "BaddieBoom.hpp"

BaddieBoom::BaddieBoom(float x, float y) 
	: GameObject(resources::textures["explosionmono"], x, y) {
		baddieDeath.setBuffer(resources::soundFile["baddieboom"]);
		baddieDeath.play();
		this->sprite.setColor(Color::Red);
	}

void BaddieBoom::update () {
	if ((buffer / BLINK_SPEED) % 2 == 0) {
		this->sprite.setColor(Color::Red);
	} else if ((buffer / BLINK_SPEED) % 2 == 1) {
		this->sprite.setColor(Color::Blue);
	}
	buffer++;
}

void BaddieBoom::draw (RenderWindow& window) {
	if (buffer < DEATH_TIMER) {
		GameObject::draw(window);
	}
}