/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:44:28 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 13:44:30 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	min_val(t_node **head_a)
{
	int		val;
	t_node	*cur;

	cur = *head_a;
	val = INT_MAX;
	while (cur)
	{
		if (cur->index < val)
			val = cur->index;
		cur = cur->next;
	}
	return (val);
}

static	int	max_val(t_node **head_a)
{
	int		val;
	t_node	*cur;

	cur = *head_a;
	val = INT_MIN;
	while (cur)
	{
		if (cur->index > val)
			val = cur->index;
		cur = cur->next;
	}
	return (val);
}

int	min_index(t_node **head_a)
{
	t_node	*cur;
	int		index;
	int		target;

	index = 0;
	target = min_val(head_a);
	cur = *head_a;
	while (cur)
	{
		if (cur->index == target)
			return (index);
		index++;
		cur = cur->next;
	}
	return (index);
}

int	max_index(t_node **head_a)
{
	t_node	*cur;
	int		index;
	int		target;

	index = 0;
	target = max_val(head_a);
	cur = *head_a;
	while (cur)
	{
		if (cur->index == target)
			return (index);
		index++;
		cur = cur->next;
	}
	return (index);
}
