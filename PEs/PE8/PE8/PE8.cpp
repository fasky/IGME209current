// PE8.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / More Pointers

#include "stdafx.h"


int main()
{
	//part 1
	int num = 10;
	cout << "Variable: " << num << endl;
	changeVariable(num);
	cout << "Variable: " << num << endl;
	changePointer(&num);
	cout << "Variable: " << num << endl;

	//part 2
	int numbers[8] = { 1,2,3,4,5,6,7,-1 };
	int * p = numbers;
	cout << "Result of getArrayLength: " << getLengthArray(p) << endl;
	cout << "Result of getLengthPointer: " << getLengthPointer(numbers) << endl;

	//part 3
	int* stackArray = createStackArray();
	int* heapArray = createHeapArray(5);

	cout << "Result of createStackArray: " << stackArray[0] << endl;
	cout << "Result of createHeapArray: " << heapArray[0] << ", "<< heapArray[1] << ", " << heapArray[2] << ", " << heapArray[3] << ", " << heapArray[4] << endl;

	delete[] heapArray;

	//The array on the stack seems to not be saved or carried over into main. The one on the heap is and I can print the values assigned in createHeapArray.
	//Maybe because it doesn't save to global memory and is lost when the function ends.

    return 0;
}

