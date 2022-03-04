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
	drawToStart.setString("Press Any Key To Start");
	drawToStart.setFont(resources::font);
	drawToStart.setCharacterSize(80);
	drawToStart.setScale(.03, .03);
	drawToStart.setPosition(35, 100);
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
	} else {
		isBlink = !isBlink;
		blinkBuffer = 0;

		if (isBlink) {
			drawToStart.setString("");
		} else {
			drawToStart.setString("Press Any Key To Start");
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
}


TitleState::~TitleState() {}