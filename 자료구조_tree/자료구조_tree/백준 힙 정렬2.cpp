#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 100001
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef int element;

typedef struct
{
	element heap[N];
	int heapSize;
}HeapType;

void init(HeapType* H)
{
	H->heapSize = 0;
}

void upHeap(HeapType* H) //스왑 해주는 함수 
{
	int i = H->heapSize;
	element key = H->heap[i];

	while ((i != 1) && (key < H->heap[i / 2]))
	{
		H->heap[i] = H->heap[i / 2];
		i /= 2;
	}
	H->heap[i] = key;
}

void InsertHeap(HeapType* H, int key)
{
	H->heapSize++;
	H->heap[H->heapSize] = key;
	upHeap(H);
}

void downHeap(HeapType* H)
{
	element key = H->heap[1];
	int parent = 1, child = 2;

	while (child <= H->heapSize)
	{
		if ((child < H->heapSize) && (H->heap[child] > H->heap[child + 1]))
		{
			child++;
		}
		if (key <= H->heap[child]) break;

		H->heap[parent] = H->heap[child];
		parent = child;
		child *= 2;
	}
	H->heap[parent] = key;
}

element removeHeap(HeapType* H)
{
	element key = H->heap[1];
	H->heap[1] = H->heap[H->heapSize];
	H->heapSize--;
	downHeap(H);
	return key;

}
void print(HeapType* H)
{
	for (int i = 1; i <= H->heapSize; i++)
	{
		printf("[%d]", H->heap[i]);
	}
	printf("\n");
}

void heapSort(HeapType* H)
{
	int n = H->heapSize;
	int before, after, size=0,  recent;
	before = removeHeap(H);
	if (n == 1) {
		printf("%d", size);
		return;
	}
	after = before+ removeHeap(H);
	size += after;
	
	for (int i = n - 3; i >= 0; i--)
	{
		InsertHeap(H, after);
		before = removeHeap(H);
		after = removeHeap(H);
		after += before;
		size += after;
	}
	printf("%d", size);
}

int main() {
	HeapType H;
	init(&H);

	int n, k;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		InsertHeap(&H, k);
	}

	heapSort(&H);


	return 0;
}