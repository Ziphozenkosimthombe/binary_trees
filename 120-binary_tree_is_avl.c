#include "binary_trees.h"
#include "limits.h"

int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * height - measures the height of binary.
 * @tree: pointer to the root node of the tree to measure.
 *
 * Return: 0 if tree is NULL.
 * else - return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rgt = 0;

		lft = tree->left ? 1 + height(tree->left) : 1;
		rgt = tree->right ? 1 + height(tree->right) : 1;
		return ((lft > rgt) ? lft : rgt);
	}
	return (0);
}

/**
 * is_avl_helper - checks if a binary tree is a valid tree.
 * @tree: pointer to the root node of the tree to check.
 * @lo: smallest node visited.
 * @hi: largest node visited.
 *
 * Return: 1 if the tree is valid AVL tree
 * else - return 0;
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t leftHgt, rightHgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		leftHgt = height(tree->left);
		rightHgt = height(tree->right);
		diff = leftHgt > rightHgt ? leftHgt - rightHgt : rightHgt - leftHgt;

		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl -  checks if a binary tree is a valid AVL Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
