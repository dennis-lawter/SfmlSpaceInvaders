#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BaddieGroup.hpp"
#include "Player.hpp"
#include "Baddie.hpp"
#include "PlayerBullet.hpp"
#include "BaddieBullet.hpp"
#include "Hud.hpp"
using namespace sf;
using namespace std;

RenderWindow window;
View kamera;
RectangleShape background;

Player* defender = nullptr;
PlayerBullet* pew = nullptr;
BaddieGroup* killemAll = nullptr;
Hud* hud = nullptr;


int init() {
	/* a try catch will run the first function and catches a RUNTIME ERROR
	
	*/
	try {
		resources::loadResources();
	} catch (runtime_error e) {
		return EXIT_FAILURE;
	}

	defender = new Player();
	killemAll = new BaddieGroup();
	hud = new Hud();

	background.setFillColor(Color::Black);
	background.setSize(Vector2f(defines::WIDTH, defines::HEIGHT));
	background.setPosition(0, 0);

	return EXIT_SUCCESS;
}


/*Creates the window within a certain range of the user screen and creates
a square screen that makes the game large enough to see the models at a 
proper aspect ratio
*/
void windowInit() {
	int width = VideoMode::getDesktopMode().width - 100;
	int height = VideoMode::getDesktopMode().height - 120;
	int widthMulti = width / defines::WIDTH;
	int heightMulti = height / defines::HEIGHT;
	int smallestMulti = (widthMulti > heightMulti) ? heightMulti : widthMulti;
	window.create(VideoMode(smallestMulti * defines::WIDTH, smallestMulti * defines::HEIGHT), defines::GAME_NAME);
	kamera.setSize(defines::WIDTH, defines::HEIGHT);
	kamera.setCenter(defines::WIDTH / 2, defines::HEIGHT / 2);
	window.setView(kamera);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
}

void update() {
	defender->update();
	if(defender->testHit(killemAll->bulletArray)) {
		hud->currentLives--;
	}
	if (pew) {
		pew->update();
		if (killemAll->testHit(*pew)) { //deletes bullet on enemy contact
			delete pew;
			pew = nullptr;
			hud->score += 100;
		} else if (pew->getY() <= 6) { //deletes bullet when it leaves screen
			delete pew;
			pew = nullptr;
		}
	}
	killemAll->update();
	if (killemAll->currentBaddies <= 0) { //Win Condition
		window.close();
	}
	if (killemAll->baddiesWin() || hud->currentLives < 0) { //Lose Condition
		window.close();
	}
}

void draw() {
	window.clear(Color(0x000022ff)); //The background of the game when in fullscreen
	window.draw(background);
	if (pew) {
		pew->draw(window);
	}
	hud->draw(window);
	defender->draw(window);
	killemAll->draw(window);
	window.display();
}

int main(int argc, char** argv) {
	if (init() != EXIT_SUCCESS)
		return EXIT_FAILURE;
	windowInit();

	while (window.isOpen()) {
		Event currentEvent;
		while (window.pollEvent(currentEvent)) {
			switch (currentEvent.type) {
			case Event::Closed:
				window.close();
				break;
/* This case allows the game to become fullscreen and maintain aspect ratio
*/
			case Event::Resized:
			{
				double w, h, goal, x, y;
				double windowWidth = window.getSize().x;
				double windowHeight = window.getSize().y;
				double screenAspectRatio = windowWidth / windowHeight;
				double gameAspectRatio = ((double)defines::WIDTH) / defines::HEIGHT;
				if (screenAspectRatio > 1) {
					goal = windowHeight / gameAspectRatio;
					w = goal / windowWidth;
					x = (1.0 - w) / 2.0;
					h = 1.0;
					y = 0.0;
				} else {
					goal = windowWidth / gameAspectRatio;
					h = goal / windowHeight;
					y = (1.0 - h) / 2.0;
					w = 1.0;
					x = 0.0;
				}
				kamera.setViewport(FloatRect(x, y, w, h));
				window.setView(kamera);
				break;
			}
/* This case is for player controls
*/
			case Event::KeyPressed:
				switch (currentEvent.key.code) {
				case Keyboard::Key::Escape: //Manual game close
					window.close();
					break;
				case Keyboard::Key::A:
				case Keyboard::Key::Left: //Move Left
					defender->playerIsMovingLeft = true;
					break;
				case Keyboard::Key::D:
				case Keyboard::Key::Right: //Move Right
					defender->playerIsMovingRight = true;
					break;
				case Keyboard::W: //Player fires
				case Keyboard::Up:
				case Keyboard::Space:
					if (!pew)
						pew = new PlayerBullet(defender->getX() + 3);
					break;
				default:
					break;
				}
				break;

/* This case allows for smooth player movement left and right
*/
			case Event::KeyReleased:
				switch (currentEvent.key.code) {
				case Keyboard::Key::A:
				case Keyboard::Key::Left:
					defender->playerIsMovingLeft = false;
					break;
				case Keyboard::Key::D:
				case Keyboard::Key::Right:
					defender->playerIsMovingRight = false;
					break;
				default:
					break;
				}
			default:
				break;
			}

		}

		update();
		draw();
	}
	delete defender;
	delete killemAll;
	if (pew)
		delete pew;
	return EXIT_SUCCESS;
}
