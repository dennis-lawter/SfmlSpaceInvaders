#include "GamePlayState.hpp"

GamePlayState::GamePlayState() {
	defender = new Player();
	killemAll = new BaddieGroup();
	hud = new Hud();
}

void GamePlayState::processInput(Event& event) {
	switch (event.type) {
	case Event::KeyPressed:
		switch (event.key.code) {
		// case Keyboard::Key::Escape: //Manual game close
		// 	break;
		case Keyboard::Key::A:
		case Keyboard::Key::Left: //Move Left
			defender->playerIsMovingLeft = true;
			break;
		case Keyboard::Key::D:
		case Keyboard::Key::Right: //Move Right
			defender->playerIsMovingRight = true;
			break;
		case Keyboard::W: //Player fires
		case Keyboard::Up:
		case Keyboard::Space:
			if (!pew)
				pew = new PlayerBullet(defender->getX() + 3);
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
			defender->playerIsMovingLeft = false;
			break;
		case Keyboard::Key::D:
		case Keyboard::Key::Right:
			defender->playerIsMovingRight = false;
			break;
		default:
			break;
		}
	default:
		break;
	}

}

void GamePlayState::update(RenderWindow& window) {
	defender->update();
	if (defender->testHit(killemAll->bulletArray)) {
		hud->currentLives--;
	}
	if (pew) {
		pew->update();
		if (killemAll->testHit(*pew)) { //deletes bullet on enemy contact
			delete pew;
			pew = nullptr;
			hud->score += 100;
		} else if (pew->getY() <= 6) { //deletes bullet when it leaves screen
			delete pew;
			pew = nullptr;
		}
	}
	killemAll->update();
	if (killemAll->currentBaddies <= 0) { //Win Condition
		window.close();
	}
	if (killemAll->baddiesWin() || hud->currentLives < 0) { //Lose Condition
		window.close();
	}
}

void GamePlayState::draw(RenderWindow& window) {
	if (pew) {
		pew->draw(window);
	}
	hud->draw(window);
	defender->draw(window);
	killemAll->draw(window);
}

GamePlayState::~GamePlayState() {
	delete defender;
	delete killemAll;
	if (pew)
		delete pew;
}