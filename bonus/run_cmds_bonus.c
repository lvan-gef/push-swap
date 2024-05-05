/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmds_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:14:43 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:14:44 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	bool	check_a(t_node **head_a, t_node **head_b,
		char *cmd, size_t str_len)
{
	if (!ft_strncmp(cmd, "sa\n", str_len))
	{
		sa(head_a);
		return (true);
	}
	else if (!ft_strncmp(cmd, "pa\n", str_len))
	{
		pa(head_a, head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "ra\n", str_len))
	{
		ra(head_a);
		return (true);
	}
	else if (!ft_strncmp(cmd, "rra\n", str_len))
	{
		rra(head_a);
		return (true);
	}
	return (false);
}

static	bool	check_b(t_node **head_a, t_node **head_b,
		char *cmd, size_t str_len)
{
	if (!ft_strncmp(cmd, "sb\n", str_len))
	{
		sb(head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "pb\n", str_len))
	{
		pb(head_a, head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "rb\n", str_len))
	{
		rb(head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "rrb\n", str_len))
	{
		rrb(head_b);
		return (true);
	}
	return (false);
}

static	bool	check_x(t_node **head_a, t_node **head_b,
		char *cmd, size_t str_len)
{
	if (!ft_strncmp(cmd, "ss\n", str_len))
	{
		ss(head_a, head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "rr\n", str_len))
	{
		rr(head_a, head_b);
		return (true);
	}
	else if (!ft_strncmp(cmd, "rrr\n", str_len))
	{
		rrr(head_a, head_b);
		return (true);
	}
	return (false);
}

static	bool	check_cmd(t_node **head_a, t_node **head_b, char *cmd)
{
	size_t	str_len;

	str_len = ft_strlen(cmd);
	if (str_len < 3)
		return (false);
	else if (str_len > 4)
		return (false);
	if (ft_strrchr(cmd, 'a'))
		return (check_a(head_a, head_b, cmd, str_len));
	else if (ft_strrchr(cmd, 'b'))
		return (check_b(head_a, head_b, cmd, str_len));
	else
		return (check_x(head_a, head_b, cmd, str_len));
	return (false);
}

void	run_commands(t_command **cmds, t_node **head_a, t_node **head_b)
{
	t_command	*cur;

	cur = *cmds;
	while (cur != NULL)
	{
		if (!check_cmd(head_a, head_b, cur->cmd))
		{
			invalid_cmd_error(cmds, head_a, head_b);
			break ;
		}
		cur = cur->next;
	}
}
