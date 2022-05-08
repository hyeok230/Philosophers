/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:03:54 by junylee           #+#    #+#             */
/*   Updated: 2022/05/08 17:03:56 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_atoi(const char *str)
{
	long	ret;
	long	sign;
	int		i;

	sign = 1;
	i = 0;
	ret = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == FALSE)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (-1);
		ret = ret * 10 + (str[i] - '0');
		if ((ret > 2147483647 && sign == 1) || (ret > 2147483648 && sign == -1))
			return (-1);
		i++;
	}
	return (sign * ret);
}
