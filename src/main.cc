#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BaddieGroup.hpp"
#include "Player.hpp"
#include "Baddie.hpp"
#include "PlayerBullet.hpp"
#include "BaddieBullet.hpp"
using namespace sf;
using namespace std;

RenderWindow window;
View kamera;
RectangleShape background;

Player* defender = nullptr;
PlayerBullet* pew = nullptr;
BaddieGroup* killemAll = nullptr;

int init() {
	try {
		resources::loadResources();
	} catch (runtime_error e) {
		return EXIT_FAILURE;
	}

	defender = new Player();
	killemAll = new BaddieGroup();

	background.setFillColor(Color::Black);
	background.setSize(Vector2f(128, 128));
	background.setPosition(0, 0);

	return EXIT_SUCCESS;
}

void windowInit() {
	int width = VideoMode::getDesktopMode().width - 100;
	int height = VideoMode::getDesktopMode().height - 120;
	int widthMulti = width / 128;
	int heightMulti = height / 128;
	int smallestMulti = (widthMulti > heightMulti) ? heightMulti : widthMulti;
	window.create(VideoMode(smallestMulti * 128, smallestMulti * 128), "Totally Invading Space");
	kamera.setSize(128, 128);
	kamera.setCenter(128 / 2, 128 / 2);
	window.setView(kamera);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
}

void update() {
	defender->update();
	defender->testHit(killemAll->bulletArray);
	if (pew) {
		pew->update();
		if (killemAll->testHit(*pew)) {
			delete pew;
			pew = nullptr;
		} else if (pew->getY() <= -6) {
			delete pew;
			pew = nullptr;
		}
	}
	killemAll->update();
	if (killemAll->currentBaddies <= 0) {
		window.close();
	}
	if (killemAll->baddiesWin()) {
		window.close();
	}
}
void draw() {
	window.clear(Color(0x000022ff));
	window.draw(background);
	if (pew) {
		pew->draw(window);
	}
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
			case Event::Resized:
			{
				double w, h, goal, x, y;
				double windowWidth = window.getSize().x;
				double windowHeight = window.getSize().y;
				double aspectRatio = windowWidth / windowHeight;
				if (aspectRatio > 1) {
					goal = windowHeight;
					w = goal / windowWidth;
					x = (1.0 - w) / 2.0;
					h = 1.0;
					y = 0.0;
				} 				else {
					goal = windowWidth;
					h = goal / windowHeight;
					y = (1.0 - h) / 2.0;
					w = 1.0;
					x = 0.0;
				}
				kamera.setViewport(FloatRect(x, y, w, h));
				window.setView(kamera);
				break;
			}
			case Event::KeyPressed:
				switch (currentEvent.key.code) {
				case Keyboard::Key::Escape:
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
				case Keyboard::W:
				case Keyboard::Up:
				case Keyboard::Space:
					if (!pew)
						pew = new PlayerBullet(defender->getX() + 3);
					break;
				default:
					break;
				}
				break;

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
