#include <stdio.h>

/* find() - Find or show the relevant position of target in an array.
 * - arr    : The array.
 * - lo, hi : The end-points.
 * - tar    : The target. */
int find(int* arr, int lo, int hi, int tar) {
	int mid = (lo + hi) / 2;

	if (arr[mid] == tar) /* base case i - hit */
		return mid;
	else if (lo > hi) /* base case ii - over */
		return lo;
	else if (arr[mid] < tar)
		return find(arr, mid + 1, hi, tar);
	else
		return find(arr, lo, mid - 1, tar);
}

int searchInsert(int* nums, int numsSize, int target) {
	return (numsSize == 0) ? 0 : find(nums, 0, numsSize - 1, target);
}


int main() {
	int nums[5] = {2, 7, 8, 9, 10};

	printf("== %d", searchInsert(nums, 4, 12));

	return 0;
}

