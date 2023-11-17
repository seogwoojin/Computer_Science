
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define N 100
int num = 0;

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

void print(StackType* S)
{
	for (int i = 0; i <= S->top; i++) {
		printf("%c ", S->stack[i]);
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

int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}


void convert(char* a, char* b)
{
	StackType S;
	init(&S);
	char c, t;

	for (int i = 0; i < strlen(a); i++) {
		c = a[i];
		switch (c) {
		case '(':
			push(&S, c);
			break;
		case ')':
			t = pop(&S);
			while (t != '(') {
				b[num++] = t;
				t = pop(&S);
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
				b[num++] = pop(&S);
			push(&S, c);
			break;
		default:
			b[num++] = c;
			break;
		}
	}
	while (!(isEmpty(&S))) {
		b[num++] = pop(&S);
	}
}

int evaluate(char* c) {
	StackType S;
	init(&S);
	char ch, op1, op2;
	int value;

	for (int i = 0; i < num; i++) {
		ch = c[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&S, value);
		}
		else { 
			op2 = pop(&S);
			op1 = pop(&S);
			switch (ch) { 
			case '+': push(&S, op1 + op2); break;
			case '-': push(&S, op1 - op2); break;
			case '*': push(&S, op1 * op2); break;
			case '/': push(&S, op1 / op2); break;
			}
		}
	}
	return pop(&S);
}

int main()
{
	char infix[N], postfix[N];

	scanf("%s", infix);

	convert(infix, postfix);

	printf("%d\n", evaluate(postfix));

	return 0;
}
