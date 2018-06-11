#ifndef DRAWHELP_H
#define DRAWHELP_H

#include <SFML/Graphics.hpp>

class drawhelp{

public:
	/* Basic shapes */
	void drawCircle(sf::RenderWindow& Window, int x, int y, int radius);
	void drawRect(sf::RenderWindow& Window, int x, int y, int width, int height);
	void line(sf::RenderWindow& Window, int x1, int y1, int x2, int y2);

	/* Colors */
	//void setColor(sf::RenderWindow& Window, int r, int g, int b);

	void fill(sf::Color getFillColor);
	void fill(int red, int green, int blue, int alpha);
	void stroke(int red, int green, int blue, int alpha);

private:
	sf::Color fillColor;
	sf::Color strokeColor;

};

#endif
