#pragma once
#include "Player.h"
//fighter class

class Fighter : public Player
{
public:
	//methods
	Fighter();
	Fighter(char name[100], int wpn, int str, int hlt, int stm);
	~Fighter();
	void printFighter();

	//vars
	int weaponSkill;
};

