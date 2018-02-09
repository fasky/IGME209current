// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << "Adresses\nBoss: " << boss << "\nPlayer: " << pOne << "\nFake Monster:" << fakeMonster << endl;

	//set values
	boss->xPos = 100;
	boss->yPos = 200;
	//boss->damage = 30; //if using MovableObject, cant set damage or name since they don't exist in MovableObject
	//pOne->name = "Catman"; Can't set name of player, MovableObject doesn't have variable 
	pOne->yPos = 300;
	fakeMonster->damage = 10; 	//but you can set the fakeMonster's damage. (Monster*)pOne makes it so fakemonster points to pOne values and also has damage variable, but pOne does not have a damage variable
	fakeMonster->xPos = 400;

	// print pos
	cout << "Positions\nBoss: ";
	boss->PrintPos();
	cout << "Player: ";
	pOne->PrintPos();
	cout << "Fake Monster: ";
	fakeMonster->PrintPos();
	cout<< "Fake Monster Damage: " << fakeMonster->damage << endl;

	delete boss;
	delete pOne; //delete the pointer
	fakeMonster = nullptr; //dangling pointer? set to nullptr since what pOne points to is deleted


	_getch();
    return 0;
}

