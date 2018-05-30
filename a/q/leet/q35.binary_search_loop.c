#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	int lo = 0, hi = numsSize - 1, mid;

	while (mid = (lo + hi) / 2, lo <= hi)
		if (nums[mid] == target) /* base case */
			return mid;
		else if (nums[mid] < target)
			lo = mid + 1;
		else
			hi = mid - 1;

	return lo; /* empty list */
}

int main() {
	int nums[5] = {2, 7, 8, 9, 10};

	/* expect: 2 */
	printf("%d", searchInsert(nums, 5, 9));
	return 0;
}

