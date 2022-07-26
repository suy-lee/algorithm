/*
https://leetcode.com/problems/product-of-array-except-self/
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    int acc1[numsSize];
    int acc2[numsSize];
    acc1[0] = nums[0];            // dummyValue
    acc2[numsSize-1] = nums[numsSize-1];   // dummyValue

    for (int i = 1; i < numsSize; i++) {
        //printf("[i:%d] %d %d %d %d\n", i, i-1, i, numsSize-i, numsSize-i-1);
        acc1[i]             = acc1[i-1] * nums[i];
        acc2[numsSize-i-1]  = acc2[numsSize-i] * nums[numsSize-i-1];
    }
    
    res[0] = acc2[1];
    res[numsSize-1] = acc1[numsSize-2];

    for (int i = 1; i < numsSize-1; i++) {
        res[i] = acc1[i-1] * acc2[i+1];
    }

    *returnSize = numsSize;

    //for (int i = 0; i < numsSize; i++) {
        //printf("%d ", res[i]);
    //}

    return res;

#if 0 // do not use division!
    int zero_count = 0;
    int zero_index = -1;    // 0이 1개일 때 index 기록
    int predefined_val = 1; /* The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. */
    int *res;
    res = (int *)malloc(sizeof(int) * numsSize);

    int N;
    //printf("%d\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) zero_count++;
        if (nums[i] == 0 && zero_count == 1) {
            zero_index = i;
            //printf("i:%d\n", i);
            continue;
        }
        predefined_val *= nums[i];
    }

    if (zero_count == 0) {
        // 1) 0이 없는 경우
        for (int i = 0; i < numsSize; i++) 
            res[i] = predefined_val / nums[i];
    }
    else if (zero_count == 1) {
        // 2) 0이 1개인 경우
         for (int i = 0; i < numsSize; i++) {
             if (i == zero_index) res[i] = predefined_val;
             else res[i] = 0;
         }
    }
    else {
        // 3) 0이 2개 이상인 경우
        for (int i = 0; i < numsSize; i++)
            res[i] = 0;
    }
/*
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", res[i]);
    }
*/
    *returnSize = numsSize;

    return res;
#endif
}

int res[5];

/* Stub */
int main()
{
    int numsSize = 4;
    int nums[4] = {1, 2, 3, 4};
    //int nums[5] = {-1, 1, 0, -3, 3};
    int returnSize;

    *res = productExceptSelf(nums, numsSize, &returnSize);
}