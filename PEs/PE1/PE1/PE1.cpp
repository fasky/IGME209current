// PE1.cpp : Defines the entry point for the console application.
// Kyle Fasanella - Hello World! - Section 1

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	std::cout << "Hello World, I'm testing branching.\n";

	int number = 31*24*60;
	double decimal = 6.2 * 6.2 * 3.14;

	std::cout << "Minutes in Dec.: " << number << "\nArea of circle with rad 6.2: " << decimal << "\n";

	int uneeded = -100;
	int dog = 0;
	int animal = 2;

	//1 and 0, it rounds down, no double

	std::cout << "Testing" << endl;

	//%d vs %f(floats doubles)
	printf("Area of circle, rad 6.2: %f\n", decimal);

	int name = 1000;

    return 0;
}
void other() {
	std::cout << "test" << std::endl;
}