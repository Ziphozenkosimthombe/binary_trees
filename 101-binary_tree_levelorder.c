#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - creates a new levelorder_queue_t.
 * @node: binary tree for the new node.
 *
 * Return: NULL, if an error occurs.
 * else - return pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - fees levelorder_queue_t.
 * @head: pointer to the head of queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - the function on the given binary tree node and
 * push it's children.
 * @node: binary tree node to print and push.
 * @head: pointer to the head of the queue.
 * @tail: pointer to the tail of the queue.
 * @func: pointer to the function to call on @node.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}

}

/**
 * pop - pops head of a levelorder_queue_t.
 * @head: pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - goes through a binary tree using,
 * level-order traversal.
 * @tree: pointer to the  root node of the tree to traverse.
 * @func: pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *heads, *tails;

	if (tree == NULL || func == NULL)
		return;

	heads = tails = create_node((binary_tree_t *)tree);
	if (heads == NULL)
		return;

	while (heads != NULL)
	{
		pint_push(heads->node, heads, &tails, func);
		pop(&heads);
	}
}
