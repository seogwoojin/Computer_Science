#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

void hanoi(int N, char start, char end)
{
    if (N == 1) {
        printf("%c %c\n", start, end);
        return;
    }
    else {
        if (start == 'A' && end == 'C') {
            hanoi(N - 1, 'A', 'B');
            hanoi(1, 'A', 'C');
            hanoi(N - 1, 'B', 'C');
        }
        else if (start == 'A' && end == 'B') {
            hanoi(N - 1, 'A', 'C');
            hanoi(1, 'A', 'B');
            hanoi(N - 1, 'C', 'B');
        }
        else if (start == 'B' && end == 'C') {
            hanoi(N - 1, 'B', 'A');
            hanoi(1, 'B', 'C');
            hanoi(N - 1, 'A', 'C');
        }
        else if (start == 'B' && end == 'A') {
            hanoi(N - 1, 'B', 'C');
            hanoi(1, 'B', 'A');
            hanoi(N - 1, 'C', 'A');
        }
        else if (start == 'C' && end == 'A') {
            hanoi(N - 1, 'C', 'B');
            hanoi(1, 'C', 'A');
            hanoi(N - 1, 'B', 'A');
        }
        else if (start == 'C' && end == 'B') {
            hanoi(N - 1, 'C', 'A');
            hanoi(1, 'C', 'B');
            hanoi(N - 1, 'A', 'B');
        }
        return;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    hanoi(N, 'A', 'C');


    return 0;
}