#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

static int *merge(int *av, int ac, int *bv, int bc) {
	/* two-finger algorithm */
	int ai = 0, bi = 0;
	int *res = (int *)malloc(sizeof(int) * (ac + bc));

	while (ai < ac || bi < bc) {
		if (ai == ac) {
			res[ai + bi] = bv[bi];
			bi++;
		} else if (bi == bc) {
			res[ai + bi] = av[ai];
			ai++;
		} else {
			if (av[ai] < bv[bi]) {
				res[ai + bi] = av[ai];
				ai++;
			} else {
				res[ai + bi] = bv[bi];
				bi++;
			}
		}
	}

	return res;
}

static int *merge_sort_recursive_helper(int *arr, int len) {
	int mid = len / 2;
	int *l;
	int *r;
	int *res;

	if (len == 1) return arr;
	l = merge_sort_recursive_helper(arr, mid);
	r = merge_sort_recursive_helper(arr + mid, len - mid);
	res = merge(l, mid, r, len - mid);

	return res;
}

void merge_sort_recursive(int *arr, int len) {
	if (len == 0) return;
	int *mem = (int *)malloc(sizeof(int) * len);
	int *res;
	int i;

	for (i = 0; i < len; i++) mem[i] = arr[i];
	res = merge_sort_recursive_helper(mem, len);
	for (i = 0; i < len; i++) arr[i] = res[i];

	free(mem);
	free(res);
}

void merge_sort_loop(int* arr, int len) {
}
