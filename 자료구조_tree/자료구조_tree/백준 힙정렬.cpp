#include<stdio.h>
#include<stdlib.h>
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

	while ((i != 1) && (key > H->heap[i / 2]))
	{
		H->heap[i] = H->heap[i / 2];
		i /= 2;
	}
	H->heap[i] = key;
}

void upFirst(HeapType* H)
{
	int i = H->heapSize;
	int temp;
	while (i != 1)
	{
		temp = H->heap[i];
		H->heap[i] = H->heap[i / 2];
		H->heap[i / 2] = temp;
		i /= 2;
	}
}

void InsertHeap(HeapType* H, int key)
{
	H->heapSize++;
	H->heap[H->heapSize] = 1;
	H->heap[1] = key;
}

void downHeap(HeapType* H)
{
	element key = H->heap[1];
	int parent = 1, child = 2;

	while (child <= H->heapSize)
	{
		if ((child < H->heapSize) && (H->heap[child] < H->heap[child + 1]))
		{
			child++;
		}
		if (key >= H->heap[child]) break;

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
		printf("%d ", H->heap[i]);
	}
}
int main() {
	HeapType H;
	init(&H);

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		InsertHeap(&H, i);
		upFirst(&H);
	}
	InsertHeap(&H, n);

	print(&H);


	return 0;
}