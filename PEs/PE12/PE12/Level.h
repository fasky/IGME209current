#pragma once
class Level
{
public:
	int levelNum;
	int startX;
	int startY;
	char treasureID[];

	Level();
	~Level();
};

