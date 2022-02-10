#include "BaddieGroup.hpp"

BaddieGroup::BaddieGroup() {
	textureArray[0].loadFromFile("res/resource/invader3.png");
	textureArray[1].loadFromFile("res/resource/invader2.png");
	textureArray[2].loadFromFile("res/resource/invader1.png");

	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			baddies[x][y] = new Baddie(textureArray[y], x * 12, 4 + (y * 14));
		}
	}
}

bool BaddieGroup::testHit(Bullet &pew) {
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y]){
				if (baddies[x][y]->collision().intersects(pew.collision())) {
					delete baddies[x][y];
					baddies[x][y] = nullptr;
					return true;
				}	
			}
		}
	}
	return false;
}

void BaddieGroup::update() {
	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {
			if (baddies[x][y]){
				baddies[x][y]->update();
			}	
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
}