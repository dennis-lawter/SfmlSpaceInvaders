#include "Player.hpp"

/* Bullet gets erased when it hits a player
*/
bool Player::testHit(vector<BaddieBullet>& pew) {
	for (auto i = pew.begin(); i != pew.end(); i++) {
		if (this->collision().intersects(i->collision())) {
			pew.erase(i);
			return true;
		}
	}
	return false;
}


void Player::update() {
	if (this->playerIsMovingLeft) {
		if (this->getX() > 0) {
			this->sprite.move(-.7, 0);
		}
	}
	if (this->playerIsMovingRight) {
		if (this->getX() < 120) {
			this->sprite.move(.7, 0);
		}
	}
}