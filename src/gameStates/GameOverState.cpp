#include "GameOverState.hpp"

GameOverState::GameOverState(bool didWin) {
	this->didWin = didWin;
	score::addScore();
}

void GameOverState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyPressed:
		holdBuffer = false;
		break;
	case Event::KeyReleased:
		if (!holdBuffer && bufferTick == BUFFERTIMER) {
			isEnding = true;
		}
		break;
	default:
		break;
	}
}

void GameOverState::draw(RenderWindow& window) {
	hud.draw(window);

	Text highScoreText(highScores.str(), font, 80);
	highScoreText.setScale(.05, .05);
	highScoreText.setPosition(44, 50);
	window.draw(highScoreText);

	Text gameOverText(gameOver, font, 80);
	gameOverText.setScale(.1, .1);
	gameOverText.setPosition(28, 25);
	window.draw(gameOverText);

	if (!isBlink && bufferTick >= BUFFERTIMER) {
		pressAnyKey = "Press Any Key To Reset";
		Text pressReset = Text(pressAnyKey, font, 80);
		pressReset.setScale(.03, .03);
		pressReset.setPosition(36, 95);
		window.draw(pressReset);
	}

	int matchScore = score::matchScore();
	highScores.str("");
	for (size_t score = 0; score < score::scoreList.size(); score++) {
		if (matchScore == (int)score) {
			if (isBlink) {
				highScores << "" << endl;
			} else {
				highScores << setfill('0') << setw(8) << score::scoreList[score] << endl;
			}
		} else {
			highScores << setfill('0') << setw(8) << score::scoreList[score] << endl;
		}
	}
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