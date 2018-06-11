#ifndef PONG_H
#define PONG_H

#include <SFML/Graphics.hpp>
#include "drawhelp.h"

extern drawhelp pdhelp;

class pong{

public:
	pong();
	pong(int getWidth, int getHeigth);

	void run(sf::RenderWindow& Window);

private:
	void draw();
	void input();
	void resetGame();
	void logic();
	sf::Clock clock;
	sf::Time elapsed;

	/* Game variables */
	bool gameOver = false;

	int leftPaddleY = 150;
	int rightPaddleY = 150;
	float paddleSpeed = 0.2;
	float ballSpeed = 0.3;

	float getElapsedTime = 1;

	int ballX = 40;
	int ballY = 150;

	float dirX = 1;
	float dirY = 1;

	/* Keyboard variables */
	bool keyUp = false;
	bool keyDown = false;
	bool keyLeft = false;
	bool keyRight = false;
	bool keyExit = false;

	bool keyW = false;
	bool keyS = false;

	/* Screen variables */
	int pongWindowWidth = 512;
	int pongWindowHeigth = 512;
};

#endif
