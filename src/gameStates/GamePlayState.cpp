#include "GamePlayState.hpp"

GamePlayState::GamePlayState() {}

void GamePlayState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::Key::A:
		case Keyboard::Key::Left: //Move Left
			defender.playerIsMovingLeft = true;
			break;
		case Keyboard::Key::D:
		case Keyboard::Key::Right: //Move Right
			defender.playerIsMovingRight = true;
			break;
		case Keyboard::W: //Player fires
		case Keyboard::Up:
		case Keyboard::Space:
			defender.fire();
			break;
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

void GamePlayState::update(RenderWindow& window) {
	// update state components
	defender.update();
	killemAll.update();

	// do collision tests

	// defender's bullet collision tests
	defender.testBulletCollisions(killemAll, saveMe);

	// defender touches baddie bullet
	if (defender.testManyForCollision((vector<GameObject>&)killemAll.bulletVector)) {
		hud.currentLives--;
	}

	// barrier touches baddie bullet
	saveMe.testManyForCollision((vector<GameObject>&)killemAll.bulletVector, true, true);
	// barrier touches baddie
	killemAll.testManyForCollision((vector<GameObject>&)saveMe.barrierVector, false, true);

	// test if state has been completed
	if (killemAll.currentBaddies <= 0) {
		didWin = true;
		isEnding = true;
	}
	if (killemAll.isBaddiesWin() || hud.currentLives < 0) {
		didWin = false;
		isEnding = true;
	}
}

void GamePlayState::draw(RenderWindow& window) {
	hud.draw(window);
	defender.draw(window);
	killemAll.draw(window);
	saveMe.draw(window);
}

GamePlayState::~GamePlayState() {}