#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Baddie.hpp"
#include "Bullet.hpp"
using namespace sf;
using namespace std;

int main(int argc, char** argv) {

	

	RenderWindow window(VideoMode(128, 128), "Totally Invading Space");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
	
	Texture enemyTexture;
	enemyTexture.setSmooth(false);
	enemyTexture.setRepeated(false);
	if (!enemyTexture.loadFromFile("res/resource/enemy.png")) {
		return EXIT_FAILURE;
	}

	Texture playerTexture;
	if (!playerTexture.loadFromFile("res/resource/player.png")) {
		return EXIT_FAILURE;
	}

	Texture bulletTexture;
	if (!bulletTexture.loadFromFile("res/resource/bullet.png")) {
		return EXIT_FAILURE;
	}

	Player defender (playerTexture);
	Baddie killem (enemyTexture);
	Bullet* pew = nullptr;


	while(window.isOpen()) {
		Event currentEvent;
		while (window.pollEvent(currentEvent)) {
			switch (currentEvent.type) {
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					switch(currentEvent.key.code) {
						case Keyboard::Key::Escape:
							window.close();
							break;
						case Keyboard::Key::A:
						case Keyboard::Key::Left: //Move Left
							defender.playerIsMovingLeft = true;
							break;
						case Keyboard::Key::D:
						case Keyboard::Key::Right: //Move Right
							defender.playerIsMovingRight = true;
							break;
						case Keyboard::W:
						case Keyboard::Up:
						case Keyboard::Space:
							if (!pew)
								pew = new Bullet(bulletTexture, defender.getX() + 3);
							break;
					}
					break;

				case Event::KeyReleased:
					switch(currentEvent.key.code) {
						case Keyboard::Key::A:
						case Keyboard::Key::Left:
							defender.playerIsMovingLeft = false;
							break;
						case Keyboard::Key::D:
						case Keyboard::Key::Right:
							defender.playerIsMovingRight = false;
							break;
					}
			}

		}

		defender.update();
		killem.update();
		if (pew) {
			pew->update();
			if (pew->collision().intersects(killem.collision())) {
				delete pew;
				pew = nullptr;
			}
			else if (pew->getY() <= -6) {
				delete pew;
				pew = nullptr;
			}
		}
		window.clear(Color::Black);
		if (pew) {
			pew->draw(window);
		}
		defender.draw(window);
		killem.draw(window);
		window.display();
	}

	return EXIT_SUCCESS;
}
