#pragma once
#include <Box2D\Box2D.h>
#include "globals.h"

//declare functions

int main();

void processInput(b2Body& player);

void applyForceUp(b2Body& player);

void applyForceDown(b2Body& player);

void applyForceLeft(b2Body& player);

void applyForceRight(b2Body& player);

void stopMoving(b2Body& player);

void reverseGravity(b2World& world);

void setupTargets(int cnt, int windowW, int windowH);

bool selectNextTarget();