/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:14:00 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/06/27 16:07:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_info	*set_struct(t_philo_info *info)
{
	info->philo_t = (t_philo *)malloc(sizeof(t_philo) * (info->p_num));
	if (!(info->philo_t))
		return (free_atoi(info));
	info->forks = (t_fork *)malloc(sizeof(t_fork) * info->p_num);
	if (!(info->forks))
	{
		free(info->philo_t);
		return (free_atoi(info));
	}
	long long i;
	i = 0;
	while (i < info->p_num)
	{
		pthread_mutex_init(&info->forks[i].fork_mtx, NULL);
		info->forks[i].fork = -1;
		i++;
	}
	info->flag = 0;
	pthread_mutex_init(&info->flag_mtx, NULL);

	return (info);
}

t_philo_info	*set_info(int ac, char **av)
{
	t_philo_info	*info;

	info = (t_philo_info *)malloc(sizeof(t_philo_info));
	if (!info)
		return (NULL);
	info->p_num = ft_atoi(av[1]);
	info->die = ft_atoi(av[2]);
	info->eat = ft_atoi(av[3]);
	info->sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->eat_count = ft_atoi(av[5]);
	else
		info->eat_count = -1;
	info = set_struct(info);
	if (!info)
		return (NULL);
	return (info);
}
