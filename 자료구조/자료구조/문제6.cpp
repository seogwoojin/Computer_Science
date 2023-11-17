#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

int recu(int a, int b) {
    
    int r;
    r = a % b;
    if (r == 0) return b;
    return recu(b, r);
}

int main()
{
    int a, b, ans;
    scanf("%d %d", &a, &b);
    ans = recu(a, b);

    printf("%d", ans);
    return 0;
}