/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ranking_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:08:35 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:08:38 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	void	rank_it(t_node **head, int nbr, int index)
{
	t_node	*cur;

	cur = *head;
	while (cur != NULL)
	{
		if (cur->nbr == nbr)
		{
			cur->index = index;
			break ;
		}
		cur = cur->next;
	}
}

static	int	get_min(t_node *head)
{
	int	min_val;

	min_val = INT_MAX;
	while (head != NULL)
	{
		if (head->index == -1 && head->nbr < min_val)
			min_val = head->nbr;
		head = head->next;
	}
	return (min_val);
}

void	set_ranking(t_node *head)
{
	int	min_val;
	int	size;
	int	i;

	i = 0;
	size = ll_len(head);
	while (i < size)
	{
		min_val = get_min(head);
		rank_it(&head, min_val, i);
		i++;
	}
}
