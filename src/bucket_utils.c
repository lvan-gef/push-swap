/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:42:53 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 13:43:36 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_to_b(t_node **head_a, t_node **head_b, int index, int middle)
{
	if (index == 0)
		pb(head_a, head_b);
	else
	{
		if (index < middle)
		{
			while (index > 0)
			{
				ra(head_a);
				index--;
			}
			pb(head_a, head_b);
		}
		else
		{
			index = ll_len(*head_a) - index;
			while (index > 0)
			{
				rra(head_a);
				index--;
			}
			pb(head_a, head_b);
		}
	}
}

static	bool	bucket_full(t_node **head, int bucket_size)
{
	t_node	*cur;

	cur = *head;
	while (cur != NULL)
	{
		if (cur->index <= bucket_size)
			return (false);
		cur = cur->next;
	}
	return (true);
}

void	bucket(t_node **head_a, t_node **head_b, int bucket_size)
{
	t_node	*cur;
	int		index;
	int		size;
	int		middle;

	while (!bucket_full(head_a, bucket_size))
	{
		cur = *head_a;
		index = 0;
		size = ll_len(*head_a);
		middle = size / 2;
		while (index < size)
		{
			if (cur->index <= bucket_size)
			{
				move_to_b(head_a, head_b, index, middle);
				break ;
			}
			cur = cur->next;
			index++;
		}
	}
}
