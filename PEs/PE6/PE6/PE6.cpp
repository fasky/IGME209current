// PE6.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Debugging

#include "stdafx.h"

int main()
{
	int a;
	char* b = new char;

	cout << "How many random numbers would you like to generate?: ";
	cin >> a;
	cout << "\n";
	generateRandom(a);

	cout << "\nPlease enter a string: ";
	cin >> b;
	//char* word = reverseString(b);
	cout << "\n";

	cout << "\nReversed: " << reverseString(b) << "\n";

    return 0; 
	//Exception thrown at 0x00007FF89592E680 (ntdll.dll) in PE6.exe: 0xC0000005: Access violation reading location 0xFFFFFFFFFFFFFFFF. pointer problem
	//among other errors when trying to fix it
}
