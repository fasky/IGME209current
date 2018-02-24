//snake functions from header
#include "stdafx.h"

//update the physics world
void update() {

}

//display position of target and player
void display() {

}

//apply force to snake
void applyForces(b2Body& snake, char strInput) {
	switch (strInput) {
		case 'w':
			snake.ApplyForceToCenter(b2Vec2(0,10),true);
			break;
		case 'a':
			snake.ApplyForceToCenter(b2Vec2(-10, 0), true);
			break;
		case 's':
			snake.ApplyForceToCenter(b2Vec2(0, -10), true);
			break;
		case 'd':
			snake.ApplyForceToCenter(b2Vec2(10, 0), true);
			break;
		default:
			break;
	}
}

//move the target
void moveTarget(float& xPos, float& yPos) {

}