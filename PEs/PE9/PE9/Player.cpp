#include "stdafx.h"
#include "Player.h"

//functions for player class
//default
Player::Player() {
	strength = 10;
	health = 10;
	stamina = 10;
	namePlayer = (char*)"Unknown";
}

//parametrized
Player::Player(char name[100], int str, int hlth, int stmna)
{
	strength = str;
	health = hlth;
	stamina = stmna;
	namePlayer = (char*)name;
}

//print player info
void Player::PrintPlayer() {
	cout << "Name: " << namePlayer << "\nStrength: " << strength << "\nHealth: " << health << "\nStamina: " << stamina << endl << endl;
}

Player::~Player()
{

}
