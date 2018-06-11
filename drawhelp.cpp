#include "drawhelp.h"

void drawhelp::drawCircle(sf::RenderWindow& Window, int x, int y, int radius) {
 sf::CircleShape localCircle(radius/2); //Local circle object

 localCircle.setPosition(sf::Vector2f(x-radius/2,y-radius/2));
 localCircle.setFillColor(fillColor);
 
 Window.draw(localCircle);
}

void drawhelp::drawRect(sf::RenderWindow& Window, int x, int y, int width, int height) {
 sf::RectangleShape localRectangle(sf::Vector2f(width, height));

 localRectangle.setPosition(sf::Vector2f(x-width/2,y-height/2));
 localRectangle.setFillColor(fillColor);

 Window.draw(localRectangle);
}

void drawhelp::line(sf::RenderWindow& Window, int x1, int y1, int x2, int y2) {
 sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(x1, y1)),
    sf::Vertex(sf::Vector2f(x2, y2))
};

Window.draw(line, 2, sf::Lines);

}

void drawhelp::fill(sf::Color getFillColor) {
	fillColor = getFillColor;
}

void drawhelp::fill(int red, int green, int blue, int alpha) {
	fillColor = sf::Color(red,green,blue,alpha);
}

void drawhelp::stroke(int red, int green, int blue, int alpha) {
	strokeColor = sf::Color(red,green,blue,alpha);
}
