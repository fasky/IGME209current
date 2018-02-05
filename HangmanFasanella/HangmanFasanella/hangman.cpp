// hangman functions
#include "stdafx.h"

//show gallows so far
void showGallows(int a) {
	//based on guesses left, draw different art
	switch(a) {
		case 6: cout << "_________\n|  |\n|\n|\n|\n|\n|\n";
			return;
		case 5:cout << "_________\n|  |\n|  O\n|\n|\n|\n|\n";
			return;
		case 4:cout << "_________\n|  |\n|  O\n|  |\n|\n|\n|\n";
			return;
		case 3:cout << "_________\n|  |\n|  O\n| /|\n|\n|\n|\n";
			return;
		case 2:cout << "_________\n|  |\n|  O\n| /|\\ \n|\n|\n|\n";
			return;
		case 1:cout << "_________\n|  |\n|  O\n| /|\\ \n| /\n|\n|\n";
			return;
		case 0:cout << "_________\n|  |\n|  O\n| /|\\ \n| / \\ \n|\n|\n";
			return;
		default: //if none wrong yet
			cout << "_________\n|\n|\n|\n|\n|\n|\n";;
			return;
	}
	
}

//Show word solved so far - show message when complete - show how many letters are left
void showSolved(char b[], char c[])
{
	//start new each time
	char correct[20] = "";
	char correctWord[10] = "---------";
	int left = 0;

	//check letters of word(b) against guessed letters(c)
	for (int a = 0; a < strlen(b); a++) {
		for (int d = 0; d < strlen(c); d++) {
			if (b[a] == c[d]) {
				//if there are right guesses, alter the hidden word to reveal letters
				switch (c[d]) {
					case'n':
						correctWord[0] = c[d];
						break;
					case'e':
						correctWord[1] = c[d];
						break;
					case'o':
						correctWord[2] = c[d];
						break;
					case'l':
						correctWord[3] = c[d];
						break;
					case'i':
						correctWord[4] = c[d];
						correctWord[7] = c[d];
						break;
					case't':
						correctWord[5] = c[d];
						break;
					case'h':
						correctWord[6] = c[d];
						break;
					case'c':
						correctWord[8] = c[d];
						break;
					default:
						cout << "Something's wrong here.";
						break;
				}

			}
		}
	}

	//find out how many letters are left
	for (char a : correctWord) {
		if (a == '-') {
			left++;
		}
	}

	//print out the results
	cout << "\nWord to solve: " << correctWord << "\n\n" << left << " letter(s) left to guess.";

	//if no letters are left to find, player wins
	if (left == 0) {
		cout << "\n\nYou did it!\n\n";
	}
}