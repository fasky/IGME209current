#pragma once
#include <Box2D\Box2D.h>

//globals
extern b2Vec2* targetLocations; //5 points

extern b2Vec2 currentLocation; //5 points

//Scores are high
extern int score;

//for moving through pointer array
extern int currentTarget;

typedef void(*forcFunc)(b2Body& player); //5 points