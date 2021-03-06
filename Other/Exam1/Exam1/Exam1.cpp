// Exam1.cpp : Defines the entry point for the console application.
// Kyle Fasanella // Section 1 // Exam #1

#include "stdafx.h"
#include <iostream>
using namespace std;

//print out the average score of the scores passed in
void AverageScore(float* scores, int count) {
	double sum = 0;
	double average;

	for (int i = 0; i < count; i++) {
		sum += scores[i];
	}

	average = (sum / count);

	cout << "Average Score is " << average << endl;
}

//print out the highest score of the scores passed in
void HighScore(float* scores, int count) {
	int high = 0;

	for (int i = 0; i < count; i++) {
		if (high < scores[i]) {
			high = scores[i];
		}
	}

	cout << "High Score is " << high << endl;
}

//print out the lowest score of the scores passed in
void LowScore(float* scores, int count) {
	int low = 10000000000;

	for (int i = 0; i < count; i++) {
		if (low > scores[i]) {
			low = scores[i];
		}
	}

	cout << "Low Score is " << low << endl;
}

//get user input for scores, call score functions
int main()
{
	int num = -1;
	while (num < 1) {
		cout << "Enter the number of scores to use: ";
		cin >> num;
	}

	float * scores = new float[num];

	for (int i = 0; i < num; i++) {
		cout << "Enter a score: ";
		cin >> scores[i];
	}
	
	AverageScore(scores, num);
	HighScore(scores, num);
	LowScore(scores, num); 

	delete[] scores;

    return 0;
}

