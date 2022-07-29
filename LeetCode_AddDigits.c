/*
0 <= num <= 2^31 - 1
*/

int addOneTimeDigits(int num);

int addDigits(int num) {
	int sum = num;
	while (1) {
		sum = addOneTimeDigits(sum);
		if (sum < 10) break;
	}

	return sum;
}

int addOneTimeDigits(int num) {
	int divided = 0;
	int remained = 0;
	int sum = 0;

	while (1) {
		divided = num / 10;
		remained = num % 10;
		sum += remained;
		num = divided;
		if (num < 10) break;
	}
	sum += num;

	return sum;
}

/*
------------- Dummy Code --------------

#include <stdio.h>

int main()
{
	int ret = addDigits(38);
	printf("%d\n", ret);
}
*/