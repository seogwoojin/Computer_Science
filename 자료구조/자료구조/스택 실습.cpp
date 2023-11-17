#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
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
	if (S->top == -1) return 1;
}

int isFull(StackType * S)
{
	if (S->top == N - 1) return 1;
	else return 0;
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
		char c = S->stack[S->top];
		S->top--;
		return c;
	}

}

int main() {
	StackType S;
	init(&S);
	push(&S, 'C');
	push(&S, 'a');
	push(&S, 't');
	push(&S, 'D');
	print(&S);

	getchar();
	printf("After pop: %c \n", pop(&S));
	print(&S);

	return 0;
}