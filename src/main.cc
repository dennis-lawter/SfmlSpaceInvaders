#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class GameObject {
	public:
		Sprite sprite;
		GameObject(Texture& texture, int x, int y) {
			this->sprite.setTexture(texture);
			this->sprite.move(x, y);
		}
		void update() {}
		void draw(sf::RenderWindow& window) {
			window.draw(this->sprite);
		}
};

class Player : public GameObject {
	public:
		bool playerIsMovingLeft = false;
		bool playerIsMovingRight = false;
		bool playerIsFire = false;
		int playerLives = 3;
		//todo add damage indicator, death "animation", score
		Player(Texture& texture) : GameObject(texture, 60, 120) {}
		void update() {
			if (this->playerIsMovingLeft) {
				if(this->sprite.getPosition().x > 0) {
					this->sprite.move(-.7,0);
				}
			}
			if (this->playerIsMovingRight) {
				if(this->sprite.getPosition().x < 120) {
					this->sprite.move(.7,0);
				}
			}
			//cout << sprite.getPosition().x << "  " << sprite.getPosition().y << endl;
		}


};

class Bullet : public GameObject {
	public: 
		bool playerIsFire = false;
		Bullet(Texture& texture, int fired) : GameObject (texture, fired, 112) {}
		void update() {
			this->sprite.move(0,-1);
		}
};


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

	Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);

	Texture playerTexture;
	if (!playerTexture.loadFromFile("res/resource/player.png")) {
		return EXIT_FAILURE;
	}

	Texture bulletTexture;
	if (!bulletTexture.loadFromFile("res/resource/bullet.png")) {
		return EXIT_FAILURE;
	}

	Player defender (playerTexture);
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
								pew = new Bullet(bulletTexture, defender.sprite.getPosition().x + 3.5);
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
		if (pew) {
			pew->update();
			if (pew->sprite.getGlobalBounds().intersects(enemySprite.getGlobalBounds())) {
				delete pew;
				pew = nullptr;
			}
			else if (pew->sprite.getPosition().y <= -6) {
				delete pew;
				pew = nullptr;
			}
		}
		window.clear(Color::Black);
		if (pew) {
			pew->draw(window);
		}
		window.draw(enemySprite);
		defender.draw(window);
		window.display();
	}

	return EXIT_SUCCESS;
}
