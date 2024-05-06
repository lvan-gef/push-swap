/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_number.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 13:49:10 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/06 02:23:53 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_number(const char *str)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!str)
		return (false);
	str_len = ft_strlen(str);
	if (str_len > 11)
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str_len == i)
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	in_bound(long int nbr)
{
	return (nbr >= INT_MIN && nbr <= INT_MAX);
}
