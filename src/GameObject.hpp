#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject {
    protected:
		Sprite sprite;
	public:
		GameObject(Texture& texture, float x, float y);
		void update();
		void draw(sf::RenderWindow& window);
		FloatRect collision();
		float getX ();
		float getY ();
};

#endif