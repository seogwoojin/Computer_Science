#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

typedef char element;

typedef struct{
	element queue[N];
	int front, rear;
}QueueType;

void init(QueueType* Q)
{
	Q->rear = Q->front = -1;
}

int isEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isFull(QueueType* Q) {
	return Q->rear == N - 1;
}

void enqueue(QueueType* Q, element e) {
	if (isFull) {
		printf("FULL!\n");
	}
	else {
		Q->rear++;
		Q->queue[Q->rear] = e;
	}
}

element dequeue(QueueType* Q) {
	if (isEmpty) {
		printf("EMPTY\n");
		return -1;
	}
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peek(QueueType* Q) {
	if (isEmpty) {
		printf("EMPTY!\n");
		return -1;
	}
	else {
		return Q->queue[(Q->front)+1];
	}
}
void print(QueueType* Q)
{
	printf("Front pos: %d", Q->front);
	for (int i = Q->front; i < Q->rear; i++)
		printf("%c ", Q->queue[i]);
}
int main()
{
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
		enqueue(&Q, rand() % 26 + 65);

	print(&Q);
	getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c]", dequeue(&Q));

	printf("\n\n");
	print(&Q);

	return 0;
}