/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:03:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 18:15:22 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_loop(void *data)
{
	t_ph	*philo;

	// 세팅
	philo = (t_ph *)data;
	philo->last_eat = philo->info->start_time;

	pthread_mutex_lock(&philo->info->time_mtx);
	pthread_mutex_unlock(&philo->info->time_mtx);

	//먹고
	while (1)
	{
		if (philo->name % 2 == 0)
			usleep(200);
		pthread_mutex_lock(&philo->info->forks[philo->fork_one]);
		print_state(philo, FORK);
		pthread_mutex_lock(&philo->info->forks[philo->fork_two]);
		print_state(philo, FORK);

		if (!print_state(philo, EAT))
		{
			pthread_mutex_unlock(&philo->info->forks[philo->fork_one]);
			pthread_mutex_unlock(&philo->info->forks[philo->fork_two]);
			return (NULL);
		}

		philo->eat_num++;
		pthread_mutex_lock(&philo->info->eat_mtx);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->info->eat_mtx);

		if (philo->info->max_eat != -1 && philo->eat_num == philo->info->max_eat)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->fork_one]);
			pthread_mutex_unlock(&philo->info->forks[philo->fork_two]);

			return (NULL);
		}

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
		usleep(200);
	}

	return (NULL);
}

int	check_dead_loop(t_ph *philos, t_info *info)
{
	int	i;

	while (1)
	{
		// pthread_mutex_lock(&info->die);
		if (!info->die_flag && info->finish_meal == info->n_ph)
		{
			// pthread_mutex_unlock(&info->die);
			return (0);
		}
		i = -1;
		while (++i < info->n_ph)
		{
			pthread_mutex_lock(&info->eat_mtx);
			if (philos[i].last_eat && get_time() - philos[i].last_eat >= info->t_die)
			{
				pthread_mutex_unlock(&info->eat_mtx);
				// pthread_mutex_unlock(&info->die);
				print_state(&philos[i], DIE);
				return (0);
			}
			pthread_mutex_unlock(&info->eat_mtx);
		}
		usleep(200);
	}

	return (1);
}
