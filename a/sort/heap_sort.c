// SPDX-License-Identifier: GPL-2.0
/*
 * A fast, small, non-recursive O(nlog n) sort for the Linux kernel
 *
 * Jan 23 2005  Matt Mackall <mpm@selenic.com>
 */

/* I read the source code of `linux/lib/sort.c`
 * for learing the C implementation
 * of heap sort. */

#include "sort.h"

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void sink(int* heap, int len, int idx) {
	int sinker = idx, child;

	while ((child = 2 * sinker + 1) < len) {
		if (child+1 < len && heap[child] < heap[child+1])
			child += 1;
		if (heap[sinker] >= heap[child])
			break;
		swap(heap, sinker, child);
		sinker = child; /* sink */
	}
}

void build(int* arr, int len) {
	int swimmer;

	for (swimmer = len/2 - 1; swimmer >= 0; --swimmer)
		sink(arr, len, swimmer);
}

void pop_all(int* heap, int len) {
	while (len > 0) {
		swap(heap, 0, len-1);
		len -= 1;
		sink(heap, len, 0);
	}
}

void heap_sort(int* arr, int len) {
	build(arr, len);
	pop_all(arr, len);
}

//#define HEAP_SORT_DEBUG_

#ifdef HEAP_SORT_DEBUG_

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[10] = {0, 9, 1, 8, 3, 2, 7, 4, 5, 6};

	build(arr, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}

#endif
