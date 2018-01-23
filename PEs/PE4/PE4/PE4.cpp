// PE4.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Strings

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char word[100] = "supercalifraglistic";

	cout << "Length: " << strlen(word) << "\n";

	char nextWord[15] = "expialidocious";

	strcat_s(word, "expialidocious");

	cout << "Full word: " << word << "\n";

	int count = 0;

	for (char letter : word) {
		if (letter == 'i') {
			count++;
		}
	}

	cout << "'i' count: " << count << "\n";

    return 0;
}