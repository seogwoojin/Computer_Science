#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

int rec(int num)
{

    if (num == 1) {
        return 1;
    }
    return num + rec(num - 1);

}

int main()
{
    int N, ans;
    scanf("%d", &N);
    ans = rec(N);
    printf("%d", ans);
    return 0;
}