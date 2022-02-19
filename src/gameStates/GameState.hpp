#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_
#include <SFML/Graphics.hpp>
using namespace sf;

class GameState {
public:
	virtual void processInput(Event& event) = 0;
	virtual void update(RenderWindow& window) = 0;
	virtual void draw(RenderWindow& window) = 0;

	virtual ~GameState() {}
};

#endif