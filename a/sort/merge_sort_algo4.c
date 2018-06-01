#include <stdio.h>
#include <stdlib.h>

/* @par tmp
 * The capacity of []tmp is equal to
 * the length of the original array */
void merge(int* arr, int* tmp, int lo, int mid, int hi) {
	int i = lo, j = mid+1, k;

	/* copy from arr to tmp */
	for (k = lo; k <= hi; k++)
		tmp[k] = arr[k];

	/* i is the iterator of tmp[lo:mid],
	 * j is the iterator of tmp[mid+1:hi] */
	for (k = lo; k <= hi; k++)
		if (i > mid) /* i is out of bound */
			arr[k] = tmp[j++];
		else if (j > hi) /* j is out of bound */
			arr[k] = tmp[i++];
		else if (tmp[j] < tmp[i])
			arr[k] = tmp[j++];
		else
			arr[k] = tmp[i++];
}

void merge_sort_top_down_helper(int* arr, int* tmp, int lo, int hi) {
	int mid = lo + (hi - lo) / 2;

	if (hi <= lo)
		return;

	merge_sort_top_down_helper(arr, tmp, lo, mid);
	merge_sort_top_down_helper(arr, tmp, mid+1, hi);
	merge(arr, tmp, lo, mid, hi);
}

/* pub */

void merge_sort_top_down(int* arr, int len) {
	int* tmp = (int*) malloc(sizeof(int) * len);

	merge_sort_top_down_helper(arr, tmp, 0, len-1);
	free(tmp);
}

void merge_sort_bottom_up(int* arr, int len) {
}

int main() {
	int a[5] = {5, 4, 3, 2, 1};

	merge_sort_top_down(a, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);

	return 0;
}
