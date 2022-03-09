#ifndef GAMEOVERSTATE_HPP_
#define GAMEOVERSTATE_HPP_
#include <iostream>
#include <iomanip>
#include <vector>
#include "GameState.hpp"
#include "GamePlayState.hpp"
#include "../Hud.hpp"
#include "../score.hh"
#include "../resources.hh"

class GameOverState : public GameState {
private:
	Hud hud;
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
	stringstream highScores;
public:
	bool didWin;
	GameOverState(bool didWin);

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~GameOverState();

};

#endif