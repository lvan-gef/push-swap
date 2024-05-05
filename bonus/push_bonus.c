/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:08:07 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:08:08 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*node;

	node = pop_node(head_b);
	if (node == NULL)
		return ;
	push_node(head_a, node);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*node;

	node = pop_node(head_a);
	if (node == NULL)
		return ;
	push_node(head_b, node);
}
