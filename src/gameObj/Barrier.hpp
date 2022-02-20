#ifndef BARRIER_HPP_
#define BARRIER_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "../resources.hh"

class Barrier : public GameObject{
public:
	Barrier(int x, int y) 
		:GameObject(resources::textures["barrier"], x, y) {}

	void update();

};

#endif