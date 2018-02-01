#include "stdafx.h"

void generateRandom(int numberOfRandoms) {
	
	//seed
	srand(NULL);

	//generate and print
	for (int i = 0; i < numberOfRandoms; i++) {
		
		cout << "#" << i + 1 << ":" << rand() << "\n";

	}

	cout << "\n";
}

char* reverseString(char* inputString)
{
	char newString[256] = "";
	int len = strlen(inputString); //access violation
	for (int i = 0; i < len; i++)
	{
		char c = inputString[i];
		newString[len - i] = c;
	}
	strcpy_s(inputString, 128, (const char*)&newString);
	return inputString;
}