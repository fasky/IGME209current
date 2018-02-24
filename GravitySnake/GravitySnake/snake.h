#pragma once
#include <Box2D\Box2D.h>

void update();

void display();

void applyForces(b2Body& snake, char strInput);

void moveTarget(float& xPos, float& yPos);

int main();