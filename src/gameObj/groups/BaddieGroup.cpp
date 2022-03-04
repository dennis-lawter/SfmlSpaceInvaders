#include "BaddieGroup.hpp"

/* Builds all baddies and assigns texture based off the row its in
*/
BaddieGroup::BaddieGroup() {
	Texture* textureArray[ROWS];
	textureArray[0] = &resources::textures["invader3"];
	textureArray[1] = &resources::textures["invader2"];
	textureArray[2] = &resources::textures["invader1"];
	baddiepew.setBuffer(resources::soundFile["baddiepew"]);

	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			baddies[x][y] = new Baddie(*textureArray[y], x * 12, 10 + (y * 12));
			baddies[x][y]->speed += score::speedModifier;
		}
	}
}

bool BaddieGroup::isBaddiesAdvance() {
	if (allMoveRight) {
		/*
		18 15 12  9  6  3  0
		19 16 13 10  7  4  1
		20 17 14 11  8  5  2
		*/
		for (int x = COLUMNS - 1; x >= 0; x--) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					return (baddies[x][y]->getX() >= 120);
				}
			}
		}
	} else {
		/*
		0  3  6  9 12 15 18
		1  4  7 10 13 16 19
		2  5  8 11 14 17 20
		*/
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					return (baddies[x][y]->getX() <= 0);
				}
			}
		}
	}
	return false;
}

void BaddieGroup::moveBaddies() {
	if (isBaddiesAdvance()) {
		allMoveRight = !allMoveRight;
		score::scoreBonus--;
		// order is irrelevant
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					baddies[x][y]->moveDown();
				}
			}
		}
	} else {
		// order is irrelevant
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					if (allMoveRight) {
						baddies[x][y]->moveRight();
					} else {
						baddies[x][y]->moveLeft();
					}
				}
			}
		}
	}
}

void BaddieGroup::accelerateBaddies() {
	while (baddiesKilledThisFrame > 0) {
		// order irrelevant
		for (int x = 0; x < COLUMNS; x++) {
			for (int y = 0; y < ROWS; y++) {
				if (baddies[x][y]) {
					baddies[x][y]->speed += (SPEED_MULT * MAX_BADDIES) / currentBaddies;
				}
			}
		}
		baddiesKilledThisFrame--;
		currentBaddies--;
	}
}

void BaddieGroup::baddieShoot() {
	if (shootTimer > SHOOT_DELAY) {
		randomColumn = rand() % COLUMNS + 0;
		// Bottom-up
		for (int y = ROWS - 1; y >= 0; y--) {
			if (baddies[randomColumn][y]) {
				float bulletX = baddies[randomColumn][y]->getX() + 3;
				float bulletY = baddies[randomColumn][y]->getY() + 8;
				bulletVector.emplace_back(BaddieBullet(bulletX, bulletY));
				shootTimer = 0;
				baddiepew.play();
				return;
			}
		}
	}
	shootTimer++;
	return;
}

void BaddieGroup::bulletUpdate() {
	for (auto bullet = bulletVector.begin(); bullet < bulletVector.end(); bullet++) {
		bullet->update();
		if (bullet->isOffScreen()) {
			bulletVector.erase(bullet);
		}
	}
}

void BaddieGroup::deathAnimationUpdate() {
	for (auto nextToDie = deathList.begin(); nextToDie < deathList.end(); nextToDie++) {
		nextToDie->update();
		if (nextToDie->buffer >= nextToDie->ERASE_TIMER) {
			deathList.erase(nextToDie);
		}
	}
}

void BaddieGroup::deleteBaddie(int x, int y) {
	deathList.emplace_back(baddies[x][y]->getX(), baddies[x][y]->getY());
	delete baddies[x][y];
	baddies[x][y] = nullptr;
}

bool BaddieGroup::testOneForCollision(GameObject& obj, bool deleteMine) {
	if (allMoveRight) {
		/*
		20 19 18 17 16 15 14
		13 12 11 10  9  8  7
		 6  5  4  3  2  1  0
		*/
		for (int y = ROWS - 1; y >= 0; y--) {
			for (int x = COLUMNS - 1; x >= 0; x--) {
				if (baddies[x][y]) {
					if (baddies[x][y]->testCollision(obj)) {
						if (deleteMine) {
							deleteBaddie(x, y);
							baddiesKilledThisFrame++;
						}
						return true;
					}
				}
			}
		}
	} else {
		/*
		14 15 16 17 18 19 20
		 7  8  9 10 11 12 13
		 0  1  2  3  4  5  6
		*/
		for (int y = ROWS - 1; y >= 0; y--) {
			for (int x = 0; x < COLUMNS; x++) {
				if (baddies[x][y]) {
					if (baddies[x][y]->testCollision(obj)) {
						if (deleteMine) {
							deleteBaddie(x, y);
							baddiesKilledThisFrame++;
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool BaddieGroup::testManyForCollision(vector<GameObject>& objs, bool deleteMine, bool deleteTheirs) {
	for (auto obj = objs.begin(); obj < objs.end(); obj++) {
		if (testOneForCollision(*obj, deleteMine)) {
			if (deleteTheirs) {
				objs.erase(obj);
			}
			return true;
		}
	}
	return false;
}

bool BaddieGroup::isBaddiesWin() {
	/*
	14 15 16 17 18 19 20
	 7  8  9 10 11 12 13
	 0  1  2  3  4  5  6
	*/
	for (int y = ROWS - 1; y >= 0; y--) {
		for (int x = 0; x < COLUMNS; x++) {
			if (baddies[x][y]) {
				return (baddies[x][y]->getY() >= 115);
			}
		}
	}
	return false;
}

void BaddieGroup::update() {
	moveBaddies();
	accelerateBaddies();
	baddieShoot();
	bulletUpdate();
	deathAnimationUpdate();
}


void BaddieGroup::draw(RenderWindow& window) {
	for (BaddieBoom& theDead : deathList) {
		theDead.draw(window);
	}
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y])
				baddies[x][y]->draw(window);
		}
	}
	for (BaddieBullet& bullet : bulletVector) {
		bullet.draw(window);
	}
}

BaddieGroup::~BaddieGroup() {
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y]) {
				deleteBaddie(x, y);
			}
		}
	}
}