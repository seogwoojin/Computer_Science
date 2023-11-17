#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

typedef struct
{
	ListNode* tail;
	int size;
}ListType;

void init(ListType* L) {
	L->tail = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->tail == NULL;
}

void insertLast(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;

	if (isEmpty(L))
	{
		node->link = node;
		L->tail = node;
	}
	else
	{
		node->link = L->tail->link;
		L->tail->link = node;
		L->tail = node;
	}
	L->size++;
}

void insertFirst(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;

	if (isEmpty(L))
	{
		node->link = node;
		L->tail = node;
	}
	else
	{	
		node ->link = L->tail->link;
		L->tail->link = node;
	}
	L->size++;
}

void print(ListType* L)
{
	if (isEmpty(L))
		return;
	ListNode* p = L->tail->link;
	for (int i = 1; i <= L->size; i++)
	{
		printf("[%d] -> ", p->data);
		p = p->link;
	}
}

element deleteLast(ListType* L) {
	if (isEmpty(L))
		return -1;
	
	ListNode* p = L->tail;
	ListNode* q = p->link;
	element e = p->data;

	if (p == q)
		L->tail = NULL;
	else
	{
		while (q->link != p)
		{
			q = q->link;
		}
		L->tail = q;
		q->link = p->link;
		element e = q->data;
	}
	L->size--;
	free(q);
	return e;
}


int main()
{
	ListType L;
	init(&L);

	insertFirst(&L, 10);
	insertLast(&L, 5);
	insertFirst(&L, 3);
	print(&L);

	return 0;
}