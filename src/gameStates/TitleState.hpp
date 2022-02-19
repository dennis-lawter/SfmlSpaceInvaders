#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
using namespace sf;

class TitleState : public GameState {
public:
	TitleState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~TitleState();
};

#endif