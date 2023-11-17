#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef struct StackType
{
	int top;
	char stack[N];
}StackType;

void init(StackType* Sp)
{
	(*Sp).top = -1;
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

void print(StackType* S)
{
	for (int i = 0; i <= S->top; i++) {
		printf("%c ", S->stack[i]);
	}

}

char pop(StackType* S)
{

	if (isEmpty(S)) {
		printf("empty");
		return -1;
	}
	else {
		char c = S->stack[S->top--];
		return c;
	}
}

int check(char* a)
{
	StackType S;
	init(&S);

	char c, t;

	for (int i = 0; i < strlen(a); i++) {
		c = a[i];
		if (c == '(' || c == '{' || c == '[')
			push(&S, c);
		else if (c == ')' || c == '}' || c == ']') {
			if (isEmpty(&S))
				return 0;
			else {
				t = pop(&S);
				if ((t == '(' && c != ')') ||
					(t == '{' && c != '}') ||
					(t == '[' && c != ']')) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {
	char expr[N];
	scanf("%s", expr);

	if (check(expr))
		printf("Success");
	else
		printf("Fail");

	return 0;
}