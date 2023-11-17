#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

typedef char element;

typedef struct {
	element queue[N];
	int front, rear;
}QueueType;

void init(QueueType* Q)
{
	Q->rear = Q->front = 0;
}

int isEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isFull(QueueType* Q) {
	return (Q->rear+1)%N==Q->front;
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q)) {
		printf("FULL!\n");
	}
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->queue[Q->rear] = e;
	}
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("EMPTY\n");
		return -1;
	}
	else {
		Q->front=(Q->front+1)%N;
		return Q->queue[Q->front];
	}
}

element peek(QueueType* Q) {
	if (isEmpty) {
		printf("EMPTY!\n");
		return -1;
	}
	else {
		return Q->queue[(Q->front) + 1];
	}
}

void print(QueueType* Q)
{
	printf("Front pos: %d, Rear Pos: %d\n", Q->front, Q->rear);
	int i = Q->front;
	while (i != Q->rear) 
	{
		i = (i + 1) % N;
		printf("%c", Q->queue[i]);
	}
}
int main()
{
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
		enqueue(&Q, rand() % 26 + 65);

	print(&Q);

	for (int i = 0; i < 3; i++)
		printf("[%c]", dequeue(&Q));

	printf("\n\n");
	print(&Q);

	return 0;
}