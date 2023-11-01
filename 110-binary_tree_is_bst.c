#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - checks if binary tree is valid binary.
 * @tree: pointer to the root node.
 * @lo: smallest node visited.
 * @hi: largest node visited.
 *
 * Return: 1 if tree is valid BST
 * else - return 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: return 1 if tree is a valid BST,
 * else - return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
