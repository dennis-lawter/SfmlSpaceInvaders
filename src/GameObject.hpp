#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <SFML/Graphics.hpp>
#include "resources.hh"

using namespace sf;

class GameObject {
protected:
	Sprite sprite;
public:
	float speed;
	
	GameObject(Texture& texture, float x, float y);
	void update();
	void draw(sf::RenderWindow& window);
	FloatRect collision();
	float getX();
	float getY();
};

#endif