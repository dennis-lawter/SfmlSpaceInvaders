#ifndef BADDIEGROUP_HPP_
#define BADDIEGROUP_HPP_
#include <SFML/Graphics.hpp>
#include "Baddie.hpp"
using namespace sf;

class BaddieGroup {
	public:
		const static int ROWS = 3;
		const static int COLUMNS = 7;
		const static int MAXBADDIES = ROWS * COLUMNS;
		int currentBaddies = 0;
		Texture textureArray[ROWS]; 
		Baddie* baddies[COLUMNS][ROWS];
		
		BaddieGroup();
		void update();
		void draw(RenderWindow& window);
};

#endif