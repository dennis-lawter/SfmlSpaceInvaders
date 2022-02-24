#ifndef GAMEPLAYSTATE_HPP_
#define GAMEPLAYSTATE_HPP_
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "../gameObj/Player.hpp"
#include "../gameObj/PlayerBullet.hpp"
#include "../gameObj/Barrier.hpp"
#include "../gameObj/groups/BaddieGroup.hpp"
#include "../gameObj/groups/BarrierGroup.hpp"
#include "../Hud.hpp"

using namespace sf;

class GamePlayState : public GameState {
private:
	Hud hud;
	Player defender;
	BaddieGroup killemAll;
	BarrierGroup saveMe;
public:
	bool didWin = false;

	GamePlayState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~GamePlayState();
};

#endif