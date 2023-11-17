#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 60

typedef char element;

typedef struct {
	element queue[N];
	int front, rear;
}DequqType;

void init(DequqType* D)
{
	D->rear = D->front = 0;
}

int isEmpty(DequqType* D) {
	return D->rear == D->front;
}

int isFull(DequqType* D) {
	return (D->rear + 1) % N == D->front;
}

void addFront(DequqType* D, element e)
{
	if (isFull(D)) {
		printf("FULL!\n");
	}
	else {
		D->queue[D->front] = e;
		D->front = (D->front - 1 + N) % N;
	}
}
void addRear(DequqType* D, element e)
{
	if (isFull(D)) {
		printf("full!\n");
	}
	else {
		D->rear = (D->rear + 1) % N;
		D->queue[D->rear] = e;
	}
}

element deleteFront(DequqType* D) {
	if (isEmpty(D)) {
		printf("EMPTY!\n");
	}
	else {
		D->front = (D->front + 1) % N;
		return D->queue[D->front];
	}
}
element deleteRear(DequqType* D) {
	if (isEmpty(D)) {
		printf("EMPTY!\n");
	}
	else {
		int pos = D->rear;
		D->rear = (D->rear - 1 + N) % N;
		return D->queue[pos];
	}
}

element getFront(DequqType* D) {
	if (isEmpty(D)) {
		printf("EMPTY!\n");
		return -1;
	}
	else {
		return D->queue[((D->front) + 1)%N];
	}
}

element getRear(DequqType* D) {
	if (isEmpty(D)) {
		printf("EMPTY!\n");
		return -1;
	}
	else {
		return D->queue[D->rear];
	}
}
void print(DequqType* D)
{
	int i = D->front;
	while (i != D->rear)
	{
		i = (i + 1) % N;
		printf("%c", D->queue[i]);
	}
}
int main()
{
	DequqType D;
	init(&D);
	char string[N];
	char c,a;
	scanf("%s", string);
	addRear(&D, string[0]);
	for (int i = 1; i < strlen(string); i++) {
		c = getFront(&D);
		a = string[i];
		if (c >= string[i]) {
			addFront(&D, string[i]);
		}
		else {
			addRear(&D, string[i]);
		}
	}
	print(&D);
	return 0;
}