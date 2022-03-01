#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include "GameState.hpp"
#include "../resources.hh"
#include "../score.hh"
using namespace sf;
using namespace std;

class TitleState : public GameState {
private:
	Text drawTitle1;
	Text drawTitle2;
	Text drawToStart;
	const int BLINKTIMER = 40;
	int blinkBuffer = 0;
	bool isBlink = false;
	const int BUFFERTIMER = 90;
	int bufferTick = 0;
public:
	TitleState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~TitleState();
};

#endif