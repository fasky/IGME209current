#include "stdafx.h"
#include "Fighter.h"

//methods
//default
Fighter::Fighter()
{
	weaponSkill = 5;
}

//param
Fighter::Fighter(char name[100], int wpn, int str, int hlt, int stm) : Player(name, str, hlt, stm)
{
	weaponSkill = wpn;
}

//decon
Fighter::~Fighter()
{
}

//print
void Fighter::printFighter()
{
	PrintPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}
