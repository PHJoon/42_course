/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:59:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 14:06:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*mutex_init(t_info *info)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&info->print_mtx, NULL))
		return (destroy_mutex(info, 0, 0));
	if (pthread_mutex_init(&info->die_mtx, NULL))
		return (destroy_mutex(info, 1, 0));
	if (pthread_mutex_init(&info->time_mtx, NULL))
		return (destroy_mutex(info, 2, 0));
	info->forks_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->n_ph);
	if (!info->forks_mtx)
		return (destroy_mutex(info, 3, 0));
	while (++i < info->n_ph)
	{
		if (pthread_mutex_init(&info->forks_mtx[i], NULL))
			return (destroy_mutex(info, 4, i));
	}
	return (info);
}

t_info	*set_info(int ac, char **av)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->n_ph = (int)ft_atoll(av[1]);
	info->t_die = (int)ft_atoll(av[2]);
	info->t_eat = (int)ft_atoll(av[3]);
	info->t_sleep = (int)ft_atoll(av[4]);
	info->finish_meal = 0;
	info->must_eat = -1;
	info->die_flag = 0;
	if (ac == 6)
		info->must_eat = (int)ft_atoll(av[5]);
	info = mutex_init(info);
	if (!info)
		return (NULL);
	return (info);
}

t_ph	*set_ph(t_info *info)
{
	t_ph	*philos;
	int		i;

	i = -1;
	philos = (t_ph *)malloc(sizeof(t_ph) * info->n_ph);
	if (!philos)
		return (NULL);
	while (++i < info->n_ph)
	{
		philos[i].name = i + 1;
		philos[i].eat_num = 0;
		philos[i].last_eat = 0;
		philos[i].fork_one = (i + 1) % (info->n_ph);
		philos[i].fork_two = i % info->n_ph;
		if (i % 2 == 1 || (i % 2 == 0 && i == info->n_ph - 1))
		{
			philos[i].fork_one = i % info->n_ph;
			philos[i].fork_two = (i + 1) % (info->n_ph);
		}
		philos[i].info = info;
	}
	info->philos = philos;
	return (philos);
}
