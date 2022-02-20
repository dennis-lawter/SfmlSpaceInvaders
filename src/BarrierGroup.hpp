#ifndef BARRIERGROUP_HPP_
#define BARRIERGROUP_HPP_
#include <SFML/Graphics.hpp>
#include "gameObj/Barrier.hpp"
#include "gameObj/PlayerBullet.hpp"

class BarrierGroup {
private:
	const vector<pair<int, int>> COORDS = {
		{3,14},
		{4,14},
		{5,14},
		{3,13},
		{4,13},
		{5,13},
		{3+7,14},
		{4+7,14},
		{5+7,14},
		{3+7,13},
		{4+7,13},
		{5+7,13}
	}; 
	// const static int SIZEX = 6;
	// const static int SIZEY = 2;
	// const static int TOTALBARRIERS = SIZEX * SIZEY;
	// const int BARRIERPOSITIONX[SIZEX] = {0,8,16,24,32,40};
	// const int BARRIERPOSITIONY[SIZEY] = {0,8};

public:
	vector<Barrier> barrierVector;

	BarrierGroup();
	bool testHit(PlayerBullet& pew);
	void update();
	void draw(RenderWindow& window);

};

#endif