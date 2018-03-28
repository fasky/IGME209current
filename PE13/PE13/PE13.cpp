// PE13.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Alien Theater

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

//iterative
int handsCount(int seats) {
	int hands = 0;
	for (int i = 1; i <= seats; i++) {
		if ((i % 2) == 0) {
			hands += 4;
		}
		else {
			hands += 3;
		}
	}

	return hands;
}

//recursion
int handsRecursive(int seats) {

	int hands = 0;

	//if even, add 4, if odd, 3
	if ((seats % 2) == 0) {
		hands += 4;
	}
	else {
		hands += 3;
	}

	//check if there are more seats
	if (seats > 1) {
		seats--;
		hands += handsRecursive(seats);
	}

	return hands;
}

//formula
int handsFormula(int seats) {
	return (seats * 3) + (seats / 2);
}

int main()
{
	/*LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) {
		cout << "QueryPerformanceFrequencyFailed\n";
	}
	QueryPerformanceCounter(&li);
	_int64 counterStart = li.QuadPart;*/

	

	int numSeats = 0;
	cout << "Enter number of seats: ";
	cin >> numSeats;
	cout << "Iterative: " << numSeats << " seats contain " << handsCount(numSeats) << " hands." << endl;
	cout << "Recursive: " << numSeats << " seats contain " << handsRecursive(numSeats) << " hands." << endl;
	cout << "Formula: " << numSeats << " seats contain " << handsFormula(numSeats) << " hands." << endl;
	
	/*performance in ticks		
	cout << "\nSeats Time" << endl;
	for (int i = 10; i <= 1000; i++) {
		DWORD value1 = GetTickCount();
		handsCount(i);
		DWORD value2 = GetTickCount();
		cout << i << "  " << (value2) << endl;
		value1 = GetTickCount();
		handsRecursive(i);
		value2 = GetTickCount();
		cout << i << "  " << (value2) << endl;
		value1 = GetTickCount();
		handsFormula(i);
		value2 = GetTickCount();
		cout << i << "  " << (value2) << endl;
	}*/

    return 0;
}