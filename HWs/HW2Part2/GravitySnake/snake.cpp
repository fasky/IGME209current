//snake functions from header
#include "stdafx.h"

/////////Part 1
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

//move the target
void moveTarget(float& xPos, float& yPos) {
	//nothing here
}

///////Part 2
void ProcessInput() {

}

/*forcFunc applyForceUp;

forcFunc applyForceDown;

forcFunc applyForceLeft;

forcFunc applyForceRight;

void stopMoving(b2Body& player) {
	b2Vec2 newVel(0.0f, 0.0f);
	player.SetLinearVelocity(newVel);
}*/

void reverseGravity(b2World& world) {

}

void setupTargets(int cnt) {

}

bool selectNextTarget() {
	return false;
}