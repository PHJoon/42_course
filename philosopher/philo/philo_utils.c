/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:00:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/06 17:33:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	do_time(long long usleep_time, t_info *info)
{
	long long	start;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&info->die_mtx);
		if (info->die_flag)
		{
			pthread_mutex_unlock(&info->die_mtx);
			break ;
		}
		pthread_mutex_unlock(&info->die_mtx);
		if (get_time() - start >= usleep_time)
			break ;
		usleep(300);
	}
}

void	*destroy_mutex(t_info *info, int state, int idx)
{
	int	i;

	i = -1;
	if (state >= 1)
		pthread_mutex_destroy(&info->print_mtx);
	if (state >= 2)
		pthread_mutex_destroy(&info->die_mtx);
	if (state >= 3)
		pthread_mutex_destroy(&info->time_mtx);
	if (state >= 4)
		pthread_mutex_destroy(&info->eat_mtx);
	if (state >= 5)
	{
		while (++i <= idx)
			pthread_mutex_destroy(&info->forks_mtx[i]);
	}
	free(info->forks_mtx);
	free(info);
	return (NULL);
}

void	destroy_mutex_all(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_ph)
		pthread_mutex_destroy(&info->forks_mtx[i]);
	pthread_mutex_destroy(&info->print_mtx);
	pthread_mutex_destroy(&info->die_mtx);
	pthread_mutex_destroy(&info->time_mtx);
}

void	free_struct(t_ph *philos, t_info *info)
{
	free(philos);
	free(info->forks_mtx);
	free(info);
}
