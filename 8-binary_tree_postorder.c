#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses the binary tree using the post-order
 * travesal.
 * @tree: pointer to the root of the tree to traverse.
 * @func: pointer to the function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
