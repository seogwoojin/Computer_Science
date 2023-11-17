#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
    int n, f=10;
    scanf("%d", &n);
    
    while (true) {
        printf("%d\n", n % f);
        n=n/f;
        if (n == 0) break;
    }



    return 0;
}