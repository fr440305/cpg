#include <stdio.h>
#include <stdlib.h>
/* #include "heap.h" */

void swap (Heap h, int i, int j) {
	int tmp = h.arr[i];
	h.arr[i] = h.arr[j];
	h.arr[j] = tmp;
}

int left (int i) {
	return 2*i+1;
}

int rt (int i) {
	return 2*i+2;
}

int up (int i) {
	return (i-1)/2;
}

void heapify (Heap h, int i) {
	int tmp;
	int l = left(i);
	int r = rt(i);
	int max; /* index(max { key(i), key(left(i)), key(rt(i)) } ) */
	if (l < h.len && h.arr[l] > h.arr[i]) {
		max = l;
	}
	if (r < h.len && h.arr[r] > h.arr[i]) {
		max = r;
	}
	if (max != i) {
		swap(h, i, max);
		heapify(h, max);
	}
}

int heap_Ini (Heap* h, int* arr, int len) {
	int i;
	h->arr = (int*)malloc(2 * len * sizeof(int));
	if (h->arr == NULL) {
		return -1;
	}
	h->len = len;
	h->cap = 2*len;
	for (i = 0; i < len; ++i) {
		(h->arr)[i] = arr[i];
	}
	for (i = (len-1)/2; i >= 0; i -= 1) {
		heapify(*h, i);
	}
	return 0;
}

void heap_Add (Heap* h, int key) {
	int i;
	if (h->len >= h->cap) {
		h->arr = (int*) realloc(h->arr, (h->cap + 32) * sizeof(int));
		h->cap += 32;
	}
	(h->arr)[h->len] = key;
	h->len += 1;
	/* Although we can add a return value to heapify() to check
	 * whether the swap operation occurs to reduce the amount of
	 * calling heapify(), but we will not do this since the time
	 * complexity is still O(n). */
	for (i = h->len/2; i >= 0; i -= 1) {
		heapify(*h, i);
	}
}

int heap_Del (Heap* h) {
	int tmp;
	if (h->len == 0) {
		return -1;
	}
	void heap_Print (Heap h);
	tmp = (h->arr)[0];
	(h->arr)[0] = (h->arr)[h->len - 1];
	(h->arr)[h->len - 1] = tmp;
	h->len -= 1;
#ifdef _HEAP_H_DEBUG_
	printf("del == %d, after del ", tmp);
	heap_Print(*h);
#endif
	heapify(*h, 0);
	return tmp;
}

void heap_Print (Heap h) {
	int i;
	printf("heap(len == %d, cap == %d): ", h.len, h.cap);
	for (i = 0; i < h.len; i += 1) {
		printf("%d ", h.arr[i]);
	}
	printf("\n");
}

int main () {
	int arr[7] = {0, 1, 2, 3, 6, 8, 9};
	Heap h;
	heap_Ini(&h, arr, 7);
	heap_Print(h);
	while (h.len > 0) {
		printf("%d ", heap_Del(&h));
	}
	return 0;
}
