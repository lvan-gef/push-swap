/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 19:30:29 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/06 02:17:10 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// bucker_utils.c
void		bucket(t_node **head_a, t_node **head_b, int bucket_size);

// free_it.c
void		free_array(char **elements);
void		free_ll(t_node **head);

// get_index.c
int			min_index(t_node **head_a);
int			max_index(t_node **head_a);

// handle_exit.c
void		exit_ps(t_node **head_a, t_node **head_b, int rtn_code);
void		init_error(t_node **head);
void		create_node_error(t_node **head);

// ll.c
void		push_node(t_node **head, t_node *node);
t_node		*pop_node(t_node **head);
void		create_node(t_node **head, int nbr);
int			ll_len(t_node *head);

// push.c
void		pa(t_node **head_a, t_node **head_b);
void		pb(t_node **head_a, t_node **head_b);

// ranking.c
void		set_ranking(t_node *head);

// read_args.c
void		read_args(t_node **head, int argc, char **argv);

// reverse_rotate.c
void		rra(t_node **head_a);
void		rrb(t_node **head_b);
void		rrr(t_node **head_a, t_node **head_b);

// rotate.c
void		ra(t_node **head_a);
void		rb(t_node **head_b);
void		rr(t_node **head_a, t_node **head_b);

// sort_alogs.c
void		sort_five(t_node **head_a, t_node **head_b);
void		bucket_sort(t_node **head_a, t_node **head_b);
void		radix(t_node **head_a, t_node **head_b);

// sort_utils.c
void		push_lowest(t_node **head_a, t_node **head_b);
void		push_highest(t_node **head_a, t_node **head_b);

// swap.c
void		sa(t_node **head_a);
void		sb(t_node **head_b);
void		ss(t_node **head_a, t_node **head_b);

// utils.c
int			arr_len(char **arr);
bool		is_sorted(t_node *head);

// valid_numbers.c
bool		is_number(const char *str);
bool		in_bound(long int nbr);

#endif
