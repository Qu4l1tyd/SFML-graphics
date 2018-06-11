#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawhelp.h"
#include "pong.h"

int main() {
	/* Custom helper function */
	drawhelp dhelp;

	/* Pong game */
	pong pongGame(512,512);
	
	/* Setup the window */
	sf::RenderWindow window(sf::VideoMode(512,512), "C++ works!", sf::Style::Close	|	sf::Style::Titlebar);

	/* Set framerate limit */
	window.setFramerateLimit(60);

	sf::Texture texture;
	sf::Sprite sprite;
	
	/* If there is error with loading the texture */
	if(!texture.loadFromFile("image.jpg")) {
		std::cout<<"File error!\n";
		return 0;
	}

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(10,50)); //move to 10,50

	/* Initalization done, move to game loop */

	sf::Clock clock;
	while(window.isOpen()) {
		sf::Time elapsed = clock.restart();

		sf::Event evnt; //this is the eventhandler
		while(window.pollEvent(evnt)) {
			if(evnt.type == evnt.Closed) {
				window.close();
			}
		}

		pongGame.run(window);

		// If escape was pressed
		 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		  window.close();
		 }
	}
return 0;
}
