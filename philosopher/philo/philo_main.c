/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:18:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/06 18:51:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_av(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 \
	|| ft_atoi(av[4]) <= 0)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (0);
	return (1);
}

int	start_philo(t_ph *philos, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	pthread_mutex_lock(&info->time_mtx);
	while (++i < info->n_ph)
	{
		if (pthread_create(&philos[i].ph, NULL, philo_loop, \
		(void *)&philos[i]))
		{
			while (++j <= i)
				pthread_detach(philos[j].ph);
			return (0);
		}
	}
	info->start_time = get_time();
	pthread_mutex_unlock(&info->time_mtx);
	check_dead_loop(philos, info);
	i = -1;
	while (++i < info->n_ph)
		pthread_join(philos[i].ph, NULL);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_ph	*philos;

	if (!check_av(ac, av))
		return (ft_error("Error!\n"));
	info = set_info(ac, av);
	if (!info)
		return (ft_error("Error!\n"));
	philos = set_ph(info);
	if (!philos)
	{
		destroy_mutex_all(info);
		free(info->forks_mtx);
		free(info);
		return (ft_error("Error!\n"));
	}
	if (!start_philo(philos, info))
	{
		destroy_mutex_all(info);
		free_struct(philos, info);
		return (ft_error("Error!\n"));
	}
	destroy_mutex_all(info);
	free_struct(philos, info);
	return (0);
}
