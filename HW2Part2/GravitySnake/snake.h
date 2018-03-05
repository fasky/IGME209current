#pragma once
#include <Box2D\Box2D.h>
#include "globals.h"

//part 1
void update();

void display(b2Vec2 pos1, b2Vec2 pos2);

void applyForces(b2Body& snake, char strInput);

void moveTarget(float& xPos, float& yPos);

int main();

//part 2
void ProcessInput();

forcFunc applyForceUp;

forcFunc applyForceDown;

forcFunc applyForceLeft;

forcFunc applyForceRight;

forcFunc stopMoving;

void reverseGravity(b2World& world);

void setupTargets(int cnt);

bool selectNextTarget();