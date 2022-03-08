#include "TitleState.hpp"

TitleState::TitleState() {
	score::score = 0;
	score::currentLives = 2;
	score::roundNumber = 1;
	score::speedModifier = 0;

	drawTitle1.setString("TOTALLY INVADING");
	drawTitle1.setFont(resources::font);
	drawTitle1.setCharacterSize(80);
	drawTitle1.setScale(.08, .08);
	drawTitle1.setPosition(10, 25);
	drawTitle2.setString("SPACE!");
	drawTitle2.setFont(resources::font);
	drawTitle2.setCharacterSize(80);
	drawTitle2.setScale(.08, .08);
	drawTitle2.setPosition(44, 35);
	drawToStart.setString("");
	drawToStart.setFont(resources::font);
	drawToStart.setCharacterSize(80);
	drawToStart.setScale(.03, .03);
	drawToStart.setPosition(35, 100);
	highScores.str("");
	for (size_t score = 0; score < score::scoreList.size(); score++) {
		highScores << setfill('0') << setw(8) << score::scoreList[score] << endl;
	}
	highScoreText.setString(highScores.str());
	highScoreText.setFont(resources::font);
	highScoreText.setCharacterSize(80);
	highScoreText.setScale(.05, .05);
	highScoreText.setPosition(44, 50);
}

void TitleState::processInput(Event& event) {
	if (bufferTick == BUFFERTIMER) {
		switch (event.type) {
		case Event::KeyReleased:
			isEnding = true;
			break;
		default:
			break;
		}
	}
}


void TitleState::update(RenderWindow& window) {
	if (blinkBuffer < BLINKTIMER) {
		blinkBuffer++;
	} else if (bufferTick >= BUFFERTIMER){
		isBlink = !isBlink;
		blinkBuffer = 0;

		if (isBlink) {
			drawToStart.setString("Press Any Key To Start");
		} else {
			drawToStart.setString("");
		}
	}
	if (bufferTick < BUFFERTIMER) {
		bufferTick++;
	}
}


void TitleState::draw(RenderWindow& window) {
	window.draw(drawTitle1);
	window.draw(drawTitle2);
	window.draw(drawToStart);
	window.draw(highScoreText);
}


TitleState::~TitleState() {}