#include "stdafx.h"
#include "Item.h"

void Item::print() {
	cout << "Name: " << name << "\nDamage: " << damage << "\nWeight: " << weight << endl;
}

Item::Item(string nm, int dam, int wt)
{
	name = nm;
	damage = dam;
	weight = wt;
}


Item::~Item()
{

}
