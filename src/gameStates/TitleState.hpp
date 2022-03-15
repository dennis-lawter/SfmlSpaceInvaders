#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_
#include <iomanip>
#include <iostream>
#include "GameState.hpp"
#include "../resources.hh"
#include "../score.hh"

class TitleState : public GameState {
private:
	stringstream highScores;
	GameText drawTitle1;
	GameText pressStart;
	GameText highScoreText;
	GameText controls;
	GameText boon;
	GameText bane;

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
	Sound titleSound;


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
