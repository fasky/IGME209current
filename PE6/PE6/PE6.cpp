// PE6.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Debugging

#include "stdafx.h"

int main()
{
	int a;
	char* b = 0;

	cout << "How many random numbers would you like to generate?: ";
	cin >> a;
	cout << "\n";
	generateRandom(a);

	cout << "\nPlease enter a string: ";
	cin >> b; //if char* b, *_Str wasnullptr
	char* word = reverseString(b);
	cout << "\n";

	cout << "\nReversed: " << word << "\n";

    return 0;
}
