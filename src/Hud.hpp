#ifndef HUD_HPP_
#define HUD_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include "resources.hh"
#include "score.hh"
using namespace sf;
using namespace std;


class Hud {
private:
	Font& font = resources::font;
	stringstream scoreOut;
public:
	Sprite lives;
	
	Hud();
	void draw(RenderWindow& window);
	void update();
};

#endif