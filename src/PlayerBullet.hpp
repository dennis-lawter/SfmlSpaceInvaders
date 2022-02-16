#ifndef PLAYERBULLET_HPP_
#define PLAYERBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class PlayerBullet : public GameObject {
public:
	bool playerIsFire = false;
	PlayerBullet(Texture& texture, float fired) : GameObject(texture, fired, 112) {}

	void update();
};

#endif