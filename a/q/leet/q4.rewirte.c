#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int* av, int ac, int* bv, int bc) {
	int len = ac + bc;
	int tmp[len]; /* VLA */
	int i = 0, j = 0, k = 0;
	double res;

	for (k = 0; k < len; k++)
		if (i == ac)
			tmp[k] = bv[j++];
		else if (j == bc)
			tmp[k] = av[i++];
		else if (av[i] < bv[j])
			tmp[k] = av[i++];
		else
			tmp[k] = bv[j++];

	if (len % 2 == 0) /* even */
		res = (tmp[len/2] + tmp[len/2 - 1]) / 2.0;
	else
		res = tmp[len/2];

	return res;
}

int main() {
	int a[2] = {1, 2};
	int b[2] = {3, 4};

	printf("\n== %f\n", findMedianSortedArrays(a, 2, b, 2));

	return 0;
}
