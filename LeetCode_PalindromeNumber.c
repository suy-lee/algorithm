#include <stdio.h>
#include <stdbool.h>

bool isArrayPalindrome(int *src, int count)
{
	bool ret = true;

	for (int i = 0; i < count / 2; i++) {
		if (src[i] != src[count - i - 1]) {
			ret = false; return ret;
		}
	}

	return ret;
}

int convertToIntArray(int x, int *dest)
{
	int count = 0;
	int x_temp = x;

	while (x / 10 >= 10) {
		dest[count++] = x % 10;
		x /= 10;
	}
	dest[count++] = x % 10;
	if (x_temp >= 10) dest[count++] = x / 10; // exception handling for one-digit

	// test
    /*
	for (int i = 0; i < count; i++) {
		printf("%d ", dest[i]);
	}
	printf("\n");
    */
	return count;
}

bool isPalindrome(int x) {
	int arr[12] = { 0, };
	int count = 0;

	if (x < 0) return false;

	count = convertToIntArray(x, arr);

	return isArrayPalindrome(arr, count);
}

/*
------------- Dummy Code ------------

int main()
{
	int arr[1] = { 1001 };
	for (int i = 0; i < 1; i++) {
		if (isPalindrome(arr[i]) == true) printf("%d: true\n", arr[i]);
		else printf("%d: false\n", arr[i]);
	}
}
*/