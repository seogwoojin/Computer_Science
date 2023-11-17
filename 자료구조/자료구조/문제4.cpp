#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

int comp(int* num, int N)
{
    if (N == 2) {
        return (num[0] > num[N - 1] ? num[0] : num[N - 1]);
    }
    else {
        int big1;
        big1 = comp(num, N - 1);
        return (big1 > num[N - 1] ? big1 : num[N - 1]);
    }
}

int main()
{
    int N;
    int lst[20];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }
    int k;
    k = comp(lst, N);
    printf("%d", k);
    return 0;
}