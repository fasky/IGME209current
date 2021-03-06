// PE13.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Alien Theater

#include "stdafx.h"
#include <iostream>
#include <tchar.h>
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
	int numSeats = 0;
	cout << "Enter number of seats: ";
	cin >> numSeats;
	cout << "Iterative: " << numSeats << " seats contain " << handsCount(numSeats) << " hands." << endl;
	cout << "Recursive: " << numSeats << " seats contain " << handsRecursive(numSeats) << " hands." << endl;
	cout << "Formula: " << numSeats << " seats contain " << handsFormula(numSeats) << " hands." << endl;
	
	//performance	
	cout << "\nPerformance Evaluation\n Seats|Time" << endl;

	__int64 ctr1 = 0, ctr2 = 0, freq = 0;

	for (int i = 10; i <= 1000; i++) {
		if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0) {
			handsCount(i);
		}
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		cout << "-------------------\n"<<"I: " << i << " | " << ctr2 - ctr1 << endl;

		if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0) {
			handsRecursive(i);
		}
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		cout <<"R: " << i << " | " << ctr2 - ctr1 << endl;

		
		if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0) {
			handsFormula(i);
		}
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		cout << "F: "<< i << " | " << ctr2 - ctr1 << endl << "-------------------\n";
	}

    return 0;
}