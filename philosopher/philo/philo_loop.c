/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:03:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 18:20:53 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_down_forks(t_ph *philo, int i)
{
	if (i == 1)
		pthread_mutex_unlock(&philo->info->forks_mtx[philo->fork_one]);
	if (i == 2)
	{
		pthread_mutex_unlock(&philo->info->forks_mtx[philo->fork_one]);
		pthread_mutex_unlock(&philo->info->forks_mtx[philo->fork_two]);
	}
	if (i == 3)
	{
		pthread_mutex_unlock(&philo->info->forks_mtx[philo->fork_one]);
		print_state(philo, DIE);
	}
	return (0);
}

int	do_eat(t_ph *philo)
{
	pthread_mutex_lock(&philo->info->forks_mtx[philo->fork_one]);
	if (!print_state(philo, FORK))
		return (put_down_forks(philo, 1));
	if (philo->info->n_ph == 1)
		return (put_down_forks(philo, 3));
	pthread_mutex_lock(&philo->info->forks_mtx[philo->fork_two]);
	if (!print_state(philo, FORK))
		return (put_down_forks(philo, 2));
	print_state(philo, EAT);
	do_time(philo->info->t_eat, philo->info);
	philo->eat_num++;
	pthread_mutex_lock(&philo->info->die_mtx);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->info->die_mtx);
	if (philo->info->max_eat != -1 && philo->eat_num == philo->info->max_eat)
	{
		pthread_mutex_lock(&philo->info->die_mtx);
		philo->info->finish_meal++;
		pthread_mutex_unlock(&philo->info->die_mtx);
	}
	put_down_forks(philo, 2);
	return (1);
}

int	do_sleep(t_ph *philo)
{
	if (!print_state(philo, SLEEP))
		return (0);
	do_time(philo->info->t_sleep, philo->info);
	return (1);
}

void	*philo_loop(void *data)
{
	t_ph	*philo;
	t_info	*info;

	philo = (t_ph *)data;
	info = philo->info;
	pthread_mutex_lock(&info->time_mtx);
	pthread_mutex_lock(&info->die_mtx);
	philo->last_eat = info->start_time;
	pthread_mutex_unlock(&info->die_mtx);
	pthread_mutex_unlock(&info->time_mtx);
	if (philo->name % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!do_eat(philo))
			return (NULL);
		if (!do_sleep(philo))
			return (NULL);
		if (!print_state(philo, THINK))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

void	check_dead_loop(t_ph *philos, t_info *info)
{
	int			i;

	while (1)
	{
		i = -1;
		while (++i < info->n_ph)
		{
			pthread_mutex_lock(&info->die_mtx);
			if (info->finish_meal == info->n_ph)
			{
				info->die_flag = 1;
				pthread_mutex_unlock(&info->die_mtx);
				return ;
			}
			if (philos[i].last_eat && get_time() - philos[i].last_eat \
			>= info->t_die)
			{
				pthread_mutex_unlock(&info->die_mtx);
				print_state(&philos[i], DIE);
				return ;
			}
			pthread_mutex_unlock(&info->die_mtx);
			usleep(300);
		}
	}
}
