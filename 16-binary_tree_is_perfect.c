#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - checks if node is a leaf of a binary tree.
 * @node: pointer to node to check.
 *
 * Return: 1, if node is a leaf.
 * else - return 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - gives the depth of given node
 * in a binary tree.
 * @tree: pointer to node to measure the depth.
 *
 * Return: depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - gives leaf of the binary tree.
 * @tree: pointer to a root node of the tree to find a leaf.
 *
 * Return: pointer to first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks if binary tree is perfect recursively.
 * @tree: pointer to root node of tree to check.
 * @leaf_depth: depth of one leaf in the binary tree.
 * @level: level current node.
 *
 * Return: 1, if tree is prefect.
 * else - return 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
			 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to root node of tree to check.
 *
 * Return: If tree is NULL, your function must return 0.
 * else - return 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
