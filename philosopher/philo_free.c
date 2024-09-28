/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:44:53 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 14:07:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
