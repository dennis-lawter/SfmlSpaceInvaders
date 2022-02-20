#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include "GameState.hpp"
#include "../resources.hh"
using namespace sf;
using namespace std;

class TitleState : public GameState {
private:
	Font& font = resources::font;
	string gameTitle1 = "TOTALLY INVADING";
	string gameTitle2 = "SPACE!";
	string pressAnyKey = "Press Any Key To Start";
	const int BLINKTIMER = 40;
	int blinkBuffer = 0;
	bool isBlink = false;

public:
	TitleState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~TitleState();
};

#endif