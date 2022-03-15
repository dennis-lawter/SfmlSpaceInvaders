#include "Hud.hpp"

Hud::Hud() {
	lastCheckedScore = score::score;
	lives.setTexture(resources::textures["1up"]);

	text.setHAlign(GameText::LEFT);
	text.setVAlign(GameText::TOP);
	text.setSize(GameText::HUGE);
	text.setPosition(Vector2f(2.f, 1.f));

	updateScore();
}

void Hud::draw(RenderWindow& window) {
	text.draw(window);

	for (int i = 0; i < score::currentLives; i++) {
		lives.setPosition(120 - (9 * i), 0);
		window.draw(lives);
	}
}

void Hud::updateScore() {
	scoreOut.str("");
	scoreOut << setfill('0') << setw(8) << lastCheckedScore;
	string scoreOutString = scoreOut.str();
	text.setText(scoreOutString);
}

void Hud::update() {
	if (score::score > this->lastCheckedScore) {
		lastCheckedScore+=4;
		if (lastCheckedScore > score::score) {
			lastCheckedScore = score::score;
		}
		updateScore();
	}
}
