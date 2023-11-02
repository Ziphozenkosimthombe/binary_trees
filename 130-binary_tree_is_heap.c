#include <stddef.h>
#include "binary_trees.h"

int btih_helper(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - check if a binary tree is valid.
 * @tree: pointer to the node of the tree.
 *
 * Return: return 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - checks if a binary tree is valid.
 * @tree: pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid.
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if the binary tree is complete.
 * @tree: pointer to the root of the node tree to check
 *
 * Return: 1if the tree is complete.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - checks if binary is complete.
 * @tree: pointer to the root node of the tree to check
 * @index: node index to check.
 * @size: number of node in the tree
 *
 * Return: 1 if the tree is complete.
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measure the size of binary tree.
 * @tree: tree to be measured.
 *
 * Return: size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
