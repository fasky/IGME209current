#pragma once
struct Item 
{
public:
	void print();
	Item(string nm, int dam, int wt);
	~Item();

private:
	string name;
	int damage;
	int weight;
};

