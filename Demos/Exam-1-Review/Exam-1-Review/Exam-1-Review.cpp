// Exam-1-Review.cpp : Defines the entry point for the console application.
// Kyle F Section 1 Review

#include "stdafx.h"
#include <iostream>
using namespace std;

//address
void function1(int& x) {

}

//pointer
int function2(int* x) {
	return 0;
}

int main()
{
	int *h = new int; //not made with brackets, don't need to delete with delete[] but just delete
	*h = 9;
	int g = 5;
	function1(*h);
	function2(&g);
	function2(h);
	function2(&*h);

	g = 3;
	cout << "++ testing\n";
	cout << g++ << endl;
	cout << ++g << endl;

	int* temp = h;
	cout << temp << endl;
	cout << ++temp << endl;

	delete h;
    return 0;
}

