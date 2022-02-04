#include <cstdlib>

#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
	sf::RenderWindow window(sf::VideoMode(128, 128), "Test");
	
	sf::Texture enemyTexture;
	enemyTexture.setSmooth(false);
	enemyTexture.setRepeated(false);
	if (!enemyTexture.loadFromFile("res/resource/enemy.png"))
	{
		return EXIT_FAILURE;
	}

	sf::Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);

	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		window.draw(enemySprite);

		window.display();
	}

	return EXIT_SUCCESS;
}
