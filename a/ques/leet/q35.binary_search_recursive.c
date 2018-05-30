#include <stdio.h>

int find(int* arr, int off, int len, int tar) {
	/* Note that len cannot be zero. */
	int mid = off + len/2;
	int odd = len % 2;

	printf("find %d from arr[off == %d, len == %d]\n", tar, off, len);

	if (len == 1) /* base case */
		return off + (tar > arr[off]);
	else
		if (arr[mid] == tar)
			return mid;
		else if (arr[mid] < tar)
			return find(arr, mid + odd, len/2, tar);
		else
			return find(arr, off, len/2, tar);
}

int searchInsert(int* nums, int numsSize, int target) {
	if (nums == 0)
		return 0;
	else
		return find(nums, 0, numsSize, target);
}


int main() {
	int nums[5] = {2, 7, 8, 9, 10};

	/* expect: 2 */
	printf("%d", searchInsert(nums, 5, 9));
	return 0;
}

