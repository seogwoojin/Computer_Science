#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000010

typedef struct {
	int num;
	char sign;
}element;

int ifint(char e)
{
	if (e >= 48) {

	}
}

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
		return D->queue[((D->front) + 1) % N];
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
	char c, a;
	scanf("%s", string);
	int num[N];
	int k = 0;
	int k1 = 1;
	
	if (string[0] == '-') {
		c = string[k1];
		while (c != '+' && c != '-' && c != '*' && c != '/' && c>=48 && c<=57) {
			num[k++] = (int)(c-48);
			k1++;
			c = string[k1];
		}
		int ret = 0;
		int z = 0;
		for (int j = k - 1; j >= 0; j--) {
			printf("%d %d\n", num[z], j);
			ret+=num[z]*pow(10, j);
			z++;
		}
		printf("%d", -ret);
		addRear(&D, -ret);
	}

	else {
		c = string[0];
		while (c != '+' && c != '-' && c != '*' && c != '/' && c != '\n') {
			num[k++] = int(c);
			k1++;
			c = string[k1];
			printf("%c", c);
		}
	}


	printf("%d", D.queue[1]);
	return 0;
}