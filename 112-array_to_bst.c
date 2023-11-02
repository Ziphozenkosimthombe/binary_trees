#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: pointer to a first element of an array.
 * @size: number of the elements in array.
 *
 * Return: pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
