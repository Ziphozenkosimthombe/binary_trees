#include "binary_trees.h"

/*
 * binary_tree_insert_right - insert the node as a right-child
 * of another in binary tree.
 * @parent: pointer to the node to insert the right-child.
 * @value: value to store in the new node
 * Return: if parent is NULL - NULL.
 * else - pointer to the created node
 *
 * Description: If parent already has a right-child, the new node
 * must take its place, and the old right-child must be set as
 * the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
