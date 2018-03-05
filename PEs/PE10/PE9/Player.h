#pragma once

//player class declerations
class Player
{
public:
	Player();
	Player(char[100], int, int, int);
	void PrintPlayer();
	~Player();

private:
	char* namePlayer;
	int strength;
	int health;
	int stamina;
};

