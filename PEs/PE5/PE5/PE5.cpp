// PE5.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Playing with Windows

#include "stdafx.h"
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
	//create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

	while (window.isOpen()) {

		//check window events are triggered
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//make it black
		window.clear(sf::Color::Black);

		//draw stuff
		sf::CircleShape shape(50);
		shape.setFillColor(sf::Color(100, 100, 20));
		window.draw(shape);

		sf::CircleShape triangle(50,3);
		triangle.setFillColor(sf::Color(100, 30, 20));
		triangle.setPosition(sf::Vector2f(400,300));
		window.draw(triangle);

		sf::RectangleShape rectangle(sf::Vector2f(200, 30));
		rectangle.setFillColor(sf::Color(10, 100, 20));
		rectangle.setPosition(sf::Vector2f(100,100));
		window.draw(rectangle);

		//end frame
		window.display();
	}

    return 0;
}

