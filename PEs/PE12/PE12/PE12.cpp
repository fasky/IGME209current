// PE12.cpp : Defines the entry point for the console application.
// Kyle Fasanella // Section 1 // Smart Pointers

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void pointySmart() {
	shared_ptr<Level> levelPtrSmrt(new Level());
}

void pointyNormal() {
	Level * levelPtrNrml = new Level();
}

int main()
{
	pointySmart(); //created and then destroyed
	pointyNormal(); //created and not destroyed - memory leak
	/*Detected memory leaks! -- Example
		Dumping objects ->
		{167} normal block at 0x010FD860, 12 bytes long.
		 Data: <            > CD CD CD CD CD CD CD CD CD CD CD CD 
		Object dump complete.
	*/

	_CrtDumpMemoryLeaks();
    return 0;
}

