#ifndef GAMETEXT_HPP_
#define GAMETEXT_HPP_
#include <iostream>
#include <iomanip>
#include <string>
#include <SFML/Graphics.hpp>
#include "resources.hh"
using namespace sf;
using namespace std;

class GameText {
public:
	enum Origin {
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		MIDDLE_LEFT,
		MIDDLE_CENTER,
		MIDDLE_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT
	};
	enum Size {
		TITLE,
		LARGE,
		MEDIUM,
		SMALL
	};
private:
	Text text;
	stringstream characters;
	
	Vector2f position;
	Size size;
	Origin origin;

	void reRender();
public:
	GameText(Vector2f position, GameText::Size size, GameText::Origin origin);

	void setText(string s);
	void appendText(string s);
	void resetText();

	Vector2f getPosition();
	GameText::Size getSize();
	GameText::Origin getOrigin();

	void setPosition(Vector2f position);
	void setSize(GameText::Size size);
	void setOrigin(GameText::Origin origin);

	void draw(RenderWindow& window);
};

#endif
