#ifndef ENTERINITIALSSTATE_HPP_
#define ENTERINITIALSSTATE_HPP_
#include "GameState.hpp"

class EnterInitialsState : public GameState {
private:
	GameText newHighScoreText;
	GameText instructionsText;
	GameText playerEnteredText;
	string playerInitials = "   ";
	Vector2f screenCenter = {defines::WIDTH/2.f, defines::HEIGHT/2.f};
	bool isBlink = false;
	char displayedChar = ' ';
	int currentCharIndex = 0;
public:
	EnterInitialsState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~EnterInitialsState();
};

#endif
