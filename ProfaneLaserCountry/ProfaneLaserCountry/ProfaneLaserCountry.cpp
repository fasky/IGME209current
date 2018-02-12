// ProfaneLaserCountry.cpp : Defines the entry point for the console application.
// Demo

#include "stdafx.h"

class Laser {
public:
	int power;
};

int main()
{
	Laser* farmer = new Laser;
	farmer[0].power = 101;
	farmer[1].power = 1000;
	farmer[2].power = 0;

	printf("farmer = %x %d\n", farmer, farmer->power);
	printf("before loop\n");
	Laser* temp = farmer;
	for (size_t i = 0; i < 5; i++) {
		printf("farmer = %x %d\n", temp, temp->power);
		temp++;
	}
	temp = 0;
	printf("after loop\n");
	printf("farmer = %x\n", farmer);

    return 0;
}

