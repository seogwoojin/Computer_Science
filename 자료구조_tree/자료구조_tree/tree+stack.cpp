#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 10

typedef struct
{
	TreeNode* data[N];
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
	return S->top == N-1;
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
typedef int element;

typedef struct TreeNode
{
	element data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->data = data;
	node->left = left;
	node->right = right;

	return node;
}

void preOrder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d]", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(TreeNode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("[%d]", root->data);
		inOrder(root->right);
	}
}

void iterInOrder(TreeNode* root) {
	StackType S;
	init(&S);

	while (1)
	{

	}
}

int main() {
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16, NULL, NULL);
	TreeNode* N7 = makeNode(25, NULL, NULL);
	TreeNode* N2 = makeNode(4, N4, NULL);
	TreeNode* N3 = makeNode(20, N6, N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	preOrder(N1);
}