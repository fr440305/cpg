#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	int off = 0;
	int len = numsSize;
	int mid;
	int odd;

	if (numsSize == 0)
		return 0;

	while (len > 1) {
		mid = off + len / 2;
		odd = len % 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			off = mid + odd;

		len /= 2;
	}

	return off + (target > nums[off]);
}

int main() {
	int nums[5] = {2, 7, 8, 9, 10};

	/* expect: 2 */
	printf("%d", searchInsert(nums, 5, 9));
	return 0;
}

