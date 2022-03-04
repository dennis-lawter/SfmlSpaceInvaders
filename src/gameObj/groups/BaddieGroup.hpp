#ifndef BADDIEGROUP_HPP_
#define BADDIEGROUP_HPP_
#include <SFML/Graphics.hpp>
#include "../Baddie.hpp"
#include "../BaddieBoom.hpp"
#include "../BaddieBullet.hpp"
#include "../../score.hh"
using namespace sf;
using namespace std;

class BaddieGroup {
private:
	const static int SHOOT_DELAY = 60;
	const static int ROWS = 3;
	const static int COLUMNS = 7;
	const static int MAX_BADDIES = ROWS * COLUMNS;
	const float SPEED_MULT = 0.0125; // can't be static, doesn't need to be

	bool allMoveRight = true;
	int baddiesKilledThisFrame = 0;
	int randomColumn = 0;
	int shootTimer = 0;

	Sound baddiepew;

	void deathAnimationUpdate();
	void moveBaddies();
	void accelerateBaddies();
	void baddieShoot();
	void bulletUpdate();

	void deleteBaddie(int x, int y);
public:
	Baddie* baddies[COLUMNS][ROWS];
	vector<BaddieBullet> bulletVector;
	vector<BaddieBoom> deathList;
	int currentBaddies = MAX_BADDIES;

	BaddieGroup();

	bool testOneForCollision(GameObject& obj, bool deleteMine);
	bool testManyForCollision(vector<GameObject>& objs, bool deleteMine, bool deleteTheirs);

	bool isBaddiesAdvance();
	bool isBaddiesWin();

	void update();
	void draw(RenderWindow& window);

	~BaddieGroup();
};

#endif