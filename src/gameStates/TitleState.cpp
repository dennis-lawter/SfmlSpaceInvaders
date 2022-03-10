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
	controls.setString("Controls\nLeft | A\nRight | D\nUp | W | Space");
	controls.setFont(resources::font);
	controls.setCharacterSize(80);
	controls.setScale(.03, .04);
	controls.setLineSpacing(1.2);
	controls.setPosition(5, 60);
	boon.setString("BOONS");
	boon.setFont(resources::font);
	boon.setCharacterSize(80);
	boon.setScale(.05, .05);
	boon.setLineSpacing(1.2);
	boon.setPosition(90, 43);
	bane.setString("BANES");
	bane.setFont(resources::font);
	bane.setCharacterSize(80);
	bane.setScale(.05, .05);
	bane.setLineSpacing(1.2);
	bane.setPosition(90, 78);
	oneUp.setTexture(resources::textures["1up"]);
	oneUp.setPosition(85, 50);
	agressive.setTexture(resources::textures["aggression"]);
	agressive.setPosition(85, 85);
	bomb.setTexture(resources::textures["bomb"]);
	bomb.setPosition(97, 85);
	coin.setTexture(resources::textures["coin"]);
	coin.setPosition(97, 50);
	curved.setTexture(resources::textures["curved"]);
	curved.setPosition(109, 50);
	missile.setTexture(resources::textures["missile"]);
	missile.setPosition(80, 60);
	passive.setTexture(resources::textures["passive"]);
	passive.setPosition(92, 60);
	punch.setTexture(resources::textures["punch"]);
	punch.setPosition(104, 60);
	speedDown.setTexture(resources::textures["speed_down"]);
	speedDown.setPosition(109, 85);
	speedUp.setTexture(resources::textures["speed_up"]);
	speedUp.setPosition(116, 60);
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
	} else if (bufferTick >= BUFFERTIMER) {
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
	window.draw(controls);
	window.draw(boon);
	window.draw(bane);
	window.draw(oneUp);
	window.draw(coin);
	window.draw(curved);
	window.draw(punch);
	window.draw(missile);
	window.draw(passive);
	window.draw(agressive);
	window.draw(bomb);
	window.draw(speedUp);
	window.draw(speedDown);
}


TitleState::~TitleState() {}
