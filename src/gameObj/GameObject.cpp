#include "GameObject.hpp"
GameObject::GameObject(Texture& texture, float x, float y) {
	this->sprite.setTexture(texture);
	this->sprite.move(x, y);
}
void GameObject::draw(sf::RenderWindow& window) {
	window.draw(this->sprite);
}
FloatRect GameObject::collision() {
	return this->sprite.getGlobalBounds();
}
float GameObject::getX() { //get current x position of object from the top left pixel of the object
	return this->sprite.getPosition().x;
}
float GameObject::getY() { //get current y position of object from the top left pixel of the object
	return this->sprite.getPosition().y;
}