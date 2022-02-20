#include "TitleState.hpp"

TitleState::TitleState() {

}


void TitleState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyReleased:
		isEnding = true;
		break;
	default:
		break;
	}
}


void TitleState::update(RenderWindow& window) {
	if (blinkBuffer < BLINKTIMER) {
		blinkBuffer++;
	}
	else {
		isBlink = !isBlink;
		blinkBuffer = 0;
	}
}


void TitleState::draw(RenderWindow& window) {
	Text drawTitle1 = Text(gameTitle1, font, 80);
	drawTitle1.setScale(.08, .08);
	drawTitle1.setPosition(10, 20);
	window.draw(drawTitle1);
	Text drawTitle2 = Text(gameTitle2, font, 80);
	drawTitle2.setScale(.08, .08);
	drawTitle2.setPosition(42, 30);
	window.draw(drawTitle2);
	Text drawToStart = Text(pressAnyKey, font, 80);
	drawToStart.setScale(.03, .03);
	drawToStart.setPosition(35, 100);
	window.draw(drawToStart);
	
	if (isBlink) {
		pressAnyKey = "";
	}
	else {
		pressAnyKey = "Press Any Key To Start";
	}
}


TitleState::~TitleState() {

}