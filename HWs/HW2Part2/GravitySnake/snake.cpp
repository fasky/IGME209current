//snake functions from header
#include "stdafx.h"

/////////Part 1
void update(b2World& world) {

	//time steps and iterations for simulating
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	//step
	world.Step(timeStep, velocityIterations, positionIterations);
}

//display position of target and player
void display(b2Vec2 targetPos, b2Vec2 position) {
	printf("Target: %4.2f %4.2f --> Snake: %4.2f %4.2f\n", targetPos.x, targetPos.y, position.x, position.y);
}

//apply force to snake
void applyForces(b2Body& snake, char strInput) {
	switch (strInput) {
		case 'w':
			snake.ApplyForceToCenter(b2Vec2(0,-8.0f),true);
			break;
		case 'a':
			snake.ApplyForceToCenter(b2Vec2(-10, 0), true);
			break;
		case 's':
			snake.ApplyForceToCenter(b2Vec2(0, 10), true);
			break;
		case 'd':
			snake.ApplyForceToCenter(b2Vec2(10, 0), true);
			break;
		default:
			break;
	}
}

///////Part 2
void ProcessInput(b2Body& player) {
	forcFunc applied = nullptr;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		applied = &applyForceUp;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		applied = &applyForceLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		applied = &applyForceDown;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		applied = &applyForceRight;
	}
	if (applied != nullptr) {
		applied(player);
	}

	applied = nullptr;
}

void applyForceUp(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0, -9.0f), true);
}

void applyForceDown(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0, 100), true);
}

void applyForceLeft(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(-300, 0), true);
}

void applyForceRight(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(300, 0), true);
}

void stopMoving(b2Body& player) {
	b2Vec2 newVel(0.0f, 0.0f);
	player.SetLinearVelocity(newVel);
}

void reverseGravity(b2World& world) {
	world.SetGravity(-(world.GetGravity()));
}

//get count from user, set up random targets
void setupTargets(int cnt) {
	int count = 0;
	cout << "How many targets? (1 - 10): ";
	while (count < 1 || count > cnt) {
		cin >> count;
		if (count < 1 || count > cnt) {
			cout << "\nPlease enter a suitable number (1 - 10): " << endl;
		}
	}

	targetLocations = new b2Vec2[count + 1];

	for (int i = 0; i < (count + 1); i++) {
		srand(time(NULL));
		b2Vec2 newPos(rand() % 751 + 25, rand() % 200 + 340);
		targetLocations[i] = newPos;

		if (i == count) {
			b2Vec2 pos(-1000,-1000);
			targetLocations[i] = pos;
		}
	}

	currentLocation = *targetLocations;
	
}

bool selectNextTarget() {

	currentLocation = *++targetLocations;

	return true;
}