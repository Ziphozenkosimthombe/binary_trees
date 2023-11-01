#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * Return: node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree)
	{
		node += (tree->left || tree->right) ? 1 : 0;
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
	}
	return (node);
}
