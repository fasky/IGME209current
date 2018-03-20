#pragma once
#include "Item.h"
class Helmet:public Item
{
public:
	Helmet(string nm, int dam, int wt);
	~Helmet();
};

