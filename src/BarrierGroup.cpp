#include "BarrierGroup.hpp"

BarrierGroup::BarrierGroup() {
	for (auto coord : COORDS) {
		barrierVector.emplace_back(coord.first * 8, coord.second * 8 - 4);
	}
}

bool BarrierGroup::testHitMany(vector<BaddieBullet>& objects) {
	for (auto i = objects.begin(); i != objects.end(); i++) {
		if(this->testHit(*i)) {
			objects.erase(i);
			return true;
		}
	}
	return false;
}

bool BarrierGroup::testHit(GameObject& pew) {
	for (int i = 0; i < barrierVector.size(); i++) {
		if (pew.collision().intersects(barrierVector[i].collision())) {
			barrierVector.erase(barrierVector.begin() + i);
			return true;
		}
	}
	return false;
}

void BarrierGroup::draw(RenderWindow& window) {
	for (Barrier& barrier : barrierVector) {
		barrier.draw(window);
	}
}