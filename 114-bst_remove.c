#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *inorder_successor(bst_t *root);

/**
 * inorder_successor - return min value of the binary.
 * @root: pointer to the root node.
 *
 *  Return: min value in tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - deletes a node from a binary.
 *  @root: pointer to the root node.
 *  @node: pointer to the node to delete from.
 *
 *  Return: pointer to the new root node.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - the node from the binary search will remove.
 * @root: pointer to the rrot node of BST.
 * @node: pointer to the current node in BST.
 * @value: value to remove from.
 *
 * Return: pointer to the root node.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the BST.
 * @value: value to remove in the BST.
 *
 * Return:  pointer to the new root node of the tree after,
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
