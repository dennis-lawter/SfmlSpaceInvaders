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
	Sound gameOverSound;
	
	const string gameOver = "GAME OVER";
	const string pressAnyKey = "PRESS ANY KEY TO RESET";

	GameText highScoreText;
	GameText gameOverText;
	GameText pressAnyKeyText;

	const int BLINKTIMER = 40;
	int blinkBuffer = 0;
	bool isTextHidden = true;
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
