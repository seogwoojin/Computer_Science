#include<string.h>
#include<stdio.h>
#include<malloc.h>

typedef int element;

typedef struct DListNode
{
	struct DListNode* prev;
	struct DListNode* next;
	element data;
}DListNode;

void init(DListNode* H, DListNode* T)
{
	H->next = T;
	T->prev = H;
}

void insert(DListNode* H, int pos, element e) {
	DListNode* p = H;

	for (int i = 1; i < pos; i++)
		p = p->next;

	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = e;
	node->prev = p;
	node->next = p->next;
	p->next->prev = node;
	p->next = node;
}
void Ddelete(DListNode* H, int pos)
{
	DListNode* p = H;

	for (int i = 1; i <= pos; i++)
		p = p->next;

	DListNode* node = (DListNode*)malloc(sizeof(DListNode));


}
int main()
{
	DListNode* H = (DListNode*)malloc(sizeof(DListNode));
	DListNode* T = (DListNode*)malloc(sizeof(DListNode));
}