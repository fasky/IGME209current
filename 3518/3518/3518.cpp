// 3518.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	//setting

	vector<string> pokemon;

	pokemon.push_back("Gengar");
	string name("Mew");
	pokemon.push_back(name);

	//printing

	cout << pokemon[0] << endl;
	cout << pokemon.at(1) << endl;

	for (size_t i = 0; i < pokemon.size(); i++) {
		cout << pokemon[i] << endl;
	}

	for (const auto& p : pokemon) {
		cout << p << " " << p.length() << endl;
	}

    return 0;
}

