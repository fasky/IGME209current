// GravitySnake.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / HW2 Gravity Snake

#include "stdafx.h"


int main()
{
	//welcome and keys
	cout << "Welcome to Gravity Snake!" << endl << "Use WASD to move." << endl;

	//A lot of code is made following helloworld.cpp for box2d
	//create world
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);

	//Ground -----------------------------------
	//ground body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -16.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	//ground box
	b2PolygonShape ground;
	ground.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&ground, 0.0f);

	//------------------------------------------
	//create snake body
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(6.0f, 6.0f);
	snakeDef.angle = 0;
	b2Body* snake = world.CreateBody(&snakeDef);
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = 1.0f;
	snakeFixture.friction = 0.3f;
	snake->CreateFixture(&snakeFixture);

	//create target
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(3.0f, -3.0f);
	b2Body* target = world.CreateBody(&targetDef);
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.shape = &snakeBox;
	targetFixtureDef.density = 1;
	target->CreateFixture(&targetFixtureDef);

	//time steps and iterations for simulating
	//update();?
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	//for exiting while looping
	char strInput;
	bool run = true;

	//loop until ESC
	while (run) {
		for (int32 i = 0; i < 60; ++i) {
			if (_kbhit()) {

				strInput = _getch();

				//leave if user presses 'esc'
				if (strInput == '\x1b') {
					run = false;
					break;
				}

				//apply force if not esc and w,a,s,d
				if (strInput == 'w' || strInput == 'a' || strInput == 's' || strInput == 'd') {
					applyForces(*snake, strInput);
				}

				//update(); ?
				world.Step(timeStep, velocityIterations, positionIterations);

				//display(); ?
				b2Vec2 position = snake->GetPosition();
				b2Vec2 targetPos = target->GetPosition();
				printf("Target: %4.2f %4.2f --> Snake: %4.2f %4.2f\n",targetPos.x, targetPos.y, position.x, position.y);
			}
		}
	}

	//null pointers
	groundBody = nullptr;
	snake = nullptr;
	target = nullptr;

    return 0;
}

