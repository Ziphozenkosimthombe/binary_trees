#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert the node as a left-child
 * of another in binary tree.
 * @parent: pointer to the node to insert the left-child
 * @value: value to store in the new node
 * Return: if parent is NULL - NULL.
 * else - pointer to the created node
 *
 * Decription: If parent already has a left-child, the new node
 * must take its place, and the old left-child must be set as
 * the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
