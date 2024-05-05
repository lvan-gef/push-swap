/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_args.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 16:57:46 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/06 17:53:50 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	bool	is_duplicate(t_node *head, long int nbr)
{
	while (head != NULL)
	{
		if (head->nbr == nbr)
			return (true);
		head = head->next;
	}
	return (false);
}

static	bool	parse_str(t_node **head, char *element)
{
	if (!is_number(element))
	{
		init_error(head);
		return (false);
	}
	if (ft_strlen(element) > 11)
	{
		init_error(head);
		return (false);
	}
	return (true);
}

static	bool	valid_element(t_node **head, char *element)
{
	long int	long_nbr;

	if (!parse_str(head, element))
	{
		init_error(head);
		return (false);
	}
	long_nbr = ft_atoli(element);
	if (!in_bound(long_nbr))
	{
		init_error(head);
		return (false);
	}
	if (is_duplicate(*head, (int)long_nbr))
	{
		init_error(head);
		return (false);
	}
	create_node(head, (int)long_nbr);
	return (true);
}

static	bool	parse_elements(t_node **head, char **elements)
{
	int	i;

	i = arr_len(elements) - 1;
	while (i >= 0)
	{
		if (!valid_element(head, elements[i]))
		{
			init_error(head);
			return (false);
		}
		i--;
	}
	return (true);
}

void	read_args(t_node **head, int argc, char **argv)
{
	char	**elements;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		elements = ft_split(argv[i], ' ');
		if (elements == NULL)
		{
			init_error(head);
			break ;
		}
		if (!parse_elements(head, elements))
		{
			free_array(elements);
			init_error(head);
			break ;
		}
		free_array(elements);
		i--;
	}
}
