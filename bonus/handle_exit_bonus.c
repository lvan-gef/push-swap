/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_exit_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 18:21:50 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/17 18:21:54 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	exit_ps(t_node **head_a, t_node **head_b,
				t_command **cmds, int rtn_code)
{
	free_ll(head_a);
	free_ll(head_b);
	free_cmds(cmds);
	exit(rtn_code);
}

void	init_error(t_node **head)
{
	ft_putendl_fd("Error", 2);
	exit_ps(head, NULL, NULL, 1);
}

void	create_node_error(t_node **head)
{
	init_error(head);
}

void	create_cmd_error(t_command **command, t_node **head)
{
	free_cmds(command);
	init_error(head);
}

void	invalid_cmd_error(t_command **cmds, t_node **head_a,
		t_node **head_b)
{
	free_cmds(cmds);
	free_ll(head_b);
	init_error(head_a);
}
