#ifndef DEFINES_HH_
#define DEFINES_HH_

#include <string>
#include <vector>
using namespace std;

namespace defines {
	static const string GAME_NAME = "Totally Invading Space";
	static const int WIDTH = 128;
	static const int HEIGHT = 128;
	static const int UFO_FIRE_RANGE = 64;
	static const int UFO_FIRE_START = 32;
	static const string IMAGE_FILE_TYPE = ".png";
	static const string FONT_FILE_TYPE = ".ttf";
	static const string SOUND_FILE_TYPE = ".wav";
	static const int LIVES_CAP = 3;
	static const int BULLET_SPEED_MODIFIER_CAP = 3;

	static const string FONT_FILE_NAME = "PressStart2P";

	static const vector<string> TEXTURE_FILE_NAMES = {
		"1up",
		"aggression",
		"barrier",
		"bomb",
		"boom",
		"bullet",
		"coin",
		"curved",
		"defender",
		// "enemy",
		"explosion",
		"explosionmono",
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

	static const vector<string> SOUND_FILE_NAMES = {
		"1up",
		"bad",
		"baddieadvance",
		"baddieboom",
		"baddiepew",
		"barrierboom",
		"boss",
		"defenderboom",
		"defenderpew",
		"gameover",
		"randommusic",
		"speeddown",
		"speedup",
		"ufo",
		"ufoFire",
		"woah",
		"wtf"
	};


	enum PowerUp {
		OneUp = 0,
		Aggressive,
		Bomb,
		Coin,
		Curved,
		// Ghost,
		Missile,
		Passive,
		Punch,
		SpeedDown,
		SpeedUp,

		COUNT
	};

	static map<PowerUp, string> POWER_UP_LIST = {
		{OneUp, "1up"},
		{Aggressive, "aggression"},
		{Bomb, "bomb"},
		{Coin, "coin"},
		{Curved, "curved"},
		// {Ghost, "ghost"},
		{Missile, "missile"},
		{Passive, "passive"},
		{Punch, "punch"},
		{SpeedDown, "speed_down"},
		{SpeedUp, "speed_up"}
	};

}

#endif
