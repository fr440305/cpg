#include <stdio.h>

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

int main() {
	int a[5] = {5, 4, 3, 2, 1};
	int i;

	binary_insertion_sort(a, 5);
	for (i = 0; i < 5; i++) {
		printf("%d, ", a[i]);
	}

	return 0;
}

