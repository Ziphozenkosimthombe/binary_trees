#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST.
 * @value: store value in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->left = new);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->right = new);
		}
	}
	return (NULL);
}
