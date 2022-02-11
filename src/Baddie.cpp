#include <iostream>
#include "Baddie.hpp"
using namespace std;


void Baddie::moveRight() {
	this->sprite.move(speed, 0);
}

void Baddie::moveLeft() {
	this->sprite.move(-(speed), 0);
}

void Baddie::moveDown() {
	this->sprite.move(0, 10);
}


// void Baddie::update() {
// 	if (isMovingRight) {
// 		this->sprite.move(speed,0);
// 		if (this->getX() >= 120) {
// 			this->sprite.move(0,10);
// 			isMovingRight = false;
// 			speed += 0.2;

// 		}
// 	}	 
// 	else {
// 		this->sprite.move(-(speed),0);
// 		if (this->getX() <= 0) {
// 			this->sprite.move(0,10);
// 			isMovingRight = true;
// 			speed += 0.2;
// 		}
// 	}		
// }