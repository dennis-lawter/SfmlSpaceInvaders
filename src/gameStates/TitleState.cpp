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

}


void TitleState::draw(RenderWindow& window) {

}


TitleState::~TitleState() {

}