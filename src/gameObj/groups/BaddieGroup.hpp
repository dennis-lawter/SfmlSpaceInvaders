#ifndef BADDIEGROUP_HPP_
#define BADDIEGROUP_HPP_
#include "../Baddie.hpp"
#include "../BaddieBullet.hpp"
#include "../Particle.hpp"
#include "../../score.hh"
#include "../Barrier.hpp"

class BaddieGroup {
private:
	const static int SHOOT_DELAY = 60;

	const float SPEED_MULT = 0.0125; // can't be static, doesn't need to be

	bool allMoveRight = true;
	int baddiesKilledThisFrame = 0;
	int randomColumn = 0;
	int shootTimer = 0;

	Sound baddiepew;

	void moveBaddies();
	void accelerateBaddies();
	void baddieShoot();
	void bulletUpdate();
	void deleteBaddie(int x, int y);
public:
	const static int COLUMNS = 7;
	const static int ROWS = 3;
	const static int MAX_BADDIES = ROWS * COLUMNS;
	Baddie* baddies[COLUMNS][ROWS];
	vector<BaddieBullet> bulletVector;
	int currentBaddies = MAX_BADDIES;
	int baddiesTimesAdvanced = 0;
	float shakeSpeed = 0.f;

	BaddieGroup();

	bool testOneForCollision(GameObject* obj, bool deleteMine);
	bool testManyForCollisionWithBarrier(vector<Barrier>& objs, bool deleteMine, bool deleteTheirs);

	bool isBaddiesAdvance();
	bool isBaddiesWin();

	void animateIntro(int framesElapsed);

	void update();
	void windowShake(RenderWindow& window);
	void draw(RenderWindow& window);

	~BaddieGroup();
};

#endif
