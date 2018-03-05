#include "stdafx.h"

//Part 1
//changes the variable locally - in the function - not affecting the one in main.
void changeVariable(int a)
{
	a = a + 1;
	cout << "Inside changeVariable: Variable's value is now: " << a << endl;
}

//changes the variable at its address - affects one in main.
void changePointer(int *a)
{
	*a = *a + 1;
	cout << "Inside changePointer: Variable's value is now: " << *a << endl;
}

//Part 2
int getLengthArray(int a[])
{
	int count = 0;
	int current = 0;

	while (current != -1) {
		current = a[count];
		count++;
	}

	return count;
}

int getLengthPointer(int *a)
{
	int count = 0;
	a--; //start at one before so it counts right

	while (*a != -1) 
	{
		a++;
		count++;
	}

	return count;
}

//Part 3
int* createStackArray()
{
	int index[5] = { 0,1,2,3,4 };

	return index;
}

int* createHeapArray(int a)
{
	int *indices = new int[a];

	for (int b = 0; b < a; b++) {
		indices[b] = b;
	}

	return indices;
}
