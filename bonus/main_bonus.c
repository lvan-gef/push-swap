/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:07:18 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:07:19 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static	void	user_input(t_command **cmds, t_node **head_a)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		create_cmd(cmds, head_a, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_node		*head_a;
	t_node		*head_b;
	t_command	*cmds;

	if (argc < 2)
		return (1);
	head_a = NULL;
	head_b = NULL;
	cmds = NULL;
	read_args(&head_a, argc, argv);
	set_ranking(head_a);
	user_input(&cmds, &head_a);
	run_commands(&cmds, &head_a, &head_b);
	if (ll_len(head_b) != 0)
		ft_printf("KO\n");
	else
	{
		if (is_sorted(head_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	exit_ps(&head_a, &head_b, &cmds, 0);
	return (0);
}
