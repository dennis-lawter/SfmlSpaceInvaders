#include "GameText.hpp"

GameText::GameText(
	Vector2f position,
	GameText::Size size,
	GameText::HAlign hAlign,
	GameText::VAlign vAlign) {
	this->position = position;
	this->size = size;
	this->hAlign = hAlign;
	this->vAlign = vAlign;
	text.setFont(resources::font);
	text.setCharacterSize(80);
}

void GameText::setInternalOrigin() {
	FloatRect textBounds = text.getGlobalBounds();
	Vector2f origin;
	switch (hAlign) {
		case LEFT:
			origin.x = 0;
			break;
		case CENTER:
			origin.x = textBounds.width/2.f;
			break;
		case RIGHT:
			origin.x = textBounds.width;
			break;
	}
	switch (vAlign) {
		case TOP:
			origin.y = 0;
			break;
		case MIDDLE:
			origin.y = textBounds.height/2.f;
			break;
		case BOTTOM:
			origin.y = textBounds.height;
			break;
	}
	text.setOrigin(origin);
}

void GameText::reRender() {
	text.setString(characters.str());
	setInternalOrigin();
}

void GameText::setText(string s) {
	this->characters.str(s);
	reRender();
}

void GameText::appendText(string s) {
	this->characters << s;
	reRender();
}

void GameText::resetText() {
	this->characters.str("");
	reRender();
}

void GameText::setPosition(Vector2f position) {
	this->position = position;
	reRender();
}

void GameText::setSize(Size size) {
	this->size = size;
	reRender();
}

void GameText::setHAlign(HAlign align) {
	this->hAlign = align;
	reRender();
}

void GameText::setVAlign(VAlign align) {
	this->vAlign = align;
	reRender();
}

Vector2f GameText::getPosition() {
	return this->position;
}

GameText::Size GameText::getSize() {
	return this->size;
}

void GameText::draw(RenderWindow& window) {
	window.draw(text);
}
