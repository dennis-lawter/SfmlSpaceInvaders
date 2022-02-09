#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

using namespace sf;

class Player : public GameObject {
public:
	bool playerIsMovingLeft = false;
	bool playerIsMovingRight = false;
	bool playerIsFire = false;
	int playerLives = 3;
	//todo add damage indicator, death "animation", score
	Player(Texture& texture) : GameObject(texture, 60, 120) {}
	void update();
};

#endif