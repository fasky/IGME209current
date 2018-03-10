#pragma once
#include <Box2D\Box2D.h>
#include "globals.h"

//part 1
void update(b2World& world);

void display(b2Vec2 pos1, b2Vec2 pos2);

void applyForces(b2Body& snake, char strInput);

void moveTarget(float& xPos, float& yPos);

int main();

//part 2
void ProcessInput(b2Body& player);

void applyForceUp(b2Body& player);

void applyForceDown(b2Body& player);

void applyForceLeft(b2Body& player);

void applyForceRight(b2Body& player);

void stopMoving(b2Body& player);

void reverseGravity(b2World& world);

void setupTargets(int cnt);

bool selectNextTarget();