// MathDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


__declspec(dllexport) int MulMe(int x, int y) {
	return x + y;
}