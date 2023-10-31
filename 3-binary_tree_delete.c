#include "binary_trees.h"

/*
 * binary_tree_delete - this delete a binary tree.
 * @tree: this is the pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
