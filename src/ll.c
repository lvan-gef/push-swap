/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:48:41 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/06 17:54:20 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	push_node(t_node **head, t_node *node)
{
	node->next = *head;
	if (*head == NULL)
		*head = node;
	else
		*head = node;
}

t_node	*pop_node(t_node **head)
{
	t_node	*node;

	if (*head == NULL)
		return (NULL);
	node = *head;
	*head = node->next;
	node->next = NULL;
	return (node);
}

void	create_node(t_node **head, int nbr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		create_node_error(head);
	else
	{
		new->nbr = nbr;
		new->index = -1;
		new->next = NULL;
		push_node(head, new);
	}
}

int	ll_len(t_node *head)
{
	int	counter;

	counter = 0;
	if (head == NULL)
		return (counter);
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
