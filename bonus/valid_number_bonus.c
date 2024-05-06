/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_number_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:17:02 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/06 02:28:11 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

bool	is_number(char *str)
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
