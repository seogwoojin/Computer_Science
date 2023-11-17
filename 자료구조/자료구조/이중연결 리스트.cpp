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

void init(DListNode* DL)
{
	DL->data = NULL;
	DL->prev = DL;
	DL->next = DL;
}

int isEmpty(DListNode* D)
{
	return D->prev == D;
}

void insertFirst(DListNode* D, element e)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode*));
	node->data = e;
	if(isEmpty(D)){
		D->next = node;
		D->prev = node;
		node->next = D;
		node->prev = D;
	}
	else {
		DListNode* p = D->next;
		D->next = node;
		node->next = p;
		node->prev = D;
		p->prev = node;
	}
}

void insertLast(DListNode* D, element e)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode*));
	node->data = e;
	if (isEmpty(D)) {
		D->next = node;
		D->prev = node;
		node->next = D;
		node->prev = D;
	}
	else {
		DListNode* p = D->prev;
		p->next = node;
		node->prev = p;
		node->next = D;
		D->prev = node;
	}
}

element deleteFirst(DListNode* D)
{
	if (isEmpty(D))
		return -1;
	else {
		DListNode* node = D->next;
		element e = node->data;
		
		D->next = node->next;
		DListNode* q = node->next;
		q->prev = D;
		node->next = NULL;
		node->prev = NULL;
		node->data = NULL;

		free(node);
		return e;
	}
}

void print(DListNode* D)
{
	if (isEmpty(D))
		printf("Empty!");

	else {
		DListNode* p = D->next;

		while (p != D) {

			printf("<--%d-->", p->data);
			p = p->next;

		}	
	}
	printf("\n");
}

int main() {

	DListNode head;
	init(&head);

	for (int i = 1; i < 5; i++) {
		insertFirst(&head, i * 3);
	}
	print(&head);

	for (int i = 1; i < 3; i++) {
		insertLast(&head, i * 4);
	}
	print(&head);
	for (int i = 0; i < 3; i++) {
		deleteFirst(&head);
	}
	printf("here");
	print(&head);



	return 0;
}