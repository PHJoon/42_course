/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:02:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 14:39:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_ph *philo, char *str)
{
	long long	now;
	t_info		*info;
	int			ret;

	info = philo->info;
	ret = 0;
	pthread_mutex_lock(&info->print_mtx);
	pthread_mutex_lock(&info->die_mtx);
	if (!info->die_flag)
	{
		now = get_time();
		printf("%lld %d %s", now - info->start_time, philo->name, str);
		ret = 1;
		if (!ft_strncmp(str, DIE, 5))
		{
			info->die_flag = 1;
			ret = 0;
		}
	}
	pthread_mutex_unlock(&info->die_mtx);
	pthread_mutex_unlock(&info->print_mtx);
	return (ret);
}

int	print_error(char *str)
{
	printf("%s", str);
	return (1);
}
