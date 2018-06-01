#include <stdio.h>

void linear_insertion_sort(int* arr, int len) {
	int i, j;
	int tmp;

	for (i = 1; i < len; i++) {
		for (j = i; j > 0; j--) {
			if (arr[j] > arr[j-1]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}


void main() {
	int a[5] = {1, 2, 3, 4, 5};
	int i;

	linear_insertion_sort(a, 5);
	for (i = 0; i < 5; i++) {
		printf("%d, ", a[i]);
	}

	return 0;
}
