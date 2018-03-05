#pragma once
#include "Assassin.h"

extern class Elf;

class Dwarf :
	public Assassin
{
public:
	Dwarf();
	~Dwarf();
};

extern Dwarf* dwarfHead;
//extern void Print();