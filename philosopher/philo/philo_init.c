/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:59:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 16:01:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*set_info(int ac, char **av)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->n_ph = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->max_eat = -1;
	if (ac == 6)
		info->max_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&info->print, NULL) == -1)
	{
		free(info);
		return (NULL);
	}
	if (pthread_mutex_init(&info->die, NULL) == -1)
	{
		free(info);
		pthread_mutex_destroy(&info->print);
		return (NULL);
	}

	if (pthread_mutex_init(&info->time_mtx, NULL) == -1)
	{
		// free
		return (NULL);
	}
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n_ph);
	int	i;
	i = -1;
	while (++i < info->n_ph)
		pthread_mutex_init(&info->forks[i], NULL);
		// 뮤텍스 init 실패 로직 추가
	return (info);
}

t_ph	*set_ph(t_info *info)
{
	t_ph	*philos;

	philos = (t_ph *)malloc(sizeof(t_ph) * info->n_ph);
	if (!philos)
		return (NULL);
	int i;
	i = -1;
	while (++i < info->n_ph)
	{
		philos[i].name = i + 1;
		philos[i].eat_num = 0;
		philos[i].last_eat = 0;
		philos[i].fork_one = (i + 1) % (info->n_ph + 1);
		philos[i].fork_two = i;
		if (i % 2 == 1)
		{
			philos[i].fork_one = i;
			philos[i].fork_two = (i + 1) % (info->n_ph + 1);
		}
		philos[i].info = info;
	}
	info->philos = philos;
	return (philos);
}