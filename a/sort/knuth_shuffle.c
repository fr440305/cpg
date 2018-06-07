#include <stdlib.h>

void knuth_shuffle(int* ret, int len) {
	int i, j;
	int tmp;

	for (i = 0; i < len; i++)
        ret[i] = i;
	for (i = len-1; i >= 0; i--) {
		j = rand() % len;
		tmp = ret[i];
		ret[i] = ret[j];
		ret[j] = tmp;
	}
}
