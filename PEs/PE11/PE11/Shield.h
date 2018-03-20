#pragma once
#include "Item.h"
class Shield:public Item
{
public:
	Shield(string nm, int dam, int wt);
	~Shield();
};

