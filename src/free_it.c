/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_it.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:47:50 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/28 16:47:55 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_array(char **elements)
{
	size_t	i;

	if (!elements)
		return ;
	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

void	free_ll(t_node **head)
{
	t_node	*cur;

	if (head == NULL)
		return ;
	cur = *head;
	if (cur == NULL)
		return ;
	while (cur != NULL)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
}
