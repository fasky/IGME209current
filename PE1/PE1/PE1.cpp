// PE1.cpp : Defines the entry point for the console application.
// Kyle Fasanella - Hello World! - Section 1

#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "Hello World!\n";

	int number = 31*24*60;
	double decimal = 6.2 * 6.2 * 3.14;

	std::cout << "Minutes in Dec.: " << number << "\nArea of circle with rad 6.2: " << decimal << "\n";

	int divide = 12 / 10;
	int divideTwo = 10 / 12;

	//1 and 0, it rounds down, no double

	std::cout << divide << " and " << divideTwo << "\n";

	//%d vs %f(floats doubles)
	printf("The answer is %d and %d\n", divide, divideTwo);
	printf("Area of circle, rad 6.2: %f\n", decimal);

    return 0;
}