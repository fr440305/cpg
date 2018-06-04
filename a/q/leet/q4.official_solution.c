/* findMedianSortedArrays() - with time complexity O(log2[n]) and space complexity O(1)
 * @av The first array
 * @ac The length of the first array
 *
 * 这个解法真是吊炸天 */

#include <stdio.h>

double findMedianSortedArrays(int* av, int ac, int* bv, int bc) {
	int half = (ac + bc + 1) / 2;
	int i, j;
	int lo = 0, hi = ac - 1;
	int min, max;
	int* swap;

	if (ac > bc) {
		swap = av;
		av = bv;
		bv = swap;

		i = ac;
		ac = bc;
		bc = i;
	}

	while (lo <= hi) {
		i = (lo + hi) / 2;
		j = half - i;
		if (i < hi && bv[j-1] > av[i])
			lo += 1;
		else if (i > lo && av[i-1] > bv[j])
			hi -= 1;
		else /* find */
			break;
	}

	if      (i == 0)            max = bv[j-1];
	else if (j == 0)            max = av[i-1];
	else if (av[i-1] > bv[j-1]) max = av[i-1];
	else                        max = bv[j-1];

	if      (i == ac)       min = bv[j];
	else if (j == bc)       min = av[i];
	else if (av[i] < bv[j]) min = av[i];
	else                    min = bv[j];

	return (min + max) / 2.0;
}

int main() {
	int a[3] = {1, 3, 5};
	int b[3] = {2, 4, 6};

	printf("== %f", findMedianSortedArrays(a, 2, b, 1));

	return 0;
}
