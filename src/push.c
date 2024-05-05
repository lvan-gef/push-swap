/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:49:37 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/29 23:10:01 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*node;

	ft_printf("pa\n");
	node = pop_node(head_b);
	if (node == NULL)
		return ;
	push_node(head_a, node);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*node;

	ft_printf("pb\n");
	node = pop_node(head_a);
	if (node == NULL)
		return ;
	push_node(head_b, node);
}
