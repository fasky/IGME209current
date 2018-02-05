// HangmanFasanella.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Hangman

#include "stdafx.h"

int main()
{
	//create strings
	char word[10] = "neolithic";
	char correct[10] = "";
	char wrong[27] = "";
	int guesses = 7;

	cout << "Welcome to Hangman!\nYour word has " << strlen(word) << " letters in it.\n";

	while (guesses > 0) 
	{
		char l[2];
		bool good = false;
		cout << "\nGuess a letter: ";
		cin >> l;
		cout << "Guess: " << l << endl;

		for (int a = 0; a < strlen(word); a++) {
			if (word[a] == l[0]) {
				cout << "\nGood!\n";
				strcat_s(correct, l);
				good = true;
			}
		}

		if (good == false) {
			guesses--;
			strcat_s(wrong, l);
		}

		showGallows(guesses);

		cout << "\nWrong guesses: " << wrong;

		showSolved(word, correct);
	}

	cout << "\n\nGame Over";
	return 0;
}

