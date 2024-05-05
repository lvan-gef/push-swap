/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:46:21 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 13:46:22 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	reverse_rotate(t_node **head, int size)
{
	t_node	*node;
	t_node	*tmp_stack;
	t_node	*tmp_node;
	int		index;

	index = 0;
	tmp_stack = NULL;
	while (index < size)
	{
		tmp_node = pop_node(head);
		push_node(&tmp_stack, tmp_node);
		index++;
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

	ft_printf("rra\n");
	size = ll_len(*head_a) - 1;
	reverse_rotate(head_a, size);
}

void	rrb(t_node **head_b)
{
	int	size;

	ft_printf("rrb\n");
	size = ll_len(*head_b) - 1;
	reverse_rotate(head_b, size);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	int	size;

	ft_printf("rrr\n");
	size = ll_len(*head_a) - 1;
	reverse_rotate(head_a, size);
	size = ll_len(*head_b) - 1;
	reverse_rotate(head_b, size);
}
