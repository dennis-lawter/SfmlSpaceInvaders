#ifndef BADDIEGROUP_HPP_
#define BADDIEGROUP_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Baddie.hpp"
#include "Bullet.hpp"
using namespace sf;
using namespace std;


class BaddieGroup {
	public:
		const static int ROWS = 3;
		const static int COLUMNS = 7;
		const static int MAXBADDIES = ROWS * COLUMNS;
		int currentBaddies = MAXBADDIES;
		Texture textureArray[ROWS]; 
		Baddie* baddies[COLUMNS][ROWS];
		bool allMoveRight = true;
		bool didDieThisFrame = false;

		BaddieGroup();
		bool testHit(Bullet &pew);
		bool baddiesWin();
		void update();
		void draw(RenderWindow& window);
};

#endif