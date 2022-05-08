/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:01:40 by junylee           #+#    #+#             */
/*   Updated: 2022/05/08 17:03:46 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str)
{
	if (pthread_mutex_lock(&(philo->info->mutex_print)) == 0)
	{
		printf("%lu\t%d\t%s\n",
			get_time_ms() - philo->info->start_time,
			philo->num, str);
		pthread_mutex_unlock(&(philo->info->mutex_print));
	}
}

int	print_error(char *str)
{
	printf("%s", str);
	return (1);
}

size_t	get_time_ms(void)
{
	struct timeval	tv;
	size_t			ms;

	gettimeofday(&tv, NULL);
	ms = (size_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}
