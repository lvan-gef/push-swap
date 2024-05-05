/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:59:13 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/01 01:19:40 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_node **head)
{
	t_node	*node_a;
	t_node	*node_b;

	if (ll_len(*head) < 2)
		return ;
	node_a = pop_node(head);
	node_b = pop_node(head);
	push_node(head, node_a);
	push_node(head, node_b);
}

void	sa(t_node **head_a)
{
	ft_printf("sa\n");
	swap(head_a);
}

void	sb(t_node **head_b)
{
	ft_printf("sb\n");
	swap(head_b);
}

void	ss(t_node **head_a, t_node **head_b)
{
	ft_printf("ss\n");
	swap(head_a);
	swap(head_b);
}
