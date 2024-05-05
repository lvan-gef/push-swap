/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:11:02 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:11:03 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	void	rotate(t_node **head)
{
	t_node	*node;
	t_node	*tmp_stack;
	t_node	*tmp_node;

	tmp_stack = NULL;
	node = pop_node(head);
	tmp_node = pop_node(head);
	while (tmp_node != NULL)
	{
		push_node(&tmp_stack, tmp_node);
		tmp_node = pop_node(head);
	}
	push_node(head, node);
	tmp_node = pop_node(&tmp_stack);
	while (tmp_node != NULL)
	{
		push_node(head, tmp_node);
		tmp_node = pop_node(&tmp_stack);
	}
}

void	ra(t_node **head_a)
{
	rotate(head_a);
}

void	rb(t_node **head_b)
{
	rotate(head_b);
}

void	rr(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}
