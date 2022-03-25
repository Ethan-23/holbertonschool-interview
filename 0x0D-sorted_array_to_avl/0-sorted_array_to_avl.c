#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Prints an array of integers
 *
 * @array: Given Array
 * @size: Size of the array
 */

avl_t *sortedArray(int *arr, int start, int end, avl_t *par)
{
    avl_t *root;
    int mid;

    if (start > end)
        return (NULL);
    
    mid = (start + end) / 2;
    root = malloc(sizeof(avl_t));
    if (root == NULL)
        return (NULL);
    root->n = arr[mid];
    root->left = NULL;
    root->right = NULL;
    root->parent = par;

    root->left = sortedArray(arr, start, mid - 1, root);
    root->right = sortedArray(arr, mid + 1, end, root);
    
    return(root);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    return(sortedArray(array, 0, (int)size - 1, NULL));
}