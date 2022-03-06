#include "GamePlayState.hpp"

GamePlayState::GamePlayState() {
	startMusic.setBuffer(resources::soundFile["randommusic"]);
	startMusic.play();
	score::scoreBonus = 10;

	pauseTint.setFillColor(Color(0x000000D0));
	pauseTint.setSize(Vector2f(defines::WIDTH, defines::HEIGHT));
	pauseTint.setPosition(0, 0);
	
	pause.setString("PAUSE");
	pause.setFont(resources::font);
	pause.setCharacterSize(80);
	pause.setScale(.12, .12);
	pause.setPosition(40, 55);
}

void GamePlayState::processInput(Event& event) {
	if (roundStart) {
		return;
	}
	if (isPause && event.key.code != Keyboard::Escape) {
		return;
	}
	switch (event.type) {
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::A:
		case Keyboard::Left: //Move Left
			defender.playerIsMovingLeft = true;
			break;
		case Keyboard::D:
		case Keyboard::Right: //Move Right
			defender.playerIsMovingRight = true;
			break;
		case Keyboard::W: //Player fires
		case Keyboard::Up:
		case Keyboard::Space:
			defender.fire();
			break;
		case Keyboard::Escape:
			isPause = !isPause;
			defender.playerIsMovingLeft = false;
			defender.playerIsMovingRight = false;
		default:
			break;
		}
		break;

		/* This case allows for smooth player movement left and right
		*/
	case Event::KeyReleased:
		switch (event.key.code) {
		case Keyboard::Key::A:
		case Keyboard::Key::Left:
			defender.playerIsMovingLeft = false;
			break;
		case Keyboard::Key::D:
		case Keyboard::Key::Right:
			defender.playerIsMovingRight = false;
			break;
		default:
			break;
		}
	default:
		break;
	}

}

void GamePlayState::startRound() {
	if (roundStartTimer < ROUND_START_MAX) {
		if (roundStartTimer < BLINK_MAX && (roundStartTimer / BLINK_SPEED) % 2 == 0) {
			roundTitle.str("");
			roundTitle << "ROUND   " << score::roundNumber;
		} else if (roundStartTimer < BLINK_MAX) {
			roundTitle.str("");
		}
		roundStartTimer++;
		return;
	} else {
		roundTitle.str("");
		roundStart = false;
	}
	return;
}

void GamePlayState::update(RenderWindow& window) {
	if (isPause) {
		return;
	}
	if (roundStart) {
		startRound();
		return;
	}

	// update state components
	defender.update();
	killemAll.update();
	if (isUfoMoving && ufo) {
		ufo->update();
	}
	if (powerup) {
		powerup->update();
	}

	// do collision tests

	// defender's bullet collision tests
	defender.testBulletCollisions(killemAll, saveMe);

	// defender touches baddie bullet
	if (defender.testManyForCollision((vector<GameObject>&)killemAll.bulletVector) && !defender.isInvuln) {
		score::currentLives--;
		defender.isInvuln = true;
	}

	// barrier touches baddie bullet
	saveMe.testManyForCollision((vector<GameObject>&)killemAll.bulletVector, true, true);
	// barrier touches baddie
	killemAll.testManyForCollision((vector<GameObject>&)saveMe.barrierVector, false, true);

	// powerup touches defender 
	if (powerup && defender.testCollision(*powerup)) {
		didPowerupHit = true;
	}

	// powerup off screen
	if (powerup) {
		if (powerup->isOffScreen() || didPowerupHit) {
			delete powerup;
			powerup = nullptr;
			didPowerupHit = false;
		}
	}

	//start ufo timer when baddies advance
	if (killemAll.baddiesTimesAdvanced > 0) {
		if (setUfoRandom > ufoBuffer && setUfoTimer) {
			ufoBuffer++;
		} else if (ufoBuffer >= setUfoRandom && setUfoTimer) {
			ufo = new Ufo();
			setUfoTimer = false;
			isUfoMoving = true;
			setUfoRandom = 0;
			ufoBuffer = 0;
		} else if (!setUfoTimer && !isUfoMoving) {
			setUfoTimer = true;
			setUfoRandom = rand() % (UFO_TIMER_MAX - UFO_TIMER_MIN) + UFO_TIMER_MIN;
		}
	}

	//ufo fires powerup
	if (ufo && ufo->hasFired && !powerup && !didUfoFire) {
		powerup = new Powerup("1up", ufo->getX());
		didUfoFire = true;
	}

	if (!powerup && !ufo) {
		didUfoFire = false;
	}


	//ufo despawns off screen
	if (ufo && ufo->isOffScreen()) {
		delete ufo;
		ufo = nullptr;
		isUfoMoving = false;
	}

	// test if state has been completed
	if (killemAll.currentBaddies <= 0) {
		didWin = true;
		isEnding = true;
	}
	if (killemAll.isBaddiesWin() || score::currentLives < 0) {
		didWin = false;
		isEnding = true;
	}
}

void GamePlayState::draw(RenderWindow& window) {
	hud.draw(window);
	defender.draw(window);
	killemAll.draw(window);
	saveMe.draw(window);
	Text drawTitle1 = Text(roundTitle.str(), resources::font, 80);
	drawTitle1.setScale(.08, .08);
	drawTitle1.setPosition(30, 50);
	window.draw(drawTitle1);
	if (ufo) {
		ufo->draw(window);
	}
	if (powerup) {
		powerup->draw(window);
	}
	if (isPause) {
		window.draw(pauseTint);
		window.draw(pause);
	}
}

GamePlayState::~GamePlayState() {}