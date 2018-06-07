#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void test_sort_func(void (*sort_func)(int *, int), int len, int testc) {
	int arr[len]; // VLA, please enable C99 features.
	int i, j;
	int err;

	for (i = 0; i < testc; i++) {
		err = 0;
		knuth_shuffle(arr, len);
		printf("		"); /* indentation */
		for (j = 0; j < len; j++) {
			printf("%d ", arr[j]);
		}
		sort_func(arr, len);
		printf(" -> ");
		for (j = 0; j < len; j++) {
			printf("%d ", arr[j]);
			if (j != 0 && arr[j - 1] > arr[j]) {
				err = 1;
			}
		}
		if (err == 1) {
			printf(" error");
		}
		printf("\n");
	}
}

char *func_names[] = {
	"linear_insertion_sort",
	"binary_insertion_sort",
	"merge_sort_recursive",
	"merge_sort_top_down",
	"merge_sort_bottom_up",
	"heap_sort",
	NULL
};

void (*func_pointers[])(int *, int) = {
	linear_insertion_sort,
	binary_insertion_sort,
	merge_sort_recursive,
	merge_sort_top_down,
	merge_sort_bottom_up,
	heap_sort,
	NULL
};

int main() {
	int i;
	for (i = 0; func_pointers[i] != NULL; i++) {
		printf("\n\n@@ %s:\n", func_names[i]);
		printf("	Empty list:\n");
		test_sort_func(func_pointers[i], 0, 1);
		printf("	Ten elements:\n");
		test_sort_func(func_pointers[i], 10, 10);
	}

	return 0;
}
