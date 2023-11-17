#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

typedef struct ListType {
	ListNode *H;
}ListType;

void init(ListType* L) {
	L->H = NULL;
}

int isEmpty(ListType* L) {
	return L->H == NULL;
}

void insert_First(ListType* L, element e)
{
	ListNode* node;
	node = (ListNode*)malloc(sizeof(ListNode));
	if (isEmpty(L)) {
		node->next = NULL;
		node->data = e;
		L->H = node;
	}
	else {
		node->next = L->H;
		node->data = e;
		L->H = node;
	}

}

void insert(ListType* L, element e, int pos)
{
	ListNode* p;
	ListNode* q;
	ListNode* node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	p = L->H;
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	if (p->next == NULL) {
		node->next = NULL;
		p->next = node;
	}
	else {
		q = p->next;
		node->next = q;
		p->next = node;
	}
}

void makeSet(ListType* L, element e)
{
	if (isEmpty(L)) {
		insert_First(L, e);
	}
	else {
		ListNode* p = L->H;
		ListNode* q = p->next;
		int pos = 0;
		while (q !=NULL && q->data<e) {
			p = p->next;
			q = p->next;
			pos++;
		}

		if (q != NULL && q->data == e)
			return;
		else if (p->data == e)
			return;
		else if (p->data > e) {
			if (pos == 0) {
				insert_First(L, e);
			}
			else {
				insert(L, e, pos - 1);
			}
		}
		else {
			insert(L, e, pos);
		}

	}

}
void print(ListType* L) {
	ListNode* node = L->H;
	while (node != NULL) {
		printf("%d->", node->data);
		node = node->next;
		
	}
	printf("\n");
}

void intersect(ListType* L1, ListType* L2) {
	ListNode* node1;
	node1 = L1->H;
	ListNode* node2;
	node2 = L2->H;
	int array[10] = { 0, };
	int n = 0;
	int ans[10] = { 0, };
	while (node1 != NULL) {
		array[n] = node1->data;
		n++;
		node1 = node1->next;
	}
	int i = 0;
	while (node2 != NULL) {
		element e = node2->data;
		for (int j = 0; j < 10; j++) {
			if (array[j] == e) {
				ans[i] = e;
				i++;
			}
		}
		node2 = node2->next;
	}
	int k = 0;
	printf("Intersect : {");
	while (ans[k] != 0) {
		printf(" %d,", ans[k]);
		k++;
	}
	printf("}");
}
void Union(ListType* L1, ListType* L2)
{
	ListNode* node1;
	node1 = L1->H;
	ListNode* node2;
	node2 = L2->H;
	int array[10] = { 0, };
	int n = 0;
	int ans1[20] = { 0, };
	int i = 0;

	while (node1 != NULL) {
		array[n] = node1->data;
		ans1[i] = node1->data;
		i++;
		n++;
		node1 = node1->next;
	}


	while (node2 != NULL) {
		element e = node2->data;
		int j = 0;
		for (j; j < 10; j++) {
			if (array[j] == e) {
				break;
			}

		}
		if (j == 10) {
			ans1[i] = e;
			i++;
		}
		node2 = node2->next;
	}
	int k = 0;
	printf("Union : {");
	while(ans1[k]!=0) {
		printf(" %d,", ans1[k]);
		k++;
	}
	printf("}");
} 

int main() {
	ListType L1, L2;
	init(&L1);
	init(&L2);
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		makeSet(&L1, rand() % 30 + 1);
		makeSet(&L2, rand() % 30 + 1);
	}
	print(&L1);
	print(&L2);

	intersect(&L1, &L2);
	Union(&L1, &L2);
	return 0;
}