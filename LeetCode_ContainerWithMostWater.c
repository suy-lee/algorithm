#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int getArea(int l, int h, int idx_diff)
{
	int temp = min(l, h) * idx_diff;
	return temp;
}

int maxArea(int* height, int heightSize) {
	int i = 0;
	int j = heightSize - 1;
	int max = -1;
	int area = 0;

	while (i < j) {
		area = getArea(height[i], height[j], j - i);
		if (area > max) max = area;
		
		if (min(height[i], height[j]) == height[i]) {
			// i is lower
			i += 1;
		}
		else { // min(height[i], height[j]) == height[j]
			// j is lower
			j -= 1;
		}
	}

	printf("max: %d\n", max);

	return max;
}

/*
--------------- Dummy Code ---------------

int main()
{

	int arr1[9] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int arr2[2] = { 1, 1 };
	int arr3[7] = { 2, 3, 10, 5, 7, 8, 9 };
	int arr4[3] = { 1, 2, 1 };
	int arr5[4] = { 1, 2, 4, 3 };
	int ret = maxArea(arr5, 4);

	printf("%d\n", ret);
}
*/