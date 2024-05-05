/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:48:09 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 13:48:17 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	rotate_dir(t_node **head_a, t_node **head_b, int index, int dir)
{
	while (index > 0)
	{
		if (dir == 1)
			rra(head_a);
		else if (dir == 2)
			ra(head_a);
		else if (dir == 3)
			rrb(head_b);
		else if (dir == 4)
			rb(head_b);
		index--;
	}
	if (dir == 1 || dir == 2)
		pb(head_a, head_b);
	else if (dir == 3 || dir == 4)
		pa(head_a, head_b);
}

void	push_lowest(t_node **head_a, t_node **head_b)
{
	int	index;
	int	middle;

	index = min_index(head_a);
	middle = ll_len(*head_a) / 2;
	if (index == 0)
		pb(head_a, head_b);
	else if (index == ll_len(*head_a) - 1)
	{
		rra(head_a);
		pb(head_a, head_b);
	}
	else if (index > middle)
	{
		index = ll_len(*head_a) - index;
		rotate_dir(head_a, head_b, index, 1);
	}
	else
		rotate_dir(head_a, head_b, index, 2);
}

void	push_highest(t_node **head_a, t_node **head_b)
{
	int	index;
	int	middle;

	index = max_index(head_b);
	middle = ll_len(*head_b) / 2;
	if (index == 0)
		pa(head_a, head_b);
	else if (index == ll_len(*head_b) - 1)
	{
		rrb(head_b);
		pa(head_a, head_b);
	}
	else if (index < middle)
		rotate_dir(head_a, head_b, index, 4);
	else
	{
		index = ll_len(*head_b) - index;
		rotate_dir(head_a, head_b, index, 3);
	}
}
