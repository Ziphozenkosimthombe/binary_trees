#include "binary_trees.h"

/**
 * tree_size - measure the sum of the height.
 * @tree: pointer to the root node of the tree.
 *
 * Return: height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{

	size_t height_left = 0;

	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_size(tree->left);

	if (tree->right)
		height_right = 1 + tree_size(tree->right);

	return (height_left + height_right);
}


/**
 * heap_to_sorted_array - converts a Binary Max Heap to a,
 * sorted array of integers.
 * @heap: pointer to the root node of the heap.
 * @size: address to store the size of the array.
 *
 * Return: array must be sorted in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int a, *b = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	b = malloc(sizeof(int) * (*size));

	if (!b)
		return (NULL);

	for (a = 0; heap; a++)
		b[a] = heap_extract(&heap);
	return (b);
}
