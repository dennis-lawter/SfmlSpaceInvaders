#include "Ufo.hpp"

Ufo::Ufo() 
	: GameObject(resources::textures["ufo"], 128, 8) {

}

void Ufo::move() {
	this->sprite.move(-speed,0);
}

bool Ufo::isOffScreen() {
	return this->getX() < -this->getWidth();
}

void Ufo::update() {
	move();
}