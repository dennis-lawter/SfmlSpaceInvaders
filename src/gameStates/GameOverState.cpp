#include "GameOverState.hpp"

GameOverState::GameOverState(bool didWin) {
	this->didWin = didWin;
	hud = new Hud();
	score::addScore();
	for (int score : score::scoreList) {
		highScores << setfill('0') << setw(8) << score << endl;
	}
}

void GameOverState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyPressed:
		holdBuffer = false;
		break;
	case Event::KeyReleased:
		if (!holdBuffer && bufferTick == BUFFERTIMER) {
			score::score = 0;
			isEnding = true;
		}
		break;
	default:
		break;

	}
}

void GameOverState::draw(RenderWindow& window) {

	Text highScoreText(highScores.str(), font, 80);
	highScoreText.setScale(.05,.05);
	highScoreText.setPosition(44, 50);
	window.draw(highScoreText);
	
	Text gameOverText(gameOver, font, 80);
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
	} else {
		pressAnyKey = "Press Any Key To Reset";
	}
	hud->draw(window);
	Text pressReset = Text(pressAnyKey, font, 80);
	pressReset.setScale(.03, .03);
	pressReset.setPosition(36, 95);
	window.draw(pressReset);

}

void GameOverState::update(RenderWindow& window) {
	if (blinkBuffer < BLINKTIMER) {
		blinkBuffer++;
	} else {
		isBlink = !isBlink;
		blinkBuffer = 0;
	}
	if (bufferTick < BUFFERTIMER) {
		bufferTick++;
	}
}

GameOverState::~GameOverState() {

}