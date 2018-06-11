#include "pong.h"

/**********************************************************/

pong::pong() {
	pongWindowWidth = 128;
	pongWindowHeigth = 128;
}

pong::pong(int getWidth, int getHeigth) {
	pongWindowWidth = getWidth;
	pongWindowHeigth = getHeigth;
}

void pong::run(sf::RenderWindow& Window)  {

elapsed = clock.restart();

Window.clear(); //clear window

input();

//draw left paddle
pdhelp.fill(255,255,255,255);
pdhelp.drawRect(Window,10,leftPaddleY,20,100);

//draw right paddle
pdhelp.fill(255,255,255,255);
pdhelp.drawRect(Window,512-10,rightPaddleY,20,100);

pdhelp.drawRect(Window,ballX,ballY,20,20);

Window.display(); //push the buffer to the window

logic(); //DO LOGIC HERE

/* If game is over */
while(gameOver) {
	sf::sleep(sf::milliseconds(500));	
	gameOver = false;
	//Reset variables
	resetGame();
}

}

/**********************************************************/

void pong::resetGame() {

ballX = 40;
ballY = 150;

dirX = 1;
dirY = 1;

leftPaddleY = 150;
rightPaddleY = 150;

}

/**********************************************************/

void pong::input() {
 /* Map keyboard to the variables */
 keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
 keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
 keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
 keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
 keyExit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

 keyW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
 keyS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

/**********************************************************/

void pong::logic() {
 int timeInSeconds = elapsed.asMilliseconds();

 /* LEFT PADDLE */

 /* if moving up */
 if(keyW) {
  if(leftPaddleY>50) {
   leftPaddleY-=paddleSpeed*timeInSeconds;
  }else{
   leftPaddleY=50;
  }
 }

 /* if moving down */
 if(keyS) {
  if(leftPaddleY<462) {
   leftPaddleY+=paddleSpeed*timeInSeconds;
  }
 }

 /* RIGHT PADDLE */

 /* if moving up */
 if(keyUp) {
  if(rightPaddleY>50) {
   rightPaddleY-=paddleSpeed*timeInSeconds;
  }else{
   rightPaddleY=50;
  }
 }

 /* if moving down */
 if(keyDown) {
  if(rightPaddleY<462) {
   rightPaddleY+=paddleSpeed*timeInSeconds;
  }
 }

 ballX += dirX*ballSpeed*timeInSeconds;
 ballY += dirY*ballSpeed*timeInSeconds;

 if(ballX > pongWindowWidth-30)
 {
  dirX = -1+(rand()%100)/100;
 }
 if(ballX < 30) {
  if((ballY+10>=leftPaddleY-50) && (ballY-10<=leftPaddleY+50)) {
  	dirX = 1-(rand()%100)/100;
  }else{
	gameOver = true;
  }
 }
 if(ballY > pongWindowHeigth-10) {
  dirY = -1+(rand()%100)/100;
 }
 if(ballY < 30) {
  dirY = 1-(rand()%100)/100;
 }
}
