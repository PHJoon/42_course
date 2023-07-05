/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:03:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 16:07:05 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_loop(void *data)
{
	t_ph	*philo;

	// 세팅
	philo = (t_ph *)data;
	philo->last_eat = philo->info->start_time;

	// 시간 설정되면 루프 돌아가는 뮤텍스
	int	time_flag;

	time_flag = 1;
	if (time_flag)
	{
		pthread_mutex_lock(&philo->info->time_mtx);
		time_flag = 0;
		philo->last_eat = philo->info->start_time;
		pthread_mutex_unlock(&philo->info->time_mtx);
	}

	//먹고
	while (1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->fork_one]);
		if (!print_state(philo, FORK))
			return (NULL);
		pthread_mutex_lock(&philo->info->forks[philo->fork_two]);
		if (!print_state(philo, FORK))
			return (NULL);

		if (!print_state(philo, EAT))
			return (NULL);

		philo->eat_num++;
		philo->last_eat = get_time();

		if (philo->info->max_eat != -1 && philo->eat_num == philo->info->max_eat)
			return (NULL);

		do_time(philo->info->t_eat, philo->info);

		pthread_mutex_unlock(&philo->info->forks[philo->fork_one]);
		pthread_mutex_unlock(&philo->info->forks[philo->fork_two]);

		// 자고
		if (!print_state(philo, SLEEP))
			return (NULL);
		do_time(philo->info->t_sleep, philo->info);

		// 생각하고
		if (!print_state(philo, THINK))
			return (NULL);
		
	}

	return (NULL);
}

int	check_dead_loop(t_ph *philos, t_info *info)
{
	int			i;
	long long	now;

	i = -1;
	usleep(100);
	while (1)
	{
		while (++i < info->n_ph)
		{
			now = get_time();
			if (now - philos[i].last_eat > info->t_eat || info->finish_meal == info->n_ph)
			{
				print_state(&philos[i], DIE);
				return (0);
			}
		}
	}

	return (1);
}
