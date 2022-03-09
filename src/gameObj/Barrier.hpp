#ifndef BARRIER_HPP_
#define BARRIER_HPP_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
// #include "../resources.hh"

class Barrier : public GameObject {
public:
	Vector2f startingPosition;
	Vector2f destination;
	Barrier(int x, int y);
};

#endif