#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BaddieGroup.hpp"
#include "Hud.hpp"
#include "gameObj/Player.hpp"
#include "gameObj/Baddie.hpp"
#include "gameObj/PlayerBullet.hpp"
#include "gameObj/BaddieBullet.hpp"
#include "gameStates/GamePlayState.hpp"
using namespace sf;
using namespace std;

RenderWindow window;
View kamera;
RectangleShape background;

GamePlayState* gameplay = nullptr;

BaddieGroup* killemAll = nullptr;



int init() {
	/* a try catch will run the first function and catches a RUNTIME ERROR
	
	*/
	try {
		resources::loadResources();
	} catch (runtime_error e) {
		return EXIT_FAILURE;
	}

	gameplay = new GamePlayState();

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
	gameplay->update(window);
}

void draw() {
	window.clear(Color(0x000022ff)); //The background of the game when in fullscreen
	window.draw(background);
	gameplay->draw(window);
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

			default:
				gameplay->processInput(currentEvent);
				break;
			}

		}

		update();
		draw();
	}
	delete gameplay;
	return EXIT_SUCCESS;
}
