#include "EnterInitialsState.hpp"

EnterInitialsState::EnterInitialsState() {
	newHighScoreText.setPosition({screenCenter.x, 15.f});
	newHighScoreText.setHAlign(GameText::CENTER);
	newHighScoreText.setSize(GameText::TITLE);
	newHighScoreText.setText("NEW HIGH SCORE");

	instructionsText.setPosition({screenCenter.x, 30.f});
	instructionsText.setHAlign(GameText::CENTER);
	instructionsText.setText("ENTER INITIALS THEN PRESS ENTER");
}

void EnterInitialsState::processInput(Event& event) {
	switch (event.type) {
	// case Event::TextEntered:
		
	// 	break;
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::Left:
		case Keyboard::Backspace:
			// go back
		case Keyboard::Right:
		case Keyboard::Space:
		case Keyboard::Enter:
			// accept
			break;
		case Keyboard::W:
		case Keyboard::Up:
			// up
			if (displayedChar == ' ') {
				displayedChar = 'A';
			} else if (displayedChar == 'Z') {
				displayedChar = 'A';
			} else {
				displayedChar++;
			}
		case Keyboard::D:
		case Keyboard::Down:
			// down
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void EnterInitialsState::update(RenderWindow& window) {
}

void EnterInitialsState::draw(RenderWindow& window) {
	newHighScoreText.draw(window);
	instructionsText.draw(window);
}

EnterInitialsState::~EnterInitialsState() {}
