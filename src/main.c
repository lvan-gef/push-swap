/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:51:15 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/07 21:33:37 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		size;

	if (argc < 2)
		return (1);
	head_a = NULL;
	head_b = NULL;
	read_args(&head_a, argc, argv);
	set_ranking(head_a);
	if (is_sorted(head_a))
		exit_ps(&head_a, NULL, 0);
	size = ll_len(head_a);
	if (size == 2)
		sa(&head_a);
	else if (size < 13)
		sort_five(&head_a, &head_b);
	else if (size < 101)
		bucket_sort(&head_a, &head_b);
	else
	{
		radix(&head_a, &head_b);
	}
	exit_ps(&head_a, &head_b, 0);
}
