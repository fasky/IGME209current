// ManicHoedownUncensored.cpp : Defines the entry point for the console application.
// Kyle fasanella / Section 1 / Demo 2

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char song1[24] = "Ding Dong Noodley Swift";
	cout << strlen(song1) << endl;
	char buffer[30];

	strcpy(buffer, song1);

    return 0;
}

