/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll_cmd_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:06:27 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:06:29 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	void	add_node(t_command **cmds, t_command *cmd)
{
	t_command	*cur;

	if (!cmd)
		return ;
	cur = NULL;
	if (*cmds == NULL)
		*cmds = cmd;
	else
	{
		cur = *cmds;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = cmd;
	}
}

void	create_cmd(t_command **cmds, t_node **head, char *cmd)
{
	t_command	*new;
	size_t		str_len;

	new = (t_command *)malloc(sizeof(t_command));
	if (new == NULL)
		create_cmd_error(cmds, head);
	else
	{
		str_len = ft_strlen(cmd);
		new->cmd = ft_calloc(str_len + 1, sizeof(char));
		if (new->cmd == NULL)
			create_cmd_error(cmds, head);
		else
		{
			ft_strlcpy(new->cmd, cmd, str_len + 1);
			new->next = NULL;
			add_node(cmds, new);
		}
	}
}
