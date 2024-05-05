/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_number_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 14:17:02 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/16 14:17:03 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

long int	ft_atoli(char *str)
{
	long int	result;
	long int	index;
	int			prefix;

	result = 0;
	prefix = 0;
	index = 0;
	while (ft_strchr(" \t\v\f\r\n", str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			prefix = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	if (prefix < 0)
		result *= prefix;
	return (result);
}

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
