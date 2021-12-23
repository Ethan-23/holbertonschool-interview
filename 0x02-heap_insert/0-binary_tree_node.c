#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - inserts node to binary tree
 * @parent: Parent node
 * @value: Value to input to node
 * Return: New Node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}
