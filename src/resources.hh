#ifndef RESOURCES_HH_
#define RESOURCES_HH_

#include <map>
#include <exception>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "defines.hh"

using namespace sf;
using namespace std;

namespace resources {
	extern string dirRoot;
	extern map<string, Texture> textures;
	extern Font font;

	void loadResources();
}

#endif