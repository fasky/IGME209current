#pragma once
#include <Box2D\Box2D.h>

void update();

void display(b2Vec2 pos1, b2Vec2 pos2);

void applyForces(b2Body& snake, char strInput);

void moveTarget(float& xPos, float& yPos);

int main();