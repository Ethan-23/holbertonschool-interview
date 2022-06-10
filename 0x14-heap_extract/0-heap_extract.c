#include "binary_trees.h"

/**
* binary_tree_size - measures the size of a binary tree from a given node
* @tree: tree is a pointer to the given node to find the size of
* Return: returns the size of the tree from the given node
*/
unsigned int binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * get_last - Finds the last node in the heap
 * @root: given root
 * Return: heap of final node
 */
heap_t *get_last(heap_t *root)
{
	unsigned int count, binary = 1;

	count = binary_tree_size(root);
	while (count / binary > 1)
		binary = binary << 1;
	binary = binary >> 1;

	while (binary)
	{
		if (count & binary)
			root = root->right;
		else
			root = root->left;
		binary = binary >> 1;
	}
	return (root);
}

/**
 * heap_reorder - reorders the heap
 * @root: root
 */
void heap_reorder(heap_t *root)
{
	heap_t *swap = root;
	int temp;

	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				swap = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				swap = root->right;
		}
	}
	else if (root->left && root->left->n > root->n)
		swap = root->left;
	else if (root->right && root->right->n > root->n)
		swap = root->right;

	if (swap != root)
	{
		temp = root->n;
		root->n = swap->n;
		swap->n = temp;
		heap_reorder(swap);
	}
}


/**
 * heap_extract - extracts the root of a give heap
 * @root: given root node to extract
 * Return: new root / 0 on fail
 */

int heap_extract(heap_t **root)
{
	heap_t *lastnode;
	int extracted;

	if (root == NULL || *root == NULL)
		return (0);
	lastnode = get_last(*root);
	extracted = (*root)->n;
	if (lastnode == *root)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		if (lastnode->parent->left == lastnode)
			lastnode->parent->left = NULL;
		else
			lastnode->parent->right = NULL;
		lastnode->parent = NULL;

		if ((*root)->left == lastnode)
			lastnode->left = NULL;
		else
			lastnode->left = (*root)->left;
		if ((*root)->right == lastnode)
			lastnode->right = NULL;
		else
			lastnode->right = (*root)->right;

		if (lastnode->left != NULL)
			lastnode->left->parent = lastnode;
		if (lastnode->right != NULL)
			lastnode->right->parent = lastnode;
		free(*root);
		*root = lastnode;
		heap_reorder(lastnode);
	}
	return (extracted);
}
