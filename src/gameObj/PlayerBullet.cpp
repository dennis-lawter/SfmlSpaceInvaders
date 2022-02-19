#include "PlayerBullet.hpp"

void PlayerBullet::update() {
    this->sprite.move(0, -2);
}