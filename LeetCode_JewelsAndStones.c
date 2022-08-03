#include <stdio.h>
#include <string.h>
/*
Z = 90
a = 97 -- > 91
A = 65

if c >= 97
A ....Z a
65 ... 90 97
- 64 | -64 - 6
1 .... 26 27 ..........52

53개, index 0은 안쓰고
*/
int jewels_count[53] = { 0, };

int getCharIndex(char c)
{
	int ret;
	int comp = 64;

	if (c >= 97) // 'A' to 'Z'
		ret = c - comp - 6;
	else		 // 'a' to 'z'
		ret = c - comp;

	return ret;
}

int numJewelsInStones(char * jewels, char * stones) {
    for (int i = 0; i < 53; i++)
        jewels_count[i] = 0;

	for (int i = 0; i < strlen(jewels); i++)
        jewels_count[getCharIndex(jewels[i])]++;

	int stone, stone_count = 0;
	for (int i = 0; i < strlen(stones); i++) {
		stone = getCharIndex(stones[i]);
        //printf("stone: %d, jewels_count[stone]: %d\n", stone, jewels_count[stone]);
		if (jewels_count[stone] != 0) stone_count++;
	}
	return stone_count;
}

/*
--------------- Dummy Code -----------------
int main()
{
	
	//char jewels[3] = "aA";
	//char stones[8] = "aAAbbbb";

	char jewels[4] = "bcd";
	char stones[4] = "cba";
	int ret = numJewelsInStones(jewels, stones);
	printf("%d\n", ret);
}
*/