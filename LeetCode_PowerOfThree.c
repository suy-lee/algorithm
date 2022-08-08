#include <stdio.h>
#include <stdbool.h>

#define RESN 32

char ternary[RESN]; // MAX: 2^32

int getTernary(int n, char *arr) {
	int count = 0;

	// convert negative to positive
	//if (n < 0) n *= -1;
	if (n < 0) return 0;

	// initialize result array
	for (int i = 0; i < RESN; i++) ternary[i] = 0;

	while (n / 3 >= 3) {
		arr[count++] = n % 3;
		n /= 3;
	}
	arr[count++] = n % 3;
	arr[count++] = n / 3;

	//printf("count: %d\n", count);
	for (int i = count - 1; i >= 0; i--) {
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	printf("\n");
	return count;
	// test	
}

int getCountOfOne(int n, char *arr) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) count++;
		else if (arr[i] == 0) continue;
		else {
			count = -1;
			return count;
		}
	}

	return count;
}

bool isPowerOfThree(int n) {
	// convert into ternary
	int count = getTernary(n, ternary);

	// return number of 1
	int ret = getCountOfOne(count, ternary);

	printf("ret=%d\n", ret);

	if (ret == 1) return true;
	else return false;
}

/*
------------- Dummy Code ------------

int main()
{
	int arr[5] = { 27, 0, 9, 1, 45 };
	for (int i = 0; i < 5; i++) {
		if (isPowerOfThree(arr[i]) == true) printf("%d: true\n", arr[i]);
		else printf("%d: false\n", arr[i]);
	}
}
*/