#ifndef BADDIEGROUP_HPP_
#define BADDIEGROUP_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "gameObj/Baddie.hpp"
#include "gameObj/PlayerBullet.hpp"
#include "gameObj/BaddieBullet.hpp"
using namespace sf;
using namespace std;

class BaddieGroup {
public:
	const static int ROWS = 3;
	const static int COLUMNS = 7;
	const static int MAXBADDIES = ROWS * COLUMNS;
	int currentBaddies = MAXBADDIES;
	Baddie* baddies[COLUMNS][ROWS];
	vector<BaddieBullet> bulletArray;
	bool allMoveRight = true;
	bool didDieThisFrame = false;
	int randomColumn = 0;
	int const SHOOTDELAY = 60;
	int shootTimer = 0;
	float baddieCurrentX = 0;
	float baddieCurrentY = 0;


	BaddieGroup();
	bool testHit(GameObject& pew);
	bool baddiesWin();
	void baddieShoot();
	void update();
	void draw(RenderWindow& window);
};

#endif