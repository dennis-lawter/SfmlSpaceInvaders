#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <SFML/Graphics.hpp>
#include "../resources.hh"
#include "../score.hh"

using namespace sf;

class GameObject {
protected:
	Sprite sprite;
public:
	float speed;
	
	GameObject(Texture& texture, float x, float y);

	void update();
	void draw(sf::RenderWindow& window);

	bool testCollision(GameObject& obj);

	FloatRect getHitBox();
	float getX();
	float getY();
	float getWidth();
	float getHeight();
};

#endif