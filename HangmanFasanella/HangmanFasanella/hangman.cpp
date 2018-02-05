// hangman functions
#include "stdafx.h"

void showGallows(int a) {
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
		default:
			cout << "_________\n|\n|\n|\n|\n|\n|\n";;
			return;
	}
	
}

void showSolved(char b[], char c[])
{
	for (int a = 0; a < strlen(b); a++) {
		for (int d = 0; d < strlen(c); d++) {
			if (b[a] == c[d]) {

			}
		}
		
	}
	cout << "\nWord to solve: ";
}