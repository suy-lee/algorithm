#define MAX 100001
int arr[MAX] = { 0, };

int findDuplicate(int* nums, int numsSize) {
	// init
	for (int i = 0; i < numsSize; i++) {
		arr[i] = 0;
	}
	
	for (int i = 0; i < numsSize; i++) {
		if (arr[nums[i]] == 1) return nums[i];
		arr[nums[i]] += 1;
	}
	return 0;
}
/*
----------------- Dummy Code --------------------

#include <stdio.h>

int main()
{
	int numsSize1 = 5;
	int nums1[5] = { 1, 3, 4, 2, 2 };

	int numsSize2 = 5;
	int nums2[5] = { 3, 1, 3, 4, 2 };

	int numsSize3 = 3;
	int nums3[3] = { 1, 2, 2 };

	int ret1 = findDuplicate(nums1, numsSize1);
	int ret2 = findDuplicate(nums2, numsSize2);
	int ret3 = findDuplicate(nums3, numsSize3);

	printf("%d %d %d\n", ret1, ret2, ret3);
}
*/