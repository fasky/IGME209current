// HangmanFasanella.cpp : Defines the entry point for the console application.
// Kyle Fasanella / Section 1 / Hangman

#include "stdafx.h"

int main()
{
	//create strings
	char word[10] = "neolithic";
	char guess[27] = "";
	char wrong[27] = "";
	int guesses = 7;

	//welcome
	cout << "Welcome to Hangman!\nYour word has " << strlen(word) << " letters in it.\n";

	//while there are guesses left
	while (guesses > 0) 
	{
		//get guess
		char l[100] = ""; //prevented an error by making l[100] instead of l[2]
		bool good = false;
		bool duplicate = false;
		cout << "\nGuess a letter: ";
		cin >> l;
		cout << "Guess: " << l[0] << endl;
		//check if already guessed
		if (strchr(guess, l[0])) {
			duplicate = true;
			cout << "\nAlready guessed.\n";
		}

		//if not already guessed, continue
		if (duplicate == false) {
			//check it against word
			for (int a = 0; a < strlen(word); a++) {
				if (word[a] == l[0])
				//if good, add to guesses and set good to true
				{
					strcat_s(guess, l);
					good = true;
				}
			}

			//if good is false, take away a guess and add letter to both guesses and wrong guesses
			if (good == false) {
				guesses--;
				strcat_s(wrong, l);
				strcat_s(guess, l);
			}

			//show gallows, pass in amount of guesses left
			showGallows(guesses);

			//print our wrong guesses
			cout << "\nWrong guesses: " << wrong;

			//show word solved so far, pass in word to be put against all guessed letters
			showSolved(word, guess);

			//if the guesses contain the right letters, end the game.
			if (strchr(guess, 'n') && strchr(guess, 'e') && strchr(guess, 'o') && strchr(guess, 'l') && strchr(guess, 'i') && strchr(guess, 't') && strchr(guess, 'h') && strchr(guess, 'c')) {
				return 0;
			}
		}

	}

	cout << "\n\nGame Over\n\n";

	return 0;
}

