#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#define max(a,b) (((a)>(b))?(a):(b))
typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->key = key;
	node->left = NULL;
	node->right = NULL;
		
	return node;
}

void preOrder(TreeNode* root)
{
	if (root != NULL)
	{
		printf(": [%d] :", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

TreeNode* insertNode(TreeNode* root, element key)
{
	if (root == NULL)
		return makeNode(key);

	if (root->key == key)
		return root;

	else if (root->key > key)
		root->left = insertNode(root->left, key);

	else
		root->right = insertNode(root->right, key);

	return root;

}

TreeNode* minValueNode(TreeNode* root)
{
	TreeNode* p = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
}

TreeNode* deleteNode(TreeNode* root, element key)
{
	if (root == NULL) {
		return NULL;
	}
	if (key < root->key) {
		printf("%d !!\n", root->key);
		root->left = deleteNode(root->left, key);
		return root;
	}
	else if (key > root->key) {
		printf("%d !!\n", root->key);
		root->right = deleteNode(root->right, key);
		return root;
	}
	else
	{
		if (root->left == NULL)
		{
			printf("%d", root->key);
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			TreeNode* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
			return root;
		}
	}
}


int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int main() {
	TreeNode* root = NULL;

	root = insertNode(root, 35); root= insertNode(root, 68);
	root = insertNode(root, 99); root =insertNode(root, 18);
	root = insertNode(root, 7); root =insertNode(root, 3);
	root = insertNode(root, 26); root = insertNode(root, 22);
	root = insertNode(root, 30); root = insertNode(root, 12);
	
	
	preOrder(root); printf("\n");
	deleteNode(root, 26);
	preOrder(root); printf("\n");
	printf("Tree's count = %d\n", get_node_count(root));
	printf("Tree's height = %d\n", get_height(root));
	return 0;
}