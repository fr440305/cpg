#include <stdlib.h>

int* knuth_shuffle(int lo, int hi) {
	int len = hi - lo + 1;
	int* ret = (int*) malloc(len * sizeof (int));
	int i, j;
	int tmp;

	for (i = 0; i < len; i++)
		ret[i] = lo + i;
	for (i = len-1; i >= 0; i--) {
		j = lo + rand() % len;
		tmp = ret[i];
		ret[i] = ret[j];
		ret[j] = tmp;
	}

	return ret;
}

