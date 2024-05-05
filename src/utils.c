/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:59:26 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/17 18:25:01 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	arr_len(char **arr)
{
	int	index;

	index = 0;
	if (!arr)
		return (index);
	while (arr[index])
		index++;
	return (index);
}

bool	is_sorted(t_node *head)
{
	int	index;

	if (head == NULL)
		return (true);
	index = head->index;
	while (head != NULL)
	{
		if (index != head->index)
			return (false);
		index++;
		head = head->next;
	}
	return (true);
}
