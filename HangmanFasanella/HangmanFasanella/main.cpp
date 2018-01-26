// HangmanFasanella.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Hangman

#include "stdafx.h"

int main()
{
	//create strings
	char word[10] = "neolithic";
	char correct[10] = "";
	char wrong[27] = "";
	int guesses = 6;

	cout << "Welcome to Hangman!\nYour word has " << strlen(word) << " letters in it.\n";

	while (guesses > 0) 
	{
		char l[2];
		bool good = false;
		cout << "\nGuess a letter: ";
		cin >> l;
		cout << "Guess: " << l << endl;

		for (char a : word) {
			if (a == (char)l) {
				cout << "\nGood!\n";
				good = true;
			}
		}

		if (good == false) {
			guesses--;
			strcat_s(wrong, l);
		}

		showGallows(guesses);

		cout << "\nWrong guesses: \n" << wrong;

		showSolved(word, correct);
	}

	return 0;
}

