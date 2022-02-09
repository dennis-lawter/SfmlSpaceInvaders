#include "Player.hpp"

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