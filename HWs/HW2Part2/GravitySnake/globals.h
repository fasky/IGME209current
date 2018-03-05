#pragma once
#include <Box2D\Box2D.h>

//globals
extern b2Vec2* targetLocations;

extern b2Vec2 currentLocation;

typedef void(*forcFunc)(b2Body& player);