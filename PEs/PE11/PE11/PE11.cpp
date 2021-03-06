// PE11.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Structs-Inheritance

#include "stdafx.h"
#include "Armor.h"
#include "Shield.h"
#include "Sword.h"
#include "Helmet.h"
#include <vector>

int main()
{
	Item * armor = new Armor("Armor",0,20);
	Item * shield = new Shield("Shield",5,10);
	Item * sword = new Sword("Sword",20,5);
	Item * helmet = new Helmet("Helmet",0,5);

	vector<Item*> inventory;
	inventory.push_back(armor);
	inventory.push_back(shield);
	inventory.push_back(sword);
	inventory.push_back(helmet);

	for (int i = 0; i < inventory.size(); i++) {
		inventory[i]->print();
	}

	delete armor;
	delete shield;
	delete helmet;
	delete sword;

    return 0;
}

