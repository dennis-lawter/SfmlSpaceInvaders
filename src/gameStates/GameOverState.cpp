#include "GameOverState.hpp"

GameOverState::GameOverState(bool didWin) {
	this->didWin = didWin;
}

void GameOverState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyReleased:
		isEnding = true;
		break;
	default:
		break;
	}
}

void GameOverState::draw(RenderWindow& window) {
	Text gameOverText = Text(gameOver, font, 80);
	gameOverText.setScale(.1, .1);
	gameOverText.setPosition(28, 25);
	window.draw(gameOverText);
	if (didWin) {
		Text youWinText = Text(youWin, font, 80);
		youWinText.setScale(.1, .1);
		youWinText.setPosition(31, 35);
		window.draw(youWinText);
	} else {
		Text youLoseText = Text(youLose, font, 80);
		youLoseText.setScale(.1, .1);
		youLoseText.setPosition(31, 35);
		window.draw(youLoseText);
	}

	if (isBlink) {
		pressAnyKey = "";
	}
	else {
		pressAnyKey = "Press Any Key To Reset";
	}

	Text pressReset = Text(pressAnyKey, font, 80);
	pressReset.setScale(.03, .03);
	pressReset.setPosition(38, 90);
	window.draw(pressReset);

}

void GameOverState::update(RenderWindow& window) {
	if (blinkBuffer < BLINKTIMER) {
		blinkBuffer++;
	}
	else {
		isBlink = !isBlink;
		blinkBuffer = 0;
	}
}

GameOverState::~GameOverState() {

}