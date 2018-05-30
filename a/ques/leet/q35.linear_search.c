#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        } else if (nums[i] < target) {
            if (i+1 >= numsSize || nums[i+1] > target) {
                return i+1;
            }
        }
    }
    /* empty list: */
    return 0;
}

int main() {
	int nums[5] = {2, 7, 8, 9, 10};

	/* expect: 2 */
	printf("%d", searchInsert(nums, 5, 9));
	return 0;
}

