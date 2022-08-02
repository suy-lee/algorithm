/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int i_comp, j_comp, dest_size, max_size;

void acc(int s_i, int s_j, int sz_m, int sz_n, int **src, int *dest)
{
	int i, j;
	
	// ph #1
	i = s_i;
	for (j = s_j; j < s_j + sz_m; j++) {
		if (dest_size >= max_size) break;
		dest[dest_size++] = src[i][j];
	}

	// ph#2
	j = s_j + sz_m - 1;
	for (i = s_i + 1; i < s_i + sz_n; i++) {
		if (dest_size >= max_size) break;
		dest[dest_size++] = src[i][j];
	}

	// ph#3
	i = s_i + sz_n - 1;
	for (j = s_j + sz_m - 2; j >= s_j; j--) {
		if (dest_size >= max_size) break;
		dest[dest_size++] = src[i][j];
	}

	// ph#4
	j = s_j;
	for (i = s_i + sz_n - 2; i >= s_i + 1; i--) {
		if (dest_size >= max_size) break;
		dest[dest_size++] = src[i][j];
	}
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	// initialize global variables
	int m = *matrixColSize, n = matrixSize;
	dest_size = 0, max_size = m * n;

	printf("%d %d\n", m, n);
	
	// initialize return array
	int *result_arr = (int *)malloc(sizeof(int) * (m * n));

	// call accumulate function
	int max = m / 2;
	printf("max=%d\n", max);
	for (int i = 0; i <= max; i++, m -= 2, n -= 2) {
		printf("i=%d, m=%d\n", i, m);
		acc(i, i, m, n, matrix, result_arr);
	}

	// verify
	for (int i = 0; i < dest_size; i++) {
		printf("[%d] %d\n", i, result_arr[i]);
	}

	// return
	*returnSize = dest_size;
	return result_arr;
}

/*
------------ Dummy Code --------------
*/
/*
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

https://stackoverflow.com/questions/61464607/what-is-the-best-way-to-make-2-dimensional-array-in-c

int main()
{
/* TC 1 
	const int row = 3;
	const int col = 3;

	int **arr = (int **)malloc(sizeof(int *) * 3);
	arr[0] = (int *)malloc(sizeof(int) * 3);
	arr[1] = (int *)malloc(sizeof(int) * 3);
	arr[2] = (int *)malloc(sizeof(int) * 3);

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;
	arr[2][0] = 7;
	arr[2][1] = 8;
	arr[2][2] = 9;
*/
/* TC 2
	int row = 3;
	int col = 4;

	int **arr = (int **)malloc(sizeof(int *) * 3);
	arr[0] = (int *)malloc(sizeof(int) * 4);
	arr[1] = (int *)malloc(sizeof(int) * 4);
	arr[2] = (int *)malloc(sizeof(int) * 4);

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 5;
	arr[1][1] = 6;
	arr[1][2] = 7;
	arr[1][3] = 8;
	arr[2][0] = 9;
	arr[2][1] = 10;
	arr[2][2] = 11;
	arr[2][3] = 12;
*/
/* TC 3
	int row = 1;
	int col = 2;
	int **arr = (int **)malloc(sizeof(int *) * 1);
	arr[0] = (int *)malloc(sizeof(int) * 2);
	arr[0][0] = 2;
	arr[0][1] = 3;
*/

/* TC 4 
	int row = 4;
	int col = 4;

	int **arr = (int **)malloc(sizeof(int *) * 4);
	arr[0] = (int *)malloc(sizeof(int) * 4);
	arr[1] = (int *)malloc(sizeof(int) * 4);
	arr[2] = (int *)malloc(sizeof(int) * 4);
	arr[3] = (int *)malloc(sizeof(int) * 4);

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 5;
	arr[1][1] = 6;
	arr[1][2] = 7;
	arr[1][3] = 8;
	arr[2][0] = 9;
	arr[2][1] = 10;
	arr[2][2] = 11;
	arr[2][3] = 12;
	arr[3][0] = 13;
	arr[3][1] = 14;
	arr[3][2] = 15;
	arr[3][3] = 16;

	int res;
	spiralOrder(arr, row, &col, &res);
#if 0
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
#endif
}
*/