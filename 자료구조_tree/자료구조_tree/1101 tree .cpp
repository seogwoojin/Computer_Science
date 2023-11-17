#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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

void postOrder(TreeNode* root)
{
	if (root != NULL)
	{
		
		postOrder(root->left);
		postOrder(root->right);
		printf("[%d]", root->data);
	}
}

void VRL(TreeNode* node)
{
	printf("%d \n", node->data);
	if(node->left!=NULL)
		VRL(node->left);
	if(node->right!=NULL)
		VRL(node->right);

}

int main() {
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16, NULL, NULL);
	TreeNode* N7 = makeNode(25, NULL, NULL);
	TreeNode* N2 = makeNode(4, N4, NULL);
	TreeNode* N3 = makeNode(20, N6, N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	preOrder(N1);
	printf("\n");
	inOrder(N1);
	printf("\n");
	postOrder(N1);
}