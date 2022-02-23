#include "BarrierGroup.hpp"

BarrierGroup::BarrierGroup() {
	for (auto coord : COORDS) {
		barrierVector.emplace_back(coord.first * 8, coord.second * 8 - 4);
	}
}

bool BarrierGroup::testOneForCollision(GameObject& obj, bool deleteMine) {
	for (auto barrier = barrierVector.begin(); barrier < barrierVector.end(); barrier++) {
		if (barrier->testCollision(obj)) {
			if (deleteMine) {
				barrierVector.erase(barrier);
			}
			return true;
		}
	}
	return false;
}

bool BarrierGroup::testManyForCollision(vector<GameObject>& objs, bool deleteMine, bool deleteTheirs) {
	for (auto obj = objs.begin(); obj < objs.end(); obj++) {
		if (testOneForCollision(*obj, deleteMine)) {
			if (deleteTheirs) {
				objs.erase(obj);
			}
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

BarrierGroup::~BarrierGroup() {}