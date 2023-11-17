#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define N 100

typedef struct StackType
{
	int top;
	char stack[N];
}StackType;

void init(StackType* S)
{
	S->top = -1;
}

int isEmpty(StackType* S)
{
	return (S->top == -1);
}

int isFull(StackType* S)
{
	return (S->top == N - 1);
}

void push(StackType* S, char c) {
	if (isFull(S))
		printf("overflow!\n");
	else {
		S->top++;
		S->stack[S->top] = c;
	}
}

char pop(StackType* S)
{

	if (isEmpty(S)) {
		return -1;
	}
	else {
		char c = S->stack[S->top--];
		return c;
	}
}

char peek(StackType* S)
{
	return S->stack[S->top];
}


int check(char* st) { //문자열 체크 함수
	StackType S;
	init(&S);
	char c;
	char ch[N];
	int len = strlen(st);
	int small_len=0;

	for (int i = 0; i < len; i++) {
		c = st[i];
		if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) {
			if (97 <= c) {
				c -= 32;
			}
			ch[small_len++] = c;
		}
	}

	if (small_len % 2 == 0) {
		for (int j = 0; j < small_len; j++) {
			c = ch[j];
			if (c == peek(&S))
				pop(&S);
			else
				push(&S, c);
		}
	}
	else {
		int mid = (small_len - 1) / 2;
		for (int j = 0; j < small_len; j++) {
			if (j == mid)
				continue;
			else if (c == peek(&S))
				pop(&S);
			else
				push(&S, c);
		}
	}
	return isEmpty(&S);
}

int main()
{
	char st[N];
	scanf("%[^\n]s", st); //문자열 입력
	
	if (check(st)) {
		printf("It's palindrome");
	}
	else {
		printf("It's not palindrome");
	}
	return 0;
}