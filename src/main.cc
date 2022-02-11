#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Baddie.hpp"
#include "Bullet.hpp"
#include "BaddieGroup.hpp"
using namespace sf;
using namespace std;

RenderWindow window;
Texture enemyTexture;
Texture playerTexture;
Texture bulletTexture;
Player* defender = nullptr; //No memory reserved
Bullet* pew = nullptr;
BaddieGroup killemAll;

int init() {
	if (!playerTexture.loadFromFile("res/resource/defender.png")) {
		return EXIT_FAILURE;
	}

	if (!bulletTexture.loadFromFile("res/resource/bullet.png")) {
		return EXIT_FAILURE;
	}

	defender = new Player(playerTexture); //reserves memory for new object

	return EXIT_SUCCESS;
}

void update() {
	defender->update();
	if (pew) {
		pew->update();
		if (killemAll.testHit(*pew)) {
			delete pew; //frees memory
			pew = nullptr;
		} else if (pew->getY() <= -6) {
			delete pew;
			pew = nullptr;
		}
	}
	killemAll.update();
	if (killemAll.currentBaddies <= 0) {
		window.close();
	}
}
void draw() {
	window.clear(Color::Black);
	if (pew) {
		pew->draw(window);
	}
	defender->draw(window);
	killemAll.draw(window);
	window.display();
}

int main(int argc, char** argv) {
	if (init() != EXIT_SUCCESS)
		return EXIT_FAILURE;
	window.create(VideoMode(128, 128), "Totally Invading Space");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		Event currentEvent;
		while (window.pollEvent(currentEvent)) {
			switch (currentEvent.type) {
			case Event::Closed:
				window.close();
				break;
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
						pew = new Bullet(bulletTexture, defender->getX() + 3);
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
	if (pew)
		delete pew;
	return EXIT_SUCCESS;
}
