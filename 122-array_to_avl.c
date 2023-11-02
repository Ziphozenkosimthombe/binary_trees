#include "binary_trees.h"

/**
 * array_to_avl -  builds an AVL tree from an array.
 * @array: pointer to the first element of the array.
 * @size: number of elements in array.
 *
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
