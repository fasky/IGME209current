// Menu.cpp : Defines the entry point for the console application.
// Demo sec. 1 fasanella

#include "stdafx.h"
#include <iostream>
using namespace std;

void DisplayMenu() {
	cout << "Main Menu\n-_-_-_-_-_-_-_-_-_-\nS -> Start\nO -> Options\nQ -> Quit\n";
}

void Options() {
	cout << "you have no options" << endl;
}

void QuitGame() {
	cout << "Bye!" << endl;
	exit;
}

void StartGame() {
	cout << "Start Game" << endl;
}

void GetInput() {
	typedef void(*FunctionType)();
	FunctionType myFunction;

	char input;
	cin >> input;
	switch (input) {

	case 's':
	case 'S':
		myFunction = &StartGame;
		break;

	case 'Q':
	case 'q':
		myFunction = &QuitGame;
		break;

	case 'O':
	case 'o':
		myFunction = &Options;
		break;

	default:
		cout << "Bad input." << endl;
		break;
	}
	if (myFunction != nullptr) {
		(*myFunction)();
	}
}

int main()
{
	while (1 == 1) {
		DisplayMenu();
		GetInput();
	}

    return 0;
}

