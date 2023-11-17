#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>

int check(char* ch, int start, char w) {
    if (sizeof(ch)-1 == start) {
        if (ch[start] == w) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
        if (ch[start] == w) {
            return 1 + check(ch, ++start, w);
        }
        else {
            return 0 + check(ch, ++start, w);
        }
    }
}

int main()
{
    int ck;
    char str[100];
    char word;
    scanf("%s", str);
    getchar();
    scanf("%c", &word);
    ck=check(str, 0, word);
    printf("%d", ck);
    return 0;
}