/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:10:43 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:10:45 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	void	reverse_rotate(t_node **head, int size)
{
	t_node	*node;
	t_node	*tmp_stack;
	t_node	*tmp_node;
	int		i;

	i = 0;
	tmp_stack = NULL;
	while (i < size)
	{
		tmp_node = pop_node(head);
		push_node(&tmp_stack, tmp_node);
		i++;
	}
	node = pop_node(head);
	tmp_node = pop_node(&tmp_stack);
	while (tmp_node)
	{
		push_node(head, tmp_node);
		tmp_node = pop_node(&tmp_stack);
	}
	push_node(head, node);
}

void	rra(t_node **head_a)
{
	int	size;

	size = ll_len(*head_a) - 1;
	reverse_rotate(head_a, size);
}

void	rrb(t_node **head_b)
{
	int	size;

	size = ll_len(*head_b) - 1;
	reverse_rotate(head_b, size);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	int	size;

	size = ll_len(*head_a) - 1;
	reverse_rotate(head_a, size);
	size = ll_len(*head_b) - 1;
	reverse_rotate(head_b, size);
}
