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


