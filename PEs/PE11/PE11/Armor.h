#pragma once
#include "Item.h"

class Armor:public Item
{
public:
	Armor(string nm, int dam, int wt);
	~Armor();
};

