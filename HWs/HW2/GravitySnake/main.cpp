// GravitySnake.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / HW2 Gravity Snake
// The world updates when you press/hold a key - easier to play this way with text, 
// but will change it when visuals are working

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
	//create snake
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, 10.0f);
	snakeDef.angle = 0;
	b2Body* snake = world.CreateBody(&snakeDef);
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(.5f, .5f);
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = 1.0f;
	snakeFixture.friction = 0.3f;
	snake->CreateFixture(&snakeFixture);

	//create target
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(0.0f, -3.0f);
	targetDef.angle = 0;
	b2Body* target = world.CreateBody(&targetDef);
	b2PolygonShape targetBox;
	targetBox.SetAsBox(.02f, .02f);
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.shape = &targetBox;
	targetFixtureDef.density = 1;
	target->CreateFixture(&targetFixtureDef);

	//for exiting while looping
	char strInput;
	bool run = true;

	//time steps and iterations for simulating
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	//for checking collision
	double range = .03;
	int hitCount = 0;
	int score = 300;

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
					score--;
					applyForces(*snake, strInput);
				}

				//update(); ?
				world.Step(timeStep, velocityIterations, positionIterations);

				//get positions, pass into display
				b2Vec2 position = snake->GetPosition();
				b2Vec2 targetPos = target->GetPosition();

				if ((targetPos.x - .02) < (position.x + .5 + range) && (targetPos.x + .02 + range) > (position.x - .5) && (targetPos.y - .02) < (position.y + .5 + range) && (targetPos.y + range + .02) > (position.y - .5)) {
					
					printf("Target: %4.2f %4.2f --> Snake: %4.2f %4.2f (target hit)\n", targetPos.x, targetPos.y, position.x, position.y);

					hitCount++;
					score += (50 * hitCount);
					if (hitCount == 2) {
						run = false;
						cout << "\nYou win!" << endl << "Score: " << score << endl << endl;
					}

					//moveTarget(); ?
					srand(time(NULL));
					b2Vec2 newPos(rand() % 11 - 5, rand() % 11 - 5);
					target->SetTransform(newPos,0);

					//reset player pos
					b2Vec2 pos(0.0f, 10.0f);
					b2Vec2 newVel(0.0f, 0.0f);
					snake->SetLinearVelocity(newVel);
					snake->SetTransform(pos, 0);					
				}
				else {
					//show locations
					display(targetPos, position);

					//reset player pos if at bottom
					if (position.y < -5) {
						b2Vec2 pos(0.0f, 10.0f);
						b2Vec2 newVel(0.0f, 0.0f);
						snake->SetLinearVelocity(newVel);
						snake->SetTransform(pos, 0);
					}
					if (position.x > 5) {
						b2Vec2 pos(-5.0f, position.y);
						snake->SetTransform(pos, 0);
					}
					if (position.x < -5) {
						b2Vec2 pos(5.0f, position.y);
						snake->SetTransform(pos, 0);
					}
				}

			}
		}
	}

	cout << "Game Over." << endl;
	_getch(); //it closes quickly if you hold down a key and hit the last target

	//null pointers
	groundBody = nullptr;
	snake = nullptr;
	target = nullptr;

    return 0;
}

