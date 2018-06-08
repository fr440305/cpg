#include <stdio.h>

void linear_insertion_sort(int* arr, int len) {
	int i, j;
	int tmp;

	for (i = 1; i < len; i++) {
		for (j = i; j > 0; j--) {
			if (arr[j] < arr[j-1]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}

void binary_insertion_sort(int* arr, int len) {
	int i; /* interate */
	int j; /* shift */
	int lo, hi, mid; /* search */
	int tmp; /* swap */

	for (i = 1; i < len; i++) {
		lo = 0;
		hi = i-1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (arr[i] < arr[mid]) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		/* lo is the place where arr[i] should be */
		for (j = i; j > lo; j--) {
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
		}
	}
}
