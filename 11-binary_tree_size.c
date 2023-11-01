#include "binary_trees.h"

/**
 * binary_tree_size - measures a size of a binary tree.
 * @tree: pointer to the root node of a tree to measure the size.
 *
 * Return: If tree is NULL, the function must return 0.
 * else - return size of a tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
