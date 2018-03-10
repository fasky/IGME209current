// GravitySnake.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / HW2 Gravity Snake

#include "stdafx.h"


int main()
{	
	//set up targets - ask for count
	setupTargets(10);

	//prepare window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Gravity Snake");
	window.setFramerateLimit(60);

	//setup targets and snake visuals
	sf::RectangleShape targetVisual(sf::Vector2f(50, 50));
	sf::CircleShape snakeVis(50);
	snakeVis.setFillColor(sf::Color(100, 200, 50));
	snakeVis.setPosition(400,0);

	//welcome and keys
	//cout << "Welcome to Gravity Snake!" << endl << "Use WASD to move." << endl;
	//A lot of code is made following helloworld.cpp for box2d
	//create world
	b2Vec2 gravity(0.0f, 19.6f);
	b2World world(gravity);
	b2World* worldP = &world;

	//Ground -----------------------------------
	//ground body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(400.0f, 580.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	//ground box
	b2PolygonShape ground;
	ground.SetAsBox(400.0f, 20.0f);
	groundBody->CreateFixture(&ground, 0.0f);
	//------------------------------------------

	//create snake
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(400.0f, 0.0f);
	snakeDef.angle = 0;
	b2Body* snake = world.CreateBody(&snakeDef);
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(50.0f, 50.0f);
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = 1.0f;
	snakeFixture.friction = 0.3f;
	snake->CreateFixture(&snakeFixture);

	//create target
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(currentLocation.x,currentLocation.y);
	targetDef.angle = 0;
	b2Body* target = world.CreateBody(&targetDef);
	b2PolygonShape targetBox;
	targetBox.SetAsBox(25.0f, 25.0f);
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.shape = &targetBox;
	targetFixtureDef.density = 1;
	target->CreateFixture(&targetFixtureDef);

	//for exiting while looping
	//char strInput;
	//bool run = true;

	//for checking collision
	double range = 1;
	int hitCount = 0;
	int score = 300;

	//sfml loop
	while (window.isOpen()) {
		//loop until ESC
		//while (run) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int32 i = 0; i < 60; ++i) {

			if (_kbhit()) {

				//strInput = _getch();

				//leave if user presses 'esc'
				//if (strInput == '\x1b') {
					//run = false;
					//break;
				//}

				//apply force if not esc and w,a,s,d
				//if (strInput == 'w' || strInput == 'a' || strInput == 's' || strInput == 'd') {
				score--;
				ProcessInput(*snake);
					//applyForces(*snake, strInput);
				//}
			}

			window.clear();
			update(*worldP);

			//get positions, pass into display later
			b2Vec2 position = snake->GetPosition();
			b2Vec2 targetPos = target->GetPosition();

			//collision and wrapping
			if ((targetPos.x - 25) < (position.x + 50 + range) && (targetPos.x + 25 + range) > (position.x - 50) && (targetPos.y - 25) < (position.y + 50 + range) && (targetPos.y + range + 25) > (position.y - 50)) {

				//printf("Target: %4.2f %4.2f --> Snake: %4.2f %4.2f (target hit)\n", targetPos.x, targetPos.y, position.x, position.y);

				//hitCount++;
				score += (50 * hitCount);
				/*if (hitCount == 2) {
					//run = false;
					//cout << "\nYou win!" << endl << "Score: " << score << endl << endl;
					window.close();
				}*/

				/*move target
				srand(time(NULL));
				b2Vec2 newPos(rand() % 751 + 25, rand() % 200 + 340);
				target->SetTransform(newPos, 0);*/

				//reset player pos
				b2Vec2 pos(400.0f, 0.0f);
				stopMoving(*snake);
				snake->SetTransform(pos, 0);
			}
			else {
				//show locations
				//display(targetPos, position);

				//reset player pos if at bottom
				if (position.y > 550) {
					reverseGravity(*worldP);
				}
				if(position.y < 0) {
					reverseGravity(*worldP);
				}
				if (position.x > 800) {
					b2Vec2 pos(0, position.y);
					snake->SetTransform(pos, 0);
				}
				if (position.x < 0) {
					b2Vec2 pos(800.0f, position.y);
					snake->SetTransform(pos, 0);
				}
			}

			targetVisual.setPosition(targetPos.x, targetPos.y);
			snakeVis.setPosition(position.x, position.y);

			window.draw(snakeVis);
			window.draw(targetVisual);
			window.display();
		}
		//}
	}

	//cout << "Game Over." << endl;
	//getch(); //it closes quickly if you hold down a key and hit the last target

	//null pointers
	groundBody = nullptr;
	snake = nullptr;
	target = nullptr;
	worldP = nullptr;

    return 0;
}

