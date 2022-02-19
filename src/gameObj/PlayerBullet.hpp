#ifndef PLAYERBULLET_HPP_
#define PLAYERBULLET_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace sf;

class PlayerBullet : public GameObject {
public:
	PlayerBullet(float fired)
		: GameObject(resources::textures["bullet"], fired, 112) {}

	void update();
};

#endif