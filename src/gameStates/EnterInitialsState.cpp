#include "EnterInitialsState.hpp"

EnterInitialsState::EnterInitialsState() {
	newHighScoreText.setPosition({ screenCenter.x, 15.f });
	newHighScoreText.setHAlign(GameText::CENTER);
	newHighScoreText.setSize(GameText::HUGE);
	newHighScoreText.setText("NEW HIGH SCORE");

	instructionsText.setPosition({ screenCenter.x, 30.f });
	instructionsText.setHAlign(GameText::CENTER);
	instructionsText.setText("ENTER INITIALS");

	playerEnteredText.setPosition(screenCenter);
	playerEnteredText.setHAlign(GameText::CENTER);
	playerEnteredText.setVAlign(GameText::MIDDLE);
	playerEnteredText.setSize(GameText::TITLE);
	playerEnteredText.setText(playerInitials);
}

void EnterInitialsState::updateEnteredText() {
	if (currentCharIndex > 3) return;
	if (isBlink) {
		playerInitials[currentCharIndex] = ' ';
		playerEnteredText.setText(playerInitials);
	} else {
		playerInitials[currentCharIndex] = displayedChar;
		playerEnteredText.setText(playerInitials);
	}
	playerInitials[currentCharIndex] = displayedChar;
}

void EnterInitialsState::processInput(Event& event) {
	switch (event.type) {
	case Event::JoystickButtonPressed:
		switch (event.joystickButton.button) {
		case 0:
			// accept
			if (currentCharIndex >= 3) {
				score::initials = playerInitials.substr(1, 3);
				isEnding = true;
				break;
			}
			currentCharIndex++;
			updateEnteredText();
			break;
		case 1:
			// go back
			if (currentCharIndex <= 1) {
				break;
			} else if (currentCharIndex <= 3) {
				playerInitials[currentCharIndex] = '_';
			}
			currentCharIndex--;
			updateEnteredText();
			break;
		case 2:
		case 3:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			break;
		default:
			break;
		}
		break;
	case Event::JoystickMoved:
		if (Joystick::isConnected(0)) {
			if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -50 && isJoyStickCentered) {
				// go back
				if (currentCharIndex <= 1) {
					break;
				} else if (currentCharIndex <= 3) {
					playerInitials[currentCharIndex] = '_';
				}
				currentCharIndex--;
				isJoyStickCentered = false;
				updateEnteredText();
				break;
			} else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50 && isJoyStickCentered) {
				// accept
				if (currentCharIndex >= 3) {
					score::initials = playerInitials.substr(1, 3);
					isEnding = true;
					break;
				}
				currentCharIndex++;
				isJoyStickCentered = false;
				updateEnteredText();
				break;
			} else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50 && isJoyStickCentered) {
				// down
				if (displayedChar == '_') {
					displayedChar = 'Z';
				} else if (displayedChar == 'A') {
					displayedChar = 'Z';
				} else {
					displayedChar--;
				}
				updateEnteredText();
				isJoyStickCentered = false;
				break;
			} else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50 && isJoyStickCentered) {
				// up
				if (displayedChar == '_') {
					displayedChar = 'A';
				} else if (displayedChar == 'Z') {
					displayedChar = 'A';
				} else {
					displayedChar++;
				}
				updateEnteredText();
				isJoyStickCentered = false;
				break;
			} else {
				isJoyStickCentered = true;
				break;
			}
		}
		break;
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::Left:
		case Keyboard::Backspace:
		case Keyboard::A:
			// go back
			if (currentCharIndex <= 1) {
				break;
			} else if (currentCharIndex <= 3) {
				playerInitials[currentCharIndex] = '_';
			}
			currentCharIndex--;
			updateEnteredText();
			break;
		case Keyboard::Right:
		case Keyboard::Space:
		case Keyboard::Enter:
		case Keyboard::D:
			// accept
			if (currentCharIndex >= 3) {
				score::initials = playerInitials.substr(1, 3);
				isEnding = true;
				break;
			}
			currentCharIndex++;
			updateEnteredText();
			break;
		case Keyboard::W:
		case Keyboard::Up:
			// up
			if (displayedChar == '_') {
				displayedChar = 'A';
			} else if (displayedChar == 'Z') {
				displayedChar = 'A';
			} else {
				displayedChar++;
			}
			updateEnteredText();
			break;
		case Keyboard::S:
		case Keyboard::Down:
			// down
			if (displayedChar == '_') {
				displayedChar = 'Z';
			} else if (displayedChar == 'A') {
				displayedChar = 'Z';
			} else {
				displayedChar--;
			}
			updateEnteredText();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void EnterInitialsState::update(RenderWindow& window) {
	isBlinkTimer++;
	if (
		(!isBlink && isBlinkTimer >= BLINK_TIMEOUT) ||
		(isBlink && isBlinkTimer >= BLINK_TIMEOUT / 2)
		) {
		isBlink = !isBlink;
		updateEnteredText();
		isBlinkTimer = 0;
	}
}

void EnterInitialsState::draw(RenderWindow& window) {
	newHighScoreText.draw(window);
	instructionsText.draw(window);
	playerEnteredText.draw(window);
}

EnterInitialsState::~EnterInitialsState() {}
