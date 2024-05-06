/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:47:20 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/06 02:45:17 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_command
{
	char				*cmd;
	struct s_command	*next;
}	t_command;

// free_it.c
void		free_array(char **elements);
void		free_ll(t_node **head);
void		free_cmds(t_command **head);

// handle_exit.c
void		exit_ps(t_node **head_a, t_node **head_b,
				t_command **cmds, int rtn_code);
void		init_error(t_node **head);
void		create_node_error(t_node **head);
void		create_cmd_error(t_command **command, t_node **head);
void		invalid_cmd_error(t_command **cmds, t_node **head_a,
				t_node **head_b);

// ll_bonus.c
void		push_node(t_node **head, t_node *node);
t_node		*pop_node(t_node **head);
void		create_node(t_node **head, int nbr);
int			ll_len(t_node *head);

// ll_cmd_bonus.c
void		create_cmd(t_command **cmds, t_node **head, const char *cmd);

// push_bonus.c
void		pa(t_node **head_a, t_node **head_b);
void		pb(t_node **head_a, t_node **head_b);

// ranking_bonus.c
void		set_ranking(t_node *head);

// read_args_bonus.c
void		read_args(t_node **head, int argc, char **argv);

// reverse_rotate_bonus.c
void		rra(t_node **head_a);
void		rrb(t_node **head_b);
void		rrr(t_node **head_a, t_node **head_b);

// rotate_bonus.c
void		ra(t_node **head_a);
void		rb(t_node **head_b);
void		rr(t_node **head_a, t_node **head_b);

// run_cmds_bonus.c
void		run_commands(t_command **cmds, t_node **head_a, t_node **head_b);

// swap_bonus.c
void		sa(t_node **head_a);
void		sb(t_node **head_b);
void		ss(t_node **head_a, t_node **head_b);

// utils_bonus.c
int			arr_len(char **arr);
bool		is_sorted(t_node *head);

// valid_numbers_bonus.c
bool		is_number(const char *str);
bool		in_bound(long int nbr);

#endif
