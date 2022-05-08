/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:04:04 by junylee           #+#    #+#             */
/*   Updated: 2022/05/08 20:16:51 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_behave(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	philo->count_time = philo->info->start_time;
	while (1)
	{
		philo_get_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(500);
	}
	return ((void *)0);
}

int	run_philo(t_info *info, int p_num)
{
	t_philo		*p;
	pthread_t	tid;

	while (p_num < info->philo_num)
	{
		p = &(info->philo[p_num]);
		if (pthread_create(&tid, NULL, &philo_behave, p))
			return (1);
		pthread_detach(tid);
		p_num += 2;
	}
	if (p_num % 2 == 0)
		usleep(500 * (info->time_eat));
	return (0);
}

int	run_thread(t_info *info)
{
	pthread_t	tid;

	info->start_time = get_time_ms();
	if (run_philo(info, 0) || run_philo(info, 1))
		return (1);
	if (pthread_create(&tid, NULL, &check_philos, info))
		return (1);
	pthread_detach(tid);
	return (0);
}
