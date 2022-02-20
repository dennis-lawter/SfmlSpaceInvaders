#ifndef GAMEOVERSTATE_HPP_
#define GAMEOVERSTATE_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "GameState.hpp"
#include "GamePlayState.hpp"
#include "../resources.hh"
using namespace std;
using namespace sf;

class GameOverState : public GameState {
	Font& font = resources::font;
	string gameOver = "GAME OVER";
	string pressAnyKey = "Press Any Key To Reset";
	string youWin = "YOU WIN";
	string youLose = "YOU LOSE";
	const int BLINKTIMER = 40;
	int blinkBuffer = 0;
	bool isBlink = false;
	const int BUFFERTIMER = 90;
	int bufferTick = 0;
	bool holdBuffer = true;
public:
	bool didWin;
	GameOverState(bool didWin);

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~GameOverState();

};

#endif