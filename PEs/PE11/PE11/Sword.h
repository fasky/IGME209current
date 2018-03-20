#pragma once
#include "Item.h"
class Sword:public Item
{
public:
	Sword(string nm, int dam, int wt);
	~Sword();
};

