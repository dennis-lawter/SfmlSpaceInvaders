#include "GameText.hpp"

GameText::GameText(Vector2f position, GameText::Size size = MEDIUM, GameText::Origin origin = TOP_LEFT) {
	this->position = position;
	this->size = size;
	this->origin = origin;
	text.setFont(resources::font);
	text.setCharacterSize(80);
}

void GameText::reRender() {
	text.setString(characters.str());
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

void GameText::setOrigin(Origin origin) {
	this->origin = origin;
	reRender();
}

Vector2f GameText::getPosition() {
	return this->position;
}

GameText::Size GameText::getSize() {
	return this->size;
}

GameText::Origin GameText::getOrigin() {
	return this->origin;
}

void GameText::draw(RenderWindow& window) {
	window.draw(text);
}
