// main.cpp : Defines the entry point for the console application.
// Kyle Fasanella // Section 1 // Classes

#include "stdafx.h"


int main()
{
	//local on stack
	Player john = Player();

	//param stack
	Player mary = Player((char*)"Mary", 4, 20, 13);

	//heap default
	Player* steve = new Player();

	//heap param
	Player* stacy = new Player((char*)"Stacy",10,23,15);
	
	//print
	john.PrintPlayer();
	mary.PrintPlayer();
	steve->PrintPlayer();
	stacy->PrintPlayer();

	//fighters, stack and heap
	Fighter ryu = Fighter();
	Fighter* stu = new Fighter((char*)"Stu", 12, 8, 30, 14);

	ryu.printFighter();
	stu->printFighter();

	delete stu;
	delete steve;
	delete stacy;

	cout << endl;

    return 0;
}

