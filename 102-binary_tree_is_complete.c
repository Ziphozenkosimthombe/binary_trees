#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
int binary_tree_is_complete(const binary_tree_t *tree);

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
 * push - push node to the back of a levelorder_queue_t.
 * @node: binary tree node to print and push.
 * @head: pointer to the head of queue.
 * @tail: pointer to the tail of the queue.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
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
 * binary_tree_is_complete -  checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to traverse.
 *
 * Return: If tree is NULL, your function must return 0.
 * else - return 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *heads, *tails;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	heads = tails = create_node((binary_tree_t *)tree);
	if (heads == NULL)
		exit(1);

	while (heads != NULL)
	{
		if (heads->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(heads);
				return (0);
			}
			push(heads->node->left, heads, &tails);
		}
		else
			flag = 1;
		if (heads->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(heads);
				return (0);
			}
			push(heads->node->right, heads, &tails);
		}
		else
			flag = 1;
		pop(&heads);
	}
	return (1);
}


