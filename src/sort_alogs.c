/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_alogs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:47:20 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 13:47:22 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	three_sort(t_node **head, int index0, int index1, int index2)
{
	if (index0 < index1 && index1 > index2 && index2 > index0)
	{
		sa(head);
		ra(head);
	}
	else if (index0 < index1 && index1 > index2 && index2 < index0)
		rra(head);
	else if (index0 > index1 && index1 < index2 && index2 > index0)
		sa(head);
	else if (index0 > index1 && index1 < index2 && index2 < index0)
		ra(head);
	else if (index0 > index1 && index1 > index2 && index2 < index0)
	{
		sa(head);
		rra(head);
	}
}

static	void	sort_three(t_node **head)
{
	int		index0;
	int		index1;
	int		index2;
	t_node	*cur;

	cur = *head;
	if (is_sorted(cur))
		return ;
	if (ll_len(*head) != 3)
		return ;
	index0 = cur->index;
	index1 = cur->next->index;
	index2 = cur->next->next->index;
	three_sort(head, index0, index1, index2);
}

void	sort_five(t_node **head_a, t_node **head_b)
{
	int	size;
	int	sorted;

	sorted = 0;
	size = ll_len(*head_a);
	while (size > 3)
	{
		push_lowest(head_a, head_b);
		if (is_sorted(*head_a))
		{
			sorted = 1;
			break ;
		}
		size--;
	}
	if (sorted == 0)
		sort_three(head_a);
	size = ll_len(*head_b);
	while (size > 0)
	{
		pa(head_a, head_b);
		size--;
	}
}

void	bucket_sort(t_node **head_a, t_node **head_b)
{
	int	counter;
	int	chunk;
	int	bucket_size;

	counter = 0;
	chunk = ll_len(*head_a) / 6;
	bucket_size = chunk;
	while (counter < 6)
	{
		bucket(head_a, head_b, bucket_size);
		bucket_size += chunk;
		counter++;
	}
	while (ll_len(*head_a) > 3)
		push_lowest(head_a, head_b);
	sort_three(head_a);
	counter = ll_len(*head_b);
	while (counter)
	{
		push_highest(head_a, head_b);
		counter--;
	}
}

void	radix(t_node **head_a, t_node **head_b)
{
	int	size;
	int	i;
	int	j;

	size = ll_len(*head_a);
	i = 0;
	while (!is_sorted(*head_a))
	{
		j = 0;
		while (j < size)
		{
			if (((*head_a)->index >> i) & 1)
				ra(head_a);
			else
				pb(head_a, head_b);
			j++;
		}
		while (ll_len(*head_b))
			pa(head_a, head_b);
		i++;
	}
}
