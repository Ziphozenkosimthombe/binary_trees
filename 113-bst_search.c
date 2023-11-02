#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree.
 * @tree: pointer to an root node of the BTS.
 * @value: value to search in the tree.
 *
 * Return:  pointer to the node containing a value equals to value.
 * else - If tree is NULL or if nothing is found,
 * your function must return NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
