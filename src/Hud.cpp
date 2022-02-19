#include "Hud.hpp"

Hud::Hud() {
	lives.setTexture(resources::textures["1up"]);
}

void Hud::draw(RenderWindow& window) {
	scoreOut.str("");
	scoreOut << setfill('0') << setw(8) << score;
	Text text = Text(scoreOut.str(), font, 6);
	text.setPosition(2, 1);
	window.draw(text);

	for (int i = 0; i < currentLives; i++) {
		lives.setPosition(120 - (9 * i), 0);
		window.draw(lives);
	}
}

void Hud::update() {

};

