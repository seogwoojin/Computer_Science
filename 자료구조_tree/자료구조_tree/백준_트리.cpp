#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define max(a,b) (((a)>(b))?(a):(b))
typedef int element;

typedef struct TreeNode
{
	element key;
	int son;
	struct TreeNode* connect[50];
}TreeNode;

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->key = key;
	node->connect[0] = NULL;
	node->son = 0;

	return node;
}

typedef struct
{
	TreeNode* data[50];
	int top;
}StackType;

void init(StackType* S)
{
	S->top = -1;
}
int isEmpty(StackType* S)
{
	return S->top == -1;
}

int isFull(StackType* S)
{
	return S->top == 49;
}
void push(StackType* S, TreeNode* e)
{
	if (isFull(S))
		return;

	S->top++;
	S->data[S->top] = e;
}

TreeNode* pop(StackType* S)
{
	if (isEmpty(S))
		return NULL;
	TreeNode* e = S->data[S->top];
	S->top--;
	return e;
}

int main() {
	TreeNode* root = makeNode(-1);
	TreeNode* a,*b;
	StackType stack;
	init(&stack);
	push(&stack, root);
	int n;
	char c[1000];
	scanf("%d", &n);
	scanf(" %[^\n]s", c);
	int num[1000];
	int i,remove, size=0;
	char* ptr = strtok(c, " ");
	while (ptr != NULL) {
		i = atoi(ptr);
		num[size] = i;
		size++;
		ptr = strtok(NULL, " ");
	}

	while (!(isEmpty(&stack))) {
		a = pop(&stack);
		for (int k = 0; k < size; k++)
		{
			if (num[k] == a->key) {
				b = makeNode(k);
				push(&stack, b);
				a->connect[a->son] = b;
				a->son++;
			}
		}
	}

	scanf("%d", &remove);
	push(&stack, root);
	while (!(isEmpty(&stack)))
	{
		a = pop(&stack);
		for (int i = 0; i < a->son; i++)
		{
			b = a->connect[i];
			if (b->key == remove)
			{
				for (int j = i; j < a->son - 1; j++)
				{
					a->connect[j] = a->connect[j + 1];
				}
				a->son--;
				break;
			}
			else
				push(&stack, b);
		}
	}

	int leap = 0;
	push(&stack, root);
	while (!(isEmpty(&stack)))
	{
		a = pop(&stack);
		if ((a->son == 0)&&(a->key!=-1))
			leap++;
		else {
			for (int i = 0; i < a->son; i++)
			{
				b = a->connect[i];	
				push(&stack, b);
			}
		}
	}
	printf("%d", leap);


	return 0;
}