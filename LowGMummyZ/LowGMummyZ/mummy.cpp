#include "stdafx.h"

int GetLevelShambles(int level) {
	int ret = 0;
	srand(time(NULL));
	ret = (rand() % 100 + 1) * level;

	return ret;
}