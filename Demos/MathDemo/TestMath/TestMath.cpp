// TestMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int AddMe(int, int);
int SubMe(int, int);
__declspec(dllimport) int MulMe(int, int);

int main()
{
	int answer = AddMe(5, 8);
	printf("AddMe answer = %d\n", answer);

	int answerTwo = MulMe(5, 8);
	printf("MulMe answer = %d\n", answerTwo);
    return 0;
}

