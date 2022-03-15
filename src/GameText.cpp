#include "GameText.hpp"

GameText::GameText() {
	this->position = { 0.f, 0.f };
	this->size = GameText::MEDIUM;
	this->hAlign = GameText::LEFT;
	this->vAlign = GameText::TOP;
	this->stringStream.str("");
}

void GameText::setTexts() {
	string temp;
	string keepValue = stringStream.str();
	stringStream << "\n";

	texts.clear();
	while (std::getline(stringStream, temp, '\n')) {
		cout << "CREATING: " << temp << endl;
		texts.emplace_back(temp, resources::font, 80U);
	}
	stringStream.str("");
	stringStream << keepValue;
}

void GameText::setInternalOrigin() {
	widestLine = 0.f;
	totalHeight = 0.f;
	for (Text& text : texts) {
		FloatRect textBounds = text.getLocalBounds();
		float fullWidth = textBounds.left + textBounds.width;
		if (fullWidth > widestLine) {
			widestLine = fullWidth;
		}
		totalHeight += textBounds.top + textBounds.height;
	}
	Vector2f origin;
	switch (hAlign) {
	case LEFT:
		origin.x = 0.f;
		break;
	case CENTER:
		origin.x = widestLine / 2.f;
		break;
	case RIGHT:
		origin.x = widestLine;
		break;
	}
	switch (vAlign) {
	case TOP:
		origin.y = 0.f;
		break;
	case MIDDLE:
		origin.y = totalHeight / 2.f;
		break;
	case BOTTOM:
		origin.y = totalHeight;
		break;
	}
	for (Text& text : texts) {
		text.setOrigin(origin);
	}
}

void GameText::setInternalScale() {
	float scale = scaleFactor[size];
	for (Text& text : texts) {
		text.setScale(scale, scale);
	}
}

void GameText::setLinePositions() {
	float heightOffset = 0.f;
	float scale = scaleFactor[size];
	Vector2f tempPosition = this->position;
	for (Text& text : texts) {
		FloatRect localBounds = text.getLocalBounds();
		switch(hAlign){
		case LEFT:
			tempPosition.x = this->position.x;
			break;
		case CENTER:
			tempPosition.x = this->position.x - scale*(localBounds.width-widestLine)/2.f;
			break;
		case RIGHT:
			tempPosition.x = this->position.x - scale*(localBounds.width-widestLine);
			break;
		}
		tempPosition.y += heightOffset;
		text.setPosition(tempPosition);
		heightOffset = scale * (localBounds.top + localBounds.height) * 9.f/8.f;
	}
}

void GameText::reRender() {
	setTexts();
	setInternalOrigin();
	setInternalScale();
	setLinePositions();

	this->dirty = false;
}

void GameText::setText(string s) {
	this->stringStream.clear();
	this->stringStream << s;
	this->dirty = true;
}

void GameText::appendText(string s) {
	this->stringStream << s;
	this->dirty = true;
}

void GameText::resetText() {
	this->stringStream.str("");
	this->dirty = true;
}

void GameText::setPosition(Vector2f position) {
	this->position = position;
	this->dirty = true;
}

void GameText::setSize(Size size) {
	this->size = size;
	this->dirty = true;
}

void GameText::setHAlign(HAlign align) {
	this->hAlign = align;
	this->dirty = true;
}

void GameText::setVAlign(VAlign align) {
	this->vAlign = align;
	this->dirty = true;
}

Vector2f GameText::getPosition() {
	return this->position;
}

GameText::Size GameText::getSize() {
	return this->size;
}

void GameText::draw(RenderWindow& window) {
	if (this->dirty) {
		this->reRender();
	}
	if (texts.size() <= 0) return;
	for (Text& text : texts) {
		window.draw(text);
	}
}
