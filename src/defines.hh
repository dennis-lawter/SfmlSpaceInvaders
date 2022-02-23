#ifndef DEFINES_HH_
#define DEFINES_HH_

#include <string>
#include <vector>
using namespace std;

namespace defines {
	static const string GAME_NAME = "Totally Invading Space";
	static const int WIDTH = 128;
	static const int HEIGHT = 128;
	static const string IMAGE_FILE_TYPE = ".png";
	static const string FONT_FILE_TYPE = ".ttf";
	static const int LIVES_CAP = 3;

	static const string FONT_FILE_NAME = "PressStart2P";

	static const vector<string> TEXTURE_FILE_NAMES = {
		"1up",
		"aggression",
		"barrier",
		"bomb",
		"boom",
		"bullet",
		"coin",
		"defender",
		// "enemy",
		"explosion",
		"ghost",
		"invader1",
		"invader2",
		"invader3",
		"missile",
		"passive",
		// "player",
		"punch",
		"speed_down",
		"speed_up",
		"ufo"
	};
}

#endif