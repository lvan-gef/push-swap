/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_it_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:54:11 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:17:30 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	free_array(char **elements)
{
	size_t	index;

	if (!elements)
		return ;
	index = 0;
	while (elements[index])
	{
		free(elements[index]);
		index++;
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

void	free_cmds(t_command **head)
{
	t_command	*cur;

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
