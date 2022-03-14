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
	enum HAlign {
		LEFT,
		CENTER,
		RIGHT
	};
	enum VAlign {
		TOP,
		MIDDLE,
		BOTTOM
	};
	enum Size {
		TITLE,
		HUGE,
		LARGE,
		MEDIUM,
		SMALL,
	};
private:
	map<Size, float> scaleFactor = {
		{TITLE, .12f},
		{HUGE, .10f},
		{LARGE, .08f},
		{MEDIUM, .05f},
		{SMALL, .03f}
	};
	vector<Text> texts;
	vector<string> stringLines;
	stringstream stringStream;
	
	Vector2f position;
	Size size;
	HAlign hAlign;
	VAlign vAlign;
	bool dirty = false;

	float widestLine = 0.f;
	float totalHeight = 0.f;

	void setTexts();
	void setInternalOrigin();
	void setInternalScale();
	void setLinePositions();
	void reRender();
public:
	GameText();

	void setText(string s);
	void appendText(string s);
	void resetText();

	Vector2f getPosition();
	Size getSize();

	void setPosition(Vector2f position);
	void setSize(Size size);
	void setHAlign(HAlign align);
	void setVAlign(VAlign align);

	void draw(RenderWindow& window);
};

#endif
