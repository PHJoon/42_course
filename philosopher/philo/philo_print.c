/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:02:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/06 18:44:32 by hyungjpa         ###   ########.fr       */
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
	pthread_mutex_lock(&info->die_mtx);
	pthread_mutex_lock(&info->print_mtx);
	if (!info->die_flag)
	{
		now = get_time() - info->start_time;
		printf("%lld %d %s", now, philo->name, str);
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

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (1);
}
