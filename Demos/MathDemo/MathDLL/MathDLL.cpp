// MathDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


__declspec(dllexport) int MulMe(int x, int y) {
	return x * y;
}

__declspec(dllexport) int MulMePointers(int* x, int* y) {
	if (x == nullptr || y == nullptr) {
		return 0;
	}
	return *x * *y;
}

__declspec(dllexport) int MulMeReference(int &x, int &y) {
	return x + y;
}