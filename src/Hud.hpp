#ifndef HUD_HPP_
#define HUD_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include "resources.hh"
using namespace sf;
using namespace std;


class Hud {
private:
	Font& font = resources::font;
	stringstream scoreOut; 
public:
	Sprite lives;
	int currentLives = 2;
	int score = 0;
	//int secretBonus = 5000;
	Hud();
	void draw(RenderWindow& window);
	void update();
};


#endif