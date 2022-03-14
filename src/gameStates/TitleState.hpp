#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_
#include <iomanip>
#include <iostream>
#include "GameState.hpp"
#include "../resources.hh"
#include "../score.hh"

class TitleState : public GameState {
private:
	// Text drawTitle1;
	GameText drawTitle1;
	Text drawTitle2;
	Text drawToStart;
	stringstream highScores;
	Text highScoreText;
	Text controls;
	Text boon;
	Text bane;
	Sprite oneUp;
	Sprite coin;
	Sprite agressive;
	Sprite bomb;
	Sprite curved;
	Sprite missile;
	Sprite passive;
	Sprite punch;
	Sprite speedUp;
	Sprite speedDown;


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
