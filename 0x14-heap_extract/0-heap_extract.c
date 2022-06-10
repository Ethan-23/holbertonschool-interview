#include <stdlib.h>
#include <stdio.h>
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
 * tree_height - Finds the height of a given binary tree
 * @tree: given tree
 * Return: returns total height of tree
 */
size_t tree_height(const heap_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left) + 1;
	right_height = tree_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * find_last_node - Finds the height of a given binary tree
 * @size: size
 * @binary: binary
 * @current_index: current Index
 * Return: returns total height of tree
 */
void find_last_node(unsigned long int size, int *binary, int current_index)
{
	unsigned long int temp = size;

	if (temp == 1)
		return;
	if (temp > 1)
		find_last_node(temp >> 1, binary, current_index - 1);
	binary[current_index] = (temp & 1);
}

/**
 * rm_last_node - Finds the height of a given binary tree
 * @root: given root node
 * Return: returns total height of tree
 */
int rm_last_node(heap_t *root)
{
	int size = binary_tree_size(root);
	heap_t *temp_head = root;
	int height = tree_height(root) - 1;
	int *binary = malloc(sizeof(int) * height);
	int i;
	int hold_n1;

	find_last_node(size, binary, height - 1);

	for (i = 0; i < height; i++)
	{
		if (binary[i] == 1)
			temp_head = temp_head->right;
		else if (binary[i] == 0)
			temp_head = temp_head->left;
	}

	if (binary[i - 1] == 1)
		temp_head->parent->right = NULL;
	else if (binary[i - 1] == 0)
		temp_head->parent->left = NULL;
	hold_n1 = temp_head->n;
	free(temp_head);
	free(binary);

	return (hold_n1);
}


/**
 * heap_extract - extracts the root of a give heap
 * @root: given root node to extract
 * Return: new root / 0 on fail
 */

int heap_extract(heap_t **root)
{
	heap_t *head = NULL;
	int hold_n1, hold_n2;

	if (root == NULL || *root == NULL)
		return (0);

	hold_n1 = rm_last_node(*root);
	head = *root;

	if (head->right == NULL && head->left == NULL)
	{
		hold_n2 = head->n;
		*root = NULL;
		free(head);
		return (hold_n2);
	}

	while (head->right != NULL || head->left != NULL)
	{
		hold_n2 = head->n;
		if (head->right == NULL || head->left->n >= head->right->n)
		{
			head->n = head->left->n;
			head->left->n = hold_n2;
			head = head->left;
		}
		else if (head->left == NULL || head->right->n >= head->left->n)
		{
			head->n = head->right->n;
			head->right->n = hold_n2;
			head = head->right;
		}
		if (head->right == NULL && head->left == NULL)
		{
			head->n = hold_n1;
			return (hold_n2);
		}
	}
	return (0);
}
