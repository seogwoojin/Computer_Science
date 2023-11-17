#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define N 100


typedef int element;

typedef struct {
	element array[N];
	int size;

}ArrayListType;

void init(ArrayListType* L) {
	L->size = 0;
}

int isEmpty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == N;
}

element get_entry(ArrayListType* L, int pos) {
	return L->array[pos];
}

void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

void insertLast(ArrayListType* L, element item)
{
	if (L->size >= N) {
		printf("리스트 오버플로우");
	}
	else {
		L->array[L->size++] = item;
	}
}

element deleteLast(ArrayListType* L)
{
	if (isEmpty) {
		printf("empty List");
		return -1;
	}
	L->size--;
	return L->array[L->size];
}

element del(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->size)
		printf("위치 오류");

	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
}
void print_list(ArrayListType* L)
{
	for (int i = 0; i < L->size; i++) {
		printf("%d -> ", L->array[i]);
	}
	printf("\n");
}

int main() {
	ArrayListType L;
	init(&L);
	insertLast(&L, 10); print_list(&L);
	insertLast(&L, 20); print_list(&L);

	insert(&L, 0, 15); print_list(&L);

	insert(&L, 1, 100); print_list(&L);
	del(&L, 1); print_list(&L);

	return 0;
}