#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

void rec(int num)
{
    int cut;
    cut = num % 10;

    if (num / 10 == 0) {
        printf("%d\n", cut);
    }
    else
    {
        rec(num / 10);
        printf("%d\n", cut);
    }
}

int main()
{
    int N, ans;
    scanf("%d", &N);

    rec(N);
    return 0;
}