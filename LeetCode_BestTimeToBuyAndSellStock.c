#include <stdio.h>

#define MAX(a, b) a > b? a: b;
#define MIN(a, b) a > b? b: a;

int maxProfit(int* prices, int pricesSize){
    int min = prices[0];
    int max = -10000;
    int res = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        max = MAX(prices[i]-min, max);
        min = MIN(prices[i], min);
    }
    
    if (max < 0) max = 0;
    return max;
}

int main()
{
    int arr1[6] = {7, 1, 5, 3, 6, 4};
    int arr2[5] = {7, 6, 4, 3, 1};

    printf("%d\n%d\n", maxProfit(arr1, 6), maxProfit(arr2, 5));

    return 0;
}