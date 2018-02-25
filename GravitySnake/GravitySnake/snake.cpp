//snake functions from header
#include "stdafx.h"

void update() {
	//nothing here
}

//display position of target and player
void display(b2Vec2 targetPos, b2Vec2 position) {
	printf("Target: %4.2f %4.2f --> Snake: %4.2f %4.2f\n", targetPos.x, targetPos.y, position.x, position.y);
}

//apply force to snake
void applyForces(b2Body& snake, char strInput) {
	switch (strInput) {
		case 'w':
			snake.ApplyForceToCenter(b2Vec2(0,9.5f),true);
			break;
		case 'a':
			snake.ApplyForceToCenter(b2Vec2(-5, 0), true);
			break;
		case 's':
			snake.ApplyForceToCenter(b2Vec2(0, -10), true);
			break;
		case 'd':
			snake.ApplyForceToCenter(b2Vec2(5, 0), true);
			break;
		default:
			break;
	}
}

//move the target
void moveTarget(float& xPos, float& yPos) {
	//nothing here
}