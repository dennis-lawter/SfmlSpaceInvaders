#include "BaddieGroup.hpp"

/* Builds all baddies and assigns texture based off the row its in
*/
BaddieGroup::BaddieGroup() {
	Texture* textureArray[ROWS];
	textureArray[0] = &resources::textures["invader3"];
	textureArray[1] = &resources::textures["invader2"];
	textureArray[2] = &resources::textures["invader1"];

	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			baddies[x][y] = new Baddie(*textureArray[y], x * 12, 10.1 + (y * 14));
		}
	}
}

/*Tests to see if player's bullet intercepts with a baddie.
Baddie will die on execution.
*/
bool BaddieGroup::testHit(PlayerBullet& pew) {
	for (int y = ROWS - 1; y >= 0; y--) {
		for (int x = COLUMNS - 1; x >= 0; x--) {
			if (baddies[x][y]) {
				if (baddies[x][y]->collision().intersects(pew.collision())) {
					delete baddies[x][y];
					baddies[x][y] = nullptr;
					didDieThisFrame = true;
					return true;
				}
			}
		}
	}
	return false;
}

/*Will pass true when a baddie hits the bottom of the screen.
Registers from the bottom row on furthest right column.
*/
bool BaddieGroup::baddiesWin() {
	for (int y = ROWS - 1; y >= 0; y--) {
		for (int x = COLUMNS - 1; x >= 0; x--) {
			if (baddies[x][y]) {
				return (baddies[x][y]->getY() >= 115);
			}
		}
	}
	return false;
}


void BaddieGroup::baddieShoot() {
	if (SHOOTDELAY <= shootTimer) {
		randomColumn = rand() % COLUMNS + 0;
		for (int y = ROWS - 1; y >= 0; y--) {
			if (baddies[randomColumn][y]) {
				baddieCurrentX = baddies[randomColumn][y]->getX() + 3;
				baddieCurrentY = baddies[randomColumn][y]->getY() + 8;
				bulletArray.emplace(bulletArray.end(), BaddieBullet(baddieCurrentX, baddieCurrentY));
				shootTimer = 0;
				return;
			}
		}
	}
	shootTimer++;
	return;
}

void BaddieGroup::update() {
	bool allMoveDown = false;
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y]) {
				if (allMoveRight) {
					baddies[x][y]->moveRight();
					if (baddies[x][y]->getX() >= 120) {
						allMoveDown = true;
					}
				} else if (!allMoveRight) {
					baddies[x][y]->moveLeft();
					if (baddies[x][y]->getX() <= 0) {
						allMoveDown = true;
					}
				}
			}
		}
	}
	if (allMoveRight && allMoveDown) {
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					baddies[x][y]->moveDown();
				}
			}
		}
		allMoveDown = false;
		allMoveRight = false;
	}
	if (!allMoveRight && allMoveDown) {
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					baddies[x][y]->moveDown();
				}
			}
		}
		allMoveDown = false;
		allMoveRight = true;
	}
	if (didDieThisFrame) {
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					baddies[x][y]->speed += .02;
				}
			}
		}
		didDieThisFrame = false;
		currentBaddies--;
	}
	baddieShoot();
	//for (auto i = bulletArray.begin(); i != bulletArray.end(); i++) {
	for (int i=0; i < bulletArray.size(); i++) {
		BaddieBullet & bullet = bulletArray[i];
		bullet.update();
		if (bullet.offScreen()) {
			bulletArray.erase(bulletArray.begin() + i);
		}
	}
}


void BaddieGroup::draw(RenderWindow& window) {
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y])
				baddies[x][y]->draw(window);
		}
	}
	for (BaddieBullet& bullet : bulletArray) {
		bullet.draw(window);
	}
}