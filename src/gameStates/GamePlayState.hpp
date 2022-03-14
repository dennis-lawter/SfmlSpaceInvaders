#ifndef GAMEPLAYSTATE_HPP_
#define GAMEPLAYSTATE_HPP_
#include "GameState.hpp"
#include "../gameObj/groups/ParticleGroup.hpp"
#include "../gameObj/groups/BaddieGroup.hpp"
#include "../gameObj/groups/BarrierGroup.hpp"
#include "../gameObj/Player.hpp"
#include "../gameObj/PlayerBullet.hpp"
#include "../gameObj/Barrier.hpp"
#include "../gameObj/Ufo.hpp"
#include "../gameObj/Powerup.hpp"
#include "../Hud.hpp"
#include "../score.hh"

class GamePlayState : public GameState {
private:
	ParticleGroup particles;
	Hud hud;
	Player defender;
	BaddieGroup killemAll;
	BarrierGroup saveMe;
	Sound startMusic;
	Text pause;
	RectangleShape pauseTint;
	Ufo* ufo = nullptr;
	Powerup* powerup = nullptr;
	Sound powerupSound;
	Sound powerdownSound;
	Sound playerDeath;


	const static int ROUND_START_MAX = 425;
	int roundStartTimer = 0;
	const static int BLINK_MAX = 380;
	const static int BLINK_SPEED = 20;
	const static int UFO_TIMER_MAX = 600;
	const static int UFO_TIMER_MIN = 50;
	const static int END_ROUND_TIMER = 100;
	int ufoBuffer = 0;
	int setUfoRandom = 0;
	int endRoundBuffer = 0;
	defines::PowerUp randomPowerup;

	void startRound();
	void endRound();
	void updateComponents();
	void detectCollisions();
	void removeOffscreenAssets();
	void calculateUfo();
	void calculateStateStatus();
public:
	bool didWin = false;
	bool roundStart = true;
	bool isPause = false;
	bool setUfoTimer = false;
	bool isUfoMoving = false;
	bool didUfoFire = false;

	stringstream roundTitle;



	GamePlayState();

	void processInput(Event& event);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);

	virtual ~GamePlayState();
};

#endif
