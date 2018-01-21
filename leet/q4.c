#include <stdio.h>
#include <stdlib.h>

double mid (int* A, int alen, int* B, int blen) {
	int a = 0;
	int b = 0;
	int odd = ((alen + blen) % 2 != 0);
	int len = (alen + blen) / 2 + 1 + odd;
	int* M = (int*)malloc(len * sizeof(int));
	int m = 0;
	double ret;
	while (m < len) {
		if (a != alen && b != blen) {
			if (A[a] <= B[b]) {
				M[m] = A[a];
				a += 1;
			} else {
				M[m] = B[b];
				b += 1;
			}
		} else if (a != alen) {
			M[m] = A[a];
			a += 1;
		} else if (b != blen) {
			M[m] = B[b];
			b += 1;
		}
		m += 1;
	}
	ret = (odd ? (M[len-2]) :
		((M[len-1] + M[len-2]) / 2.0)
	);
	free(M);
	return ret;
}

int main () {
	int A[] = {1, 2, 3};
	int B[] = {5, 6, 7};
	double m = mid(A, 3, B, 3);
	printf("%f\n", m);
	return 0;
}
