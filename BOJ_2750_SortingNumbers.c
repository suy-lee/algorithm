/*
BOJ
https://www.acmicpc.net/problem/2750
*/
#include <stdio.h>

#define MAX 1000

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;   
}

void bubbleSort(int N, int *A)
{
    int flag = 1;
    int i = 0;
    
    while (flag) {
        flag = 0;
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(&A[j], &A[j-1]);
                flag = 1;
            }
        }
        i++;
    }
}

int main()
{
    int N, A[MAX]; // memory space could be reduced...
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bubbleSort(N, A);

    for (int i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }
}