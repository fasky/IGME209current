// GravitySnake.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / HW3 Graphical Snake

#include "stdafx.h"

int main()
{	

	//Some values for snake/target props, window
	const int SNAKE_SIZE = 24;
	const int TAR_SIZE = 10;
	const int WINDOW_H = 800;
	const int WINDOW_W = 700;

	//begin
	cout << "Welcome to Graphical Snake! WASD to move." << endl;
	bool run = true; //for if -1000, -1000 target is reached
	setupTargets(100, WINDOW_W,WINDOW_H); //get user input, 1 to 10 targets

	//sfml window
	sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Graphical Snake");
	window.setFramerateLimit(60);

	//setup snake and world
	//create world box2d
	b2Vec2 gravity(0.0f, 9.8f); //initial gravity
	b2World world(gravity);
	b2World* worldP = &world;

	//create snake box2d
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(WINDOW_W/2, 0.0f);
	snakeDef.angle = 0;
	b2Body* snake = world.CreateBody(&snakeDef);
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(SNAKE_SIZE, SNAKE_SIZE);
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = .3f;
	snakeFixture.friction = 0.3f;
	snake->CreateFixture(&snakeFixture);

	//create target for collisions box2d
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	//targetDef.position.Set(currentLocation.x, currentLocation.y);
	targetDef.angle = 0;
	b2Body* target = world.CreateBody(&targetDef);
	b2PolygonShape targetBox;
	targetBox.SetAsBox(TAR_SIZE, TAR_SIZE);
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.shape = &targetBox;
	targetFixtureDef.density = 1;
	target->CreateFixture(&targetFixtureDef);

	//setup targets and snake visuals
	sf::RectangleShape targetVisual(sf::Vector2f(TAR_SIZE*2, TAR_SIZE*2));
	targetVisual.setOrigin(TAR_SIZE, TAR_SIZE);
	sf::CircleShape snakeVis(SNAKE_SIZE);
	snakeVis.setOrigin(SNAKE_SIZE, SNAKE_SIZE);
	snakeVis.setFillColor(sf::Color(100, 200, 50));
	snakeVis.setPosition(WINDOW_W/2, 0);
	targetVisual.setFillColor(sf::Color(230, 0, 230));

	//range for coll
	double range = 1.0;

	//loop
	while (window.isOpen() && run)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int32 i = 0; i < 60; ++i) {

			window.clear();
			processInput(*snake);

			//step - update
			world.Step(1.0f/60.0f, 6, 2);

			//get positions, pass into display later
			b2Vec2 position = snake->GetPosition();
			b2Vec2 targetPos = currentLocation;


			//collision and wrapping
			if ((targetPos.x - TAR_SIZE) < (position.x + SNAKE_SIZE + range) && (targetPos.x + TAR_SIZE + range) > (position.x - SNAKE_SIZE) && (targetPos.y - TAR_SIZE) < (position.y + SNAKE_SIZE + range) && (targetPos.y + range + TAR_SIZE) > (position.y - SNAKE_SIZE)) {

				run = selectNextTarget();
				targetVisual.setPosition(currentLocation.x, currentLocation.y);
				score += 500;
			}
			else {
				//reverse gravity when top or bottom is hit, wrap player on sides
				if (position.y > WINDOW_H && world.GetGravity() == b2Vec2(0,9.8)) {
					reverseGravity(*worldP);
					stopMoving(*snake);
				}
				if (position.y < 0 && world.GetGravity() == b2Vec2(0, -9.8)) {
					reverseGravity(*worldP);
					stopMoving(*snake);
				}
				if (position.x > WINDOW_W) {
					b2Vec2 pos(0, position.y);
					snake->SetTransform(pos, 0);
				}
				if (position.x < 0) {
					b2Vec2 pos(WINDOW_W, position.y);
					snake->SetTransform(pos, 0);
				}
			}

			//set visual positions
			targetVisual.setPosition(targetPos.x, targetPos.y);
			snakeVis.setPosition(position.x, position.y);

			//draw
			window.draw(snakeVis);
			window.draw(targetVisual);
			window.display();
		}
	}
	
	window.close();

	cout << "Score: " << score << "\nPress any key to continue." << endl;

	//null pointers, delete, etc.
	snake = nullptr;
	target = nullptr;
	worldP = nullptr;
	currentLocation = b2Vec2(0, 0);
	delete[] targetLocations;
	targetLocations = NULL;

	_getch();

	//end
    return 0;
}

