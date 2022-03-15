#include "TitleState.hpp"

TitleState::TitleState() {
	score::score = 0;
	score::currentLives = 2;
	score::roundNumber = 1;
	score::speedModifier = 0;

	score::loadScores();

	titleSound.setBuffer(resources::soundFile["boss"]);
	titleSound.play();

	float center = defines::WIDTH / 2.f;
	float rightCenter = 0.75f * defines::WIDTH;

	highScores.str("");
	for (size_t score = 0; score < score::scoreList.size(); score++) {
		highScores << setfill('0') << setw(8) << score::scoreList[score] << endl;
	}
	
	drawTitle1.setPosition({center, 5.f});
	drawTitle1.setHAlign(GameText::CENTER);
	drawTitle1.setSize(GameText::TITLE);
	drawTitle1.setText(defines::GAME_TITLE_SCREEN);

	pressStart.setPosition({center, 100.f});
	pressStart.setHAlign(GameText::CENTER);
	pressStart.setSize(GameText::MEDIUM);
	pressStart.setText("PRESS ANY KEY TO START");

	highScoreText.setText(highScores.str());
	highScoreText.setHAlign(GameText::CENTER);
	highScoreText.setPosition({center, 50.f});
	
	controls.setText("");
	controls.appendText("CONTROLS  \n \n");
	controls.appendText("LEFT:\n");
	controls.appendText("Left     A\n \n");
	controls.appendText("RIGHT:\n");
	controls.appendText("Right    D\n \n");
	controls.appendText("FIRE:\n");
	controls.appendText("Up Space W");
	controls.setPosition({2.f, 43.f});

	boon.setText("COLLECT");
	boon.setHAlign(GameText::CENTER);
	boon.setPosition({rightCenter+5.f, 43.f});

	bane.setText("AVOID");
	bane.setHAlign(GameText::CENTER);
	bane.setPosition({rightCenter+5.f, 78.f});
	
	oneUp.setTexture(resources::textures["1up"]);
	oneUp.setPosition(2.f+85.f, 50.f);
	agressive.setTexture(resources::textures["aggression"]);
	agressive.setPosition(2.f+85.f, 85.f);
	bomb.setTexture(resources::textures["bomb"]);
	bomb.setPosition(2.f+97.f, 85.f);
	coin.setTexture(resources::textures["coin"]);
	coin.setPosition(2.f+97.f, 50.f);
	curved.setTexture(resources::textures["curved"]);
	curved.setPosition(2.f+109.f, 50.f);
	missile.setTexture(resources::textures["missile"]);
	missile.setPosition(2.f+80.f, 60.f);
	passive.setTexture(resources::textures["passive"]);
	passive.setPosition(2.f+92.f, 60.f);
	punch.setTexture(resources::textures["punch"]);
	punch.setPosition(2.f+104.f, 60.f);
	speedDown.setTexture(resources::textures["speed_down"]);
	speedDown.setPosition(2.f+109.f, 85.f);
	speedUp.setTexture(resources::textures["speed_up"]);
	speedUp.setPosition(2.f+116.f, 60.f);
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
	}
	if (bufferTick < BUFFERTIMER) {
		bufferTick++;
	}
}


void TitleState::draw(RenderWindow& window) {
	drawTitle1.draw(window);
	if (isBlink) {
		pressStart.draw(window);
	}
	highScoreText.draw(window);
	controls.draw(window);
	boon.draw(window);
	bane.draw(window);
	
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
