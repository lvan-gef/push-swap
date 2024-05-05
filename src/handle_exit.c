/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_exit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:48:16 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/28 16:48:32 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_ps(t_node **head_a, t_node **head_b, int rtn_code)
{
	free_ll(head_a);
	free_ll(head_b);
	exit(rtn_code);
}

void	init_error(t_node **head)
{
	ft_putendl_fd("Error", 2);
	exit_ps(head, NULL, 1);
}

void	create_node_error(t_node **head)
{
	init_error(head);
}
