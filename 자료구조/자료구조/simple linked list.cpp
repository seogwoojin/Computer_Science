#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef char element;

typedef struct ListNode {

	element data;
	ListNode* next; //struct?
	
}ListNode; //자기 참조 구조체

typedef struct ListType{
	ListNode* head;
	int size; //node의 개수 없어도됨
}ListType;

void init(ListType* L)
{
	L->head = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->head == NULL;
}

void insertFirst(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = L->head;
	L->head = node;
	L->size++;

	/*
	ListNode N;
	N.data = e;
	N.next = L->head;
	L->head = &N;
	L->size++;
	*/
}

void insertLast(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;

	if (isEmpty)
		L->head = node;

	else {
		ListNode* p = L->head;
		while (p->next != NULL)
			p = p->next;

		p->next = node;
	}

	L->size++;
}

void print(ListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->next) {
		printf("%c => ", p->data);
	}
	printf("\b\b\b  \n"); //마지막 화살표 삭제
}

void insert(ListType* L, int pos, element e) {
	if (pos == 1)
		insertFirst(L, e);

	else if (pos == L->size + 1)
		insertLast(L, e);

	else
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = e;
		ListNode* p = L->head;

		for (int i = 1; i < pos - 1; i++) {
			p = p->next;
		}

		node->next = p->next;
		p->next = node;
		L->size++;
	}

}

element deleteFirst(ListType* L)
{
	if (isEmpty(L))
		printf("empty!");
	else
	{
		ListNode* p = L->head;
		element e = p->data;
		L->head = p->next;

		free(p);
		L->size--;

		return e;
	}
}

element deletePosition(ListType* L, int pos)
{
	if (isEmpty(L)) {
		printf("empty!");
		return -1;
	}

	else
	{
		ListNode* p = L->head; //현재 노드
		ListNode* q = NULL; //이전 노드
		element e;

		if (pos == 1)
			e = deleteFirst(L);

		else
		{
			for (int i = 1; i < pos; i++)
			{
				q = p;
				p = p->next;
			}
			e = p->data;
			q->next = p->next;
			free(p);
			L->size--;

		}
		return e;
	}
}

int main() {
	ListType L;
	init(&L);

	insertLast(&L, 'E'); print(&L);
	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);

	insertLast(&L, 'C'); print(&L);

	insertLast(&L, 'E'); print(&L);


	return 0;
}