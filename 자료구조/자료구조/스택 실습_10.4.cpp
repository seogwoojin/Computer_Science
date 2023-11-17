#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef int element;

typedef struct StackType
{
	int top;
	element stack[N];
}StackType;

void init(StackType* S)
{
	S->top = -1;
}

int isEmpty(StackType* S)
{
	return S->top == -1;
}

int isFull(StackType* S)
{
	return (S->top == N - 1);
}

void push(StackType* S, element e) {
	if (isFull(S))
		printf("overflow!\n");
	else {
		S->top++;
		S->stack[S->top] = e;
	}
}

element pop(StackType* S)
{

	if (isEmpty(S)) {
		printf("empty");
		return -1;
	}
	else {
		element e = S->stack[S->top];
		S->top--;
		return e;
	}
}

int top(StackType* S) {
	return S->stack[S->top];
}

void sortedPush(StackType* S, element e) {
	int temp;

	if (isEmpty(S) || e>top(S))
		push(S,e);
	else {
		temp = pop(S);
		sortedPush(S, e);
		push(S, temp);
	}
}
void printStack(StackType* S) {
	for (int i = 0; i <= S->top; i++) {
		printf("%d ", S->stack[i]);
	}
	printf("\n");
}
int main() {
	StackType S;
	init(&S);

	element data[6] = { 5,3,8,1,2,7 };

	for (int i = 0; i < 6; i++)
	{
		sortedPush(&S, data[i]);
		printStack(&S);
	}
	return 0;
}