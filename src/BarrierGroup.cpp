#include "BarrierGroup.hpp"

BarrierGroup::BarrierGroup() {
	for (auto coord : COORDS) {
		barrierVector.emplace_back(coord.first * 8, coord.second * 8-4);
	}

	// for (int y : BARRIERPOSITIONY) {
	// 	for (int x : BARRIERPOSITIONX) {
	// 		barrierVector.emplace_back(x , y);
	// 	}
	// }
}

bool BarrierGroup::testHit(PlayerBullet& pew) {
	return false;
}
void BarrierGroup::update() {

}
void BarrierGroup::draw(RenderWindow& window) {
	for (Barrier& barrier : barrierVector) {
		barrier.draw(window);
	}
}